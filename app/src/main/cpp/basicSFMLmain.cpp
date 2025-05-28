#include "isEngine/core/GameEngine.h"

namespace is
{
bool GameEngine::basicSFMLmain()
{
////////////////////////////////////////////////////////////
//                    WINDOW CREATION
////////////////////////////////////////////////////////////
#if defined(__ANDROID__)
    m_window.create(sf::VideoMode::getDesktopMode(), "");
#else
    m_window.create(sf::VideoMode(is::GameConfig::WINDOW_WIDTH,
                                  is::GameConfig::WINDOW_HEIGHT),
                                  is::GameConfig::GAME_NAME,
                                  is::getWindowStyle());

    // load application icon
    sf::Image iconTex;
    if (!iconTex.loadFromFile(is::GameConfig::GUI_DIR + "icon.png")) return false;
    m_window.setIcon(32, 32, iconTex.getPixelsPtr());
#endif // defined
    setFPS(m_window, is::GameConfig::FPS); // set frames per second (FPS)
    sf::View m_view(sf::Vector2f(is::GameConfig::VIEW_WIDTH / 2.f, is::GameConfig::VIEW_HEIGHT / 2.f), sf::Vector2f(is::GameConfig::VIEW_WIDTH, is::GameConfig::VIEW_HEIGHT));
    m_window.setView(m_view);

////////////////////////////////////////////////////////////
//                    INITIALIZATION
////////////////////////////////////////////////////////////
    // Define some constants
    const float pi = 3.14159f;
    sf::Vector2f paddleSize(25, 100);
    float ballRadius = 10.f;

    // Load the sounds used in the game
    sf::SoundBuffer ballSoundBuffer;
    is::loadSFMLSoundBuffer(ballSoundBuffer, is::GameConfig::SFX_DIR + "ball.wav");
    sf::Sound ballSound(ballSoundBuffer);

    // Create the left paddle
    sf::RectangleShape leftPaddle;
    leftPaddle.setSize(paddleSize - sf::Vector2f(3, 3));
    leftPaddle.setFillColor(sf::Color(100, 100, 200));
    leftPaddle.setOrigin(paddleSize / 2.f);

    // Create the right paddle
    sf::RectangleShape rightPaddle;
    rightPaddle.setSize(paddleSize - sf::Vector2f(3, 3));
    rightPaddle.setFillColor(sf::Color(200, 100, 100));
    rightPaddle.setOrigin(paddleSize / 2.f);

    // Create the ball
    sf::CircleShape ball;
    ball.setRadius(ballRadius - 3);
    ball.setFillColor(sf::Color::White);
    ball.setOrigin(ballRadius / 2, ballRadius / 2);

    // Load the text font
    sf::Font font;
    is::loadSFMLFont(font, is::GameConfig::FONT_DIR + "sansation.ttf", 40);

    // Initialize the pause message
    sf::Text pauseMessage;
    is::createText(font, pauseMessage, "", 170.f, 150.f, sf::Color::White, 40);

    #if (defined(__ANDROID__) || defined(__SWITCH__))
    pauseMessage.setString("Welcome to SFML pong!\nTouch the screen to start the game");
    #else
    pauseMessage.setString("Welcome to SFML pong!\nPress space to start the game");
    #endif

    // Define the paddles properties
    sf::Clock AITimer;
    const sf::Time AITime   = sf::seconds(0.1f);
    const float paddleSpeed = 400.f;
    float rightPaddleSpeed  = 0.f;
    const float ballSpeed   = 400.f;
    float ballAngle         = 0.f; // to be changed later

    sf::Clock clock;
    bool isPlaying = false;

////////////////////////////////////////////////////////////
//                    RENDER LOOP                         //
////////////////////////////////////////////////////////////
// This starts the render loop.                           //
// Don't touch unless you know what you're doing.         //
#if !defined(IS_ENGINE_HTML_5)                            //
    while (m_window.isOpen()                              //
#ifdef __SWITCH__                   			          //
		 && appletMainLoop()       	                      //
#endif                            						  //
		 )                             					  //
#else                                                     //
    EM_ASM(console.log("Start successfully!");, 0);       //
    execMainLoop([&]                                      //
    {                                                     //
    if (emscripten_run_script_int("Module.syncdone") == 1)//
#endif                                                    //
    {                                                     //
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
//                       EVENT
////////////////////////////////////////////////////////////
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    m_window.close();
                break;

                default: break;
            }
        }

////////////////////////////////////////////////////////////
//                    UPDATE OBJECTS
////////////////////////////////////////////////////////////

        // Window closed or escape key pressed: exit
        if (m_gameSysExt.keyIsPressed(sf::Keyboard::Escape)) is::closeApplication();

        // Space key pressed: play
        if (m_gameSysExt.keyIsPressed(sf::Keyboard::Space) || m_gameSysExt.isPressed(is::GameSystem::MOUSE))
        {
            if (!isPlaying)
            {
                // (re)start the game
                isPlaying = true;
                clock.restart();

                // Reset the position of the paddles and ball
                leftPaddle.setPosition(10 + paddleSize.x / 2, is::GameConfig::WINDOW_HEIGHT / 2);
                rightPaddle.setPosition(is::GameConfig::WINDOW_WIDTH - 10 - paddleSize.x / 2, is::GameConfig::WINDOW_HEIGHT / 2);
                ball.setPosition(is::GameConfig::WINDOW_WIDTH / 2, is::GameConfig::WINDOW_HEIGHT / 2);

                // Reset the ball angle
                do
                {
                    // Make sure the ball initial angle is not too much vertical
                    ballAngle = (std::rand() % 360) * 2 * pi / 360;
                }
                while (std::abs(std::cos(ballAngle)) < 0.7f);
            }
        }

        if (isPlaying)
        {
            float deltaTime = clock.restart().asSeconds();

            // Move the player's paddle
            if (m_gameSysExt.keyIsPressed(sf::Keyboard::Up) &&
               (leftPaddle.getPosition().y - paddleSize.y / 2 > 5.f))
            {
                leftPaddle.move(0.f, -paddleSpeed * deltaTime);
            }
            if (m_gameSysExt.keyIsPressed(sf::Keyboard::Down) &&
               (leftPaddle.getPosition().y + paddleSize.y / 2 < is::GameConfig::WINDOW_HEIGHT - 5.f))
            {
                leftPaddle.move(0.f, paddleSpeed * deltaTime);
            }

            if (m_gameSysExt.isPressed(is::GameSystem::MOUSE))
            {
                sf::Vector2f pos = is::getCursor(m_window);
                leftPaddle.setPosition(leftPaddle.getPosition().x, pos.y);
            }

            // Move the computer's paddle
            if (((rightPaddleSpeed < 0.f) && (rightPaddle.getPosition().y - paddleSize.y / 2 > 5.f)) ||
                ((rightPaddleSpeed > 0.f) && (rightPaddle.getPosition().y + paddleSize.y / 2 < is::GameConfig::WINDOW_HEIGHT - 5.f)))
            {
                rightPaddle.move(0.f, rightPaddleSpeed * deltaTime);
            }

            // Update the computer's paddle direction according to the ball position
            if (AITimer.getElapsedTime() > AITime)
            {
                AITimer.restart();
                if (ball.getPosition().y + ballRadius > rightPaddle.getPosition().y + paddleSize.y / 2)
                    rightPaddleSpeed = paddleSpeed;
                else if (ball.getPosition().y - ballRadius < rightPaddle.getPosition().y - paddleSize.y / 2)
                    rightPaddleSpeed = -paddleSpeed;
                else
                    rightPaddleSpeed = 0.f;
            }

            // Move the ball
            float factor = ballSpeed * deltaTime;
            ball.move(std::cos(ballAngle) * factor, std::sin(ballAngle) * factor);

            #if (defined(__ANDROID__) || defined(__SWITCH__))
            const std::string inputString = "Touch the screen to restart";
            #else
            const std::string inputString = "Press space to restart or\nescape to exit";
            #endif

            // Check collisions between the ball and the screen
            if (ball.getPosition().x - ballRadius < 0.f)
            {
                isPlaying = false;
                pauseMessage.setString("You Lost!\n" + inputString);
            }
            if (ball.getPosition().x + ballRadius > is::GameConfig::WINDOW_WIDTH)
            {
                isPlaying = false;
                pauseMessage.setString("You Won!\n" + inputString);
            }
            if (ball.getPosition().y - ballRadius < 0.f)
            {
                ballSound.play();
                ballAngle = -ballAngle;
                ball.setPosition(ball.getPosition().x, ballRadius + 0.1f);
            }
            if (ball.getPosition().y + ballRadius > is::GameConfig::WINDOW_HEIGHT)
            {
                ballSound.play();
                ballAngle = -ballAngle;
                ball.setPosition(ball.getPosition().x, is::GameConfig::WINDOW_HEIGHT - ballRadius - 0.1f);
            }

            // Check the collisions between the ball and the paddles
            // Left Paddle
            if (ball.getPosition().x - ballRadius < leftPaddle.getPosition().x + paddleSize.x / 2 &&
                ball.getPosition().x - ballRadius > leftPaddle.getPosition().x &&
                ball.getPosition().y + ballRadius >= leftPaddle.getPosition().y - paddleSize.y / 2 &&
                ball.getPosition().y - ballRadius <= leftPaddle.getPosition().y + paddleSize.y / 2)
            {
                if (ball.getPosition().y > leftPaddle.getPosition().y)
                    ballAngle = pi - ballAngle + (std::rand() % 20) * pi / 180;
                else
                    ballAngle = pi - ballAngle - (std::rand() % 20) * pi / 180;

                ballSound.play();
                ball.setPosition(leftPaddle.getPosition().x + ballRadius + paddleSize.x / 2 + 0.1f, ball.getPosition().y);
            }

            // Right Paddle
            if (ball.getPosition().x + ballRadius > rightPaddle.getPosition().x - paddleSize.x / 2 &&
                ball.getPosition().x + ballRadius < rightPaddle.getPosition().x &&
                ball.getPosition().y + ballRadius >= rightPaddle.getPosition().y - paddleSize.y / 2 &&
                ball.getPosition().y - ballRadius <= rightPaddle.getPosition().y + paddleSize.y / 2)
            {
                if (ball.getPosition().y > rightPaddle.getPosition().y)
                    ballAngle = pi - ballAngle + (std::rand() % 20) * pi / 180;
                else
                    ballAngle = pi - ballAngle - (std::rand() % 20) * pi / 180;

                ballSound.play();
                ball.setPosition(rightPaddle.getPosition().x - ballRadius - paddleSize.x / 2 - 0.1f, ball.getPosition().y);
            }
        }

////////////////////////////////////////////////////////////
//                     DRAW OBJECTS
////////////////////////////////////////////////////////////
        // Clear the window
        m_window.clear(sf::Color(50, 200, 50));

        if (isPlaying)
        {
            // Draw the paddles and the ball
            m_window.draw(leftPaddle);
            m_window.draw(rightPaddle);
            m_window.draw(ball);
        }
        else
        {
            // Draw the pause message
            m_window.draw(pauseMessage);
        }

        // Display things on screen
        m_window.display();
    }

////////////////////////////////////////////////////////////
// Don't touch unless you know what you're doing.         //
    #if defined(IS_ENGINE_HTML_5)                         //
    });                                                   //
    #endif                                                //
////////////////////////////////////////////////////////////
    return true;
}
}

/*
  is::Engine (Infinity Solutions Engine)
  Copyright (C) 2018-2025 Is Daouda <isdaouda.n@gmail.com>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#ifndef GAMEKEYNAME_H_INCLUDED
#define GAMEKEYNAME_H_INCLUDED

#include "../islibconnect/isLibConnect.h"

namespace is
{
////////////////////////////////////////////////////////////
/// \brief Returns the name of the keyboard key according to the value
///
/// Credit : BlackHC on SFML forum
////////////////////////////////////////////////////////////
inline const char *getKeyName(const sf::Keyboard::Key key)
{
    switch(key)
    {
        default:
        case sf::Keyboard::Unknown:
                return "Unknown";
        case sf::Keyboard::A:
                return "A";
        case sf::Keyboard::B:
                return "B";
        case sf::Keyboard::C:
                return "C";
        case sf::Keyboard::D:
                return "D";
        case sf::Keyboard::E:
                return "E";
        case sf::Keyboard::F:
                return "F";
        case sf::Keyboard::G:
                return "G";
        case sf::Keyboard::H:
                return "H";
        case sf::Keyboard::I:
                return "I";
        case sf::Keyboard::J:
                return "J";
        case sf::Keyboard::K:
                return "K";
        case sf::Keyboard::L:
                return "L";
        case sf::Keyboard::M:
                return "M";
        case sf::Keyboard::N:
                return "N";
        case sf::Keyboard::O:
                return "O";
        case sf::Keyboard::P:
                return "P";
        case sf::Keyboard::Q:
                return "Q";
        case sf::Keyboard::R:
                return "R";
        case sf::Keyboard::S:
                return "S";
        case sf::Keyboard::T:
                return "T";
        case sf::Keyboard::U:
                return "U";
        case sf::Keyboard::V:
                return "V";
        case sf::Keyboard::W:
                return "W";
        case sf::Keyboard::X:
                return "X";
        case sf::Keyboard::Y:
                return "Y";
        case sf::Keyboard::Z:
                return "Z";
        case sf::Keyboard::Num0:
                return "Num0";
        case sf::Keyboard::Num1:
                return "Num1";
        case sf::Keyboard::Num2:
                return "Num2";
        case sf::Keyboard::Num3:
                return "Num3";
        case sf::Keyboard::Num4:
                return "Num4";
        case sf::Keyboard::Num5:
                return "Num5";
        case sf::Keyboard::Num6:
                return "Num6";
        case sf::Keyboard::Num7:
                return "Num7";
        case sf::Keyboard::Num8:
                return "Num8";
        case sf::Keyboard::Num9:
                return "Num9";
        case sf::Keyboard::Escape:
                return "Escape";
        case sf::Keyboard::LControl:
                return "LControl";
        case sf::Keyboard::LShift:
                return "LShift";
        case sf::Keyboard::LAlt:
                return "LAlt";
        case sf::Keyboard::RControl:
                return "RControl";
        case sf::Keyboard::RShift:
                return "RShift";
        case sf::Keyboard::RAlt:
                return "RAlt";
        case sf::Keyboard::Menu:
                return "Menu";
        case sf::Keyboard::LBracket:
                return "LBracket";
        case sf::Keyboard::RBracket:
                return "RBracket";
        case sf::Keyboard::SemiColon:
                return "SemiColon";
        case sf::Keyboard::Comma:
                return "Comma";
        case sf::Keyboard::Period:
                return "Period";
        case sf::Keyboard::Slash:
                return "Slash";
        case sf::Keyboard::BackSlash:
                return "BackSlash";
        case sf::Keyboard::Equal:
                return "Equal";
        case sf::Keyboard::Space:
                return "Space";
        case sf::Keyboard::Return:
                return "Return";
        case sf::Keyboard::BackSpace:
                return "BackSpace";
        case sf::Keyboard::Tab:
                return "Tab";
        case sf::Keyboard::PageUp:
                return "PageUp";
        case sf::Keyboard::PageDown:
                return "PageDown";
        case sf::Keyboard::End:
                return "End";
        case sf::Keyboard::Home:
                return "Home";
        case sf::Keyboard::Insert:
                return "Insert";
        case sf::Keyboard::Delete:
                return "Delete";
        case sf::Keyboard::Multiply:
                return "Multiply";
        case sf::Keyboard::Divide:
                return "Divide";
        case sf::Keyboard::Left:
                return "Left";
        case sf::Keyboard::Right:
                return "Right";
        case sf::Keyboard::Up:
                return "Up";
        case sf::Keyboard::Down:
                return "Down";
        case sf::Keyboard::F1:
                return "F1";
        case sf::Keyboard::F2:
                return "F2";
        case sf::Keyboard::F3:
                return "F3";
        case sf::Keyboard::F4:
                return "F4";
        case sf::Keyboard::F5:
                return "F5";
        case sf::Keyboard::F6:
                return "F6";
        case sf::Keyboard::F7:
                return "F7";
        case sf::Keyboard::F8:
                return "F8";
        case sf::Keyboard::F9:
                return "F9";
        case sf::Keyboard::F10:
                return "F10";
        case sf::Keyboard::F11:
                return "F11";
        case sf::Keyboard::F12:
                return "F12";
        case sf::Keyboard::F13:
                return "F13";
        case sf::Keyboard::F14:
                return "F14";
        case sf::Keyboard::F15:
                return "F15";
        case sf::Keyboard::Pause:
                return "Pause";

#if defined(IS_ENGINE_SFML)
        case sf::Keyboard::LSystem:
                return "LSystem";
        case sf::Keyboard::RSystem:
                return "RSystem";
        case sf::Keyboard::Quote:
                return "Quote";
        case sf::Keyboard::Tilde:
                return "Tilde";
        case sf::Keyboard::Dash:
                return "Dash";
        case sf::Keyboard::Add:
                return "Add";
        case sf::Keyboard::Subtract:
                return "Subtract";
        case sf::Keyboard::Numpad0:
                return "Numpad0";
        case sf::Keyboard::Numpad1:
                return "Numpad1";
        case sf::Keyboard::Numpad2:
                return "Numpad2";
        case sf::Keyboard::Numpad3:
                return "Numpad3";
        case sf::Keyboard::Numpad4:
                return "Numpad4";
        case sf::Keyboard::Numpad5:
                return "Numpad5";
        case sf::Keyboard::Numpad6:
                return "Numpad6";
        case sf::Keyboard::Numpad7:
                return "Numpad7";
        case sf::Keyboard::Numpad8:
                return "Numpad8";
        case sf::Keyboard::Numpad9:
                return "Numpad9";
#endif
    }
    return "";
}

////////////////////////////////////////////////////////////
/// \brief Returns the name of the keyboard key according to the value
///
/// Credit : BlackHC on SFML forum
////////////////////////////////////////////////////////////
inline std::wstring getKeyWName(const sf::Keyboard::Key key)
{
    switch(key)
    {
        default:
        case sf::Keyboard::Unknown:
                return L"Unknown";
        case sf::Keyboard::A:
                return L"A";
        case sf::Keyboard::B:
                return L"B";
        case sf::Keyboard::C:
                return L"C";
        case sf::Keyboard::D:
                return L"D";
        case sf::Keyboard::E:
                return L"E";
        case sf::Keyboard::F:
                return L"F";
        case sf::Keyboard::G:
                return L"G";
        case sf::Keyboard::H:
                return L"H";
        case sf::Keyboard::I:
                return L"I";
        case sf::Keyboard::J:
                return L"J";
        case sf::Keyboard::K:
                return L"K";
        case sf::Keyboard::L:
                return L"L";
        case sf::Keyboard::M:
                return L"M";
        case sf::Keyboard::N:
                return L"N";
        case sf::Keyboard::O:
                return L"O";
        case sf::Keyboard::P:
                return L"P";
        case sf::Keyboard::Q:
                return L"Q";
        case sf::Keyboard::R:
                return L"R";
        case sf::Keyboard::S:
                return L"S";
        case sf::Keyboard::T:
                return L"T";
        case sf::Keyboard::U:
                return L"U";
        case sf::Keyboard::V:
                return L"V";
        case sf::Keyboard::W:
                return L"W";
        case sf::Keyboard::X:
                return L"X";
        case sf::Keyboard::Y:
                return L"Y";
        case sf::Keyboard::Z:
                return L"Z";
        case sf::Keyboard::Num0:
                return L"Num0";
        case sf::Keyboard::Num1:
                return L"Num1";
        case sf::Keyboard::Num2:
                return L"Num2";
        case sf::Keyboard::Num3:
                return L"Num3";
        case sf::Keyboard::Num4:
                return L"Num4";
        case sf::Keyboard::Num5:
                return L"Num5";
        case sf::Keyboard::Num6:
                return L"Num6";
        case sf::Keyboard::Num7:
                return L"Num7";
        case sf::Keyboard::Num8:
                return L"Num8";
        case sf::Keyboard::Num9:
                return L"Num9";
        case sf::Keyboard::Escape:
                return L"Escape";
        case sf::Keyboard::LControl:
                return L"LControl";
        case sf::Keyboard::LShift:
                return L"LShift";
        case sf::Keyboard::LAlt:
                return L"LAlt";
        case sf::Keyboard::RControl:
                return L"RControl";
        case sf::Keyboard::RShift:
                return L"RShift";
        case sf::Keyboard::RAlt:
                return L"RAlt";
        case sf::Keyboard::Menu:
                return L"Menu";
        case sf::Keyboard::LBracket:
                return L"LBracket";
        case sf::Keyboard::RBracket:
                return L"RBracket";
        case sf::Keyboard::SemiColon:
                return L"SemiColon";
        case sf::Keyboard::Comma:
                return L"Comma";
        case sf::Keyboard::Period:
                return L"Period";
        case sf::Keyboard::Slash:
                return L"Slash";
        case sf::Keyboard::BackSlash:
                return L"BackSlash";
        case sf::Keyboard::Equal:
                return L"Equal";
        case sf::Keyboard::Space:
                return L"Space";
        case sf::Keyboard::Return:
                return L"Return";
        case sf::Keyboard::BackSpace:
                return L"BackSpace";
        case sf::Keyboard::Tab:
                return L"Tab";
        case sf::Keyboard::PageUp:
                return L"PageUp";
        case sf::Keyboard::PageDown:
                return L"PageDown";
        case sf::Keyboard::End:
                return L"End";
        case sf::Keyboard::Home:
                return L"Home";
        case sf::Keyboard::Insert:
                return L"Insert";
        case sf::Keyboard::Delete:
                return L"Delete";
        case sf::Keyboard::Multiply:
                return L"Multiply";
        case sf::Keyboard::Divide:
                return L"Divide";
        case sf::Keyboard::Left:
                return L"Left";
        case sf::Keyboard::Right:
                return L"Right";
        case sf::Keyboard::Up:
                return L"Up";
        case sf::Keyboard::Down:
                return L"Down";
        case sf::Keyboard::F1:
                return L"F1";
        case sf::Keyboard::F2:
                return L"F2";
        case sf::Keyboard::F3:
                return L"F3";
        case sf::Keyboard::F4:
                return L"F4";
        case sf::Keyboard::F5:
                return L"F5";
        case sf::Keyboard::F6:
                return L"F6";
        case sf::Keyboard::F7:
                return L"F7";
        case sf::Keyboard::F8:
                return L"F8";
        case sf::Keyboard::F9:
                return L"F9";
        case sf::Keyboard::F10:
                return L"F10";
        case sf::Keyboard::F11:
                return L"F11";
        case sf::Keyboard::F12:
                return L"F12";
        case sf::Keyboard::F13:
                return L"F13";
        case sf::Keyboard::F14:
                return L"F14";
        case sf::Keyboard::F15:
                return L"F15";
        case sf::Keyboard::Pause:
                return L"Pause";

#if defined(IS_ENGINE_SFML)
        case sf::Keyboard::LSystem:
                return L"LSystem";
        case sf::Keyboard::RSystem:
                return L"RSystem";
        case sf::Keyboard::Quote:
                return L"Quote";
        case sf::Keyboard::Tilde:
                return L"Tilde";
        case sf::Keyboard::Dash:
                return L"Dash";
        case sf::Keyboard::Add:
                return L"Add";
        case sf::Keyboard::Subtract:
                return L"Subtract";
        case sf::Keyboard::Numpad0:
                return L"Numpad0";
        case sf::Keyboard::Numpad1:
                return L"Numpad1";
        case sf::Keyboard::Numpad2:
                return L"Numpad2";
        case sf::Keyboard::Numpad3:
                return L"Numpad3";
        case sf::Keyboard::Numpad4:
                return L"Numpad4";
        case sf::Keyboard::Numpad5:
                return L"Numpad5";
        case sf::Keyboard::Numpad6:
                return L"Numpad6";
        case sf::Keyboard::Numpad7:
                return L"Numpad7";
        case sf::Keyboard::Numpad8:
                return L"Numpad8";
        case sf::Keyboard::Numpad9:
                return L"Numpad9";
#endif
    }
    return L"";
}
}

#endif // GAMEKEYNAME_H_INCLUDED

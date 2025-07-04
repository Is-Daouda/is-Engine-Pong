# box 2d source file
set(
	box2d_sources
	
	${ISENGINE_SRC_DIR}/b2BroadPhase.cpp
	${ISENGINE_SRC_DIR}/b2CollideCircle.cpp
	${ISENGINE_SRC_DIR}/b2CollideEdge.cpp
	${ISENGINE_SRC_DIR}/b2CollidePolygon.cpp
	${ISENGINE_SRC_DIR}/b2Collision.cpp
	${ISENGINE_SRC_DIR}/b2Distance.cpp
	${ISENGINE_SRC_DIR}/b2DynamicTree.cpp
	${ISENGINE_SRC_DIR}/b2TimeOfImpact.cpp
	${ISENGINE_SRC_DIR}/b2CircleShape.cpp
	${ISENGINE_SRC_DIR}/b2EdgeShape.cpp
	${ISENGINE_SRC_DIR}/b2ChainShape.cpp
	${ISENGINE_SRC_DIR}/b2PolygonShape.cpp
	${ISENGINE_SRC_DIR}/b2BlockAllocator.cpp
	${ISENGINE_SRC_DIR}/b2Draw.cpp
	${ISENGINE_SRC_DIR}/b2Math.cpp
	${ISENGINE_SRC_DIR}/b2Settings.cpp
	${ISENGINE_SRC_DIR}/b2StackAllocator.cpp
	${ISENGINE_SRC_DIR}/b2Timer.cpp
	${ISENGINE_SRC_DIR}/b2Body.cpp
	${ISENGINE_SRC_DIR}/b2ContactManager.cpp
	${ISENGINE_SRC_DIR}/b2Fixture.cpp
	${ISENGINE_SRC_DIR}/b2Island.cpp
	${ISENGINE_SRC_DIR}/b2World.cpp
	${ISENGINE_SRC_DIR}/b2WorldCallbacks.cpp
	${ISENGINE_SRC_DIR}/b2CircleContact.cpp
	${ISENGINE_SRC_DIR}/b2Contact.cpp
	${ISENGINE_SRC_DIR}/b2ContactSolver.cpp
	${ISENGINE_SRC_DIR}/b2PolygonAndCircleContact.cpp
	${ISENGINE_SRC_DIR}/b2EdgeAndCircleContact.cpp
	${ISENGINE_SRC_DIR}/b2EdgeAndPolygonContact.cpp
	${ISENGINE_SRC_DIR}/b2ChainAndCircleContact.cpp
	${ISENGINE_SRC_DIR}/b2ChainAndPolygonContact.cpp
	${ISENGINE_SRC_DIR}/b2PolygonContact.cpp
	${ISENGINE_SRC_DIR}/b2DistanceJoint.cpp
	${ISENGINE_SRC_DIR}/b2FrictionJoint.cpp
	${ISENGINE_SRC_DIR}/b2GearJoint.cpp
	${ISENGINE_SRC_DIR}/b2Joint.cpp
	${ISENGINE_SRC_DIR}/b2MotorJoint.cpp
	${ISENGINE_SRC_DIR}/b2MouseJoint.cpp
	${ISENGINE_SRC_DIR}/b2PrismaticJoint.cpp
	${ISENGINE_SRC_DIR}/b2PulleyJoint.cpp
	${ISENGINE_SRC_DIR}/b2RevoluteJoint.cpp
	${ISENGINE_SRC_DIR}/b2RopeJoint.cpp
	${ISENGINE_SRC_DIR}/b2WeldJoint.cpp
	${ISENGINE_SRC_DIR}/b2WheelJoint.cpp
)

# engine source file
set(
	commun_sources
	
	${ISENGINE_SRC_DIR}/main.cpp

	# Basic SFML rendering loop
	${ISENGINE_SRC_DIR}/basicSFMLmain.cpp

	# core
	${ISENGINE_SRC_DIR}/GameEngine.cpp

	# islibconnect
	${ISENGINE_SRC_DIR}/isEngineWrapper.cpp
	${ISENGINE_SRC_DIR}/isEngineSDLWrapper.cpp
	
	# display
	${ISENGINE_SRC_DIR}/GameDisplay.cpp
	
	# entity
	${ISENGINE_SRC_DIR}/MainObject.cpp
	
	# graphic
	${ISENGINE_SRC_DIR}/TransitionEffect.cpp
	
	# function
	${ISENGINE_SRC_DIR}/GameFunction.cpp		
	${ISENGINE_SRC_DIR}/GameKeyData.cpp
	${ISENGINE_SRC_DIR}/GameSlider.cpp
	${ISENGINE_SRC_DIR}/GameSystem.cpp
	${ISENGINE_SRC_DIR}/GameTime.cpp
	
	# box 2d
	${box2d_sources}
)

# tmx lite
set(
	tmxlite_sources
	
	${ISENGINE_SRC_DIR}/isEngine/ext_lib/TMXLite/FreeFuncs.cpp
	${ISENGINE_SRC_DIR}/isEngine/ext_lib/TMXLite/ImageLayer.cpp
	${ISENGINE_SRC_DIR}/isEngine/ext_lib/TMXLite/LayerGroup.cpp
	${ISENGINE_SRC_DIR}/isEngine/ext_lib/TMXLite/Map.cpp
	${ISENGINE_SRC_DIR}/isEngine/ext_lib/TMXLite/Object.cpp
	${ISENGINE_SRC_DIR}/isEngine/ext_lib/TMXLite/ObjectGroup.cpp
	${ISENGINE_SRC_DIR}/isEngine/ext_lib/TMXLite/Property.cpp
	${ISENGINE_SRC_DIR}/isEngine/ext_lib/TMXLite/TileLayer.cpp
	${ISENGINE_SRC_DIR}/isEngine/ext_lib/TMXLite/Tileset.cpp
	${ISENGINE_SRC_DIR}/isEngine/ext_lib/TMXLite/detail/pugixml.cpp
	${ISENGINE_SRC_DIR}/isEngine/ext_lib/TMXLite/miniz.c
	)

# is::Engine Windows & Linux version
if (DEFINED ISENGINE_PC)
	set(
		isengine
		${commun_sources}
		${tmxlite_sources}
		
		# tiny file dialogs
		${ISENGINE_SRC_DIR}/isEngine/ext_lib/TinyFileDialogs/tinyfiledialogs.cpp
		)
# is::Engine Android version
elseif (DEFINED ISENGINE_ANDROID)
	set(
		isengine
		${commun_sources}
		${ISENGINE_SRC_DIR}/SDL_android_main.c
		#${tmxlite_sources}
		)
# is::Engine HTML version
elseif (DEFINED ISENGINE_HTML_5)
	set(
		isengine
		${commun_sources}
		)
endif()

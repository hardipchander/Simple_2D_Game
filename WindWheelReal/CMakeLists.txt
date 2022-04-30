set(HEADER_FILES 
		     WindWheelReal.h 
		     WindWheelRealApp.h 
		     WwrMacroDefinitions.h
		     WinForGame.h
		     AbstractWindow.h
		     AbstractRenderer.h
		     AbstractShader.h
		     AbstractSprite.h
		     usingGLFW/ActualGlfwWin.h
		     TwoDSprite.h
		     SingleRenderer.h
		     ShaderProgram.h
		     usingOpenGl/TwoDSpriteOpenGl.h
		     usingOpenGl/OpenGlShaderProgram.h
		     usingOpenGl/OpenGLRend.h
	
		     )

set(SOURCE_FILES 
		WindWheelRealApp.cpp 
		WinForGame.cpp
		usingGLFW/ActualGlfwWin.cpp
		usingOpenGl/OpenGLRend.cpp
		usingOpenGl/OpenGlShaderProgram.cpp
		ShaderProgram.cpp
		SingleRenderer.cpp
		TwoDSprite.cpp
		usingOpenGl/TwoDSpriteOpenGl.cpp
		
        )

add_library(WindWheelReal SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DWWR_LIB)
add_definitions(-DWWR_DEBUG)
add_definitions(-DWWR_OPENGL)

include_directories(../glfw/include)
include_directories(../WindWheelReal)
include_directories(../stbi)
include_directories(../glad/include)

target_precompile_headers(WindWheelReal PRIVATE precompilehead.h)

target_link_libraries(WindWheelReal glfw glad stbi)

set(HEADER_FILES 
		     WindWheelReal.h 
		     WindWheelRealApp.h 
		     WwrMacroDefinitions.h
			 WinForGame.h
			 AbstractWindow.h
		     usingGLFW/ActualGlfwWin.h
		     )

set(SOURCE_FILES 
		WindWheelRealApp.cpp 
		WinForGame.cpp
		usingGLFW/ActualGlfwWin.cpp
        )

add_library(WindWheelReal SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DWWR_LIB)
add_definitions(-DWWR_DEBUG)

include_directories(../glfw/include)
include_directories(../WindWheelReal)

target_precompile_headers(WindWheelReal PRIVATE precompilehead.h)

target_link_libraries(WindWheelReal glfw)
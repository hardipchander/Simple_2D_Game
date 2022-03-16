set(HEADER_FILES 
		     WindWheelReal.h 
		     WindWheelRealApp.h 
		     WwrMacroDefinitions.h
		     
		     )

set(SOURCE_FILES 
		WindWheelRealApp.cpp 
        )


add_library(WindWheelReal SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DWWR_LIB)
add_definitions(-DWWR_DEBUG)

target_precompile_headers(WindWheelReal PRIVATE precompilehead.h)
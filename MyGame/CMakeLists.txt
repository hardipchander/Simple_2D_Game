set(HEADER_FILES  
	Things.h
	MyGameApp.h	
)

set(SOURCE_FILES
	Things.cpp
	MyGameApp.cpp
	driver.cpp
)

add_executable(MyGame ${HEADER_FILES} ${SOURCE_FILES})

include_directories(../WindWheelReal)

target_link_libraries(MyGame WindWheelReal)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/MyGame)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)
add_executable(MyGame driver.cpp MyGameApp.h MyGameApp.cpp Things.h Things.cpp)

include_directories(../WindWheelReal)

target_link_libraries(MyGame WindWheelReal)
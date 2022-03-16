add_executable(MyGame driver.cpp)

include_directories(../WindWheelReal)

target_link_libraries(MyGame WindWheelReal)
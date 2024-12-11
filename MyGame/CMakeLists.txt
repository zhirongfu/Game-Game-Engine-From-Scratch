add_executable(MyGame MyGame.cpp)

include_directories(../Jelly/include)

target_link_libraries(MyGame Jelly)
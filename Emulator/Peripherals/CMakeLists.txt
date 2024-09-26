target_include_directories(tiaraCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(tiaraCore PRIVATE

)

add_subdirectory(Joystick)
add_subdirectory(Monitor)
add_subdirectory(Mouse)
add_subdirectory(Paddle)

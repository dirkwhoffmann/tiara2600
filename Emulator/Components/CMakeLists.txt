
target_include_directories(tiaraCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(tiaraCore PRIVATE

Atari.cpp
AtariBase.cpp
Emulator.cpp
EmulatorBase.cpp

)

add_subdirectory(CPU)
add_subdirectory(TIA)
add_subdirectory(PIA)
add_subdirectory(Ports)
add_subdirectory(Memory)

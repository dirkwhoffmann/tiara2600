target_include_directories(tiaraCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(tiaraCore PRIVATE

Command.cpp
Console.cpp
CommandConsole.cpp
DebugConsole.cpp
RetroShell.cpp
TextStorage.cpp

)

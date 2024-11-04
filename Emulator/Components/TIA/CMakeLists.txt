target_include_directories(tiaraCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(tiaraCore PRIVATE

BeamTraps.cpp
Ball.cpp
Detector.cpp
Player.cpp
Playfield.cpp
TIABase.cpp
TIA.cpp
LogicAnalyzer.cpp
LogicAnalyzerBase.cpp

)

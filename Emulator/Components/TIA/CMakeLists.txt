target_include_directories(tiaraCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(tiaraCore PRIVATE

VICII.cpp
VICIIBase.cpp
VICIIDraw.cpp
VICIISprites.cpp
VICIIMemory.cpp
VICIICycles.cpp
VICIITable.cpp
TIABase.cpp
TIA.cpp
LogicAnalyzer.cpp
LogicAnalyzerBase.cpp

)

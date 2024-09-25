target_include_directories(tiaraCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(tiaraCore PRIVATE

CIA.cpp
CIABase.cpp
CIARegs.cpp
TOD.cpp
TODBase.cpp

)

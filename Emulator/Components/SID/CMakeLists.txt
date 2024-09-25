target_include_directories(tiaraCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(tiaraCore PRIVATE

ReSID.cpp
SID.cpp
SIDBase.cpp
SIDBridge.cpp

)

add_subdirectory(resid)

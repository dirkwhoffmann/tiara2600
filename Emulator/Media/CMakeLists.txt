target_include_directories(tiaraCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(tiaraCore PRIVATE

MediaFile.cpp
AnyFile.cpp

CRTFile.cpp
RomFile.cpp
Script.cpp
Snapshot.cpp

)

add_subdirectory(Cartridges)

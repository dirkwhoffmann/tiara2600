target_include_directories(tiaraCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(tiaraCore PRIVATE

MediaFile.cpp
AnyCollection.cpp
AnyFile.cpp

CRTFile.cpp
D64File.cpp
Folder.cpp
G64File.cpp
PRGFile.cpp
P00File.cpp
RomFile.cpp
Script.cpp
Snapshot.cpp
TAPFile.cpp
T64File.cpp

)

add_subdirectory(Cartridges)

target_include_directories(tiaraCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(tiaraCore PRIVATE

Drive.cpp
DriveBase.cpp
DriveMemory.cpp
DriveMemoryBase.cpp
VIA.cpp
PIA.cpp
ParCable.cpp
Disk.cpp
DiskAnalyzer.cpp

)

target_include_directories(tiaraCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(tiaraCore PRIVATE

FSDescriptors.cpp
FileSystem.cpp
FSBlock.cpp
FSDirEntry.cpp

)

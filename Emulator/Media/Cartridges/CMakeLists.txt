target_include_directories(tiaraCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(tiaraCore PRIVATE

Cartridge.cpp
CartridgeBase.cpp

)

add_subdirectory(CustomCartridges)

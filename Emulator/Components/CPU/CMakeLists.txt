target_include_directories(tiaraCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(tiaraCore PRIVATE

CPU.cpp
CPUBase.cpp

)

add_subdirectory(Peddle)

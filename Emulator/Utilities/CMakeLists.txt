target_include_directories(tiaraCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(tiaraCore PRIVATE

  Buffer.cpp
  Chrono.cpp
  Concurrency.cpp
  MemUtils.cpp
  Checksum.cpp
  StringUtils.cpp
  IOUtils.cpp
  Parser.cpp
)

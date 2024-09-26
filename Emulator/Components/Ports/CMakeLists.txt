target_include_directories(tiaraCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(tiaraCore PRIVATE

AudioPort.cpp
AudioPortBase.cpp
ControlPort.cpp
ControlPortBase.cpp
ExpansionPort.cpp
ExpansionPortBase.cpp
PowerPort.cpp
PowerPortBase.cpp
UserPort.cpp
UserPortBase.cpp
VideoPort.cpp
VideoPortBase.cpp

)

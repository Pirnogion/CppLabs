add_executable (Lab6 "Lab6.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Lab6 PROPERTY CXX_STANDARD 20)
endif()
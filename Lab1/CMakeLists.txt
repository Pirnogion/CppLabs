add_executable (Lab1 "Lab13.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Lab1 PROPERTY CXX_STANDARD 20)
endif()
add_executable (Lab4 "Lab4.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Lab4 PROPERTY CXX_STANDARD 20)
endif()
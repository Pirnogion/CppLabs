set (VARIANT "Lab51")
set (EXECUTABLE "${VARIANT}.cpp")
set (INPUT_FILEPATH "/files/${VARIANT}i.txt")

add_executable (Lab5 ${EXECUTABLE})

if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}${INPUT_FILEPATH}")
  configure_file("${CMAKE_CURRENT_SOURCE_DIR}${INPUT_FILEPATH}" "${CMAKE_CURRENT_BINARY_DIR}${INPUT_FILEPATH}" COPYONLY)
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Lab5 PROPERTY CXX_STANDARD 20)
endif()
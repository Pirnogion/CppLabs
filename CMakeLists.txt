cmake_minimum_required (VERSION 3.8)

if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("CppLabs")

#add_subdirectory ("Lab1")
#add_subdirectory ("Lab2")
#add_subdirectory ("Lab3")
#add_subdirectory ("Lab4")
#add_subdirectory ("Lab5")
#add_subdirectory ("Lab6")
#add_subdirectory ("Lab7")
#add_subdirectory ("Lab8")
#add_subdirectory ("Lab9")
add_subdirectory ("Lab10")
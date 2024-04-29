# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\cpp_proj_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\cpp_proj_autogen.dir\\ParseCache.txt"
  "cpp_proj_autogen"
  )
endif()

# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Example_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Example_autogen.dir\\ParseCache.txt"
  "Example_autogen"
  )
endif()

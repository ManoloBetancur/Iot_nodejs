# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Casting_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Casting_autogen.dir\\ParseCache.txt"
  "Casting_autogen"
  )
endif()

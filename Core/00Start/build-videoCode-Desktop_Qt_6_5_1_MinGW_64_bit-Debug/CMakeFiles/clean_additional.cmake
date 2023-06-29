# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\videoCode_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\videoCode_autogen.dir\\ParseCache.txt"
  "videoCode_autogen"
  )
endif()

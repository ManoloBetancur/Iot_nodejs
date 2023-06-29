# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Templates_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Templates_autogen.dir\\ParseCache.txt"
  "Templates_autogen"
  )
endif()

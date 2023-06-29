# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QtDateTime_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QtDateTime_autogen.dir\\ParseCache.txt"
  "QtDateTime_autogen"
  )
endif()

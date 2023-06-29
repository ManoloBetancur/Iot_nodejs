# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SignalsSlots_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SignalsSlots_autogen.dir\\ParseCache.txt"
  "SignalsSlots_autogen"
  )
endif()

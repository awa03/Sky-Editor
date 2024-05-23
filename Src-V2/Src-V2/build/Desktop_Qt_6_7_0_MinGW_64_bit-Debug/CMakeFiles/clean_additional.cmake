# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Src-V2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Src-V2_autogen.dir\\ParseCache.txt"
  "Src-V2_autogen"
  )
endif()

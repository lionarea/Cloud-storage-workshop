file(STRINGS "${exe}" content REGEX "name=\"Kitware.CMake.MSManifestTest\"")
if(content)
  message(STATUS "Expected manifest content found:\n ${content}")
else()
  message(FATAL_ERROR "Expected manifest content not found in\n ${exe}")
endif()

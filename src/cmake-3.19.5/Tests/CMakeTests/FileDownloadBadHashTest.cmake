if(NOT "/home/master1/src/cmake-3.19.5/Tests/CMakeTests" MATCHES "^/")
  set(slash /)
endif()
set(url "file://${slash}/home/master1/src/cmake-3.19.5/Tests/CMakeTests/FileDownloadInput.png")
set(dir "/home/master1/src/cmake-3.19.5/Tests/CMakeTests/downloads")

file(DOWNLOAD
  ${url}
  ${dir}/file3.png
  TIMEOUT 2
  STATUS status
  EXPECTED_HASH SHA1=5555555555555555555555555555555555555555
  )

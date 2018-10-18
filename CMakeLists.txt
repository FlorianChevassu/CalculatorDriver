cmake_minimum_required(VERSION 3.10)
project(CalculatorDriver)

option(BUILD_SUPERBUILD "Build the project using the superbuild" OFF)
option(BUILD_TESTING "Build the tests" ON)

if(${BUILD_SUPERBUILD})
  # If the user asked for a superbuild, just include the superbuild script, and quit.
  include(cmake/Superbuild.cmake)
  return()
endif()

add_subdirectory(src)

if(${BUILD_TESTING})
	# These should absolutely be included in the root CMakeLists.txt file. Otherwise, CDash won't work.
	include(CTest)
	enable_testing()
	add_subdirectory(testing)
endif()
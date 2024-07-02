# FindSquirrel.cmake - Locate the Squirrel library
# This module defines the following variables:
#  SQUIRREL_FOUND - True if Squirrel is found
#  SQUIRREL_INCLUDE_DIR - The directory containing Squirrel headers
#  SQUIRREL_LIBRARY - The Squirrel library

# Try to find the Squirrel library
find_path(SQUIRREL_INCLUDE_DIR
  NAMES squirrel.h
  PATHS
    /usr/local/include
    /usr/include
    ${CMAKE_SOURCE_DIR}/include
)

if(BUILD_SHARED_LIBS)
	find_library(SQUIRREL_LIBRARY
	NAMES squirrel
	PATHS
	  /usr/local/lib
	  /usr/lib
	  ${CMAKE_SOURCE_DIR}/lib
	)
else()
	find_library(SQUIRREL_LIBRARY
	NAMES squirrel_static
	PATHS
	  /usr/local/lib
	  /usr/lib
	  ${CMAKE_SOURCE_DIR}/lib
	)
endif()



include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Squirrel DEFAULT_MSG SQUIRREL_LIBRARY SQUIRREL_INCLUDE_DIR)

if(SQUIRREL_FOUND)
  set(SQUIRREL_LIBRARIES ${SQUIRREL_LIBRARY})
  set(SQUIRREL_INCLUDE_DIRS ${SQUIRREL_INCLUDE_DIR})
else()
  set(SQUIRREL_LIBRARIES)
  set(SQUIRREL_INCLUDE_DIRS)
endif()

mark_as_advanced(SQUIRREL_INCLUDE_DIR SQUIRREL_LIBRARY)

# CMakeList.txt : CMake project for WiggleSort, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("WiggleSort")

# Add source to this project's executable.
file(GLOB SOURCES 
		header-folder/*.h,
		source-folder/*.cpp
)
add_executable (WiggleSort ${SOURCES})

# TODO: Add tests and install targets if needed.

cmake_minimum_required(VERSION 2.8)
project( vidDisplay )
#SET(TARGET_H
#	vidDisplay.h)
SET(TARGET_SRC
	filters.cpp)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( vidDisplay vidDisplay.cpp )
target_link_libraries( vidDisplay ${OpenCV_LIBS} )

cmake_minimum_required(VERSION 3.12)

project(PhotoBatch)

add_executable(PhotoBatch 
	"PhotoBatch.cpp" 
	"ArgumentParser.cpp" 
	"ArgumentParser.h"
 "Utils.h" "Utils.cpp")
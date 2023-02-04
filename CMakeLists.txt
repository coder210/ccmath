cmake_minimum_required(VERSION 3.5)

# 设置变量
set(CCMATH_NAME ccmath)
set(UNIT_TEST_NAME unit_test)

project(${CCMATH_NAME} C)


#设置包含的目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
	IF(CMAKE_CL_64)
	    message("current platform: Linux 64")
	ELSE(CMAKE_CL_32)
	    message("current platform: Linux 32")
	ENDIF(CMAKE_CL_64)
elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	IF(CMAKE_CL_64)
	    message("current platform: Windows 64")
	ELSE(CMAKE_CL_32)
	    message("current platform: Windows 32")
	ENDIF(CMAKE_CL_64)
else()
	message("current platform: unkonw ")
endif()

file(GLOB CCMATH_HEADER_FILES "*.h" "include/*.h")
file(GLOB CCMATH_SOURCE_FILES "*.c" "src/*.c")

file(GLOB UNIT_TEST_SOURCE_FILES "*.c" "${UNIT_TEST_NAME}/*.c")

add_library(${CCMATH_NAME} STATIC ${CCMATH_HEADER_FILES} ${CCMATH_SOURCE_FILES})
add_executable(${UNIT_TEST_NAME} ${UNIT_TEST_SOURCE_FILES}) 

target_link_libraries(${UNIT_TEST_NAME} ${CCMATH_NAME})
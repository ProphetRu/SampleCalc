cmake_minimum_required(VERSION 3.10)

#--------------------------------------------------------------------------------------------------
# variables
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(TEST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test)
set(PROJECT_NAME SampleCalc)
set(TEST_NAME UnitTest)


#--------------------------------------------------------------------------------------------------
# project
project(${PROJECT_NAME})


#--------------------------------------------------------------------------------------------------
# builds
add_executable(${PROJECT_NAME}
	${SRC_DIR}/SampleCalc.hpp
	${SRC_DIR}/main.cpp
)

add_executable(${TEST_NAME} 
	${TEST_DIR}/TestSampleCalc.cpp
)

# properties
set_target_properties(${PROJECT_NAME} ${TEST_NAME} 
	PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)


#--------------------------------------------------------------------------------------------------
# gtest
#
find_package(GTest)

# build googletest
add_subdirectory(
	${CMAKE_CURRENT_SOURCE_DIR}/googletest
)

# add src to the include directories for the test target
target_include_directories(${TEST_NAME} 
	PRIVATE
	${SRC_DIR}
	${GTEST_INCLUDE_DIRS}
)

# link test target against gtest libraries
target_link_libraries(${TEST_NAME} 
	PRIVATE
	${GTEST_BOOTH_LIBRARIES}
	gmock
	gmock_main
	gtest 
	gtest_main
)


#--------------------------------------------------------------------------------------------------
# compiler settings
if (MSVC)
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

	target_compile_options(${PROJECT_NAME} PRIVATE
		/W4
	)
	target_compile_options(${TEST_NAME} PRIVATE
		/W4
	)
else ()
	target_compile_options(${PROJECT_NAME} PRIVATE
		-Wall -Wextra -pedantic -Werror
	)
	target_compile_options(${TEST_NAME} PRIVATE
		-Wall -Wextra -pedantic -Werror
	)
endif()


#--------------------------------------------------------------------------------------------------
# testing
enable_testing()
include(GoogleTest)
gtest_discover_tests(${TEST_NAME})
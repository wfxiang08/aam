cmake_minimum_required(VERSION 2.8)

project(aam)

if (WIN32)
	#set(OpenCV_STATIC true)
	add_definitions("-D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS")
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
	set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
endif()

set(EIGEN_INCLUDE_DIR "../eigen" CACHE PATH "Where is the include directory of Eigen located")
set(AAM_TESTS_VERBOSE 0 CACHE BOOL "Tests will show visualizations when enabled")
find_package(OpenCV REQUIRED)

add_subdirectory(imagealign)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${OpenCV_INCLUDE_DIRS} ${EIGEN_INCLUDE_DIR} "inc" "imagealign/inc")

# Library
add_library(aam
    inc/aam/fwd.h
    inc/aam/traits.h
	inc/aam/types.h	
	inc/aam/map.h
	inc/aam/views.h
	inc/aam/pca.h
	inc/aam/aam.h
	inc/aam/io.h
	inc/aam/show.h
	inc/aam/procrustes.h
	inc/aam/barycentrics.h
	inc/aam/delaunay.h
	inc/aam/rasterization.h
	inc/aam/bilinear.h
	inc/aam/model.h
	inc/aam/matcher.h
    inc/aam/trainingset.h
	inc/aam/trainer.h
    inc/aam/transform.h
	inc/aam/io/serialization.h
	inc/aam/io/aam_generated.h
    inc/aam/io/aam.fbs
	src/pca.cpp	
	src/io.cpp
	src/show.cpp
	src/procrustes.cpp
	src/delaunay.cpp
	src/rasterization.cpp
	src/model.cpp
	src/matcher.cpp
	src/trainer.cpp
    src/transform.cpp
	src/io/serialization.cpp
)
	
target_link_libraries(aam ${OpenCV_LIBRARIES})
	
# Samples

add_executable(aam_shapemorph examples/shapemorph.cpp)
target_link_libraries(aam_shapemorph aam ${OpenCV_LIBRARIES})

add_executable(aam_showtrainingdata examples/showtrainingdata.cpp)
target_link_libraries(aam_showtrainingdata aam ${OpenCV_LIBRARIES})

add_executable(aam_appearancevariation examples/appearancevariation.cpp)
target_link_libraries(aam_appearancevariation aam ${OpenCV_LIBRARIES})

add_executable(aam_matching examples/matching.cpp)
target_link_libraries(aam_matching aam ${OpenCV_LIBRARIES})

# Tests

configure_file(tests/config.h.in test_config.h)
add_executable(aam_tests
	test_config.h
    tests/catch.hpp
	tests/random_distributions.h
    tests/pca.cpp
	tests/procrustes.cpp
	tests/map.cpp
	tests/barycentrics.cpp
	tests/delaunay.cpp
	tests/rasterization.cpp
	tests/bilinear.cpp
	tests/serialization.cpp
	tests/views.cpp
    tests/transform.cpp
	tests/matching.cpp
)
target_link_libraries(aam_tests aam ${OpenCV_LIBRARIES})

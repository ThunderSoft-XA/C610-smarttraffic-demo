cmake_minimum_required (VERSION 3.4.1)
set(CMAKE_VERBOSE_MAKEFILE on)
project (smarttraffic)

set(OpenCV_DIR /usr/local/opencv/share/OpenCV)
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "OpenCV Version: ${OpenCV_VERSION}")
message(STATUS "OpenCV Libraries: ${OpenCV_LIBS}")
message(STATUS "OpenCV Include path: ${OpenCV_INCLUDE_DIRS}")


# c++11 required
set(CMAKE_BUILD_TYPE "DEBUG")
# MESSAGE(${CMAKE_BINARY_DIR}/../)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lm -pthread -DANDROID_TARGET -DSNPE_ENGINE_SUPPORTED -DLOG_SWITCH=0")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib/)

set(SNPE_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/snpe/include/zdl")
set(SNPE_LIBS  "SNPE;symphony-cpu;snpe_adsp;")
set(SNPE_LIBRARY_DIRS  "${CMAKE_SOURCE_DIR}/libs/snpe")

# sub directories
add_subdirectory(thirdparty)

aux_source_directory(${CMAKE_SOURCE_DIR} DIR_SRCS)

include_directories(
        ${CMAKE_SOURCE_DIR}/include /
        ${SNPE_INCLUDE_DIRS} /
        ${OpenCV_INCLUDE_DIRS}
        )

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log )

link_directories(
        ${CMAKE_SOURCE_DIR}/libs /
        ${SNPE_LIBRARY_DIRS} /
        ${EXT_LIB_DIRS}
        )
# sources to be compiled
set(SOURCE_FILES
        src/core/core_func.cpp
        src/core/chars_identify.cpp
        src/core/chars_recognise.cpp
        src/core/chars_segment.cpp
        src/core/feature.cpp
        src/core/plate_detect.cpp
        src/core/plate_judge.cpp
        src/core/plate_locate.cpp
        src/core/plate_recognize.cpp
        src/core/params.cpp
        src/core/SNPEPlate.cpp

        src/train/ann_train.cpp
        src/train/annCh_train.cpp
        src/train/svm_train.cpp
        src/train/train.cpp
        src/train/create_data.cpp

        src/util/util.cpp
        src/util/program_options.cpp
        src/util/kv.cpp
        )

# pack objects to static library
add_library(easypr STATIC ${SOURCE_FILES})

add_executable(
        ${PROJECT_NAME} 
        #${DIR_SRCS}
        ${CMAKE_SOURCE_DIR}/test/main.cpp
        )

target_link_libraries(
    ${PROJECT_NAME}
    easypr
    thirdparty
    ${OpenCV_LIBS}
    ${CMAKE_SOURCE_DIR}/libs/snpe/libSNPE.so
    # zlib
    z
)



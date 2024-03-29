CMAKE_MINIMUM_REQUIRED(VERSION 3.0.2)
PROJECT(MATH4610)

IF (NOT MSVC)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ENDIF (NOT MSVC)

INCLUDE_DIRECTORIES(include)
FILE(GLOB_RECURSE LIBRARY_FILES "source/*.cpp")
ADD_LIBRARY(computations ${LIBRARY_FILES})

ADD_EXECUTABLE(target_language test/target_language.cpp)

SET(TESTS
    sandbox
    demo
    central_difference
    root_finding
    root_finding_2
    matrix_test
)

SET(GOMP_TESTS
    openmp_demo
)

FOREACH(TARGET ${TESTS})
    ADD_EXECUTABLE(${TARGET} test/${TARGET}.cpp)
    TARGET_LINK_LIBRARIES(${TARGET} computations)
ENDFOREACH()

FOREACH(TARGET ${GOMP_TESTS})
    ADD_EXECUTABLE(${TARGET} test/${TARGET}.cpp)
    TARGET_LINK_LIBRARIES(${TARGET} computations gomp)
    TARGET_COMPILE_OPTIONS(${TARGET} PUBLIC -fopenmp)
ENDFOREACH()

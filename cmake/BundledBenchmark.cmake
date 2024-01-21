message(STATUS "Adding bundled Google Benchmark")

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL INTERNAL)
set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL INTERNAL)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL INTERNAL)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty/benchmark)

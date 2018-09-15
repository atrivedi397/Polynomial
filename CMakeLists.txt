cmake_minimum_required(VERSION 3.9)
project(Illogicals)

set(CMAKE_CXX_STANDARD 17)


set(POLYNOMIAL_FILES Polynomial_Using_P_Queue/main.cpp Polynomial_Using_P_Queue/queue.h)
add_executable(POLYNOMIAL ${POLYNOMIAL_FILES} )

set(MERGE_SORT_FILES Merge_Sort/merge_sort.cpp Merge_Sort/merge_sort.h)
add_executable(MERGE_SORT ${MERGE_SORT_FILES})

set(HEAP_SORT_FILES Heap_Sort/heap_sort.cpp Heap_Sort/heap_sort.h)
add_executable(HEAP_SORT ${HEAP_SORT_FILES})
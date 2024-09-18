include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_library(CircularQueue include/CircularQueue.cpp)
add_executable(CircularQueueTest test/CircularQueueTest.cpp)
target_link_libraries(CircularQueueTest CircularQueue)

add_library(LinkQueue include/LinkQueue.cpp)
add_executable(LinkQueueTest test/LinkQueueTest.cpp)
target_link_libraries(LinkQueueTest LinkQueue)
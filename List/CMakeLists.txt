include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
# add_library(SqList include/SqList.cpp)
# add_executable(test test/SqListTest.cpp)
# target_link_libraries(test SqList)

# add_library(LinkList include/LinkList.cpp)
# add_executable(LinkListTest test/LinkListTest.cpp)
# target_link_libraries(LinkListTest LinkList)

add_library(StaticLinkList include/StaticLinkList.cpp)
add_executable(StaticLinkListTest test/StaticLinkListTest.cpp)
target_link_libraries(StaticLinkListTest StaticLinkList)
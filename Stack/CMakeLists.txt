include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(SqStack include/SqStack.cpp)
add_executable(SqStackTest test/SqStackTest.cpp)
target_link_libraries(SqStackTest SqStack)

add_library(LinkStack include/LinkStack.cpp)
add_executable(LinkStackTest test/LinkStackTest.cpp)
target_link_libraries(LinkStackTest LinkStack)

add_executable(feibonaqie src/feibonaqie.cpp)
add_executable(ReversePolishNotation src/ReversePolishNotation.cpp)
target_link_libraries(ReversePolishNotation LinkStack)
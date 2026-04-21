add_library(LinearList STATIC
        src/SeqList.cpp
        src/LinkList.cpp
        src/CircList.cpp
        src/DulList.cpp
)

target_include_directories(LinearList PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
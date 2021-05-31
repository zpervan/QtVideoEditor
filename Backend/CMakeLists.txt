project(Backend_Lib)

set(HEADERS
        thumbnail_creator.h
        path_creator.h
        )

add_library(${PROJECT_NAME} STATIC ${HEADERS})

find_package(OpenCV REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PRIVATE ${OpenCV_DIR})

target_link_libraries(${PROJECT_NAME}
        PRIVATE ${OpenCV_LIBS}
        PRIVATE stdc++fs
        PRIVATE fmt
        )

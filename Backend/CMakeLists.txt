project(Backend_Lib)

set(HEADERS
        thumbnail_creator.h
        path_creator.h
        random_number_generator.h
        )

set(SOURCE
        random_number_generator.cpp
        )

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCE})

find_package(OpenCV REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_directories(${PROJECT_NAME} PRIVATE ${OpenCV_DIR})

target_link_libraries(${PROJECT_NAME}
        PRIVATE ${OpenCV_LIBS}
        PRIVATE Qt5::Core
        PRIVATE stdc++fs
        PRIVATE fmt
        )

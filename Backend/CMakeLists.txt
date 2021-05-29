set(HEADERS
        thumbnail_creator.h
        utility.h
        )

add_library(Backend_Lib STATIC ${HEADERS})

find_package(OpenCV REQUIRED)
target_include_directories(Backend_Lib PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_directories(Backend_Lib PRIVATE ${OpenCV_DIR})

target_link_libraries(Backend_Lib PRIVATE ${OpenCV_LIBS} stdc++fs fmt)

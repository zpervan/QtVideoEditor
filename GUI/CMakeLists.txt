project(GUI_Lib)

set(HEADERS
        Code/menu.h
        Code/video_list_model.h
        )

set(SOURCES
        Code/menu.cpp
        Code/video_list_model.cpp
        )

add_library(${PROJECT_NAME} STATIC ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
        PRIVATE Qt5::Core
        PRIVATE Qt5::Quick
        PRIVATE Backend_Lib
        )

target_compile_definitions(${PROJECT_NAME} PRIVATE QT_QML_DEBUG QT_DECLARATIVE_DEBUG)
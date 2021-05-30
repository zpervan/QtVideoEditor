cmake_minimum_required(VERSION 3.16.3)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(PROJECT_NAME QtVideoEditor)
set(ALLOW_DUPLICATE_CUSTOM_TARGETS TRUE)
#set(CMAKE_FIND_DEBUG_MODE 1)

project(${PROJECT_NAME} LANGUAGES CXX)

find_package(Qt5 COMPONENTS Core Quick Widgets REQUIRED)

add_subdirectory(GUI)
add_subdirectory(Backend)

add_executable(${PROJECT_NAME} main.cpp GUI/Resources/qml.qrc)

target_compile_definitions(${PROJECT_NAME} PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

target_link_libraries(${PROJECT_NAME}
        PRIVATE Qt5::Core
        PRIVATE Qt5::Quick
        PRIVATE GUI_Lib
        PRIVATE Backend_Lib
        )

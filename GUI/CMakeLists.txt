set(HEADERS menu.h)
set(SOURCES menu.cpp)

add_library(GUI_Lib STATIC ${HEADERS} ${SOURCES})

find_package(Qt5 COMPONENTS Core Quick REQUIRED)
target_link_libraries(GUI_Lib PRIVATE Qt5::Core Qt5::Quick)
target_compile_definitions(GUI_Lib PRIVATE QT_QML_DEBUG QT_DECLARATIVE_DEBUG)
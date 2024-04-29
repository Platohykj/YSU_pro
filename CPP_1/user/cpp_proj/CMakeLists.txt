cmake_minimum_required(VERSION 3.27)
project(cpp_proj)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.8.0/mingw_64/lib/cmake")
set(OpenCV_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cv_install)
set(OpenCV_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/cv_install/include)
set(OpenCV_LIBS
        opencv_core
        opencv_imgproc
        opencv_highgui
        opencv_imgcodecs
        opencv_videoio
        opencv_objdetect
        opencv_calib3d
        opencv_features2d
        opencv_flann
        opencv_ml
        opencv_photo
        opencv_stitching
        opencv_video
        opencv_dnn
)
set(libpqxx_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/packages/libpqxx_x64-mingw-dynamic/share/libpqxx)
set(libpqxx_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/installed/x64-mingw-dynamic/include)
set(libpqxx_LIBRARIES ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/installed/x64-mingw-dynamic/lib/libpqxx.dll.a)
set(PostgreSQL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/pgsql/include)
set(PostgreSQL_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/pgsql/lib/libpq.dll)
set(CURL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/curl)
set(CURL_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/curl/include)
set(CURL_LIBRARY ${CMAKE_CURRENT_SOURCE_DIR}/curl/lib/libcurl.dll.a)
set(jsoncpp_DIR ${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp)
set(jsoncpp_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp/include)
set(jsoncpp_LIBRARIES ${CMAKE_CURRENT_SOURCE_DIR}/jsoncpp/libjsoncpp.a)

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(PostgreSQL REQUIRED)
include_directories(${PostgreSQL_INCLUDE_DIR})

find_package(libpqxx CONFIG REQUIRED)
include_directories(${libpqxx_INCLUDE_DIRS})

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

include_directories(${jsoncpp_INCLUDE_DIR})

add_executable(cpp_proj
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ui_mainwindow.h
        SHA-256.cpp
        SHA-256.h
        list.h
        student.cpp
        student.h
)

target_link_libraries(cpp_proj
        Qt::Core
        Qt::Gui
        Qt::Widgets
        libpqxx::pqxx
        ${CURL_LIBRARIES}
        ${OpenCV_LIBS}
        ${PostgreSQL_LIBRARY}
        ${jsoncpp_LIBRARIES}
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

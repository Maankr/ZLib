cmake_minimum_required(VERSION 3.14)

if (WIN32)
    project(ZLib LANGUAGES CXX)
elseif(UNIX)
    project(ZLib)
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC source/*.cpp source/*.h)  # Изменил путь к поиску исходных файлов

include_directories(source)  # Включение директории с исходными файлами

add_executable(ZLib ${SRC})  # Добавление найденных исходных файлов к исполняемому файлу

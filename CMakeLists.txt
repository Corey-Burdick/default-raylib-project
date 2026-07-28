cmake_minimum_required(VERSION 4.2)
project(default C CXX)

include(FetchContent)

set(MY_SOURCES
  src/main.cpp
  src/game.cpp
)

if(EMSCRIPTEN)
  set(CMAKE_EXECUTABLE_SUFFIX ".html")
  set(ASSET_DIR "${CMAKE_CURRENT_SOURCE_DIR}/assets")
endif()

if(WIN32)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -static")
endif()

set(RAYLIB_VERSION 6.0)

FetchContent_Declare(
  raylib
  URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
)
FetchContent_MakeAvailable(raylib)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${CMAKE_PROJECT_NAME} ${MY_SOURCES})

if(WIN32)
  set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
endif()

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC include)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE raylib)

if(EMSCRIPTEN)
  target_compile_options(${PROJECT_NAME} PRIVATE "-DPLATFORM_WEB")
  target_link_options(${PROJECT_NAME} PRIVATE
        "-sUSE_GLFW=3"         # raylib requires GLFW3 emulation
        "-sASYNCIFY"           # Allows infinite loops (Window loops) to run on web
        "-sALLOW_MEMORY_GROWTH=1"
        "--preload-file=${ASSET_DIR}@/assets"
    )
endif()

file(COPY "assets"
  DESTINATION "${CMAKE_CURRENT_BINARY_DIR}"
)

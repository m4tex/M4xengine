cmake_minimum_required(VERSION 3.25)
project(M4xEngine C CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

# GLFW
set(GLFW_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/glfw")
set(GLFW_INCLUDE_DIR "${GLFW_DIR}/include")
set(GLFW_LIBRARY "${GLFW_DIR}/lib-mingw-w64/glfw3.dll")

# GLEW

set(GLEW_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/glew")
set(GLEW_INCLUDE_DIR "${GLEW_DIR}/include")
set(GLEW_LIBRARY "${GLEW_DIR}/lib/Release/x64/glew32.lib")

include_directories(include vendor)
include_directories(${GLFW_INCLUDE_DIR})
include_directories(${GLEW_INCLUDE_DIR})

find_package(OpenGL REQUIRED)

add_executable(M4xEngine src/main.cpp src/IndexBuffer.cpp src/Renderer.cpp src/Shader.cpp src/SolarObject.cpp src/Texture.cpp src/VertexArray.cpp src/VertexBuffer.cpp vendor/imgui/imgui.cpp vendor/imgui/imgui_draw.cpp vendor/imgui/imgui_impl_glfw.cpp vendor/imgui/imgui_impl_opengl3.cpp vendor/imgui/imgui_impl_opengl3_loader.h vendor/imgui/imgui_internal.h vendor/imgui/imgui_tables.cpp vendor/imgui/imgui_widgets.cpp vendor/imgui/imstb_rectpack.h vendor/imgui/imstb_textedit.h vendor/imgui/imstb_truetype.h vendor/stb_image/stb_image.cpp)
target_link_libraries(M4xEngine ${GLEW_LIBRARY} ${GLFW_LIBRARY} ${OPENGL_gl_LIBRARY})
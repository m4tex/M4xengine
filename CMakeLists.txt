cmake_minimum_required(VERSION 3.25)
project(M4xEngine C CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")

# GLFWSE
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

add_executable(M4xEngine src/main.cpp src/rendering/IndexBuffer.cpp src/rendering/Renderer.cpp src/rendering/Shader.cpp src/rendering/M4xObject.cpp src/rendering/Texture.cpp src/rendering/VertexArray.cpp src/rendering/VertexBuffer.cpp vendor/imgui/imgui.cpp vendor/imgui/imgui_draw.cpp vendor/imgui/imgui_impl_glfw.cpp vendor/imgui/imgui_impl_opengl3.cpp vendor/imgui/imgui_tables.cpp vendor/imgui/imgui_widgets.cpp vendor/stb_image/stb_image.cpp src/engine/Input.cpp include/engine/Input.h src/engine/Scene.cpp include/engine/Scene.h src/engine/Blueprint.cpp include/engine/Blueprint.h src/game/game.cpp include/game/game.h src/game/Terrain.cpp include/game/Terrain.h src/game/TestObject.cpp include/game/TestObject.h)
target_link_libraries(M4xEngine ${GLEW_LIBRARY} ${GLFW_LIBRARY} ${OPENGL_gl_LIBRARY})

file(COPY res/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
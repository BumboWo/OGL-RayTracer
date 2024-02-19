# CMakeList.txt : CMake project for OGL RayTracer, include source and define
# project specific logic here.
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glew CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)


add_executable (CMakeTarget "src/OGL RayTracer.cpp"  "src/Camera/Camera.cpp" "src/Renderer/Renderer.cpp"  "src/uiManager/uiManager.cpp"  )

# TODO: Add tests and install targets if needed.
target_link_libraries(CMakeTarget PRIVATE glfw glm::glm glad::glad GLEW::GLEW imgui::imgui)

# TODO: Add tests and install targets if needed.

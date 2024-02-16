// uiManager.cpp
#include "uiManager.hpp"
#include <iostream>

UIManager::UIManager(GLFWwindow* window) : window(window) {
    // Initialize ImGui
    InitializeImGui();
}

UIManager::~UIManager() {
    // Cleanup ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

void UIManager::InitializeImGui() {
    // Setup ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

    // Enable docking
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

    // Setup ImGui style
    ImGui::StyleColorsDark();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

void UIManager::RenderUI(Scene& _scene, GLuint textureID) {
    // Start the ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    // Begin the main window with docking
    ImGui::Begin("Docking Window", nullptr,
        ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_MenuBar);

    // Set window position and size to cover the entire screen
    ImGui::SetWindowPos(ImVec2(0, 0));
    ImGui::SetWindowSize(ImGui::GetIO().DisplaySize);

    // Dockspace setup
    ImGuiIO& io = ImGui::GetIO();
    if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable) {
        ImGuiID dockspace_id = ImGui::GetID("DockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_None);
    }
    ImGui::SetWindowFontScale(1.3);
    // End the main window
    ImGui::End();

    //---------------------------------------------------------
    //ViewPort

    ImGui::Begin("Viewport");
    viewportSize = ImGui::GetWindowSize();
    viewportSize.y -= 35;

    ImGui::Image((void*)(intptr_t)textureID, viewportSize);

    // Check if the mouse is being dragged (moved)
    if (ImGui::IsMouseDragging) {
        double deltaX = ImGui::GetMouseDragDelta().x;
        double deltaY = ImGui::GetMouseDragDelta().y;

        _scene.godCam.Rotate(glm::vec3(0.0f, deltaX * 0.01f, deltaY * 0.01f));
    }

    ImGui::End();


    //---------------------------------------------------------
    //Debug 

    ImGui::Begin("Debug");

    ImGui::Text("Width: %.2f", viewportSize.x);
    ImGui::Text("Height: %.2f", viewportSize.y);

    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> deltaTime = currentTime - lastFrameTime;
    lastFrameTime = currentTime;

    ImGui::Text("Time since last frame: %.6f milliseconds", deltaTime.count() * 1000);

    // Calculate FPS
    fpsCounterBuffer += deltaTime.count();
    if (fpsCounterBuffer >= 0.3f) {
        fpsCounterBuffer = 0.0f;
        fps = 1 / deltaTime.count();
    }
    ImGui::Text("Frames Per Second: %.0f ", fps);

    ImGui::Text("Camera X : %f", _scene.godCam.rotation.x);
    ImGui::Text("Camera Y : %f", _scene.godCam.rotation.y);
    ImGui::Text("Camera Z : %f", _scene.godCam.rotation.z);

    ImGui::End();


    //---------------------------------------------------------
    //Heirarchy

    ImGui::Begin("Hierarchy");

    /*const std::vector<std::shared_ptr<Object>>& sceneObjects = _scene.getObjects();
    static std::shared_ptr<Object> selectedObject = nullptr;

    for (const auto& object : sceneObjects) {
        if (ImGui::Selectable(object->name.c_str(), selectedObject == object)) {
            // If the current object is clicked, update the selectedObject
            selectedObject = object;
        }
    }*/

    ImGui::End();

    //---------------------------------------------------------


    //---------------------------------------------------------
    //Inspector

    ImGui::Begin("Inspector");

    /*// Ensure that a valid object is selected
    if (selectedObject) {
        // Buffer to hold the modified name
        static char objectNameBuffer[256];

        // Copy the selected object's name to the buffer
        strncpy(objectNameBuffer, selectedObject->name.c_str(), sizeof(objectNameBuffer));

        // InputText for editing the name
        if (ImGui::InputText("Object Name", objectNameBuffer, sizeof(objectNameBuffer))) {
            // If the input text changes, update the name of the selected object
            selectedObject->name = objectNameBuffer;
        }

        // If the input text is empty, revert to the original name
        if (strlen(objectNameBuffer) == 0) {
            selectedObject->name = "OriginalName"; // Replace "OriginalName" with the desired default name
        }

        const std::shared_ptr<Transform>& objectTransform = selectedObject->transform;
        if (ImGui::CollapsingHeader("Transform")) {
            ImGui::InputFloat3("Position", glm::value_ptr(objectTransform->position));
            ImGui::InputFloat3("Rotation", glm::value_ptr(objectTransform->rotation));
            ImGui::InputFloat3("Scale", glm::value_ptr(objectTransform->scale));
        }


        // Access and display the components of the selected object
        const std::vector<std::shared_ptr<Component>>& objectComponents = selectedObject->components;

        for (const auto& component : objectComponents) {

            if (component->name == "SphereRenderer") {
                if (ImGui::CollapsingHeader("Sphere Renderer")) {
                    ImGui::Text("e");
                }
            }

        }

    }
    */

    ImGui::End();

    //---------------------------------------------------------


    //---------------------------------------------------------
    //Project

    ImGui::Begin("Project");


    ImGui::End();

    //---------------------------------------------------------
    // More UI rendering code...

    // Render ImGui
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}


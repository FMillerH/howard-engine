#include "path02.h"
#include <iostream>
#include <raylib.h>
#include <vector>

#include "../../ImportedUI/ToolsUI00/DefaultUI/defaultUI.h"
#include "BouncingSquare/Assets/player.h"
#include "BouncingSquare/Assets/map.h"


class Menu;

void runWindow02() {

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);



    auto OriginX = 400;
    auto OriginY = 400;

    // U = {z | 1/2 ≤ x ≤ 2; -pi/4 ≤ Arg(z) ≤ pi/2}
    // U = {z | 450 ≤ x ≤ 600; -pi/4 ≤ Arg(z) ≤ pi/2}

    std::vector<std::string> labels = {"one", "two", "three"};

    std::unique_ptr<Menu> menu = DefaultUI::buildDefaultMenu("test", labels);


    InitWindow(800, 600, "Raylib C++ Example");
    float x = 3.0;
    float y = 4.0;
    float z = 4.0;

    float theta = 0.0f;

    Camera3D camera = { 0 };
    camera.position = (Vector3){ x*cos(theta), y, z*sin(theta) }; // position in the xyz plane
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f }; // position toward which camera is pointed
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;


    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_DOWN)) {
            std::cout << "down" << std::endl;
            camera.position.x += 0.01;
        }

        if (IsKeyDown(KEY_UP)) {
            camera.position.y += 0.01;
        }

        if (IsKeyDown(KEY_RIGHT)) {
            theta += 0.001;
            camera.position.x = x*cos(theta);
            camera.position.z = z*sin(theta);
        }

        if (IsKeyDown(KEY_P)) {
            camera.position.z += 0.25;
        }


        BeginDrawing();
        ClearBackground(BLACK);

        // DrawLine(400, 0, 400, 600, WHITE);
        // DrawLine(0, 300, 800, 300, WHITE);
        //
        // DrawCircle(450, 300, 10.0, RED);
        // DrawCircle(600, 300, 10.0, RED);

        BeginMode3D(camera);

        DrawCube((Vector3){ .x = 0.0f, .y = 0.0f, .z = 0.0f }, 2.0f, 2.0f, 2.0f, RED);
        DrawCubeWires((Vector3){ .x = 0.0f, .y = 0.0f, .z = 0.0f }, 2.0f, 2.0f, 2.0f, MAROON);


        DrawLine3D({.x = -100.0f, .y = 0.0f, .z = 0.0f}, {.x = 100.0f, .y = 0.0f, .z = 0.0f },  RED);
        DrawLine3D({.x = 0.0f, .y = -100.0f, .z = 0.0f}, {.x = 0.0f, .y = 100.0f, .z = 0.0f },  RED);
        DrawLine3D({.x = 0.0f, .y = 0.0f, .z = -100.0f}, {.x = 0.0f, .y = 0.0f, .z = 100.0f },  RED);



        EndMode3D();



        EndDrawing();
    }

    CloseWindow();
}

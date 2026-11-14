#include "pathSandbox.h"

#include <iostream>

#include "raylib.h"
#include <string>

#include "../../Application/application.h"
#include "../../Controller/controller.h"
#include "../../Example/exampleGame2D.h"

void runSandboxPath() {

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetConfigFlags(FLAG_WINDOW_HIGHDPI);
    int width = 1000;
    int height = 800;

    InitWindow(width, height, "Raylib + C++ Example");
    SetWindowMinSize(300, 200);


    std::unique_ptr<Application> app = std::make_unique<Application>(width, height);


    while (!WindowShouldClose()) {



        app->update(GetScreenWidth(), GetScreenHeight());




        BeginDrawing();
        ClearBackground(BLACK);

        //BeginScissorMode(200, 200, 600, 400); //todo


        app->draw();

        //EndScissorMode();
        EndDrawing();
    }

    CloseWindow();
}

cmake_minimum_required(VERSION 3.16)
project(H03_01)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

include(FetchContent)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG        5.5
        GIT_SHALLOW    TRUE
)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

add_executable(H03_01 main.cpp
        ImportedUI/ToolsUI00/Button/button.cpp
        ImportedUI/ToolsUI00/Button/button.h
        ImportedUI/ToolsUI00/Container/container.cpp
        ImportedUI/ToolsUI00/Container/container.h
        ImportedUI/ToolsUI00/DefaultUI/defaultUI.cpp
        ImportedUI/ToolsUI00/DefaultUI/defaultUI.h
        ImportedUI/ToolsUI00/Menu/menu.cpp
        ImportedUI/ToolsUI00/Menu/menu.h
        ImportedUI/ToolsUI00/Placer/placer.cpp
        ImportedUI/ToolsUI00/Placer/placer.h
        Sandbox/Scene/scene.cpp
        Sandbox/Scene/scene.h
        Sandbox/SceneGraph/sceneGraph.cpp
        Sandbox/SceneGraph/sceneGraph.h
        Sandbox/Primes/primes.cpp
        Sandbox/Primes/primes.h
        ImportedUI/UIenv/UIE.cpp
        ImportedUI/UIenv/UIE.h
        LightTextParser/lightTextParser.cpp
        LightTextParser/lightTextParser.h
        ImportedUI/ToolsUI00/buttonMap.cpp
        ImportedUI/ToolsUI00/buttonMap.h
        Sandbox/SCENEenv/SCENEenv.cpp
        Sandbox/SCENEenv/SCENEenv.h
        Sandbox/Scene/SceneList/mainMenuScene.cpp
        Sandbox/Scene/SceneList/mainMenuScene.h
        Windows/Path01/path01.cpp
        Windows/Path01/path01.h
        Windows/Path02/path02.cpp
        Windows/Path02/path02.h
        Example/exampleGame2D.cpp
        Example/exampleGame2D.h
        LightTextParser/hwd.cpp
        LightTextParser/hwd.h
        ImportedUI/ButtonActions/actions.cpp
        ImportedUI/ButtonActions/actions.h
        Sandbox/Scene/SceneList/centerScene.cpp
        Sandbox/Scene/SceneList/centerScene.h
        Example/player.cpp
        Example/player.h
        Controller/controller.cpp
        Controller/controller.h
        Windows/Path02/BouncingSquare/Assets/player.cpp
        Windows/Path02/BouncingSquare/Assets/player.h
        Windows/Path02/BouncingSquare/Assets/map.cpp
        Windows/Path02/BouncingSquare/Assets/map.h
        Windows/Path02/BouncingSquare/Physics/physics.cpp
        Windows/Path02/BouncingSquare/Physics/physics.h
        Windows/Exceptions/fail.cpp
        Windows/Exceptions/fail.h
)

#target_compile_options(H03_01 PRIVATE -fsanitize=address -fsanitize=undefined)
#target_link_options(H03_01 PRIVATE -fsanitize=address -fsanitize=undefined)

target_link_libraries(H03_01 PRIVATE raylib)

cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(opengl-gdal-tutorial)

#set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
find_package(GDAL CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

add_definitions(-DGLM_ENABLE_EXPERIMENTAL)
include_directories("./code/include")

function(add_tutorial base_directory target_name code_sources)
    file(GLOB sources "${base_directory}/src/*.cpp")
    add_executable(${target_name} ${sources} ${code_sources})   
    target_include_directories(${target_name} PRIVATE "${base_directory}/include")
    target_link_libraries(${target_name} PRIVATE ${OPENGL_LIBRARIES} ${GDAL_LIBRARIES})
    target_link_libraries(${target_name} PRIVATE glm::glm)
    target_link_libraries(${target_name}
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
    )
endfunction()


set(code_sources ./code/src/AssetManager.cpp  
./code/src/buffer.cpp
./code/src/camera.cpp
./code/src/framerenderer.cpp
./code/src/gbuffer.cpp
./code/src/gishandler.cpp
./code/src/renderer.cpp
./code/src/shader.cpp
./code/src/terrain.cpp
)

## Tutorials

add_tutorial("tutorial1" "tut01" "")
add_tutorial("tutorial2" "tut02" "${code_sources}")
add_tutorial("tutorial3" "tut03" "${code_sources}")
add_tutorial("tutorial4-1" "tut04-1" "${code_sources}")
add_tutorial("tutorial4-2" "tut04-2" "${code_sources}")
add_tutorial("tutorial5" "tut05" "${code_sources}")
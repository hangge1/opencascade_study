cmake_minimum_required(VERSION 3.31)

project(OCC_CMAKE_TEST CXX)

set(CMAKE_PREFIX_PATH "D:/code_project/OCC_DEMO/occ-install/cmake";${CMAKE_PREFIX_PATH})
find_package(OpenCASCADE REQUIRED)

set(CMAKE_PREFIX_PATH "D:/code_project/OCC_DEMO/vtk-install/lib/cmake/vtk-9.0";${CMAKE_PREFIX_PATH})
find_package(VTK COMPONENTS 
  CommonColor
  CommonCore
  FiltersSources
  InteractionStyle
  RenderingContextOpenGL2
  RenderingCore
  RenderingFreeType
  RenderingGL2PSOpenGL2
  RenderingOpenGL2
)

if (NOT VTK_FOUND)
  message(FATAL_ERROR "${PROJECT_NAME}: Unable to find the VTK build folder.")
endif()

add_executable(OCC_CMAKE_TEST TestOCC1.cpp)

target_include_directories(OCC_CMAKE_TEST PRIVATE ${OpenCASCADE_INCLUDE_DIR})
target_link_directories(OCC_CMAKE_TEST PRIVATE ${OpenCASCADE_LIBRARY_DIR})

foreach(LIB ${OpenCASCADE_LIBRARIES})
    target_link_libraries(OCC_CMAKE_TEST debug ${LIB}) 
    #message("OpenCASCADE_LIBRARY_DIR = ${OpenCASCADE_LIBRARY_DIR}")
    #message("LIB = ${LIB}")
endforeach()


if(MSVC)
    set_property(TARGET OCC_CMAKE_TEST PROPERTY VS_DEBUGGER_ENVIRONMENT "PATH=D:/code_project/OCC_DEMO/vtk-install/bin;D:/code_project/OCC_DEMO/occ-install/win64/vc14/bind;$ENV{PATH}")
endif()


vtk_module_autoinit(
  TARGETS OCC_CMAKE_TEST
  MODULES ${VTK_LIBRARIES}
)
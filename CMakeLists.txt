cmake_minimum_required(VERSION 3.31)

project(OCC_CMAKE_TEST CXX)

list(APPEND CMAKE_PREFIX_PATH "D:/code_project/OCC_DEMO/occ-install/cmake")
list(APPEND CMAKE_PREFIX_PATH "D:/code_project/OCC_DEMO/vtk-install/lib/cmake/vtk-9.0")

find_package(OpenCASCADE REQUIRED)
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


message("OpenCASCADE_INCLUDE_DIR = ${OpenCASCADE_INCLUDE_DIR}")
include_directories(${OpenCASCADE_INCLUDE_DIR})

# excluede dir name
set(EXCLUDE_DIRS "build" ".git" "__pycache__")

# find sub dir and call it for add_subdirectory
file(GLOB SUBDIRS LIST_DIRECTORIES true "${CMAKE_CURRENT_SOURCE_DIR}/*")
foreach(SUBDIR IN LISTS SUBDIRS)
    if(IS_DIRECTORY ${SUBDIR})
        get_filename_component(DIR_NAME ${SUBDIR} NAME)
        if(NOT DIR_NAME IN_LIST EXCLUDE_DIRS)
            #message(STATUS "Included subdirectory: ${DIR_NAME}")
            add_subdirectory(${DIR_NAME})
        endif()
    endif()
endforeach()



# 获取当前 CMakeLists.txt 所在目录的路径
set(CURRENT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
# 提取目录名（最后一个路径部分）
get_filename_component(FOLDER_NAME ${CURRENT_DIR} NAME)
#message(STATUS "Current folder name: ${FOLDER_NAME}")

set(TARGETNAME  ${FOLDER_NAME})

# get source files
file(GLOB SRCS "*.cpp")


add_executable(${TARGETNAME} ${SRCS})

target_include_directories(${TARGETNAME}  PRIVATE ${OpenCASCADE_INCLUDE_DIR})
target_link_directories(${TARGETNAME}  PRIVATE ${OpenCASCADE_LIBRARY_DIR})

foreach(LIB ${OpenCASCADE_LIBRARIES})
    target_link_libraries(${TARGETNAME}  debug ${LIB}) 
    #message("OpenCASCADE_LIBRARY_DIR = ${OpenCASCADE_LIBRARY_DIR}")
    #message("LIB = ${LIB}")
endforeach()


if(MSVC)
    set_property(TARGET ${TARGETNAME}  PROPERTY VS_DEBUGGER_ENVIRONMENT "PATH=D:/code_project/OCC_DEMO/vtk-install/bin;D:/code_project/OCC_DEMO/occ-install/win64/vc14/bind;$ENV{PATH}")
endif()


vtk_module_autoinit(
  TARGETS ${TARGETNAME} 
  MODULES ${VTK_LIBRARIES}
)
cmake_minimum_required(VERSION 3.10)

#设定项目名称
project(IntroCV)

#设定路径变量
set(opencv_root "D:/OpenCV4/opencv")
set(opencv_include ${opencv_root}/build/include)
set(opencv_lib_dir ${opencv_root}/build/x64/vc15/lib)
set(opencv_libs opencv_world451d.lib)

#设定noise代码文件路径
set(NOISE "./noise/noise.cpp" "./noise/noise.h")

#查找指定目录下所有cpp与h文件，并存放到指定变量名SC_FILES中
FILE(GLOB SC_FILES "*.cpp", "*.h")
#设定include
include_directories(${opencv_include})

#设定lib位置
link_directories(${opencv_lib_dir})
#设定引用的lib名称
link_libraries(${opencv_libs})

#将NOISE源码分组到NOISE组里
source_group(noise FILES ${NOISE})

#设定输出名称"IntroCV"
add_executable(IntroCV ${SC_FILES} ${NOISE})
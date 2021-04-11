cmake_minimum_required(VERSION 3.10)

#设定项目名称
project(IntroCV)

#设定路径变量
set(opencv_root "D:/OpenCV4/opencv")
set(opencv_include ${opencv_root}/build/include)
set(opencv_lib_dir ${opencv_root}/build/x64/vc15/lib)
set(opencv_libs opencv_world451d.lib)

#设定include
include_directories(${opencv_include})
include_directories("G:/IntroCV/UdacityIntroToCV")
#设定lib位置
link_directories(${opencv_lib_dir})
#设定引用的lib名称
link_libraries(${opencv_libs})

#设定输出名称"IntroCV"
add_executable(IntroCV main.cpp)
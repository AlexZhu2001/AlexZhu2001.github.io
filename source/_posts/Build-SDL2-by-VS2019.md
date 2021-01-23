---
title: Build SDL2 by VS2019
date: 2021-01-21 21:18:12
tags: 
    - VS2019
    - SDL2
    - BuildForWindows
    - CMake
---
# 使用CMake GUI 完成SDL2的编译（MSVC2019）
---
### Step1.CMake设置
    打开CMake(GUI) 设置源码所在文件夹以及存放build文件的文件夹
{% asset_img 1.png Settings1 %}
    点击Configure 选择 Visual Studio 16 2019 Finish
{% asset_img 2.png Settings2 %}
    等待生成文件

### Step2.设置安装目录
    修改 CMAKE_INSTALL_PREFIX 的变量值
    点击Generate
{% asset_img 3.png Prefix Setting %}

### Step3.开始编译
    以管理员身份打开VS2019 打开设置的build存放目录下的SDL2.sln
    右击INSTALL 生成 等待编译和复制完成
{% asset_img 4.png Build With VS2019 %}
{% asset_img 5.png Build Success %}







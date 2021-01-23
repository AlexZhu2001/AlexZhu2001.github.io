---
title: SDL_DAY1
date: 2021-01-22 18:42:16
tags: 
    - SDL2
    - CMake
---
#
|函数名|函数作用|备注|
|:---:|:---:|:---:|
|SDL_Init|初始化SDL2||
|SDL_CreateWindow|创建窗口||
|SDL_ShowWindow|显示窗口||

```c
#include <stdio.h>
#include <SDL2/SDL.h>

#define  WIDTH 400
#define HEIGHT 300
int main() {
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        SDL_Log("Error,%s",SDL_GetError());
    }
    SDL_Window *win=SDL_CreateWindow("HelloWorld",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_SHOWN);
    SDL_ShowWindow(win);
    SDL_Delay(5000);
    return 0;
}
```
{% asset_img 1.png 运行效果%}

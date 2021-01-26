---
title: SDL-DAY2
date: 2021-01-26 19:14:40
tags: SDL2
---
# SDL绘制
要在SDL的窗口中绘图 需要先获得 SDL_Surface
SDL提供了`SDL_GetWindowSurface(SDL_Window *)`来获得客户区的SDL_Surface
```c
SDL_Window *win=SDL_CreateWindow("HelloWorld",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                WIDTH,HEIGHT,
                                SDL_WINDOW_SHOWN);
SDL_Surface *screen=SDL_GetWindowsSurface(win);
```
获得了SDL_Surface之后 我们有两种方法可以绘制客户区
* <h4>利用SDL提供的函数</h4>
SDL提供了一些函数来方便绘制
例如 `SDL_FillRect(SDL_Surface *s,SDL_Rect *r,uint32_t color)`
其中 第三个参数是颜色值 按照ARGB顺序排列 每个值为八位
我们可以利用这个函数将客户区涂成白色

```c
SDL_Rect r={0,0,WIDTH,HEIGHT};
SDL_FillRect(screen,&r,0xffffffff);
```

* <h4>手动绘制</h4>
SDL_Surface是一个结构体,其定义如下

```c
typedef struct SDL_Surface
{
    Uint32 flags;               /**< Read-only */
    SDL_PixelFormat *format;    /**< Read-only */
    int w, h;                   /**< Read-only */
    int pitch;                  /**< Read-only */
    void *pixels;               /**< Read-write */

    /** Application data associated with the surface */
    void *userdata;             /**< Read-write */

    /** information needed for surfaces requiring locks */
    int locked;                 /**< Read-only */
    void *lock_data;            /**< Read-only */

    /** clipping information */
    SDL_Rect clip_rect;         /**< Read-only */

    /** info for fast blit mapping to other surfaces */
    struct SDL_BlitMap *map;    /**< Private */

    /** Reference count -- used when freeing surface */
    int refcount;               /**< Read-mostly */
} SDL_Surface;

```
我们需要关注其中的 w,h 和pixels
w h 分别是宽度和高度
而pixels是一个指向一块内存的指针 此处定义为`void * `实际使用时可转换为`uint32_t *`
他对应着屏幕上任意一点处的像素的颜色值 颜色定义为ARGB
而(x,y)处的的像素获取方式为`(uint32_t *)pixels[x*w+y]`
我们通过手动绘制来画一个100x100的方块 放置于(0,0)处
```c
uint32_t *p=(uint32_t *)screen->pixels;
for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
        p[i*screen->w+j]=0xff0000ff;//ARGB Blue 100%
    }
}
```
# SDL2事件循环
SDL为事件处理提供了灵活的API，当收到来自设备的事件时，SDL会将其存入事件队列等待取出
在程序中，应当有一个循环来处理这些事件，每次循环时应从中取出事件并处理它
SDL 提供了 `SDL_PollEvent(SDL_Event *)`函数来提供取出事件的功能
如果对列中还有事件 则会取出事件存入SDL_Event类型的变量中 并返回一个非零值 否则返回零
轮询事件后，您可以在逻辑链中响应它。
为了方便阅读 通常会将循环抽出写成一个函数
```c
void eventloop(){
    SDL_Event e;
    while(1){
        while(SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_QUIT:
                    return;
                default:
                    break;
            }
        }
    }
}
```
{% asset_img 1.png 运行效果 %}
[代码](https://github.com/2018-EPI-GROUP/2020Freshman/tree/%E9%80%9A%E5%B7%A52009-%E6%9C%B1%E5%BD%A6%E6%99%9F/SDL2/SDL2-02)
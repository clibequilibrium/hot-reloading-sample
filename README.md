# hot-reloading-sample

This sample demonstrates usage of cr.h hot reloading header-only library. The primary goal of it is to increase iteration speed and bring quality of development.
In this repository you may find both hot reloadable lib.dll and app.dll which allows you to develop both core library and sample application with the abillity to hot reload. 

## Third Party libraries
This repo also features a branch for ECS library [flecs](https://github.com/clibequilibrium/hot-reloading-sample/tree/flecs) which has a sample of how to reload system function pointers which could be useful to iterate on your systems without reloading your application. It works because all the application state is stored in the world with and entities / components. 

## In action

![Sample](Animation.gif)

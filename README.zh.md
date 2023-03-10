# NovelCraft C语言的SDK

如果你只想浏览一下API文档，你可以这样做[这里](https://novelcraft.github.io/SDK-C/zh/globals_func.html)。

## 简介

NovelCraft SDK for C语言是一个C语言库，允许开发者为NovelCraft创建代理，这是一个可扩展的开源沙盒平台，灵感来自Minecraft。NovelCraft也是一个图像和符号世界状态的数据集，该数据集由在视频游戏世界中完成pogo-stick组装任务的代理看到。通过NovelCraft C语言的SDK，开发者可以访问各种功能来控制代理的行动、感知和与环境的互动。该SDK还支持开放世界中的新奇事物检测和发现，其中新奇的物体会影响游戏的进行。NovelCraft C语言的SDK被设计成易于使用并与现有的C语言项目整合。它兼容于Windows、Linux和Mac OS平台。NovelCraft SDK for C语言是为NovelCraft开发新颖和创造性代理的强大工具。

## 安装

由于SDK使用CMake构建系统，你可以在任何支持CMake的平台上构建它。你可以使用`add_subdirectory`将SDK添加到你的项目中，然后使用`target_link_libraries`将SDK链接到你的项目。这样，你就可以在你的代码中访问SDK所定义的所有函数和类型。SDK还在examples文件夹中提供了一些NovelCraft的代理实例。你可以运行它们，看看它们是如何工作的，并根据你的需要修改它们。要运行一个例子，你需要在你的机器上安装NovelCraft并在CMakeLists.txt文件中指定可执行文件的路径。该SDK还附带了一份文档，解释了如何使用其功能以及如何针对不同的场景进行定制。

## 用法

### 初始化

在使用SDK之前，你需要用配置来初始化SDK。配置指定了SDK的一些参数，如NovelCraft服务器的IP地址和端口，以及代理的token。你可以使用`ncsdk_Initialize`函数用配置结构来初始化SDK。配置结构是一个C结构，它有每个参数的字段。如果你想动态地改变一些参数，你可以手动创建配置结构。初始化SDK后，代理将自动连接到NovelCraft服务器并开始接收游戏信息。

下面是一个例子。

```c
#include <sdk.h>

int main() {
  struct ncsdk_Config config = {
    .host = "example.com",
    .port = 14514,
    .token = "0123456789abcdef"
  };

  ncsdk_Initialize(&config);
}
```

### 获取游戏信息

SDK提供了一些函数来获取游戏信息。你可以使用这些函数来查询游戏世界的状态，其中的对象，以及代理本身。例如，你可以使用`ncsdk_GetBlocks`函数来获得一个世界结构，其中包含了游戏世界中的块的信息。你可以使用`ncsdk_GetEntities`函数得到一个实体结构数组，其中包含游戏世界中每个实体的类型、位置、方向和属性的信息。你可以使用`ncsdk_GetAgent`函数来获得一个代理结构，其中包含关于代理的名称、ID、位置、方向、健康、库存和行动的信息。

下面是一个例子。

```c
#include <sdk.h>

void example() {
  // 获取位于(0, 0, 0)的块。
  struct ncsdk_BlockSource* blocks = ncsdk_GetBlocks();
  结构 ncsdk_Position_Int position {
    .x = 0,
    .y = 0,
    .z = 0
  };
  struct ncsdk_Block* block = ncsdk_BlockSource_Get(block, &position);
  int block_type = ncsdk_Block_GetTypeId(block);

  // 获取具有唯一ID 114的实体的位置。
  struct ncsdk_EntitySource* entities = ncsdk_GetEntities();
  struct ncsdk_Entity* entity = ncsdk_EntitySource_Get(entities, 114);
  结构ncsdk_Position_Float* entity_position = ncsdk_Entity_GetPosition(entity)。
}
```

### 执行动作

通过代理API，你可以在游戏中执行动作。你可以使用这些API来控制你的代理的移动、旋转和跳跃。你还可以使用这些API与游戏世界中的物体进行互动，如拾取、丢弃、放置、使用和制作物品。

下面是一个例子。

```c
#include <sdk.h>

void example() {
  struct ncsdk_Agent* agent = ncsdk_GetAgent();

  // 获取代理的位置。
  struct ncsdk_Position_Float* position = ncsdk_Agent_GetPosition(agent);

  // 如果代理的y坐标小于10，那么代理将跳转。
  if (position->y < 10) {
    ncsdk_Agent_Jump(agent);
  }
}
```

## 接下来的步骤

要了解更多关于NovelCraft SDK for C语言的信息，你可以阅读API文档。你可以查看所有的API[这里](https://novelcraft.github.io/SDK-C/zh/globals_func.html)。你也可以查看例子文件夹中的例子。你可以运行它们，看看它们是如何工作的，并根据你的需要修改它们。要运行一个例子，你需要在你的机器上安装NovelCraft，并在CMakeLists.txt文件中指定可执行文件的路径。
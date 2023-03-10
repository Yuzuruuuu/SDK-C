# NovelCraft SDK for C Language

If you would just like to browse the API documentation, you can do so [here](https://novelcraft.github.io/SDK-C/en/globals_func.html).

## Introduction

NovelCraft SDK for C Language is a library for C language that allows developers to create agents for NovelCraft, a scalable open source sandbox platform inspired by Minecraft. NovelCraft is also a dataset of images and symbolic world-states seen by an agent completing a pogo-stick assembly task within a video game world. With NovelCraft SDK for C Language, developers can access various functions to control the agent’s actions, perceptions, and interactions with the environment. The SDK also supports novelty detection and discovery in open worlds, where novel objects can impact gameplay. NovelCraft SDK for C Language is designed to be easy to use and integrate with existing C projects. It is compatible with Windows, Linux, and Mac OS platforms. NovelCraft SDK for C Language is a powerful tool for developing novel and creative agents for NovelCraft.

## Installation

Since the SDK uses the CMake build system, you can build it on any platform that supports CMake. You can use `add_subdirectory` to add the SDK to your project, and then use `target_link_libraries` to link the SDK to your project. This way, you can access all the functions and types defined by the SDK in your code. The SDK also provides some examples of agents for NovelCraft in the examples folder. You can run them to see how they work and modify them to suit your needs. To run an example, you need to have NovelCraft installed on your machine and specify the path to the executable in the CMakeLists.txt file. The SDK also comes with a documentation that explains how to use its features and how to customize it for different scenarios.

## Usage

### Initialization

Before using the SDK, you need to initialize the SDK with configuration. The configuration specifies some parameters for the SDK, such as the IP address and port of the NovelCraft server, and the token of the agent. You can use `ncsdk_Initialize` function to initialize the SDK with a configuration structure. The configuration structure is a C struct that has fields for each parameter. You can create the configuration structure manually if you want to change some parameters dynamically. After initializing the SDK, the agent will automatically connect to the NovelCraft server and start receiving game information.

Here is an example:

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

### Get game information

The SDK provides a number of functions to get game information. You can use these functions to query the state of the game world, the objects in it, and the agent itself. For example, you can use `ncsdk_GetBlocks` function to get a world structure that contains information about the blocks of the game world. You can use `ncsdk_GetEntities` function to get an array of entity structures that contain information about the type, position, orientation, and properties of each entity in the game world. You can use `ncsdk_GetAgent` function to get an agent structure that contains information about the name, ID, position, orientation, health, inventory, and actions of your agent.

Here is an example:

```c
#include <sdk.h>

void example() {
  // Gets the block at (0, 0, 0).
  struct ncsdk_BlockSource* blocks = ncsdk_GetBlocks();
  struct ncsdk_Position_Int position {
    .x = 0,
    .y = 0,
    .z = 0
  };
  struct ncsdk_Block* block = ncsdk_BlockSource_Get(blocks, &position);
  int block_type = ncsdk_Block_GetTypeId(block);

  // Gets the position of the entity with unique ID 114.
  struct ncsdk_EntitySource* entities = ncsdk_GetEntities();
  struct ncsdk_Entity* entity = ncsdk_EntitySource_Get(entities, 114);
  struct ncsdk_Position_Float* entity_position = ncsdk_Entity_GetPosition(entity);
}
```

### Perform actions

With agent APIs, you can perform actions in the game. You can use these APIs to control the movement, rotation, and jumping of your agent. You can also use these APIs to interact with objects in the game world, such as picking up, dropping, placing, using, and crafting items.

Here is an example:

```c
#include <sdk.h>

void example() {
  struct ncsdk_Agent* agent = ncsdk_GetAgent();

  // Gets the position of the agent.
  struct ncsdk_Position_Float* position = ncsdk_Agent_GetPosition(agent);

  // If the y coordinate of the agent is less than 10, then the agent will jump.
  if (position->y < 10) {
    ncsdk_Agent_Jump(agent);
  }
}
```

## Next steps

To learn more about NovelCraft SDK for C Language, you can read the API documentation. You can check out all APIs [here](https://novelcraft.github.io/SDK-C/en/globals_func.html). You can also check out the examples in the examples folder. You can run them to see how they work and modify them to suit your needs. To run an example, you need to have NovelCraft installed on your machine and specify the path to the executable in the CMakeLists.txt file.
# BehaviorTree.CPP usage (no ROS 2)

The examples in this directory show how to use the BehaviorTree.CPP library
without ROS 2.

## Environment

Tested on Ubuntu 24.04 with GCC 13.3.0, but should work in any reasonably
modern Linux environment.

## Dependencies

All the dependencies are handled internally, including BehaviorTree.CPP itself.
You do not need to worry at all. Nothing will be installed outside this
repository.

## Build steps

You can just run build.sh or execute the following commands:

```bash
cmake . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel `nproc`
```

Afterwards you'll find the examples in the `bin/` folder.

## Available example

Soon.


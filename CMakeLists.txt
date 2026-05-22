cmake_minimum_required(VERSION 3.20)

project(
    NovaRT
    VERSION 0.1
    LANGUAGES CXX CUDA
)

# STANDARDS:

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_RUNTIME_LIBRARY Shared)

# Export compile_commands.json:

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# GPU architecture

set(CMAKE_CUDA_ARCHITECTURES 86)

# Global include dirs

include_directories(${PROJECT_SOURCE_DIR})

# SUBDIRECTORIES:

# add_subdirectory(core)
add_subdirectory(cuda)
# add_subdirectory(runtime)
# add_subdirectory(serving)
add_subdirectory(examples)
# add_subdirectory(tests)
# add_subdirectory(benchmarks)


add_executable(example_inference
    inference.cpp
)

target_link_libraries(example_inference
    PRIVATE cuda_kernels
)
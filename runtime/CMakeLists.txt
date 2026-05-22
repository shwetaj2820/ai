add_library(runtime
    runtime.cpp
)

target_link_libraries(runtime
    PUBLIC cuda_kernels
)
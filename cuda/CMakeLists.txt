add_library(cuda_kernels STATIC
    kernels.cu
)

target_include_directories(cuda_kernels PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

set_target_properties(cuda_kernels PROPERTIES
    CUDA_SEPARABLE_COMPILATION ON
    CUDA_RESOLVE_DEVICE_SYMBOLS ON
)
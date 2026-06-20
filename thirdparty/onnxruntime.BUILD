package(default_visibility = ["//visibility:public"])

cc_library(
    name = "onnxruntime",
    srcs = [
        "onnxruntime-linux-x64-gpu-1.15.0/lib/libonnxruntime.so",
        "onnxruntime-linux-x64-gpu-1.15.0/lib/libonnxruntime.so.1.15.0",
        "onnxruntime-linux-x64-gpu-1.15.0/lib/libonnxruntime_providers_shared.so",
    ],
    hdrs = glob(["onnxruntime-linux-x64-gpu-1.15.0/include/*.h"]),
    strip_include_prefix = "onnxruntime-linux-x64-gpu-1.15.0/include",
)

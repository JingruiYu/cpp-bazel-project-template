package(default_visibility = ["//visibility:public"])

cc_library(
    name = "onnxruntime",
    srcs = [
        "onnxruntime-linux-aarch64-1.15.0/lib/libonnxruntime.so",
        "onnxruntime-linux-aarch64-1.15.0/lib/libonnxruntime.so.1.15.0",
    ],
    hdrs = glob(["onnxruntime-linux-aarch64-1.15.0/include/*.h"]),
    strip_include_prefix = "onnxruntime-linux-aarch64-1.15.0/include",
)

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "hello_world",
    srcs = ["hello_world.cc"],
    defines = select({
        "//config:aarch64": ["ENABLE_AARCH64_EXAMPLE_FLAG"],
        "//conditions:default": [],
    }),
    deps = [
        "@ceres",
        "@eigen3",
        "@glog",
        "@opencv4",
    ] + select({
        "//config:aarch64": [
            "@com_github_onnxruntime_aarch64//:onnxruntime",
        ],
        "//conditions:default": [
            "@com_github_onnxruntime_x86_64//:onnxruntime",
        ],
    }),
)

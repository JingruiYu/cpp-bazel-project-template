package(default_visibility = ["//visibility:public"])

cc_library(
    name = "ceres",
    srcs = select({
        "@//config:aarch64": glob(["lib/aarch64-linux-gnu/libceres.so*"]),
        "//conditions:default": glob(["lib/x86_64-linux-gnu/libceres.so*"]),
    }),
    hdrs = glob(["include/**/*.h"]),
    includes = ["include"],
    deps = [
        "@eigen3",
        "@glog",
    ],
)

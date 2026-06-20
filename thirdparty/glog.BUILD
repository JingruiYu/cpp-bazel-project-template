package(default_visibility = ["//visibility:public"])

cc_library(
    name = "glog",
    srcs = select({
        "@//config:aarch64": glob(["lib/aarch64-linux-gnu/libglog*.so*"]),
        "//conditions:default": glob(["lib/x86_64-linux-gnu/libglog*.so*"]),
    }),
    hdrs = glob([
        "include/glog/**/*.h",
        "include/glog/**/*.hpp",
    ]),
    includes = ["include"],
)

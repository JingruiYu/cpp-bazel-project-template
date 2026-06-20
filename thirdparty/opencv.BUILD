package(default_visibility = ["//visibility:public"])

cc_library(
    name = "opencv4",
    srcs = select({
        "@//config:aarch64": glob(["lib/aarch64-linux-gnu/libopencv_*.so*"]),
        "//conditions:default": glob(["lib/x86_64-linux-gnu/libopencv_*.so*"]),
    }),
    hdrs = glob([
        "include/opencv4/**/*.h",
        "include/opencv4/**/*.hpp",
    ]),
    includes = ["include/opencv4"],
)

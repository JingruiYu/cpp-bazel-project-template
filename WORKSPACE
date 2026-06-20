load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_cc",
    sha256 = "2037875b9a4456dce4a79d112a8ae885bbc4aad968e6587dca6e64f3a0900cdf",
    strip_prefix = "rules_cc-0.0.9",
    urls = ["https://github.com/bazelbuild/rules_cc/releases/download/0.0.9/rules_cc-0.0.9.tar.gz"],
)

http_archive(
    name = "com_github_onnxruntime_x86_64",
    build_file = "@//thirdparty:onnxruntime.BUILD",
    sha256 = "2dc9d135e610cb9c91a6fcfcb33cad54e438829df2f2a1c5fad920797a8c104c",
    urls = [
        "https://github.com/microsoft/onnxruntime/releases/download/" +
        "v1.15.0/onnxruntime-linux-x64-gpu-1.15.0.tgz",
    ],
)

http_archive(
    name = "com_github_onnxruntime_aarch64",
    build_file = "@//thirdparty:onnxruntime_aarch64.BUILD",
    sha256 = "69656d8dd35633f52d79dbe5b82475a8c896c39a74eddaa8b95ae7daac0099c4",
    urls = [
        "https://github.com/microsoft/onnxruntime/releases/download/" +
        "v1.15.0/onnxruntime-linux-aarch64-1.15.0.tgz",
    ],
)

new_local_repository(
    name = "opencv4",
    build_file = "thirdparty/opencv.BUILD",
    path = "/usr",
)

new_local_repository(
    name = "eigen3",
    build_file = "thirdparty/eigen.BUILD",
    path = "/usr",
)

new_local_repository(
    name = "glog",
    build_file = "thirdparty/glog.BUILD",
    path = "/usr",
)

new_local_repository(
    name = "ceres",
    build_file = "thirdparty/ceres.BUILD",
    path = "/usr",
)

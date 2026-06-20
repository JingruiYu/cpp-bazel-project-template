#include <ctime>
#include <iostream>
#include <memory>
#include <string>
#include "Eigen/Dense"
#include "ceres/ceres.h"
#include "onnxruntime_cxx_api.h"
#include "opencv2/opencv.hpp"

namespace {

struct OneDimensionalResidual {
  template <typename Scalar>
  bool operator()(const Scalar* const variable, Scalar* residual) const {
    residual[0] = Scalar(10.0) - variable[0];
    return true;
  }
};

void PrintCurrentTime() {
  const std::time_t timestamp = std::time(nullptr);
  std::cout << "Current time: " << std::asctime(std::localtime(&timestamp));
}

void CheckOpenCV() {
  const cv::Mat matrix = (cv::Mat_<int>(3, 1) << 1, 2, 3);
  std::cout << "OpenCV matrix:\n" << matrix << "\n";
}

void CheckEigen() {
  Eigen::Matrix<double, 3, 1> vector;
  vector << 1.0, 2.0, 3.0;
  std::cout << "Eigen vector:\n" << vector << "\n";
}

void CheckCeres() {
  double variable = 5.0;
  ceres::Problem problem;
  auto cost_function = std::make_unique<
      ceres::AutoDiffCostFunction<OneDimensionalResidual, 1, 1>>(
      new OneDimensionalResidual);
  problem.AddResidualBlock(cost_function.release(), nullptr, &variable);

  ceres::Solver::Options options;
  options.max_num_iterations = 20;
  options.linear_solver_type = ceres::DENSE_QR;

  ceres::Solver::Summary summary;
  ceres::Solve(options, &problem, &summary);
  std::cout << "Ceres optimized value: " << variable
            << ", final cost: " << summary.final_cost << "\n";
}

void CheckOnnxRuntime() {
  Ort::Env environment(ORT_LOGGING_LEVEL_WARNING, "hello_world");
  Ort::SessionOptions session_options;
  std::cout << "ONNX Runtime environment initialized.\n";
}

std::string BuildGreeting(const std::string& name) {
  return "Hello, " + name + "!";
}

}  // namespace

int main(int argument_count, char** argument_values) {
  std::string name = "Bazel";
  if (argument_count > 1) {
    name = argument_values[1];
  }

  std::cout << BuildGreeting(name) << "\n";
  PrintCurrentTime();
  CheckOpenCV();
  CheckEigen();
  CheckCeres();
  CheckOnnxRuntime();

#ifdef ENABLE_AARCH64_EXAMPLE_FLAG
  std::cout << "aarch64 Bazel config flag is enabled.\n";
#endif

  return 0;
}

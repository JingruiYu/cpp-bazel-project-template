#!/usr/bin/env bash
set -euo pipefail

platform_name="${1:-ubuntu-x86_64}"
docker_image_name="${IMAGE_NAME:-cpp_bazel_project_template}:${platform_name}"
repository_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

docker run -it --rm \
  --network=host \
  -v "${repository_root}:/workspace" \
  -w /workspace \
  "${docker_image_name}" \
  bash

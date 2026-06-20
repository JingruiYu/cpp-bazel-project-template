#!/usr/bin/env bash
set -euo pipefail

platform_name="${1:-ubuntu-x86_64}"
docker_image_repository="${IMAGE_NAME:-cpp_bazel_project_template}"
repository_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

case "${platform_name}" in
  ubuntu-x86_64)
    dockerfile_path="${repository_root}/docker/Dockerfile.ubuntu-x86_64"
    ;;
  ubuntu-arm64)
    dockerfile_path="${repository_root}/docker/Dockerfile.ubuntu-arm64"
    ;;
  *)
    echo "Unsupported platform: ${platform_name}" >&2
    echo "Usage: $0 [ubuntu-x86_64|ubuntu-arm64]" >&2
    exit 1
    ;;
esac

docker build \
  --build-arg user_id="$(id -u)" \
  --build-arg user_name="$(whoami)" \
  --build-arg workspace_path="/workspace" \
  -t "${docker_image_repository}:${platform_name}" \
  -f "${dockerfile_path}" \
  "${repository_root}"

FROM debian:12

# Avoid interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# Install build tools, pkg-config, MariaDB headers, Java (for Bazel) & curl
RUN apt-get update && apt-get install -y \
    build-essential \
    pkg-config \
    libmariadb-dev \
    default-jdk \
    curl \
    gnupg \
    unzip \
    zip \
    && rm -rf /var/lib/apt/lists/*

# Install Bazelisk (wrapper for Bazel) for aarch64
RUN curl -Lo /usr/local/bin/bazel \
      https://github.com/bazelbuild/bazelisk/releases/download/v1.15.0/bazelisk-linux-arm64 \
    && chmod +x /usr/local/bin/bazel

# Set working directory
WORKDIR /app

# Copy source tree (including WORKSPACE & BUILD.bazel)
COPY . .

# Build with Bazel with reduced memory usage and timeout settings
RUN bazel build //:maria_test

# Set entrypoint to the built binary
CMD ["bazel-bin/maria_test"]

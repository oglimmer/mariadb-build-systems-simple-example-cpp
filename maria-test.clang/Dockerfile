FROM debian:12

# Avoid interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# Install Clang, pkg-config, and MariaDB dev headers
RUN apt-get update && apt-get install -y \
    clang \
    pkg-config \
    libmariadb-dev \
  && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy source code and build script
COPY . .

# Build using clang (build.sh already invokes clang++)
RUN ./build.sh

# Run the resulting binary
CMD ["./maria_test"]
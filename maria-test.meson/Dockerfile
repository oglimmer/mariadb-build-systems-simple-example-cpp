FROM debian:12

# Set environment to avoid interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies including Meson, Ninja, and pkg-config
RUN apt-get update && apt-get install -y \
    build-essential \
    meson \
    ninja-build \
    pkg-config \
    libmariadb-dev \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy source code
COPY . .

# Configure and build with Meson
RUN meson setup builddir --buildtype=release \
    && ninja -C builddir

# Set runtime directory
WORKDIR /app/builddir

# Set the entrypoint
CMD ["./maria_test"]

FROM debian:12

# Set environment to avoid interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    pkg-config \
    default-libmysqlclient-dev \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy source code and build script
COPY . .

# Build using gcc
RUN ./build.sh

# Set the entrypoint
CMD ["./maria_test"]
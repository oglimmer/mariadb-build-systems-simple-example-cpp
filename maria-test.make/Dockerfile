FROM debian:12

# Set environment to avoid interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    pkg-config \
    libmariadb-dev \
    && rm -rf /var/lib/apt/lists/*

# Set working directory
WORKDIR /app

# Copy source code and Makefile
COPY . .

# Build using make
RUN make

# Set the entrypoint
CMD ["./maria_test"]
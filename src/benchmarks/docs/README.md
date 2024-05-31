# High-Performance Storage and I/O Primitives

## Overview
This project demonstrates the implementation and benchmarking of high-performance storage and I/O primitives in C++. The main objectives are to write and read data efficiently and to benchmark these operations.

## Implementation
The `StorageIO` class provides methods to write to and read from files, and to benchmark these operations.

### Files
- `src/storage_io.cpp`: Contains the implementation of the `StorageIO` class.
- `benchmarks/benchmark_storage_io.cpp`: Contains the benchmark tests.

## Running the Benchmarks
To compile and run the benchmarks, use the following commands:

```bash
g++ -o benchmark_storage_io benchmarks/benchmark_storage_io.cpp
./benchmark_storage_io

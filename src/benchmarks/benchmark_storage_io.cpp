// benchmarks/benchmark_storage_io.cpp
#include "storage_io.cpp"
#include <iostream>
#include <vector>
#include <string>

int main() {
    StorageIO storage;
    std::string filename = "testfile.bin";
    std::vector<char> data(1024 * 1024, 'A'); // 1MB of data

    double writeTime = storage.benchmarkWrite(filename, data);
    double readTime = storage.benchmarkRead(filename);

    std::cout << "Average Write Time: " << writeTime << " seconds" << std::endl;
    std::cout << "Average Read Time: " << readTime << " seconds" << std::endl;

    return 0;
}

// src/storage_io.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

class StorageIO {
public:
    void writeToFile(const std::string& filename, const std::vector<char>& data) {
        std::ofstream outfile(filename, std::ios::binary);
        outfile.write(data.data(), data.size());
        outfile.close();
    }

    std::vector<char> readFromFile(const std::string& filename) {
        std::ifstream infile(filename, std::ios::binary);
        infile.seekg(0, std::ios::end);
        size_t size = infile.tellg();
        infile.seekg(0, std::ios::beg);
        std::vector<char> buffer(size);
        infile.read(buffer.data(), size);
        infile.close();
        return buffer;
    }

    double benchmarkRead(const std::string& filename, size_t iterations = 100) {
        auto start = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < iterations; ++i) {
            readFromFile(filename);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return duration.count() / iterations;
    }

    double benchmarkWrite(const std::string& filename, const std::vector<char>& data, size_t iterations = 100) {
        auto start = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < iterations; ++i) {
            writeToFile(filename, data);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = end - start;
        return duration.count() / iterations;
    }
};

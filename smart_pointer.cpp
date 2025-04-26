#include <chrono>
#include <iostream>
#include <memory>

constexpr size_t ARRAY_SIZE = 128 * 1024 * 1024; // 128 MB size of array.
constexpr size_t STRIDE = 64;

int main() {

  // Allocate memory with smart pointer
  auto array = std::make_unique<char[]>(ARRAY_SIZE);

  // Start timing
  auto start = std::chrono::high_resolution_clock::now();

  for (size_t i = 0; i < ARRAY_SIZE; i += STRIDE) {
    array[i]++;
  }

  // End timing
  auto end = std::chrono::high_resolution_clock::now();

  // Calculate elapsed time
  std::chrono::duration<double> elapsed = end - start;
  std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;

  return 0;
}

#include <chrono>
#include <iostream>

#define ARRAY_SIZE (128 * 1024 * 1024) // 128 MB size of array.
#define STRIDE 64

int main() {
  char *arr = new char[ARRAY_SIZE];
  auto start = std::chrono::high_resolution_clock::now(); // start timing

  for (size_t i = 0; i < ARRAY_SIZE; i += STRIDE) {
    arr[i]++;
  }
  auto end = std::chrono::high_resolution_clock::now(); // end timing

  // Calculate elapsed time.
  std::chrono::duration<double> elapsed = end - start;
  std::cout << "Elapsed time: " << elapsed.count() << " seconds.\n";

  delete[] arr; // free memory
  return 0;
}

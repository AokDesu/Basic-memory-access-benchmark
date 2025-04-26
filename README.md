## License

This project is licensed under the MIT License.

# Basic Memory Access Benchmark

This program is a memory access benchmark. I did this becuase I want to understand how CPU works to
measure the **performance memory access pattern especially how fast the CPU can move through memory
with large steps**.

## what is the program doing?

**Allocate:** it allocates the `char *arr = new char[ARRAY_SIZE]` with the size of 128 MB. <br>
**Iterates:** it iterates through the array in steps of 64 bytes (`STRIDE = 64`). <br>
**Incremental:** it increments `arr[i]++` each access byte. <br>
**Measures:** Finally it measures the time of this loop.

## what does it shows?

**Elapsed time** to touch every 64th bytes of a 128 MB block of memory. <br>

- **Breakdown:**
  - Memory block size is 128 MB.
  - Stride 64 bytes. (touching every 64th byte)
  - iterations. it iterates through the block with a step of 64 bytes so for a block of 128 MB:
    - **Number of iterations = 128MB/64Bytes = (128 _ 1024 _ 1024)/64Bytes = 2,097,152 iterations.**

**Elapsed Time** is the total of time taken for entire loop, which includes:

- **Starting** the loop.
- **Accessing** every 64th byte in the array.
- **Ending** the loop

**the time shown is the total duration for all iterations.**

## Why am I using `STRIDE = 64`?

Most CPUs use 64 bytes cache lines, so this is benchmark simulates access one byte per cache line essentially
testing how quickly memory can be accessed when there is no reuse of already-cached data.

### To run the script

```bash
chmod +x benchmark.sh
./benchmark.sh
```

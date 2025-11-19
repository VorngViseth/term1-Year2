[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/qKBXPiAW)
# Directory Structure Validation
## Objective
Implement the function `bool isFolderValid(fs::path dir)` that recursively checks if a directory and all its subdirectories meet the following condition:

    Every directory must contain at least one valid non-empty file or a subdirectory that meets the same condition.

Your task is to:

1. Implement the function isWellStructured.
2. Test it on various directory structures.
3. Ensure the function correctly identifies valid and invalid directory structures.

## Function Specification

```cpp
bool isFolderValid(fs::path dir)
```

**Parameter**: 
- `dir`: The path of the directory to validate.

**Return Value**:
- `true`: If the directory and all its subdirectories are well-structured.
- `false`: If any directory in the structure is empty or lacks valid files/subdirectories.

## Examples

Here are examples of valid and invalid directory structures.

### 1. Valid Directory Structure
```shell
root/
├── file1.txt          (non-empty file)
├── subdir1/
│   ├── file2.txt      (non-empty file)
├── subdir2/
│   ├── file3.txt      (non-empty file)
│   ├── subdir3/
│       └── file4.txt  (non-empty file)
```
- **Explanation**: All directories contain at least one non-empty file or valid subdirectory.
- **Output**: `true`

### 2. Invalid Directory Structure
```shell
root/
├── file1.txt          (non-empty file)
├── subdir1/           (empty directory)
├── subdir2/
│   ├── subdir3/       (empty directory)
```
- **Explanation**: subdir1 and subdir3 are empty.
- **Output**: `false`

### 3. Single File
```shell
root.txt (non-empty file)
```
- **Explanation**: A single non-directory file is considered well-structured.
- **Output**: `true`

## Instruction
Write a recursive function to validate the directory structure. 

You have to complete the task in [Solution.h](Solution.h).

## Hints
- Use `fs::directory_iterator` to iterate through the directory.
- Use `fs::is_directory()` to check if a path is a directory.
- Use `fs::is_empty()` to check if a directory is empty.
- Use `fs::file_size()` to ensure a file is not empty.

### NOTE

If your system cannot run the C++ code using the normal ./a.out or default build method, please use the following commands depending on your operating system.

#### Windows Users

If you are using MinGW, MSYS2, or any environment with g++, compile and run using:
```
g++ -std=c++17 -O2 -Wall main.cpp -o main
main.exe
```

If you are using Visual Studio Developer Command Prompt:
```
cl /EHsc /std:c++17 main.cpp
main.exe
```

Make sure your environment supports C++17, because the lab uses `std::filesystem`.

#### macOS Users
```
g++ -std=c++17 -O2 -Wall main.cpp -o main
./main
```

If you use Apple Clang and get linker errors for <filesystem>, try:
```
g++ -std=c++17 -lstdc++fs main.cpp -o main
./main
```
#### Linux Users (Ubuntu/Debian/Fedora/etc.)
```
g++ -std=c++17 -O2 -Wall main.cpp -o main
./main
```

If your GCC version is older than 9 and `<filesystem>` fails, try:
```
g++ -std=c++17 -lstdc++fs main.cpp -o main
./main
```

## Happy Coding!
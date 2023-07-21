# Program documentation

This program provides various file manipulation functionalities for two specific directories: `Male` and `Female`. It allows renaming files, listing files, deleting files, copying files between directories, creating new directories, moving files between directories, searching files by name, and counting the number of files in a directory.

## Installation

To use this program, you need a C++ compiler that supports C++17 or later, along with the required standard libraries: `iostream`, `filesystem`, `iomanip`, `string`, `chrono`, and `thread`. 

You can compile the program using the following command:

```shell
g++ -std=c++17 main.cpp -o file_manager
```

## Usage

To run the compiled program, execute the following command:

```shell
./file_manager
```

Once the program starts, it will display a menu with multiple options. Enter the number corresponding to the desired operation and press Enter.

Example:

```
===== MENU =====
1. Rename files in the Male folder
2. Rename files in the Female folder
3. List files in the Male folder
4. List files in the Female folder
5. Delete files from the Male folder
6. Delete files from the Female folder
7. Copy files from the Male folder to the Female folder
8. Create a new directory
9. Move files from the Male folder to the Female folder
10. Search for a file by name in the Male folder
11. Count the number of files in the Female folder
12. Show this menu again
0. Exit the program
================
```

### 1. Rename files in the Male folder
This option renames all files in the `Male` folder. The new names will have the format "MaleX.extension", where X is a number corresponding to the file's position in the directory.

### 2. Rename files in the Female folder
This option renames all files in the `Female` folder. The new names will have the format "FemaleX.extension", where X is a number corresponding to the file's position in the directory.

### 3. List files in the Male folder
This option lists all files in the `Male` folder.

### 4. List files in the Female folder
This option lists all files in the `Female` folder.

### 5. Delete files from the Male folder
This option deletes all files from the `Male` folder.

### 6. Delete files from the Female folder
This option deletes all files from the `Female` folder.

### 7. Copy files from the Male folder to the Female folder
This option copies all files from the `Male` folder to the `Female` folder.

### 8. Create a new directory
This option creates a new directory named `NewDirectory` inside the `change` directory.

### 9. Move files from the Male folder to the Female folder
This option moves all files from the `Male` folder to the `Female` folder.

### 10. Search for a file by name in the Male folder
This option allows you to search for a specific file by its name in the `Male` folder.

### 11. Count the number of files in the Female folder
This option displays the total number of files in the `Female` folder.

### 12. Show this menu again
This option displays the menu with all available options.

### 0. Exit the program
This option terminates the program.

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

This project is licensed under the [MIT License](LICENSE).

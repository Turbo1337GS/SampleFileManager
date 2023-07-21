#include <iostream>
#include <filesystem>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>

namespace fs = std::filesystem;

// Function declarations
void showMenu();
void renameFilesInDirectory(const std::string& dirPath);
void listFilesInDirectory(const std::string& dirPath);
void deleteFilesInDirectory(const std::string& dirPath);
void copyFilesBetweenDirectories(const std::string& sourceDir, const std::string& destinationDir);
void createNewDirectory(const std::string& dirPath);
void moveFilesBetweenDirectories(const std::string& sourceDir, const std::string& destinationDir);
void searchFileByName(const std::string& dirPath, const std::string& fileName);
void countFilesInDirectory(const std::string& dirPath);
void wait(int milliseconds);

int main()
{
    std::string dirPathMale = "./change/Male/";
    std::string dirPathFemale = "./change/Female/";

    if (!fs::exists(dirPathMale) || !fs::exists(dirPathFemale)) {
        std::cout << "\033[31mRequired directories are missing!\033[0m\n";
        return 1;
    }

    showMenu();

    int choice;
    while (true) {
        std::cout << "Select an option: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear the input buffer

        switch (choice) {
            case 1:
                renameFilesInDirectory(dirPathMale);
                break;
            case 2:
                renameFilesInDirectory(dirPathFemale);
                break;
            case 3:
                listFilesInDirectory(dirPathMale);
                break;
            case 4:
                listFilesInDirectory(dirPathFemale);
                break;
            case 5:
                deleteFilesInDirectory(dirPathMale);
                break;
            case 6:
                deleteFilesInDirectory(dirPathFemale);
                break;
            case 7:
                copyFilesBetweenDirectories(dirPathMale, dirPathFemale);
                break;
            case 8:
                createNewDirectory("./change/NewDirectory/");
                break;
            case 9:
                moveFilesBetweenDirectories(dirPathMale, dirPathFemale);
                break;
            case 10:
                searchFileByName(dirPathMale, "file_name_to_search.txt");
                break;
            case 11:
                countFilesInDirectory(dirPathFemale);
                break;
            case 12:
                showMenu();
                break;
            case 0:
                std::cout << "Program terminated.\n";
                return 0;
            default:
                std::cout << "Unknown option. Please try again.\n";
                break;
        }
    }

    return 0;
}

// Function definitions

void showMenu() {
    std::cout << "\n===== MENU =====\n"
              << "1. Rename files in the Male folder\n"
              << "2. Rename files in the Female folder\n"
              << "3. List files in the Male folder\n"
              << "4. List files in the Female folder\n"
              << "5. Delete files from the Male folder\n"
              << "6. Delete files from the Female folder\n"
              << "7. Copy files from the Male folder to the Female folder\n"
              << "8. Create a new directory\n"
              << "9. Move files from the Male folder to the Female folder\n"
              << "10. Search for a file by name in the Male folder\n"
              << "11. Count the number of files in the Female folder\n"
              << "12. Show this menu again\n"
              << "0. Exit the program\n"
              << "================\n\n";
}

void renameFilesInDirectory(const std::string& dirPath) {
    int counter = 1;
    for (auto& p : fs::directory_iterator(dirPath)) {
        std::string prefix = dirPath == "./change/Male/" ? "Male" : "Female";
        std::string oldName = p.path().string();
        std::string newName = dirPath + prefix + std::to_string(counter) + p.path().extension().string();
        fs::rename(p.path(), newName);

        float progress = (float)counter / std::distance(fs::directory_iterator(dirPath), fs::directory_iterator{}) * 100;
        std::cout << "\rProgress: " << std::fixed << std::setprecision(2) << progress << "% " << std::flush;
        wait(25);

        counter++;
    }
    std::cout << "\nFile renaming in the folder completed.\n";
}

void listFilesInDirectory(const std::string& dirPath) {
    std::cout << "Files in the folder " << dirPath << ":\n";
    for (const auto& p : fs::directory_iterator(dirPath)) {
        std::cout << p.path().filename().string() << "\n";
    }
}

void deleteFilesInDirectory(const std::string& dirPath) {
    for (auto& p : fs::directory_iterator(dirPath)) {
        fs::remove(p.path());
    }
    std::cout << "Files deleted from the folder.\n";
}

void copyFilesBetweenDirectories(const std::string& sourceDir, const std::string& destinationDir) {
    for (auto& p : fs::directory_iterator(sourceDir)) {
        fs::copy(p.path(), destinationDir + p.path().filename().string());
    }
    std::cout << "Files copied from the Male folder to the Female folder.\n";
}

void createNewDirectory(const std::string& dirPath) {
    if (fs::create_directory(dirPath)) {
        std::cout << "New directory created: " << dirPath << "\n";
    } else {
        std::cout << "Unable to create the directory. Check if a folder with the same name already exists.\n";
    }
}

void moveFilesBetweenDirectories(const std::string& sourceDir, const std::string& destinationDir) {
    for (auto& p : fs::directory_iterator(sourceDir)) {
        fs::rename(p.path(), destinationDir + p.path().filename().string());
    }
    std::cout << "Files moved from the Male folder to the Female folder.\n";
}

void searchFileByName(const std::string& dirPath, const std::string& fileName) {
    for (const auto& p : fs::directory_iterator(dirPath)) {
        if (p.path().filename().string() == fileName) {
            std::cout << "File " << fileName << " found in the folder " << dirPath << "\n";
            return;
        }
    }
    std::cout << "File " << fileName << " not found in the folder " << dirPath << "\n";
}

void countFilesInDirectory(const std::string& dirPath) {
    int total_files = std::distance(fs::directory_iterator(dirPath), fs::directory_iterator{});
    std::cout << "Number of files in the folder: " << total_files << "\n";
}

void wait(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

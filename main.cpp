#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include "GameManager.h"

int main() {
    try {
        // Set console color
        system("color f1");
        
        // Create game manager instance
        auto gameManager = std::make_unique<GameManager>();
        
        while (true) {
            gameManager->initializeConsole();
            gameManager->showWelcome();
            system("cls");
            gameManager->showMenu();
            
            // Get user input
            char choice = _getch();
            
            switch (choice) {
                case '1':
                case '2':
                    gameManager->handleFileOperation(choice);
                    break;
                case '3':
                    std::cout << "\nThank you for using Cricket Scoresheet!\n";
                    return 0;
                default:
                    std::cout << "\nInvalid choice. Please try again.\n";
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
} 
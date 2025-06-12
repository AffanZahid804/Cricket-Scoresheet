#pragma once

#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include <windows.h>

// Forward declarations
class Team;
class Player;
class Bowler;
class Match;

class GameManager {
public:
    GameManager();
    ~GameManager() = default;

    // Console and UI functions
    void initializeConsole();
    void showWelcome();
    void showMenu();
    void locate(int x, int y);

    // File operations
    void handleFileOperation(char choice);
    void saveMatch(const std::string& filename);
    void loadMatch(const std::string& filename);

    // Match management
    void startNewMatch();
    void updateScore();
    void endInnings();
    void showMatchSummary();

private:
    std::unique_ptr<Match> currentMatch;
    std::vector<std::string> matchHistory;
    
    // Console handles
    HANDLE consoleHandle;
    
    // Helper functions
    void clearScreen();
    void showError(const std::string& message);
    bool validateInput(const std::string& input);
}; 
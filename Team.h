#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Player.h"
#include "Bowler.h"

class Team {
public:
    Team(const std::string& name);
    
    // Team management
    void addPlayer(const std::string& name);
    void addBowler(const std::string& name);
    
    // Match operations
    void startInnings();
    void endInnings();
    
    // Score management
    void updateScore(int runs);
    void addExtra(int runs);
    void addWicket(const std::string& how, const std::string& bowler, const std::string& fielder = "");
    
    // Getters
    std::string getName() const { return name; }
    int getTotalRuns() const { return totalRuns; }
    int getWickets() const { return wickets; }
    int getExtras() const { return extras; }
    float getOvers() const { return overs; }
    
    // Player access
    Player* getCurrentBatsman() { return currentBatsman; }
    Player* getNonStriker() { return nonStriker; }
    Bowler* getCurrentBowler() { return currentBowler; }
    
    // Statistics
    std::string getSummary() const;
    std::vector<std::string> getBattingCard() const;
    std::vector<std::string> getBowlingCard() const;

private:
    std::string name;
    std::vector<std::unique_ptr<Player>> players;
    std::vector<std::unique_ptr<Bowler>> bowlers;
    
    Player* currentBatsman{nullptr};
    Player* nonStriker{nullptr};
    Bowler* currentBowler{nullptr};
    
    int totalRuns{0};
    int wickets{0};
    int extras{0};
    float overs{0.0f};
    
    void rotateStrike();
    void changeBatsman();
    void changeBowler();
}; 
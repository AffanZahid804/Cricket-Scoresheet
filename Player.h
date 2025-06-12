#pragma once

#include <string>
#include <chrono>

class Player {
public:
    Player(const std::string& name);
    
    // Getters
    std::string getName() const { return name; }
    int getRuns() const { return runs; }
    int getFours() const { return fours; }
    int getSixes() const { return sixes; }
    int getBallsFaced() const { return ballsFaced; }
    std::string getHowOut() const { return howOut; }
    std::string getBowler() const { return bowler; }
    std::string getFielder() const { return fielder; }
    
    // Setters
    void addRuns(int runs);
    void addBoundary(bool isSix);
    void incrementBallsFaced();
    void setHowOut(const std::string& how, const std::string& bowler, const std::string& fielder = "");
    
    // Timing functions
    void startInnings();
    void endInnings();
    std::chrono::minutes getTimePlayed() const;
    
    // Statistics
    float getStrikeRate() const;
    std::string getSummary() const;

private:
    std::string name;
    int runs{0};
    int fours{0};
    int sixes{0};
    int ballsFaced{0};
    std::string howOut{"Not Out"};
    std::string bowler;
    std::string fielder;
    
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point endTime;
}; 
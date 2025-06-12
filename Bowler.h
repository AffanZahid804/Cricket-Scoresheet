#pragma once

#include <string>

class Bowler {
public:
    Bowler(const std::string& name);
    
    // Getters
    std::string getName() const { return name; }
    int getOvers() const { return overs; }
    int getMaidens() const { return maidens; }
    int getRuns() const { return runs; }
    int getWickets() const { return wickets; }
    int getNoBalls() const { return noBalls; }
    int getWides() const { return wides; }
    
    // Bowling operations
    void addBall(int runs);
    void addWicket();
    void addNoBall();
    void addWide();
    
    // Statistics
    float getEconomyRate() const;
    float getAverage() const;
    std::string getSummary() const;

private:
    std::string name;
    int overs{0};
    int maidens{0};
    int runs{0};
    int wickets{0};
    int noBalls{0};
    int wides{0};
    int ballsInCurrentOver{0};
    
    void updateOver();
}; 
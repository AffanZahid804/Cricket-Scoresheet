#pragma once

#include <string>
#include <memory>
#include <chrono>
#include "Team.h"

class Match {
public:
    Match(const std::string& competition, 
          const std::string& venue,
          const std::string& team1,
          const std::string& team2,
          int totalOvers);
    
    // Match setup
    void setToss(const std::string& winner, const std::string& decision);
    void startMatch();
    void endMatch();
    
    // Match operations
    void updateScore(int runs);
    void addExtra(int runs);
    void addWicket(const std::string& how, const std::string& bowler, const std::string& fielder = "");
    void endOver();
    void endInnings();
    
    // Getters
    std::string getCompetition() const { return competition; }
    std::string getVenue() const { return venue; }
    int getTotalOvers() const { return totalOvers; }
    std::string getTossWinner() const { return tossWinner; }
    std::string getTossDecision() const { return tossDecision; }
    
    // Match state
    bool isFirstInnings() const { return currentInnings == 1; }
    bool isMatchComplete() const { return matchComplete; }
    
    // Statistics
    std::string getSummary() const;
    std::string getCurrentScore() const;
    std::vector<std::string> getFullScorecard() const;

private:
    std::string competition;
    std::string venue;
    std::unique_ptr<Team> team1;
    std::unique_ptr<Team> team2;
    int totalOvers;
    
    std::string tossWinner;
    std::string tossDecision;
    
    int currentInnings{1};
    bool matchComplete{false};
    
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point endTime;
    
    Team* getBattingTeam() const;
    Team* getBowlingTeam() const;
}; 
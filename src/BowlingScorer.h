#ifndef BOWLING_SCORER_H
#define BOWLING_SCORER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum RollBonus {
    Strike,
    Spare,
    Normal
};

struct Frame {
    int roll1;
    int roll2;
    int roll3;
    int score;
    RollBonus bonus;
    Frame() : roll1(0), roll2(0), roll3(0), score(0), bonus(RollBonus::Normal) {}
};

class Player {
public:
    string name;
    vector<Frame> frames;
    int totalScore;

    Player(const string& playerName);

    void addRoll(int pinsKnocked, int frameIndex, int rollGuide);
    void calculateScore();

private:
    bool isStrike(const Frame& frame);
    bool isSpare(const Frame& frame);
};

#endif
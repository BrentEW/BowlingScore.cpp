#include "BowlingScorer.h"

int main(){
    int numberOfPlayers;
    cout << "Enter the number of players? (1-3): ";
    cin >> numberOfPlayers;
    if (numberOfPlayers < 1 || numberOfPlayers > 3) {
        cout << "Invalid number of players. Please restart the game." << endl;
        return 1;
    }

    vector<Player> players;
    for (int i = 1; i <= numberOfPlayers; ++i) {
        string playerName;
        cout << "Enter name for Player " << i << ":";
        cin >> playerName;
        players.emplace_back(playerName);
    }

    for (int frame = 1; frame <= 10; ++frame) {
        cout << "Frame " << frame << ":\n";
        for (Player& player : players) {
            cout << player.name << ", enter your rolls:\n";
            int roll1, roll2 = 0, roll3 = 0;
            cout << "Roll 1: ";
            cin >> roll1;
            player.addRoll(roll1, frame - 1, 1);
            if (roll1 != 10 || frame == 10) {
                cout << "Roll 2: ";
                cin >> roll2;
                player.addRoll(roll2, frame - 1, 2);
            }
            if (frame == 10 && (roll1 == 10 || roll1 + roll2 == 10)) {
                cout << "Roll 3: ";
                cin >> roll3;
                player.addRoll(roll3, frame - 1, 3);
            }
            player.calculateScore();
            cout << player.name << "'s total score: " << player.totalScore << endl;
        }
    }

    cout << "\nFinal Scores:\n";
    for (const Player& player : players) {
        cout << player.name << ":" << player.totalScore << endl;
    }

    return 0;
}
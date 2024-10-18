#include "BowlingScorer.h"

Player::Player(const string& playerName) : name(playerName), totalScore(0) {
	frames.resize(10);
}

bool Player::isStrike(const Frame& frame) {
	return frame.roll1 == 10;
}

bool Player::isSpare(const Frame& frame) {
	return (frame.roll1 + frame.roll2 == 10);
}

void Player::addRoll(int pinsKnocked, int frameIndex, int rollGuide) {
	if (frameIndex < 9) {
		Frame& currentFrame = frames[frameIndex];
		if (rollGuide == 1) {
			currentFrame.roll1 = pinsKnocked;
			if (isStrike(currentFrame)) {
				currentFrame.bonus = RollBonus::Strike;
			}
		}
		else if (rollGuide == 2) {
			currentFrame.roll2 = pinsKnocked;
			if (isSpare(currentFrame)) {
				currentFrame.bonus = RollBonus::Spare;
			}
		}
	} else {
		Frame& currentFrame = frames[9];
		if (rollGuide == 1) {
			currentFrame.roll1 = pinsKnocked;
		}
		else if (rollGuide == 2) {
			currentFrame.roll2 = pinsKnocked;
		}
		else if (rollGuide == 3) {
			currentFrame.roll1 = pinsKnocked;
		}
	}
}

void Player::calculateScore() {
	totalScore = 0;

	for (int i = 0; i < 10; ++i) {
		Frame& frame = frames[i];

		totalScore += frame.roll1 + frame.roll2;

		if (frame.bonus == RollBonus::Strike && i < 9) {
			totalScore += frames[i + 1].roll1;
			if (isStrike(frames[i + 1]) && i < 8) {
				totalScore += frames[i + 2].roll1;
			}
			else {
				totalScore += frames[i + 1].roll2;
			}
		}
		else if (frame.bonus == RollBonus::Spare && i < 9) {
			totalScore += frames[i + 1].roll1;
		}
		if (i == 9) {
			totalScore += frame.roll1 + frame.roll2 + frame.roll3;

			if (frames[8].bonus == RollBonus::Strike) {
				totalScore += frame.roll1 + frame.roll2;
			}
			else if (frames[8].bonus == RollBonus::Spare) {
				totalScore += frame.roll1;
			}
		}
		frame.score = totalScore;
	}
}
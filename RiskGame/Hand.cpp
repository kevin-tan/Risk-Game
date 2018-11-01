#include "stdafx.h"
#include "Hand.h"
#include "Deck.h"
#include <vector>

Hand::Hand() {
	hand_cards = vector<int>(3);
}

int Hand::exchange(Deck* deck) {
	int number_of_armies = 0;

	if (hand_size < 3) {
		return 0;
	}

	if (hand_cards[0] >= 3) {
		hand_cards[0] -= 3;
	} else if (hand_cards[1] >= 3) {
		hand_cards[1] -= 3;
	} else if (hand_cards[2] >= 3) {
		hand_cards[2] -= 3;
	} else if (hand_cards[0] >= 1 && hand_cards[1] >= 1 && hand_cards[2] >= 1) {
		hand_cards[0]--;
		hand_cards[1]--;
		hand_cards[2]--;
	} else {
		return 0;
	}

	return deck->inc_number_of_exchanges() * 5;
}
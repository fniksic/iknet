/*
 * Hand.cpp
 *
 *  Created on: 12. 6. 2012.
 *      Author: filip
 */

#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <utility>
#include <functional>

#include "Hand.h"
#include "Card.h"

namespace poker {

	Hand::Hand(std::vector<Card>& cards) :
			_cards(cards) {
		assert(_cards.size() == hand_size);
		process();
	}

	std::vector<Card> Hand::getCards() const {
		return _cards;
	}

	int Hand::compare(const Hand& other) const {
		// TODO
		return 0;
	}

	std::string Hand::toString() const {
		std::string result = "[";
		for (unsigned int i = 0; i < hand_size; ++i)
			result += (i > 0 ? ", " : "") + getCards()[i].toString();
		result += "]";
		return result;
	}

	void Hand::process() {
		sort(_cards.begin(), _cards.end(), std::greater<Card>());

		int currentRank = 0, totalRanks = 0;
		std::vector<int> counts, ranks;
		for (unsigned int i = 0; i < hand_size; ++i) {
			if (currentRank != _cards[i].getRank()) {
				currentRank = _cards[i].getRank();
				++totalRanks;
				ranks.push_back(currentRank);
				counts.push_back(0);
			}
			++counts[totalRanks - 1];
		}
	}

	bool Hand::isStraight() const {
		// TODO
		return false;
	}

	bool Hand::isFlush() const {
		for (unsigned int i = 1; i < hand_size; ++i)
			if (getCards()[0].getSuit() != getCards()[i].getSuit())
				return false;
		return true;
	}

} /* namespace poker */

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

#include "Hand.h"
#include "Card.h"
#include "Comparable.h"

namespace poker {

	Hand::Hand(std::vector<Card>& cards) :
			_cards(cards) {
		assert(_cards.size() == hand_size);
		std::sort(_cards.begin(), _cards.end());
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

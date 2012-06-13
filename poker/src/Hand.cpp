/*
 * Hand.cpp
 *
 *  Created on: 12. 6. 2012.
 *      Author: filip
 */

#include <vector>
#include <string>
#include <map>
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

	std::pair<Hand::Comb_t, std::vector<int> > Hand::getCombination() const {
		return _combination;
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
		std::map<int, int> histogram;
		for (unsigned int i = 0; i < hand_size; ++i)
			++histogram[_cards[i].getRank()];
		std::vector<std::pair<int, int> > countsAndRanks;
		for (std::map<int, int>::const_iterator it = histogram.begin(); it != histogram.end(); ++it)
			countsAndRanks.push_back(std::make_pair(it->second, it->first));
		sort(countsAndRanks.begin(), countsAndRanks.end(), std::greater<std::pair<int, int> >());

		/*
		 * Mogućnosti za counts:
		 *   (1, 1, 1, 1, 1) -> high card
		 *   (2, 1, 1, 1) -> par
		 *   (2, 2, 1) -> dva para
		 *   (3, 1, 1) -> tri iste
		 *   (3, 2) -> full house
		 *   (4, 1) -> četiri iste
		 *   (5) -> ilegalno
		 */
	}

	bool Hand::isStraight() const {
		// TODO
		return false;
	}

	bool Hand::isFlush() const {
		for (unsigned int i = 1; i < hand_size; ++i)
			if (_cards[0].getSuit() != _cards[i].getSuit())
				return false;
		return true;
	}

} /* namespace poker */

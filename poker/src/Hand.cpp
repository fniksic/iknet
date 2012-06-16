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

	const std::map<int, Hand::Comb_t> Hand::countsToCombination = createCountsToCombination();
	const std::string Hand::combinationNames[] = { "High card", "A pair", "Two pairs", "Three of a kind", "Straight",
			"Flush", "Full house", "Four of a kind", "Straight flush", "Illegal combination" };

	std::map<int, Hand::Comb_t> Hand::createCountsToCombination() {
		std::map<int, Comb_t> countsToCombination;
		countsToCombination[11111] = HIGH_CARD;
		countsToCombination[2111] = PAIR;
		countsToCombination[221] = TWO_PAIRS;
		countsToCombination[311] = THREE;
		countsToCombination[32] = FULL_HOUSE;
		countsToCombination[41] = FOUR;
		countsToCombination[5] = ILLEGAL;
		return countsToCombination;
	}

	Hand::Hand(const std::vector<Card>& cards) :
			_cards(cards) {
		assert(_cards.size() == hand_size);
		_combination = calculateCombination();
	}

	std::vector<Card> Hand::getCards() const {
		return _cards;
	}

	std::pair<Hand::Comb_t, std::vector<int> > Hand::getCombination() const {
		return _combination;
	}

	int Hand::compare(const Hand& other) const {
		return _combination < other.getCombination() ? -1 : _combination == other.getCombination() ? 0 : 1;
	}

	std::string Hand::toString() const {
		std::string result = "[" + combinationNames[_combination.first];
		for (int i = 0; i < hand_size; ++i)
			result += (i > 0 ? ", " : ": ") + getCards()[i].toString();
		result += "]";
		return result;
	}

	std::pair<Hand::Comb_t, std::vector<int> > Hand::calculateCombination() const {
		std::map<int, int> histogram;
		for (int i = 0; i < hand_size; ++i)
			++histogram[_cards[i].getRank()];

		std::vector<std::pair<int, int> > countsAndRanks;
		for (std::map<int, int>::const_iterator it = histogram.begin(); it != histogram.end(); ++it)
			countsAndRanks.push_back(std::make_pair(it->second, it->first));
		sort(countsAndRanks.begin(), countsAndRanks.end(), std::greater<std::pair<int, int> >());

		int counts = 0, totalRanks = countsAndRanks.size();
		std::vector<int> ranks;
		for (int i = 0; i < hand_size; ++i) {
			counts = counts * 10 + countsAndRanks[i].first;
			ranks.push_back(countsAndRanks[i].second);
		}

		Comb_t combination = countsToCombination.at(counts);

		if (ranks[0] == 14 && totalRanks == hand_size &&ranks[1] == hand_size && ranks[totalRanks - 1] == 2) {
			ranks[0] = 1;
			rotate(ranks.begin(), ranks.begin() + 1, ranks.end());
		}

		bool straight = totalRanks == hand_size && ranks[0] - ranks[totalRanks - 1] == hand_size - 1;
		bool flush = isFlush();

		if (straight && flush)
			combination = STRAIGHT_FLUSH;
		else if (flush)
			combination = std::max(combination, FLUSH);
		else if (straight)
			combination = std::max(combination, STRAIGHT);

		return std::make_pair(combination, ranks);
	}

	bool Hand::isFlush() const {
		for (int i = 1; i < hand_size; ++i)
			if (_cards[0].getSuit() != _cards[i].getSuit())
				return false;
		return true;
	}

} /* namespace poker */

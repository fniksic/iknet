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

using std::map;
using std::vector;
using std::string;
using std::pair;
using std::make_pair;
using std::max;
using std::greater;

namespace poker {

	const string Hand::combinationNames[] = { "High card", "A pair", "Two pairs", "Three of a kind", "Straight",
			"Flush", "Full house", "Four of a kind", "Straight flush", "Illegal combination" };

	const map<int, Hand::Comb_t> Hand::countsToCombination = createCountsToCombination();

	map<int, Hand::Comb_t> Hand::createCountsToCombination() {
		map<int, Comb_t> countsToCombination;
		countsToCombination[11111] = HIGH_CARD;
		countsToCombination[2111] = PAIR;
		countsToCombination[221] = TWO_PAIRS;
		countsToCombination[311] = THREE;
		countsToCombination[32] = FULL_HOUSE;
		countsToCombination[41] = FOUR;
		countsToCombination[5] = ILLEGAL;
		return countsToCombination;
	}

	Hand::Hand(const vector<Card>& cards) :
			_cards(cards) {
		assert(_cards.size() == hand_size);
		_combination = computeCombination();
	}

	vector<Card> Hand::getCards() const {
		return _cards;
	}

	pair<Hand::Comb_t, vector<int> > Hand::getCombination() const {
		return _combination;
	}

	int Hand::compare(const Hand& other) const {
		return _combination < other.getCombination() ? -1 : _combination == other.getCombination() ? 0 : 1;
	}

	string Hand::toString() const {
		string result = "[" + combinationNames[_combination.first];
		for (int i = 0; i < hand_size; ++i)
			result += (i > 0 ? ", " : ": ") + getCards()[i].toString();
		result += "]";
		return result;
	}

	pair<Hand::Comb_t, vector<int> > Hand::computeCombination() const {
		map<int, int> histogram = computeHistogram();
		vector<pair<int, int> > countsAndRanks = computeCountsAndRanks(histogram);
		pair<int, vector<int> > countsAndRanksUnzipped = unzip(countsAndRanks);
		int counts = countsAndRanksUnzipped.first;
		vector<int> ranks = countsAndRanksUnzipped.second;
		return computeCombination(counts, ranks);
	}

	pair<Hand::Comb_t, vector<int> > Hand::computeCombination(int counts, vector<int>& ranks) const {
		Comb_t combination = countsToCombination.at(counts);
		fixLowStraight(ranks);
		bool straight = isStraight(ranks);
		bool flush = isFlush();

		if (straight && flush)
			combination = STRAIGHT_FLUSH;
		else if (flush)
			combination = max(combination, FLUSH);
		else if (straight)
			combination = max(combination, STRAIGHT);

		return make_pair(combination, ranks);
	}

	map<int, int> Hand::computeHistogram() const {
		map<int, int> histogram;
		for (int i = 0; i < hand_size; ++i)
			++histogram[_cards[i].getRank()];
		return histogram;
	}

	vector<pair<int, int> > Hand::computeCountsAndRanks(const map<int, int>& histogram) const {
		vector<pair<int, int> > countsAndRanks;
		for (map<int, int>::const_iterator it = histogram.begin(); it != histogram.end(); ++it)
			countsAndRanks.push_back(make_pair(it->second, it->first));
		sort(countsAndRanks.begin(), countsAndRanks.end(), greater<pair<int, int> >());
		return countsAndRanks;
	}

	pair<int, vector<int> > Hand::unzip(const vector<pair<int, int> >& countsAndRanks) const {
		int counts = 0;
		vector<int> ranks;
		for (int i = 0; i < hand_size; ++i) {
			counts = counts * 10 + countsAndRanks[i].first;
			ranks.push_back(countsAndRanks[i].second);
		}
		return make_pair(counts, ranks);
	}

	void Hand::fixLowStraight(vector<int>& ranks) const {
		unsigned int totalRanks = ranks.size();
		if (ranks[0] == 14 && totalRanks == hand_size && ranks[1] == hand_size && ranks[totalRanks - 1] == 2) {
			ranks[0] = 1;
			rotate(ranks.begin(), ranks.begin() + 1, ranks.end());
		}
	}

	bool Hand::isStraight(const vector<int>& ranks) const {
		unsigned int totalRanks = ranks.size();
		return totalRanks == hand_size && ranks[0] - ranks[totalRanks - 1] == hand_size - 1;
	}

	bool Hand::isFlush() const {
		for (int i = 1; i < hand_size; ++i)
			if (_cards[0].getSuit() != _cards[i].getSuit())
				return false;
		return true;
	}

} /* namespace poker */

/*
 * Hand.h
 *
 *  Created on: 12. 6. 2012.
 *      Author: filip
 */

#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <map>
#include <string>
#include <utility>

#include "StringRepresentable.h"
#include "Comparable.h"
#include "Card.h"

namespace poker {

	class Hand: public StringRepresentable, public Comparable<Hand> {
	public:
		enum Comb_t {
			HIGH_CARD, PAIR, TWO_PAIRS, THREE, STRAIGHT, FLUSH, FULL_HOUSE, FOUR, STRAIGHT_FLUSH, ILLEGAL
		};

		Hand(const std::vector<Card>&);

		std::vector<Card> getCards() const;
		std::pair<Comb_t, std::vector<int> > getCombination() const;

		int compare(const Hand&) const;
		std::string toString() const;

	private:
		static const int hand_size = 5;
		static const std::map<int, Comb_t> countsToCombination;
		static const std::string combinationNames[];

		static std::map<int, Comb_t> createCountsToCombination();

		std::vector<Card> _cards;
		std::pair<Comb_t, std::vector<int> > _combination;

		std::pair<Comb_t, std::vector<int> > computeCombination() const;
		std::pair<Comb_t, std::vector<int> > computeCombination(int, std::vector<int>&) const;
		std::map<int, int> computeHistogram() const;
		std::vector<std::pair<int, int> > computeCountsAndRanks(const std::map<int, int>&) const;
		std::pair<int, std::vector<int> > unzip(const std::vector<std::pair<int, int> >&) const;
		void fixLowStraight(std::vector<int>&) const;
		bool isStraight(const std::vector<int>&) const;
		bool isFlush() const;
	};

} /* namespace poker */
#endif /* HAND_H_ */

/*
 * Hand.h
 *
 *  Created on: 12. 6. 2012.
 *      Author: filip
 */

#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <string>

#include "StringRepresentable.h"
#include "Comparable.h"
#include "Card.h"

namespace poker {

	class Hand: public StringRepresentable, public Comparable<Hand> {
	public:
		enum Comb_t {
			HIGH_CARD, PAIR, TWO_PAIRS, THREE, STRAIGHT, FLUSH, FULL_HOUSE, FOUR, STRAIGHT_FLUSH
		};

		Hand(std::vector<Card>&);

		std::vector<Card> getCards() const;

		int compare(const Hand&) const;
		std::string toString() const;

	private:
		static const unsigned int hand_size = 5;

		std::vector<Card> _cards;

		bool isStraight() const;
		bool isFlush() const;
	};

} /* namespace poker */
#endif /* HAND_H_ */

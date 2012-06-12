/*
 * Card.cpp
 *
 *  Created on: 9. 6. 2012.
 *      Author: filip
 */

#include "Card.h"

#include <cassert>
#include <string>

namespace poker {

	const std::string Card::rankNames[] = { "", "", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A" };
	const std::string Card::suitNames[] = { "S", "H", "C", "D" };

	Card::Card(int rank, Suit_t suit) :
			_rank(rank), _suit(suit) {
		assert(2 <= rank && rank <= 14);
	}

	int Card::getRank() const {
		return _rank;
	}

	Card::Suit_t Card::getSuit() const {
		return _suit;
	}

	int Card::compare(const Card& other) const {
		return getRank() - other.getRank();
	}

	std::string Card::toString() const {
		return rankNames[getRank()] + suitNames[getSuit()];
	}

} /* namespace poker */

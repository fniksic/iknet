/*
 * Card.h
 *
 *  Created on: 9. 6. 2012.
 *      Author: filip
 */

#ifndef CARD_H_
#define CARD_H_

#include <string>

#include "Comparable.h"
#include "StringRepresentable.h"

namespace poker {

	class Card : public Comparable<Card>, public StringRepresentable {
	public:
		enum Suit_t {
			SPADES, HEARTS, CLUBS, DIAMONDS
		};

	private:
		static const std::string rankNames[];
		static const std::string suitNames[];

		int _rank;
		Suit_t _suit;

	public:
		Card(int, Suit_t);

		int getRank() const;
		Suit_t getSuit() const;

		int compare(const Card&) const;
		std::string toString() const;
	};

} /* namespace poker */
#endif /* CARD_H_ */

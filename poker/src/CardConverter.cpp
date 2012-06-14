/*
 * CardConverter.cpp
 *
 *  Created on: 9. 6. 2012.
 *      Author: filip
 */

#include <string>
#include <map>
#include <cassert>

#include "CardConverter.h"
#include "Card.h"

namespace poker {

	CardConverter::CardConverter() {
	}

	const std::map<char, int> CardConverter::rankMap = createRankMap();
	const std::map<char, Card::Suit_t> CardConverter::suitMap = createSuitMap();

	std::map<char, int> CardConverter::createRankMap() {
		std::map<char, int> rankMap;
		for (char c = '2'; c <= '9'; ++c) {
			rankMap[c] = c - '0';
		}
		rankMap['T'] = 10;
		rankMap['J'] = 11;
		rankMap['Q'] = 12;
		rankMap['K'] = 13;
		rankMap['A'] = 14;
		return rankMap;
	}

	std::map<char, Card::Suit_t> CardConverter::createSuitMap() {
		std::map<char, Card::Suit_t> suitMap;
		suitMap['S'] = Card::SPADES;
		suitMap['H'] = Card::HEARTS;
		suitMap['C'] = Card::CLUBS;
		suitMap['D'] = Card::DIAMONDS;
		return suitMap;
	}

	Card CardConverter::convert(const std::string &cardString) {
		assert(cardString.size() == 2);
		assert(rankMap.count(cardString[0]) > 0);
		assert(suitMap.count(cardString[1]) > 0);

		int rank = rankMap.at(cardString[0]);
		Card::Suit_t suit = suitMap.at(cardString[1]);
		return Card(rank, suit);
	}

} /* namespace poker */

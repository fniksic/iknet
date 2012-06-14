/*
 * HandConverter.cpp
 *
 *  Created on: 14. 6. 2012.
 *      Author: filip
 */

#include <string>
#include <vector>

#include "HandConverter.h"
#include "Hand.h"
#include "Card.h"
#include "CardConverter.h"
#include "StringTokenizer.h"

namespace poker {

	HandConverter::HandConverter() {
	}

	Hand HandConverter::convert(const std::string& handString) {
		std::vector<Card> cards;
		StringTokenizer stringTokenizer(handString);
		while (stringTokenizer.hasNext()) {
			std::string token = stringTokenizer.next();
			cards.push_back(CardConverter::convert(token));
		}
		return Hand(cards);
	}

} /* namespace poker */

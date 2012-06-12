/*
 * CardConverter.h
 *
 *  Created on: 9. 6. 2012.
 *      Author: filip
 */

#ifndef CARDCONVERTER_H_
#define CARDCONVERTER_H_

#include <string>
#include <map>

#include "Card.h"

namespace poker {

	class CardConverter {
	private:
		CardConverter();

		static const std::map<char, int> rankMap;
		static const std::map<char, Card::Suit_t> suitMap;

		static std::map<char, int> createRankMap();
		static std::map<char, Card::Suit_t> createSuitMap();

	public:
		static Card convert(const std::string&);
	};

} /* namespace poker */
#endif /* CARDCONVERTER_H_ */

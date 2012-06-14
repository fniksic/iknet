/*
 * main.cpp
 *
 *  Created on: 9. 6. 2012.
 *      Author: filip
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "Card.h"
#include "CardConverter.h"
#include "Hand.h"
#include "HandConverter.h"

using namespace poker;
using namespace std;

int main() {
	std::string boolean[] = { "false", "true" };
	Card ten_of_hearts(10, Card::HEARTS);
	Card ace_of_spades(14, Card::SPADES);

	cout << ace_of_spades << endl;
	cout << boolean[ten_of_hearts < ace_of_spades] << endl;
	cout << CardConverter::convert("TC") << CardConverter::convert("AC") << CardConverter::convert("3H") << endl;

	Hand straight_flush = HandConverter::convert("TC JC QC KC AC");
	Hand straight = HandConverter::convert("9C TD JH QS 8C");

	cout << straight << endl << straight_flush << endl
			<< straight << " > " << straight_flush << " : " << boolean[straight > straight_flush] << endl;

	return EXIT_SUCCESS;
}

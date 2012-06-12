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

using namespace poker;
using namespace std;

int main() {
	std::string boolean[] = { "false", "true" };
	Card ten_of_hearts(10, Card::HEARTS);
	Card ace_of_spades(14, Card::SPADES);

	cout << ace_of_spades << endl;
	cout << boolean[ten_of_hearts < ace_of_spades] << endl;
	cout << CardConverter::convert("TC") << CardConverter::convert("AC") << CardConverter::convert("3H") << endl;

	vector<Card> cards;
	cards.push_back(CardConverter::convert("TC"));
	cards.push_back(CardConverter::convert("QC"));
	cards.push_back(CardConverter::convert("KC"));
	cards.push_back(CardConverter::convert("JC"));
	cards.push_back(CardConverter::convert("AC"));

	Hand hand(cards);

	cout << hand << endl;

	return EXIT_SUCCESS;
}

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
#include <cassert>

#include "Card.h"
#include "CardConverter.h"
#include "Hand.h"
#include "HandConverter.h"

using namespace poker;
using namespace std;

int main() {
	//std::string boolean[] = { "false", "true" };

	Hand royal_flush = HandConverter::convert("TC JC QC KC AC");
	Hand straight_flush = HandConverter::convert("8D 7D 9D TD JD");
	Hand low_straight_flush = HandConverter::convert("4H 3H 2H AH 5H");
	Hand four_of_a_kind = HandConverter::convert("4H 8C 4C 4D 4S");
	Hand full_house = HandConverter::convert("QD QC KC KD KH");
	Hand lower_full_house = HandConverter::convert("AH AC QD QH QC");
	Hand lowest_full_house = HandConverter::convert("QD QH TC TD QS");
	Hand flush = HandConverter::convert("8D 7D KD 3D 2D");
	Hand straight = HandConverter::convert("9C TD JH QS 8C");
	Hand low_straight = HandConverter::convert("4C 5D 3S 2C AS");
	Hand middle_straight = HandConverter::convert("4C 5D 3S 2C 6S");
	Hand three_of_a_kind = HandConverter::convert("2C 2D 2H KS AC");
	Hand two_pairs = HandConverter::convert("7C 7D 4K 4S AS");
	Hand a_pair = HandConverter::convert("6C 3C 6D AS 2D");
	Hand high_card = HandConverter::convert("8C 4D TS 7C 6C");
	Hand lower_high_card = HandConverter::convert("4C 9D 7S 2S 3S");

	cout << royal_flush << endl << straight_flush << endl << low_straight_flush << endl << four_of_a_kind << endl
			<< full_house << endl << lower_full_house << endl << lowest_full_house << endl << flush << endl << straight
			<< endl << low_straight << endl << middle_straight << endl << three_of_a_kind << endl << two_pairs << endl
			<< a_pair << endl << high_card << endl << lower_high_card << endl;

	assert(!(royal_flush > royal_flush));
	assert(royal_flush > straight_flush);
	assert(straight_flush > low_straight_flush);
	assert(low_straight_flush > four_of_a_kind);
	assert(four_of_a_kind > full_house);
	assert(full_house > lower_full_house);
	assert(lower_full_house > lowest_full_house);
	assert(lowest_full_house > flush);
	assert(flush > straight);
	assert(straight > middle_straight);
	assert(middle_straight > low_straight);
	assert(low_straight > three_of_a_kind);
	assert(three_of_a_kind > two_pairs);
	assert(two_pairs > a_pair);
	assert(a_pair > high_card);
	assert(high_card > lower_high_card);

	cout << "All tests are OK!" << endl;

	return EXIT_SUCCESS;
}

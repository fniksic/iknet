/*
 * StringTokenizer.cpp
 *
 *  Created on: 14. 6. 2012.
 *      Author: filip
 */

#include "StringTokenizer.h"

namespace poker {

	StringTokenizer::StringTokenizer(const std::string& s, const std::string& delimiters) :
			_s(s), _delimiters(delimiters) {
		nextPos = _s.find_first_not_of(_delimiters);
	}

	bool StringTokenizer::hasNext() const {
		return nextPos != std::string::npos;
	}

	std::string StringTokenizer::next() {
		size_t currPos = nextPos;
		nextPos = _s.find_first_of(_delimiters, currPos);
		std::string result = _s.substr(currPos, nextPos - currPos);
		if (nextPos != std::string::npos)
			nextPos = _s.find_first_not_of(_delimiters, nextPos);
		return result;
	}

} /* namespace poker */

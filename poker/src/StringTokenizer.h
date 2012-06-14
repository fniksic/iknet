/*
 * StringTokenizer.h
 *
 *  Created on: 14. 6. 2012.
 *      Author: filip
 */

#ifndef STRINGTOKENIZER_H_
#define STRINGTOKENIZER_H_

#include <cstddef>
#include <string>

namespace poker {

	class StringTokenizer {
	private:
		std::string _s, _delimiters;
		size_t nextPos;

	public:
		StringTokenizer(const std::string&, const std::string& = " \t\n\r");

		bool hasNext() const;
		std::string next();
	};

} /* namespace poker */
#endif /* STRINGTOKENIZER_H_ */

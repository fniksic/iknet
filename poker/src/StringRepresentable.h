/*
 * StringRepresentable.h
 *
 *  Created on: 9. 6. 2012.
 *      Author: filip
 */

#ifndef STRINGREPRESENTABLE_H_
#define STRINGREPRESENTABLE_H_

#include <string>
#include <iostream>

namespace poker {

	class StringRepresentable {
	public:
		StringRepresentable();
		virtual ~StringRepresentable();

		virtual std::string toString() const = 0;
	};

	std::ostream& operator<<(std::ostream&, const StringRepresentable&);

} /* namespace poker */
#endif /* STRINGREPRESENTABLE_H_ */

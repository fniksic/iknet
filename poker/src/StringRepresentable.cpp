/*
 * StringRepresentable.cpp
 *
 *  Created on: 9. 6. 2012.
 *      Author: filip
 */

#include "StringRepresentable.h"

#include <iostream>

namespace poker {

	StringRepresentable::StringRepresentable() {
	}

	StringRepresentable::~StringRepresentable() {
	}

	std::ostream& operator<<(std::ostream& out, const StringRepresentable& s) {
		return (out << s.toString());
	}

} /* namespace poker */

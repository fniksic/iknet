/*
 * HandConverter.h
 *
 *  Created on: 14. 6. 2012.
 *      Author: filip
 */

#ifndef HANDCONVERTER_H_
#define HANDCONVERTER_H_

#include <string>

#include "Hand.h"

namespace poker {

	class HandConverter {
	private:
		HandConverter();

	public:
		static Hand convert(const std::string&);
	};

} /* namespace poker */
#endif /* HANDCONVERTER_H_ */

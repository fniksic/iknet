/*
 * Comparable.h
 *
 *  Created on: 9. 6. 2012.
 *      Author: filip
 */

#ifndef COMPARABLE_H_
#define COMPARABLE_H_

namespace poker {

	template<class T>
	class Comparable {
	public:
		Comparable() {
		}
		virtual ~Comparable() {
		}

		virtual int compare(const T&) const = 0;
	};

	template<class T>
	bool operator<(const Comparable<T>& l, const T& r) {
		return l.compare(r) < 0;
	}

} /* namespace poker */
#endif /* COMPARABLE_H_ */

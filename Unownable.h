#ifndef UNOWNABLE_H
#define UNOWNABLE_H


#include <memory>


class Unownable {
	public:
		virtual actionAtIndex(shared_ptr<Player>) = 0;
};


#endif

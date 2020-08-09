#ifndef UNOWNABLE_H
#define UNOWNABLE_H


#include <memory>


class Unownable {
	public:
		Unownable(void);
		virtual void actionAtIndex(std::shared_ptr<Player> p) = 0;
};


#endif

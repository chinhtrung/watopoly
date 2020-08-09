#ifndef UNOWNABLE_H
#define UNOWNABLE_H


class Unownable {
	public:
		virtual actionAtIndex(shared_ptr<Player>) = 0;
};

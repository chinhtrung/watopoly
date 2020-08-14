#ifndef SLC_H
#define SLC_H


#include <memory>


class SLC: public Unownable {
	public:
		SLC();
		virtual void actionAtIndex(std::shared_ptr<Player>) override;
		void testAction(std::shared_ptr<Player>);
};


#endif

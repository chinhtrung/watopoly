#ifndef SLC_H
#define SLC_H


#include <memory>


class SLC {
	public:
		SLC(void);
		virtual void actionAtIndex(std::shared_ptr<Player>) override;
};

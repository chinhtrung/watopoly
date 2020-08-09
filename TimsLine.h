#ifndef TIMSLINE_H
#define TIMSLINE_H


#include <memory>


class TimsLine: public Unownable {
	map<char, int> captured;
	public:
		TimsLine(void);
		virtual void actionAtIndex(std::shared_ptr<Player> p) override;
		void addRoll(char player);
		bool isCaptured(char player);
};


#endif

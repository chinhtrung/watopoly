#include "load.h"


void load() {

	    cout << "Loading in saved game from " << argv[2] << endl;
	    
	    std::ifstream inf{argv[2]};

	    int numPlayers;
	    inf >> numPlayers; 
	    //auto b = std::make_unique<Board>();

	    for (int i = 0; i < numPlayers; i++){
	        string name;
		char gamepiece;
		int numTimsCups;
		int funds;
		int sqrPos;

	        inf >> name;	
		inf >> gamepiece;
		inf >> numTimsCups;
		inf >> funds;
		inf >> sqrPos;
		
		auto p = std::make_shared<Player>(name, gamepiece, funds);
		p->setTimsCup(numTimsCups);
		//b.addPlayer(gamepiece);

		if (sqrPos == DC_TIMS_POS){
		    bool inLine;
		    inf >> inLine;
		    if (inLine){
		        //b.movePlayer(gamepiece, DC_TIMS_POS);
			int turnsInLine;
			inf >> turnsInLine;
			p->moveToDCTims();
		    } else {
		        p->movePlayer(sqrPos); //but without collecting Go money
			// b.movePlayer(gamepiece, sqrPos);
		    }
		} else {
		    p->movePlayer(sqrPos); //but without collecting Go money
		    p->movePlayer(gamepiece, sqrPos);
		}

		group.push_back(p);
	    }

	    for (int i = 0; i < OWNABLE_SIZE; i++){
	        string name;
	        string owner;
		int imprLevel;
		inf >> name;
		inf >> owner;
		inf >> imprLevel;
		
		if (name != "BANK"){
		    int playerIndex;
		    int size = group.size();
		    for (int i = 0; i < size; i++){
                        if (group[i]->getName() == name){
			    playerIndex = i;
                        }
                    }  

		    auto ls = std::make_unique<LoadSave>();
		    ls->loadProperty(name, group[playerIndex], imprLevel);
		}
	    }
	    return;
}

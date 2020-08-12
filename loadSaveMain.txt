if (arg == -load file){
    int numPlayers;
    cin >> numPlayers;
    for (int i = 0; i < numPlayers; i++){
	string name;
	char gamepiece;
	int numTimsCups;
	int funds;
	int pos;
	cin >> name;
	cin >> gamepiece;
	cin >> numTimsCups;
	cin >> funds;
	cin >> pos;
	if (pos == 30){
	    cout << "Bad position. Try again" << endl;
	} else if (pos == 10){
	    bool inLine;
	    cin >> numTurns;
	    if (inLine){
	        int numTurns;
		cin >> numTurns;
		// add player and # of turns to TimsLine
	    }
	}
        shared_ptr<Player> p(new Player( name, gamepiece, numTimsCups, funds, pos));
	gb.addPlayer(p);
    }

    const int NUM_OWNABLE = 22;
    for (int i = 0; i < NUM_OWNABLE; i++){
        string name;
	string owner;
	int numImprovements;  //what if property is mortgaged?
	cin >> name;
	cin >> owner;
	cin >> numImprovements;
	//access square through gameboard
	sqr.setOwner(gb.players[owner]);

	// this sets improvement level and tuition appropriately
	sqr.setImpr(numImprovements);
    }
}

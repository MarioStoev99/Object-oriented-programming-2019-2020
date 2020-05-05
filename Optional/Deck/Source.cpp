#include "Deck.h"
#include <iostream>

using namespace std;

int main()
{
	//Deck d;
	//d.setCard(4,"Blue-eyes white dragon",3000,5000);
	//d.print();
	//cout << d.getMagicCardCount() << endl;
	//cout << d.getMonsterCardCount() << endl;
	Duelist player1("Seto Kaiba");
	player1.changecardinDeck(2, "white dragon", 3000, 4000);
	//player1.printDeck();
	Duelist player2("Dark magician");
	player2.changecardinDeck(0, "Dark magician", 1500, 5000);
	player2.printDeck();
	return 0;
}
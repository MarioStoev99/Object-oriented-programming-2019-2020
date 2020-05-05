#include "Deck.h"
#include <string.h>
#include <iostream>
using namespace std;
const char* Card::getName() const { return name; }
unsigned Card::getDamage() const { return damage; }
unsigned Card::getDefensive() const { return defensive; }
types Card::getType() const { return type; }
void Card::setName(const char* _name) { strcpy(name, _name); }
void Card::setDamage(unsigned _damage) { damage = _damage; }
void Card::setDefensive(unsigned _defensive) { defensive = _defensive; }
void Card::setType(types _type) { type = _type; }

void Deck::print() const
{
	for (int i = 0; i < 40; i++)
	{
		cout << cards[i].getDamage() << " , " 
			 << cards[i].getDefensive() << " , " 
			 << cards[i].getName() << " , "  
			 << cards[i].getType() << endl;
	}
}
Deck::Deck()
{
	for (int i = 0; i < 40; i++)
	{
		cards[i].setName("Token");
		cards[i].setDefensive(0);
		cards[i].setDamage(0);
		cards[i].setType(MONSTER_CARD);
	}
}
void Deck::setCard(unsigned index,const char* cardName,unsigned damage,unsigned defensive)
{
	cards[index].setDamage(damage);
	cards[index].setName(cardName);
	cards[index].setDefensive(defensive);
}
unsigned Deck::getMagicCardCount() const
{
	unsigned cnt = 0;
	for (int i = 0; i < 40; i++)
	{
		if (cards[i].getType() == MAGIC_CARD)
			cnt++;
	}
	return cnt;
}
unsigned Deck::getMonsterCardCount() const
{
	unsigned cnt = 0;
	for (int i = 0; i < 40; i++)
	{
		if (cards[i].getType() == MONSTER_CARD)
			cnt++;
	}
	return cnt;
}
Duelist::Duelist(const char* _name)
{
	strcpy(duelistName, _name);
	Deck d;
}
void Duelist::printDeck() const
{
	d.print();
}
void Duelist::changecardinDeck(unsigned _index, const char* duelistCardName,
	unsigned _damage, unsigned _defensive)
{
	d.setCard(_index, duelistCardName, _damage, _defensive);
}
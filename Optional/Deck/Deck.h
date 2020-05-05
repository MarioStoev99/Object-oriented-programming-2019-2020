#pragma once
enum types{MAGIC_CARD,MONSTER_CARD};
class Card
{
private :
	char name[25];
	unsigned damage;
	unsigned defensive;
	types type;
public :
	const char* getName() const;
	unsigned getDamage() const;
	unsigned getDefensive() const;
	types getType() const;
	void setName(const char*);
	void setDamage(unsigned);
	void setDefensive(unsigned);
	void setType(types);
};
class Deck
{
private :
	Card cards[40];
	
public :
	Deck();
	void print() const;
	void setCard(unsigned,const char*,unsigned,unsigned);
	unsigned getMagicCardCount() const;
	unsigned getMonsterCardCount() const;
};
class Duelist
{
private : 
	char duelistName[1024];
	Deck d;
public : 
	Duelist(const char*);
	void printDeck() const;
	void changecardinDeck(unsigned, const char*, unsigned, unsigned);
};
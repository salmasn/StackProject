#pragma once
#include<iostream>


class Pile
{
private:
	int* tab;
	int sommet;
	int capacity;

public:
	Pile();
	void afficher() const;
	void Empiler(int);
	int depiler();
	bool is_empty() const;
	bool is_full() const;
	~Pile();

};


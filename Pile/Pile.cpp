// Pile.cpp : Définit les fonctions de la bibliothèque statique.
//

#include "pch.h"
#include "framework.h"
#include "Pile.h"

// TODO: Il s'agit d'un exemple de fonction de bibliothèque
void fnPile()
{
}

Pile::Pile():sommet(-1), capacity(4)
{
	this->tab = new int[this->capacity];
}

void Pile::afficher() const
{
	for (int i = this->sommet; i >= 0; i--)
		std::cout<<this->tab[i]<<std::endl;
}

void Pile::Empiler(int a)
{
	if (!is_full())
	{
		this->tab[++this->sommet] = a;
	}
}

int Pile::depiler()
{
	int value=0;
	if (!is_empty())
	{
		value = this->tab[this->sommet--];
	}
	return value;
}


bool Pile::is_empty() const
{
	if (this->sommet == -1) return true;
	return false;
}

bool Pile::is_full() const
{
	if (this->sommet == this->capacity) return true;
	return false;
}

Pile::~Pile()
{
}

#pragma once

template<class T>
class PileGen
{
private:
	T* tab;
	int sommet;
	int capacity;

public:
	PileGen();
	void afficher() const;
	void Empiler(T);
	T depiler();
	bool is_empty() const;
	bool is_full() const;
	~PileGen();

};


template<class T>
PileGen<T>::PileGen() :sommet(0), capacity(4)
{
    this->tab = new T[this->capacity];
}

template<class T>
void PileGen<T>::afficher() const
{
    for (int i = this->sommet-1; i >= 0; i--)
        std::cout << this->tab[i] << std::endl;
}
/*
template<class T>
void PileGen<T>::Empiler(T a)
{
    if (is_full())
    {
        throw std::overflow_error("la pile est full");
    }
    else
    {
        this->tab[++this->sommet] = a;
    }
}
*/

/*

template<class T>
void PileGen<T>::Empiler(T a)
{
    try
    {
        is_full();
    }
    catch (std::overflow_error r)
    {
        T* temp = new T[this->capacity];
        int j = 0;
        this->capacity *= 2;
        T* newpile = new T[this->capacity];

        for (int i = this->sommet; i >= 0; i--)
        {
            temp[j++] = this->tab[i];
        }

        this->tab = nullptr;
        this->sommet = -1;

        for (int i = j; i >= 0; i--)
        {
            newpile[++this->sommet] = temp[i];
        }
        this->tab = newpile;
        delete[] temp;
        delete[] newpile;
    }
    this->tab[++this->sommet] = a;
}
*/


template<class T>
inline void PileGen<T>::Empiler(T object)
{
    try
    {
        is_full();
        this->tab[this->sommet++] = object;
    }
    catch (std::overflow_error e)
    {

        T* temp = new T[this->capacity];
        this->capacity *= 2;
        T* NewStack = new T[this->capacity];

        for (int i = this->sommet-1; i >= 0; i--)
        {
            temp[i] = this->tab[i];
        }

        for (int i = this->sommet-1; i >= 0; i--)
        {
            NewStack[i] = temp[i];
        }
        delete[] this->tab;
        delete[] temp;


        this->tab = NewStack;
        this->tab[this->sommet++] = object;


        NewStack = nullptr;
        delete NewStack;
    }
    
    

}
template<class T>
T PileGen<T>::depiler()
{
    int value;
    try 
    {
        is_empty();
        value = this->tab[--this->sommet];
        return value;
    } 
    catch (std::underflow_error r)
    {
        std::cerr << "Error : " <<r.what()<<std::endl;
    }
}


template<class T>
bool PileGen<T>::is_empty() const
{
    if (this->sommet == 0) throw std::underflow_error("la pile est vide");
    return false;
}

template<class T>
bool PileGen<T>::is_full() const
{
    if (this->sommet >= this->capacity)
    {
        throw std::overflow_error("la pile est full");
    }
    return false;
}

template <class T>
PileGen<T>::~PileGen()
{
}



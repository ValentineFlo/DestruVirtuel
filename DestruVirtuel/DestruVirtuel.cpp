// DestruVirtuel.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

class Voiture
{
public:
    Voiture(const std::string& MARQUE) : m_marque(MARQUE){ std::cout << "Constructeur de base apele" << std::endl; }
    virtual ~Voiture()
    {
        std::cout << "destructeur de base apele" << std::endl;
    }

private:
    std::string m_marque;
};

class Berlin : public Voiture
{
public:
    Berlin(const std::string MARQUE) : Voiture(MARQUE){ std::cout << "Constructeur de la berline apele" << std::endl; }
   ~Berlin()
    {
        std::cout << "destructeur de la berlin apele" << std::endl;
    }
};

int main()
{
    Berlin* mercedes = new Berlin("SL65");
//Error, on ne détruit pas mercedes car le destructeur de berlin n'est pas appelé peut causer des fuites de memoire c pour cela que les destructeurs doivent etre virtuel
     Voiture* ptr_mercedes = mercedes;
    delete ptr_mercedes;

}


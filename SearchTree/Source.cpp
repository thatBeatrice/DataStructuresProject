#include "SearchTree.h"

void meniuProgram(SearchTree BST)
{
	int ok = 1, numarAles, nr; 
	node* nod; 
	std::vector<int>v;
	while (ok)
	{
		system("cls");
		std::cout << "1 - Insereaza un numar;\n2 - Construieste un arbore binar dintr-un vector; \n3 - Cauta un numar in arbore; \n";
		std::cout << "4 - Sterge un numar;\n5 - Afiseaza maximul dintr-un subarbore; \n6 - Afiseaza minimul dintr-un subarbore; \n";
		std::cout << "7 - Cauta succesorul unui numar;\n8 - Cauta predecesorul unui numar; \n9 - Afiseaza arborele.\n";
		std::cout << "10 - Goleste arborele;\n11 - Verifica daca arborele este vid; \n12 - Inchide meniul.\n";
		std::cin >> numarAles;
		switch (numarAles)
		{
		case 12:
			ok = 0;
			break;
		case 1:
			std::cout << "Scrie numarul care vrei sa fie inserat:\n";
			std::cin >> nr;
			BST.insert(nr);
			break;
		case 2:
			std::cout << "Numarul de elemente:\n";
			std::cin >> nr;
			v.resize(nr);
			for (int i = 0; i < v.size(); i++)
			{
				std::cin >> v[i];
			}
			BST.construct(v);
			break;
		case 3:
			std::cout << "Cheia pe care vrei sa o cauti:\n";
			std::cin >> nr;
			if (BST.find(nr))
				std::cout << "Numarul exista in arbore.\n";
			else
				std::cout << "Numarul nu exista in arbore.\n";
			system("PAUSE");
			break;
		case 4:
			std::cout << "Numarul pe care vrei sa il stergi:\n";
			std::cin >> nr;
			BST.deleteNode(nr);
			break;
		case 5:
			std::cout << "Radacina arborelui din care cauti maximul:\n";
			std::cin >> nr;
			nod = BST.find(nr);
			nod = BST.maxim(nod);
			std::cout << "Maximul este: " << nod->value << "\n";
			system("PAUSE");
			break;
		case 6:
			std::cout << "Radacina arborelui din care cauti minimul:\n";
			std::cin >> nr;
			nod = BST.find(nr);
			nod = BST.minim(nod);
			std::cout << "Minimul este: " << nod->value << "\n";
			system("PAUSE");
			break;
		case 7:
			std::cout << "Numarul caruia ii cauti succesorul:\n";
			std::cin >> nr;
			nod = BST.find(nr);
			nod = BST.succesor(nod);
			if (nod)
				std::cout << "Succesorul este: " << nod->value << "\n";
			else
				std::cout << "Numarul nu are succesor.\n";
			system("PAUSE");
			break;
		case 8:
			std::cout << "Numarul caruia ii cauti predecesorul:\n";
			std::cin >> nr;
			nod = BST.find(nr);
			nod = BST.predecesor(nod);
			if (nod)
				std::cout << "Predecesorul este: " << nod->value << "\n";
			else
				std::cout << "Numarul nu are predecesor.\n";
			system("PAUSE");
			break;
		case 9:
			std::cout << "Alege in ce mod vrei sa afisezi arborele:\n1 - RSD\n2 - SRD\n3 - SDR\n4 - Nivel\n";
			std::cin >> nr;
			BST.print_tree(nr); std::cout << "\n";
			system("PAUSE");
			break;
		case 10:
			BST.clear();
			break;
		case 11:
			if (BST.empty())
				std::cout << "Arborele este vid.\n";
			else
				std::cout << "Arborele contine chei.\n";
			system("PAUSE");
			break;
		}
	}
}
int main()
{
	SearchTree BST;
	meniuProgram(BST);
	return 0;
}

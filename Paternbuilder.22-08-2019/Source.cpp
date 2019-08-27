#include"Header.h"
//PATERN BUILDER
//int main()
//{
//	int choise = 0;
//	cout << "Create\n1.Gamer\n2.Office\n3.Random\n";
//	cin >> choise;
//	if (choise == 1)
//	{
//		NoteBookShop* shop = new NoteBookShop();
//		NoteBookBuilder* builder = new GamerNoteBookBuilder();
//		shop->createNoteBook(builder);
//		builder->getNoteBook()->Show();
//		cout << builder->getNoteBook()->chekPart("ccc") << endl;
//		delete shop;
//		delete builder;
//	}
//	else if (choise == 2)
//	{
//		NoteBookShop* shop = new NoteBookShop();
//		NoteBookBuilder* builder = new OfficeNoteBookBuilder();
//		shop->createNoteBook(builder);
//		builder->getNoteBook()->Show();
//		cout << builder->getNoteBook()->chekPart("ccc") << endl;
//		delete shop;
//		delete builder;
//	}
//	else if (choise == 3)
//	{
//		NoteBookShop* shop = new NoteBookShop();
//		NoteBookBuilder* builder = new CastingNoteBookBuilder();
//		shop->createNoteBook(builder);
//		builder->getNoteBook()->Show();
//		cout << builder->getNoteBook()->chekPart("ccc") << endl;
//		delete shop;
//		delete builder;
//	}
//	string memory;
//	cin >> memory;
//
//	system("pause");
//}

Unit* createPrototipe::Prototipes[3] = { new Archer(),new Mag(),new Swordsman() };
Weapon* createWeapon::Prototipe[3] = { new Drow(),new Scipetr(),new Sword() };

int main()
{
	cout << "What create\n1.text\n2.html\n";
	int choise = 0;
	cin >> choise;
	if (choise == 1)
	{
		Builder* Build = new Builder();
		TextHTMLBuilder* txml = new TextBuilder();
		Build->setBuilder(txml);
		txml->getTextHTML()->Show();
	}
	else
	{
		Builder* Build = new Builder();
		TextHTMLBuilder* txml = new HTMLBuilder();
		Build->setBuilder(txml);
		txml->getTextHTML()->Show();
	}


	vector<Unit*> team;
	vector<Weapon*> wpteam;
	//int choise = 0;
	cout << "Chouse player\n1.Archer\n2.Mage\n3.Swordsman\n4.Exit\n";
	cin >> choise;
	team.push_back(createPrototipe::CreatePlayer(Players(choise)));
	cout << "Chouse weapon\n1.Drow\n2.Scipetr\n3.Sword\n4.Exit\n";
	cin >> choise;
	wpteam.push_back(createWeapon::CreateWeapon(WEAPON(choise)));
	for (auto el : team)
	{
		el->play();
		cout << endl;
	}
	for (auto el : wpteam)
	{
		el->WPN();
		cout << endl;
	}
	for (auto el : wpteam)
	{
		delete el;
	}
	for (auto el : team	)
	{
		delete team;
	}


	system("pause");
}


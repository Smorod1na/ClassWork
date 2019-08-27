#pragma once
#include<iostream>
#include<ctime>
#include<string>
#include<vector>
#include<map>
using namespace std;

//class Notebook
//{
//	string Name;
//	map<string, string> mmm;
//
//public:
//	Notebook(string name="ooo") :Name(name) {
//
//	}
//	string getPart(const string&key)
//	{
//		return mmm[key];
//	}
//	void setPart(const string&key, const string&value)
//	{
//		mmm[key] = value;
//	}
//	void Show()const
//	{
//		for (auto el : mmm)
//		{
//			cout<<"Parametr: " << el.first<<" ";
//			cout << el.second<<endl;
//		}
//	}
//	bool chekPart(const string&key)
//	{
//		return mmm.find(key) != mmm.end()?true:false;
//	}
//	virtual ~Notebook() {
//
//	}
//};
//class NoteBookBuilder
//{
//protected:
//	Notebook* device;
//public:
//	NoteBookBuilder()
//	{
//		device = new Notebook();
//	}
//	virtual void setMemory()=0;
//	
//	virtual void setHDD() = 0;
//	
//	virtual void setMatrix() = 0;
//	
//	virtual void setProcessor() = 0;
//	Notebook* getNoteBook()
//	{
//		return this->device;
//	}
//};
//class GamerNoteBookBuilder:public NoteBookBuilder
//{
//public:
//	GamerNoteBookBuilder()
//	{
//		device = new Notebook("Gamer");
//	}
//	void setMemory()
//	{
//		device->setPart("memory", "16 GB");
//	}
//	void setHDD()
//	{
//		device->setPart("HDD", "500hdd ");
//	}
//	void setMatrix()
//	{
//		device->setPart("Matrix", "1080B");
//	}
//	void setProcessor()
//	{
//		device->setPart("Processor", "2.0Ggz");
//	}
//};
//class OfficeNoteBookBuilder :public NoteBookBuilder
//{
//public:
//	OfficeNoteBookBuilder()
//	{
//		device = new Notebook("Office");
//	}
//	void setMemory()
//	{
//		device->setPart("memory", "8 GB");
//	}
//	void setHDD()
//	{
//		device->setPart("HDD", "300hdd ");
//	}
//	void setMatrix()
//	{
//		device->setPart("Matrix", "780B");
//	}
//	void setProcessor()
//	{
//		device->setPart("Processor", "1.52Ggz");
//	}
//};
//class CastingNoteBookBuilder :public NoteBookBuilder
//{
//public:
//	CastingNoteBookBuilder()
//	{
//		device = new Notebook("Casting");
//	}
//	void setMemory()
//	{
//		device->setPart("memory", "32 GB");
//	}
//	void setHDD()
//	{
//		device->setPart("HDD", "800hdd ");
//	}
//	void setMatrix()
//	{
//		device->setPart("Matrix", "1280B");
//	}
//	void setProcessor()
//	{
//		device->setPart("Processor", "2.5Ggz");
//	}
//};
//class NoteBookShop
//{
//public:
//	void createNoteBook(NoteBookBuilder* builder)
//	{
//		builder->setMemory();
//		builder->setHDD();
//		builder->setMatrix();
//		builder->setProcessor();
//	}
//};


class TextHTML
{
	string text;
public:
	TextHTML(string text="none") :text(text) {

	}
	void Clear()
	{
		text.clear();
	}
	void setTextHTML(string text)
	{
		this->text += text;
	}
	void Show()const
	{
		cout << text << endl;
	}
};
class TextHTMLBuilder
{
protected:
	TextHTML* txt;
public:
	/*TextHTMLBuilder()
	{
		txt = new TextHTML();
	}*/
	virtual void setText() = 0;
	virtual void setMain() = 0;
	virtual void setFooter() = 0;
	TextHTML* getTextHTML()
	{
		return this->txt;
	}
};
class TextBuilder:public TextHTMLBuilder
{
public:
	TextBuilder() {
		txt = new TextHTML;
	}
	void setText()
	{
		txt->Clear();
		txt->setTextHTML("Text\n");
	}
	void setMain()
	{
		txt->setTextHTML("Osnovna chastuna\n");
	}
	void setFooter()
	{
		txt->setTextHTML("Data pidpus\n");
	}
};
class HTMLBuilder :public TextHTMLBuilder
{
public:
	HTMLBuilder() {
		txt = new TextHTML;
	}
	void setText()
	{
		txt->Clear();
		txt->setTextHTML("<h>Text</h>");
	}
	void setMain()
	{
		txt->setTextHTML("<main>Osnovna chastuna</main>\n");
	}
	void setFooter()
	{
		txt->setTextHTML("<footer>Data pidpus</footer>\n");
	}
};
class Builder
{
public:
	void setBuilder (TextHTMLBuilder* build)
	{
		build->setText();
		build->setMain();
		build->setFooter();
	}
};

//Продемонструвати створення  різних видів зброї для деякої  гри(можна доповнити задачу про юніти).
//У програмі визначити масив з об’єктів зброї(прототипів).Застосувати патерн Прототип.

enum Players { ARCHER = 1, MAG = 2, SWORDSMAN = 3 };
enum WEAPON{DROW =1,SCIPETR=2,SWORD=3};
class Unit
{
	string name;
public:
	Unit(string name = "none") :name(name) {}
	string getname()const
	{
		return name;
	}

	virtual Unit* Clone() = 0;
	virtual void play() = 0;
	virtual ~Unit() {
	}
};
class  Archer : public Unit
{
public:
	Archer() :Unit("Archer") {}
	virtual void play()
	{
		cout << Unit::getname();
	}
	Unit* Clone()
	{
		return new Archer(*this);
	}
};
class  Mag : public Unit
{
public:
	Mag() :Unit("Mag") {}
	virtual void play()
	{
		cout << Unit::getname();
	}
	Unit* Clone()
	{
		return new Mag(*this);
	}
};
class  Swordsman : public Unit
{
public:
	Swordsman() :Unit("Swordsman") {}
	virtual void play()
	{
		cout << Unit::getname();
	}
	Unit* Clone()
	{
		return new Swordsman(*this);
	}
};

class createPrototipe
{
private:
	static Unit* Prototipes[3];
public:
	static Unit*CreatePlayer(Players type)
	{
		switch (type)
		{
		case ARCHER:return Prototipes[type - 1]->Clone();
		case MAG:return Prototipes[type - 1]->Clone();
		default:
		case SWORDSMAN:return Prototipes[type - 1]->Clone();
		}
	}
};



class Weapon
{
	string weapon;
public:
	Weapon(string weapon = "none"):weapon(weapon){

	}
	string getWeapon()
	{
		return weapon;
	}
	void setWeapon(string wpn)
	{
		weapon = wpn;
	}
	virtual Weapon* Clone() = 0;
	virtual void WPN() = 0;
	virtual ~Weapon() {

	}
};
class Drow :public Weapon
{
public:
	Drow() :Weapon("Drow") {

	}
	void WPN()
	{
		cout << Weapon::getWeapon();
	}
	virtual Weapon* Clone()
	{
		return new Drow(*this);
	}
};
class Scipetr:public Weapon
{
public:
	Scipetr() :Weapon("Scipetr") {

	}
	void WPN()
	{
		cout << Weapon::getWeapon();
	}
	virtual Weapon* Clone()
	{
		return new Scipetr(*this);
	}
};
class Sword :public Weapon
{
public:
	Sword() :Weapon("Sword") {

	}
	void WPN()
	{
		cout << Weapon::getWeapon();
	}
	virtual Weapon* Clone()
	{
		return new Sword(*this);
	}
};
class createWeapon
{
private:
	static Weapon* Prototipe[3];
public:
	static Weapon*CreateWeapon(WEAPON type)
	{
		switch (type)
		{
		case DROW:return Prototipe[type - 1]->Clone();
		case SCIPETR:return Prototipe[type - 1]->Clone();
		default:
		case SWORD:return Prototipe[type - 1]->Clone();
		}
	}
};


#include <iostream>
#include <string>
using namespace std;

class ComputerGameObject
{
private:
	string title;
protected:
	
	ComputerGameObject() : title("") {}
	ComputerGameObject(const ComputerGameObject& obj) : title(obj.title) {}
	ComputerGameObject(const string& _title) : title(_title) {}
	virtual ~ComputerGameObject() { cout << "ComputerGameObject deleted" << endl << endl; }
	virtual void _print() const { cout << "title: " << title; }
public: 
	void print() const
	{
		cout << typeid(*this).name() << ": (";
		_print();
		cout << ")" << endl;
	}
	string get_title() { return title; }
};

class creature : public ComputerGameObject
{
private:
	int x, y;
	double mass, speed;
	
public:
	creature() : ComputerGameObject() {}
	creature(const creature& obj) : ComputerGameObject(obj), x(obj.x), y(obj.y), mass(obj.mass), speed(obj.speed){}
	creature(const string& _title, double _mass, int _x, int _y, double _speed) : ComputerGameObject(_title), mass(_mass), x(_x), y(_y), speed(_speed) {}
	~creature() { cout << "creature deleted" << endl; }
	int get_x() const { return x; }
	int get_y() const { return y; }
	double get_mass() const { return mass; }
	double get_speed() const { return speed; }
	void move(int x, int y)
	{
		if (speed > 0 && sqrt(x*x + y*y) <= speed) {
			this->x += x;
			this->y += y;
		}
		else cout << "Impossible. Speed = " << speed << endl;
		//cout << ComputerGameObject::get_title() << " located at (" << get_x() << ":" << get_y() << ")" << endl;
	}
	void drow()
	{
		cout << ComputerGameObject::get_title() << " located at (" << get_x() << ":" << get_y() << ")" << endl;
	}
protected:
	//virtual void move(int x, int y) = 0;
	void _print() const
	{
		ComputerGameObject::_print();
		cout <<", mass: " << mass << ", speed: " << speed << ", x: " << x << ", y: " << y;
	}
};

class MythAnimal : public creature
{
private:
	string danger;
public:
	MythAnimal() : creature() {}
	MythAnimal(const MythAnimal& obj) : creature(obj), danger(obj.danger) {}
	MythAnimal(const string& _title, double _mass, int _x, int _y, double _speed, string _danger) : creature(_title, _mass, _x, _y, _speed), danger(_danger) {}
	~MythAnimal() { cout << "MythAnimal deleted" << endl; }
	void _move(int x, int y)
	{
		creature::move(x, y);
	}
	void _drow()
	{
		creature::drow();
	}
	string det_danger() { return danger; }
protected:
	void _print() const
	{
		creature::_print();
		cout << ", danger: " << danger;
	}
};

class human : public creature
{
private:
	int skills;
public:
	
	human() : creature() {}
	human(const human& obj) : creature(obj), skills(obj.skills) {}
	human(const string& _title, double _mass, int _x, int _y, double _speed, int _skills) : creature(_title, _mass, _x, _y, _speed), skills(_skills) {}
	~human() { cout << "human deleted" << endl; }
	void _move(int x, int y)
	{
		creature::move(x, y);
	}
	void _drow()
	{
		creature::drow();
	}
	int get_skills() { return skills; }
protected:
	void _print() const
	{
		creature::_print();
		cout << ", skills: " << skills;
	}
};

class MagHuman : public human
{
private:
	string types_of_magic;
public:
	MagHuman() : human() {}
	MagHuman(const MagHuman& obj) : human(obj), types_of_magic(obj.types_of_magic) {}
	MagHuman(const string& _title, double _mass, int _x, int _y, double _speed, int _skills, string _types_of_magic) : human(_title, _mass, _x, _y, _speed, _skills), types_of_magic(_types_of_magic) {}
	~MagHuman() { cout << "MagHuman deleted" << endl; }
	void _move(int x, int y)
	{
		human::_move(x, y);
	}
	void _drow()
	{
		human::_drow();
	}
protected:
	void _print() const
	{
		human::_print();
		cout << ", magic: " << types_of_magic;
	}

};

class MagAnimal : public MythAnimal
{
private:
	string types_of_magic;
public:
	MagAnimal() : MythAnimal() {}
	MagAnimal(const MagAnimal& obj) : MythAnimal(obj), types_of_magic(obj.types_of_magic) {}
	MagAnimal(const string& _title, double _mass, int _x, int _y, double _speed, string _danger, string _types_of_magic) : MythAnimal(_title, _mass, _x, _y, _speed, _danger), types_of_magic(_types_of_magic) {}
	~MagAnimal() { cout << "MagAnimal deleted" << endl; }
	void _move(int x, int y)
	{
		MythAnimal::_move(x, y);
	}
	void _drow()
	{
		MythAnimal::_drow();
	}
protected:
	void _print() const
	{
		MythAnimal::_print();
		cout << ", magic: " << types_of_magic;
	}
};

class MagItem : public ComputerGameObject
{
private:
	string description;
public:
	MagItem() : ComputerGameObject() {}
	MagItem(const MagItem& obj) : ComputerGameObject(obj), description(obj.description) {}
	MagItem(const string& _title, string _description) : ComputerGameObject(_title), description(_description) {}
	~MagItem() { cout << "MagItem deleted" << endl; }
protected:
	void _print() const
	{
		ComputerGameObject::_print();
		cout << ", description: " << description;
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");
	
	creature tree("Дерево", 300, 10, 50, 0);
	tree.print();
	creature tree1("Дерево", 350, 10, 15, 0);
	tree1.print();
	creature tree2("Дерево", 277, 6, 105, 0);
	tree2.print();
	creature tree3("Дерево", 15, 90, 1015, 0);
	tree3.print();
	creature tree4("Дерево", 1000, 120, 159, 0);
	tree4.print();
	creature tree5("Дерево", 500, 110, 185, 0);
	tree5.print();
	MythAnimal a1("Химера", 80, 10, 150, 30, "Чрезвычайно опасный");
	a1.print();
	a1.drow();
	a1.move(10, 5);
	a1.drow();
	a1.move(100, 5);
	a1.drow();

	human Alex("Алексей", 50, 1000, 1500, 15, 100);
	Alex.print();
	Alex.drow();

	MagItem n("Звезда", "***");
	n.print();

	MagHuman Aang("Аанг", 40, 300, 800, 400, 140, "Воздух");
	Aang.print();
	Aang.move(100, 130);
	Aang.drow();

	MagAnimal Appa("Аппа", 500, 300, 800, 1000, "Безобидный", "Воздух");
	Appa.print();
	Appa.drow();

	

	system("pause");
	return 0;
}

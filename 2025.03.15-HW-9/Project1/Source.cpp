#include<string>
#include<iostream>
#include<ctime>

using namespace std;

struct Student
{
	string name;
	int hp;
	int dmg;
	int luck;

	Student(string name, int hp = 100, int dmg = 5, int luck = 10) :
		name(name), hp(hp), dmg(dmg), luck(luck)
	{
	}

	Student(const Student& student) :
		name(student.name),
		hp(student.hp),
		dmg(student.dmg),
		luck(student.luck)
	{}

	~Student()
	{
	}

	bool luckWorks()
	{
		return (rand() % 100 < luck);
	}

	bool isDead()
	{
		return (hp < 1);
	}

	void getDmg(int dmg)
	{
		if (luckWorks())
		{
			cout << "\t" << name << " LUCK WORKS FOR GETTING DAMAGE\n";
			dmg /= 2;
		}
		hp -= dmg;
	}

	int makeDmg()
	{
		if (luckWorks())
		{
			cout << "\t" << name << " LUCK WORKS FOR MAKING DAMAGE\n";
			return dmg * 2;
		}
		else
		{
			return dmg;
		}
	}

	void print()
	{
		cout << name << " [" << hp << "] (";
		cout << "luck=" << luck << ";";
		cout << "damage=" << dmg << ")\n";
	}
};

void battle(Student st1, Student st2)
{
	int round = 1;
	while (!(st1.isDead() || st2.isDead()))
	{
		cout << "\t\tROUND " << round++ << "\n";
		st1.print();
		cout << "versus\n";
		st2.print();
		st1.getDmg(st2.makeDmg());
		st2.getDmg(st1.makeDmg());
		if (st1.name == "Edgar" && st1.luckWorks())
		{
			st1.getDmg(-st1.makeDmg());
		}
	}
	if (st1.isDead() && st2.isDead())
	{
		cout << "DRAW\n";
	}
	else
	{
		cout << (st1.isDead() ? st2.name : st1.name) << " wins\n";
	}
}

int main()
{
	srand(time(0));
	Student st1("BOBA", 150, 5, 0);
	Student st2("BIBA", 60, 10, 30);
	battle(st1, st2);
	return 0;
}

#include <algorithm>
#include <iostream>
#include <exception>
#include <vector>
using namespace std;

int CallFunction(int num)
{
	if (num == 0) throw std::invalid_argument("Num can't be 0");
	return num + 1;
}

void TestMe(int num)
{
	int d = CallFunction(num);

}

class Player
{
	string name;
	int jersey;
public:
	Player(string nam, int j)
	{
		if (nam.length() < 2)
		{
			auto e = std::invalid_argument("nam måste vara längre än 2");
			throw e;
		}
		
		name = nam;
		jersey = j;
	}
	string GetName()
	{
		return name;
	}
	bool SetName(string nam)
	{
		if (nam.length() < 2)
			return false;
		name = nam;
		return  true;
	}
};

class Team
{
public:
	Team(string name) { Name = name; }
	string Name;
	vector<Player> Players;
};

template <class T>
class Stack
{
	vector<T> varden;
public:
	void Push(T v)
	{
		varden.push_back(v);
	}
	int size()
	{
		return varden.size();
	}
	T Top()
	{
		return varden[varden.size() - 1];
	}
	void Pop()
	{
		varden.pop_back();
	}
};

template <class T>
T GetBiggestOf(T a, T  b)
{
	if (a > b) return a;
	return b;
}



void main()
{
	Team a = Team("AIK");
	a.Players.push_back(Player("aasdads", 12));
	a.Players.push_back(Player("basdads", 13));
	Team ab= Team("DIF");
	ab.Players.push_back(Player("cadsasddas", 13));
	vector<Team> teams{
		a,ab
	
	};

	for_each(teams.begin(), teams.end(), [](Team t)
		{
			cout << t.Name << endl;
			for_each(t.Players.begin(), t.Players.end(), [t](Player p)
				{
					cout << "Igall du glömt: laget vi listar just nu hetrer " << t.Name << endl;
					cout << p.GetName() << endl;
				});
		});
	
	// TENTA: 24 frågor, 3 h
	// Tre Algorithm                 * 3p
	// En annan ... hmmm...??        * 3p
	// 20st 1x2 frågor * 1p
	
	//nested lambda 14
	
	/*string s = "Apa";
	string s2 = "Bok";
	if(s < s2)
	{
				
	}*/
	auto b = 13;
	int r = GetBiggestOf<int>(12, 13);
	string r2 = GetBiggestOf<string>("Apa", "Bok");
	
	Stack<Player> playerStack;
	Stack<int> intStack;
//	Player p;
	try
	{
		Player p("3", 123);
		int i;
		i = 123;
	}
	catch(exception &ex)
	{
		cout << ex.what()  << endl;
	}
	
	
	//Denna ska 
	//skriva ut exception message (dvs Num can't be 0)
	//skriva ut Klar
	TestMe(0);

	//Denna ska 
	//skriva ut detta gick bra - resultatet blev 2
	//skriva ut Klar
	TestMe(1);
}



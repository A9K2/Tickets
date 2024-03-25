#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

class Movie {
public:
	string title;
	string director;
	string genre;
	float duration;
	void Print() {
		cout << "Title:" << title << "\nDirector:" << director << "\nGenre:" << genre << "\nDuration:" << duration<<" hours" << endl;
	}
};
int main() {
	SetConsoleOutputCP(1251);
    	SetConsoleCP(1251);
	Movie SpiderMan;
	SpiderMan.title = "SpiderMan";
	SpiderMan.director = "John Weak";
	SpiderMan.genre = "Mystic";
	SpiderMan.duration = 1.50;
	SpiderMan.Print();
	return 0;
}

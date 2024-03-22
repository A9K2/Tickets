#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

class MovieSchedule {
private:
    vector<string> movieList;

public:
    void display(const vector<string>& movies)
    {
        if (movies.empty())
        {
            cout << "Афіша порожня" << endl;
        }
        else
        {
            for (const string& movie : movies)
            {
                cout << "-" << movie << endl;
            }
        }
    }

};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    MovieSchedule schedule;
    vector<string> movies = { "m1", "m2", "m3" }; 

    schedule.display(movies); 

    return 0;
}

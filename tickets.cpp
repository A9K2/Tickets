include <iostream>
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
            int i = 1;
            for (const string& movie : movies)
            {
                cout << i << ") " << movie << endl;
                i++;
            }
        }
    }

};


class Movie : public MovieSchedule {
public:
    string title;
    string director;
    string genre;
    float duration;
    void Print() {
        cout << "Title:" << title << "\nDirector:" << director << "\nGenre:" << genre << "\nDuration:" << duration << " hours" << endl;
    }
};


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    MovieSchedule schedule;
    vector<string> movies = { "Людина Павук", "Я, Побєда, і Берлін", "Дюна" };

    schedule.display(movies); 


    Movie SpiderMan, Berlin, Duna;
    int number;

    cout << "Оберіть фільм" << endl;
    cin >> number;
    
    switch (number)
    {
    case 1:
        SpiderMan.title = movies[number - 1];
        SpiderMan.director = "John Weak";
        SpiderMan.genre = "Mystic";
        SpiderMan.duration = 1.50;
        SpiderMan.Print();
        break;
    case 2:
        Berlin.title = movies[number - 1];
        Berlin.director = "Emil";
        Berlin.genre = "Mystic";
        Berlin.duration = 1.50;
        Berlin.Print();
        break;
    case 3:
        Duna.title = movies[number - 1];
        Duna.director = "Danil";
        Duna.genre = "Mystic";
        Duna.duration = 1.50;
        Duna.Print();
        break;
    default:
        break;
    }
    

    return 0;
}


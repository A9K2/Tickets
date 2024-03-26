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

    Movie() : title(""), director(""), genre(""), duration(0.0) {}
    Movie(string title, string director, string genre, float duration) : title(title), director(director), genre(genre), duration(duration) {}
    
    void Print() {
        cout << "Title:" << title << "\nDirector:" << director << "\nGenre:" << genre << "\nDuration:" << duration << " hours" << endl;
    }
};

class TicketPurchase {
private:
    Movie movie;
    int numberOfTickets;
    float ticketPrice;

public:
    TicketPurchase(Movie movie, int numberOfTickets, float ticketPrice) : movie(movie), numberOfTickets(numberOfTickets), ticketPrice(ticketPrice) {}

    Movie getMovie() const {
        return movie;
    }

    int getNumberOfTickets() const {
        return numberOfTickets;
    }

    float getTicketPrice() const {
        return ticketPrice;
    }

    float getTotalPrice() const {
        return numberOfTickets * ticketPrice;
    }

    void generateReceipt() const {
        cout << "Квитанція:" << endl;
        cout << "Фільм: " << movie.title << endl;
        cout << "Режисер: " << movie.director << endl;
        cout << "Жанр: " << movie.genre << endl;
        cout << "Тривалість: " << movie.duration << " годин" << endl;
        cout << "Кількість квитків: " << numberOfTickets << endl;
        cout << "Ціна квитка: $" << ticketPrice << endl;
        cout << "Загальна вартість: $" << getTotalPrice() << endl;
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

    int numOfTickets;
    cout << "Введіть кількість квитків, які ви хочете придбати: ";
    cin >> numOfTickets;

    float ticketPrices[] = { 10.0, 8.0, 12.0 };
    float selectedMoviePrice = ticketPrices[number - 1];

    TicketPurchase purchase((number == 1) ? SpiderMan : (number == 2) ? Berlin : Duna, numOfTickets, selectedMoviePrice);

    cout << "Ви купуєте " << numOfTickets << " квитки на " << purchase.getMovie().title << "." << endl;
    cout << "Загальна вартість: $" << purchase.getTotalPrice() << endl;

    char confirmation;
    cout << "Підтвердіть покупку (Y/N): ";
    cin >> confirmation;

    if (confirmation == 'Y' || confirmation == 'y') {
        cout << "Покупку підтверджено. Насолоджуйтесь фільмом!" << endl;
        purchase.generateReceipt();
    }
    else {
        cout << "Purchase canceled." << endl;
    }

    return 0;
}


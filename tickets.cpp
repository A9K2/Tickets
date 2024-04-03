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
        cout << "\nКвитанція:" << endl;
        cout << "Фільм: " << movie.title << endl;
        cout << "Режисер: " << movie.director << endl;
        cout << "Жанр: " << movie.genre << endl;
        cout << "Тривалість: " << movie.duration << " годин" << endl;
        cout << "Кількість квитків: " << numberOfTickets << endl;
        cout << "Ціна квитка: $" << ticketPrice << endl;
        cout << "Загальна вартість: $" << getTotalPrice() << endl;
    }

    void refundTickets(int numTicketsToRefund, const Movie& refundMovie) {
            if (refundMovie.title != movie.title) { 
                cout << "Помилка: Ви не можете повернути квитки для іншого фільму." << endl;
            }
    
            if (numTicketsToRefund > numberOfTickets) {
                cout << "Помилка: Недостатньо квитків для повернення." << endl;
            }
    
            float refundAmount = numTicketsToRefund * ticketPrice;
            numberOfTickets -= numTicketsToRefund;
    
            cout << "Квитки успішно повернуті." << endl;
            cout << "Сума повернення: $" << refundAmount << endl;
        }
};
void displayMenu() {
    system("cls");
}



int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<string> movies = { "Людина Павук", "Я, Побєда, і Берлін", "Дюна" };

    vector<Movie> movieArray = {
        Movie("Людина Павук", "John Weak", "Mystic", 1.5),
        Movie("Я, Побєда, і Берлін", "Emil", "Mystic", 1.5),
        Movie("Дюна", "Danil", "Mystic", 1.5)
    };
    float ticketPrices[] = { 10.0, 8.0, 12.0 };

    TicketPurchase* purchase = nullptr;
    
    MovieSchedule schedule;
    

    do {
        displayMenu();
        schedule.display(movies);
        cout << "\nВведіть команду ('купити білет - 1', 'повернути білет - 2', 'вийти з програми - 3'): ";
        int command;
        cin >> command;

        switch (command) {
        case 1: {
            
            int number;
            cout << "Оберіть фільм: ";
            cin >> number;

            if (number < 1 || number > movieArray.size()) {
                cout << "Недійсний вибір фільму." << endl;
                continue;
            }

            Movie selectedMovie = movieArray[number - 1];
            selectedMovie.Print();

            int numOfTickets;
            cout << "\nВведіть кількість квитків, які ви хочете придбати: ";
            cin >> numOfTickets;

            float selectedMoviePrice = ticketPrices[number - 1];

            purchase = new TicketPurchase(selectedMovie, numOfTickets, selectedMoviePrice);

            cout << "Ви купуєте " << numOfTickets << " квитки на " << purchase->getMovie().title << "." << endl;
            cout << "Загальна вартість: $" << purchase->getTotalPrice() << endl;

            char confirmation;
            cout << "\nПідтвердіть покупку (Y/N): ";
            cin >> confirmation;

            if (confirmation == 'Y' || confirmation == 'y') {
                cout << "\nПокупку підтверджено. Насолоджуйтесь фільмом!" << endl;
                purchase->generateReceipt();
            }
            else {
                cout << "Відмінено" << endl;
            }

            break;
        }
        case 2: {
            if (purchase == nullptr) {
                cout << "Ви ще не придбали квитки. Немає що повертати." << endl;
                break;
            }

            cout << "\nВиберіть фільм для повернення квитків:" << endl;
            for (int i = 0; i < movieArray.size(); ++i) {
                cout << i + 1 << ") " << movieArray[i].title << endl;
            }

            int refundMovieChoice;
            cout << "Оберіть фільм: ";
            cin >> refundMovieChoice;

            if (refundMovieChoice < 1 || refundMovieChoice > movieArray.size()) {
                cout << "Недійсний вибір фільму." << endl;
                continue;
            }

            Movie refundMovie = movieArray[refundMovieChoice - 1];

            if (refundMovie.title != purchase->getMovie().title) {
                cout << "Помилка: Ви не можете повернути квитки для іншого фільму." << endl;
                break;
            }

            int numTicketsToRefund;
            cout << "Скільки квитків ви хочете повернути для фільму '" << refundMovie.title << "'? \n";
            cin >> numTicketsToRefund;

            purchase->refundTickets(numTicketsToRefund, refundMovie);

            break;
        }
        case 3: {
            return 0;
        }
        default: {
            cout << "Невідома команда. Спробуйте ще раз." << endl;
            break;
        }
        }
        cout << "\nНатисніть Enter для продовження...";
        cin.ignore();
        cin.get();
    } while (true);
    return 0;
}


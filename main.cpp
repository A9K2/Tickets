#include <iostream>
#include <vector>
#include <string>
#include "Movie.h"
#include "MovieSchedule.h"
#include "TicketPurchase.h"


int main() {

    // Create instances of classes
    MovieSchedule schedule;
    TicketPurchase ticketPurchase(50.0f); 

    // Sample movie list
    std::vector<Movie> movies = {
        {"m1", "Director1", "Action", 2.0f, 10.0f},
        {"m2", "Director2", "Comedy", 1.5f, 8.0f},
        {"m3", "Director3", "Drama", 2.5f, 12.0f}
    };

    // Display available movies
    std::cout << "Available Movies:" << std::endl;
    schedule.display(movies);
    std::cout << std::endl;

    // Process commands entered by the user until they decide to quit
    while (true) {
        std::string command;
        std::cout << "Enter command (e.g., buy <film name> or quit): ";
        std::getline(std::cin >> std::ws, command);

        // Check if the user wants to quit
        if (command == "quit") {
            break;
        }

        // Process the command
        ticketPurchase.processCommand(command, movies);

        // Display purchased tickets
        std::cout << "Displaying purchased tickets:" << std::endl;
        ticketPurchase.displayPurchasedTickets();
    }

    return 0;
}

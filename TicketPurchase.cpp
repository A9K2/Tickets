#include "TicketPurchase.h"

TicketPurchase::TicketPurchase(float initialBalance) : userBalance(initialBalance) {

}

void TicketPurchase::processCommand(const std::string& command, const std::vector<Movie>& movies) {
    std::string operation;
    std::string action;
    size_t pos = command.find(" ");
    if (pos != std::string::npos) {
        operation = command.substr(0, pos);
        action = command.substr(pos + 1);
    }
    else {
        operation = command;
    }

    if (operation == "buy") {
        purchaseTicket(action, movies);
    }
    else {
        std::cout << "Invalid command." << std::endl;
    }
}

void TicketPurchase::purchaseTicket(const std::string& movieName, const std::vector<Movie>& movies) {
    std::string confirmation;
    std::cout << "Are you sure you want to purchase a ticket for " << movieName << " for $" << movies[movieName[1] - '0' - 1].getPrice() << "? (y/n): ";
    std::cin >> confirmation;
    if (confirmation == "y") {
        float ticketPrice = movies[movieName[1] - '0' - 1].getPrice(); 
        if (userBalance >= ticketPrice) {
            purchasedTickets.push_back(movieName);
            std::cout << "Ticket purchased for: " << movieName << std::endl;
            userBalance -= ticketPrice;
            std::cout << "Remaining balance: $" << userBalance << std::endl;
        }
        else {
            std::cout << "Insufficient funds to purchase the ticket." << std::endl;
        }
    }
    else {
        std::cout << "Ticket purchase canceled." << std::endl;
    }
}

void TicketPurchase::displayPurchasedTickets() {
    if (purchasedTickets.empty()) {
        std::cout << "No tickets purchased yet." << std::endl;
    }
    else {
        std::cout << "Purchased Tickets:" << std::endl;
        for (const std::string& ticket : purchasedTickets) {
            std::cout << "-" << ticket << std::endl;
        }
    }
}

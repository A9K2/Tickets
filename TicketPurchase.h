#ifndef TICKETPURCHASE_H
#define TICKETPURCHASE_H

#include <iostream>
#include <string>
#include <vector>
#include "Movie.h"

class TicketPurchase {
private:
    std::vector<std::string> purchasedTickets;
    float userBalance; 

public:
    TicketPurchase(float initialBalance);
    void processCommand(const std::string& command, const std::vector<Movie>& movies); 
    void displayPurchasedTickets();
private:
    void purchaseTicket(const std::string& movieName, const std::vector<Movie>& movies);
};

#endif 

#include "Movie.h"

void Movie::Print() const {
    std::cout << "Title: " << title << "\nDirector: " << director << "\nGenre: " << genre << "\nDuration: " << duration << " hours" << "\nPrice: $" << price << std::endl;
}

float Movie::getPrice() const {
    return price;
}

void Movie::setPrice(float newPrice) {
    price = newPrice;
}

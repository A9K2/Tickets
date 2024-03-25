#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

class Movie {
public:
    std::string title;
    std::string director;
    std::string genre;
    float duration;
    float price; 

    void Print() const; 
    float getPrice() const; 
    void setPrice(float newPrice); 
};

#endif 

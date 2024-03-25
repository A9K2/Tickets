#include "MovieSchedule.h"

void MovieSchedule::display(const std::vector<Movie>& movies) {
    if (movies.empty()) {
        std::cout << "No movies available" << std::endl;
    }
    else {
        for (const Movie& movie : movies) {
            std::cout << "- Title: " << movie.title << " | Director: " << movie.director << " | Genre: " << movie.genre << " | Duration: " << movie.duration << " hours" << std::endl;
        }
    }
}

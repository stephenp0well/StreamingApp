#include "Movies.h"

int main()
{
    Movies movie1("The Shawshank Redemption", 1994, 142.0, "Drama", "Frank Darabont");
   /* movie1.SetmovieName("The Shawshank Redemption");
    movie1.SetreleaseYear(1994);
    movie1.Setduration(142.0);
    movie1.Setgenre("Drama");
    movie1.Setdirector("Frank Darabont");
    */
    Movies movie2("The Godfather", 1972, 175.0, "Crime", "Francis Ford Coppola");
    movie1.PrintMovieInfo();
    movie2.PrintMovieInfo();
    return 0;
}
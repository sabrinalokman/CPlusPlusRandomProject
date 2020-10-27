/*
Users on longer flights like to start a second movie right when their first one ends, 
but they complain that the plane usually lands before they can see the ending. 
So you're building a feature for choosing two movies whose total runtimes will equal the exact flight length.

Write a function that takes an integer flightLength (in minutes) and a vector of integers movieLengths (in minutes) 
and returns a boolean indicating whether there are two numbers in movieLengths whose sum equals flightLength.

When building your function:

Assume your users will watch exactly two movies
Don't make your users watch the same movie twice
Optimize for runtime over memory
*/

#include <iostream>
#include <vector>
#include <unordered_set>

// C++11 lest unit testing framework
//#include "lest.hpp"
using namespace std;


bool computeTwoMovies(const std::vector<int> movieLengths, int flightLength){

	    // movie lengths we've seen so far
    unordered_set<int> movieLengthsSeen;

    for (int firstMovieLength : movieLengths) {
        int matchingSecondMovieLength = flightLength - firstMovieLength;

        if (movieLengthsSeen.find(matchingSecondMovieLength) != movieLengthsSeen.end()) {
            
            std::cout << "Yes there are two movies that you could watch!\n";
            return true;
        }
        //insert firstMovie after we check if second movie exist in seen to avoid watching movie twice
        movieLengthsSeen.insert(firstMovieLength);
    }
    std::cout << "Sorry couldn't find two, please watch just one :P \n";
    return false;

}

int main () {
    std::vector<int> length{100, 120, 130, 90, 75, 85, 95};
    int total = 195;

    computeTwoMovies(length, total);
}
	


// const lest::test tests[] = {
//     {CASE("short flight") {
//         const vector<int> movieLengths {2, 4};
//         EXPECT(computeTwoMovies(movieLengths, 1) == false);
//     }},
//     {CASE("long flight") {
//         const vector<int> movieLengths {2, 4};
//         EXPECT(computeTwoMovies(movieLengths, 6) == true);
//     }},
//     {CASE("only one movie half flight length") {
//         const vector<int> movieLengths {3, 8};
//         EXPECT(computeTwoMovies(movieLengths, 6) == false);
//     }},
//     {CASE("two movies half flight length") {
//         const vector<int> movieLengths {3, 8, 3};
//         EXPECT(computeTwoMovies(movieLengths, 6) == true);
//     }},
//     {CASE("lots of possible pairs") {
//         const vector<int> movieLengths {1, 2, 3, 4, 5, 6};
//         EXPECT(computeTwoMovies(movieLengths, 7) == true);
//     }},
//     {CASE("not using first movie") {
//         const vector<int> movieLengths {4, 3, 2};
//         EXPECT(computeTwoMovies(movieLengths, 5) == true);
//     }},
//     {CASE("only one movie") {
//         const vector<int> movieLengths {6};
//         EXPECT(computeTwoMovies(movieLengths, 6) == false);
//     }},
//     {CASE("no movies") {
//         const vector<int> movieLengths;
//         EXPECT(computeTwoMovies(movieLengths, 6) == false);
//     }}
// };

// int main(int argc, char** argv)
// {
//     return lest::run(tests, argc, argv);
// }
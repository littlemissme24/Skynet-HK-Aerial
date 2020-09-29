/* Brittney Tollison
9/27/2020
AI program used to hunt down ground enemies using a grid sector*/

#include <iostream>
#include <cstdlib>
#include <time.h>

int locationSearchGuess(int searchGridHighNumber, int searchGridLowNumber) {
    return ((searchGridHighNumber - searchGridLowNumber) / 2) + searchGridLowNumber;
}

int main()
{
    // Seed property for random number generator
    unsigned seed;

    // Create location property
    int location;

    // Start position
    int start = 1;

    // End position
    int end = 64;

    // Number of guesses
    int tryCount = 1;

    std::cout << "Generate 8x8 grid....\n";
    // Create a Grid, (not needed for this)

    std::cout << "Generate Random enemy location on 8x8 grid....\n";

    // Get the system time.
    seed = time(0);
    // Seed the random number generator.
    srand(seed);
    // Generate Random Enemy location
    location = rand() % end + 1;

    std::cout << "The enemy is located at location # " << location << " on 8x8 grid with " << start << " - " << end << " sectors.\n";
    std::cout << "Skynet HK-Aerial Initializing software.....\n";

    // Run this code until we find the enemy location
    while (start <= end) {

        std::cout << "--------------------------------------------\n";
        std::cout << "Skynet HK-Aerial Radar sending out ping #" << tryCount << "\n";

        // Guess based on values of start and end
        int search = locationSearchGuess(start, end);

        // If search is the location, we found the enemy
        if (search == location) {
            std::cout << "Enemy was hiding at location #" << location << "\n";
            std::cout << "Target was found at location #" << location << "\n";
            break;
        }
        // If search is greater than location, only guess locations less than search
        else if (search > location) {
            std::cout << "The target location prediction of " << search << " was higher than the actual enemy location of " << location << "\n";
            end = search - 1;
            std::cout << "The new searchGridHighNumber = " << end << "\n";
        }
        // Otherwise only guess locations greater than search
        else {
            std::cout << "The target location prediction of " << search << " was lower than the actual enemy location of " << location << "\n";
            start = search + 1;
            std::cout << "The new searchGridLowNumber = " << start << "\n";
        }

        // Increment tryCount
        tryCount++;
    }

    std::cout << "Skynet HK-Aerial Software took " << tryCount << " predictions to find the enemy location on a grid size of 8x8 (64)." << "\n";
}
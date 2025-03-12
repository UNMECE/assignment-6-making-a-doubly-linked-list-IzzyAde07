#include <iostream>
#include <cstdlib>
#include <ctime>
#include "coordinate.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: ./main <number_of_coordinates>\n";
        return 1;
    }

    int num_coords = atoi(argv[1]);

    srand(time(0));  // Seed for random number generation

    // Create an empty list with a dummy head node
    Coordinate *list_beginning = new Coordinate;
    list_beginning->next = nullptr;
    list_beginning->previous = nullptr;

    Coordinate *list_end = list_beginning;

    // Add random coordinates
    for (int i = 0; i < num_coords; i++) {
        float x = static_cast<float>(rand() % 100);  // Random x between 0 and 99
        float y = static_cast<float>(rand() % 100);  // Random y between 0 and 99
        add_coordinate(list_end, x, y);
        list_end = list_end->next;  // Move list_end pointer
    }

    cout << "Coordinates (forward):\n";
    forward_display(list_beginning);

    cout << "\nCoordinates (backward):\n";
    backward_display(list_end);

    // Find the closest coordinate to a given point
    float x = 50.0, y = 50.0;  // Example coordinates to find closest to
    cout << "\nFinding closest coordinate to (" << x << ", " << y << "):\n";
    closest_to(list_beginning, x, y);

    // Delete a coordinate (Example: delete coord_id 2)
    cout << "\nDeleting coordinate with ID 2:\n";
    delete_coordinate(list_beginning, 2);

    cout << "\nCoordinates after deletion:\n";
    forward_display(list_beginning);

    return 0;
}

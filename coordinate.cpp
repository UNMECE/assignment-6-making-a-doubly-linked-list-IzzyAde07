#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "coordinate.h"

using namespace std;

void add_coordinate(Coordinate *list_end, float x, float y) {
    Coordinate *new_coord = new Coordinate;
    new_coord->x = x;
    new_coord->y = y;
    new_coord->coord_id = list_length(list_end) + 1;
    new_coord->next = nullptr;
    new_coord->previous = list_end;
    
    list_end->next = new_coord;
}

void forward_display(Coordinate *list_beginning) {
    Coordinate *current = list_beginning->next;
    while (current != nullptr) {
        cout << "Coord ID: " << current->coord_id << " (" << current->x << ", " << current->y << ")\n";
        current = current->next;
    }
}

void backward_display(Coordinate *list_end) {
    Coordinate *current = list_end;
    while (current->previous != nullptr) {
        current = current->previous;
        cout << "Coord ID: " << current->coord_id << " (" << current->x << ", " << current->y << ")\n";
    }
}

void delete_coordinate(Coordinate *list_beginning, int coord_id_to_delete) {
    Coordinate *current = list_beginning->next;
    while (current != nullptr) {
        if (current->coord_id == coord_id_to_delete) {
            if (current->previous != nullptr)
                current->previous->next = current->next;
            if (current->next != nullptr)
                current->next->previous = current->previous;
            delete current;
            cout << "Coordinate ID " << coord_id_to_delete << " deleted.\n";
            return;
        }
        current = current->next;
    }
    cout << "Coordinate ID " << coord_id_to_delete << " not found.\n";
}

int list_length(Coordinate *list_beginning) {
    int length = 0;
    Coordinate *current = list_beginning->next;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

void closest_to(Coordinate *list_beginning, float x, float y) {
    Coordinate *current = list_beginning->next;
    Coordinate *closest_coord = nullptr;
    float min_distance = -1;

    while (current != nullptr) {
        float distance = sqrt(pow(current->x - x, 2) + pow(current->y - y, 2));
        if (min_distance == -1 || distance < min_distance) {
            min_distance = distance;
            closest_coord = current;
        }
        current = current->next;
    }

    if (closest_coord != nullptr) {
        cout << "Closest coordinate to (" << x << ", " << y << ") is Coord ID " << closest_coord->coord_id
             << " (" << closest_coord->x << ", " << closest_coord->y << ") with distance " << min_distance << "\n";
    }
}

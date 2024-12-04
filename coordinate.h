#ifndef COORDINATE_H
#define COORDINATE_H

#include <cmath>
#include <iostream>

struct Coordinate {
    float x;
    float y;
    int coord_id;
    Coordinate* next;
    Coordinate* previous;
};

void add_coord(Coordinate*& list_end, float x, float y);
void forward_display(Coordinate* list_beg);
void backward_display(Coordinate* list_end);
void delete_coord(Coordinate*& list_beg, int coord_id_to_delete);
int list_length(Coordinate* list_beg);
void closest_to(Coordinate* list_beg, float x, float y);

#endif 


#include "coordinate.h"
#include <limits>

static int global_id = 0;

void add_coord(Coordinate*& list_end,float x,float y){
    Coordinate* new_coord = new Coordinate{x, y, ++global_id,NULL,list_end};

    if (list_end!=NULL){
        list_end->next=new_coord;
    }
    list_end = new_coord;

    std::cout<<"Added coordinate ID"<<new_coord->coord_id<<"(x,y):("<<x<<","<<y<<")\n";
}

void forward_display(Coordinate* list_beg){
    if (list_beg==NULL){
        std::cout<<"List is empty\n";
        return;
    }

    std::cout<<"Coordinates(Forward):\n";
    for (Coordinate* current = list_beg;current!=NULL;current=current->next){
        std::cout<<"ID"<<current->coord_id<<":("<<current->x<<","<<current->y<<")\n";
    }
}

void backward_display(Coordinate* list_end){
    if (list_end==NULL){
        std::cout<<"List is empty.\n";
        return;
    }

    std::cout<<"Coordinates(Backward):\n";
    for (Coordinate*current=list_end;current!=NULL;current=current->previous){
        std::cout<<"ID"<<current->coord_id<<":("<<current->x<<","<<current->y<<")\n";
    }
}

void delete_coord(Coordinate*& list_beg,int coord_id_to_delete){
    if (list_beg==NULL){
        std::cout<<"List is empty\n";
        return;
    }

    for (Coordinate* current=list_beg;current!=NULL;current=current->next){
        if (current->coord_id==coord_id_to_delete){
            if (current->previous!=NULL){
                current->previous->next=current->next;
            } 
            else{
                list_beg=current->next;
            }

            if (current->next!=NULL){
                current->next->previous=current->previous;
            }

            std::cout<<"Deleted coordinate ID"<<coord_id_to_delete<<".\n";
            delete current;
            return;
        }
    }

    std::cout<<"Coordinate ID"<<coord_id_to_delete<<"not found.\n";
}

int list_length(Coordinate* list_beg){
    int count = 0;
    for (Coordinate* current=list_beg;current!=NULL;current=current->next){
        ++count;
    }
    return count;
}

void closest_to(Coordinate* list_beg,float x,float y){
    if (list_beg==NULL){
        std::cout<<"List is empty\n";
        return;
    }

    Coordinate* closest=NULL;
    float min_distance=std::numeric_limits<float>::max();

    for (Coordinate* current = list_beg;current!=NULL;current=current->next){
        float distance = std::sqrt((current->x-x)*(current->x-x)+(current->y-y)*(current->y-y));
        if (distance < min_distance){
            min_distance=distance;
            closest=current;
        }
    }

    if (closest != NULL){
        std::cout<<"Closest coordinate to("<<x<<","<<y<<")is ID"<<closest->coord_id<<"(x,y):("<<closest->x<<","<<closest->y<<")with distance "<<min_distance<<".\n";
    }
}


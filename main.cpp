#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include "coordinate.h"

int main(int argc, char* argv[]){
    if (argc != 2){
        std::cerr<<"Usage:"<<argv[0]<<"<number_of_coords>\n";
        return 1;
    }

    int num_coords=std::atoi(argv[1]);
    if (num_coords<=0){
        std::cerr<<"Number of coordinates must be positive\n";
        return 1;
    }

    std::srand(static_cast<unsigned>(std::time(0)));

    Coordinate* list_beg=NULL;
    Coordinate* list_end=NULL;

    for (int i=0;i<num_coords;++i) {
        float x=rand()%100;
        float y=rand()%100;
        add_coord(list_end,x,y);

        if (list_beg==NULL) {
            list_beg=list_end;
        }
    }

    forward_display(list_beg);
    backward_display(list_end);

    closest_to(list_beg, 50.0f, 50.0f);

    if (num_coords > 0) {
        delete_coord(list_beg, 1);
    }

    std::cout<<"List length:"<<list_length(list_beg)<<"\n";

    while (list_beg!=NULL){
        Coordinate* temp=list_beg;
        list_beg=list_beg->next;
        delete temp;
    }

    return 0;
}

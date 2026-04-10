#include "shape.h"
#include <stdio.h>

int main(){
    shape_handle_t shapes[]= {
        shape_create_circle(5.0),
        shape_create_rectangle(10, 3),
        shape_create_triangle(11, 18)
    };
    for(int i = 0; i< 3; i++){
        shape_print(shapes[i]);
        printf("  Area:  %.2f\n", shape_area(shapes[i]));
        printf("  Perimeter: %.2f\n", shape_perimeter(shapes[i]));
        printf("\n");
    }
    
    //cleanup
    for(int i =0;i<3;i++){
        shape_destroy(shapes[i]);
    }

    return 0;
}
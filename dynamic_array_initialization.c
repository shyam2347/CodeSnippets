//
// Author: shyam2347@gmail.com
// Date: August 13, 2014
//
// This program gives a sample program where you can dynamically decide and create an array size.
// Here we have an array of pointers 'pt'. It is not given a size during creation, but I do malloc 
// inside formTriangle to create new array entries dynamically.
// This approach would be useful when you want to dynamically decide the array size and still have
// pointers stored in contiguous memory.
// For example, I can have another method called formRectangle in this file and dynamically decide
// during runtime if I want to form a triangle or rectangle and the program is expected to work sane.
//
// This C feature is known as flexible array member.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct point
{
    int x;  
    int y;  
};

typedef struct point point_t;

struct polygon 
{
    int num_points;
    point_t *pt[];  // can also be written as point_t pt[];
};
typedef struct polygon polygon_t;

void formTriangle(polygon_t *ptr)
{
    ptr->num_points = 3;
    ptr->pt[0] = (point_t *) malloc(sizeof(point_t));
    ptr->pt[0]->x = 0; // s/]->/]./
    ptr->pt[0]->y = 0; // s/]->/]./

    ptr->pt[1] = (point_t *) malloc(sizeof(point_t));
    ptr->pt[1]->x = 4; // s/]->/]./
    ptr->pt[1]->y = 0; // s/]->/]./

    ptr->pt[2] = (point_t *) malloc(sizeof(point_t));
    ptr->pt[2]->x = 0; // s/]->/]./
    ptr->pt[2]->y = 3; // s/]->/]./
}

int main()
{
    int i;  
    polygon_t *ptr = (polygon_t *) malloc(sizeof(polygon_t));
    memset(ptr, 0, sizeof(polygon_t));

    formTriangle(ptr);
    printf("Print triangle co-ordinates\n");
    for (i = 0; i < ptr->num_points; i++)
    {
        printf("Point %d: ", i);
        printf("X = %d, ", ptr->pt[i]->x); // s/]->/]./
        printf("Y = %d\n", ptr->pt[i]->y); // s/]->/]./
    }
    return 0;
}

#include <stdio.h>
#include "shapes.h"

static void try_stack(void) {
    struct Triangle triangle;
    Triangle_construct(&triangle, 1, 2);
    Triangle_get_type(&triangle);
    Triangle_destruct(&triangle);
}

static void try_heap(void) {
    struct Shape *shape;
    shape = (struct Shape *) Rectangle_new(1, 2);
    shape->vptr->get_area(shape);
    Shape_delete(shape);
}

int main() {
    try_stack();
    printf("\n");
    try_heap();

    return 0;
}

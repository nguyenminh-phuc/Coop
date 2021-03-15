#ifndef COOP_SHAPES_H
#define COOP_SHAPES_H

struct Shape;

struct IShape {
    void (*destruct)(struct Shape *self);

    const char *(*get_type)(const struct Shape *self);

    int (*get_area)(const struct Shape *self);
};

struct Shape {
    const struct IShape *vptr;
    int a;
    int b;
};

struct Rectangle {
    struct Shape base;
};

struct Triangle {
    struct Shape base;
};

void Shape_construct(struct Shape *self, int a, int b);

void Rectangle_construct(struct Rectangle *self, int a, int b);

void Triangle_construct(struct Triangle *self, int a, int b);

void Shape_destruct(struct Shape *self);

void Rectangle_destruct(struct Rectangle *self);

void Triangle_destruct(struct Triangle *self);

struct Shape *Shape_new(int a, int b);

struct Rectangle *Rectangle_new(int a, int b);

struct Triangle *Triangle_new(int a, int b);

void Shape_delete(struct Shape *self);

const char *Shape_get_type(const struct Shape *self);

const char *Rectangle_get_type(const struct Rectangle *self);

const char *Triangle_get_type(const struct Triangle *self);

int Rectangle_get_area(const struct Rectangle *self);

int Triangle_get_area(const struct Triangle *self);

#endif

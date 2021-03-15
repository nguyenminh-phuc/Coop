#include "shapes.h"
#include <stdlib.h>
#include <stdio.h>

static const char *Shape_get_type(const struct Shape *self) {
    printf("Shape_get_type\n");
    return "shape";
}

static const char *Rectangle_get_type(const struct Rectangle *self) {
    printf("Rectangle_get_type\n");
    return "rectangle";
}

static const char *Triangle_get_type(const struct Triangle *self) {
    printf("Triangle_get_type\n");
    return "triangle";
}

static int Rectangle_get_area(const struct Rectangle *self) {
    printf("Rectangle_get_area\n");
    return self->base.a * self->base.b;
}

static int Triangle_get_area(const struct Triangle *self) {
    printf("Triangle_get_area\n");
    return (self->base.a * self->base.b) / 2;
}

static const struct IShape Shape_IShape = {
        .destruct = Shape_destruct,
        .get_type = Shape_get_type,
        .get_area = NULL
};

static const struct IShape Rectangle_IShape = {
        .destruct = (void (*)(struct Shape *)) Rectangle_destruct,
        .get_type = (const char *(*)(const struct Shape *)) Rectangle_get_type,
        .get_area = (int (*)(const struct Shape *)) Rectangle_get_area
};

static const struct IShape Triangle_IShape = {
        .destruct = (void (*)(struct Shape *)) Triangle_destruct,
        .get_type = (const char *(*)(const struct Shape *)) Triangle_get_type,
        .get_area = (int (*)(const struct Shape *)) Triangle_get_area
};

void Shape_construct(struct Shape *self, int a, int b) {
    printf("Shape_construct\n");
    self->vptr = &Shape_IShape;
    self->a = a;
    self->b = b;
}

void Rectangle_construct(struct Rectangle *self, int a, int b) {
    printf("Rectangle_construct\n");
    Shape_construct(&self->base, a, b);
    self->base.vptr = &Rectangle_IShape;
}

void Triangle_construct(struct Triangle *self, int a, int b) {
    printf("Triangle_construct\n");
    Shape_construct(&self->base, a, b);
    self->base.vptr = &Triangle_IShape;
}

void Shape_destruct(struct Shape *self) {
    printf("Shape_destruct\n");
    self->vptr = &Shape_IShape;
}

void Rectangle_destruct(struct Rectangle *self) {
    printf("Rectangle_destruct\n");
    self->base.vptr = &Rectangle_IShape;
    Shape_destruct(&self->base);
}

void Triangle_destruct(struct Triangle *self) {
    printf("Triangle_destruct\n");
    self->base.vptr = &Triangle_IShape;
    Shape_destruct(&self->base);
}

struct Shape *Shape_new(int a, int b) {
    printf("Shape_new\n");
    struct Shape *instance = malloc(sizeof(struct Shape));
    if (!instance) return NULL;

    Shape_construct(instance, a, b);
    return instance;
}

struct Rectangle *Rectangle_new(int a, int b) {
    printf("Rectangle_new\n");
    struct Rectangle *instance = malloc(sizeof(struct Rectangle));
    if (!instance) return NULL;

    Rectangle_construct(instance, a, b);
    return instance;
}

struct Triangle *Triangle_new(int a, int b) {
    printf("Triangle_new\n");
    struct Triangle *instance = malloc(sizeof(struct Triangle));
    if (!instance) return NULL;

    Triangle_construct(instance, a, b);
    return instance;
}

void Shape_delete(struct Shape *self) {
    printf("Shape_delete\n");
    if (!self) return;

    self->vptr->destruct(self);
    free(self);
}

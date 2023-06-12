#include <stdlib.h>
#include <math.h>

#include "vector.h"

/*
* implementation of the Vector API
*/

vector* vector_new(double x, double y, double z) {
    vector* u = (vector*) malloc(sizeof(vector));
    u->x = x;
    u->y = y;
    u->z = z;
    return u;
}

vector* vector_add(vector* u, vector* v){
    return vector_new(u->x + v->x, u->y + v->y, u->z + v->z);

}

vector* vector_sub(vector* u, vector* v){
        return vector_new(u->x - v->x, u->y - v->y, u->z - v->z);
}

vector* vector_scale(double a, vector* u){
    return vector_new(a*(u->x), a*(u->y), a*(u->z));
}

vector* vector_vprod(vector* u, vector* v){
    return vector_new((u->y)*(v->z)-(v->y)*(u->z),(u->z)*(v->x)-(u->x)*(v->z),(u->x)*(v->y)-(u->y)*(v->x));
}

double vector_sprod(vector* u, vector* v){
    return (u->x)*(v->x) + (u->y)*(v->y) + (u->z)*(v->z);
}

double vector_mod(vector* u){
    return sqrt((u->x)*(u->x) + (u->y)*(u->y) + (u->z)*(u->z));    
}




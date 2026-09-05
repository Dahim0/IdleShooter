#include "DahimQol.h"
#include <cmath>

int randi(int from,int to){
    return (rand() % (to - from + 1))+from;
}

Vector2 normalized(Vector2 vector){
    float l = sqrt(vector.x*vector.x + vector.y*vector.y);
    Vector2 t = {0,0};
    t.x = vector.x / l;
    t.y = vector.y / l;
    return t;
}

Vector2 add_v2(Vector2 vec1, Vector2 vec2){
    Vector2 t; 
    t.x = vec1.x + vec2.x;
    t.y = vec1.y + vec2.y;
    return t;
}
Vector2 sub_v2(Vector2 vec1, Vector2 vec2){
    Vector2 t; 
    t.x = vec1.x - vec2.x;
    t.y = vec1.y - vec2.y;
    return t;
}
Vector2 mult_v2(Vector2 vec1, float mult){
    Vector2 t; 
    t.x = vec1.x * mult;
    t.y = vec1.y * mult;
    return t;
}
Vector2 division_v2(Vector2 vec1, float div){
    Vector2 t; 
    t.x = vec1.x / div;
    t.y = vec1.y / div;
    return t;
}
float distance_v2(Vector2 vec1, Vector2 vec2){
    float dx = vec1.x - vec2.x;
    float dy = vec1.y - vec2.y;
    return sqrt(dx*dx + dy*dy);
}

float lerp(float a, float b, float t)
{
    return a + t * (b - a);
}


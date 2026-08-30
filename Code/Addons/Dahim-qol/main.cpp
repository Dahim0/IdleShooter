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
float lerp(float a, float b, float t)
{
    return a + t * (b - a);
}
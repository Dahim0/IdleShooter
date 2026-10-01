#include <cstdlib>
#include "raylib.h"
#include <cmath>

/// @brief Return a random number from an inteager to another inteager
inline int randi(int from,int to){
    return (rand() % (to - from + 1))+from;
}
/// @brief Return a vector2 if it was normalized
inline Vector2 normalized(Vector2 vector){
    float l = sqrt(vector.x*vector.x + vector.y*vector.y);
    Vector2 t = {0,0};
    t.x = vector.x / l;
    t.y = vector.y / l;
    return t;
}
/// @brief Return a vector2 if it was added with another vector2
inline Vector2 add_v2(Vector2 vec1, Vector2 vec2){
    Vector2 t; 
    t.x = vec1.x + vec2.x;
    t.y = vec1.y + vec2.y;
    return t;
}
/// @brief Return a vector2 if it was substracted with another vector2
inline Vector2 sub_v2(Vector2 vec1, Vector2 vec2){
    Vector2 t; 
    t.x = vec1.x - vec2.x;
    t.y = vec1.y - vec2.y;
    return t;
}
/// @brief Return a vector2 if it was multiplued with a float
inline Vector2 mult_v2(Vector2 vec1, float mult){
    Vector2 t; 
    t.x = vec1.x * mult;
    t.y = vec1.y * mult;
    return t;
}
/// @brief Return a vector2 if it was divided with a float
inline Vector2 division_v2(Vector2 vec1, float div){
    Vector2 t; 
    t.x = vec1.x / div;
    t.y = vec1.y / div;
    return t;
}
/// @brief Return the distance between 2 Vector2
inline float distance_v2(Vector2 vec1, Vector2 vec2){
    float dx = vec1.x - vec2.x;
    float dy = vec1.y - vec2.y;
    return sqrt(dx*dx + dy*dy);
}
/// @brief Return a number that is between a & b using t as a middle;
inline float lerp(float a, float b, float t)
{
    return a + t * (b - a);
}

// Timer section, all credit to : https://www.youtube.com/@GameDevTutorialsYT

/// @brief Timer with a certain life time
typedef struct{
    float LifeTime;
    bool JustDone;
}Timer;
/// @brief Start or restart a timer in x seconds
inline void StartTimer(Timer* timer,float LifeTime){
    if(timer != NULL){
        timer->LifeTime= LifeTime;
        timer->JustDone= false;
    }
}
/// @brief Update specefied timer so it can runs out
inline void UpdateTimer(Timer* timer){
    timer->JustDone=false;

    if(timer != NULL && timer->LifeTime > 0){
        if(timer->LifeTime - GetFrameTime() <= 0){
            timer->JustDone=true;
        }
        timer->LifeTime-= GetFrameTime();
    }

}
/// @brief Return true if timer LifeTime is equal or smaller to zero
inline bool IsTimerDone(Timer* timer){
    if (timer != NULL){
        return timer->LifeTime <= 0;
    }
    else{
        return false;
    }
}
/// @brief Return true if timer Hit 0 this frame
inline bool IsTimerJustDone(Timer* timer){
    if (timer != NULL){
        return timer->JustDone;
    }
    else{
        return false;
    }
}
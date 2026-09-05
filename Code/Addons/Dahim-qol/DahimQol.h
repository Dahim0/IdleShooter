#include <cstdlib>
#include "raylib.h"

/// @brief Return a random number from an inteager to another inteager
int randi(int from,int to);
/// @brief Return a vector2 if it was normalized
Vector2 normalized(Vector2 vector);
/// @brief Return a vector2 if it was added with another vector2
Vector2 add_v2(Vector2 vec1, Vector2 vec2);
/// @brief Return a vector2 if it was substracted with another vector2
Vector2 sub_v2(Vector2 vec1, Vector2 vec2);
/// @brief Return a vector2 if it was multiplued with a float
Vector2 mult_v2(Vector2 vec1, float mult);
/// @brief Return a vector2 if it was divided with a float
Vector2 division_v2(Vector2 vec1, float mult);
/// @brief Return the distance between 2 Vector2
float distance_v2(Vector2 vec1, Vector2 vec2);
/// @brief Return a number that is between a & b using t as a middle;
float lerp(float a, float b, float t);

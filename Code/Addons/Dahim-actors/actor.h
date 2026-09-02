#include "raylib.h"
#include <iostream>
using namespace std;


/// @brief An actor class with velocity position sprite and rotation
class actor{
    public:
        int rotation;
        int hp;
        Vector2 pos;
        Vector2 vel;
        string path;

        float width;
        float height;
        float scale= 1.0f;

        /// @brief Add the actor velocity to its position
        void move();
        /// @brief Draws the acotr using its path texture and its position
        void draw();
        actor();
        /// @brief 
        /// @param pos 2D position ex: {0,0}
        /// @param vel 2D velocity ex: {1,0}
        /// @param rotation Rotation in degrees
        /// @param HP Actor Health
        /// @param Scale Multiply the actor scale
        /// @param path Path to the sprite ex: "Assets/player.png"
        actor( Vector2 POS, Vector2 VEL,int ROTATION,int HP, std::string TEXTURE_PATH);
};
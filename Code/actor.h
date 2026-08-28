#include "raylib.h"
#include <iostream>

class actor{
    public:
        int rotation;
        Vector2 pos;
        Vector2 vel;
        std::string path;

        void move();
        void draw();
        actor( Vector2 POS, Vector2 VEL,int ROTATION, std::string TEXTURE_PATH);
};
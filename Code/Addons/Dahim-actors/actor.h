#include "raylib.h"
#include <iostream>
using namespace std;


//actor
class actor{
    public:
        int rotation;
        Vector2 pos;
        Vector2 vel;
        string path;

        void move();
        void draw();
        actor();
        actor( Vector2 POS, Vector2 VEL,int ROTATION, std::string TEXTURE_PATH);
};
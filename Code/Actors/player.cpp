#include "Code/General.h"

/* #region bullets var*/
vector<actor> bullets;
float b_cooldown = 0.1f * target_fps;
float b_size = 1.0f;
float b_dmg = 1.0f;
float b_speed = 15.0f;
float b_time_left = b_cooldown;
/* #endregion */


void shoot()
{
    Vector2 target_pos;
    target_pos.x = normalized(GetMousePosition()).x + player.pos.x;
    target_pos.y = normalized(GetMousePosition()).y + player.pos.y;
    Vector2 target_vel;
    target_vel = normalized(sub_v2(GetMousePosition(), player.pos));

    bullets.push_back(actor(target_pos, mult_v2(target_vel, b_speed), 0, 1, "Assets/bullet.png"));
}

actor player({400, 250}, {0, 0}, 0, 1, "Assets/player.png");

void player_update()
{
    /* #region bullets */
    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i].move();
        bullets[i].scale = b_size;

        if (distance_v2(bullets[i].pos, player.pos) > 1000)
        {
            bullets.erase(bullets.begin() + i); // weird but work
        }
        for (int u = 0; u < enemies.size(); u++)
        { // enemies
            if (distance_v2(bullets[i].pos, enemies[u].pos) < (bullets[i].width + enemies[u].width) / 2)
            {
                try{
                enemies[u].damage(b_dmg, u, i);
                bullets.erase(bullets.begin() + i);
                }
                catch (const char* msg) {
                cout << "Error: " << msg; 
                } 
            }
        }
    }

    if (b_time_left > 0.0f){
    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        b_time_left -= 1;
    }
    }
    else if (b_time_left <= 0)
    {
        b_time_left = b_cooldown;
        shoot();
    }
    /* #endregion */

    // look at the mosue
    player.rotation = atan2(
    -(GetMousePosition().x - player.pos.x),
    GetMousePosition().y - player.pos.y) *
    (180 / M_PI);
}

void player_draw()
{
    for (actor &i : bullets)
    {
        i.draw();
    }
    player.draw();
}
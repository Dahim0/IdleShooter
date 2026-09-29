#include "Code/General.h"

/* #region bullets var*/
vector<actor> bullets;
float b_cooldown = 0.1f;
float b_size = 1.0f;
float b_dmg = 1.0f;
float b_speed = 15.0f;
Timer b_time_left = {b_cooldown};
/* #endregion */


void shoot()
{
    actor PUPPET;
    PUPPET.pos.x = normalized(GetMousePosition()).x + player.pos.x;
    PUPPET.pos.y = normalized(GetMousePosition()).y + player.pos.y;
    PUPPET.vel = mult_v2(normalized(sub_v2(GetMousePosition(), player.pos)),b_speed);
    PUPPET.scale = b_size;
    PUPPET.path = "Assets/bullet.png";

    bullets.push_back(PUPPET);
}

actor player({400, 250}, {0, 0}, 0, 1, "Assets/player.png");

void player_update()
{
    /* #region bullets */
    for (int i = 0; i < bullets.size(); i++)
    {

        bullets[i].move();
        //bullet-proof remover (pun's inteded)
        bullets.erase(
            remove_if(bullets.begin(), bullets.end(), [](const actor& e) {
                return (distance_v2(e.pos,player.pos)) > 1000;
            }),
            bullets.end()
        );

        for (int u = 0; u < enemies.size(); u++)
        {
            
            //skips dying enemies
            if(enemies[u].die_anim > 0){
                continue;
            }
            if (distance_v2(bullets[i].pos, enemies[u].pos) < (bullets[i].width + enemies[u].width) / 2)
            {
                enemies[u].damage(b_dmg, u, i);
                bullets[i].pos = {50000,0}; // moving them out of bound so they get deleted safly
            }


        }

    }


    UpdateTimer(&b_time_left);
    if(IsTimerDone(&b_time_left)&&IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        StartTimer(&b_time_left,b_cooldown);
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
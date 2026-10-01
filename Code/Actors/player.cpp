#include "Code/General.h"

/* #region Bullets var*/
vector<actor> Bullets;
float SpawnBulletCooldown = 0.1f;//seconds
float BulletSize = 1.0f;
float BulletDmg = 1.0f;
float BulletSpd = 15.0f;
Timer SpawnBulletTimer = {SpawnBulletCooldown};
/* #endregion */


void shoot()
{
    actor PUPPET;
    PUPPET.pos.x = normalized(GetMousePosition()).x + player.pos.x;
    PUPPET.pos.y = normalized(GetMousePosition()).y + player.pos.y;
    PUPPET.vel = mult_v2(normalized(sub_v2(GetMousePosition(), player.pos)),BulletSpd);
    PUPPET.scale = BulletSize;
    PUPPET.path = "Assets/bullet.png";

    Bullets.push_back(PUPPET);
}

actor player({400, 250}, {0, 0}, 0, 1, "Assets/player.png");

void player_update()
{
    /* #region Bullets */
    for (int i = 0; i < Bullets.size(); i++)
    {

        Bullets[i].move();
        //bullet-proof remover (pun's inteded)
        Bullets.erase(
            remove_if(Bullets.begin(), Bullets.end(), [](const actor& e) {
                return (distance_v2(e.pos,player.pos)) > 1000;
            }),
            Bullets.end()
        );

        for (int u = 0; u < enemies.size(); u++)
        {
            
            //skips dying enemies
            if(enemies[u].die_anim.LifeTime > 0){
                continue;
            }
            if (distance_v2(Bullets[i].pos, enemies[u].pos) < (Bullets[i].width + enemies[u].width) / 2)
            {
                enemies[u].damage(BulletDmg, u, i);
                Bullets[i].pos = {50000,0}; // moving them out of bound so they get deleted safly
            }


        }

    }


    UpdateTimer(&SpawnBulletTimer);
    if(IsTimerDone(&SpawnBulletTimer)&&IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        StartTimer(&SpawnBulletTimer,SpawnBulletCooldown);
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
    for (actor &i : Bullets)
    {
        i.draw();
    }
    player.draw();
}
#include "Code/General.h"

vector<enemie> enemies;

float SpawnEnemieCooldown = 1;//seconds
Timer SpawnEnemieTimer = {SpawnEnemieCooldown};


float speed = 0.0001f;
float friction = 1.1f;
int KnockBack = 2;
int diffuclty = 1;

enum ColorHp{
  white = 5,
  green = 10,
  blue = 20,
  violet = 50,
  orange = 100,
};
ColorHp CurrentColor = white;


int current_id = 0;



/* #region  Custom Enemie Class */

//give out the index of the object in the enemies vector via the object id
int GetIndexFromId(int id) {
    for (size_t /*size t is like int*/ i = 0; i < enemies.size(); i++) {
        if (enemies[i].id == id) {
            return static_cast<int>(i);
        }
    }

    return -1; // Return -1 for "not found" instead of NAN
}
//no paramterer consturcter
enemie::enemie()
{
    rotation = 0;
    hp = 1;
    pos = {0, 0};
    vel = {0, 0};
    path = "Assets/enemies.png";
    modulate = WHITE;
    money_drop = 1;
    scale = 1.0;
}

//when enemie take damage
void enemie::damage(float dmg, int v_index, int a_index)
{
    StartTimer(&hit_anim,0.1f);

    draw(); // needed to smooth out things

    vel = mult_v2(normalized(Bullets[a_index].vel),KnockBack);


    hp -= dmg;
    if (hp <= 0)
    {
        money += money_drop;
        StartTimer(&die_anim,1.0f);
    }

    
}
// remove enemies if too small
void clean_up()
{
    enemies.erase(
        remove_if(enemies.begin(), enemies.end(), [](const enemie& e) {
            
            return e.die_anim.JustDone; //cant use the IsTimerJustDone() bcs cpp dum.
        }),
        enemies.end()
    );
}
// plays different effect for enemies
void enemie::animate()
{
    UpdateTimer(&hit_anim);
    UpdateTimer(&die_anim);

    if (hit_anim.LifeTime > 0)
    {
        //Make enemie redder when hit
        target_color = lerp(target_color,{255,0,0,255},0.4);
    }
    else
    {
        //Make enemie white when hit
        target_color = lerp(target_color,diff_color,0.1);
    }

    if(!IsTimerDone(&die_anim)){
        //make enemie grey when dying
        target_color = lerp(target_color,{0,0,0,0},0.1);
    }
    modulate = target_color;
}

/* #endregion */

void spawn_enemie()
{
    enemie PUPPET;

    switch (CurrentColor)
    {
    case white:
        PUPPET.diff_color = WHITE;
        break;
    case green:
        PUPPET.diff_color = GREEN;
        break;
    case blue:
        PUPPET.diff_color = BLUE;
        break;
    case violet:
        PUPPET.diff_color = PURPLE;
        break;
    case orange:
        PUPPET.diff_color = ORANGE;
        break;
    }
    // 250 000 000 (i dont think anyone will ever have this many enemies,if so they deserve for the game to crash)
    if(current_id > 250000000){
        current_id = 0;
    }
    current_id ++;
    PUPPET.id = current_id;
    // We make the enemie appear around the player in the circumrence of a circle with a radius of 500
    PUPPET.pos = add_v2(player.pos,mult_v2(DegToVec(randi(0,360)),500));
    PUPPET.hp = CurrentColor * diffuclty;
    PUPPET.money_drop = PUPPET.hp;
    PUPPET.path = "Assets/enemies.png";
    enemies.push_back(PUPPET);
}

void enemies_update()
{
    UpdateTimer(&SpawnEnemieTimer);
    if (IsTimerDone(&SpawnEnemieTimer))
    {
        spawn_enemie();
        StartTimer(&SpawnEnemieTimer,SpawnEnemieCooldown);
    }

    for (enemie &i : enemies)
    {
        i.move();

        //stop dead enemies from updating
        if(i.die_anim.LifeTime > 0){
            continue;
        }
        //move enemies toward player

        i.vel.x += sub_v2(player.pos,i.pos).x*speed;
        i.vel.y += sub_v2(player.pos,i.pos).y*speed;

        i.vel.x /= friction;
        i.vel.y /= friction;

        
    }

    clean_up();
}

void enemies_draw()
{
    
    for (enemie &i : enemies)
    {
        
        i.draw();
        i.animate();

        /*
        in case you want to debug the id of the enemie
        DrawText(TextFormat("%d", i.id), i.pos.x, i.pos.y, 30, YELLOW)
        */
    }
}

#include "Code/General.h"

vector<enemie> enemies;

float SpawnEnemieCooldown = 1;//seconds
Timer SpawnEnemieTimer = {SpawnEnemieCooldown,false};

float diffuclty = 1.0f;
float speed = 0.001f;

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
    if(IsTimerDone(&hit_anim)){
        StartTimer(&hit_anim,0.1f);

        animate();
        draw();
        pos = add_v2(pos, mult_v2(normalized(Bullets[a_index].vel),5.0f));
        hp -= dmg;
        if (hp <= 0)
        {
            money += money_drop;
            StartTimer(&die_anim,1.0f);
        }
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
        target_color.b = lerp(target_color.b,0,0.4);
        target_color.g = lerp(target_color.g,0,0.4);
        modulate = target_color;
    }
    else
    {
        //Make enemie white when hit
        target_color.b = lerp(target_color.b,255,0.1);
        target_color.g = lerp(target_color.g,255,0.1);
        modulate = target_color;
    }

    if(!IsTimerDone(&die_anim)){
        //make enemie grey when dying
        target_color.a = lerp(target_color.a,0,0.1);
        modulate = target_color;
    }
    
}

/* #endregion */

void spawn_enemie(float diffuclty)
{
    enemie PUPPET;
    int StartingDirection = randi(1, 4);
    switch (StartingDirection)
    {
    case 1:
        // left
        PUPPET.pos = {-50, (float)randi(0, 800)};
        break;
    case 2:
        // up
        PUPPET.pos = {(float)randi(0, 400), -50};
        break;
    case 3:
        // right
        PUPPET.pos = {850, (float)randi(0, 800)};
        break;
    case 4:
        // down
        PUPPET.pos = {(float)randi(0, 400), 550};
        break;
    }

    // 250 000 000 (i dont think anyone will ever have this many enemies,if so they deserve for the game to crash)
    if(current_id > 250000000){
        current_id = 0;
    }
    current_id ++;

    PUPPET.id = current_id;
    PUPPET.hp = 5;
    PUPPET.money_drop = 5;
    PUPPET.path = "Assets/enemies.png";
    enemies.push_back(PUPPET);
}

void enemies_update()
{
    UpdateTimer(&SpawnEnemieTimer);
    if (IsTimerDone(&SpawnEnemieTimer))
    {
        spawn_enemie(diffuclty);
        StartTimer(&SpawnEnemieTimer,SpawnEnemieCooldown);
    }

    for (enemie &i : enemies)
    {
        //stop dead enemies from moving
        if(i.die_anim.LifeTime > 0){
            continue;
        }
        //move enemies toward player
        i.pos.x = lerp(i.pos.x, player.pos.x, speed);
        i.pos.y = lerp(i.pos.y, player.pos.y, speed);
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

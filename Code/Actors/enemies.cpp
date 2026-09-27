#include "Code/General.h"

vector<enemie> enemies;

float timer = 3 * target_fps;
float time_left = timer;

float diffuclty = 1.0f;
float speed = 0.001f;

int current_id = 0;

/* #region  Custom Enemie Class */
int GetIndexFromId(int id) {
    for (size_t i = 0; i < enemies.size(); i++) {
        if (enemies[i].id == id) {
            return static_cast<int>(i);
        }
    }
    return -1; // Return -1 for "not found" instead of NAN (NAN is for floating-point numbers)
}


enemie::enemie()
{
    rotation = 0;
    hp = 1;
    pos = {0, 0};
    vel = {0, 0};
    path = "Assets/enemies.png";
    modulate = WHITE;
    money = 0;
    scale = 1.0;
}
enemie::enemie(Vector2 POS, Vector2 VEL, int HP, int MONEY, float SCALE, std::string TEXTURE_PATH, Color MODULATE)
{
    scale = SCALE;
    pos = POS;
    vel = VEL;
    path = TEXTURE_PATH;
    hp = HP;
    money = MONEY;
    modulate = MODULATE;
}
void enemie::damage(float dmg, int v_index, int a_index)
{
    if(die_anim == 0.0f){
    hit_anim = 0.1f * target_fps;
    animate();
    draw();
    pos = add_v2(pos, mult_v2(normalized(bullets[a_index].vel),5.0f));
    hp -= dmg;
    if (hp <= 0)
    {
        die_anim = 1.0f;
    }
    }
}
// remove enemies if too small
void clean_up()
{
    enemies.erase(
        remove_if(enemies.begin(), enemies.end(), [](const enemie& e) {
            return (e.scale) < 0.01f;
        }),
        enemies.end()
    );
}
// plays different effect for enemies
void enemie::animate()
{
    if (hit_anim > 0.0f)
    {
        hit_anim--;
        target_color.b = lerp(target_color.b,0,0.7);
        target_color.g = lerp(target_color.g,0,0.7);
        modulate = target_color;
    }
    else
    {
        target_color.b = lerp(target_color.b,255,0.1);
        target_color.g = lerp(target_color.g,255,0.1);
        modulate = target_color;
    }
    if(die_anim > 0.0f){
        scale = lerp(scale,0.0f,0.2);
    }
    
}

/* #endregion */

void spawn_enemie(float diffuclty)
{
    int starting_direction = randi(1, 4);
    Vector2 starting_pos;
    switch (starting_direction)
    {
    case 1:
        // left
        starting_pos = {-50, (float)randi(0, 800)};
        break;
    case 2:
        // up
        starting_pos = {(float)randi(0, 400), -50};
        break;
    case 3:
        // right
        starting_pos = {850, (float)randi(0, 800)};
        break;
    case 4:
        // down
        starting_pos = {(float)randi(0, 400), 550};
        break;
    }

    // 250 000 000 (i dont think anyone will ever have this many enemies,if so they deserve it)
    if(current_id > 250000000){
        current_id = 0;
    }
    current_id ++;
    enemie PUPPET(starting_pos, {0, 0}, /*hp*/ 5, /*money*/ 0, /*scale*/ 1.0f, "Assets/enemies.png", WHITE);
    PUPPET.id = current_id;
    PUPPET.pos = starting_pos;
    PUPPET.hp = 5;
    PUPPET.money = 1;
    PUPPET.path = "Assets/enemies.png";
    enemies.push_back(PUPPET);
}

void enemies_update()
{
    if (time_left > 0.0f)
    {
        time_left -= 1;
    }
    else if (time_left <= 0)
    {
        spawn_enemie(diffuclty);
        time_left = timer;
    }
    for (enemie &i : enemies)
    {
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

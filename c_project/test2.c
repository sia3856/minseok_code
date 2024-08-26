void iterface(int map[][50][50], int xlen, int ylen, int zlen, int *x, int *y, int *p_loc,  int bag[bag_z][bag_y][bag_x],Player *player,int *s_loc_x, int *s_loc_y,int *s_loc_z,Item *item);

iterface(map, x_len, y_len, z_len, &loc_x, &loc_y, &present_loc, bag, &player, &s_loc_x, &s_loc_y, &s_loc_z, &item);

void iterface(int map[][50][50], int xlen, int ylen, int zlen, int *x, int *y, int *p_loc,  int bag[bag_z][bag_y][bag_x],Player *player,int *s_loc_x, int *s_loc_y,int *s_loc_z,Item *item)
{
    printf("═════════════════════════════════════════════════════════════════════════════════════════\n");
    enter(9);
    printf("          이름 : %s"\t\t\t레벨 : %d", player->name,player->level);
    sleep(10);










}char name[20];struct player
{
    char name[20];
    int level;
    double max_hp;
    double hp;
    int max_mp;
    int mp;
    double dmg;
    double defence;
    int max_xp;
    int xp;
    int gold;
    int t_portal;
    struct p_skill skill_list[6];
    double e_dmg;
};


struct p_skill
{
    char name[50];
    int cnum;
    double min_dmg;
    double max_dmg;
    int mp;
    double min_recovery;
    double max_recovery;
    int level_limit;
};

struct w_inf
{
    char name[20];
    double dmg;
};
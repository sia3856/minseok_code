else if (select == 52)
    {
        system("clear");
        enter(10);
        if((player->mp)+150 < player->max_mp && item->mpot_4 > 0)
        {
            player->mp = player->max_mp;
            printf("체력 + 150\n");
            item->mpot_4 -= 1;
        }
        else if(player->mp < player->max_mp && item->mpot_4 > 0)
        {
            player->mp += 150;
            printf("체력 + 150\n");
            item->mpot_4 -= 1;
        }
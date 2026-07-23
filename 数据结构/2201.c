void player_level_up(User *user)
{
    if (!user) return;
    
    user->level++;
    user->skill_points++;
    
    /* 属性成长 */
    float *growth = (float *)CLASS_GROWTH[user->class_id];
    user->strength += (int)growth[0];
    user->physique += (int)growth[1];
    user->endurance += (int)growth[2];
    user->agility += (int)growth[3];
    user->intelligence += (int)growth[4];
    
    /* 重新计算战斗属性 */
    player_calc_battle_stats(user);
    
    /* 升级恢复满血满蓝 */
    user->hp = user->max_hp;
    user->mp = user->max_mp;
    
    LOGI("升级! %s 达到 %d 级", user->username, user->level);
    printf("\n*** 恭喜! %s 升到了 %d 级! ***\n", user->username, user->level);
    printf("  气血上限: %d  法力上限: %d\n", user->max_hp, user->max_mp);
    printf("  攻击: %d  防御: %d  速度: %d\n", user->attack, user->defense, user->speed);
}
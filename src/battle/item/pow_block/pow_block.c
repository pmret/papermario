#include "pow_block.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = (const) ITEM_P_O_W_BLOCK;
    await N(UseItemWithEffect);
    sleep 10;
    MakeEntity(0x802EA2E0, -40, 60, 0, 0, MAKE_ENTITY_END);
    SI_VAR(10) = SI_VAR(0);
    N(func_802A1318_718B68)();
    PlayEffect(0x7, 2, -40, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, -30, 65, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, -40, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, -40, 55, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    sleep 20;
    UseBattleCamPreset(2);
    MoveBattleCamOver(20);
    spawn {
        sleep 15;
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_HIT_BLOCK);
        N(func_802A123C_718A8C)();
        PlayEffect(0x7, 2, -40, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        PlayEffect(0x7, 2, -30, 65, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        PlayEffect(0x7, 2, -40, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        PlayEffect(0x7, 2, -40, 55, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        StartRumble(4);
        ShakeCam(1, 0, 2, 1.0);
        ShakeCam(1, 0, 2, 3.0);
        ShakeCam(1, 0, 2, 6.0);
        ShakeCam(1, 0, 2, 5.0);
        ShakeCam(1, 0, 2, 4.0);
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_2030);
        ShakeCam(1, 0, 2, 3.0);
        ShakeCam(1, 0, 2, 2.0);
        ShakeCam(1, 0, 2, 1.0);
        ShakeCam(1, 0, 2, 0.5);
        ShakeCam(1, 0, 2, 0.2001953125);
    }
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 30;
    SetActorSpeed(ACTOR_PLAYER, 4.0);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_RUNNING);
    SetGoalPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    PlayerRunToGoal(ACTOR_PLAYER);
    sleep 5;
    SetJumpAnimations(ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_10009);
    SetActorJumpGravity(ACTOR_PLAYER, 0.6005859375);
    SetGoalPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_80273444(20, 0, 0);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    UseBattleCamPreset(3);
    MoveBattleCamOver(20);
    InitTargetIterator();
0:
    SetGoalToTarget(ACTOR_SELF);
    ItemCheckHit(SI_VAR(0), 0x10000000, 0, SI_VAR(0), 0);
    if (SI_VAR(0) == 6) {
        goto 1;
    }
    GetItemPower(ITEM_P_O_W_BLOCK, SI_VAR(3), SI_VAR(4));
    ApplyShrinkFromOwner(SI_VAR(3));
    func_80269EAC(22);
    ItemDamageEnemy(SI_VAR(0), 0x38000400, 0, SI_VAR(3), 32);
1:
    ChooseNextTarget(0, SI_VAR(0));
    if (SI_VAR(0) != -1) {
        goto 0;
    }
    PlayEffect(0x7, 2, -70, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, -60, 65, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, -70, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, -70, 55, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    N(func_802A12E4_718B34)();
    sleep 30;
    await N(PlayerGoHome);
});

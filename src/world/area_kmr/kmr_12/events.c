#include "kmr_12.h"
#include "message_ids.h"
#include "entity.h"
#include "sprite/npc/goomba.h"

EvtScript N(ExitWest) = EXIT_WALK_SCRIPT(60, 0, "kmr_07", 1);
EvtScript N(ExitEast) = EXIT_WALK_SCRIPT(60, 1, "kmr_11", 0);

EvtScript N(BindExits) = {
    EVT_BIND_TRIGGER(N(ExitWest), TRIGGER_FLOOR_ABOVE, 0, 1, 0) // deili1
    EVT_BIND_TRIGGER(N(ExitEast), TRIGGER_FLOOR_ABOVE, 3, 1, 0) // deili2
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(GB_WorldLocation, LOCATION_GOOMBA_ROAD)
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamPerspective, 0, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, 0, 0, 0, 0)
    EVT_CALL(SetCamEnabled, 0, 1)
    EVT_CALL(MakeNpcs, 0, EVT_ADDR(N(npcGroupList)))
    EVT_EXEC_WAIT(N(MakeEntities))
    EVT_EXEC(N(PlayMusic))
    EVT_SET(LW(0), EVT_ADDR(N(BindExits)))
    EVT_EXEC(EnterWalk)
    EVT_WAIT(1)
    EVT_BIND_TRIGGER(N(ReadWestSign), TRIGGER_WALL_PRESS_A, 10, 1, 0)
    EVT_RETURN
    EVT_END
};

MobileAISettings N(goombaAISettings) = {
    .moveSpeed = 1.5f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 130.0f,
    .alertOffsetDist = 0.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 2.5f,
    .chaseTurnRate= 180,
    .chaseUpdateInterval = 3,
    .chaseRadius = 150.0f,
    .chaseOffsetDist = 0.0f,
    .unk_AI_2C = 1,
};

EvtScript kmr_12_GoombaAI = {
    EVT_CALL(BasicAI_Main, EVT_ADDR(N(goombaAISettings)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(goombaNpcSettings) = {
    .height = 20,
    .radius = 23,
    .ai = &N(GoombaAI),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .level = 5,
};

/// @bug Never returns
EvtScript N(ReadWestSign) = {
    EVT_SET_GROUP(EVT_GROUP_00)

    // "Eat a Mushroom to regain your energy!"
    EVT_SUSPEND_GROUP(1)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_kmr_12_sign_trap, 160, 40)
    EVT_RESUME_GROUP(1)

    EVT_SET(LF(0), FALSE)
    EVT_CALL(GetGoomba)
    EVT_IF_NE(LW(0), FALSE)
        EVT_CALL(GetNpcVar, NPC_GOOMBA, 0, LW(0))
        EVT_IF_EQ(LW(0), FALSE)
            // Trigger Goomba to peel off
            EVT_CALL(SetNpcVar, NPC_GOOMBA, 0, TRUE)
            EVT_SET(LF(0), TRUE)
            EVT_WAIT(10)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_IF_EQ(LF(0), TRUE)
        EVT_UNBIND
    EVT_END_IF
    EVT_END
    EVT_RETURN
};

EvtScript N(GoombaIdle) = {
    EVT_WAIT(1)

    EVT_CALL(SetSelfVar, 0, FALSE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_goomba_normal_fake_mushroom) // TODO: work out why palette 0 is used here
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetSelfEnemyFlagBits, NPC_FLAG_NO_AI, TRUE)

    // Wait until read_sign sets NPC var 0
    EVT_LABEL(0)
    EVT_CALL(GetSelfVar, 0, LW(0))
    EVT_WAIT(1)
    EVT_IF_EQ(LW(0), FALSE)
        EVT_GOTO(0)
    EVT_END_IF

    // Peel and jump off the sign
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40000 | NPC_FLAG_200000, TRUE)
    EVT_WAIT(3)
    EVT_SETF(LW(0), EVT_FLOAT(0.0))
    EVT_LOOP(9)
        EVT_ADDF(LW(0), EVT_FLOAT(10.0))
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, LW(0), 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_goomba_normal_still)
    EVT_LOOP(9)
        EVT_ADDF(LW(0), EVT_FLOAT(10.0))
        EVT_CALL(SetNpcRotation, NPC_SELF, 0, LW(0), 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_goomba_normal_dizzy)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_goomba_normal_idle)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0xF8, 0)
    EVT_CALL(func_802CFE2C, NPC_SELF, 8192)
    EVT_CALL(func_802CFD30, NPC_SELF, 5, 6, 1, 1, 0)
    EVT_WAIT(12)
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtNpc, NPC_SELF, 0x32C, 0)
    EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
    EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.6))
    EVT_CALL(NpcJump0, NPC_SELF, -35, 0, 30, 23)
    EVT_CALL(func_802CFD30, NPC_SELF, 0, 0, 0, 0, 0)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40000 | NPC_FLAG_200000, FALSE)
    EVT_CALL(SetSelfEnemyFlagBits, NPC_FLAG_NO_AI, FALSE)
    EVT_CALL(SetSelfEnemyFlagBits, NPC_FLAG_NO_ANIMS_LOADED, TRUE)

    // We're done jumping off; the player can read the sign again
    EVT_BIND_TRIGGER(N(ReadWestSign), TRIGGER_WALL_PRESS_A, 10, 1, 0)

    // Behave like a normal enemy from now on
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_ADDR(N(GoombaAI)))
    EVT_RETURN
    EVT_END
};

EvtScript N(GoombaInit) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_ADDR(N(GoombaIdle)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(goombaNpc) = {
    .id = NPC_GOOMBA,
    .settings = &N(goombaNpcSettings),
    .pos = { -33.0f, 30.0f, -25.0f },
    .flags = 0x00000C00,
    .init = &N(GoombaInit),
    .yaw = 90,
    .drops = {
		.dropFlags = NPC_DROP_FLAGS_80,
        .itemDropChance = 5,
        .itemDrops = { { ITEM_MUSHROOM, 10 } },
        .heartDrops = GENEROUS_WHEN_LOW_HEART_DROPS(2),
        .flowerDrops = GENEROUS_WHEN_LOW_FLOWER_DROPS(2),
    },
	.territory = { .temp = {
        // Wander
        /* center x, y, z */ -33, 0, 30,
        /* size x, z */ 40, 20,
        /* speed */ NO_OVERRIDE_MOVEMENT_SPEED,
        /* box? */ TRUE,

        // Detect
        /* center x, y, z */ 200, 0, 0,
        /* size x, z */ 400, 60,
        /* box? */ TRUE,

        /* flying? */ TRUE,
    }},
    .animations = {
        NPC_ANIM_goomba_normal_idle,
        NPC_ANIM_goomba_normal_walk,
        NPC_ANIM_goomba_normal_run,
        NPC_ANIM_goomba_normal_run,
        NPC_ANIM_goomba_normal_idle,
        NPC_ANIM_goomba_normal_idle,
        NPC_ANIM_goomba_normal_pain,
        NPC_ANIM_goomba_normal_pain,
        NPC_ANIM_goomba_normal_run,
        NPC_ANIM_goomba_normal_run,
        NPC_ANIM_goomba_normal_run,
        NPC_ANIM_goomba_normal_run,
        NPC_ANIM_goomba_normal_run,
        NPC_ANIM_goomba_normal_run,
        NPC_ANIM_goomba_normal_run,
        NPC_ANIM_goomba_normal_run,
    },
};

NpcGroupList N(npcGroupList) = {
    NPC_GROUP(N(goombaNpc), 0x0001, 0x02),
    {},
};

EvtScript N(ReadEastSign) = {
    EVT_CALL(IsStartingConversation, LW(0))
    EVT_IF_EQ(LW(0), 1)
        EVT_RETURN
    EVT_END_IF
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, 1)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(ShowMessageAtScreenPos, MSG_kmr_12_sign_to_fortress, 160, 40)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(SetTimeFreezeMode, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_ADDR(Entity_Signpost), 436, 0, -42, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignScript, EVT_ADDR(N(ReadEastSign)))
    EVT_RETURN
    EVT_END
};

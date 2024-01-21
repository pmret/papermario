#include "jan_03.h"
#include "sprite/player.h"

#include "world/common/npc/Toad_Stationary.inc.c"

#include "world/common/npc/Yoshi.inc.c"
#include "world/common/npc/Yoshi_Patrol.inc.c"

#include "world/common/npc/YoshiKid.inc.c"
#include "world/common/npc/YoshiKid_Patrol.inc.c"

#define NAME_SUFFIX _Unused
// included again later in this file; this copy is not used
#include "world/common/npc/Raven.inc.c"
#define NAME_SUFFIX

#include "world/common/npc/Sushie.inc.c"
#include "world/common/npc/Kolorado.inc.c"

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,key_item);
#include "world/common/complete/NormalItemChoice.inc.c"

#define CHUCK_QUIZMO_NPC_ID NPC_ChuckQuizmo
#include "world/common/complete/Quizmo.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(RedYoshiKidLetters)[] = {
    ITEM_LETTER_CHAIN_YOSHI_KID,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_RedYoshiKid) = {
    Call(N(LetterDelivery_Init),
        NPC_YoshiKid_02, ANIM_YoshiKid_Red_Talk, ANIM_YoshiKid_Red_Idle,
        ITEM_LETTER_CHAIN_YOSHI_KID, ITEM_LETTER_CHAIN_DANE_T_2,
        MSG_CH5_0079, MSG_CH5_007A, MSG_CH5_007B, MSG_CH5_007C,
        Ref(N(RedYoshiKidLetters)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

s32 N(KoloradoLetters)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EvtScript N(EVS_LetterPrompt_Kolorado) = {
    Call(N(LetterDelivery_Init),
        NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
        ITEM_LETTER_TO_KOLORADO, ITEM_NONE,
        MSG_CH5_001D, MSG_CH5_001E, MSG_CH5_001F, MSG_CH5_0020,
        Ref(N(KoloradoLetters)))
    ExecWait(N(EVS_DoLetterDelivery))
    Return
    End
};

EvtScript N(EVS_LetterReward_Kolorado) = {
    IfEq(LVarC, DELIVERY_ACCEPTED)
        EVT_GIVE_STAR_PIECE()
    EndIf
    Return
    End
};

s32 N(FoodItemList)[] = {
    ITEM_FRIED_SHROOM,
    ITEM_SPICY_SOUP,
    ITEM_NUTTY_CAKE,
    ITEM_KOOPA_TEA,
    ITEM_SPAGHETTI,
    ITEM_BIG_COOKIE,
    ITEM_CAKE,
    ITEM_FRIED_EGG,
    ITEM_BOILED_EGG,
    ITEM_FROZEN_FRIES,
    ITEM_POTATO_SALAD,
    ITEM_HOT_SHROOM,
    ITEM_BLAND_MEAL,
    ITEM_HONEY_SHROOM,
    ITEM_MAPLE_SHROOM,
    ITEM_JELLY_SHROOM1,
    ITEM_SHROOM_CAKE,
    ITEM_SHROOM_STEAK,
    ITEM_HONEY_SUPER,
    ITEM_MAPLE_SUPER,
    ITEM_JELLY_SUPER,
    ITEM_YUMMY_MEAL,
    ITEM_HONEY_ULTRA,
    ITEM_MAPLE_ULTRA,
    ITEM_JELLY_ULTRA,
    ITEM_SWEET_SHROOM,
    ITEM_ELECTRO_POP,
    ITEM_FIRE_POP,
    ITEM_SPECIAL_SHAKE,
    ITEM_COCO_POP,
    ITEM_LIME_CANDY,
    ITEM_LEMON_CANDY,
    ITEM_HONEY_CANDY,
    ITEM_JELLY_POP,
    ITEM_APPLE_PIE,
    ITEM_KOOPASTA,
    ITEM_KOOKY_COOKIE,
    ITEM_YOSHI_COOKIE,
    ITEM_NONE
};

API_CALLABLE(N(CountFoodItems)) {
    Bytecode* args = script->ptrReadPos;
    PlayerData* playerData = &gPlayerData;
    s32 outVar = *args++;
    s32 foodCount = 0;
    s32* it;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(playerData->invItems); i++) {
        it = N(FoodItemList);
        while (*it != 0) {
            if (playerData->invItems[i] == *it++) {
                foodCount++;
            }
        }
    }
    evt_set_variable(script, outVar, foodCount);
    return ApiStatus_DONE2;
}


EvtScript N(EVS_GetRescuedYoshiCount) = {
    Set(LVar0, 0)
    Add(LVar0, GF_JAN05_SavedYoshi)
    Add(LVar0, GF_JAN07_SavedYoshi)
    Add(LVar0, GF_JAN08_SavedYoshi)
    Add(LVar0, GF_JAN10_SavedYoshi)
    Add(LVar0, GF_JAN11_SavedYoshi)
    Return
    End
};

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    Set(LVar0, MSG_CH5_0094)
    Set(LVar8, MSG_CH5_0095)
    Set(LVar1, MSG_CH5_0096)
    Set(LVar2, MSG_CH5_0097)
    Set(LVar3, MSG_CH5_0098)
    Return
    End
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    Exec(N(EVS_PlayRestingSong))
    Call(SetPlayerSpeed, Float(3.5))
    Call(PlayerMoveTo, 322, -178, 0)
    Thread
        Wait(15)
        Call(N(ToadHouse_CamSetFOV), 0, 40)
        Call(SetCamType, CAM_DEFAULT, 4, FALSE)
        Call(SetCamPitch, CAM_DEFAULT, 54, -27)
        Call(SetCamDistance, CAM_DEFAULT, 135)
        Call(SetCamPosA, CAM_DEFAULT, 406, -130)
        Call(SetCamPosB, CAM_DEFAULT, 361, -190)
        Call(SetCamPosC, CAM_DEFAULT, 0, -1)
        Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, 361, -194, 0)
    Call(PlayerMoveTo, 370, -257, 0)
    Call(InterpPlayerYaw, 229, 1)
    Call(HidePlayerShadow, TRUE)
    Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Call(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    Thread
        Wait(60)
        Call(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    EndThread
    Wait(20)
    Thread
        Wait(81)
        Call(N(ToadHouse_CamSetFOV), 0, 25)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Wait(1)
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
    EndThread
    Return
    End
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    Call(HidePlayerShadow, FALSE)
    Call(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    Call(SetPlayerPos, 345, 0, -186)
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, 291, -100, 0)
    Exec(N(EVS_SetupMusic))
    Return
    End
};

EvtScript N(EVS_NpcInit_Toad) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_ToadHouseKeeper)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Yoshi_01) = {
    ExecWait(EVS_ShopOwnerDialog)
    Return
    End
};

EvtScript N(EVS_NpcInit_Yoshi_01) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Yoshi_01)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_VillageLeader) = {
    ExecWait(N(EVS_GetRescuedYoshiCount))
    Switch(LVar0)
        CaseLt(1)
            IfEq(GF_JAN03_AgreedToRescueChildren, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Shout, ANIM_VillageLeader_IdleSad, 0, MSG_CH5_0099)
                Set(GF_JAN03_AgreedToRescueChildren, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Shout, ANIM_VillageLeader_IdleSad, 0, MSG_CH5_009A)
            EndIf
        CaseLt(3)
            Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Shout, ANIM_VillageLeader_IdleSad, 0, MSG_CH5_009B)
        CaseLt(4)
            Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Shout, ANIM_VillageLeader_IdleSad, 0, MSG_CH5_009C)
        CaseLt(5)
            Call(SpeakToPlayer, NPC_SELF, ANIM_VillageLeader_Shout, ANIM_VillageLeader_IdleSad, 0, MSG_CH5_009D)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_VillageLeader) = {
    Loop(0)
        Call(NpcMoveTo, NPC_SELF, -300, -70, 50)
        Call(NpcMoveTo, NPC_SELF, -350, -70, 50)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_VillageLeader) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            Call(RemoveNpc, NPC_SELF)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            Call(SetNpcAnimation, NPC_SELF, ANIM_VillageLeader_Panic)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_VillageLeader)))
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_VillageLeader)))
        CaseDefault
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_Yoshi_02) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_Talk, ANIM_Yoshi_Green_Idle, 0, MSG_CH5_005A)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            ExecWait(N(EVS_GetRescuedYoshiCount))
            IfEq(LVar0, 0)
                IfEq(GF_JAN03_AgreedToRescueChildren, FALSE)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_CryTalk, ANIM_Yoshi_Green_Cry, 0, MSG_CH5_005B)
                Else
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_CryTalk, ANIM_Yoshi_Green_Cry, 0, MSG_CH5_005C)
                EndIf
            Else
                IfEq(GF_JAN11_SavedYoshi, FALSE)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_CryTalk, ANIM_Yoshi_Green_Cry, 0, MSG_CH5_005D)
                Else
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_Talk, ANIM_Yoshi_Green_Idle, 0, MSG_CH5_005E)
                EndIf
            EndIf
        CaseLe(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_Talk, ANIM_Yoshi_Green_Idle, 0, MSG_CH5_005F)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_Talk, ANIM_Yoshi_Green_Idle, 0, MSG_CH5_0060)
        CaseLt(STORY_CH6_FLOWER_GATE_OPEN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_Talk, ANIM_Yoshi_Green_Idle, 0, MSG_CH5_0061)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Green_Talk, ANIM_Yoshi_Green_Idle, 0, MSG_CH5_0062)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_Yoshi_02) = {
    Loop(0)
        Call(NpcMoveTo, NPC_SELF, -430, -220, 50)
        Call(NpcMoveTo, NPC_SELF, -340, -220, 50)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_Yoshi_02) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            IfEq(GF_JAN11_SavedYoshi, FALSE)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Yoshi_Green_Panic)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Yoshi_02)))
            Else
                Call(BindNpcIdle, NPC_SELF, 0)
            EndIf
    EndSwitch
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Yoshi_02)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Yoshi_03) = {
    IfGe(GB_StoryProgress, STORY_CH5_STAR_SPRIT_DEPARTED)
        Call(N(CountFoodItems), LVar0)
        IfNe(LVar0, 0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_006C)
            EVT_CHOOSE_CONSUMABLE_FROM(N(FoodItemList), 4)
            IfLe(LVar0, 0)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_006E)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_006D)
                Set(LVar0, ITEM_MELON)
                Set(LVar1, ITEM_TYPE_CONSUMABLE)
                ExecWait(N(GiveItemReward)) // misuse?
                Call(AddItem, ITEM_MELON, LVar0)
            EndIf
            Return
        EndIf
    EndIf
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_0063)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            ExecWait(N(EVS_GetRescuedYoshiCount))
            IfEq(LVar0, 0)
                IfEq(GF_JAN03_AgreedToRescueChildren, FALSE)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_CryTalk, ANIM_Yoshi_Yellow_Cry, 0, MSG_CH5_0064)
                Else
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_CryTalk, ANIM_Yoshi_Yellow_Cry, 0, MSG_CH5_0065)
                EndIf
            Else
                IfEq(GF_JAN07_SavedYoshi, FALSE)
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_CryTalk, ANIM_Yoshi_Yellow_Cry, 0, MSG_CH5_0066)
                Else
                    Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_0067)
                EndIf
            EndIf
        CaseLe(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_0068)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_0069)
        CaseLt(STORY_CH6_FLOWER_GATE_OPEN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_006A)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_Yoshi_Yellow_Talk, ANIM_Yoshi_Yellow_Idle, 0, MSG_CH5_006B)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_Yoshi_03) = {
    Loop(0)
        Call(NpcMoveTo, NPC_SELF, -105, -20, 50)
        Call(NpcMoveTo, NPC_SELF, -190, -80, 50)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_Yoshi_03) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            IfEq(GF_JAN07_SavedYoshi, FALSE)
                Call(SetNpcAnimation, NPC_SELF, ANIM_Yoshi_Yellow_Panic)
                Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Yoshi_03)))
            Else
                Call(BindNpcIdle, NPC_SELF, 0)
            EndIf
    EndSwitch
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Yoshi_03)))
    Return
    End
};

EvtScript N(EVS_NpcIdle_YoshiKid_01) = {
    Return
    End
};

EvtScript N(EVS_NpcIdle_YoshiKid_04) = {
    Return
    End
};

EvtScript N(EVS_NpcInteract_YoshiKid_01) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Green_Talk, ANIM_YoshiKid_Green_Idle, 0, MSG_CH5_006F)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Green_Talk, ANIM_YoshiKid_Green_Idle, 0, MSG_CH5_0070)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Green_Talk, ANIM_YoshiKid_Green_Idle, 0, MSG_CH5_0071)
        CaseLt(STORY_CH6_FLOWER_GATE_OPEN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Green_Talk, ANIM_YoshiKid_Green_Idle, 0, MSG_CH5_0072)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Green_Talk, ANIM_YoshiKid_Green_Idle, 0, MSG_CH5_0073)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_YoshiKid_02) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Red_Talk, ANIM_YoshiKid_Red_Idle, 0, MSG_CH5_0074)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Red_Talk, ANIM_YoshiKid_Red_Idle, 0, MSG_CH5_0075)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Red_Talk, ANIM_YoshiKid_Red_Idle, 0, MSG_CH5_0076)
        CaseLt(STORY_CH6_FLOWER_GATE_OPEN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Red_Talk, ANIM_YoshiKid_Red_Idle, 0, MSG_CH5_0077)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Red_Talk, ANIM_YoshiKid_Red_Idle, 0, MSG_CH5_0078)
    EndSwitch
    ExecWait(N(EVS_LetterPrompt_RedYoshiKid))
    IfNe(LVarC, 0)
        Return
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_YoshiKid_03) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Blue_Talk, ANIM_YoshiKid_Blue_Idle, 0, MSG_CH5_007D)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Blue_Talk, ANIM_YoshiKid_Blue_Idle, 0, MSG_CH5_007E)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Blue_Talk, ANIM_YoshiKid_Blue_Idle, 0, MSG_CH5_007F)
        CaseLt(STORY_CH6_FLOWER_GATE_OPEN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Blue_Talk, ANIM_YoshiKid_Blue_Idle, 0, MSG_CH5_0080)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Blue_Talk, ANIM_YoshiKid_Blue_Idle, 0, MSG_CH5_0081)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_YoshiKid_04) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Yellow_Talk, ANIM_YoshiKid_Yellow_Idle, 0, MSG_CH5_0082)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Yellow_Talk, ANIM_YoshiKid_Yellow_Idle, 0, MSG_CH5_0083)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Yellow_Talk, ANIM_YoshiKid_Yellow_Idle, 0, MSG_CH5_0084)
        CaseLt(STORY_CH6_FLOWER_GATE_OPEN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Yellow_Talk, ANIM_YoshiKid_Yellow_Idle, 0, MSG_CH5_0085)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Yellow_Talk, ANIM_YoshiKid_Yellow_Idle, 0, MSG_CH5_0086)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInteract_YoshiKid_05) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Purple_Talk, ANIM_YoshiKid_Purple_Idle, 0, MSG_CH5_0087)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Purple_Talk, ANIM_YoshiKid_Purple_Idle, 0, MSG_CH5_0088)
        CaseLt(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Purple_Talk, ANIM_YoshiKid_Purple_Idle, 0, MSG_CH5_0089)
        CaseLt(STORY_CH6_FLOWER_GATE_OPEN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Purple_Talk, ANIM_YoshiKid_Purple_Idle, 0, MSG_CH5_008A)
        CaseDefault
            Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Purple_Talk, ANIM_YoshiKid_Purple_Idle, 0, MSG_CH5_008B)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_YoshiKid_01) = {
    IfGe(GB_StoryProgress, STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        IfEq(GF_JAN11_SavedYoshi, FALSE)
            Call(RemoveNpc, NPC_SELF)
            Return
        Else
            IfEq(GB_StoryProgress, STORY_CH5_STAR_SPRIT_DEPARTED)
                Call(SetNpcPos, NPC_SELF, -490, 0, -90)
            Else
                Call(SetNpcPos, NPC_SELF, -450, 0, -190)
            EndIf
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_YoshiKid_01)))
        EndIf
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_YoshiKid_01)))
    Return
    End
};

EvtScript N(EVS_NpcInit_YoshiKid_02) = {
    IfGe(GB_StoryProgress, STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        IfEq(GF_JAN08_SavedYoshi, FALSE)
            Call(RemoveNpc, NPC_SELF)
            Return
        EndIf
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_YoshiKid_02)))
    Return
    End
};

EvtScript N(EVS_NpcInit_YoshiKid_03) = {
    IfGe(GB_StoryProgress, STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        IfEq(GF_JAN10_SavedYoshi, FALSE)
            Call(RemoveNpc, NPC_SELF)
            Return
        EndIf
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_YoshiKid_03)))
    Return
    End
};

EvtScript N(EVS_NpcInit_YoshiKid_04) = {
    IfGe(GB_StoryProgress, STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        IfEq(GF_JAN07_SavedYoshi, FALSE)
            Call(RemoveNpc, NPC_SELF)
            Return
        Else
            Call(SetNpcPos, NPC_SELF, -135, 0, -70)
            Call(InterpNpcYaw, NPC_SELF, 270, 0)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_YoshiKid_04)))
        EndIf
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_YoshiKid_04)))
    Return
    End
};

EvtScript N(EVS_NpcInit_YoshiKid_05) = {
    IfGe(GB_StoryProgress, STORY_CH5_YOSHI_CHILDREN_ARE_MISSING)
        IfEq(GF_JAN05_SavedYoshi, FALSE)
            Call(RemoveNpc, NPC_SELF)
            Return
        EndIf
    EndIf
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_YoshiKid_05)))
    Return
    End
};

EvtScript N(EVS_NpcInteract_Raven) = {
    Call(GetSelfNpcID, LVar0)
    Switch(LVar0)
        CaseEq(NPC_Raven_01)
            IfLt(GB_StoryProgress, STORY_CH5_RAPHAEL_LEFT_NEST)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_008C)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_008D)
            EndIf
        CaseEq(NPC_Raven_03)
            IfLt(GB_StoryProgress, STORY_CH5_RAPHAEL_LEFT_NEST)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_008E)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_008F)
            EndIf
        CaseEq(NPC_Raven_04)
            IfLt(GB_StoryProgress, STORY_CH5_RAPHAEL_LEFT_NEST)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_0090)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_0091)
            EndIf
        CaseEq(NPC_Raven_05)
            IfLt(GB_StoryProgress, STORY_CH5_RAPHAEL_LEFT_NEST)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_0092)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Raven_Talk, ANIM_Raven_Idle, 0, MSG_CH5_0093)
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Raven) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Raven)))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_RAPHAEL_LEFT_NEST)
        CaseRange(STORY_CH5_ZIP_LINE_READY, STORY_CH5_OPENED_ESCAPE_ROUTE)
            Call(GetSelfNpcID, LVar0)
            IfEq(LVar0, 14)
                Call(RemoveNpc, NPC_SELF)
            EndIf
        CaseGe(STORY_CH5_BEGAN_PEACH_MISSION)
        CaseDefault
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

s32 N(VolcanoVaseList)[] = {
    ITEM_VOLCANO_VASE,
    -1
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0012)
            ExecWait(N(EVS_LetterPrompt_Kolorado))
            ExecWait(N(EVS_LetterReward_Kolorado))
        CaseLt(STORY_CH5_GOT_JADE_RAVEN)
            Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0013)
            ExecWait(N(EVS_LetterPrompt_Kolorado))
            ExecWait(N(EVS_LetterReward_Kolorado))
        CaseLt(STORY_CH5_ZIP_LINE_READY)
            IfEq(AF_JAN_06, FALSE)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0014)
                Set(AF_JAN_06, TRUE)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0015)
            EndIf
            ExecWait(N(EVS_LetterPrompt_Kolorado))
            ExecWait(N(EVS_LetterReward_Kolorado))
        CaseEq(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(FindKeyItem, ITEM_VOLCANO_VASE, LVar0)
            IfEq(LVar0, -1)
                Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0016)
                ExecWait(N(EVS_LetterPrompt_Kolorado))
                ExecWait(N(EVS_LetterReward_Kolorado))
            Else
                Call(AdjustCam, CAM_DEFAULT, Float(5.0), 0, 325, Float(20.0), Float(-7.5))
                Set(LVar0, Ref(N(VolcanoVaseList)))
                Set(LVar1, 15)
                ExecWait(N(EVS_ChooseKeyItem))
                Switch(LVar0)
                    CaseEq(-1)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0017)
                        ExecWait(N(EVS_LetterPrompt_Kolorado))
                        ExecWait(N(EVS_LetterReward_Kolorado))
                    CaseDefault
                        Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0018)
                        Call(SetPlayerAnimation, ANIM_Mario1_NodYes)
                        Wait(20)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_0019)
                        Wait(10)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_IdleSad)
                        Wait(15)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
                        Call(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
                        Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
                        Wait(25)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_001A)
                        EVT_GIVE_KEY_REWARD(ITEM_MAGICAL_SEED4)
                        Set(GF_JAN03_Gift_MagicalSeed4, TRUE)
                        Wait(20)
                        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_001B)
                        Wait(10)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_001C)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
                        Call(SetNpcSpeed, NPC_SELF, Float(4.0))
                        Call(NpcMoveTo, NPC_SELF, -465, -185, 0)
                        Call(NpcMoveTo, NPC_SELF, -540, -70, 0)
                        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
                        Set(GB_StoryProgress, STORY_CH5_TRADED_VASE_FOR_SEED)
                EndSwitch
                Call(ResetCam, CAM_DEFAULT, Float(5.0))
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    Set(LVar0, 0)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_ZIP_LINE_READY)
            Set(LVar0, 1)
        CaseEq(STORY_CH5_STAR_SPRIT_DEPARTED)
            Call(SetNpcPos, NPC_SELF, -433, 0, -205)
            Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_400000, 0)
            Set(LVar0, 1)
    EndSwitch
    IfEq(LVar0, 1)
        Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Kolorado)))
    Else
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcInteract_Sushie) = {
    IfEq(AF_JAN_07, FALSE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 0, MSG_CH5_0058)
        Set(AF_JAN_07, TRUE)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_WorldSushie_Talk, ANIM_WorldSushie_Idle, 0, MSG_CH5_0059)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcIdle_Sushie) = {
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(SetNpcJumpscale, NPC_SELF, 1)
    Loop(0)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldSushie_Talk)
        Wait(30)
        Call(SetNpcAnimation, NPC_SELF, ANIM_WorldSushie_Run)
        Wait(15)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInit_Sushie) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Sushie)))
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_Sushie)))
    Return
    End
};

#include "world/common/npc/Raven.inc.c"

AnimID N(ExtraAnims_VillageLeader)[] = {
    ANIM_VillageLeader_Idle,
    ANIM_VillageLeader_IdleSad,
    ANIM_VillageLeader_Walk,
    ANIM_VillageLeader_Panic,
    ANIM_VillageLeader_Run,
    ANIM_VillageLeader_Talk,
    ANIM_VillageLeader_Shout,
    ANIM_VillageLeader_Celebrate,
    ANIM_VillageLeader_CrossArms,
    ANIM_LIST_END
};

NpcData N(NpcData_VillageLeader) = {
    .id = NPC_VillageLeader,
    .pos = { -300.0f, 0.0f, -70.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_VillageLeader),
    .settings = &N(NpcSettings_Yoshi),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = YOSHI_LEADER_ANIMS,
    .extraAnimations = N(ExtraAnims_VillageLeader),
    .tattle = MSG_NpcTattle_VillageLeader,
};

AnimID N(ExtraAnims_Sushie)[] = {
    ANIM_WorldSushie_Idle,
    ANIM_WorldSushie_Run,
    ANIM_WorldSushie_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Sushie) = {
    .id = NPC_Sushie,
    .pos = { -425.0f, 0.0f, -350.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Sushie),
    .settings = &N(NpcSettings_Sushie),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = SUSHIE_ANIMS,
    .extraAnimations = N(ExtraAnims_Sushie),
    .tattle = MSG_NpcTattle_Sushie,
};

AnimID N(ExtraAnims_Kolorado)[] = {
    ANIM_Kolorado_Idle,
    ANIM_Kolorado_IdleSad,
    ANIM_Kolorado_Walk,
    ANIM_Kolorado_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Kolorado) = {
    .id = NPC_Kolorado,
    .pos = { -475.0f, 0.0f, -75.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_Kolorado),
    .settings = &N(NpcSettings_Kolorado),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = KOLORADO_ANIMS,
    .extraAnimations = N(ExtraAnims_Kolorado),
    .tattle = MSG_NpcTattle_Kolorado,
};

NpcData N(NpcData_Toad)[] = {
    {
        .id = NPC_Toad,
        .pos = { 275.0f, 0.0f, -70.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Toad),
        .settings = &N(NpcSettings_Toad_Stationary),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = TOAD_RED_ANIMS,
        .tattle = MSG_NpcTattle_JAN_ToadHouseToad,
    },
    {
        .id = NPC_Yoshi_01,
        .pos = { 125.0f, 30.0f, -425.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Yoshi_01),
        .settings = &N(NpcSettings_Yoshi),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_JAN_ShopOwner,
    },
    {
        .id = NPC_Yoshi_02,
        .pos = { -350.0f, 0.0f, -220.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { -375, 0, -220 },
                    { -325, 0, -220 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Yoshi_02),
        .settings = &N(NpcSettings_Yoshi_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_GenericYoshi,
    },
    {
        .id = NPC_Yoshi_03,
        .pos = { -100.0f, 0.0f, -80.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 2,
                .points  = {
                    { -100, 0, -20 },
                    { -210, 0, -80 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_Yoshi_03),
        .settings = &N(NpcSettings_Yoshi_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_FoodLovingYoshi,
    },
    {
        .id = NPC_YoshiKid_01,
        .pos = { -450.0f, 0.0f, -160.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 5,
                .points  = {
                    { -450, 0, -160 },
                    { -378, 0, -81 },
                    { -590, 0, -100 },
                    { -464, 0, -46 },
                    { -495, 0, -147 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_YoshiKid_01),
        .settings = &N(NpcSettings_YoshiKid_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_GREEN_ANIMS,
        .tattle = MSG_NpcTattle_GreenYoshiKid,
    },
    {
        .id = NPC_YoshiKid_02,
        .pos = { -340.0f, 0.0f, -385.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 3,
                .points  = {
                    { -340, 0, -385 },
                    { -290, 0, -310 },
                    { -360, 0, -310 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_YoshiKid_02),
        .settings = &N(NpcSettings_YoshiKid_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_RED_ANIMS,
        .tattle = MSG_NpcTattle_RedYoshiKid,
    },
    {
        .id = NPC_YoshiKid_03,
        .pos = { -260.0f, 0.0f, -220.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 3,
                .points  = {
                    { -260, 0, -220 },
                    { -270, 0, -220 },
                    { -260, 0, -230 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_YoshiKid_03),
        .settings = &N(NpcSettings_YoshiKid_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_BLUE_ANIMS,
        .tattle = MSG_NpcTattle_BlueYoshiKid,
    },
    {
        .id = NPC_YoshiKid_04,
        .pos = { -460.0f, 0.0f, 150.0f },
        .yaw = 90,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 3,
                .points  = {
                    { -460, 0, 150 },
                    { -450, 0, 150 },
                    { -460, 0, 160 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_YoshiKid_04),
        .settings = &N(NpcSettings_YoshiKid_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_YELLOW_ANIMS,
        .tattle = MSG_NpcTattle_YellowYoshiKid,
    },
    {
        .id = NPC_YoshiKid_05,
        .pos = { -320.0f, 0.0f, 80.0f },
        .yaw = 270,
        .territory = {
            .patrol = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .numPoints  = 3,
                .points  = {
                    { -320, 0, 80 },
                    { -330, 0, 80 },
                    { -320, 0, 90 },
                },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_YoshiKid_05),
        .settings = &N(NpcSettings_YoshiKid_Patrol),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
        .drops = NO_DROPS,
        .animations = YOSHI_KID_PURPLE_ANIMS,
        .tattle = MSG_NpcTattle_PurpleYoshiKid,
    },
};

AnimID N(ExtraAnims_Raven)[] = {
    ANIM_Raven_Still,
    ANIM_Raven_Idle,
    ANIM_Raven_Talk,
    ANIM_LIST_END
};

NpcData N(NpcData_Ravens)[] = {
    {
        .id = NPC_Raven_01,
        .pos = { -650.0f, 374.0f, -150.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Raven),
        .settings = &N(NpcSettings_Raven),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .extraAnimations = N(ExtraAnims_Raven),
        .tattle = MSG_NpcTattle_RavenA,
    },
    {
        .id = NPC_Raven_02,
        .pos = { -645.0f, 457.0f, -255.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Raven),
        .settings = &N(NpcSettings_Raven),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
    },
    {
        .id = NPC_Raven_03,
        .pos = { -570.0f, 374.0f, -300.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Raven),
        .settings = &N(NpcSettings_Raven),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenC,
    },
    {
        .id = NPC_Raven_04,
        .pos = { -500.0f, 374.0f, -285.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Raven),
        .settings = &N(NpcSettings_Raven),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenD,
    },
    {
        .id = NPC_Raven_05,
        .pos = { -450.0f, 374.0f, -175.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_Raven),
        .settings = &N(NpcSettings_Raven),
        .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
        .drops = NO_DROPS,
        .animations = RAVEN_ANIMS,
        .tattle = MSG_NpcTattle_RavenE,
    },
};

NpcData N(NpcData_ChuckQuizmo) = {
    .id = NPC_ChuckQuizmo,
    .pos = { 300.0f, 0.0f, 400.0f },
    .yaw = 90,
    .initVarCount = 1,
    .initVar = { .bytes = { 0, QUIZ_AREA_JAN, QUIZ_COUNT_JAN, QUIZ_MAP_JAN_03 }},
    .settings = &N(NpcSettings_ChuckQuizmo),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = NO_DROPS,
    .animations = QUIZMO_ANIMS,
    .tattle = MSG_NpcTattle_ChuckQuizmo,
};

NpcGroupList N(CrisisNPCs) = {
    NPC_GROUP(N(NpcData_VillageLeader)),
    NPC_GROUP(N(NpcData_Sushie)),
    NPC_GROUP(N(NpcData_Ravens)),
    NPC_GROUP(N(NpcData_Toad)),
    {}
};

NpcGroupList N(ChapterNPCs) = {
    NPC_GROUP(N(NpcData_VillageLeader)),
    NPC_GROUP(N(NpcData_Kolorado)),
    NPC_GROUP(N(NpcData_Ravens)),
    NPC_GROUP(N(NpcData_Toad)),
    {}
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_VillageLeader)),
    NPC_GROUP(N(NpcData_Ravens)),
    NPC_GROUP(N(NpcData_Toad)),
    {}
};

NpcGroupList N(AfterNPCs) = {
    NPC_GROUP(N(NpcData_ChuckQuizmo)),
    NPC_GROUP(N(NpcData_Ravens)),
    NPC_GROUP(N(NpcData_Toad)),
    {}
};

#include "omo_09.h"
#include "effects.h"

s32 N(HoverOffsets)[] = {
     1,  2 , 3,  2,  1,
    -1, -2, -3, -2, -1,
};

EvtScript N(EVS_NpcIdle_Kammy) = {
    Call(SetSelfVar, 0, 0)
    Call(GetNpcPos, NPC_SELF, LVar6, LVar3, LVar4)
    Loop(0)
        UseBuf(Ref(N(HoverOffsets)))
        Loop(10)
            Call(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
            Call(GetSelfVar, 0, LVar5)
            IfEq(LVar5, 0)
                Wait(1)
            Else
                BufRead1(LVar1)
                Add(LVar3, LVar1)
                Call(SetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
                Wait(3)
            EndIf
        EndLoop
    EndLoop
    Return
    End
};

#define KAMMY_NPC NPC_Kammy
#include "world/common/util/GetKammyBroomEmitterPos.inc.c"

EvtScript N(EVS_NpcAux_Kammy) = {
    Call(GetNpcPos, NPC_Kammy, LVar6, LVar7, LVar8)
    Loop(0)
        Call(N(GetKammyBroomEmitterPos))
        Call(GetNpcPos, NPC_Kammy, LVar9, LVarA, LVarB)
        Set(LVar3, LVar9)
        Set(LVar4, LVarA)
        Set(LVar5, LVarB)
        SubF(LVar3, LVar6)
        SubF(LVar4, LVar7)
        SubF(LVar5, LVar8)
        SetF(LVar6, LVar9)
        SetF(LVar7, LVarA)
        SetF(LVar8, LVarB)
        IfNe(LVar3, 0)
            IfNe(LVar5, 0)
                PlayEffect(EFFECT_PURPLE_RING, 0, LVar0, LVar1, LVar2, LVar3, LVar4, LVar5, Float(1.0))
            EndIf
        EndIf
        Wait(3)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Scene_KammySetAmbush) = {
    Call(DisablePlayerInput, true)
    Set(GF_OMO09_SpawnedPeachChoice3, true)
    Set(AB_OMO_CurrentPeachChoice, GB_OMO_PeachChoice3)
    Switch(AB_OMO_CurrentPeachChoice)
        CaseEq(0)
            Set(MV_AmbushID, NPC_Pokey)
        CaseEq(1)
            Set(MV_AmbushID, NPC_Koopatrol)
        CaseEq(2)
            Set(MV_AmbushID, ITEM_SUPER_SODA)
    EndSwitch
    Call(SetNpcPos, NPC_Kammy, 1820, 165, 0)
    Call(SetNpcYaw, NPC_Kammy, 90)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim13)
    IfNe(AB_OMO_CurrentPeachChoice, 2)
        Call(SetNpcPos, MV_AmbushID, NPC_DISPOSE_LOCATION)
    EndIf
    Call(UseSettingsFrom, CAM_DEFAULT, 1900, 150, 0)
    Call(SetPanTarget, CAM_DEFAULT, 1900, 150, 0)
    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(15.0), Float(-7.5))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(5 * DT)
    Call(SetNpcVar, NPC_Kammy, 0, 1)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim13)
    Wait(25 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0E)
    Call(GetNpcPos, NPC_Kammy, LVar0, LVar1, LVar2)
    Add(LVar0, 25)
    Add(LVar1, 38)
    Call(PlaySoundAt, SOUND_KAMMY_SUMMON_MAGIC, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 0, LVar0, LVar1, LVar2, Float(1.0), 75)
    Wait(75 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0F)
    Add(LVar0, 55)
    Call(PlaySoundAt, SOUND_VANISH_IN_SMOKE, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_BIG_SMOKE_PUFF, LVar0, 150, 0, 1, 15, 3, 8)
    Wait(5 * DT)
    IfNe(AB_OMO_CurrentPeachChoice, 2)
        Call(SetNpcPos, MV_AmbushID, LVar0, 150, 0)
    Else
        Call(MakeItemEntity, MV_AmbushID, LVar0, 150, 0, ITEM_SPAWN_MODE_DECORATION, 0)
    EndIf
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim13)
    Call(SetNpcVar, NPC_Kammy, 0, 0)
    Wait(5 * DT)
    IfNe(AB_OMO_CurrentPeachChoice, 2)
        Call(PlaySoundAtNpc, MV_AmbushID, SOUND_EMOTE_QUESTION, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, MV_AmbushID, EMOTE_QUESTION, 0, 20, EMOTER_NPC, 0, 0, 0, 0)
        Wait(5 * DT)
    EndIf
    Call(GotoMap, Ref("omo_09"), omo_09_ENTRY_0)
    Wait(100 * DT)
    Return
    End
};

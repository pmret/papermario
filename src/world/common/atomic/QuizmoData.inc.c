#include "common.h"

u8 N(Quizmo_Answers)[64] = {
    0x02, 0x01, 0x01, 0x02, 0x02, 0x00, 0x02, 0x00,
    0x02, 0x01, 0x00, 0x02, 0x01, 0x01, 0x00, 0x02,
    0x00, 0x02, 0x01, 0x00, 0x00, 0x02, 0x01, 0x00,
    0x02, 0x01, 0x01, 0x02, 0x02, 0x01, 0x01, 0x01,
    0x00, 0x02, 0x02, 0x02, 0x02, 0x00, 0x01, 0x01,
    0x02, 0x01, 0x02, 0x01, 0x02, 0x00, 0x00, 0x01,
    0x01, 0x00, 0x01, 0x02, 0x01, 0x00, 0x02, 0x02,
    0x01, 0x02, 0x00, 0x02, 0x02, 0x01, 0x01, 0x01,
};

Quizmo_Requirements N(Quizmo_Requirements)[] = {
    { STORY_CH0_KAMMY_RETURNED_TO_BOWSER, 0 },
    { STORY_CH1_BEGAN_PEACH_MISSION, 10 },
    { STORY_CH2_BEGAN_PEACH_MISSION, 20 },
    { STORY_CH3_BEGAN_PEACH_MISSION, 30 },
    { STORY_CH4_BEGAN_PEACH_MISSION, 37 },
    { STORY_CH5_STAR_SPRIT_DEPARTED, 44 },
    { STORY_CH6_BEGAN_PEACH_MISSION, 52 },
    { STORY_CH7_BEGAN_PEACH_MISSION, 60 },
    { STORY_EPILOGUE, 64 },
    { 0, 64 },
};

EvtScript N(EVS_Quizmo_Exit) = {
    EVT_CALL(N(Quizmo_GetGameStatus75))
    EVT_IF_LE(EVT_VAR(0), 1)
        EVT_CALL(GetNpcPos, NPC_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 300)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, 1)
        EVT_CALL(SetNpcAnimation, NPC_SELF, NPC_ANIM_chuck_quizmo_Palette_00_Anim_C)
        EVT_WAIT_FRAMES(40)
        EVT_CALL(SetNpcPos, NPC_SELF, 0, -1000, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

#include "common.h"
#include "map.h"

#define NAMESPACE flo_08

ApiStatus N(AddPlayerHandsOffset)(Evt* script, s32 isInitialCall);
ApiStatus N(SetOverrideFlags_40)(Evt* script, s32 isInitialCall);
ApiStatus N(TransformFoliage)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc17)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc18)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc19)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc20)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc21)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc22)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc23)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkPartnerPosFunc)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkPartnerPosFunc2)(Evt* script, s32 isInitialCall);
ApiStatus N(func_8024003C_CAED7C)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc38)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802401CC_CAEF0C)(Evt* script, s32 isInitialCall);
ApiStatus N(SwitchToPartner)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc39)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240600_CAF340)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc40)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80240D40_CAFA80)(Evt* script, s32 isInitialCall);
ApiStatus N(func_8024150C_CB024C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241970_CB06B0)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802419C4_CB0704)(Evt* script, s32 isInitialCall);
ApiStatus N(func_802419FC_CB073C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241A98_CB07D8)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241B5C_CB089C)(Evt* script, s32 isInitialCall);
ApiStatus N(func_80241BCC_CB090C)(Evt* script, s32 isInitialCall);
ApiStatus N(UnkFunc43)(Evt* script, s32 isInitialCall);

extern NpcGroupList N(npcGroupList_80244EC4);
extern EvtSource N(80245914);
extern EvtSource N(80245F5C);
extern EvtSource N(main);
extern s32 N(D_80241FB0_CB0CF0)[];
extern s16 N(D_80241FB8_CB0CF8)[];
extern s32 N(D_80241FC8_CB0D08)[8][2];
extern f32 N(D_80242008_CB0D48)[3];

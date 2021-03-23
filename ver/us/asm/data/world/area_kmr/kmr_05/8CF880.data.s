.include "macro.inc"

.section .data

glabel D_80241810_8CF880
.word 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000000, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80243430, 0x00000001, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x0000004D, 0x00000001, 0x0000001B, 0x00000043, 0x00000003, UseExitHeading, 0x0000003C, 0x00000001, 0x00000044, 0x00000001, ExitWalk, 0x00000043, 0x00000003, GotoMap, 0x80243438, 0x00000002, 0x00000008, 0x00000001, 0x00000064, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80241810_8CF880, 0x00080000, 0x00000000, 0x00000001, 0x00000000, 0x00000047, 0x00000005, 0x8024186C, 0x00080000, 0x00000002, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0329, 0x0000001E, 0x00000043, 0x00000002, SetSpriteShading, 0xFFFFFFFF, 0x00000043, 0x00000006, SetCamPerspective, 0x00000000, 0x00000003, 0x00000019, 0x00000010, 0x00001000, 0x00000043, 0x00000005, SetCamBGColor, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamEnabled, 0x00000000, 0x00000001, 0x0000000A, 0x00000002, 0xF8405BAB, 0x00000000, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x8024280C, 0x00000012, 0x00000000, 0x00000043, 0x00000003, MakeNpcs, 0x00000000, 0x80242848, 0x00000013, 0x00000000, 0x00000046, 0x00000001, 0x80242890, 0x00000044, 0x00000001, 0x802417E0, 0x00000046, 0x00000001, 0x802433D8, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000001, 0x7FFFFE00, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000000, 0x00000003, 0x7FFFFE00, 0x00000024, 0x00000002, 0xFE363C80, 0x802418C8, 0x00000044, 0x00000001, EnterWalk, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000002, GetEntryID, 0xFE363C80, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000000, 0x0000000A, 0x00000002, 0xF8405BC8, 0x00000000, 0x00000044, 0x00000001, 0x80241C8C, 0x00000024, 0x00000002, 0xF8405BC8, 0x00000001, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x3FC00000, 0x0000001E, 0x0000001E, 0x43020000, 0x00000000, 0x00000001, 0x40200000, 0x000000B4, 0x00000003, 0x43160000, 0x00000000, 0x00000001, 0x00000043, 0x00000002, DoBasicAI, 0x80241AB0, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00140017, 0x00000000, 0x00000000, 0x80241AE0, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00050000

glabel D_80241B2C_8CFB9C
.word 0x40900000, 0x40600000, 0x40266666, 0x40000000, 0x3FC00000, 0x41A00000, 0x3FCCCCCD, 0x0000003C, 0x0000001E, 0x42A00000, 0x00000000, 0x00000005, 0x400CCCCD, 0x0000003C, 0x0000000F, 0x42C80000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0xFFFFFE0C, 0x00000043, 0x00000003, SetSelfVar, 0x00000006, 0x00000015, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000244, 0x00000043, 0x00000002, func_8024130C_8CF37C, 0x80241B44, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00140015, 0x00000000, 0x00000000, 0x80241B74, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00060002, 0x3FC00000, 0x0000001E, 0x0000001E, 0x43020000, 0x00000000, 0x00000001, 0x40200000, 0x000000B4, 0x00000003, 0x43160000, 0x00000000, 0x00000001, 0x00000043, 0x00000002, DoBasicAI, 0x80241C10, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00170017, 0x00000000, 0x00000000, 0x80241C40, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00060000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000002, SetPlayerSpeed, 0xF24A8680, 0x00000043, 0x00000004, PlayerMoveTo, 0xFFFFFFC4, 0xFFFFFFED, 0x00000000, 0x00000043, 0x00000002, DisablePartnerAI, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFC, 0x009D0008, 0x009D0001, 0x00000000, 0x000B00B7, 0x00000043, 0x00000001, EnablePartnerAI, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000005, TranslateModel, 0x0000006B, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, TranslateModel, 0x0000006B, 0x00000001, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000005, TranslateModel, 0x0000006B, 0x00000001, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, TranslateModel, 0x0000006B, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000008, 0x00000043, 0x00000005, TranslateModel, 0x0000006B, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000043, 0x00000005, TranslateModel, 0x0000006B, 0x00000001, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x0000001E, 0x00000004, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, func_800445D4, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000064, 0x00000003, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x0000000C, 0x00000002, 0xFE363C81, 0x00000064, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x0000000C, 0x00000002, 0xFE363C80, 0x00000230, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x0000000D, 0x00000002, 0xFE363C80, 0x000002BC, 0x00000004, 0x00000001, 0x0000000A, 0x00000013, 0x00000000, 0x00000043, 0x00000003, SetNpcAux, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x0000000A, ShowEmote, 0xFFFFFFFF, 0x00000000, 0xFFFFFFE2, 0x0000000C, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFF, 0xF24A7E80, 0x00000043, 0x00000003, SetNpcSpeed, 0xFFFFFFFF, 0xF24A8E80, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFF, 0x000002AD, 0x00000064, 0xFFFFFFDD, 0x00000000, 0x00000043, 0x00000003, SetSelfEnemyFlagBits, 0x40000000, 0x00000001, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, 0x80241C40, 0x0000001D, 0x00000001, 0x00000066, 0x0000001D, 0x00000001, 0x00000003, 0x0000001D, 0x00000001, 0x00000067, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, 0x80241C40, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x80241B00, 0x43988000, 0x42480000, 0xC1500000, 0x00000400, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x8005008A, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x66650002, 0x4CCC2666, 0x59980002, 0x3FFF3FFF, 0x4CCC0002, 0x3FFF6665, 0x3FFF0002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000131, 0x00000032, 0xFFFFFFF3, 0x0000001E, 0x00000014, 0xFFFF8001, 0x00000001, 0x0000014A, 0x00000032, 0x00000014, 0x00000078, 0x00000082, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00260001, 0x00260002, 0x00260003, 0x00260003, 0x00260001, 0x00260001, 0x00260005, 0x00260005, 0x00260003, 0x00260003, 0x00260003, 0x00260003, 0x00260003, 0x00260003, 0x00260003, 0x00260003, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x80241B00, 0x442F0000, 0x43520000, 0xC3250000, 0x00000400, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x8005008A, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x66650002, 0x4CCC2666, 0x59980002, 0x3FFF3FFF, 0x4CCC0002, 0x3FFF6665, 0x3FFF0002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000002BC, 0x000000D2, 0xFFFFFF5B, 0x0000001E, 0x00000014, 0xFFFF8001, 0x00000001, 0x000002BC, 0x000000D2, 0xFFFFFF5B, 0x00000078, 0x00000082, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00260001, 0x00260002, 0x00260003, 0x00260003, 0x00260001, 0x00260001, 0x00260005, 0x00260005, 0x00260003, 0x00260003, 0x00260003, 0x00260003, 0x00260003, 0x00260003, 0x00260003, 0x00260003, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, 0x80241E44, 0x00000043, 0x00000003, BindNpcAux, 0xFFFFFFFF, 0x80241D2C, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000003, 0x80241C60, 0x44320000, 0x42C80000, 0xC2BE0000, 0x00000400, 0x802423F4, 0x00000000, 0x00000000, 0x0000010E, 0x8005008A, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0x00000276, 0x00000064, 0x00000019, 0x00000028, 0x00000014, 0xFFFF8001, 0x00000001, 0x00000294, 0x00000064, 0x0000001E, 0x000000A5, 0x00000096, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00270001, 0x00270002, 0x00270003, 0x00270003, 0x00270001, 0x00270001, 0x00270005, 0x00270005, 0x00270003, 0x00270003, 0x00270003, 0x00270003, 0x00270003, 0x00270003, 0x00270003, 0x00270003, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000004, 0x80241BE4, 0x44700000, 0x43520000, 0xC1A00000, 0x00000400, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x8005008A, 0x000A0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00010000, 0x000003C0, 0x000000D2, 0xFFFFFFEC, 0x00000032, 0x00000019, 0xFFFF8001, 0x00000001, 0x000003E3, 0x000000D2, 0xFFFFFFC7, 0x000000D2, 0x00000064, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00280001, 0x00280003, 0x00280004, 0x00280004, 0x00280001, 0x00280001, 0x00280006, 0x00280006, 0x00280004, 0x00280004, 0x00280004, 0x00280004, 0x00280004, 0x00280004, 0x00280004, 0x00280004, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x80242014, 0x00000004, 0x00000001, 0x80242204, 0x00000004, 0x00000001, 0x8024242C, 0x02000004, 0x00000001, 0x8024261C, 0x02010004, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x80242014, 0x00000004, 0x00000001, 0x80242204, 0x00000004, 0x00000001, 0x8024242C, 0x000A0004, 0x00000001, 0x8024261C, 0x00080004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

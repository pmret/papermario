.include "macro.inc"

.section .data

dlabel D_80240C80_D11D40
.word 0x00000000, 0x00200018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80240CAC_D11D6C
.word 0x0000000F, 0x00000002, 0xF5DE0180, 0x00000044, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000003, 0x00000001, 0x0000000B, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000008, 0x00000001, 0x00000001, 0x0000000C, 0x00000002, 0xFE363C80, 0x00000190, 0x00000004, 0x00000001, 0x0000000B, 0x00000013, 0x00000000, 0x00000043, 0x00000001, func_802D2B6C, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000005, SetMusicTrack, 0x00000000, 0x00000047, 0x00000000, 0x00000008, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00210016, 0x00210003, 0x00000000, 0x001200D8, 0x00000043, 0x00000003, SetNpcJumpscale, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, NpcJump0, 0x00000000, 0x00000208, 0x00000000, 0xFFFFFFBC, 0x00000014, 0x00000043, 0x00000003, PlayerFaceNpc, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0xFFFFFFEC, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24DFE80, 0x00000043, 0x00000004, SetCamPitch, 0x00000000, 0xF24AB680, 0xF24A5A80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x0021001A, 0x00210003, 0x00000000, 0x001200D9, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000027, 0x00000002, 0xFE363C80, 0x0000001E, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00210016, 0x00210003, 0x00000000, 0x001200DA, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C83, 0xFE363C84, 0xFE363C85, 0x00000043, 0x00000006, GetDist2D, 0xFE363C86, 0xFE363C80, 0xFE363C82, 0xFE363C83, 0xFE363C85, 0x0000002E, 0x00000002, 0xFE363C86, 0xF24A7D4D, 0x00000043, 0x00000001, func_80240000_D110C0, 0x00000043, 0x00000005, AddVectorPolar, 0xFE363C83, 0xFE363C85, 0xFE363C86, 0xFE363C80, 0x00000043, 0x00000003, SetNpcSpeed, 0x00000000, 0xF24A8A80, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x0021000A, 0x00000056, 0x00000000, 0x00000043, 0x00000005, NpcMoveTo, 0x00000000, 0xFE363C83, 0xFE363C85, 0x00000000, 0x00000057, 0x00000000, 0x00000043, 0x00000002, StartBossBattle, 0x00000004, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241094_D12154
.word 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00210014, 0x00210014, 0x00000005, 0x001200DF, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802410C4_D12184
.word 0x00000043, 0x00000002, GetOwnerEncounterTrigger, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x0000001D, 0x00000001, 0x00000002, 0x0000001D, 0x00000001, 0x00000004, 0x0000001D, 0x00000001, 0x00000006, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000006, SpeakToPlayer, 0xFFFFFFFF, 0x00210011, 0x00210027, 0x00000005, 0x001200DF, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000020, 0x00000000, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241164_D12224
.word 0x00000043, 0x00000001, ClearDefeatedEnemies, 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xF5DE0180, 0x00000044, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00210014, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000001, 0x00210014, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, UseSettingsFrom, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetCamDistance, 0x00000000, 0xF24D9A80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000005, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A8280, 0x00000043, 0x00000003, WaitForCam, 0x00000000, 0xF24A7E80, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24A7E80, 0x00000057, 0x00000000, 0x00000043, 0x00000006, SpeakToPlayer, 0x00000000, 0x00210014, 0x00210014, 0x00000005, 0x001200DF, 0x00000043, 0x00000005, GetNpcPos, 0x00000000, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000005, SetNpcPos, 0x00000001, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000004, SetNpcCollisionSize, 0x00000000, 0x0000001A, 0x00000018, 0x00000043, 0x00000004, SetNpcCollisionSize, 0x00000001, 0x0000001A, 0x00000018, 0x00000043, 0x00000004, SetNpcFlagBits, 0x00000001, 0x00000002, 0x00000001, 0x00000043, 0x00000003, BindNpcInteract, 0xFFFFFFFF, D_80241094_D12154, 0x00000043, 0x00000003, BindNpcHit, 0x00000001, D_802410C4_D12184, 0x00000044, 0x00000001, 0x80240980, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000016, 0x00000001, 0x00000002, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802413F0_D124B0
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_80240CAC_D11D6C, 0x00000043, 0x00000003, BindNpcDefeat, 0xFFFFFFFF, D_80241164_D12224, 0x00000014, 0x00000001, 0xF5DE0180, 0x00000018, 0x00000001, 0x00000044, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0x00000258, 0x00000000, 0xFFFFFFBF, 0x0000001B, 0x00000001, 0x00000044, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0x0000018F, 0x00000006, 0xFFFFFF9C, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00210027, 0x00000043, 0x00000003, EnableModel, 0x00000023, 0x00000001, 0x00000043, 0x00000004, ModifyColliderFlags, 0x00000001, 0x0000000D, 0x7FFFFE00, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802414CC_D1258C
.word 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802414F8_D125B8
.word 0x00000000, D_80240C80_D11D40, 0x43828000, 0x00000000, 0xC2980000, 0x00440D0D, D_802413F0_D124B0, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00210003, 0x00210007, 0x00210007, 0x00210007, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00000000, 0x00000000, 0x00000000, 0x001A0006, 0x00000001, D_80240C80_D11D40, 0x43828000, 0x00000000, 0xC2980000, 0x21540F0C, D_802414CC_D1258C, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00210003, 0x00210007, 0x00210007, 0x00210007, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00210003, 0x00000000, 0x00000000, 0x00000000, 0x001A0006, 0x00000002, D_802414F8_D125B8, 0x02060000, 0x00000000, 0x00000000, 0x00000000

dlabel D_802418F0_D129B0
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000002, func_80045900, 0x00000001, 0x00000016, 0x00000001, 0x00000003, 0x00000043, 0x00000004, SetEnemyFlagBits, 0xFFFFFFFF, 0x00000010, 0x00000001, 0x00000043, 0x00000002, RemoveNpc, 0xFFFFFFFF, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802419AC_D12A6C
.word 0x3F000000, 0x0000003C, 0x0000000F, 0x42C80000, 0x00000000, 0x0000000A, 0x40600000, 0x000000B4, 0x00000014, 0x43160000, 0x00000000, 0x00000001

dlabel D_802419DC_D12A9C
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x00000005, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x0000000D, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x0000001E, 0x00000043, 0x00000002, sam_03_MeleeHitbox_Main, D_802419AC_D12A6C, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241A4C_D12B0C
.word 0x00000000, 0x00300024, 0x00000000, 0x00000000, D_802419DC_D12A9C, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00160000

dlabel D_80241A78_D12B38
.word 0x00000043, 0x00000003, EnableNpcShadow, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000006, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x0000001C, 0x00000043, 0x00000003, SetSelfVar, 0x00000002, 0x00000037, 0x00000043, 0x00000003, SetSelfVar, 0x00000003, 0x00000020, 0x00000043, 0x00000003, SetSelfVar, 0x00000004, 0x0000000A, 0x00000043, 0x00000003, SetSelfVar, 0x0000000F, 0x00000000, 0x00000043, 0x00000001, sam_03_MeleeHitbox_Control, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241B20_D12BE0
.word 0x00000000, 0x00200016, 0x00000000, 0x00000000, D_80241A78_D12B38, 0x00000000, 0x00000000, D_802418F0_D129B0, 0x00000000, 0x00000000, 0x00160008

dlabel D_80241B4C_D12C0C
.word 0x00520000, 0xFFFFFFFF

dlabel D_80241B54_D12C14
.word 0x00520000, 0x00520001, 0x0052000B, 0x00520004, 0x00520002, 0x00520003, 0xFFFFFFFF

dlabel D_80241B70_D12C30
.word 0x00000000, D_80241A4C_D12B0C, 0xC3AC8000, 0x00000000, 0x42E60000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x80050085, 0x00020000, 0x008C0008, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00040000, 0xFFFFFEA7, 0x00000000, 0x00000073, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFEA7, 0x00000000, 0x00000073, 0x000000FA, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00520001, 0x00520002, 0x00520003, 0x00520003, 0x00520001, 0x00520001, 0x0052000B, 0x0052000B, 0x00520004, 0x00520004, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00000003, 0x00000000, D_80241B54_D12C14, 0x00000000, 0x00000001, D_80241B20_D12BE0, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00520001, 0x00520002, 0x00520003, 0x00520003, 0x00520001, 0x00520001, 0x0052000B, 0x0052000B, 0x00520004, 0x00520004, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00000000, 0x00000000, D_80241B4C_D12C0C, 0x00000000

dlabel D_80241F50_D13010
.word 0x00000002, D_80241A4C_D12B0C, 0x43480000, 0x00000000, 0x00000000, 0x00000C00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x80050085, 0x00020000, 0x008C0008, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00040000, 0x000000C8, 0x00000000, 0x00000000, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x000000C8, 0x00000000, 0x00000000, 0x000000FA, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00520001, 0x00520002, 0x00520003, 0x00520003, 0x00520001, 0x00520001, 0x0052000B, 0x0052000B, 0x00520004, 0x00520004, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00000003, 0x00000000, D_80241B54_D12C14, 0x00000000, 0x00000003, D_80241B20_D12BE0, 0x00000000, 0xC47A0000, 0x00000000, 0x00800D00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00520001, 0x00520002, 0x00520003, 0x00520003, 0x00520001, 0x00520001, 0x0052000B, 0x0052000B, 0x00520004, 0x00520004, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00520001, 0x00000000, 0x00000000, D_80241B4C_D12C0C, 0x00000000, 0x00000002, D_80241B70_D12C30, 0x1D010001, 0x00000002, D_80241F50_D13010, 0x1D020001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000

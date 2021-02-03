.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A10EC_73797C
/* 73797C 802A10EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 737980 802A10F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 737984 802A10F4 0080802D */  daddu     $s0, $a0, $zero
/* 737988 802A10F8 2402000F */  addiu     $v0, $zero, 0xf
/* 73798C 802A10FC 3C03800E */  lui       $v1, %hi(gBattleStatus+0x83)
/* 737990 802A1100 8063C0F3 */  lb        $v1, %lo(gBattleStatus+0x83)($v1)
/* 737994 802A1104 24040015 */  addiu     $a0, $zero, 0x15
/* 737998 802A1108 AFBF0014 */  sw        $ra, 0x14($sp)
/* 73799C 802A110C AE020088 */  sw        $v0, 0x88($s0)
/* 7379A0 802A1110 0C03A752 */  jal       is_ability_active
/* 7379A4 802A1114 AE030084 */   sw       $v1, 0x84($s0)
/* 7379A8 802A1118 10400003 */  beqz      $v0, .L802A1128
/* 7379AC 802A111C 24020028 */   addiu    $v0, $zero, 0x28
/* 7379B0 802A1120 AE000084 */  sw        $zero, 0x84($s0)
/* 7379B4 802A1124 AE020088 */  sw        $v0, 0x88($s0)
.L802A1128:
/* 7379B8 802A1128 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7379BC 802A112C 8FB00010 */  lw        $s0, 0x10($sp)
/* 7379C0 802A1130 24020002 */  addiu     $v0, $zero, 2
/* 7379C4 802A1134 03E00008 */  jr        $ra
/* 7379C8 802A1138 27BD0018 */   addiu    $sp, $sp, 0x18

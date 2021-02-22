.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1B14_731E14
/* 731E14 802A1B14 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 731E18 802A1B18 2405000E */  addiu     $a1, $zero, 0xe
/* 731E1C 802A1B1C AFB00010 */  sw        $s0, 0x10($sp)
/* 731E20 802A1B20 3C10800E */  lui       $s0, %hi(gBattleStatus+0xD8)
/* 731E24 802A1B24 8E10C148 */  lw        $s0, %lo(gBattleStatus+0xD8)($s0)
/* 731E28 802A1B28 24060003 */  addiu     $a2, $zero, 3
/* 731E2C 802A1B2C AFBF0018 */  sw        $ra, 0x18($sp)
/* 731E30 802A1B30 AFB10014 */  sw        $s1, 0x14($sp)
/* 731E34 802A1B34 8E1101F4 */  lw        $s1, 0x1f4($s0)
/* 731E38 802A1B38 0C0997D0 */  jal       inflict_status
/* 731E3C 802A1B3C 0200202D */   daddu    $a0, $s0, $zero
/* 731E40 802A1B40 A200021C */  sb        $zero, 0x21c($s0)
/* 731E44 802A1B44 8E230000 */  lw        $v1, ($s1)
/* 731E48 802A1B48 34630100 */  ori       $v1, $v1, 0x100
/* 731E4C 802A1B4C AE230000 */  sw        $v1, ($s1)
/* 731E50 802A1B50 8FBF0018 */  lw        $ra, 0x18($sp)
/* 731E54 802A1B54 8FB10014 */  lw        $s1, 0x14($sp)
/* 731E58 802A1B58 8FB00010 */  lw        $s0, 0x10($sp)
/* 731E5C 802A1B5C 24020002 */  addiu     $v0, $zero, 2
/* 731E60 802A1B60 03E00008 */  jr        $ra
/* 731E64 802A1B64 27BD0020 */   addiu    $sp, $sp, 0x20

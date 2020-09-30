.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E069C
/* 79B4C 800E069C 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* 79B50 800E06A0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* 79B54 800E06A4 8C430004 */  lw        $v1, 4($v0)
/* 79B58 800E06A8 2404FFDF */  addiu     $a0, $zero, -0x21
/* 79B5C 800E06AC 3C018011 */  lui       $at, 0x8011
/* 79B60 800E06B0 AC20C940 */  sw        $zero, -0x36c0($at)
/* 79B64 800E06B4 00641824 */  and       $v1, $v1, $a0
/* 79B68 800E06B8 03E00008 */  jr        $ra
/* 79B6C 800E06BC AC430004 */   sw       $v1, 4($v0)

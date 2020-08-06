.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802E7D38
/* 1095B8 802E7D38 8C820040 */  lw    $v0, 0x40($a0)
/* 1095BC 802E7D3C 3C038016 */  lui   $v1, 0x8016
/* 1095C0 802E7D40 8C63C7D0 */  lw    $v1, -0x3830($v1)
/* 1095C4 802E7D44 AC430010 */  sw    $v1, 0x10($v0)
/* 1095C8 802E7D48 3403FFFF */  ori   $v1, $zero, 0xffff
/* 1095CC 802E7D4C 03E00008 */  jr    $ra
/* 1095D0 802E7D50 A4430000 */   sh    $v1, ($v0)

/* 1095D4 802E7D54 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1095D8 802E7D58 AFB00010 */  sw    $s0, 0x10($sp)
/* 1095DC 802E7D5C AFBF0014 */  sw    $ra, 0x14($sp)
/* 1095E0 802E7D60 0C0B9F4E */  jal   func_802E7D38
/* 1095E4 802E7D64 0080802D */   daddu $s0, $a0, $zero
/* 1095E8 802E7D68 3C02802E */  lui   $v0, 0x802e
/* 1095EC 802E7D6C 24426ED8 */  addiu $v0, $v0, 0x6ed8
/* 1095F0 802E7D70 AE02003C */  sw    $v0, 0x3c($s0)
/* 1095F4 802E7D74 8FBF0014 */  lw    $ra, 0x14($sp)
/* 1095F8 802E7D78 8FB00010 */  lw    $s0, 0x10($sp)
/* 1095FC 802E7D7C 03E00008 */  jr    $ra
/* 109600 802E7D80 27BD0018 */   addiu $sp, $sp, 0x18

/* 109604 802E7D84 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 109608 802E7D88 AFB00010 */  sw    $s0, 0x10($sp)
/* 10960C 802E7D8C 0080802D */  daddu $s0, $a0, $zero
/* 109610 802E7D90 24020001 */  addiu $v0, $zero, 1
/* 109614 802E7D94 AFBF0014 */  sw    $ra, 0x14($sp)
/* 109618 802E7D98 8E030040 */  lw    $v1, 0x40($s0)
/* 10961C 802E7D9C 0C0B9F4E */  jal   func_802E7D38
/* 109620 802E7DA0 A0620007 */   sb    $v0, 7($v1)
/* 109624 802E7DA4 3C013F0F */  lui   $at, 0x3f0f
/* 109628 802E7DA8 34215C29 */  ori   $at, $at, 0x5c29
/* 10962C 802E7DAC 44810000 */  mtc1  $at, $f0
/* 109630 802E7DB0 3C02802E */  lui   $v0, 0x802e
/* 109634 802E7DB4 24426ED8 */  addiu $v0, $v0, 0x6ed8
/* 109638 802E7DB8 AE02003C */  sw    $v0, 0x3c($s0)
/* 10963C 802E7DBC E6000054 */  swc1  $f0, 0x54($s0)
/* 109640 802E7DC0 E6000058 */  swc1  $f0, 0x58($s0)
/* 109644 802E7DC4 E600005C */  swc1  $f0, 0x5c($s0)
/* 109648 802E7DC8 8FBF0014 */  lw    $ra, 0x14($sp)
/* 10964C 802E7DCC 8FB00010 */  lw    $s0, 0x10($sp)
/* 109650 802E7DD0 03E00008 */  jr    $ra
/* 109654 802E7DD4 27BD0018 */   addiu $sp, $sp, 0x18

/* 109658 802E7DD8 00000000 */  nop   
/* 10965C 802E7DDC 00000000 */  nop   



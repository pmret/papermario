.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel play_sound_at_npc
/* 0E0408 80149D08 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0E040C 80149D0C AFB00018 */  sw    $s0, 0x18($sp)
/* 0E0410 80149D10 0080802D */  daddu $s0, $a0, $zero
/* 0E0414 80149D14 AFB1001C */  sw    $s1, 0x1c($sp)
/* 0E0418 80149D18 00A0882D */  daddu $s1, $a1, $zero
/* 0E041C 80149D1C AFBF0020 */  sw    $ra, 0x20($sp)
/* 0E0420 80149D20 0C00EAD2 */  jal   get_npc_safe
/* 0E0424 80149D24 00C0202D */   daddu $a0, $a2, $zero
/* 0E0428 80149D28 10400007 */  beqz  $v0, .L80149D48
/* 0E042C 80149D2C 0200202D */   daddu $a0, $s0, $zero
/* 0E0430 80149D30 C4400040 */  lwc1  $f0, 0x40($v0)
/* 0E0434 80149D34 E7A00010 */  swc1  $f0, 0x10($sp)
/* 0E0438 80149D38 8C460038 */  lw    $a2, 0x38($v0)
/* 0E043C 80149D3C 8C47003C */  lw    $a3, 0x3c($v0)
/* 0E0440 80149D40 0C052757 */  jal   play_sound_at_position
/* 0E0444 80149D44 0220282D */   daddu $a1, $s1, $zero
.L80149D48:
/* 0E0448 80149D48 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0E044C 80149D4C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 0E0450 80149D50 8FB00018 */  lw    $s0, 0x18($sp)
/* 0E0454 80149D54 03E00008 */  jr    $ra
/* 0E0458 80149D58 27BD0028 */   addiu $sp, $sp, 0x28


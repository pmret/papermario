.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel ShowVariableMessageBox
/* 17FBEC 8025130C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 17FBF0 80251310 AFB10014 */  sw    $s1, 0x14($sp)
/* 17FBF4 80251314 0080882D */  daddu $s1, $a0, $zero
/* 17FBF8 80251318 AFBF001C */  sw    $ra, 0x1c($sp)
/* 17FBFC 8025131C AFB20018 */  sw    $s2, 0x18($sp)
/* 17FC00 80251320 AFB00010 */  sw    $s0, 0x10($sp)
/* 17FC04 80251324 8E30000C */  lw    $s0, 0xc($s1)
/* 17FC08 80251328 8E050000 */  lw    $a1, ($s0)
/* 17FC0C 8025132C 0C0B1EAF */  jal   get_variable
/* 17FC10 80251330 26100004 */   addiu $s0, $s0, 4
/* 17FC14 80251334 8E050000 */  lw    $a1, ($s0)
/* 17FC18 80251338 26100004 */  addiu $s0, $s0, 4
/* 17FC1C 8025133C 0220202D */  daddu $a0, $s1, $zero
/* 17FC20 80251340 0C0B1EAF */  jal   get_variable
/* 17FC24 80251344 0040902D */   daddu $s2, $v0, $zero
/* 17FC28 80251348 0220202D */  daddu $a0, $s1, $zero
/* 17FC2C 8025134C 8E050000 */  lw    $a1, ($s0)
/* 17FC30 80251350 0C0B1EAF */  jal   get_variable
/* 17FC34 80251354 0040802D */   daddu $s0, $v0, $zero
/* 17FC38 80251358 0240202D */  daddu $a0, $s2, $zero
/* 17FC3C 8025135C 0200282D */  daddu $a1, $s0, $zero
/* 17FC40 80251360 0C093E81 */  jal   show_variable_battle_message
/* 17FC44 80251364 0040302D */   daddu $a2, $v0, $zero
/* 17FC48 80251368 8FBF001C */  lw    $ra, 0x1c($sp)
/* 17FC4C 8025136C 8FB20018 */  lw    $s2, 0x18($sp)
/* 17FC50 80251370 8FB10014 */  lw    $s1, 0x14($sp)
/* 17FC54 80251374 8FB00010 */  lw    $s0, 0x10($sp)
/* 17FC58 80251378 24020002 */  addiu $v0, $zero, 2
/* 17FC5C 8025137C 03E00008 */  jr    $ra
/* 17FC60 80251380 27BD0020 */   addiu $sp, $sp, 0x20


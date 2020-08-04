.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel GetIdleGoal
/* 1991CC 8026A8EC 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 1991D0 8026A8F0 AFB40020 */  sw    $s4, 0x20($sp)
/* 1991D4 8026A8F4 0080A02D */  daddu $s4, $a0, $zero
/* 1991D8 8026A8F8 AFBF0024 */  sw    $ra, 0x24($sp)
/* 1991DC 8026A8FC AFB3001C */  sw    $s3, 0x1c($sp)
/* 1991E0 8026A900 AFB20018 */  sw    $s2, 0x18($sp)
/* 1991E4 8026A904 AFB10014 */  sw    $s1, 0x14($sp)
/* 1991E8 8026A908 AFB00010 */  sw    $s0, 0x10($sp)
/* 1991EC 8026A90C 8E92000C */  lw    $s2, 0xc($s4)
/* 1991F0 8026A910 8E450000 */  lw    $a1, ($s2)
/* 1991F4 8026A914 0C0B1EAF */  jal   get_variable
/* 1991F8 8026A918 26520004 */   addiu $s2, $s2, 4
/* 1991FC 8026A91C 0040202D */  daddu $a0, $v0, $zero
/* 199200 8026A920 2402FF81 */  addiu $v0, $zero, -0x7f
/* 199204 8026A924 14820002 */  bne   $a0, $v0, .L8026A930
/* 199208 8026A928 00000000 */   nop   
/* 19920C 8026A92C 8E840148 */  lw    $a0, 0x148($s4)
.L8026A930:
/* 199210 8026A930 0C09A75B */  jal   get_actor
/* 199214 8026A934 00000000 */   nop   
/* 199218 8026A938 8E450000 */  lw    $a1, ($s2)
/* 19921C 8026A93C 26520004 */  addiu $s2, $s2, 4
/* 199220 8026A940 C44000D4 */  lwc1  $f0, 0xd4($v0)
/* 199224 8026A944 C44200DC */  lwc1  $f2, 0xdc($v0)
/* 199228 8026A948 8E500000 */  lw    $s0, ($s2)
/* 19922C 8026A94C 4600010D */  trunc.w.s $f4, $f0
/* 199230 8026A950 44062000 */  mfc1  $a2, $f4
/* 199234 8026A954 C44000D8 */  lwc1  $f0, 0xd8($v0)
/* 199238 8026A958 8E520004 */  lw    $s2, 4($s2)
/* 19923C 8026A95C 4600010D */  trunc.w.s $f4, $f0
/* 199240 8026A960 44112000 */  mfc1  $s1, $f4
/* 199244 8026A964 4600110D */  trunc.w.s $f4, $f2
/* 199248 8026A968 44132000 */  mfc1  $s3, $f4
/* 19924C 8026A96C 0C0B2026 */  jal   set_variable
/* 199250 8026A970 0280202D */   daddu $a0, $s4, $zero
/* 199254 8026A974 0280202D */  daddu $a0, $s4, $zero
/* 199258 8026A978 0200282D */  daddu $a1, $s0, $zero
/* 19925C 8026A97C 0C0B2026 */  jal   set_variable
/* 199260 8026A980 0220302D */   daddu $a2, $s1, $zero
/* 199264 8026A984 0280202D */  daddu $a0, $s4, $zero
/* 199268 8026A988 0240282D */  daddu $a1, $s2, $zero
/* 19926C 8026A98C 0C0B2026 */  jal   set_variable
/* 199270 8026A990 0260302D */   daddu $a2, $s3, $zero
/* 199274 8026A994 8FBF0024 */  lw    $ra, 0x24($sp)
/* 199278 8026A998 8FB40020 */  lw    $s4, 0x20($sp)
/* 19927C 8026A99C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 199280 8026A9A0 8FB20018 */  lw    $s2, 0x18($sp)
/* 199284 8026A9A4 8FB10014 */  lw    $s1, 0x14($sp)
/* 199288 8026A9A8 8FB00010 */  lw    $s0, 0x10($sp)
/* 19928C 8026A9AC 24020002 */  addiu $v0, $zero, 2
/* 199290 8026A9B0 03E00008 */  jr    $ra
/* 199294 8026A9B4 27BD0028 */   addiu $sp, $sp, 0x28


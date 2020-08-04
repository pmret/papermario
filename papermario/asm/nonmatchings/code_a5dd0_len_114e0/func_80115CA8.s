.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80115CA8
/* 0AC3A8 80115CA8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0AC3AC 80115CAC AFB3001C */  sw    $s3, 0x1c($sp)
/* 0AC3B0 80115CB0 0080982D */  daddu $s3, $a0, $zero
/* 0AC3B4 80115CB4 AFB10014 */  sw    $s1, 0x14($sp)
/* 0AC3B8 80115CB8 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0AC3BC 80115CBC AFB20018 */  sw    $s2, 0x18($sp)
/* 0AC3C0 80115CC0 AFB00010 */  sw    $s0, 0x10($sp)
/* 0AC3C4 80115CC4 8E630000 */  lw    $v1, ($s3)
/* 0AC3C8 80115CC8 24020002 */  addiu $v0, $zero, 2
/* 0AC3CC 80115CCC 10620015 */  beq   $v1, $v0, .L80115D24
/* 0AC3D0 80115CD0 0000882D */   daddu $s1, $zero, $zero
/* 0AC3D4 80115CD4 8E620010 */  lw    $v0, 0x10($s3)
/* 0AC3D8 80115CD8 50400013 */  beql  $v0, $zero, .L80115D28
/* 0AC3DC 80115CDC 0220102D */   daddu $v0, $s1, $zero
/* 0AC3E0 80115CE0 8C52000C */  lw    $s2, 0xc($v0)
/* 0AC3E4 80115CE4 12400010 */  beqz  $s2, .L80115D28
/* 0AC3E8 80115CE8 0220102D */   daddu $v0, $s1, $zero
/* 0AC3EC 80115CEC 0240882D */  daddu $s1, $s2, $zero
/* 0AC3F0 80115CF0 1A20000C */  blez  $s1, .L80115D24
/* 0AC3F4 80115CF4 0000802D */   daddu $s0, $zero, $zero
.L80115CF8:
/* 0AC3F8 80115CF8 8E620010 */  lw    $v0, 0x10($s3)
/* 0AC3FC 80115CFC 8C430010 */  lw    $v1, 0x10($v0)
/* 0AC400 80115D00 00101080 */  sll   $v0, $s0, 2
/* 0AC404 80115D04 00431021 */  addu  $v0, $v0, $v1
/* 0AC408 80115D08 8C440000 */  lw    $a0, ($v0)
/* 0AC40C 80115D0C 0C04572A */  jal   func_80115CA8
/* 0AC410 80115D10 26100001 */   addiu $s0, $s0, 1
/* 0AC414 80115D14 02228821 */  addu  $s1, $s1, $v0
/* 0AC418 80115D18 0212102A */  slt   $v0, $s0, $s2
/* 0AC41C 80115D1C 1440FFF6 */  bnez  $v0, .L80115CF8
/* 0AC420 80115D20 00000000 */   nop   
.L80115D24:
/* 0AC424 80115D24 0220102D */  daddu $v0, $s1, $zero
.L80115D28:
/* 0AC428 80115D28 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0AC42C 80115D2C 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0AC430 80115D30 8FB20018 */  lw    $s2, 0x18($sp)
/* 0AC434 80115D34 8FB10014 */  lw    $s1, 0x14($sp)
/* 0AC438 80115D38 8FB00010 */  lw    $s0, 0x10($sp)
/* 0AC43C 80115D3C 03E00008 */  jr    $ra
/* 0AC440 80115D40 27BD0028 */   addiu $sp, $sp, 0x28


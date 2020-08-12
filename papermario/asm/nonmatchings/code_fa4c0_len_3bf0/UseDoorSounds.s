.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel UseDoorSounds
/* 0FACC4 802D6314 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FACC8 802D6318 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FACCC 802D631C 8C82000C */  lw    $v0, 0xc($a0)
/* 0FACD0 802D6320 0C0B1EAF */  jal   get_variable
/* 0FACD4 802D6324 8C450000 */   lw    $a1, ($v0)
/* 0FACD8 802D6328 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FACDC 802D632C 3C018015 */  lui   $at, 0x8015
/* 0FACE0 802D6330 A4221340 */  sh    $v0, 0x1340($at)
/* 0FACE4 802D6334 24020002 */  addiu $v0, $zero, 2
/* 0FACE8 802D6338 03E00008 */  jr    $ra
/* 0FACEC 802D633C 27BD0018 */   addiu $sp, $sp, 0x18

glabel func_802D6340
/* 0FACF0 802D6340 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FACF4 802D6344 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FACF8 802D6348 8C82000C */  lw    $v0, 0xc($a0)
/* 0FACFC 802D634C 0C0B1EAF */  jal   get_variable
/* 0FAD00 802D6350 8C450000 */   lw    $a1, ($v0)
/* 0FAD04 802D6354 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FAD08 802D6358 3C018015 */  lui   $at, 0x8015
/* 0FAD0C 802D635C A4221308 */  sh    $v0, 0x1308($at)
/* 0FAD10 802D6360 24020002 */  addiu $v0, $zero, 2
/* 0FAD14 802D6364 03E00008 */  jr    $ra
/* 0FAD18 802D6368 27BD0018 */   addiu $sp, $sp, 0x18


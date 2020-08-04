.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel init_script_list
/* 0E7C9C 802C32EC 3C028007 */  lui   $v0, 0x8007
/* 0E7CA0 802C32F0 8C42419C */  lw    $v0, 0x419c($v0)
/* 0E7CA4 802C32F4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E7CA8 802C32F8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0E7CAC 802C32FC 80420070 */  lb    $v0, 0x70($v0)
/* 0E7CB0 802C3300 1440000D */  bnez  $v0, .L802C3338
/* 0E7CB4 802C3304 00000000 */   nop   
/* 0E7CB8 802C3308 3C02802E */  lui   $v0, 0x802e
/* 0E7CBC 802C330C 2442A490 */  addiu $v0, $v0, -0x5b70
/* 0E7CC0 802C3310 3C01802E */  lui   $at, 0x802e
/* 0E7CC4 802C3314 AC22A890 */  sw    $v0, -0x5770($at)
/* 0E7CC8 802C3318 3C02802E */  lui   $v0, 0x802e
/* 0E7CCC 802C331C 2442BCA8 */  addiu $v0, $v0, -0x4358
/* 0E7CD0 802C3320 3C01802E */  lui   $at, 0x802e
/* 0E7CD4 802C3324 AC22A484 */  sw    $v0, -0x5b7c($at)
/* 0E7CD8 802C3328 3C02802E */  lui   $v0, 0x802e
/* 0E7CDC 802C332C 2442BC70 */  addiu $v0, $v0, -0x4390
/* 0E7CE0 802C3330 080B0CD8 */  j     .L802C3360
/* 0E7CE4 802C3334 00000000 */   nop   

.L802C3338:
/* 0E7CE8 802C3338 3C02802E */  lui   $v0, 0x802e
/* 0E7CEC 802C333C 2442A690 */  addiu $v0, $v0, -0x5970
/* 0E7CF0 802C3340 3C01802E */  lui   $at, 0x802e
/* 0E7CF4 802C3344 AC22A890 */  sw    $v0, -0x5770($at)
/* 0E7CF8 802C3348 3C02802E */  lui   $v0, 0x802e
/* 0E7CFC 802C334C 2442BCE8 */  addiu $v0, $v0, -0x4318
/* 0E7D00 802C3350 3C01802E */  lui   $at, 0x802e
/* 0E7D04 802C3354 AC22A484 */  sw    $v0, -0x5b7c($at)
/* 0E7D08 802C3358 3C02802E */  lui   $v0, 0x802e
/* 0E7D0C 802C335C 2442BD34 */  addiu $v0, $v0, -0x42cc
.L802C3360:
/* 0E7D10 802C3360 3C01802E */  lui   $at, 0x802e
/* 0E7D14 802C3364 AC22A480 */  sw    $v0, -0x5b80($at)
/* 0E7D18 802C3368 3C01802E */  lui   $at, 0x802e
/* 0E7D1C 802C336C AC20A488 */  sw    $zero, -0x5b78($at)
/* 0E7D20 802C3370 3C01802E */  lui   $at, 0x802e
/* 0E7D24 802C3374 0C0B5158 */  jal   func_802D4560
/* 0E7D28 802C3378 AC209CA4 */   sw    $zero, -0x635c($at)
/* 0E7D2C 802C337C 0C0B355F */  jal   func_802CD57C
/* 0E7D30 802C3380 00000000 */   nop   
/* 0E7D34 802C3384 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0E7D38 802C3388 03E00008 */  jr    $ra
/* 0E7D3C 802C338C 27BD0018 */   addiu $sp, $sp, 0x18


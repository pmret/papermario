.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel clear_script_list
/* 0E7B8C 802C31DC 3C028007 */  lui   $v0, 0x8007
/* 0E7B90 802C31E0 8C42419C */  lw    $v0, 0x419c($v0)
/* 0E7B94 802C31E4 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E7B98 802C31E8 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0E7B9C 802C31EC 80420070 */  lb    $v0, 0x70($v0)
/* 0E7BA0 802C31F0 1440000D */  bnez  $v0, .L802C3228
/* 0E7BA4 802C31F4 00000000 */   nop   
/* 0E7BA8 802C31F8 3C02802E */  lui   $v0, 0x802e
/* 0E7BAC 802C31FC 2442A490 */  addiu $v0, $v0, -0x5b70
/* 0E7BB0 802C3200 3C01802E */  lui   $at, 0x802e
/* 0E7BB4 802C3204 AC22A890 */  sw    $v0, -0x5770($at)
/* 0E7BB8 802C3208 3C02802E */  lui   $v0, 0x802e
/* 0E7BBC 802C320C 2442BCA8 */  addiu $v0, $v0, -0x4358
/* 0E7BC0 802C3210 3C01802E */  lui   $at, 0x802e
/* 0E7BC4 802C3214 AC22A484 */  sw    $v0, -0x5b7c($at)
/* 0E7BC8 802C3218 3C02802E */  lui   $v0, 0x802e
/* 0E7BCC 802C321C 2442BC70 */  addiu $v0, $v0, -0x4390
/* 0E7BD0 802C3220 080B0C94 */  j     .L802C3250
/* 0E7BD4 802C3224 00000000 */   nop   

.L802C3228:
/* 0E7BD8 802C3228 3C02802E */  lui   $v0, 0x802e
/* 0E7BDC 802C322C 2442A690 */  addiu $v0, $v0, -0x5970
/* 0E7BE0 802C3230 3C01802E */  lui   $at, 0x802e
/* 0E7BE4 802C3234 AC22A890 */  sw    $v0, -0x5770($at)
/* 0E7BE8 802C3238 3C02802E */  lui   $v0, 0x802e
/* 0E7BEC 802C323C 2442BCE8 */  addiu $v0, $v0, -0x4318
/* 0E7BF0 802C3240 3C01802E */  lui   $at, 0x802e
/* 0E7BF4 802C3244 AC22A484 */  sw    $v0, -0x5b7c($at)
/* 0E7BF8 802C3248 3C02802E */  lui   $v0, 0x802e
/* 0E7BFC 802C324C 2442BD34 */  addiu $v0, $v0, -0x42cc
.L802C3250:
/* 0E7C00 802C3250 3C01802E */  lui   $at, 0x802e
/* 0E7C04 802C3254 AC22A480 */  sw    $v0, -0x5b80($at)
/* 0E7C08 802C3258 3C02802E */  lui   $v0, 0x802e
/* 0E7C0C 802C325C 8C42A890 */  lw    $v0, -0x5770($v0)
/* 0E7C10 802C3260 2403007F */  addiu $v1, $zero, 0x7f
/* 0E7C14 802C3264 244201FC */  addiu $v0, $v0, 0x1fc
.L802C3268:
/* 0E7C18 802C3268 AC400000 */  sw    $zero, ($v0)
/* 0E7C1C 802C326C 2463FFFF */  addiu $v1, $v1, -1
/* 0E7C20 802C3270 0461FFFD */  bgez  $v1, .L802C3268
/* 0E7C24 802C3274 2442FFFC */   addiu $v0, $v0, -4
/* 0E7C28 802C3278 3C02802E */  lui   $v0, 0x802e
/* 0E7C2C 802C327C 8C42A484 */  lw    $v0, -0x5b7c($v0)
/* 0E7C30 802C3280 2403000F */  addiu $v1, $zero, 0xf
/* 0E7C34 802C3284 3C01802E */  lui   $at, 0x802e
/* 0E7C38 802C3288 AC20A488 */  sw    $zero, -0x5b78($at)
/* 0E7C3C 802C328C 3C01802E */  lui   $at, 0x802e
/* 0E7C40 802C3290 AC20AC98 */  sw    $zero, -0x5368($at)
/* 0E7C44 802C3294 3C01802E */  lui   $at, 0x802e
/* 0E7C48 802C3298 AC209CA4 */  sw    $zero, -0x635c($at)
/* 0E7C4C 802C329C 2442003C */  addiu $v0, $v0, 0x3c
.L802C32A0:
/* 0E7C50 802C32A0 AC400000 */  sw    $zero, ($v0)
/* 0E7C54 802C32A4 2463FFFF */  addiu $v1, $v1, -1
/* 0E7C58 802C32A8 0461FFFD */  bgez  $v1, .L802C32A0
/* 0E7C5C 802C32AC 2442FFFC */   addiu $v0, $v0, -4
/* 0E7C60 802C32B0 3C02802E */  lui   $v0, 0x802e
/* 0E7C64 802C32B4 8C42A480 */  lw    $v0, -0x5b80($v0)
/* 0E7C68 802C32B8 24030002 */  addiu $v1, $zero, 2
/* 0E7C6C 802C32BC 24420008 */  addiu $v0, $v0, 8
.L802C32C0:
/* 0E7C70 802C32C0 AC400000 */  sw    $zero, ($v0)
/* 0E7C74 802C32C4 2463FFFF */  addiu $v1, $v1, -1
/* 0E7C78 802C32C8 0461FFFD */  bgez  $v1, .L802C32C0
/* 0E7C7C 802C32CC 2442FFFC */   addiu $v0, $v0, -4
/* 0E7C80 802C32D0 0C0B5122 */  jal   func_802D4488
/* 0E7C84 802C32D4 00000000 */   nop   
/* 0E7C88 802C32D8 0C0B352D */  jal   func_802CD4B4
/* 0E7C8C 802C32DC 00000000 */   nop   
/* 0E7C90 802C32E0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0E7C94 802C32E4 03E00008 */  jr    $ra
/* 0E7C98 802C32E8 27BD0018 */   addiu $sp, $sp, 0x18


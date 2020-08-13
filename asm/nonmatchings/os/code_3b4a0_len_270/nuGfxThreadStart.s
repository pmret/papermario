.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel nuGfxThreadStart
/* 03B5F0 800601F0 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 03B5F4 800601F4 AFB00018 */  sw    $s0, 0x18($sp)
/* 03B5F8 800601F8 3C10800B */  lui   $s0, 0x800b
/* 03B5FC 800601FC 26101B90 */  addiu $s0, $s0, 0x1b90
/* 03B600 80060200 0200202D */  daddu $a0, $s0, $zero
/* 03B604 80060204 3C02800B */  lui   $v0, 0x800b
/* 03B608 80060208 2442E6D0 */  addiu $v0, $v0, -0x1930
/* 03B60C 8006020C AFA20010 */  sw    $v0, 0x10($sp)
/* 03B610 80060210 24020032 */  addiu $v0, $zero, 0x32
/* 03B614 80060214 24050004 */  addiu $a1, $zero, 4
/* 03B618 80060218 3C068006 */  lui   $a2, 0x8006
/* 03B61C 8006021C 24C60248 */  addiu $a2, $a2, 0x248
/* 03B620 80060220 0000382D */  daddu $a3, $zero, $zero
/* 03B624 80060224 AFBF001C */  sw    $ra, 0x1c($sp)
/* 03B628 80060228 0C019798 */  jal   osCreateThread
/* 03B62C 8006022C AFA20014 */   sw    $v0, 0x14($sp)
/* 03B630 80060230 0C019808 */  jal   osStartThread
/* 03B634 80060234 0200202D */   daddu $a0, $s0, $zero
/* 03B638 80060238 8FBF001C */  lw    $ra, 0x1c($sp)
/* 03B63C 8006023C 8FB00018 */  lw    $s0, 0x18($sp)
/* 03B640 80060240 03E00008 */  jr    $ra
/* 03B644 80060244 27BD0020 */   addiu $sp, $sp, 0x20


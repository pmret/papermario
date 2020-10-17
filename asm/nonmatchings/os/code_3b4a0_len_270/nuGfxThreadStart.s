.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuGfxThreadStart
/* 3B5F0 800601F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3B5F4 800601F4 AFB00018 */  sw        $s0, 0x18($sp)
/* 3B5F8 800601F8 3C10800B */  lui       $s0, 0x800b
/* 3B5FC 800601FC 26101B90 */  addiu     $s0, $s0, 0x1b90
/* 3B600 80060200 0200202D */  daddu     $a0, $s0, $zero
/* 3B604 80060204 3C02800B */  lui       $v0, 0x800b
/* 3B608 80060208 2442E6D0 */  addiu     $v0, $v0, -0x1930
/* 3B60C 8006020C AFA20010 */  sw        $v0, 0x10($sp)
/* 3B610 80060210 24020032 */  addiu     $v0, $zero, 0x32
/* 3B614 80060214 24050004 */  addiu     $a1, $zero, 4
/* 3B618 80060218 3C068006 */  lui       $a2, %hi(nuGfxThread)
/* 3B61C 8006021C 24C60248 */  addiu     $a2, $a2, %lo(nuGfxThread)
/* 3B620 80060220 0000382D */  daddu     $a3, $zero, $zero
/* 3B624 80060224 AFBF001C */  sw        $ra, 0x1c($sp)
/* 3B628 80060228 0C019798 */  jal       osCreateThread
/* 3B62C 8006022C AFA20014 */   sw       $v0, 0x14($sp)
/* 3B630 80060230 0C019808 */  jal       osStartThread
/* 3B634 80060234 0200202D */   daddu    $a0, $s0, $zero
/* 3B638 80060238 8FBF001C */  lw        $ra, 0x1c($sp)
/* 3B63C 8006023C 8FB00018 */  lw        $s0, 0x18($sp)
/* 3B640 80060240 03E00008 */  jr        $ra
/* 3B644 80060244 27BD0020 */   addiu    $sp, $sp, 0x20

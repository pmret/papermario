.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel SetAnimModelRotation
/* 0F1BA0 802CD1F0 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F1BA4 802CD1F4 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F1BA8 802CD1F8 0080902D */  daddu $s2, $a0, $zero
/* 0F1BAC 802CD1FC AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F1BB0 802CD200 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F1BB4 802CD204 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F1BB8 802CD208 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0F1BBC 802CD20C F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F1BC0 802CD210 8E50000C */  lw    $s0, 0xc($s2)
/* 0F1BC4 802CD214 8E050000 */  lw    $a1, ($s0)
/* 0F1BC8 802CD218 0C0B1EAF */  jal   get_variable
/* 0F1BCC 802CD21C 26100004 */   addiu $s0, $s0, 4
/* 0F1BD0 802CD220 8E050000 */  lw    $a1, ($s0)
/* 0F1BD4 802CD224 26100004 */  addiu $s0, $s0, 4
/* 0F1BD8 802CD228 0240202D */  daddu $a0, $s2, $zero
/* 0F1BDC 802CD22C 0C0B210B */  jal   get_float_variable
/* 0F1BE0 802CD230 0040882D */   daddu $s1, $v0, $zero
/* 0F1BE4 802CD234 8E050000 */  lw    $a1, ($s0)
/* 0F1BE8 802CD238 26100004 */  addiu $s0, $s0, 4
/* 0F1BEC 802CD23C 0240202D */  daddu $a0, $s2, $zero
/* 0F1BF0 802CD240 0C0B210B */  jal   get_float_variable
/* 0F1BF4 802CD244 46000586 */   mov.s $f22, $f0
/* 0F1BF8 802CD248 0240202D */  daddu $a0, $s2, $zero
/* 0F1BFC 802CD24C 8E050000 */  lw    $a1, ($s0)
/* 0F1C00 802CD250 0C0B210B */  jal   get_float_variable
/* 0F1C04 802CD254 46000506 */   mov.s $f20, $f0
/* 0F1C08 802CD258 3C02802E */  lui   $v0, 0x802e
/* 0F1C0C 802CD25C 8C42AE30 */  lw    $v0, -0x51d0($v0)
/* 0F1C10 802CD260 00118880 */  sll   $s1, $s1, 2
/* 0F1C14 802CD264 02228821 */  addu  $s1, $s1, $v0
/* 0F1C18 802CD268 8E230000 */  lw    $v1, ($s1)
/* 0F1C1C 802CD26C E4760010 */  swc1  $f22, 0x10($v1)
/* 0F1C20 802CD270 E4740014 */  swc1  $f20, 0x14($v1)
/* 0F1C24 802CD274 E4600018 */  swc1  $f0, 0x18($v1)
/* 0F1C28 802CD278 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F1C2C 802CD27C 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F1C30 802CD280 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F1C34 802CD284 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F1C38 802CD288 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0F1C3C 802CD28C D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F1C40 802CD290 24020002 */  addiu $v0, $zero, 2
/* 0F1C44 802CD294 03E00008 */  jr    $ra
/* 0F1C48 802CD298 27BD0030 */   addiu $sp, $sp, 0x30


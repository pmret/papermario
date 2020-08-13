.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetObjRotation
/* 0F81F0 802D3840 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0F81F4 802D3844 AFB20018 */  sw    $s2, 0x18($sp)
/* 0F81F8 802D3848 0080902D */  daddu $s2, $a0, $zero
/* 0F81FC 802D384C AFBF001C */  sw    $ra, 0x1c($sp)
/* 0F8200 802D3850 AFB10014 */  sw    $s1, 0x14($sp)
/* 0F8204 802D3854 AFB00010 */  sw    $s0, 0x10($sp)
/* 0F8208 802D3858 F7B60028 */  sdc1  $f22, 0x28($sp)
/* 0F820C 802D385C F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0F8210 802D3860 8E50000C */  lw    $s0, 0xc($s2)
/* 0F8214 802D3864 8E050000 */  lw    $a1, ($s0)
/* 0F8218 802D3868 0C0B1EAF */  jal   get_variable
/* 0F821C 802D386C 26100004 */   addiu $s0, $s0, 4
/* 0F8220 802D3870 8E050000 */  lw    $a1, ($s0)
/* 0F8224 802D3874 26100004 */  addiu $s0, $s0, 4
/* 0F8228 802D3878 0240202D */  daddu $a0, $s2, $zero
/* 0F822C 802D387C 0C0B210B */  jal   get_float_variable
/* 0F8230 802D3880 0040882D */   daddu $s1, $v0, $zero
/* 0F8234 802D3884 8E050000 */  lw    $a1, ($s0)
/* 0F8238 802D3888 26100004 */  addiu $s0, $s0, 4
/* 0F823C 802D388C 0240202D */  daddu $a0, $s2, $zero
/* 0F8240 802D3890 0C0B210B */  jal   get_float_variable
/* 0F8244 802D3894 46000586 */   mov.s $f22, $f0
/* 0F8248 802D3898 0240202D */  daddu $a0, $s2, $zero
/* 0F824C 802D389C 8E050000 */  lw    $a1, ($s0)
/* 0F8250 802D38A0 0C0B210B */  jal   get_float_variable
/* 0F8254 802D38A4 46000506 */   mov.s $f20, $f0
/* 0F8258 802D38A8 3C02802E */  lui   $v0, 0x802e
/* 0F825C 802D38AC 8C42B7C0 */  lw    $v0, -0x4840($v0)
/* 0F8260 802D38B0 00118880 */  sll   $s1, $s1, 2
/* 0F8264 802D38B4 02228821 */  addu  $s1, $s1, $v0
/* 0F8268 802D38B8 8E230000 */  lw    $v1, ($s1)
/* 0F826C 802D38BC E4760010 */  swc1  $f22, 0x10($v1)
/* 0F8270 802D38C0 E4740014 */  swc1  $f20, 0x14($v1)
/* 0F8274 802D38C4 E4600018 */  swc1  $f0, 0x18($v1)
/* 0F8278 802D38C8 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0F827C 802D38CC 8FB20018 */  lw    $s2, 0x18($sp)
/* 0F8280 802D38D0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0F8284 802D38D4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0F8288 802D38D8 D7B60028 */  ldc1  $f22, 0x28($sp)
/* 0F828C 802D38DC D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0F8290 802D38E0 24020002 */  addiu $v0, $zero, 2
/* 0F8294 802D38E4 03E00008 */  jr    $ra
/* 0F8298 802D38E8 27BD0030 */   addiu $sp, $sp, 0x30


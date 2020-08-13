.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osContStartQuery
/* 03CD00 80061900 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 03CD04 80061904 AFB00010 */  sw    $s0, 0x10($sp)
/* 03CD08 80061908 AFBF0014 */  sw    $ra, 0x14($sp)
/* 03CD0C 8006190C 0C019771 */  jal   osSiGetAccess
/* 03CD10 80061910 00808021 */   addu  $s0, $a0, $zero
/* 03CD14 80061914 3C02800A */  lui   $v0, 0x800a
/* 03CD18 80061918 9042A61C */  lbu   $v0, -0x59e4($v0)
/* 03CD1C 8006191C 1040000B */  beqz  $v0, .L8006194C
/* 03CD20 80061920 00000000 */   nop   
/* 03CD24 80061924 0C018774 */  jal   osPackRequestData
/* 03CD28 80061928 00002021 */   addu  $a0, $zero, $zero
/* 03CD2C 8006192C 3C05800B */  lui   $a1, 0x800b
/* 03CD30 80061930 24A50ED0 */  addiu $a1, $a1, 0xed0
/* 03CD34 80061934 0C019730 */  jal   osSiRawStartDma
/* 03CD38 80061938 24040001 */   addiu $a0, $zero, 1
/* 03CD3C 8006193C 02002021 */  addu  $a0, $s0, $zero
/* 03CD40 80061940 00002821 */  addu  $a1, $zero, $zero
/* 03CD44 80061944 0C0195BC */  jal   osRecvMesg
/* 03CD48 80061948 24060001 */   addiu $a2, $zero, 1
.L8006194C:
/* 03CD4C 8006194C 3C05800B */  lui   $a1, 0x800b
/* 03CD50 80061950 24A50ED0 */  addiu $a1, $a1, 0xed0
/* 03CD54 80061954 0C019730 */  jal   osSiRawStartDma
/* 03CD58 80061958 00002021 */   addu  $a0, $zero, $zero
/* 03CD5C 8006195C 3C01800A */  lui   $at, 0x800a
/* 03CD60 80061960 A020A61C */  sb    $zero, -0x59e4($at)
/* 03CD64 80061964 0C01978C */  jal   osSiRelAccess
/* 03CD68 80061968 00408021 */   addu  $s0, $v0, $zero
/* 03CD6C 8006196C 02001021 */  addu  $v0, $s0, $zero
/* 03CD70 80061970 8FBF0014 */  lw    $ra, 0x14($sp)
/* 03CD74 80061974 8FB00010 */  lw    $s0, 0x10($sp)
/* 03CD78 80061978 03E00008 */  jr    $ra
/* 03CD7C 8006197C 27BD0018 */   addiu $sp, $sp, 0x18


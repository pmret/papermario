.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8024D890
/* 140BD0 8024D890 3C063F80 */  lui   $a2, 0x3f80
/* 140BD4 8024D894 0C0B78AB */  jal   func_802DE2AC
/* 140BD8 8024D898 26310010 */   addiu $s1, $s1, 0x10
/* 140BDC 8024D89C 3C028027 */  lui   $v0, 0x8027
/* 140BE0 8024D8A0 8C4206FC */  lw    $v0, 0x6fc($v0)
/* 140BE4 8024D8A4 26520001 */  addiu $s2, $s2, 1
/* 140BE8 8024D8A8 0242102A */  slt   $v0, $s2, $v0
/* 140BEC 8024D8AC 1440FFE8 */  bnez  $v0, .L8024D850
/* 140BF0 8024D8B0 26100004 */   addiu $s0, $s0, 4
.L8024D8B4:
/* 140BF4 8024D8B4 8FBF0028 */  lw    $ra, 0x28($sp)
/* 140BF8 8024D8B8 8FB50024 */  lw    $s5, 0x24($sp)
/* 140BFC 8024D8BC 8FB40020 */  lw    $s4, 0x20($sp)
/* 140C00 8024D8C0 8FB3001C */  lw    $s3, 0x1c($sp)
/* 140C04 8024D8C4 8FB20018 */  lw    $s2, 0x18($sp)
/* 140C08 8024D8C8 8FB10014 */  lw    $s1, 0x14($sp)
/* 140C0C 8024D8CC 8FB00010 */  lw    $s0, 0x10($sp)
/* 140C10 8024D8D0 03E00008 */  jr    $ra
/* 140C14 8024D8D4 27BD0030 */   addiu $sp, $sp, 0x30

/* 140C18 8024D8D8 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 140C1C 8024D8DC AFB10014 */  sw    $s1, 0x14($sp)
/* 140C20 8024D8E0 0000882D */  daddu $s1, $zero, $zero
/* 140C24 8024D8E4 AFB00010 */  sw    $s0, 0x10($sp)
/* 140C28 8024D8E8 3C108027 */  lui   $s0, 0x8027
/* 140C2C 8024D8EC 261006C0 */  addiu $s0, $s0, 0x6c0
/* 140C30 8024D8F0 AFBF0018 */  sw    $ra, 0x18($sp)
.L8024D8F4:
/* 140C34 8024D8F4 8E040000 */  lw    $a0, ($s0)
/* 140C38 8024D8F8 26100004 */  addiu $s0, $s0, 4
/* 140C3C 8024D8FC 0C0B797A */  jal   func_802DE5E8
/* 140C40 8024D900 26310001 */   addiu $s1, $s1, 1
/* 140C44 8024D904 2A220007 */  slti  $v0, $s1, 7
/* 140C48 8024D908 1440FFFA */  bnez  $v0, .L8024D8F4
/* 140C4C 8024D90C 00000000 */   nop   
/* 140C50 8024D910 8FBF0018 */  lw    $ra, 0x18($sp)
/* 140C54 8024D914 8FB10014 */  lw    $s1, 0x14($sp)
/* 140C58 8024D918 8FB00010 */  lw    $s0, 0x10($sp)
/* 140C5C 8024D91C 03E00008 */  jr    $ra
/* 140C60 8024D920 27BD0020 */   addiu $sp, $sp, 0x20

/* 140C64 8024D924 00000000 */  nop   
/* 140C68 8024D928 00000000 */  nop   
/* 140C6C 8024D92C 00000000 */  nop   
/* 140C70 8024D930 0000582D */  daddu $t3, $zero, $zero
/* 140C74 8024D934 0160502D */  daddu $t2, $t3, $zero
/* 140C78 8024D938 3C058025 */  lui   $a1, 0x8025
/* 140C7C 8024D93C 24A502B8 */  addiu $a1, $a1, 0x2b8

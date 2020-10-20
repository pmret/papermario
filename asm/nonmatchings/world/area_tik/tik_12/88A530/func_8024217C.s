.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024217C
/* 88AD4C 8024217C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 88AD50 80242180 AFBF0010 */  sw        $ra, 0x10($sp)
/* 88AD54 80242184 0C00EAD2 */  jal       get_npc_safe
/* 88AD58 80242188 8C84014C */   lw       $a0, 0x14c($a0)
/* 88AD5C 8024218C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 88AD60 80242190 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 88AD64 80242194 C44C0038 */  lwc1      $f12, 0x38($v0)
/* 88AD68 80242198 C44E0040 */  lwc1      $f14, 0x40($v0)
/* 88AD6C 8024219C 8C660028 */  lw        $a2, 0x28($v1)
/* 88AD70 802421A0 0C00A7B5 */  jal       dist2D
/* 88AD74 802421A4 8C670030 */   lw       $a3, 0x30($v1)
/* 88AD78 802421A8 3C014248 */  lui       $at, 0x4248
/* 88AD7C 802421AC 44811000 */  mtc1      $at, $f2
/* 88AD80 802421B0 00000000 */  nop       
/* 88AD84 802421B4 4602003C */  c.lt.s    $f0, $f2
/* 88AD88 802421B8 00000000 */  nop       
/* 88AD8C 802421BC 45010002 */  bc1t      .L802421C8
/* 88AD90 802421C0 24020002 */   addiu    $v0, $zero, 2
/* 88AD94 802421C4 0000102D */  daddu     $v0, $zero, $zero
.L802421C8:
/* 88AD98 802421C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 88AD9C 802421CC 03E00008 */  jr        $ra
/* 88ADA0 802421D0 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002AD70
/* 6170 8002AD70 3C028007 */  lui       $v0, %hi(D_8007417C)
/* 6174 8002AD74 8C42417C */  lw        $v0, %lo(D_8007417C)($v0)
/* 6178 8002AD78 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 617C 8002AD7C AFBF0010 */  sw        $ra, 0x10($sp)
/* 6180 8002AD80 80420070 */  lb        $v0, 0x70($v0)
/* 6184 8002AD84 0080282D */  daddu     $a1, $a0, $zero
/* 6188 8002AD88 3C048027 */  lui       $a0, %hi(D_80268000)
/* 618C 8002AD8C 24848000 */  addiu     $a0, $a0, %lo(D_80268000)
/* 6190 8002AD90 10400003 */  beqz      $v0, .L8002ADA0
/* 6194 8002AD94 00000000 */   nop
/* 6198 8002AD98 3C04803E */  lui       $a0, %hi(D_803DA800)
/* 619C 8002AD9C 2484A800 */  addiu     $a0, $a0, %lo(D_803DA800)
.L8002ADA0:
/* 61A0 8002ADA0 0C00A40B */  jal       func_8002902C
/* 61A4 8002ADA4 00000000 */   nop
/* 61A8 8002ADA8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 61AC 8002ADAC 03E00008 */  jr        $ra
/* 61B0 8002ADB0 27BD0018 */   addiu    $sp, $sp, 0x18

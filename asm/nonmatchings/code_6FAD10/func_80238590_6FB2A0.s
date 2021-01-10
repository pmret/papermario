.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238590_6FB2A0
/* 6FB2A0 80238590 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6FB2A4 80238594 AFB10014 */  sw        $s1, 0x14($sp)
/* 6FB2A8 80238598 0080882D */  daddu     $s1, $a0, $zero
/* 6FB2AC 8023859C AFBF0018 */  sw        $ra, 0x18($sp)
/* 6FB2B0 802385A0 AFB00010 */  sw        $s0, 0x10($sp)
/* 6FB2B4 802385A4 8E22000C */  lw        $v0, 0xc($s1)
/* 6FB2B8 802385A8 8C450000 */  lw        $a1, ($v0)
/* 6FB2BC 802385AC 3C10800E */  lui       $s0, %hi(gBattleStatus+0xDC)
/* 6FB2C0 802385B0 8E10C14C */  lw        $s0, %lo(gBattleStatus+0xDC)($s0)
/* 6FB2C4 802385B4 0C0B1EAF */  jal       get_variable
/* 6FB2C8 802385B8 00000000 */   nop      
/* 6FB2CC 802385BC 8E030008 */  lw        $v1, 8($s0)
/* 6FB2D0 802385C0 0040282D */  daddu     $a1, $v0, $zero
/* 6FB2D4 802385C4 90630006 */  lbu       $v1, 6($v1)
/* 6FB2D8 802385C8 24020002 */  addiu     $v0, $zero, 2
/* 6FB2DC 802385CC 1462000E */  bne       $v1, $v0, .L80238608
/* 6FB2E0 802385D0 0000202D */   daddu    $a0, $zero, $zero
/* 6FB2E4 802385D4 28A20024 */  slti      $v0, $a1, 0x24
/* 6FB2E8 802385D8 1440000B */  bnez      $v0, .L80238608
/* 6FB2EC 802385DC 24040001 */   addiu    $a0, $zero, 1
/* 6FB2F0 802385E0 28A2003D */  slti      $v0, $a1, 0x3d
/* 6FB2F4 802385E4 14400008 */  bnez      $v0, .L80238608
/* 6FB2F8 802385E8 24040003 */   addiu    $a0, $zero, 3
/* 6FB2FC 802385EC 28A20051 */  slti      $v0, $a1, 0x51
/* 6FB300 802385F0 14400005 */  bnez      $v0, .L80238608
/* 6FB304 802385F4 24040005 */   addiu    $a0, $zero, 5
/* 6FB308 802385F8 28A20064 */  slti      $v0, $a1, 0x64
/* 6FB30C 802385FC 10400003 */  beqz      $v0, .L8023860C
/* 6FB310 80238600 24040007 */   addiu    $a0, $zero, 7
/* 6FB314 80238604 24040006 */  addiu     $a0, $zero, 6
.L80238608:
/* 6FB318 80238608 28A20064 */  slti      $v0, $a1, 0x64
.L8023860C:
/* 6FB31C 8023860C 54400003 */  bnel      $v0, $zero, .L8023861C
/* 6FB320 80238610 AE200084 */   sw       $zero, 0x84($s1)
/* 6FB324 80238614 24020001 */  addiu     $v0, $zero, 1
/* 6FB328 80238618 AE220084 */  sw        $v0, 0x84($s1)
.L8023861C:
/* 6FB32C 8023861C AE2400C0 */  sw        $a0, 0xc0($s1)
/* 6FB330 80238620 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6FB334 80238624 8FB10014 */  lw        $s1, 0x14($sp)
/* 6FB338 80238628 8FB00010 */  lw        $s0, 0x10($sp)
/* 6FB33C 8023862C 24020002 */  addiu     $v0, $zero, 2
/* 6FB340 80238630 03E00008 */  jr        $ra
/* 6FB344 80238634 27BD0020 */   addiu    $sp, $sp, 0x20
/* 6FB348 80238638 00000000 */  nop       
/* 6FB34C 8023863C 00000000 */  nop       

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409EC_969BAC
/* 969BAC 802409EC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 969BB0 802409F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 969BB4 802409F4 3C108011 */  lui       $s0, %hi(gPlayerData)
/* 969BB8 802409F8 2610F290 */  addiu     $s0, $s0, %lo(gPlayerData)
/* 969BBC 802409FC AFBF0018 */  sw        $ra, 0x18($sp)
/* 969BC0 80240A00 AFB10014 */  sw        $s1, 0x14($sp)
/* 969BC4 80240A04 960302C0 */  lhu       $v1, 0x2c0($s0)
/* 969BC8 80240A08 2C6203E7 */  sltiu     $v0, $v1, 0x3e7
/* 969BCC 80240A0C 10400003 */  beqz      $v0, .L80240A1C
/* 969BD0 80240A10 0080882D */   daddu    $s1, $a0, $zero
/* 969BD4 80240A14 24620001 */  addiu     $v0, $v1, 1
/* 969BD8 80240A18 A60202C0 */  sh        $v0, 0x2c0($s0)
.L80240A1C:
/* 969BDC 80240A1C 3C05F5DE */  lui       $a1, 0xf5de
/* 969BE0 80240A20 34A502E0 */  ori       $a1, $a1, 0x2e0
/* 969BE4 80240A24 0C0B1EAF */  jal       get_variable
/* 969BE8 80240A28 0000202D */   daddu    $a0, $zero, $zero
/* 969BEC 80240A2C 3C038024 */  lui       $v1, 0x8024
/* 969BF0 80240A30 00621821 */  addu      $v1, $v1, $v0
/* 969BF4 80240A34 90634E44 */  lbu       $v1, 0x4e44($v1)
/* 969BF8 80240A38 8E220084 */  lw        $v0, 0x84($s1)
/* 969BFC 80240A3C 54430006 */  bnel      $v0, $v1, .L80240A58
/* 969C00 80240A40 AE200084 */   sw       $zero, 0x84($s1)
/* 969C04 80240A44 24020001 */  addiu     $v0, $zero, 1
/* 969C08 80240A48 AE220084 */  sw        $v0, 0x84($s1)
/* 969C0C 80240A4C 960202C2 */  lhu       $v0, 0x2c2($s0)
/* 969C10 80240A50 24420001 */  addiu     $v0, $v0, 1
/* 969C14 80240A54 A60202C2 */  sh        $v0, 0x2c2($s0)
.L80240A58:
/* 969C18 80240A58 8FBF0018 */  lw        $ra, 0x18($sp)
/* 969C1C 80240A5C 8FB10014 */  lw        $s1, 0x14($sp)
/* 969C20 80240A60 8FB00010 */  lw        $s0, 0x10($sp)
/* 969C24 80240A64 24020002 */  addiu     $v0, $zero, 2
/* 969C28 80240A68 03E00008 */  jr        $ra
/* 969C2C 80240A6C 27BD0020 */   addiu    $sp, $sp, 0x20

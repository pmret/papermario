.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A04_91C2E4
/* 91C2E4 80240A04 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91C2E8 80240A08 AFB20018 */  sw        $s2, 0x18($sp)
/* 91C2EC 80240A0C 0080902D */  daddu     $s2, $a0, $zero
/* 91C2F0 80240A10 AFBF001C */  sw        $ra, 0x1c($sp)
/* 91C2F4 80240A14 AFB10014 */  sw        $s1, 0x14($sp)
/* 91C2F8 80240A18 AFB00010 */  sw        $s0, 0x10($sp)
/* 91C2FC 80240A1C 8E500148 */  lw        $s0, 0x148($s2)
/* 91C300 80240A20 86040008 */  lh        $a0, 8($s0)
/* 91C304 80240A24 0C00EABB */  jal       get_npc_unsafe
/* 91C308 80240A28 00A0882D */   daddu    $s1, $a1, $zero
/* 91C30C 80240A2C 0040182D */  daddu     $v1, $v0, $zero
/* 91C310 80240A30 9462008E */  lhu       $v0, 0x8e($v1)
/* 91C314 80240A34 2442FFFF */  addiu     $v0, $v0, -1
/* 91C318 80240A38 A462008E */  sh        $v0, 0x8e($v1)
/* 91C31C 80240A3C 00021400 */  sll       $v0, $v0, 0x10
/* 91C320 80240A40 1C400015 */  bgtz      $v0, .L80240A98
/* 91C324 80240A44 00000000 */   nop      
/* 91C328 80240A48 8E0200CC */  lw        $v0, 0xcc($s0)
/* 91C32C 80240A4C 8C420004 */  lw        $v0, 4($v0)
/* 91C330 80240A50 AC620028 */  sw        $v0, 0x28($v1)
/* 91C334 80240A54 8E0200D0 */  lw        $v0, 0xd0($s0)
/* 91C338 80240A58 8C420014 */  lw        $v0, 0x14($v0)
/* 91C33C 80240A5C 04410004 */  bgez      $v0, .L80240A70
/* 91C340 80240A60 00000000 */   nop      
/* 91C344 80240A64 C6200000 */  lwc1      $f0, ($s1)
/* 91C348 80240A68 080902A4 */  j         .L80240A90
/* 91C34C 80240A6C E4600018 */   swc1     $f0, 0x18($v1)
.L80240A70:
/* 91C350 80240A70 3C018024 */  lui       $at, %hi(update_end_player_turn)
/* 91C354 80240A74 D4222BB0 */  ldc1      $f2, %lo(update_end_player_turn)($at)
/* 91C358 80240A78 44820000 */  mtc1      $v0, $f0
/* 91C35C 80240A7C 00000000 */  nop       
/* 91C360 80240A80 46800021 */  cvt.d.w   $f0, $f0
/* 91C364 80240A84 46220003 */  div.d     $f0, $f0, $f2
/* 91C368 80240A88 46200020 */  cvt.s.d   $f0, $f0
/* 91C36C 80240A8C E4600018 */  swc1      $f0, 0x18($v1)
.L80240A90:
/* 91C370 80240A90 24020029 */  addiu     $v0, $zero, 0x29
/* 91C374 80240A94 AE420070 */  sw        $v0, 0x70($s2)
.L80240A98:
/* 91C378 80240A98 8FBF001C */  lw        $ra, 0x1c($sp)
/* 91C37C 80240A9C 8FB20018 */  lw        $s2, 0x18($sp)
/* 91C380 80240AA0 8FB10014 */  lw        $s1, 0x14($sp)
/* 91C384 80240AA4 8FB00010 */  lw        $s0, 0x10($sp)
/* 91C388 80240AA8 03E00008 */  jr        $ra
/* 91C38C 80240AAC 27BD0020 */   addiu    $sp, $sp, 0x20

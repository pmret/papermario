.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242FDC_7EDCEC
/* 7EDCEC 80242FDC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7EDCF0 80242FE0 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EDCF4 80242FE4 0080882D */  daddu     $s1, $a0, $zero
/* 7EDCF8 80242FE8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7EDCFC 80242FEC AFB00010 */  sw        $s0, 0x10($sp)
/* 7EDD00 80242FF0 8E300148 */  lw        $s0, 0x148($s1)
/* 7EDD04 80242FF4 0C00EABB */  jal       get_npc_unsafe
/* 7EDD08 80242FF8 86040008 */   lh       $a0, 8($s0)
/* 7EDD0C 80242FFC 9443008E */  lhu       $v1, 0x8e($v0)
/* 7EDD10 80243000 2463FFFF */  addiu     $v1, $v1, -1
/* 7EDD14 80243004 A443008E */  sh        $v1, 0x8e($v0)
/* 7EDD18 80243008 00031C00 */  sll       $v1, $v1, 0x10
/* 7EDD1C 8024300C 14600008 */  bnez      $v1, .L80243030
/* 7EDD20 80243010 00000000 */   nop      
/* 7EDD24 80243014 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 7EDD28 80243018 30420080 */  andi      $v0, $v0, 0x80
/* 7EDD2C 8024301C 10400003 */  beqz      $v0, .L8024302C
/* 7EDD30 80243020 2402000F */   addiu    $v0, $zero, 0xf
/* 7EDD34 80243024 08090C0C */  j         .L80243030
/* 7EDD38 80243028 AE220070 */   sw       $v0, 0x70($s1)
.L8024302C:
/* 7EDD3C 8024302C AE200070 */  sw        $zero, 0x70($s1)
.L80243030:
/* 7EDD40 80243030 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7EDD44 80243034 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EDD48 80243038 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EDD4C 8024303C 03E00008 */  jr        $ra
/* 7EDD50 80243040 27BD0020 */   addiu    $sp, $sp, 0x20

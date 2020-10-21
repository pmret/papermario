.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80245FBC_80683C
/* 80683C 80245FBC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 806840 80245FC0 AFB10014 */  sw        $s1, 0x14($sp)
/* 806844 80245FC4 0080882D */  daddu     $s1, $a0, $zero
/* 806848 80245FC8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 80684C 80245FCC AFB00010 */  sw        $s0, 0x10($sp)
/* 806850 80245FD0 8E300148 */  lw        $s0, 0x148($s1)
/* 806854 80245FD4 0C00EABB */  jal       get_npc_unsafe
/* 806858 80245FD8 86040008 */   lh       $a0, 8($s0)
/* 80685C 80245FDC 9443008E */  lhu       $v1, 0x8e($v0)
/* 806860 80245FE0 2463FFFF */  addiu     $v1, $v1, -1
/* 806864 80245FE4 A443008E */  sh        $v1, 0x8e($v0)
/* 806868 80245FE8 00031C00 */  sll       $v1, $v1, 0x10
/* 80686C 80245FEC 14600008 */  bnez      $v1, .L80246010
/* 806870 80245FF0 00000000 */   nop      
/* 806874 80245FF4 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 806878 80245FF8 30420080 */  andi      $v0, $v0, 0x80
/* 80687C 80245FFC 10400003 */  beqz      $v0, .L8024600C
/* 806880 80246000 2402000F */   addiu    $v0, $zero, 0xf
/* 806884 80246004 08091804 */  j         .L80246010
/* 806888 80246008 AE220070 */   sw       $v0, 0x70($s1)
.L8024600C:
/* 80688C 8024600C AE200070 */  sw        $zero, 0x70($s1)
.L80246010:
/* 806890 80246010 8FBF0018 */  lw        $ra, 0x18($sp)
/* 806894 80246014 8FB10014 */  lw        $s1, 0x14($sp)
/* 806898 80246018 8FB00010 */  lw        $s0, 0x10($sp)
/* 80689C 8024601C 03E00008 */  jr        $ra
/* 8068A0 80246020 27BD0020 */   addiu    $sp, $sp, 0x20

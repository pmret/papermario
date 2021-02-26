.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002B334
/* 6734 8002B334 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6738 8002B338 AFB20018 */  sw        $s2, 0x18($sp)
/* 673C 8002B33C 0080902D */  daddu     $s2, $a0, $zero
/* 6740 8002B340 AFBF001C */  sw        $ra, 0x1c($sp)
/* 6744 8002B344 AFB10014 */  sw        $s1, 0x14($sp)
/* 6748 8002B348 0C00AC45 */  jal       func_8002B114
/* 674C 8002B34C AFB00010 */   sw       $s0, 0x10($sp)
/* 6750 8002B350 3C118007 */  lui       $s1, %hi(D_8007417C)
/* 6754 8002B354 2631417C */  addiu     $s1, $s1, %lo(D_8007417C)
/* 6758 8002B358 8E220000 */  lw        $v0, ($s1)
/* 675C 8002B35C 0C00AD7C */  jal       func_8002B5F0
/* 6760 8002B360 A0520166 */   sb       $s2, 0x166($v0)
/* 6764 8002B364 3C10800E */  lui       $s0, %hi(D_800DACA0)
/* 6768 8002B368 2610ACA0 */  addiu     $s0, $s0, %lo(D_800DACA0)
/* 676C 8002B36C 3C058007 */  lui       $a1, %hi(D_800745B0)
/* 6770 8002B370 24A545B0 */  addiu     $a1, $a1, %lo(D_800745B0)
/* 6774 8002B374 0C01BB48 */  jal       func_8006ED20
/* 6778 8002B378 0200202D */   daddu    $a0, $s0, $zero
/* 677C 8002B37C 8E230000 */  lw        $v1, ($s1)
/* 6780 8002B380 AE120038 */  sw        $s2, 0x38($s0)
/* 6784 8002B384 8C620168 */  lw        $v0, 0x168($v1)
/* 6788 8002B388 0200202D */  daddu     $a0, $s0, $zero
/* 678C 8002B38C 24420001 */  addiu     $v0, $v0, 1
/* 6790 8002B390 AC620168 */  sw        $v0, 0x168($v1)
/* 6794 8002B394 AE02003C */  sw        $v0, 0x3c($s0)
/* 6798 8002B398 2402FFFF */  addiu     $v0, $zero, -1
/* 679C 8002B39C AE000030 */  sw        $zero, 0x30($s0)
/* 67A0 8002B3A0 0C00AC24 */  jal       func_8002B090
/* 67A4 8002B3A4 AE020034 */   sw       $v0, 0x34($s0)
/* 67A8 8002B3A8 3C11800A */  lui       $s1, %hi(D_8009BA60)
/* 67AC 8002B3AC 2631BA60 */  addiu     $s1, $s1, %lo(D_8009BA60)
/* 67B0 8002B3B0 8E240000 */  lw        $a0, ($s1)
/* 67B4 8002B3B4 AE020030 */  sw        $v0, 0x30($s0)
/* 67B8 8002B3B8 00021027 */  nor       $v0, $zero, $v0
/* 67BC 8002B3BC 0C00AE77 */  jal       func_8002B9DC
/* 67C0 8002B3C0 AE020034 */   sw       $v0, 0x34($s0)
/* 67C4 8002B3C4 0200282D */  daddu     $a1, $s0, $zero
/* 67C8 8002B3C8 8E240000 */  lw        $a0, ($s1)
/* 67CC 8002B3CC 0C00AE42 */  jal       func_8002B908
/* 67D0 8002B3D0 24061380 */   addiu    $a2, $zero, 0x1380
/* 67D4 8002B3D4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 67D8 8002B3D8 8FB20018 */  lw        $s2, 0x18($sp)
/* 67DC 8002B3DC 8FB10014 */  lw        $s1, 0x14($sp)
/* 67E0 8002B3E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 67E4 8002B3E4 03E00008 */  jr        $ra
/* 67E8 8002B3E8 27BD0020 */   addiu    $sp, $sp, 0x20

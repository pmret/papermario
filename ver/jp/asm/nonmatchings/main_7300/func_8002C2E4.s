.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002C2E4
/* 76E4 8002C2E4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 76E8 8002C2E8 AFB10014 */  sw        $s1, 0x14($sp)
/* 76EC 8002C2EC 0080882D */  daddu     $s1, $a0, $zero
/* 76F0 8002C2F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 76F4 8002C2F4 3C100002 */  lui       $s0, 2
/* 76F8 8002C2F8 2404001E */  addiu     $a0, $zero, 0x1e
/* 76FC 8002C2FC 2405009B */  addiu     $a1, $zero, 0x9b
/* 7700 8002C300 3C06800A */  lui       $a2, %hi(D_80098030)
/* 7704 8002C304 24C68030 */  addiu     $a2, $a2, %lo(D_80098030)
/* 7708 8002C308 AFBF0018 */  sw        $ra, 0x18($sp)
/* 770C 8002C30C 0C00B072 */  jal       func_8002C1C8
/* 7710 8002C310 0220382D */   daddu    $a3, $s1, $zero
/* 7714 8002C314 0000182D */  daddu     $v1, $zero, $zero
/* 7718 8002C318 3C078007 */  lui       $a3, %hi(D_800773B8)
/* 771C 8002C31C 24E773B8 */  addiu     $a3, $a3, %lo(D_800773B8)
.L8002C320:
/* 7720 8002C320 02301024 */  and       $v0, $s1, $s0
/* 7724 8002C324 50400009 */  beql      $v0, $zero, .L8002C34C
/* 7728 8002C328 24E70004 */   addiu    $a3, $a3, 4
/* 772C 8002C32C 24040084 */  addiu     $a0, $zero, 0x84
/* 7730 8002C330 8CE70000 */  lw        $a3, ($a3)
/* 7734 8002C334 3C06800A */  lui       $a2, %hi(D_8009803C)
/* 7738 8002C338 24C6803C */  addiu     $a2, $a2, %lo(D_8009803C)
/* 773C 8002C33C 0C00B072 */  jal       func_8002C1C8
/* 7740 8002C340 2405009B */   addiu    $a1, $zero, 0x9b
/* 7744 8002C344 0800B0D7 */  j         .L8002C35C
/* 7748 8002C348 00000000 */   nop
.L8002C34C:
/* 774C 8002C34C 24630001 */  addiu     $v1, $v1, 1
/* 7750 8002C350 28620006 */  slti      $v0, $v1, 6
/* 7754 8002C354 1440FFF2 */  bnez      $v0, .L8002C320
/* 7758 8002C358 00108042 */   srl      $s0, $s0, 1
.L8002C35C:
/* 775C 8002C35C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7760 8002C360 8FB10014 */  lw        $s1, 0x14($sp)
/* 7764 8002C364 8FB00010 */  lw        $s0, 0x10($sp)
/* 7768 8002C368 03E00008 */  jr        $ra
/* 776C 8002C36C 27BD0020 */   addiu    $sp, $sp, 0x20

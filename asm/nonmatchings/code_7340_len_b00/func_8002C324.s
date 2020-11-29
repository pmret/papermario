.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002C324
/* 7724 8002C324 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7728 8002C328 AFB10014 */  sw        $s1, 0x14($sp)
/* 772C 8002C32C 0080882D */  daddu     $s1, $a0, $zero
/* 7730 8002C330 AFB00010 */  sw        $s0, 0x10($sp)
/* 7734 8002C334 3C100002 */  lui       $s0, 2
/* 7738 8002C338 2404001E */  addiu     $a0, $zero, 0x1e
/* 773C 8002C33C 2405009B */  addiu     $a1, $zero, 0x9b
/* 7740 8002C340 3C06800A */  lui       $a2, %hi(D_80098050)
/* 7744 8002C344 24C68050 */  addiu     $a2, $a2, %lo(D_80098050)
/* 7748 8002C348 AFBF0018 */  sw        $ra, 0x18($sp)
/* 774C 8002C34C 0C00B082 */  jal       crash_printf_string
/* 7750 8002C350 0220382D */   daddu    $a3, $s1, $zero
/* 7754 8002C354 0000182D */  daddu     $v1, $zero, $zero
/* 7758 8002C358 3C078007 */  lui       $a3, %hi(D_800773D8)
/* 775C 8002C35C 24E773D8 */  addiu     $a3, $a3, %lo(D_800773D8)
.L8002C360:
/* 7760 8002C360 02301024 */  and       $v0, $s1, $s0
/* 7764 8002C364 50400009 */  beql      $v0, $zero, .L8002C38C
/* 7768 8002C368 24E70004 */   addiu    $a3, $a3, 4
/* 776C 8002C36C 24040084 */  addiu     $a0, $zero, 0x84
/* 7770 8002C370 8CE70000 */  lw        $a3, ($a3)
/* 7774 8002C374 3C06800A */  lui       $a2, %hi(D_8009805C)
/* 7778 8002C378 24C6805C */  addiu     $a2, $a2, %lo(D_8009805C)
/* 777C 8002C37C 0C00B082 */  jal       crash_printf_string
/* 7780 8002C380 2405009B */   addiu    $a1, $zero, 0x9b
/* 7784 8002C384 0800B0E7 */  j         .L8002C39C
/* 7788 8002C388 00000000 */   nop      
.L8002C38C:
/* 778C 8002C38C 24630001 */  addiu     $v1, $v1, 1
/* 7790 8002C390 28620006 */  slti      $v0, $v1, 6
/* 7794 8002C394 1440FFF2 */  bnez      $v0, .L8002C360
/* 7798 8002C398 00108042 */   srl      $s0, $s0, 1
.L8002C39C:
/* 779C 8002C39C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 77A0 8002C3A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 77A4 8002C3A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 77A8 8002C3A8 03E00008 */  jr        $ra
/* 77AC 8002C3AC 27BD0020 */   addiu    $sp, $sp, 0x20

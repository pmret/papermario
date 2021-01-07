.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218FAC_5B245C
/* 5B245C 80218FAC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 5B2460 80218FB0 AFB10014 */  sw        $s1, 0x14($sp)
/* 5B2464 80218FB4 0080882D */  daddu     $s1, $a0, $zero
/* 5B2468 80218FB8 AFB20018 */  sw        $s2, 0x18($sp)
/* 5B246C 80218FBC 3C128011 */  lui       $s2, %hi(gPlayerData)
/* 5B2470 80218FC0 2652F290 */  addiu     $s2, $s2, %lo(gPlayerData)
/* 5B2474 80218FC4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 5B2478 80218FC8 AFB00010 */  sw        $s0, 0x10($sp)
/* 5B247C 80218FCC 8E30000C */  lw        $s0, 0xc($s1)
/* 5B2480 80218FD0 82460000 */  lb        $a2, ($s2)
/* 5B2484 80218FD4 8E050000 */  lw        $a1, ($s0)
/* 5B2488 80218FD8 0C0B2026 */  jal       set_variable
/* 5B248C 80218FDC 26100004 */   addiu    $s0, $s0, 4
/* 5B2490 80218FE0 8E050000 */  lw        $a1, ($s0)
/* 5B2494 80218FE4 82460001 */  lb        $a2, 1($s2)
/* 5B2498 80218FE8 0C0B2026 */  jal       set_variable
/* 5B249C 80218FEC 0220202D */   daddu    $a0, $s1, $zero
/* 5B24A0 80218FF0 8FBF001C */  lw        $ra, 0x1c($sp)
/* 5B24A4 80218FF4 8FB20018 */  lw        $s2, 0x18($sp)
/* 5B24A8 80218FF8 8FB10014 */  lw        $s1, 0x14($sp)
/* 5B24AC 80218FFC 8FB00010 */  lw        $s0, 0x10($sp)
/* 5B24B0 80219000 24020002 */  addiu     $v0, $zero, 2
/* 5B24B4 80219004 03E00008 */  jr        $ra
/* 5B24B8 80219008 27BD0020 */   addiu    $sp, $sp, 0x20

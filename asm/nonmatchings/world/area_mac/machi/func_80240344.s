.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240344
/* 7E76E4 80240344 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E76E8 80240348 2405000B */  addiu     $a1, $zero, 0xb
/* 7E76EC 8024034C 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 7E76F0 80240350 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 7E76F4 80240354 24440058 */  addiu     $a0, $v0, 0x58
/* 7E76F8 80240358 24030005 */  addiu     $v1, $zero, 5
/* 7E76FC 8024035C AFBF0010 */  sw        $ra, 0x10($sp)
/* 7E7700 80240360 A0430002 */  sb        $v1, 2($v0)
/* 7E7704 80240364 A0430003 */  sb        $v1, 3($v0)
/* 7E7708 80240368 2403FFFF */  addiu     $v1, $zero, -1
/* 7E770C 8024036C A0400000 */  sb        $zero, ($v0)
/* 7E7710 80240370 A0430001 */  sb        $v1, 1($v0)
/* 7E7714 80240374 A040000E */  sb        $zero, 0xe($v0)
.L80240378:
/* 7E7718 80240378 A0800014 */  sb        $zero, 0x14($a0)
/* 7E771C 8024037C 24A5FFFF */  addiu     $a1, $a1, -1
/* 7E7720 80240380 04A1FFFD */  bgez      $a1, .L80240378
/* 7E7724 80240384 2484FFF8 */   addiu    $a0, $a0, -8
/* 7E7728 80240388 0C03AC5A */  jal       func_800EB168
/* 7E772C 8024038C 0000202D */   daddu    $a0, $zero, $zero
/* 7E7730 80240390 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7E7734 80240394 24020002 */  addiu     $v0, $zero, 2
/* 7E7738 80240398 03E00008 */  jr        $ra
/* 7E773C 8024039C 27BD0018 */   addiu    $sp, $sp, 0x18

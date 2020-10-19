.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240624_CD2454
/* CD2454 80240624 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CD2458 80240628 AFBF0018 */  sw        $ra, 0x18($sp)
/* CD245C 8024062C 8C82000C */  lw        $v0, 0xc($a0)
/* CD2460 80240630 0C0B1EAF */  jal       get_variable
/* CD2464 80240634 8C450000 */   lw       $a1, ($v0)
/* CD2468 80240638 0C04417A */  jal       get_entity_by_index
/* CD246C 8024063C 0040202D */   daddu    $a0, $v0, $zero
/* CD2470 80240640 3C013F80 */  lui       $at, 0x3f80
/* CD2474 80240644 44810000 */  mtc1      $at, $f0
/* CD2478 80240648 C442004C */  lwc1      $f2, 0x4c($v0)
/* CD247C 8024064C E7A00010 */  swc1      $f0, 0x10($sp)
/* CD2480 80240650 3C014148 */  lui       $at, 0x4148
/* CD2484 80240654 44810000 */  mtc1      $at, $f0
/* CD2488 80240658 2403004B */  addiu     $v1, $zero, 0x4b
/* CD248C 8024065C AFA30014 */  sw        $v1, 0x14($sp)
/* CD2490 80240660 46001080 */  add.s     $f2, $f2, $f0
/* CD2494 80240664 8C450048 */  lw        $a1, 0x48($v0)
/* CD2498 80240668 8C470050 */  lw        $a3, 0x50($v0)
/* CD249C 8024066C 44061000 */  mfc1      $a2, $f2
/* CD24A0 80240670 0C01C2EC */  jal       func_80070BB0
/* CD24A4 80240674 24040004 */   addiu    $a0, $zero, 4
/* CD24A8 80240678 8FBF0018 */  lw        $ra, 0x18($sp)
/* CD24AC 8024067C 24020002 */  addiu     $v0, $zero, 2
/* CD24B0 80240680 03E00008 */  jr        $ra
/* CD24B4 80240684 27BD0020 */   addiu    $sp, $sp, 0x20

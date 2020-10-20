.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240574
/* 892F94 80240574 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 892F98 80240578 AFBF0018 */  sw        $ra, 0x18($sp)
/* 892F9C 8024057C 8C82000C */  lw        $v0, 0xc($a0)
/* 892FA0 80240580 0C0B1EAF */  jal       get_variable
/* 892FA4 80240584 8C450000 */   lw       $a1, ($v0)
/* 892FA8 80240588 0C04417A */  jal       get_entity_by_index
/* 892FAC 8024058C 0040202D */   daddu    $a0, $v0, $zero
/* 892FB0 80240590 3C013F80 */  lui       $at, 0x3f80
/* 892FB4 80240594 44810000 */  mtc1      $at, $f0
/* 892FB8 80240598 C442004C */  lwc1      $f2, 0x4c($v0)
/* 892FBC 8024059C E7A00010 */  swc1      $f0, 0x10($sp)
/* 892FC0 802405A0 3C014148 */  lui       $at, 0x4148
/* 892FC4 802405A4 44810000 */  mtc1      $at, $f0
/* 892FC8 802405A8 2403004B */  addiu     $v1, $zero, 0x4b
/* 892FCC 802405AC AFA30014 */  sw        $v1, 0x14($sp)
/* 892FD0 802405B0 46001080 */  add.s     $f2, $f2, $f0
/* 892FD4 802405B4 8C450048 */  lw        $a1, 0x48($v0)
/* 892FD8 802405B8 8C470050 */  lw        $a3, 0x50($v0)
/* 892FDC 802405BC 44061000 */  mfc1      $a2, $f2
/* 892FE0 802405C0 0C01C2EC */  jal       func_80070BB0
/* 892FE4 802405C4 24040004 */   addiu    $a0, $zero, 4
/* 892FE8 802405C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 892FEC 802405CC 24020002 */  addiu     $v0, $zero, 2
/* 892FF0 802405D0 03E00008 */  jr        $ra
/* 892FF4 802405D4 27BD0020 */   addiu    $sp, $sp, 0x20

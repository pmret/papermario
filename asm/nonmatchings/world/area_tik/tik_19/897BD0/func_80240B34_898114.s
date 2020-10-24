.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B34_898114
/* 898114 80240B34 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 898118 80240B38 AFBF0018 */  sw        $ra, 0x18($sp)
/* 89811C 80240B3C 8C82000C */  lw        $v0, 0xc($a0)
/* 898120 80240B40 0C0B1EAF */  jal       get_variable
/* 898124 80240B44 8C450000 */   lw       $a1, ($v0)
/* 898128 80240B48 0C04417A */  jal       get_entity_by_index
/* 89812C 80240B4C 0040202D */   daddu    $a0, $v0, $zero
/* 898130 80240B50 3C013F80 */  lui       $at, 0x3f80
/* 898134 80240B54 44810000 */  mtc1      $at, $f0
/* 898138 80240B58 C442004C */  lwc1      $f2, 0x4c($v0)
/* 89813C 80240B5C E7A00010 */  swc1      $f0, 0x10($sp)
/* 898140 80240B60 3C014148 */  lui       $at, 0x4148
/* 898144 80240B64 44810000 */  mtc1      $at, $f0
/* 898148 80240B68 2403004B */  addiu     $v1, $zero, 0x4b
/* 89814C 80240B6C AFA30014 */  sw        $v1, 0x14($sp)
/* 898150 80240B70 46001080 */  add.s     $f2, $f2, $f0
/* 898154 80240B74 8C450048 */  lw        $a1, 0x48($v0)
/* 898158 80240B78 8C470050 */  lw        $a3, 0x50($v0)
/* 89815C 80240B7C 44061000 */  mfc1      $a2, $f2
/* 898160 80240B80 0C01C2EC */  jal       func_80070BB0
/* 898164 80240B84 24040004 */   addiu    $a0, $zero, 4
/* 898168 80240B88 8FBF0018 */  lw        $ra, 0x18($sp)
/* 89816C 80240B8C 24020002 */  addiu     $v0, $zero, 2
/* 898170 80240B90 03E00008 */  jr        $ra
/* 898174 80240B94 27BD0020 */   addiu    $sp, $sp, 0x20

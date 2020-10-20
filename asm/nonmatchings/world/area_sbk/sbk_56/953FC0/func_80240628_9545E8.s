.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240628_9545E8
/* 9545E8 80240628 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9545EC 8024062C AFBF0018 */  sw        $ra, 0x18($sp)
/* 9545F0 80240630 0C00EAD2 */  jal       get_npc_safe
/* 9545F4 80240634 2404FFFC */   addiu    $a0, $zero, -4
/* 9545F8 80240638 C444003C */  lwc1      $f4, 0x3c($v0)
/* 9545FC 8024063C 3C014148 */  lui       $at, 0x4148
/* 954600 80240640 44811000 */  mtc1      $at, $f2
/* 954604 80240644 3C013F80 */  lui       $at, 0x3f80
/* 954608 80240648 44810000 */  mtc1      $at, $f0
/* 95460C 8024064C 2403001E */  addiu     $v1, $zero, 0x1e
/* 954610 80240650 AFA30014 */  sw        $v1, 0x14($sp)
/* 954614 80240654 46022100 */  add.s     $f4, $f4, $f2
/* 954618 80240658 E7A00010 */  swc1      $f0, 0x10($sp)
/* 95461C 8024065C 8C450038 */  lw        $a1, 0x38($v0)
/* 954620 80240660 8C470040 */  lw        $a3, 0x40($v0)
/* 954624 80240664 44062000 */  mfc1      $a2, $f4
/* 954628 80240668 0C01C2EC */  jal       func_80070BB0
/* 95462C 8024066C 24040009 */   addiu    $a0, $zero, 9
/* 954630 80240670 8FBF0018 */  lw        $ra, 0x18($sp)
/* 954634 80240674 24020002 */  addiu     $v0, $zero, 2
/* 954638 80240678 03E00008 */  jr        $ra
/* 95463C 8024067C 27BD0020 */   addiu    $sp, $sp, 0x20

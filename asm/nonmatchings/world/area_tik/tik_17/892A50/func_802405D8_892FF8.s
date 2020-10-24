.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405D8_892FF8
/* 892FF8 802405D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 892FFC 802405DC AFBF0018 */  sw        $ra, 0x18($sp)
/* 893000 802405E0 0C00EAD2 */  jal       get_npc_safe
/* 893004 802405E4 2404FFFC */   addiu    $a0, $zero, -4
/* 893008 802405E8 C444003C */  lwc1      $f4, 0x3c($v0)
/* 89300C 802405EC 3C014148 */  lui       $at, 0x4148
/* 893010 802405F0 44811000 */  mtc1      $at, $f2
/* 893014 802405F4 3C013F80 */  lui       $at, 0x3f80
/* 893018 802405F8 44810000 */  mtc1      $at, $f0
/* 89301C 802405FC 2403001E */  addiu     $v1, $zero, 0x1e
/* 893020 80240600 AFA30014 */  sw        $v1, 0x14($sp)
/* 893024 80240604 46022100 */  add.s     $f4, $f4, $f2
/* 893028 80240608 E7A00010 */  swc1      $f0, 0x10($sp)
/* 89302C 8024060C 8C450038 */  lw        $a1, 0x38($v0)
/* 893030 80240610 8C470040 */  lw        $a3, 0x40($v0)
/* 893034 80240614 44062000 */  mfc1      $a2, $f4
/* 893038 80240618 0C01C2EC */  jal       func_80070BB0
/* 89303C 8024061C 24040009 */   addiu    $a0, $zero, 9
/* 893040 80240620 8FBF0018 */  lw        $ra, 0x18($sp)
/* 893044 80240624 24020002 */  addiu     $v0, $zero, 2
/* 893048 80240628 03E00008 */  jr        $ra
/* 89304C 8024062C 27BD0020 */   addiu    $sp, $sp, 0x20

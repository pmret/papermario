.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel iwa_10_UnkFunc22
/* 91EE08 80240898 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91EE0C 8024089C AFBF0018 */  sw        $ra, 0x18($sp)
/* 91EE10 802408A0 0C00EAD2 */  jal       get_npc_safe
/* 91EE14 802408A4 2404FFFC */   addiu    $a0, $zero, -4
/* 91EE18 802408A8 C444003C */  lwc1      $f4, 0x3c($v0)
/* 91EE1C 802408AC 3C014148 */  lui       $at, 0x4148
/* 91EE20 802408B0 44811000 */  mtc1      $at, $f2
/* 91EE24 802408B4 3C013F80 */  lui       $at, 0x3f80
/* 91EE28 802408B8 44810000 */  mtc1      $at, $f0
/* 91EE2C 802408BC 2403001E */  addiu     $v1, $zero, 0x1e
/* 91EE30 802408C0 AFA30014 */  sw        $v1, 0x14($sp)
/* 91EE34 802408C4 46022100 */  add.s     $f4, $f4, $f2
/* 91EE38 802408C8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 91EE3C 802408CC 8C450038 */  lw        $a1, 0x38($v0)
/* 91EE40 802408D0 8C470040 */  lw        $a3, 0x40($v0)
/* 91EE44 802408D4 44062000 */  mfc1      $a2, $f4
/* 91EE48 802408D8 0C01C2EC */  jal       func_80070BB0
/* 91EE4C 802408DC 24040009 */   addiu    $a0, $zero, 9
/* 91EE50 802408E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 91EE54 802408E4 24020002 */  addiu     $v0, $zero, 2
/* 91EE58 802408E8 03E00008 */  jr        $ra
/* 91EE5C 802408EC 27BD0020 */   addiu    $sp, $sp, 0x20

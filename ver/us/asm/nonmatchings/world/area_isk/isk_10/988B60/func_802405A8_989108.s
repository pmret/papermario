.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel isk_10_UnkFunc22
/* 989108 802405A8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 98910C 802405AC AFBF0018 */  sw        $ra, 0x18($sp)
/* 989110 802405B0 0C00EAD2 */  jal       get_npc_safe
/* 989114 802405B4 2404FFFC */   addiu    $a0, $zero, -4
/* 989118 802405B8 C444003C */  lwc1      $f4, 0x3c($v0)
/* 98911C 802405BC 3C014148 */  lui       $at, 0x4148
/* 989120 802405C0 44811000 */  mtc1      $at, $f2
/* 989124 802405C4 3C013F80 */  lui       $at, 0x3f80
/* 989128 802405C8 44810000 */  mtc1      $at, $f0
/* 98912C 802405CC 2403001E */  addiu     $v1, $zero, 0x1e
/* 989130 802405D0 AFA30014 */  sw        $v1, 0x14($sp)
/* 989134 802405D4 46022100 */  add.s     $f4, $f4, $f2
/* 989138 802405D8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 98913C 802405DC 8C450038 */  lw        $a1, 0x38($v0)
/* 989140 802405E0 8C470040 */  lw        $a3, 0x40($v0)
/* 989144 802405E4 44062000 */  mfc1      $a2, $f4
/* 989148 802405E8 0C01C2EC */  jal       func_80070BB0
/* 98914C 802405EC 24040009 */   addiu    $a0, $zero, 9
/* 989150 802405F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 989154 802405F4 24020002 */  addiu     $v0, $zero, 2
/* 989158 802405F8 03E00008 */  jr        $ra
/* 98915C 802405FC 27BD0020 */   addiu    $sp, $sp, 0x20

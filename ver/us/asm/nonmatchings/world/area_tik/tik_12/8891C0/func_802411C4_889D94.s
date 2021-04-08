.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_12_UnkFunc22
/* 889D94 802411C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 889D98 802411C8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 889D9C 802411CC 0C00EAD2 */  jal       get_npc_safe
/* 889DA0 802411D0 2404FFFC */   addiu    $a0, $zero, -4
/* 889DA4 802411D4 C444003C */  lwc1      $f4, 0x3c($v0)
/* 889DA8 802411D8 3C014148 */  lui       $at, 0x4148
/* 889DAC 802411DC 44811000 */  mtc1      $at, $f2
/* 889DB0 802411E0 3C013F80 */  lui       $at, 0x3f80
/* 889DB4 802411E4 44810000 */  mtc1      $at, $f0
/* 889DB8 802411E8 2403001E */  addiu     $v1, $zero, 0x1e
/* 889DBC 802411EC AFA30014 */  sw        $v1, 0x14($sp)
/* 889DC0 802411F0 46022100 */  add.s     $f4, $f4, $f2
/* 889DC4 802411F4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 889DC8 802411F8 8C450038 */  lw        $a1, 0x38($v0)
/* 889DCC 802411FC 8C470040 */  lw        $a3, 0x40($v0)
/* 889DD0 80241200 44062000 */  mfc1      $a2, $f4
/* 889DD4 80241204 0C01C2EC */  jal       func_80070BB0
/* 889DD8 80241208 24040009 */   addiu    $a0, $zero, 9
/* 889DDC 8024120C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 889DE0 80241210 24020002 */  addiu     $v0, $zero, 2
/* 889DE4 80241214 03E00008 */  jr        $ra
/* 889DE8 80241218 27BD0020 */   addiu    $sp, $sp, 0x20

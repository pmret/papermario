.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kzn_09_UnkFunc22
/* C77288 802405A8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C7728C 802405AC AFBF0018 */  sw        $ra, 0x18($sp)
/* C77290 802405B0 0C00EAD2 */  jal       get_npc_safe
/* C77294 802405B4 2404FFFC */   addiu    $a0, $zero, -4
/* C77298 802405B8 C444003C */  lwc1      $f4, 0x3c($v0)
/* C7729C 802405BC 3C014148 */  lui       $at, 0x4148
/* C772A0 802405C0 44811000 */  mtc1      $at, $f2
/* C772A4 802405C4 3C013F80 */  lui       $at, 0x3f80
/* C772A8 802405C8 44810000 */  mtc1      $at, $f0
/* C772AC 802405CC 2403001E */  addiu     $v1, $zero, 0x1e
/* C772B0 802405D0 AFA30014 */  sw        $v1, 0x14($sp)
/* C772B4 802405D4 46022100 */  add.s     $f4, $f4, $f2
/* C772B8 802405D8 E7A00010 */  swc1      $f0, 0x10($sp)
/* C772BC 802405DC 8C450038 */  lw        $a1, 0x38($v0)
/* C772C0 802405E0 8C470040 */  lw        $a3, 0x40($v0)
/* C772C4 802405E4 44062000 */  mfc1      $a2, $f4
/* C772C8 802405E8 0C01C2EC */  jal       func_80070BB0
/* C772CC 802405EC 24040009 */   addiu    $a0, $zero, 9
/* C772D0 802405F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* C772D4 802405F4 24020002 */  addiu     $v0, $zero, 2
/* C772D8 802405F8 03E00008 */  jr        $ra
/* C772DC 802405FC 27BD0020 */   addiu    $sp, $sp, 0x20

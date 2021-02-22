.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802405A8_CAF2E8
/* CAF2E8 802405A8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CAF2EC 802405AC AFBF0018 */  sw        $ra, 0x18($sp)
/* CAF2F0 802405B0 0C00EAD2 */  jal       get_npc_safe
/* CAF2F4 802405B4 2404FFFC */   addiu    $a0, $zero, -4
/* CAF2F8 802405B8 C444003C */  lwc1      $f4, 0x3c($v0)
/* CAF2FC 802405BC 3C014148 */  lui       $at, 0x4148
/* CAF300 802405C0 44811000 */  mtc1      $at, $f2
/* CAF304 802405C4 3C013F80 */  lui       $at, 0x3f80
/* CAF308 802405C8 44810000 */  mtc1      $at, $f0
/* CAF30C 802405CC 2403001E */  addiu     $v1, $zero, 0x1e
/* CAF310 802405D0 AFA30014 */  sw        $v1, 0x14($sp)
/* CAF314 802405D4 46022100 */  add.s     $f4, $f4, $f2
/* CAF318 802405D8 E7A00010 */  swc1      $f0, 0x10($sp)
/* CAF31C 802405DC 8C450038 */  lw        $a1, 0x38($v0)
/* CAF320 802405E0 8C470040 */  lw        $a3, 0x40($v0)
/* CAF324 802405E4 44062000 */  mfc1      $a2, $f4
/* CAF328 802405E8 0C01C2EC */  jal       func_80070BB0
/* CAF32C 802405EC 24040009 */   addiu    $a0, $zero, 9
/* CAF330 802405F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* CAF334 802405F4 24020002 */  addiu     $v0, $zero, 2
/* CAF338 802405F8 03E00008 */  jr        $ra
/* CAF33C 802405FC 27BD0020 */   addiu    $sp, $sp, 0x20

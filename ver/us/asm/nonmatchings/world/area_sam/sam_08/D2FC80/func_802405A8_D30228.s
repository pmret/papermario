.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sam_08_UnkFunc22
/* D30228 802405A8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D3022C 802405AC AFBF0018 */  sw        $ra, 0x18($sp)
/* D30230 802405B0 0C00EAD2 */  jal       get_npc_safe
/* D30234 802405B4 2404FFFC */   addiu    $a0, $zero, -4
/* D30238 802405B8 C444003C */  lwc1      $f4, 0x3c($v0)
/* D3023C 802405BC 3C014148 */  lui       $at, 0x4148
/* D30240 802405C0 44811000 */  mtc1      $at, $f2
/* D30244 802405C4 3C013F80 */  lui       $at, 0x3f80
/* D30248 802405C8 44810000 */  mtc1      $at, $f0
/* D3024C 802405CC 2403001E */  addiu     $v1, $zero, 0x1e
/* D30250 802405D0 AFA30014 */  sw        $v1, 0x14($sp)
/* D30254 802405D4 46022100 */  add.s     $f4, $f4, $f2
/* D30258 802405D8 E7A00010 */  swc1      $f0, 0x10($sp)
/* D3025C 802405DC 8C450038 */  lw        $a1, 0x38($v0)
/* D30260 802405E0 8C470040 */  lw        $a3, 0x40($v0)
/* D30264 802405E4 44062000 */  mfc1      $a2, $f4
/* D30268 802405E8 0C01C2EC */  jal       func_80070BB0
/* D3026C 802405EC 24040009 */   addiu    $a0, $zero, 9
/* D30270 802405F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* D30274 802405F4 24020002 */  addiu     $v0, $zero, 2
/* D30278 802405F8 03E00008 */  jr        $ra
/* D3027C 802405FC 27BD0020 */   addiu    $sp, $sp, 0x20

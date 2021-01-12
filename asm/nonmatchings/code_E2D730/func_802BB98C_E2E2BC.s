.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB98C_E2E2BC
/* E2E2BC 802BB98C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2E2C0 802BB990 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* E2E2C4 802BB994 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* E2E2C8 802BB998 3C02800B */  lui       $v0, %hi(gCameras)
/* E2E2CC 802BB99C 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* E2E2D0 802BB9A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* E2E2D4 802BB9A4 8C830040 */  lw        $v1, 0x40($a0)
/* E2E2D8 802BB9A8 C4A00028 */  lwc1      $f0, 0x28($a1)
/* E2E2DC 802BB9AC C4A2002C */  lwc1      $f2, 0x2c($a1)
/* E2E2E0 802BB9B0 C4A40030 */  lwc1      $f4, 0x30($a1)
/* E2E2E4 802BB9B4 24A40028 */  addiu     $a0, $a1, 0x28
/* E2E2E8 802BB9B8 E4400060 */  swc1      $f0, 0x60($v0)
/* E2E2EC 802BB9BC E4420064 */  swc1      $f2, 0x64($v0)
/* E2E2F0 802BB9C0 E4440068 */  swc1      $f4, 0x68($v0)
/* E2E2F4 802BB9C4 8C660008 */  lw        $a2, 8($v1)
/* E2E2F8 802BB9C8 8C670004 */  lw        $a3, 4($v1)
/* E2E2FC 802BB9CC 0C00A7E7 */  jal       add_vec2D_polar
/* E2E300 802BB9D0 24A50030 */   addiu    $a1, $a1, 0x30
/* E2E304 802BB9D4 8FBF0010 */  lw        $ra, 0x10($sp)
/* E2E308 802BB9D8 03E00008 */  jr        $ra
/* E2E30C 802BB9DC 27BD0018 */   addiu    $sp, $sp, 0x18

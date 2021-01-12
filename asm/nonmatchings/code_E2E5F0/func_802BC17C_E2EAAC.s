.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BC17C_E2EAAC
/* E2EAAC 802BC17C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E2EAB0 802BC180 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* E2EAB4 802BC184 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* E2EAB8 802BC188 3C02800B */  lui       $v0, %hi(gCameras)
/* E2EABC 802BC18C 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* E2EAC0 802BC190 AFBF0010 */  sw        $ra, 0x10($sp)
/* E2EAC4 802BC194 8C830040 */  lw        $v1, 0x40($a0)
/* E2EAC8 802BC198 C4A00028 */  lwc1      $f0, 0x28($a1)
/* E2EACC 802BC19C C4A2002C */  lwc1      $f2, 0x2c($a1)
/* E2EAD0 802BC1A0 C4A40030 */  lwc1      $f4, 0x30($a1)
/* E2EAD4 802BC1A4 24A40028 */  addiu     $a0, $a1, 0x28
/* E2EAD8 802BC1A8 E4400060 */  swc1      $f0, 0x60($v0)
/* E2EADC 802BC1AC E4420064 */  swc1      $f2, 0x64($v0)
/* E2EAE0 802BC1B0 E4440068 */  swc1      $f4, 0x68($v0)
/* E2EAE4 802BC1B4 8C660018 */  lw        $a2, 0x18($v1)
/* E2EAE8 802BC1B8 8C670014 */  lw        $a3, 0x14($v1)
/* E2EAEC 802BC1BC 0C00A7E7 */  jal       add_vec2D_polar
/* E2EAF0 802BC1C0 24A50030 */   addiu    $a1, $a1, 0x30
/* E2EAF4 802BC1C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* E2EAF8 802BC1C8 03E00008 */  jr        $ra
/* E2EAFC 802BC1CC 27BD0018 */   addiu    $sp, $sp, 0x18

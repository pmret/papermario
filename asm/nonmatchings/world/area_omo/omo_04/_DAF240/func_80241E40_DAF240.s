.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E40_DAF240
/* DAF240 80241E40 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DAF244 80241E44 AFB10014 */  sw        $s1, 0x14($sp)
/* DAF248 80241E48 0080882D */  daddu     $s1, $a0, $zero
/* DAF24C 80241E4C AFBF001C */  sw        $ra, 0x1c($sp)
/* DAF250 80241E50 AFB20018 */  sw        $s2, 0x18($sp)
/* DAF254 80241E54 AFB00010 */  sw        $s0, 0x10($sp)
/* DAF258 80241E58 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DAF25C 80241E5C F7B40020 */  sdc1      $f20, 0x20($sp)
/* DAF260 80241E60 0C00EABB */  jal       get_npc_unsafe
/* DAF264 80241E64 24040002 */   addiu    $a0, $zero, 2
/* DAF268 80241E68 0040802D */  daddu     $s0, $v0, $zero
/* DAF26C 80241E6C 3C12800B */  lui       $s2, %hi(gCameras)
/* DAF270 80241E70 26521D80 */  addiu     $s2, $s2, %lo(gCameras)
/* DAF274 80241E74 C60C000C */  lwc1      $f12, 0xc($s0)
/* DAF278 80241E78 C640006C */  lwc1      $f0, 0x6c($s2)
/* DAF27C 80241E7C 46006300 */  add.s     $f12, $f12, $f0
/* DAF280 80241E80 3C014334 */  lui       $at, 0x4334
/* DAF284 80241E84 4481A000 */  mtc1      $at, $f20
/* DAF288 80241E88 3C014220 */  lui       $at, 0x4220
/* DAF28C 80241E8C 4481B000 */  mtc1      $at, $f22
/* DAF290 80241E90 0C00A8BB */  jal       sin_deg
/* DAF294 80241E94 46146300 */   add.s    $f12, $f12, $f20
/* DAF298 80241E98 46160002 */  mul.s     $f0, $f0, $f22
/* DAF29C 80241E9C 00000000 */  nop       
/* DAF2A0 80241EA0 C6020038 */  lwc1      $f2, 0x38($s0)
/* DAF2A4 80241EA4 46001080 */  add.s     $f2, $f2, $f0
/* DAF2A8 80241EA8 4600110D */  trunc.w.s $f4, $f2
/* DAF2AC 80241EAC E6240084 */  swc1      $f4, 0x84($s1)
/* DAF2B0 80241EB0 C600003C */  lwc1      $f0, 0x3c($s0)
/* DAF2B4 80241EB4 3C014100 */  lui       $at, 0x4100
/* DAF2B8 80241EB8 44811000 */  mtc1      $at, $f2
/* DAF2BC 80241EBC 00000000 */  nop       
/* DAF2C0 80241EC0 46020000 */  add.s     $f0, $f0, $f2
/* DAF2C4 80241EC4 4600010D */  trunc.w.s $f4, $f0
/* DAF2C8 80241EC8 E6240088 */  swc1      $f4, 0x88($s1)
/* DAF2CC 80241ECC C60C000C */  lwc1      $f12, 0xc($s0)
/* DAF2D0 80241ED0 C640006C */  lwc1      $f0, 0x6c($s2)
/* DAF2D4 80241ED4 46006300 */  add.s     $f12, $f12, $f0
/* DAF2D8 80241ED8 0C00A8D4 */  jal       cos_deg
/* DAF2DC 80241EDC 46146300 */   add.s    $f12, $f12, $f20
/* DAF2E0 80241EE0 46160002 */  mul.s     $f0, $f0, $f22
/* DAF2E4 80241EE4 00000000 */  nop       
/* DAF2E8 80241EE8 C6020040 */  lwc1      $f2, 0x40($s0)
/* DAF2EC 80241EEC 46001081 */  sub.s     $f2, $f2, $f0
/* DAF2F0 80241EF0 4600110D */  trunc.w.s $f4, $f2
/* DAF2F4 80241EF4 E624008C */  swc1      $f4, 0x8c($s1)
/* DAF2F8 80241EF8 8FBF001C */  lw        $ra, 0x1c($sp)
/* DAF2FC 80241EFC 8FB20018 */  lw        $s2, 0x18($sp)
/* DAF300 80241F00 8FB10014 */  lw        $s1, 0x14($sp)
/* DAF304 80241F04 8FB00010 */  lw        $s0, 0x10($sp)
/* DAF308 80241F08 D7B60028 */  ldc1      $f22, 0x28($sp)
/* DAF30C 80241F0C D7B40020 */  ldc1      $f20, 0x20($sp)
/* DAF310 80241F10 24020002 */  addiu     $v0, $zero, 2
/* DAF314 80241F14 03E00008 */  jr        $ra
/* DAF318 80241F18 27BD0030 */   addiu    $sp, $sp, 0x30
/* DAF31C 80241F1C 00000000 */  nop       

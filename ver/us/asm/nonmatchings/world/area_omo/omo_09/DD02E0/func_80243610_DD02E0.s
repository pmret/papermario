.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243610_DD02E0
/* DD02E0 80243610 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DD02E4 80243614 AFB10014 */  sw        $s1, 0x14($sp)
/* DD02E8 80243618 0080882D */  daddu     $s1, $a0, $zero
/* DD02EC 8024361C AFBF001C */  sw        $ra, 0x1c($sp)
/* DD02F0 80243620 AFB20018 */  sw        $s2, 0x18($sp)
/* DD02F4 80243624 AFB00010 */  sw        $s0, 0x10($sp)
/* DD02F8 80243628 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DD02FC 8024362C F7B40020 */  sdc1      $f20, 0x20($sp)
/* DD0300 80243630 0C00EABB */  jal       get_npc_unsafe
/* DD0304 80243634 24040007 */   addiu    $a0, $zero, 7
/* DD0308 80243638 0040802D */  daddu     $s0, $v0, $zero
/* DD030C 8024363C 3C12800B */  lui       $s2, %hi(gCameras)
/* DD0310 80243640 26521D80 */  addiu     $s2, $s2, %lo(gCameras)
/* DD0314 80243644 C60C000C */  lwc1      $f12, 0xc($s0)
/* DD0318 80243648 C640006C */  lwc1      $f0, 0x6c($s2)
/* DD031C 8024364C 46006300 */  add.s     $f12, $f12, $f0
/* DD0320 80243650 3C014334 */  lui       $at, 0x4334
/* DD0324 80243654 4481A000 */  mtc1      $at, $f20
/* DD0328 80243658 3C014220 */  lui       $at, 0x4220
/* DD032C 8024365C 4481B000 */  mtc1      $at, $f22
/* DD0330 80243660 0C00A8BB */  jal       sin_deg
/* DD0334 80243664 46146300 */   add.s    $f12, $f12, $f20
/* DD0338 80243668 46160002 */  mul.s     $f0, $f0, $f22
/* DD033C 8024366C 00000000 */  nop
/* DD0340 80243670 C6020038 */  lwc1      $f2, 0x38($s0)
/* DD0344 80243674 46001080 */  add.s     $f2, $f2, $f0
/* DD0348 80243678 4600110D */  trunc.w.s $f4, $f2
/* DD034C 8024367C E6240084 */  swc1      $f4, 0x84($s1)
/* DD0350 80243680 C600003C */  lwc1      $f0, 0x3c($s0)
/* DD0354 80243684 3C014100 */  lui       $at, 0x4100
/* DD0358 80243688 44811000 */  mtc1      $at, $f2
/* DD035C 8024368C 00000000 */  nop
/* DD0360 80243690 46020000 */  add.s     $f0, $f0, $f2
/* DD0364 80243694 4600010D */  trunc.w.s $f4, $f0
/* DD0368 80243698 E6240088 */  swc1      $f4, 0x88($s1)
/* DD036C 8024369C C60C000C */  lwc1      $f12, 0xc($s0)
/* DD0370 802436A0 C640006C */  lwc1      $f0, 0x6c($s2)
/* DD0374 802436A4 46006300 */  add.s     $f12, $f12, $f0
/* DD0378 802436A8 0C00A8D4 */  jal       cos_deg
/* DD037C 802436AC 46146300 */   add.s    $f12, $f12, $f20
/* DD0380 802436B0 46160002 */  mul.s     $f0, $f0, $f22
/* DD0384 802436B4 00000000 */  nop
/* DD0388 802436B8 C6020040 */  lwc1      $f2, 0x40($s0)
/* DD038C 802436BC 46001081 */  sub.s     $f2, $f2, $f0
/* DD0390 802436C0 4600110D */  trunc.w.s $f4, $f2
/* DD0394 802436C4 E624008C */  swc1      $f4, 0x8c($s1)
/* DD0398 802436C8 8FBF001C */  lw        $ra, 0x1c($sp)
/* DD039C 802436CC 8FB20018 */  lw        $s2, 0x18($sp)
/* DD03A0 802436D0 8FB10014 */  lw        $s1, 0x14($sp)
/* DD03A4 802436D4 8FB00010 */  lw        $s0, 0x10($sp)
/* DD03A8 802436D8 D7B60028 */  ldc1      $f22, 0x28($sp)
/* DD03AC 802436DC D7B40020 */  ldc1      $f20, 0x20($sp)
/* DD03B0 802436E0 24020002 */  addiu     $v0, $zero, 2
/* DD03B4 802436E4 03E00008 */  jr        $ra
/* DD03B8 802436E8 27BD0030 */   addiu    $sp, $sp, 0x30
/* DD03BC 802436EC 00000000 */  nop

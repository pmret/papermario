.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243220_DC04D0
/* DC04D0 80243220 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DC04D4 80243224 AFB10014 */  sw        $s1, 0x14($sp)
/* DC04D8 80243228 0080882D */  daddu     $s1, $a0, $zero
/* DC04DC 8024322C AFBF001C */  sw        $ra, 0x1c($sp)
/* DC04E0 80243230 AFB20018 */  sw        $s2, 0x18($sp)
/* DC04E4 80243234 AFB00010 */  sw        $s0, 0x10($sp)
/* DC04E8 80243238 F7B60028 */  sdc1      $f22, 0x28($sp)
/* DC04EC 8024323C F7B40020 */  sdc1      $f20, 0x20($sp)
/* DC04F0 80243240 0C00EABB */  jal       get_npc_unsafe
/* DC04F4 80243244 24040007 */   addiu    $a0, $zero, 7
/* DC04F8 80243248 0040802D */  daddu     $s0, $v0, $zero
/* DC04FC 8024324C 3C12800B */  lui       $s2, %hi(gCameras)
/* DC0500 80243250 26521D80 */  addiu     $s2, $s2, %lo(gCameras)
/* DC0504 80243254 C60C000C */  lwc1      $f12, 0xc($s0)
/* DC0508 80243258 C640006C */  lwc1      $f0, 0x6c($s2)
/* DC050C 8024325C 46006300 */  add.s     $f12, $f12, $f0
/* DC0510 80243260 3C014334 */  lui       $at, 0x4334
/* DC0514 80243264 4481A000 */  mtc1      $at, $f20
/* DC0518 80243268 3C014220 */  lui       $at, 0x4220
/* DC051C 8024326C 4481B000 */  mtc1      $at, $f22
/* DC0520 80243270 0C00A8BB */  jal       sin_deg
/* DC0524 80243274 46146300 */   add.s    $f12, $f12, $f20
/* DC0528 80243278 46160002 */  mul.s     $f0, $f0, $f22
/* DC052C 8024327C 00000000 */  nop
/* DC0530 80243280 C6020038 */  lwc1      $f2, 0x38($s0)
/* DC0534 80243284 46001080 */  add.s     $f2, $f2, $f0
/* DC0538 80243288 4600110D */  trunc.w.s $f4, $f2
/* DC053C 8024328C E6240084 */  swc1      $f4, 0x84($s1)
/* DC0540 80243290 C600003C */  lwc1      $f0, 0x3c($s0)
/* DC0544 80243294 3C014100 */  lui       $at, 0x4100
/* DC0548 80243298 44811000 */  mtc1      $at, $f2
/* DC054C 8024329C 00000000 */  nop
/* DC0550 802432A0 46020000 */  add.s     $f0, $f0, $f2
/* DC0554 802432A4 4600010D */  trunc.w.s $f4, $f0
/* DC0558 802432A8 E6240088 */  swc1      $f4, 0x88($s1)
/* DC055C 802432AC C60C000C */  lwc1      $f12, 0xc($s0)
/* DC0560 802432B0 C640006C */  lwc1      $f0, 0x6c($s2)
/* DC0564 802432B4 46006300 */  add.s     $f12, $f12, $f0
/* DC0568 802432B8 0C00A8D4 */  jal       cos_deg
/* DC056C 802432BC 46146300 */   add.s    $f12, $f12, $f20
/* DC0570 802432C0 46160002 */  mul.s     $f0, $f0, $f22
/* DC0574 802432C4 00000000 */  nop
/* DC0578 802432C8 C6020040 */  lwc1      $f2, 0x40($s0)
/* DC057C 802432CC 46001081 */  sub.s     $f2, $f2, $f0
/* DC0580 802432D0 4600110D */  trunc.w.s $f4, $f2
/* DC0584 802432D4 E624008C */  swc1      $f4, 0x8c($s1)
/* DC0588 802432D8 8FBF001C */  lw        $ra, 0x1c($sp)
/* DC058C 802432DC 8FB20018 */  lw        $s2, 0x18($sp)
/* DC0590 802432E0 8FB10014 */  lw        $s1, 0x14($sp)
/* DC0594 802432E4 8FB00010 */  lw        $s0, 0x10($sp)
/* DC0598 802432E8 D7B60028 */  ldc1      $f22, 0x28($sp)
/* DC059C 802432EC D7B40020 */  ldc1      $f20, 0x20($sp)
/* DC05A0 802432F0 24020002 */  addiu     $v0, $zero, 2
/* DC05A4 802432F4 03E00008 */  jr        $ra
/* DC05A8 802432F8 27BD0030 */   addiu    $sp, $sp, 0x30
/* DC05AC 802432FC 00000000 */  nop

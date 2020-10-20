.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240540_CE3C30
/* CE3C30 80240540 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* CE3C34 80240544 AFB00010 */  sw        $s0, 0x10($sp)
/* CE3C38 80240548 0080802D */  daddu     $s0, $a0, $zero
/* CE3C3C 8024054C AFBF0018 */  sw        $ra, 0x18($sp)
/* CE3C40 80240550 AFB10014 */  sw        $s1, 0x14($sp)
/* CE3C44 80240554 F7B80030 */  sdc1      $f24, 0x30($sp)
/* CE3C48 80240558 F7B60028 */  sdc1      $f22, 0x28($sp)
/* CE3C4C 8024055C F7B40020 */  sdc1      $f20, 0x20($sp)
/* CE3C50 80240560 8E05008C */  lw        $a1, 0x8c($s0)
/* CE3C54 80240564 4480B000 */  mtc1      $zero, $f22
/* CE3C58 80240568 0C0B1EAF */  jal       get_variable
/* CE3C5C 8024056C 0000202D */   daddu    $a0, $zero, $zero
/* CE3C60 80240570 4600B306 */  mov.s     $f12, $f22
/* CE3C64 80240574 C60200A8 */  lwc1      $f2, 0xa8($s0)
/* CE3C68 80240578 468010A0 */  cvt.s.w   $f2, $f2
/* CE3C6C 8024057C 44061000 */  mfc1      $a2, $f2
/* CE3C70 80240580 C60200B0 */  lwc1      $f2, 0xb0($s0)
/* CE3C74 80240584 468010A0 */  cvt.s.w   $f2, $f2
/* CE3C78 80240588 44071000 */  mfc1      $a3, $f2
/* CE3C7C 8024058C 4482A000 */  mtc1      $v0, $f20
/* CE3C80 80240590 00000000 */  nop       
/* CE3C84 80240594 4680A520 */  cvt.s.w   $f20, $f20
/* CE3C88 80240598 0C00A7B5 */  jal       dist2D
/* CE3C8C 8024059C 4600B386 */   mov.s    $f14, $f22
/* CE3C90 802405A0 4600B306 */  mov.s     $f12, $f22
/* CE3C94 802405A4 4600B386 */  mov.s     $f14, $f22
/* CE3C98 802405A8 C60200A8 */  lwc1      $f2, 0xa8($s0)
/* CE3C9C 802405AC 468010A0 */  cvt.s.w   $f2, $f2
/* CE3CA0 802405B0 44061000 */  mfc1      $a2, $f2
/* CE3CA4 802405B4 C60200B0 */  lwc1      $f2, 0xb0($s0)
/* CE3CA8 802405B8 468010A0 */  cvt.s.w   $f2, $f2
/* CE3CAC 802405BC 44071000 */  mfc1      $a3, $f2
/* CE3CB0 802405C0 0C00A720 */  jal       atan2
/* CE3CB4 802405C4 46000606 */   mov.s    $f24, $f0
/* CE3CB8 802405C8 0C00A6C9 */  jal       clamp_angle
/* CE3CBC 802405CC 46140301 */   sub.s    $f12, $f0, $f20
/* CE3CC0 802405D0 46000506 */  mov.s     $f20, $f0
/* CE3CC4 802405D4 0C00A8BB */  jal       sin_deg
/* CE3CC8 802405D8 4600A306 */   mov.s    $f12, $f20
/* CE3CCC 802405DC 4600C002 */  mul.s     $f0, $f24, $f0
/* CE3CD0 802405E0 00000000 */  nop       
/* CE3CD4 802405E4 46160000 */  add.s     $f0, $f0, $f22
/* CE3CD8 802405E8 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* CE3CDC 802405EC 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* CE3CE0 802405F0 E6200028 */  swc1      $f0, 0x28($s1)
/* CE3CE4 802405F4 8E0500AC */  lw        $a1, 0xac($s0)
/* CE3CE8 802405F8 0C0B1EAF */  jal       get_variable
/* CE3CEC 802405FC 0000202D */   daddu    $a0, $zero, $zero
/* CE3CF0 80240600 0000202D */  daddu     $a0, $zero, $zero
/* CE3CF4 80240604 8E050090 */  lw        $a1, 0x90($s0)
/* CE3CF8 80240608 0C0B1EAF */  jal       get_variable
/* CE3CFC 8024060C 0040802D */   daddu    $s0, $v0, $zero
/* CE3D00 80240610 4600A306 */  mov.s     $f12, $f20
/* CE3D04 80240614 02028021 */  addu      $s0, $s0, $v0
/* CE3D08 80240618 44900000 */  mtc1      $s0, $f0
/* CE3D0C 8024061C 00000000 */  nop       
/* CE3D10 80240620 46800020 */  cvt.s.w   $f0, $f0
/* CE3D14 80240624 0C00A8D4 */  jal       cos_deg
/* CE3D18 80240628 E620002C */   swc1     $f0, 0x2c($s1)
/* CE3D1C 8024062C 4600C602 */  mul.s     $f24, $f24, $f0
/* CE3D20 80240630 00000000 */  nop       
/* CE3D24 80240634 4618B581 */  sub.s     $f22, $f22, $f24
/* CE3D28 80240638 E6360030 */  swc1      $f22, 0x30($s1)
/* CE3D2C 8024063C 8FBF0018 */  lw        $ra, 0x18($sp)
/* CE3D30 80240640 8FB10014 */  lw        $s1, 0x14($sp)
/* CE3D34 80240644 8FB00010 */  lw        $s0, 0x10($sp)
/* CE3D38 80240648 D7B80030 */  ldc1      $f24, 0x30($sp)
/* CE3D3C 8024064C D7B60028 */  ldc1      $f22, 0x28($sp)
/* CE3D40 80240650 D7B40020 */  ldc1      $f20, 0x20($sp)
/* CE3D44 80240654 24020002 */  addiu     $v0, $zero, 2
/* CE3D48 80240658 03E00008 */  jr        $ra
/* CE3D4C 8024065C 27BD0038 */   addiu    $sp, $sp, 0x38

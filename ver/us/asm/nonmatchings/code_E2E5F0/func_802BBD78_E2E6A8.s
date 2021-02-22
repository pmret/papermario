.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BBD78_E2E6A8
/* E2E6A8 802BBD78 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* E2E6AC 802BBD7C AFB00020 */  sw        $s0, 0x20($sp)
/* E2E6B0 802BBD80 0080802D */  daddu     $s0, $a0, $zero
/* E2E6B4 802BBD84 AFBF0024 */  sw        $ra, 0x24($sp)
/* E2E6B8 802BBD88 F7B60030 */  sdc1      $f22, 0x30($sp)
/* E2E6BC 802BBD8C F7B40028 */  sdc1      $f20, 0x28($sp)
/* E2E6C0 802BBD90 0C00A6C9 */  jal       clamp_angle
/* E2E6C4 802BBD94 C60C0064 */   lwc1     $f12, 0x64($s0)
/* E2E6C8 802BBD98 3C0140C9 */  lui       $at, 0x40c9
/* E2E6CC 802BBD9C 34210FD0 */  ori       $at, $at, 0xfd0
/* E2E6D0 802BBDA0 44811000 */  mtc1      $at, $f2
/* E2E6D4 802BBDA4 00000000 */  nop
/* E2E6D8 802BBDA8 46020582 */  mul.s     $f22, $f0, $f2
/* E2E6DC 802BBDAC 00000000 */  nop
/* E2E6E0 802BBDB0 3C0143B4 */  lui       $at, 0x43b4
/* E2E6E4 802BBDB4 44810000 */  mtc1      $at, $f0
/* E2E6E8 802BBDB8 00000000 */  nop
/* E2E6EC 802BBDBC 4600B583 */  div.s     $f22, $f22, $f0
/* E2E6F0 802BBDC0 0C00A874 */  jal       cos_rad
/* E2E6F4 802BBDC4 4600B306 */   mov.s    $f12, $f22
/* E2E6F8 802BBDC8 3C01C03A */  lui       $at, 0xc03a
/* E2E6FC 802BBDCC 44811800 */  mtc1      $at, $f3
/* E2E700 802BBDD0 44801000 */  mtc1      $zero, $f2
/* E2E704 802BBDD4 46000521 */  cvt.d.s   $f20, $f0
/* E2E708 802BBDD8 4622A502 */  mul.d     $f20, $f20, $f2
/* E2E70C 802BBDDC 00000000 */  nop
/* E2E710 802BBDE0 4600B306 */  mov.s     $f12, $f22
/* E2E714 802BBDE4 0C00A85B */  jal       sin_rad
/* E2E718 802BBDE8 4620A520 */   cvt.s.d  $f20, $f20
/* E2E71C 802BBDEC 3C014018 */  lui       $at, 0x4018
/* E2E720 802BBDF0 44811800 */  mtc1      $at, $f3
/* E2E724 802BBDF4 44801000 */  mtc1      $zero, $f2
/* E2E728 802BBDF8 460005A1 */  cvt.d.s   $f22, $f0
/* E2E72C 802BBDFC 4622B582 */  mul.d     $f22, $f22, $f2
/* E2E730 802BBE00 00000000 */  nop
/* E2E734 802BBE04 C60C0064 */  lwc1      $f12, 0x64($s0)
/* E2E738 802BBE08 3C01802C */  lui       $at, %hi(D_802BCE10_E2F740)
/* E2E73C 802BBE0C D420CE10 */  ldc1      $f0, %lo(D_802BCE10_E2F740)($at)
/* E2E740 802BBE10 46006321 */  cvt.d.s   $f12, $f12
/* E2E744 802BBE14 46206301 */  sub.d     $f12, $f12, $f0
/* E2E748 802BBE18 46206320 */  cvt.s.d   $f12, $f12
/* E2E74C 802BBE1C 0C00A6C9 */  jal       clamp_angle
/* E2E750 802BBE20 4620B5A0 */   cvt.s.d  $f22, $f22
/* E2E754 802BBE24 C6020048 */  lwc1      $f2, 0x48($s0)
/* E2E758 802BBE28 C604004C */  lwc1      $f4, 0x4c($s0)
/* E2E75C 802BBE2C C6060050 */  lwc1      $f6, 0x50($s0)
/* E2E760 802BBE30 E7A00010 */  swc1      $f0, 0x10($sp)
/* E2E764 802BBE34 46141080 */  add.s     $f2, $f2, $f20
/* E2E768 802BBE38 3C014278 */  lui       $at, 0x4278
/* E2E76C 802BBE3C 44810000 */  mtc1      $at, $f0
/* E2E770 802BBE40 00000000 */  nop
/* E2E774 802BBE44 46002100 */  add.s     $f4, $f4, $f0
/* E2E778 802BBE48 24020002 */  addiu     $v0, $zero, 2
/* E2E77C 802BBE4C 46163180 */  add.s     $f6, $f6, $f22
/* E2E780 802BBE50 3C014258 */  lui       $at, 0x4258
/* E2E784 802BBE54 44810000 */  mtc1      $at, $f0
/* E2E788 802BBE58 44051000 */  mfc1      $a1, $f2
/* E2E78C 802BBE5C 44062000 */  mfc1      $a2, $f4
/* E2E790 802BBE60 44073000 */  mfc1      $a3, $f6
/* E2E794 802BBE64 0000202D */  daddu     $a0, $zero, $zero
/* E2E798 802BBE68 AFA20018 */  sw        $v0, 0x18($sp)
/* E2E79C 802BBE6C 0C01C13C */  jal       func_800704F0
/* E2E7A0 802BBE70 E7A00014 */   swc1     $f0, 0x14($sp)
/* E2E7A4 802BBE74 8FBF0024 */  lw        $ra, 0x24($sp)
/* E2E7A8 802BBE78 8FB00020 */  lw        $s0, 0x20($sp)
/* E2E7AC 802BBE7C D7B60030 */  ldc1      $f22, 0x30($sp)
/* E2E7B0 802BBE80 D7B40028 */  ldc1      $f20, 0x28($sp)
/* E2E7B4 802BBE84 03E00008 */  jr        $ra
/* E2E7B8 802BBE88 27BD0038 */   addiu    $sp, $sp, 0x38

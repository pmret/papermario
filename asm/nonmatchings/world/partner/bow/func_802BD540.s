.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD540
/* 323E90 802BD540 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 323E94 802BD544 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 323E98 802BD548 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 323E9C 802BD54C AFB20038 */  sw        $s2, 0x38($sp)
/* 323EA0 802BD550 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* 323EA4 802BD554 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* 323EA8 802BD558 AFBF003C */  sw        $ra, 0x3c($sp)
/* 323EAC 802BD55C AFB10034 */  sw        $s1, 0x34($sp)
/* 323EB0 802BD560 AFB00030 */  sw        $s0, 0x30($sp)
/* 323EB4 802BD564 F7B60048 */  sdc1      $f22, 0x48($sp)
/* 323EB8 802BD568 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 323EBC 802BD56C 84430086 */  lh        $v1, 0x86($v0)
/* 323EC0 802BD570 24020010 */  addiu     $v0, $zero, 0x10
/* 323EC4 802BD574 5462003F */  bnel      $v1, $v0, .L802BD674
/* 323EC8 802BD578 2402FFFF */   addiu    $v0, $zero, -1
/* 323ECC 802BD57C C640001C */  lwc1      $f0, 0x1c($s2)
/* 323ED0 802BD580 44801000 */  mtc1      $zero, $f2
/* 323ED4 802BD584 00000000 */  nop       
/* 323ED8 802BD588 46020032 */  c.eq.s    $f0, $f2
/* 323EDC 802BD58C 00000000 */  nop       
/* 323EE0 802BD590 45000006 */  bc1f      .L802BD5AC
/* 323EE4 802BD594 00000000 */   nop      
/* 323EE8 802BD598 C6400024 */  lwc1      $f0, 0x24($s2)
/* 323EEC 802BD59C 46020032 */  c.eq.s    $f0, $f2
/* 323EF0 802BD5A0 00000000 */  nop       
/* 323EF4 802BD5A4 45010033 */  bc1t      .L802BD674
/* 323EF8 802BD5A8 2402FFFF */   addiu    $v0, $zero, -1
.L802BD5AC:
/* 323EFC 802BD5AC 8E46001C */  lw        $a2, 0x1c($s2)
/* 323F00 802BD5B0 44806000 */  mtc1      $zero, $f12
/* 323F04 802BD5B4 8E470024 */  lw        $a3, 0x24($s2)
/* 323F08 802BD5B8 0C00A720 */  jal       atan2
/* 323F0C 802BD5BC 46006386 */   mov.s    $f14, $f12
/* 323F10 802BD5C0 864200B0 */  lh        $v0, 0xb0($s2)
/* 323F14 802BD5C4 3C013F00 */  lui       $at, 0x3f00
/* 323F18 802BD5C8 4481A000 */  mtc1      $at, $f20
/* 323F1C 802BD5CC 44821000 */  mtc1      $v0, $f2
/* 323F20 802BD5D0 00000000 */  nop       
/* 323F24 802BD5D4 468010A0 */  cvt.s.w   $f2, $f2
/* 323F28 802BD5D8 46141082 */  mul.s     $f2, $f2, $f20
/* 323F2C 802BD5DC 00000000 */  nop       
/* 323F30 802BD5E0 46000586 */  mov.s     $f22, $f0
/* 323F34 802BD5E4 3C014334 */  lui       $at, 0x4334
/* 323F38 802BD5E8 44816000 */  mtc1      $at, $f12
/* 323F3C 802BD5EC C6460028 */  lwc1      $f6, 0x28($s2)
/* 323F40 802BD5F0 460CB300 */  add.s     $f12, $f22, $f12
/* 323F44 802BD5F4 C640002C */  lwc1      $f0, 0x2c($s2)
/* 323F48 802BD5F8 C6440030 */  lwc1      $f4, 0x30($s2)
/* 323F4C 802BD5FC 46020000 */  add.s     $f0, $f0, $f2
/* 323F50 802BD600 E7A60020 */  swc1      $f6, 0x20($sp)
/* 323F54 802BD604 E7A40024 */  swc1      $f4, 0x24($sp)
/* 323F58 802BD608 0C00A6C9 */  jal       clamp_angle
/* 323F5C 802BD60C E7A00028 */   swc1     $f0, 0x28($sp)
/* 323F60 802BD610 864200B2 */  lh        $v0, 0xb2($s2)
/* 323F64 802BD614 44821000 */  mtc1      $v0, $f2
/* 323F68 802BD618 00000000 */  nop       
/* 323F6C 802BD61C 468010A0 */  cvt.s.w   $f2, $f2
/* 323F70 802BD620 46141082 */  mul.s     $f2, $f2, $f20
/* 323F74 802BD624 00000000 */  nop       
/* 323F78 802BD628 27B00020 */  addiu     $s0, $sp, 0x20
/* 323F7C 802BD62C 0200202D */  daddu     $a0, $s0, $zero
/* 323F80 802BD630 27B10024 */  addiu     $s1, $sp, 0x24
/* 323F84 802BD634 44070000 */  mfc1      $a3, $f0
/* 323F88 802BD638 44061000 */  mfc1      $a2, $f2
/* 323F8C 802BD63C 0C00A7E7 */  jal       add_vec2D_polar
/* 323F90 802BD640 0220282D */   daddu    $a1, $s1, $zero
/* 323F94 802BD644 0000202D */  daddu     $a0, $zero, $zero
/* 323F98 802BD648 0240282D */  daddu     $a1, $s2, $zero
/* 323F9C 802BD64C 0200302D */  daddu     $a2, $s0, $zero
/* 323FA0 802BD650 84A200B2 */  lh        $v0, 0xb2($a1)
/* 323FA4 802BD654 27A70028 */  addiu     $a3, $sp, 0x28
/* 323FA8 802BD658 AFB10010 */  sw        $s1, 0x10($sp)
/* 323FAC 802BD65C E7B60018 */  swc1      $f22, 0x18($sp)
/* 323FB0 802BD660 44820000 */  mtc1      $v0, $f0
/* 323FB4 802BD664 00000000 */  nop       
/* 323FB8 802BD668 46800020 */  cvt.s.w   $f0, $f0
/* 323FBC 802BD66C 0C037B01 */  jal       do_lateral_collision
/* 323FC0 802BD670 E7A00014 */   swc1     $f0, 0x14($sp)
.L802BD674:
/* 323FC4 802BD674 8FBF003C */  lw        $ra, 0x3c($sp)
/* 323FC8 802BD678 8FB20038 */  lw        $s2, 0x38($sp)
/* 323FCC 802BD67C 8FB10034 */  lw        $s1, 0x34($sp)
/* 323FD0 802BD680 8FB00030 */  lw        $s0, 0x30($sp)
/* 323FD4 802BD684 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 323FD8 802BD688 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 323FDC 802BD68C 03E00008 */  jr        $ra
/* 323FE0 802BD690 27BD0050 */   addiu    $sp, $sp, 0x50

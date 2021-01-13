.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E5C_A7023C
/* A7023C 80241E5C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A70240 80241E60 AFB20018 */  sw        $s2, 0x18($sp)
/* A70244 80241E64 0080902D */  daddu     $s2, $a0, $zero
/* A70248 80241E68 AFBF001C */  sw        $ra, 0x1c($sp)
/* A7024C 80241E6C AFB10014 */  sw        $s1, 0x14($sp)
/* A70250 80241E70 AFB00010 */  sw        $s0, 0x10($sp)
/* A70254 80241E74 F7B40020 */  sdc1      $f20, 0x20($sp)
/* A70258 80241E78 8E500148 */  lw        $s0, 0x148($s2)
/* A7025C 80241E7C 0C00EABB */  jal       get_npc_unsafe
/* A70260 80241E80 86040008 */   lh       $a0, 8($s0)
/* A70264 80241E84 C60C006C */  lwc1      $f12, 0x6c($s0)
/* A70268 80241E88 46806320 */  cvt.s.w   $f12, $f12
/* A7026C 80241E8C 0040882D */  daddu     $s1, $v0, $zero
/* A70270 80241E90 C6140070 */  lwc1      $f20, 0x70($s0)
/* A70274 80241E94 4680A520 */  cvt.s.w   $f20, $f20
/* A70278 80241E98 3C014059 */  lui       $at, 0x4059
/* A7027C 80241E9C 44810800 */  mtc1      $at, $f1
/* A70280 80241EA0 44800000 */  mtc1      $zero, $f0
/* A70284 80241EA4 4600A521 */  cvt.d.s   $f20, $f20
/* A70288 80241EA8 4620A503 */  div.d     $f20, $f20, $f0
/* A7028C 80241EAC 0C00A8BB */  jal       sin_deg
/* A70290 80241EB0 4620A520 */   cvt.s.d  $f20, $f20
/* A70294 80241EB4 3C014018 */  lui       $at, 0x4018
/* A70298 80241EB8 44811800 */  mtc1      $at, $f3
/* A7029C 80241EBC 44801000 */  mtc1      $zero, $f2
/* A702A0 80241EC0 46000021 */  cvt.d.s   $f0, $f0
/* A702A4 80241EC4 46220002 */  mul.d     $f0, $f0, $f2
/* A702A8 80241EC8 00000000 */  nop
/* A702AC 80241ECC 4600A0A1 */  cvt.d.s   $f2, $f20
/* A702B0 80241ED0 46201080 */  add.d     $f2, $f2, $f0
/* A702B4 80241ED4 462010A0 */  cvt.s.d   $f2, $f2
/* A702B8 80241ED8 E622003C */  swc1      $f2, 0x3c($s1)
/* A702BC 80241EDC 8E02006C */  lw        $v0, 0x6c($s0)
/* A702C0 80241EE0 2442000A */  addiu     $v0, $v0, 0xa
/* A702C4 80241EE4 44826000 */  mtc1      $v0, $f12
/* A702C8 80241EE8 00000000 */  nop
/* A702CC 80241EEC 0C00A6C9 */  jal       clamp_angle
/* A702D0 80241EF0 46806320 */   cvt.s.w  $f12, $f12
/* A702D4 80241EF4 4600010D */  trunc.w.s $f4, $f0
/* A702D8 80241EF8 E604006C */  swc1      $f4, 0x6c($s0)
/* A702DC 80241EFC 9622008E */  lhu       $v0, 0x8e($s1)
/* A702E0 80241F00 2442FFFF */  addiu     $v0, $v0, -1
/* A702E4 80241F04 A622008E */  sh        $v0, 0x8e($s1)
/* A702E8 80241F08 00021400 */  sll       $v0, $v0, 0x10
/* A702EC 80241F0C 1C400008 */  bgtz      $v0, .L80241F30
/* A702F0 80241F10 00000000 */   nop
/* A702F4 80241F14 8E0200CC */  lw        $v0, 0xcc($s0)
/* A702F8 80241F18 8C430000 */  lw        $v1, ($v0)
/* A702FC 80241F1C 24020003 */  addiu     $v0, $zero, 3
/* A70300 80241F20 A622008E */  sh        $v0, 0x8e($s1)
/* A70304 80241F24 24020032 */  addiu     $v0, $zero, 0x32
/* A70308 80241F28 AE230028 */  sw        $v1, 0x28($s1)
/* A7030C 80241F2C AE420070 */  sw        $v0, 0x70($s2)
.L80241F30:
/* A70310 80241F30 8FBF001C */  lw        $ra, 0x1c($sp)
/* A70314 80241F34 8FB20018 */  lw        $s2, 0x18($sp)
/* A70318 80241F38 8FB10014 */  lw        $s1, 0x14($sp)
/* A7031C 80241F3C 8FB00010 */  lw        $s0, 0x10($sp)
/* A70320 80241F40 D7B40020 */  ldc1      $f20, 0x20($sp)
/* A70324 80241F44 03E00008 */  jr        $ra
/* A70328 80241F48 27BD0028 */   addiu    $sp, $sp, 0x28

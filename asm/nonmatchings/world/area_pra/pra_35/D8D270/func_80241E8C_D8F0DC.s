.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E8C_D8F0DC
/* D8F0DC 80241E8C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* D8F0E0 80241E90 AFB10034 */  sw        $s1, 0x34($sp)
/* D8F0E4 80241E94 0080882D */  daddu     $s1, $a0, $zero
/* D8F0E8 80241E98 AFBF0038 */  sw        $ra, 0x38($sp)
/* D8F0EC 80241E9C AFB00030 */  sw        $s0, 0x30($sp)
/* D8F0F0 80241EA0 8E300148 */  lw        $s0, 0x148($s1)
/* D8F0F4 80241EA4 0C00EABB */  jal       get_npc_unsafe
/* D8F0F8 80241EA8 86040008 */   lh       $a0, 8($s0)
/* D8F0FC 80241EAC 0040282D */  daddu     $a1, $v0, $zero
/* D8F100 80241EB0 94A2008E */  lhu       $v0, 0x8e($a1)
/* D8F104 80241EB4 2442FFFF */  addiu     $v0, $v0, -1
/* D8F108 80241EB8 A4A2008E */  sh        $v0, 0x8e($a1)
/* D8F10C 80241EBC 00021400 */  sll       $v0, $v0, 0x10
/* D8F110 80241EC0 1C400023 */  bgtz      $v0, .L80241F50
/* D8F114 80241EC4 24020004 */   addiu    $v0, $zero, 4
/* D8F118 80241EC8 8E0300CC */  lw        $v1, 0xcc($s0)
/* D8F11C 80241ECC AE02006C */  sw        $v0, 0x6c($s0)
/* D8F120 80241ED0 8C620000 */  lw        $v0, ($v1)
/* D8F124 80241ED4 ACA20028 */  sw        $v0, 0x28($a1)
/* D8F128 80241ED8 9602007A */  lhu       $v0, 0x7a($s0)
/* D8F12C 80241EDC A4A2008E */  sh        $v0, 0x8e($a1)
/* D8F130 80241EE0 8E020078 */  lw        $v0, 0x78($s0)
/* D8F134 80241EE4 28420008 */  slti      $v0, $v0, 8
/* D8F138 80241EE8 14400018 */  bnez      $v0, .L80241F4C
/* D8F13C 80241EEC 24020021 */   addiu    $v0, $zero, 0x21
/* D8F140 80241EF0 24040003 */  addiu     $a0, $zero, 3
/* D8F144 80241EF4 27A30028 */  addiu     $v1, $sp, 0x28
/* D8F148 80241EF8 84A700A8 */  lh        $a3, 0xa8($a1)
/* D8F14C 80241EFC 3C013F80 */  lui       $at, 0x3f80
/* D8F150 80241F00 44810000 */  mtc1      $at, $f0
/* D8F154 80241F04 3C014000 */  lui       $at, 0x4000
/* D8F158 80241F08 44811000 */  mtc1      $at, $f2
/* D8F15C 80241F0C 3C01C1A0 */  lui       $at, 0xc1a0
/* D8F160 80241F10 44812000 */  mtc1      $at, $f4
/* D8F164 80241F14 44873000 */  mtc1      $a3, $f6
/* D8F168 80241F18 00000000 */  nop       
/* D8F16C 80241F1C 468031A0 */  cvt.s.w   $f6, $f6
/* D8F170 80241F20 E7A00010 */  swc1      $f0, 0x10($sp)
/* D8F174 80241F24 E7A20014 */  swc1      $f2, 0x14($sp)
/* D8F178 80241F28 E7A40018 */  swc1      $f4, 0x18($sp)
/* D8F17C 80241F2C 8E020078 */  lw        $v0, 0x78($s0)
/* D8F180 80241F30 44073000 */  mfc1      $a3, $f6
/* D8F184 80241F34 0000302D */  daddu     $a2, $zero, $zero
/* D8F188 80241F38 AFA30020 */  sw        $v1, 0x20($sp)
/* D8F18C 80241F3C 2442FFFF */  addiu     $v0, $v0, -1
/* D8F190 80241F40 0C01BFA4 */  jal       fx_emote
/* D8F194 80241F44 AFA2001C */   sw       $v0, 0x1c($sp)
/* D8F198 80241F48 24020021 */  addiu     $v0, $zero, 0x21
.L80241F4C:
/* D8F19C 80241F4C AE220070 */  sw        $v0, 0x70($s1)
.L80241F50:
/* D8F1A0 80241F50 8FBF0038 */  lw        $ra, 0x38($sp)
/* D8F1A4 80241F54 8FB10034 */  lw        $s1, 0x34($sp)
/* D8F1A8 80241F58 8FB00030 */  lw        $s0, 0x30($sp)
/* D8F1AC 80241F5C 03E00008 */  jr        $ra
/* D8F1B0 80241F60 27BD0040 */   addiu    $sp, $sp, 0x40

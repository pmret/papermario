.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024095C_E0F0FC
/* E0F0FC 8024095C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E0F100 80240960 AFB10014 */  sw        $s1, 0x14($sp)
/* E0F104 80240964 0080882D */  daddu     $s1, $a0, $zero
/* E0F108 80240968 AFBF001C */  sw        $ra, 0x1c($sp)
/* E0F10C 8024096C AFB20018 */  sw        $s2, 0x18($sp)
/* E0F110 80240970 AFB00010 */  sw        $s0, 0x10($sp)
/* E0F114 80240974 8E300148 */  lw        $s0, 0x148($s1)
/* E0F118 80240978 86040008 */  lh        $a0, 8($s0)
/* E0F11C 8024097C 0C00EABB */  jal       get_npc_unsafe
/* E0F120 80240980 00A0902D */   daddu    $s2, $a1, $zero
/* E0F124 80240984 8E230078 */  lw        $v1, 0x78($s1)
/* E0F128 80240988 24630001 */  addiu     $v1, $v1, 1
/* E0F12C 8024098C AE230078 */  sw        $v1, 0x78($s1)
/* E0F130 80240990 8E0400D0 */  lw        $a0, 0xd0($s0)
/* E0F134 80240994 8C840000 */  lw        $a0, ($a0)
/* E0F138 80240998 0064182A */  slt       $v1, $v1, $a0
/* E0F13C 8024099C 14600002 */  bnez      $v1, .L802409A8
/* E0F140 802409A0 0040282D */   daddu    $a1, $v0, $zero
/* E0F144 802409A4 AE200078 */  sw        $zero, 0x78($s1)
.L802409A8:
/* E0F148 802409A8 8E0200CC */  lw        $v0, 0xcc($s0)
/* E0F14C 802409AC 8C420004 */  lw        $v0, 4($v0)
/* E0F150 802409B0 ACA20028 */  sw        $v0, 0x28($a1)
/* E0F154 802409B4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* E0F158 802409B8 8C42007C */  lw        $v0, 0x7c($v0)
/* E0F15C 802409BC 04410004 */  bgez      $v0, .L802409D0
/* E0F160 802409C0 00000000 */   nop
/* E0F164 802409C4 C6400000 */  lwc1      $f0, ($s2)
/* E0F168 802409C8 0809027C */  j         .L802409F0
/* E0F16C 802409CC E4A00018 */   swc1     $f0, 0x18($a1)
.L802409D0:
/* E0F170 802409D0 3C018024 */  lui       $at, %hi(D_80243DF8_E12598)
/* E0F174 802409D4 D4223DF8 */  ldc1      $f2, %lo(D_80243DF8_E12598)($at)
/* E0F178 802409D8 44820000 */  mtc1      $v0, $f0
/* E0F17C 802409DC 00000000 */  nop
/* E0F180 802409E0 46800021 */  cvt.d.w   $f0, $f0
/* E0F184 802409E4 46220003 */  div.d     $f0, $f0, $f2
/* E0F188 802409E8 46200020 */  cvt.s.d   $f0, $f0
/* E0F18C 802409EC E4A00018 */  swc1      $f0, 0x18($a1)
.L802409F0:
/* E0F190 802409F0 24020001 */  addiu     $v0, $zero, 1
/* E0F194 802409F4 AE220070 */  sw        $v0, 0x70($s1)
/* E0F198 802409F8 8FBF001C */  lw        $ra, 0x1c($sp)
/* E0F19C 802409FC 8FB20018 */  lw        $s2, 0x18($sp)
/* E0F1A0 80240A00 8FB10014 */  lw        $s1, 0x14($sp)
/* E0F1A4 80240A04 8FB00010 */  lw        $s0, 0x10($sp)
/* E0F1A8 80240A08 03E00008 */  jr        $ra
/* E0F1AC 80240A0C 27BD0020 */   addiu    $sp, $sp, 0x20

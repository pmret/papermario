.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80245A08_A92488
.double 32767.0

.section .text

glabel func_8024075C_A8D1DC
/* A8D1DC 8024075C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A8D1E0 80240760 AFB10014 */  sw        $s1, 0x14($sp)
/* A8D1E4 80240764 0080882D */  daddu     $s1, $a0, $zero
/* A8D1E8 80240768 AFBF001C */  sw        $ra, 0x1c($sp)
/* A8D1EC 8024076C AFB20018 */  sw        $s2, 0x18($sp)
/* A8D1F0 80240770 AFB00010 */  sw        $s0, 0x10($sp)
/* A8D1F4 80240774 8E300148 */  lw        $s0, 0x148($s1)
/* A8D1F8 80240778 86040008 */  lh        $a0, 8($s0)
/* A8D1FC 8024077C 0C00EABB */  jal       get_npc_unsafe
/* A8D200 80240780 00A0902D */   daddu    $s2, $a1, $zero
/* A8D204 80240784 8E230078 */  lw        $v1, 0x78($s1)
/* A8D208 80240788 24630001 */  addiu     $v1, $v1, 1
/* A8D20C 8024078C AE230078 */  sw        $v1, 0x78($s1)
/* A8D210 80240790 8E0400D0 */  lw        $a0, 0xd0($s0)
/* A8D214 80240794 8C840000 */  lw        $a0, ($a0)
/* A8D218 80240798 0064182A */  slt       $v1, $v1, $a0
/* A8D21C 8024079C 14600002 */  bnez      $v1, .L802407A8
/* A8D220 802407A0 0040282D */   daddu    $a1, $v0, $zero
/* A8D224 802407A4 AE200078 */  sw        $zero, 0x78($s1)
.L802407A8:
/* A8D228 802407A8 8E0200CC */  lw        $v0, 0xcc($s0)
/* A8D22C 802407AC 8C420004 */  lw        $v0, 4($v0)
/* A8D230 802407B0 ACA20028 */  sw        $v0, 0x28($a1)
/* A8D234 802407B4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* A8D238 802407B8 8C42007C */  lw        $v0, 0x7c($v0)
/* A8D23C 802407BC 04410004 */  bgez      $v0, .L802407D0
/* A8D240 802407C0 00000000 */   nop
/* A8D244 802407C4 C6400000 */  lwc1      $f0, ($s2)
/* A8D248 802407C8 080901FC */  j         .L802407F0
/* A8D24C 802407CC E4A00018 */   swc1     $f0, 0x18($a1)
.L802407D0:
/* A8D250 802407D0 3C018024 */  lui       $at, %hi(D_80245A08_A92488)
/* A8D254 802407D4 D4225A08 */  ldc1      $f2, %lo(D_80245A08_A92488)($at)
/* A8D258 802407D8 44820000 */  mtc1      $v0, $f0
/* A8D25C 802407DC 00000000 */  nop
/* A8D260 802407E0 46800021 */  cvt.d.w   $f0, $f0
/* A8D264 802407E4 46220003 */  div.d     $f0, $f0, $f2
/* A8D268 802407E8 46200020 */  cvt.s.d   $f0, $f0
/* A8D26C 802407EC E4A00018 */  swc1      $f0, 0x18($a1)
.L802407F0:
/* A8D270 802407F0 24020001 */  addiu     $v0, $zero, 1
/* A8D274 802407F4 AE220070 */  sw        $v0, 0x70($s1)
/* A8D278 802407F8 8FBF001C */  lw        $ra, 0x1c($sp)
/* A8D27C 802407FC 8FB20018 */  lw        $s2, 0x18($sp)
/* A8D280 80240800 8FB10014 */  lw        $s1, 0x14($sp)
/* A8D284 80240804 8FB00010 */  lw        $s0, 0x10($sp)
/* A8D288 80240808 03E00008 */  jr        $ra
/* A8D28C 8024080C 27BD0020 */   addiu    $sp, $sp, 0x20

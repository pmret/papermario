.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80251A98_9D6E78
.double 0.3

glabel D_80251AA0_9D6E80
.double 32767.0

.section .text

glabel func_80240540_9C5920
/* 9C5920 80240540 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9C5924 80240544 AFB10014 */  sw        $s1, 0x14($sp)
/* 9C5928 80240548 0080882D */  daddu     $s1, $a0, $zero
/* 9C592C 8024054C AFBF001C */  sw        $ra, 0x1c($sp)
/* 9C5930 80240550 AFB20018 */  sw        $s2, 0x18($sp)
/* 9C5934 80240554 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C5938 80240558 8E300148 */  lw        $s0, 0x148($s1)
/* 9C593C 8024055C 86040008 */  lh        $a0, 8($s0)
/* 9C5940 80240560 0C00EABB */  jal       get_npc_unsafe
/* 9C5944 80240564 00A0902D */   daddu    $s2, $a1, $zero
/* 9C5948 80240568 8E0300CC */  lw        $v1, 0xcc($s0)
/* 9C594C 8024056C 8C630004 */  lw        $v1, 4($v1)
/* 9C5950 80240570 0040202D */  daddu     $a0, $v0, $zero
/* 9C5954 80240574 AC830028 */  sw        $v1, 0x28($a0)
/* 9C5958 80240578 8E0200D0 */  lw        $v0, 0xd0($s0)
/* 9C595C 8024057C 8C420014 */  lw        $v0, 0x14($v0)
/* 9C5960 80240580 04410009 */  bgez      $v0, .L802405A8
/* 9C5964 80240584 00000000 */   nop
/* 9C5968 80240588 C640000C */  lwc1      $f0, 0xc($s2)
/* 9C596C 8024058C 3C018025 */  lui       $at, %hi(D_80251A98_9D6E78)
/* 9C5970 80240590 D4221A98 */  ldc1      $f2, %lo(D_80251A98_9D6E78)($at)
/* 9C5974 80240594 46000021 */  cvt.d.s   $f0, $f0
/* 9C5978 80240598 46220002 */  mul.d     $f0, $f0, $f2
/* 9C597C 8024059C 00000000 */  nop
/* 9C5980 802405A0 08090171 */  j         .L802405C4
/* 9C5984 802405A4 46200020 */   cvt.s.d  $f0, $f0
.L802405A8:
/* 9C5988 802405A8 3C018025 */  lui       $at, %hi(D_80251AA0_9D6E80)
/* 9C598C 802405AC D4221AA0 */  ldc1      $f2, %lo(D_80251AA0_9D6E80)($at)
/* 9C5990 802405B0 44820000 */  mtc1      $v0, $f0
/* 9C5994 802405B4 00000000 */  nop
/* 9C5998 802405B8 46800021 */  cvt.d.w   $f0, $f0
/* 9C599C 802405BC 46220003 */  div.d     $f0, $f0, $f2
/* 9C59A0 802405C0 46200020 */  cvt.s.d   $f0, $f0
.L802405C4:
/* 9C59A4 802405C4 E4800018 */  swc1      $f0, 0x18($a0)
/* 9C59A8 802405C8 24020010 */  addiu     $v0, $zero, 0x10
/* 9C59AC 802405CC AE200074 */  sw        $zero, 0x74($s1)
/* 9C59B0 802405D0 AE220070 */  sw        $v0, 0x70($s1)
/* 9C59B4 802405D4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9C59B8 802405D8 8FB20018 */  lw        $s2, 0x18($sp)
/* 9C59BC 802405DC 8FB10014 */  lw        $s1, 0x14($sp)
/* 9C59C0 802405E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C59C4 802405E4 03E00008 */  jr        $ra
/* 9C59C8 802405E8 27BD0020 */   addiu    $sp, $sp, 0x20

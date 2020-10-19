.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240984_BDDB34
/* BDDB34 80240984 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BDDB38 80240988 AFB20018 */  sw        $s2, 0x18($sp)
/* BDDB3C 8024098C 0080902D */  daddu     $s2, $a0, $zero
/* BDDB40 80240990 AFBF001C */  sw        $ra, 0x1c($sp)
/* BDDB44 80240994 AFB10014 */  sw        $s1, 0x14($sp)
/* BDDB48 80240998 AFB00010 */  sw        $s0, 0x10($sp)
/* BDDB4C 8024099C 8E500148 */  lw        $s0, 0x148($s2)
/* BDDB50 802409A0 86040008 */  lh        $a0, 8($s0)
/* BDDB54 802409A4 0C00EABB */  jal       get_npc_unsafe
/* BDDB58 802409A8 00A0882D */   daddu    $s1, $a1, $zero
/* BDDB5C 802409AC 0040182D */  daddu     $v1, $v0, $zero
/* BDDB60 802409B0 9462008E */  lhu       $v0, 0x8e($v1)
/* BDDB64 802409B4 2442FFFF */  addiu     $v0, $v0, -1
/* BDDB68 802409B8 A462008E */  sh        $v0, 0x8e($v1)
/* BDDB6C 802409BC 00021400 */  sll       $v0, $v0, 0x10
/* BDDB70 802409C0 1C400015 */  bgtz      $v0, .L80240A18
/* BDDB74 802409C4 00000000 */   nop      
/* BDDB78 802409C8 8E0200CC */  lw        $v0, 0xcc($s0)
/* BDDB7C 802409CC 8C420004 */  lw        $v0, 4($v0)
/* BDDB80 802409D0 AC620028 */  sw        $v0, 0x28($v1)
/* BDDB84 802409D4 8E0200D0 */  lw        $v0, 0xd0($s0)
/* BDDB88 802409D8 8C420014 */  lw        $v0, 0x14($v0)
/* BDDB8C 802409DC 04410004 */  bgez      $v0, .L802409F0
/* BDDB90 802409E0 00000000 */   nop      
/* BDDB94 802409E4 C6200000 */  lwc1      $f0, ($s1)
/* BDDB98 802409E8 08090284 */  j         .L80240A10
/* BDDB9C 802409EC E4600018 */   swc1     $f0, 0x18($v1)
.L802409F0:
/* BDDBA0 802409F0 3C018024 */  lui       $at, 0x8024
/* BDDBA4 802409F4 D4221B00 */  ldc1      $f2, 0x1b00($at)
/* BDDBA8 802409F8 44820000 */  mtc1      $v0, $f0
/* BDDBAC 802409FC 00000000 */  nop       
/* BDDBB0 80240A00 46800021 */  cvt.d.w   $f0, $f0
/* BDDBB4 80240A04 46220003 */  div.d     $f0, $f0, $f2
/* BDDBB8 80240A08 46200020 */  cvt.s.d   $f0, $f0
/* BDDBBC 80240A0C E4600018 */  swc1      $f0, 0x18($v1)
.L80240A10:
/* BDDBC0 80240A10 24020029 */  addiu     $v0, $zero, 0x29
/* BDDBC4 80240A14 AE420070 */  sw        $v0, 0x70($s2)
.L80240A18:
/* BDDBC8 80240A18 8FBF001C */  lw        $ra, 0x1c($sp)
/* BDDBCC 80240A1C 8FB20018 */  lw        $s2, 0x18($sp)
/* BDDBD0 80240A20 8FB10014 */  lw        $s1, 0x14($sp)
/* BDDBD4 80240A24 8FB00010 */  lw        $s0, 0x10($sp)
/* BDDBD8 80240A28 03E00008 */  jr        $ra
/* BDDBDC 80240A2C 27BD0020 */   addiu    $sp, $sp, 0x20

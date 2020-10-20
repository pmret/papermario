.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241650_D3BC20
/* D3BC20 80241650 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D3BC24 80241654 AFB10014 */  sw        $s1, 0x14($sp)
/* D3BC28 80241658 0080882D */  daddu     $s1, $a0, $zero
/* D3BC2C 8024165C AFB00010 */  sw        $s0, 0x10($sp)
/* D3BC30 80241660 00A0802D */  daddu     $s0, $a1, $zero
/* D3BC34 80241664 AFBF0018 */  sw        $ra, 0x18($sp)
/* D3BC38 80241668 0C00EABB */  jal       get_npc_unsafe
/* D3BC3C 8024166C 2404FFFC */   addiu    $a0, $zero, -4
/* D3BC40 80241670 12000003 */  beqz      $s0, .L80241680
/* D3BC44 80241674 0040182D */   daddu    $v1, $v0, $zero
/* D3BC48 80241678 2402003C */  addiu     $v0, $zero, 0x3c
/* D3BC4C 8024167C AE220070 */  sw        $v0, 0x70($s1)
.L80241680:
/* D3BC50 80241680 C462000C */  lwc1      $f2, 0xc($v1)
/* D3BC54 80241684 3C0141F0 */  lui       $at, 0x41f0
/* D3BC58 80241688 44810000 */  mtc1      $at, $f0
/* D3BC5C 8024168C 00000000 */  nop       
/* D3BC60 80241690 46001000 */  add.s     $f0, $f2, $f0
/* D3BC64 80241694 3C0143B4 */  lui       $at, 0x43b4
/* D3BC68 80241698 44811000 */  mtc1      $at, $f2
/* D3BC6C 8024169C 00000000 */  nop       
/* D3BC70 802416A0 4600103E */  c.le.s    $f2, $f0
/* D3BC74 802416A4 00000000 */  nop       
/* D3BC78 802416A8 45000003 */  bc1f      .L802416B8
/* D3BC7C 802416AC E460000C */   swc1     $f0, 0xc($v1)
/* D3BC80 802416B0 46020001 */  sub.s     $f0, $f0, $f2
/* D3BC84 802416B4 E460000C */  swc1      $f0, 0xc($v1)
.L802416B8:
/* D3BC88 802416B8 8E230070 */  lw        $v1, 0x70($s1)
/* D3BC8C 802416BC 2463FFFF */  addiu     $v1, $v1, -1
/* D3BC90 802416C0 000317C3 */  sra       $v0, $v1, 0x1f
/* D3BC94 802416C4 AE230070 */  sw        $v1, 0x70($s1)
/* D3BC98 802416C8 8FBF0018 */  lw        $ra, 0x18($sp)
/* D3BC9C 802416CC 8FB10014 */  lw        $s1, 0x14($sp)
/* D3BCA0 802416D0 8FB00010 */  lw        $s0, 0x10($sp)
/* D3BCA4 802416D4 30420002 */  andi      $v0, $v0, 2
/* D3BCA8 802416D8 03E00008 */  jr        $ra
/* D3BCAC 802416DC 27BD0020 */   addiu    $sp, $sp, 0x20

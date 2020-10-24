.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242D0C_BE64BC
/* BE64BC 80242D0C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BE64C0 80242D10 AFB20018 */  sw        $s2, 0x18($sp)
/* BE64C4 80242D14 0080902D */  daddu     $s2, $a0, $zero
/* BE64C8 80242D18 AFBF001C */  sw        $ra, 0x1c($sp)
/* BE64CC 80242D1C AFB10014 */  sw        $s1, 0x14($sp)
/* BE64D0 80242D20 AFB00010 */  sw        $s0, 0x10($sp)
/* BE64D4 80242D24 8E500148 */  lw        $s0, 0x148($s2)
/* BE64D8 80242D28 86040008 */  lh        $a0, 8($s0)
/* BE64DC 80242D2C 0C00EABB */  jal       get_npc_unsafe
/* BE64E0 80242D30 00A0882D */   daddu    $s1, $a1, $zero
/* BE64E4 80242D34 0040182D */  daddu     $v1, $v0, $zero
/* BE64E8 80242D38 9462008E */  lhu       $v0, 0x8e($v1)
/* BE64EC 80242D3C 2442FFFF */  addiu     $v0, $v0, -1
/* BE64F0 80242D40 A462008E */  sh        $v0, 0x8e($v1)
/* BE64F4 80242D44 00021400 */  sll       $v0, $v0, 0x10
/* BE64F8 80242D48 1C400015 */  bgtz      $v0, .L80242DA0
/* BE64FC 80242D4C 00000000 */   nop      
/* BE6500 80242D50 8E0200CC */  lw        $v0, 0xcc($s0)
/* BE6504 80242D54 8C420004 */  lw        $v0, 4($v0)
/* BE6508 80242D58 AC620028 */  sw        $v0, 0x28($v1)
/* BE650C 80242D5C 8E0200D0 */  lw        $v0, 0xd0($s0)
/* BE6510 80242D60 8C420014 */  lw        $v0, 0x14($v0)
/* BE6514 80242D64 04410004 */  bgez      $v0, .L80242D78
/* BE6518 80242D68 00000000 */   nop      
/* BE651C 80242D6C C6200000 */  lwc1      $f0, ($s1)
/* BE6520 80242D70 08090B66 */  j         .L80242D98
/* BE6524 80242D74 E4600018 */   swc1     $f0, 0x18($v1)
.L80242D78:
/* BE6528 80242D78 3C018024 */  lui       $at, 0x8024
/* BE652C 80242D7C D4224348 */  ldc1      $f2, 0x4348($at)
/* BE6530 80242D80 44820000 */  mtc1      $v0, $f0
/* BE6534 80242D84 00000000 */  nop       
/* BE6538 80242D88 46800021 */  cvt.d.w   $f0, $f0
/* BE653C 80242D8C 46220003 */  div.d     $f0, $f0, $f2
/* BE6540 80242D90 46200020 */  cvt.s.d   $f0, $f0
/* BE6544 80242D94 E4600018 */  swc1      $f0, 0x18($v1)
.L80242D98:
/* BE6548 80242D98 24020029 */  addiu     $v0, $zero, 0x29
/* BE654C 80242D9C AE420070 */  sw        $v0, 0x70($s2)
.L80242DA0:
/* BE6550 80242DA0 8FBF001C */  lw        $ra, 0x1c($sp)
/* BE6554 80242DA4 8FB20018 */  lw        $s2, 0x18($sp)
/* BE6558 80242DA8 8FB10014 */  lw        $s1, 0x14($sp)
/* BE655C 80242DAC 8FB00010 */  lw        $s0, 0x10($sp)
/* BE6560 80242DB0 03E00008 */  jr        $ra
/* BE6564 80242DB4 27BD0020 */   addiu    $sp, $sp, 0x20

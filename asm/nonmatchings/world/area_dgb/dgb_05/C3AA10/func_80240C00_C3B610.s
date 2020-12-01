.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C00_C3B610
/* C3B610 80240C00 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C3B614 80240C04 AFB20018 */  sw        $s2, 0x18($sp)
/* C3B618 80240C08 0080902D */  daddu     $s2, $a0, $zero
/* C3B61C 80240C0C AFBF001C */  sw        $ra, 0x1c($sp)
/* C3B620 80240C10 AFB10014 */  sw        $s1, 0x14($sp)
/* C3B624 80240C14 AFB00010 */  sw        $s0, 0x10($sp)
/* C3B628 80240C18 8E500148 */  lw        $s0, 0x148($s2)
/* C3B62C 80240C1C 86040008 */  lh        $a0, 8($s0)
/* C3B630 80240C20 0C00EABB */  jal       get_npc_unsafe
/* C3B634 80240C24 00A0882D */   daddu    $s1, $a1, $zero
/* C3B638 80240C28 0040182D */  daddu     $v1, $v0, $zero
/* C3B63C 80240C2C 9462008E */  lhu       $v0, 0x8e($v1)
/* C3B640 80240C30 2442FFFF */  addiu     $v0, $v0, -1
/* C3B644 80240C34 A462008E */  sh        $v0, 0x8e($v1)
/* C3B648 80240C38 00021400 */  sll       $v0, $v0, 0x10
/* C3B64C 80240C3C 1C400015 */  bgtz      $v0, .L80240C94
/* C3B650 80240C40 00000000 */   nop      
/* C3B654 80240C44 8E0200CC */  lw        $v0, 0xcc($s0)
/* C3B658 80240C48 8C420004 */  lw        $v0, 4($v0)
/* C3B65C 80240C4C AC620028 */  sw        $v0, 0x28($v1)
/* C3B660 80240C50 8E0200D0 */  lw        $v0, 0xd0($s0)
/* C3B664 80240C54 8C420014 */  lw        $v0, 0x14($v0)
/* C3B668 80240C58 04410004 */  bgez      $v0, .L80240C6C
/* C3B66C 80240C5C 00000000 */   nop      
/* C3B670 80240C60 C6200000 */  lwc1      $f0, ($s1)
/* C3B674 80240C64 08090323 */  j         .L80240C8C
/* C3B678 80240C68 E4600018 */   swc1     $f0, 0x18($v1)
.L80240C6C:
/* C3B67C 80240C6C 3C018024 */  lui       $at, %hi(D_80242348)
/* C3B680 80240C70 D4222348 */  ldc1      $f2, %lo(D_80242348)($at)
/* C3B684 80240C74 44820000 */  mtc1      $v0, $f0
/* C3B688 80240C78 00000000 */  nop       
/* C3B68C 80240C7C 46800021 */  cvt.d.w   $f0, $f0
/* C3B690 80240C80 46220003 */  div.d     $f0, $f0, $f2
/* C3B694 80240C84 46200020 */  cvt.s.d   $f0, $f0
/* C3B698 80240C88 E4600018 */  swc1      $f0, 0x18($v1)
.L80240C8C:
/* C3B69C 80240C8C 24020029 */  addiu     $v0, $zero, 0x29
/* C3B6A0 80240C90 AE420070 */  sw        $v0, 0x70($s2)
.L80240C94:
/* C3B6A4 80240C94 8FBF001C */  lw        $ra, 0x1c($sp)
/* C3B6A8 80240C98 8FB20018 */  lw        $s2, 0x18($sp)
/* C3B6AC 80240C9C 8FB10014 */  lw        $s1, 0x14($sp)
/* C3B6B0 80240CA0 8FB00010 */  lw        $s0, 0x10($sp)
/* C3B6B4 80240CA4 03E00008 */  jr        $ra
/* C3B6B8 80240CA8 27BD0020 */   addiu    $sp, $sp, 0x20

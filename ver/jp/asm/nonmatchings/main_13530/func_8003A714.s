.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003A714
/* 15B14 8003A714 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 15B18 8003A718 F7B60020 */  sdc1      $f22, 0x20($sp)
/* 15B1C 8003A71C 4485B000 */  mtc1      $a1, $f22
/* 15B20 8003A720 3C0140C9 */  lui       $at, 0x40c9
/* 15B24 8003A724 34210FD0 */  ori       $at, $at, 0xfd0
/* 15B28 8003A728 44810000 */  mtc1      $at, $f0
/* 15B2C 8003A72C 44862000 */  mtc1      $a2, $f4
/* 15B30 8003A730 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 15B34 8003A734 46002502 */  mul.s     $f20, $f4, $f0
/* 15B38 8003A738 00000000 */  nop
/* 15B3C 8003A73C AFB00010 */  sw        $s0, 0x10($sp)
/* 15B40 8003A740 3C0143B4 */  lui       $at, 0x43b4
/* 15B44 8003A744 44810000 */  mtc1      $at, $f0
/* 15B48 8003A748 0080802D */  daddu     $s0, $a0, $zero
/* 15B4C 8003A74C AFBF0014 */  sw        $ra, 0x14($sp)
/* 15B50 8003A750 4600A503 */  div.s     $f20, $f20, $f0
/* 15B54 8003A754 0C00A84B */  jal       func_8002A12C
/* 15B58 8003A758 4600A306 */   mov.s    $f12, $f20
/* 15B5C 8003A75C 4600A306 */  mov.s     $f12, $f20
/* 15B60 8003A760 0C00A864 */  jal       func_8002A190
/* 15B64 8003A764 46000506 */   mov.s    $f20, $f0
/* 15B68 8003A768 4614B502 */  mul.s     $f20, $f22, $f20
/* 15B6C 8003A76C 00000000 */  nop
/* 15B70 8003A770 4600B587 */  neg.s     $f22, $f22
/* 15B74 8003A774 4600B582 */  mul.s     $f22, $f22, $f0
/* 15B78 8003A778 00000000 */  nop
/* 15B7C 8003A77C C6020038 */  lwc1      $f2, 0x38($s0)
/* 15B80 8003A780 46141080 */  add.s     $f2, $f2, $f20
/* 15B84 8003A784 C6000040 */  lwc1      $f0, 0x40($s0)
/* 15B88 8003A788 46160000 */  add.s     $f0, $f0, $f22
/* 15B8C 8003A78C E6020038 */  swc1      $f2, 0x38($s0)
/* 15B90 8003A790 E6000040 */  swc1      $f0, 0x40($s0)
/* 15B94 8003A794 8FBF0014 */  lw        $ra, 0x14($sp)
/* 15B98 8003A798 8FB00010 */  lw        $s0, 0x10($sp)
/* 15B9C 8003A79C D7B60020 */  ldc1      $f22, 0x20($sp)
/* 15BA0 8003A7A0 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 15BA4 8003A7A4 03E00008 */  jr        $ra
/* 15BA8 8003A7A8 27BD0028 */   addiu    $sp, $sp, 0x28

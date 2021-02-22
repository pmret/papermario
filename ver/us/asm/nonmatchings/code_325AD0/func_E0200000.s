.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0200000
/* 325AD0 E0200000 3C05E020 */  lui       $a1, %hi(D_E0200690)
/* 325AD4 E0200004 24A50690 */  addiu     $a1, $a1, %lo(D_E0200690)
/* 325AD8 E0200008 8CA20000 */  lw        $v0, ($a1)
/* 325ADC E020000C 00021080 */  sll       $v0, $v0, 2
/* 325AE0 E0200010 24430002 */  addiu     $v1, $v0, 2
/* 325AE4 E0200014 24420003 */  addiu     $v0, $v0, 3
/* 325AE8 E0200018 00620018 */  mult      $v1, $v0
/* 325AEC E020001C 24840001 */  addiu     $a0, $a0, 1
/* 325AF0 E0200020 00001812 */  mflo      $v1
/* 325AF4 E0200024 00031882 */  srl       $v1, $v1, 2
/* 325AF8 E0200028 ACA30000 */  sw        $v1, ($a1)
/* 325AFC E020002C 14800002 */  bnez      $a0, .LE0200038
/* 325B00 E0200030 0064001B */   divu     $zero, $v1, $a0
/* 325B04 E0200034 0007000D */  break     7
.LE0200038:
/* 325B08 E0200038 00001010 */   mfhi     $v0
/* 325B0C E020003C 03E00008 */  jr        $ra
/* 325B10 E0200040 00000000 */   nop

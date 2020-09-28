.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800560BC
/* 314BC 800560BC 3C07800A */  lui       $a3, 0x800a
/* 314C0 800560C0 8CE7A5C0 */  lw        $a3, -0x5a40($a3)
/* 314C4 800560C4 8CE20098 */  lw        $v0, 0x98($a3)
/* 314C8 800560C8 2C420010 */  sltiu     $v0, $v0, 0x10
/* 314CC 800560CC 1040000D */  beqz      $v0, .L80056104
/* 314D0 800560D0 0080182D */   daddu    $v1, $a0, $zero
/* 314D4 800560D4 00031F00 */  sll       $v1, $v1, 0x1c
/* 314D8 800560D8 30A2000F */  andi      $v0, $a1, 0xf
/* 314DC 800560DC 00021600 */  sll       $v0, $v0, 0x18
/* 314E0 800560E0 00621821 */  addu      $v1, $v1, $v0
/* 314E4 800560E4 8CE40090 */  lw        $a0, 0x90($a3)
/* 314E8 800560E8 00661821 */  addu      $v1, $v1, $a2
/* 314EC 800560EC AC830000 */  sw        $v1, ($a0)
/* 314F0 800560F0 8CE20098 */  lw        $v0, 0x98($a3)
/* 314F4 800560F4 24840004 */  addiu     $a0, $a0, 4
/* 314F8 800560F8 ACE40090 */  sw        $a0, 0x90($a3)
/* 314FC 800560FC 24420001 */  addiu     $v0, $v0, 1
/* 31500 80056100 ACE20098 */  sw        $v0, 0x98($a3)
.L80056104:
/* 31504 80056104 03E00008 */  jr        $ra
/* 31508 80056108 00000000 */   nop      

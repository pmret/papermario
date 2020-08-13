.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8003C53C
/* 01793C 8003C53C 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 017940 8003C540 AFB00010 */  sw    $s0, 0x10($sp)
/* 017944 8003C544 0080802D */  daddu $s0, $a0, $zero
/* 017948 8003C548 AFB10014 */  sw    $s1, 0x14($sp)
/* 01794C 8003C54C 00A0882D */  daddu $s1, $a1, $zero
/* 017950 8003C550 02111021 */  addu  $v0, $s0, $s1
/* 017954 8003C554 AFBF0018 */  sw    $ra, 0x18($sp)
/* 017958 8003C558 8043032C */  lb    $v1, 0x32c($v0)
/* 01795C 8003C55C 2C620007 */  sltiu $v0, $v1, 7
/* 017960 8003C560 10400027 */  beqz  $v0, .L8003C600
/* 017964 8003C564 00031080 */   sll   $v0, $v1, 2
/* 017968 8003C568 3C01800A */  lui   $at, 0x800a
/* 01796C 8003C56C 00220821 */  addu  $at, $at, $v0
/* 017970 8003C570 8C228500 */  lw    $v0, -0x7b00($at)
/* 017974 8003C574 00400008 */  jr    $v0
/* 017978 8003C578 00000000 */   nop   
/* 01797C 8003C57C 0200202D */  daddu $a0, $s0, $zero
/* 017980 8003C580 0C00F198 */  jal   func_8003C660
/* 017984 8003C584 0220282D */   daddu $a1, $s1, $zero
/* 017988 8003C588 0800F181 */  j     .L8003C604
/* 01798C 8003C58C 02111021 */   addu  $v0, $s0, $s1

/* 017990 8003C590 0200202D */  daddu $a0, $s0, $zero
/* 017994 8003C594 0C00F1E3 */  jal   func_8003C78C
/* 017998 8003C598 0220282D */   daddu $a1, $s1, $zero
/* 01799C 8003C59C 0800F181 */  j     .L8003C604
/* 0179A0 8003C5A0 02111021 */   addu  $v0, $s0, $s1

/* 0179A4 8003C5A4 0200202D */  daddu $a0, $s0, $zero
/* 0179A8 8003C5A8 0C00F22B */  jal   func_8003C8AC
/* 0179AC 8003C5AC 0220282D */   daddu $a1, $s1, $zero
/* 0179B0 8003C5B0 0800F181 */  j     .L8003C604
/* 0179B4 8003C5B4 02111021 */   addu  $v0, $s0, $s1

/* 0179B8 8003C5B8 0200202D */  daddu $a0, $s0, $zero
/* 0179BC 8003C5BC 0C00F261 */  jal   func_8003C984
/* 0179C0 8003C5C0 0220282D */   daddu $a1, $s1, $zero
/* 0179C4 8003C5C4 0800F181 */  j     .L8003C604
/* 0179C8 8003C5C8 02111021 */   addu  $v0, $s0, $s1

/* 0179CC 8003C5CC 0200202D */  daddu $a0, $s0, $zero
/* 0179D0 8003C5D0 0C00F2C8 */  jal   func_8003CB20
/* 0179D4 8003C5D4 0220282D */   daddu $a1, $s1, $zero
/* 0179D8 8003C5D8 0800F181 */  j     .L8003C604
/* 0179DC 8003C5DC 02111021 */   addu  $v0, $s0, $s1

/* 0179E0 8003C5E0 0200202D */  daddu $a0, $s0, $zero
/* 0179E4 8003C5E4 0C00F323 */  jal   func_8003CC8C
/* 0179E8 8003C5E8 0220282D */   daddu $a1, $s1, $zero
/* 0179EC 8003C5EC 0800F181 */  j     .L8003C604
/* 0179F0 8003C5F0 02111021 */   addu  $v0, $s0, $s1

/* 0179F4 8003C5F4 0200202D */  daddu $a0, $s0, $zero
/* 0179F8 8003C5F8 0C00F3E8 */  jal   func_8003CFA0
/* 0179FC 8003C5FC 0220282D */   daddu $a1, $s1, $zero
.L8003C600:
/* 017A00 8003C600 02111021 */  addu  $v0, $s0, $s1
.L8003C604:
/* 017A04 8003C604 A040032C */  sb    $zero, 0x32c($v0)
/* 017A08 8003C608 8FBF0018 */  lw    $ra, 0x18($sp)
/* 017A0C 8003C60C 8FB10014 */  lw    $s1, 0x14($sp)
/* 017A10 8003C610 8FB00010 */  lw    $s0, 0x10($sp)
/* 017A14 8003C614 03E00008 */  jr    $ra
/* 017A18 8003C618 27BD0020 */   addiu $sp, $sp, 0x20


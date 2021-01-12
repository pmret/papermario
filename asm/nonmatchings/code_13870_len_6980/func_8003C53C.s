.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003C53C
/* 1793C 8003C53C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 17940 8003C540 AFB00010 */  sw        $s0, 0x10($sp)
/* 17944 8003C544 0080802D */  daddu     $s0, $a0, $zero
/* 17948 8003C548 AFB10014 */  sw        $s1, 0x14($sp)
/* 1794C 8003C54C 00A0882D */  daddu     $s1, $a1, $zero
/* 17950 8003C550 02111021 */  addu      $v0, $s0, $s1
/* 17954 8003C554 AFBF0018 */  sw        $ra, 0x18($sp)
/* 17958 8003C558 8043032C */  lb        $v1, 0x32c($v0)
/* 1795C 8003C55C 2C620007 */  sltiu     $v0, $v1, 7
/* 17960 8003C560 10400027 */  beqz      $v0, .L8003C600
/* 17964 8003C564 00031080 */   sll      $v0, $v1, 2
/* 17968 8003C568 3C01800A */  lui       $at, %hi(D_80098500)
/* 1796C 8003C56C 00220821 */  addu      $at, $at, $v0
/* 17970 8003C570 8C228500 */  lw        $v0, %lo(D_80098500)($at)
/* 17974 8003C574 00400008 */  jr        $v0
/* 17978 8003C578 00000000 */   nop
/* 1797C 8003C57C 0200202D */  daddu     $a0, $s0, $zero
/* 17980 8003C580 0C00F198 */  jal       func_8003C660
/* 17984 8003C584 0220282D */   daddu    $a1, $s1, $zero
/* 17988 8003C588 0800F181 */  j         .L8003C604
/* 1798C 8003C58C 02111021 */   addu     $v0, $s0, $s1
/* 17990 8003C590 0200202D */  daddu     $a0, $s0, $zero
/* 17994 8003C594 0C00F1E3 */  jal       func_8003C78C
/* 17998 8003C598 0220282D */   daddu    $a1, $s1, $zero
/* 1799C 8003C59C 0800F181 */  j         .L8003C604
/* 179A0 8003C5A0 02111021 */   addu     $v0, $s0, $s1
/* 179A4 8003C5A4 0200202D */  daddu     $a0, $s0, $zero
/* 179A8 8003C5A8 0C00F22B */  jal       func_8003C8AC
/* 179AC 8003C5AC 0220282D */   daddu    $a1, $s1, $zero
/* 179B0 8003C5B0 0800F181 */  j         .L8003C604
/* 179B4 8003C5B4 02111021 */   addu     $v0, $s0, $s1
/* 179B8 8003C5B8 0200202D */  daddu     $a0, $s0, $zero
/* 179BC 8003C5BC 0C00F261 */  jal       func_8003C984
/* 179C0 8003C5C0 0220282D */   daddu    $a1, $s1, $zero
/* 179C4 8003C5C4 0800F181 */  j         .L8003C604
/* 179C8 8003C5C8 02111021 */   addu     $v0, $s0, $s1
/* 179CC 8003C5CC 0200202D */  daddu     $a0, $s0, $zero
/* 179D0 8003C5D0 0C00F2C8 */  jal       func_8003CB20
/* 179D4 8003C5D4 0220282D */   daddu    $a1, $s1, $zero
/* 179D8 8003C5D8 0800F181 */  j         .L8003C604
/* 179DC 8003C5DC 02111021 */   addu     $v0, $s0, $s1
/* 179E0 8003C5E0 0200202D */  daddu     $a0, $s0, $zero
/* 179E4 8003C5E4 0C00F323 */  jal       func_8003CC8C
/* 179E8 8003C5E8 0220282D */   daddu    $a1, $s1, $zero
/* 179EC 8003C5EC 0800F181 */  j         .L8003C604
/* 179F0 8003C5F0 02111021 */   addu     $v0, $s0, $s1
/* 179F4 8003C5F4 0200202D */  daddu     $a0, $s0, $zero
/* 179F8 8003C5F8 0C00F3E8 */  jal       func_8003CFA0
/* 179FC 8003C5FC 0220282D */   daddu    $a1, $s1, $zero
.L8003C600:
/* 17A00 8003C600 02111021 */  addu      $v0, $s0, $s1
.L8003C604:
/* 17A04 8003C604 A040032C */  sb        $zero, 0x32c($v0)
/* 17A08 8003C608 8FBF0018 */  lw        $ra, 0x18($sp)
/* 17A0C 8003C60C 8FB10014 */  lw        $s1, 0x14($sp)
/* 17A10 8003C610 8FB00010 */  lw        $s0, 0x10($sp)
/* 17A14 8003C614 03E00008 */  jr        $ra
/* 17A18 8003C618 27BD0020 */   addiu    $sp, $sp, 0x20

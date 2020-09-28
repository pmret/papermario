.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056DCC
/* 321CC 80056DCC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 321D0 80056DD0 00A0302D */  daddu     $a2, $a1, $zero
/* 321D4 80056DD4 308400FF */  andi      $a0, $a0, 0xff
/* 321D8 80056DD8 00041040 */  sll       $v0, $a0, 1
/* 321DC 80056DDC 00441021 */  addu      $v0, $v0, $a0
/* 321E0 80056DE0 3C038008 */  lui       $v1, 0x8008
/* 321E4 80056DE4 8C638E54 */  lw        $v1, -0x71ac($v1)
/* 321E8 80056DE8 000210C0 */  sll       $v0, $v0, 3
/* 321EC 80056DEC AFBF0018 */  sw        $ra, 0x18($sp)
/* 321F0 80056DF0 AFB10014 */  sw        $s1, 0x14($sp)
/* 321F4 80056DF4 AFB00010 */  sw        $s0, 0x10($sp)
/* 321F8 80056DF8 8C700020 */  lw        $s0, 0x20($v1)
/* 321FC 80056DFC 30D100FF */  andi      $s1, $a2, 0xff
/* 32200 80056E00 02028021 */  addu      $s0, $s0, $v0
/* 32204 80056E04 8E040004 */  lw        $a0, 4($s0)
/* 32208 80056E08 0220282D */  daddu     $a1, $s1, $zero
/* 3220C 80056E0C 0C016413 */  jal       func_8005904C
/* 32210 80056E10 A206000C */   sb       $a2, 0xc($s0)
/* 32214 80056E14 8E040008 */  lw        $a0, 8($s0)
/* 32218 80056E18 0C016413 */  jal       func_8005904C
/* 3221C 80056E1C 0220282D */   daddu    $a1, $s1, $zero
/* 32220 80056E20 8FBF0018 */  lw        $ra, 0x18($sp)
/* 32224 80056E24 8FB10014 */  lw        $s1, 0x14($sp)
/* 32228 80056E28 8FB00010 */  lw        $s0, 0x10($sp)
/* 3222C 80056E2C 03E00008 */  jr        $ra
/* 32230 80056E30 27BD0020 */   addiu    $sp, $sp, 0x20

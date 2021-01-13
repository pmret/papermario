.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400BC_A9964C
/* A9964C 802400BC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A99650 802400C0 AFBF002C */  sw        $ra, 0x2c($sp)
/* A99654 802400C4 AFB00028 */  sw        $s0, 0x28($sp)
/* A99658 802400C8 8C820098 */  lw        $v0, 0x98($a0)
/* A9965C 802400CC 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* A99660 802400D0 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* A99664 802400D4 14400005 */  bnez      $v0, .L802400EC
/* A99668 802400D8 00000000 */   nop
/* A9966C 802400DC C4800084 */  lwc1      $f0, 0x84($a0)
/* A99670 802400E0 46800020 */  cvt.s.w   $f0, $f0
/* A99674 802400E4 0809003E */  j         .L802400F8
/* A99678 802400E8 E6000028 */   swc1     $f0, 0x28($s0)
.L802400EC:
/* A9967C 802400EC C4800084 */  lwc1      $f0, 0x84($a0)
/* A99680 802400F0 46800020 */  cvt.s.w   $f0, $f0
/* A99684 802400F4 E6000030 */  swc1      $f0, 0x30($s0)
.L802400F8:
/* A99688 802400F8 27A20024 */  addiu     $v0, $sp, 0x24
/* A9968C 802400FC 0000202D */  daddu     $a0, $zero, $zero
/* A99690 80240100 27A50018 */  addiu     $a1, $sp, 0x18
/* A99694 80240104 27A6001C */  addiu     $a2, $sp, 0x1c
/* A99698 80240108 C6000028 */  lwc1      $f0, 0x28($s0)
/* A9969C 8024010C 3C014120 */  lui       $at, 0x4120
/* A996A0 80240110 44811000 */  mtc1      $at, $f2
/* A996A4 80240114 3C014220 */  lui       $at, 0x4220
/* A996A8 80240118 44813000 */  mtc1      $at, $f6
/* A996AC 8024011C 27A70020 */  addiu     $a3, $sp, 0x20
/* A996B0 80240120 E7A00018 */  swc1      $f0, 0x18($sp)
/* A996B4 80240124 C600002C */  lwc1      $f0, 0x2c($s0)
/* A996B8 80240128 C6040030 */  lwc1      $f4, 0x30($s0)
/* A996BC 8024012C 46020000 */  add.s     $f0, $f0, $f2
/* A996C0 80240130 E7A60024 */  swc1      $f6, 0x24($sp)
/* A996C4 80240134 E7A40020 */  swc1      $f4, 0x20($sp)
/* A996C8 80240138 E7A0001C */  swc1      $f0, 0x1c($sp)
/* A996CC 8024013C 0C0372DF */  jal       func_800DCB7C
/* A996D0 80240140 AFA20010 */   sw       $v0, 0x10($sp)
/* A996D4 80240144 C7A00018 */  lwc1      $f0, 0x18($sp)
/* A996D8 80240148 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* A996DC 8024014C C7A40020 */  lwc1      $f4, 0x20($sp)
/* A996E0 80240150 E6000028 */  swc1      $f0, 0x28($s0)
/* A996E4 80240154 E602002C */  swc1      $f2, 0x2c($s0)
/* A996E8 80240158 E6040030 */  swc1      $f4, 0x30($s0)
/* A996EC 8024015C 8FBF002C */  lw        $ra, 0x2c($sp)
/* A996F0 80240160 8FB00028 */  lw        $s0, 0x28($sp)
/* A996F4 80240164 24020002 */  addiu     $v0, $zero, 2
/* A996F8 80240168 03E00008 */  jr        $ra
/* A996FC 8024016C 27BD0030 */   addiu    $sp, $sp, 0x30

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400BC_A4C01C
/* A4C01C 802400BC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A4C020 802400C0 AFBF002C */  sw        $ra, 0x2c($sp)
/* A4C024 802400C4 AFB00028 */  sw        $s0, 0x28($sp)
/* A4C028 802400C8 8C820098 */  lw        $v0, 0x98($a0)
/* A4C02C 802400CC 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* A4C030 802400D0 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* A4C034 802400D4 14400005 */  bnez      $v0, .L802400EC
/* A4C038 802400D8 00000000 */   nop      
/* A4C03C 802400DC C4800084 */  lwc1      $f0, 0x84($a0)
/* A4C040 802400E0 46800020 */  cvt.s.w   $f0, $f0
/* A4C044 802400E4 0809003E */  j         .L802400F8
/* A4C048 802400E8 E6000028 */   swc1     $f0, 0x28($s0)
.L802400EC:
/* A4C04C 802400EC C4800084 */  lwc1      $f0, 0x84($a0)
/* A4C050 802400F0 46800020 */  cvt.s.w   $f0, $f0
/* A4C054 802400F4 E6000030 */  swc1      $f0, 0x30($s0)
.L802400F8:
/* A4C058 802400F8 27A20024 */  addiu     $v0, $sp, 0x24
/* A4C05C 802400FC 0000202D */  daddu     $a0, $zero, $zero
/* A4C060 80240100 27A50018 */  addiu     $a1, $sp, 0x18
/* A4C064 80240104 27A6001C */  addiu     $a2, $sp, 0x1c
/* A4C068 80240108 C6000028 */  lwc1      $f0, 0x28($s0)
/* A4C06C 8024010C 3C014120 */  lui       $at, 0x4120
/* A4C070 80240110 44811000 */  mtc1      $at, $f2
/* A4C074 80240114 3C014220 */  lui       $at, 0x4220
/* A4C078 80240118 44813000 */  mtc1      $at, $f6
/* A4C07C 8024011C 27A70020 */  addiu     $a3, $sp, 0x20
/* A4C080 80240120 E7A00018 */  swc1      $f0, 0x18($sp)
/* A4C084 80240124 C600002C */  lwc1      $f0, 0x2c($s0)
/* A4C088 80240128 C6040030 */  lwc1      $f4, 0x30($s0)
/* A4C08C 8024012C 46020000 */  add.s     $f0, $f0, $f2
/* A4C090 80240130 E7A60024 */  swc1      $f6, 0x24($sp)
/* A4C094 80240134 E7A40020 */  swc1      $f4, 0x20($sp)
/* A4C098 80240138 E7A0001C */  swc1      $f0, 0x1c($sp)
/* A4C09C 8024013C 0C0372DF */  jal       func_800DCB7C
/* A4C0A0 80240140 AFA20010 */   sw       $v0, 0x10($sp)
/* A4C0A4 80240144 C7A00018 */  lwc1      $f0, 0x18($sp)
/* A4C0A8 80240148 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* A4C0AC 8024014C C7A40020 */  lwc1      $f4, 0x20($sp)
/* A4C0B0 80240150 E6000028 */  swc1      $f0, 0x28($s0)
/* A4C0B4 80240154 E602002C */  swc1      $f2, 0x2c($s0)
/* A4C0B8 80240158 E6040030 */  swc1      $f4, 0x30($s0)
/* A4C0BC 8024015C 8FBF002C */  lw        $ra, 0x2c($sp)
/* A4C0C0 80240160 8FB00028 */  lw        $s0, 0x28($sp)
/* A4C0C4 80240164 24020002 */  addiu     $v0, $zero, 2
/* A4C0C8 80240168 03E00008 */  jr        $ra
/* A4C0CC 8024016C 27BD0030 */   addiu    $sp, $sp, 0x30

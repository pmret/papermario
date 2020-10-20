.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400BC_C3159C
/* C3159C 802400BC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C315A0 802400C0 AFBF002C */  sw        $ra, 0x2c($sp)
/* C315A4 802400C4 AFB00028 */  sw        $s0, 0x28($sp)
/* C315A8 802400C8 8C820098 */  lw        $v0, 0x98($a0)
/* C315AC 802400CC 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* C315B0 802400D0 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* C315B4 802400D4 14400005 */  bnez      $v0, .L802400EC
/* C315B8 802400D8 00000000 */   nop      
/* C315BC 802400DC C4800084 */  lwc1      $f0, 0x84($a0)
/* C315C0 802400E0 46800020 */  cvt.s.w   $f0, $f0
/* C315C4 802400E4 0809003E */  j         .L802400F8
/* C315C8 802400E8 E6000028 */   swc1     $f0, 0x28($s0)
.L802400EC:
/* C315CC 802400EC C4800084 */  lwc1      $f0, 0x84($a0)
/* C315D0 802400F0 46800020 */  cvt.s.w   $f0, $f0
/* C315D4 802400F4 E6000030 */  swc1      $f0, 0x30($s0)
.L802400F8:
/* C315D8 802400F8 27A20024 */  addiu     $v0, $sp, 0x24
/* C315DC 802400FC 0000202D */  daddu     $a0, $zero, $zero
/* C315E0 80240100 27A50018 */  addiu     $a1, $sp, 0x18
/* C315E4 80240104 27A6001C */  addiu     $a2, $sp, 0x1c
/* C315E8 80240108 C6000028 */  lwc1      $f0, 0x28($s0)
/* C315EC 8024010C 3C014120 */  lui       $at, 0x4120
/* C315F0 80240110 44811000 */  mtc1      $at, $f2
/* C315F4 80240114 3C014220 */  lui       $at, 0x4220
/* C315F8 80240118 44813000 */  mtc1      $at, $f6
/* C315FC 8024011C 27A70020 */  addiu     $a3, $sp, 0x20
/* C31600 80240120 E7A00018 */  swc1      $f0, 0x18($sp)
/* C31604 80240124 C600002C */  lwc1      $f0, 0x2c($s0)
/* C31608 80240128 C6040030 */  lwc1      $f4, 0x30($s0)
/* C3160C 8024012C 46020000 */  add.s     $f0, $f0, $f2
/* C31610 80240130 E7A60024 */  swc1      $f6, 0x24($sp)
/* C31614 80240134 E7A40020 */  swc1      $f4, 0x20($sp)
/* C31618 80240138 E7A0001C */  swc1      $f0, 0x1c($sp)
/* C3161C 8024013C 0C0372DF */  jal       func_800DCB7C
/* C31620 80240140 AFA20010 */   sw       $v0, 0x10($sp)
/* C31624 80240144 C7A00018 */  lwc1      $f0, 0x18($sp)
/* C31628 80240148 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* C3162C 8024014C C7A40020 */  lwc1      $f4, 0x20($sp)
/* C31630 80240150 E6000028 */  swc1      $f0, 0x28($s0)
/* C31634 80240154 E602002C */  swc1      $f2, 0x2c($s0)
/* C31638 80240158 E6040030 */  swc1      $f4, 0x30($s0)
/* C3163C 8024015C 8FBF002C */  lw        $ra, 0x2c($sp)
/* C31640 80240160 8FB00028 */  lw        $s0, 0x28($sp)
/* C31644 80240164 24020002 */  addiu     $v0, $zero, 2
/* C31648 80240168 03E00008 */  jr        $ra
/* C3164C 8024016C 27BD0030 */   addiu    $sp, $sp, 0x30

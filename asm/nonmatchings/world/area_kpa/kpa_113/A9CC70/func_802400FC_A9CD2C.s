.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400FC_A9CD2C
/* A9CD2C 802400FC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* A9CD30 80240100 AFBF002C */  sw        $ra, 0x2c($sp)
/* A9CD34 80240104 AFB00028 */  sw        $s0, 0x28($sp)
/* A9CD38 80240108 8C820098 */  lw        $v0, 0x98($a0)
/* A9CD3C 8024010C 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* A9CD40 80240110 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* A9CD44 80240114 14400005 */  bnez      $v0, .L8024012C
/* A9CD48 80240118 00000000 */   nop      
/* A9CD4C 8024011C C4800084 */  lwc1      $f0, 0x84($a0)
/* A9CD50 80240120 46800020 */  cvt.s.w   $f0, $f0
/* A9CD54 80240124 0809004E */  j         .L80240138
/* A9CD58 80240128 E6000028 */   swc1     $f0, 0x28($s0)
.L8024012C:
/* A9CD5C 8024012C C4800084 */  lwc1      $f0, 0x84($a0)
/* A9CD60 80240130 46800020 */  cvt.s.w   $f0, $f0
/* A9CD64 80240134 E6000030 */  swc1      $f0, 0x30($s0)
.L80240138:
/* A9CD68 80240138 27A20024 */  addiu     $v0, $sp, 0x24
/* A9CD6C 8024013C 0000202D */  daddu     $a0, $zero, $zero
/* A9CD70 80240140 27A50018 */  addiu     $a1, $sp, 0x18
/* A9CD74 80240144 27A6001C */  addiu     $a2, $sp, 0x1c
/* A9CD78 80240148 C6000028 */  lwc1      $f0, 0x28($s0)
/* A9CD7C 8024014C 3C014120 */  lui       $at, 0x4120
/* A9CD80 80240150 44811000 */  mtc1      $at, $f2
/* A9CD84 80240154 3C014220 */  lui       $at, 0x4220
/* A9CD88 80240158 44813000 */  mtc1      $at, $f6
/* A9CD8C 8024015C 27A70020 */  addiu     $a3, $sp, 0x20
/* A9CD90 80240160 E7A00018 */  swc1      $f0, 0x18($sp)
/* A9CD94 80240164 C600002C */  lwc1      $f0, 0x2c($s0)
/* A9CD98 80240168 C6040030 */  lwc1      $f4, 0x30($s0)
/* A9CD9C 8024016C 46020000 */  add.s     $f0, $f0, $f2
/* A9CDA0 80240170 E7A60024 */  swc1      $f6, 0x24($sp)
/* A9CDA4 80240174 E7A40020 */  swc1      $f4, 0x20($sp)
/* A9CDA8 80240178 E7A0001C */  swc1      $f0, 0x1c($sp)
/* A9CDAC 8024017C 0C0372DF */  jal       func_800DCB7C
/* A9CDB0 80240180 AFA20010 */   sw       $v0, 0x10($sp)
/* A9CDB4 80240184 C7A00018 */  lwc1      $f0, 0x18($sp)
/* A9CDB8 80240188 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* A9CDBC 8024018C C7A40020 */  lwc1      $f4, 0x20($sp)
/* A9CDC0 80240190 E6000028 */  swc1      $f0, 0x28($s0)
/* A9CDC4 80240194 E602002C */  swc1      $f2, 0x2c($s0)
/* A9CDC8 80240198 E6040030 */  swc1      $f4, 0x30($s0)
/* A9CDCC 8024019C 8FBF002C */  lw        $ra, 0x2c($sp)
/* A9CDD0 802401A0 8FB00028 */  lw        $s0, 0x28($sp)
/* A9CDD4 802401A4 24020002 */  addiu     $v0, $zero, 2
/* A9CDD8 802401A8 03E00008 */  jr        $ra
/* A9CDDC 802401AC 27BD0030 */   addiu    $sp, $sp, 0x30

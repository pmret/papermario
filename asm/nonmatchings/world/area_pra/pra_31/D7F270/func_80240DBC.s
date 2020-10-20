.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DBC
/* D7FB1C 80240DBC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D7FB20 80240DC0 AFBF002C */  sw        $ra, 0x2c($sp)
/* D7FB24 80240DC4 AFB00028 */  sw        $s0, 0x28($sp)
/* D7FB28 80240DC8 8C820098 */  lw        $v0, 0x98($a0)
/* D7FB2C 80240DCC 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D7FB30 80240DD0 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D7FB34 80240DD4 14400005 */  bnez      $v0, .L80240DEC
/* D7FB38 80240DD8 00000000 */   nop      
/* D7FB3C 80240DDC C4800084 */  lwc1      $f0, 0x84($a0)
/* D7FB40 80240DE0 46800020 */  cvt.s.w   $f0, $f0
/* D7FB44 80240DE4 0809037E */  j         .L80240DF8
/* D7FB48 80240DE8 E6000028 */   swc1     $f0, 0x28($s0)
.L80240DEC:
/* D7FB4C 80240DEC C4800084 */  lwc1      $f0, 0x84($a0)
/* D7FB50 80240DF0 46800020 */  cvt.s.w   $f0, $f0
/* D7FB54 80240DF4 E6000030 */  swc1      $f0, 0x30($s0)
.L80240DF8:
/* D7FB58 80240DF8 27A20024 */  addiu     $v0, $sp, 0x24
/* D7FB5C 80240DFC 0000202D */  daddu     $a0, $zero, $zero
/* D7FB60 80240E00 27A50018 */  addiu     $a1, $sp, 0x18
/* D7FB64 80240E04 27A6001C */  addiu     $a2, $sp, 0x1c
/* D7FB68 80240E08 C6000028 */  lwc1      $f0, 0x28($s0)
/* D7FB6C 80240E0C 3C014120 */  lui       $at, 0x4120
/* D7FB70 80240E10 44811000 */  mtc1      $at, $f2
/* D7FB74 80240E14 3C014220 */  lui       $at, 0x4220
/* D7FB78 80240E18 44813000 */  mtc1      $at, $f6
/* D7FB7C 80240E1C 27A70020 */  addiu     $a3, $sp, 0x20
/* D7FB80 80240E20 E7A00018 */  swc1      $f0, 0x18($sp)
/* D7FB84 80240E24 C600002C */  lwc1      $f0, 0x2c($s0)
/* D7FB88 80240E28 C6040030 */  lwc1      $f4, 0x30($s0)
/* D7FB8C 80240E2C 46020000 */  add.s     $f0, $f0, $f2
/* D7FB90 80240E30 E7A60024 */  swc1      $f6, 0x24($sp)
/* D7FB94 80240E34 E7A40020 */  swc1      $f4, 0x20($sp)
/* D7FB98 80240E38 E7A0001C */  swc1      $f0, 0x1c($sp)
/* D7FB9C 80240E3C 0C0372DF */  jal       func_800DCB7C
/* D7FBA0 80240E40 AFA20010 */   sw       $v0, 0x10($sp)
/* D7FBA4 80240E44 C7A00018 */  lwc1      $f0, 0x18($sp)
/* D7FBA8 80240E48 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* D7FBAC 80240E4C C7A40020 */  lwc1      $f4, 0x20($sp)
/* D7FBB0 80240E50 E6000028 */  swc1      $f0, 0x28($s0)
/* D7FBB4 80240E54 E602002C */  swc1      $f2, 0x2c($s0)
/* D7FBB8 80240E58 E6040030 */  swc1      $f4, 0x30($s0)
/* D7FBBC 80240E5C 8FBF002C */  lw        $ra, 0x2c($sp)
/* D7FBC0 80240E60 8FB00028 */  lw        $s0, 0x28($sp)
/* D7FBC4 80240E64 24020002 */  addiu     $v0, $zero, 2
/* D7FBC8 80240E68 03E00008 */  jr        $ra
/* D7FBCC 80240E6C 27BD0030 */   addiu    $sp, $sp, 0x30

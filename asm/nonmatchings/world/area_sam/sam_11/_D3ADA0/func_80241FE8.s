.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FE8
/* D3C5B8 80241FE8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* D3C5BC 80241FEC AFB00028 */  sw        $s0, 0x28($sp)
/* D3C5C0 80241FF0 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* D3C5C4 80241FF4 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* D3C5C8 80241FF8 27A20024 */  addiu     $v0, $sp, 0x24
/* D3C5CC 80241FFC 0000202D */  daddu     $a0, $zero, $zero
/* D3C5D0 80242000 27A50018 */  addiu     $a1, $sp, 0x18
/* D3C5D4 80242004 27A6001C */  addiu     $a2, $sp, 0x1c
/* D3C5D8 80242008 AFBF002C */  sw        $ra, 0x2c($sp)
/* D3C5DC 8024200C C6000028 */  lwc1      $f0, 0x28($s0)
/* D3C5E0 80242010 3C014120 */  lui       $at, 0x4120
/* D3C5E4 80242014 44811000 */  mtc1      $at, $f2
/* D3C5E8 80242018 3C014220 */  lui       $at, 0x4220
/* D3C5EC 8024201C 44813000 */  mtc1      $at, $f6
/* D3C5F0 80242020 27A70020 */  addiu     $a3, $sp, 0x20
/* D3C5F4 80242024 E7A00018 */  swc1      $f0, 0x18($sp)
/* D3C5F8 80242028 C600002C */  lwc1      $f0, 0x2c($s0)
/* D3C5FC 8024202C C6040030 */  lwc1      $f4, 0x30($s0)
/* D3C600 80242030 46020000 */  add.s     $f0, $f0, $f2
/* D3C604 80242034 E7A60024 */  swc1      $f6, 0x24($sp)
/* D3C608 80242038 E7A40020 */  swc1      $f4, 0x20($sp)
/* D3C60C 8024203C E7A0001C */  swc1      $f0, 0x1c($sp)
/* D3C610 80242040 0C0372DF */  jal       func_800DCB7C
/* D3C614 80242044 AFA20010 */   sw       $v0, 0x10($sp)
/* D3C618 80242048 C7A00018 */  lwc1      $f0, 0x18($sp)
/* D3C61C 8024204C C7A2001C */  lwc1      $f2, 0x1c($sp)
/* D3C620 80242050 C7A40020 */  lwc1      $f4, 0x20($sp)
/* D3C624 80242054 E6000028 */  swc1      $f0, 0x28($s0)
/* D3C628 80242058 E602002C */  swc1      $f2, 0x2c($s0)
/* D3C62C 8024205C E6040030 */  swc1      $f4, 0x30($s0)
/* D3C630 80242060 8FBF002C */  lw        $ra, 0x2c($sp)
/* D3C634 80242064 8FB00028 */  lw        $s0, 0x28($sp)
/* D3C638 80242068 24020002 */  addiu     $v0, $zero, 2
/* D3C63C 8024206C 03E00008 */  jr        $ra
/* D3C640 80242070 27BD0030 */   addiu    $sp, $sp, 0x30

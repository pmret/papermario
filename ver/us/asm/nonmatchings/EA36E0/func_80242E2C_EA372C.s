.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242E2C_EA372C
/* EA372C 80242E2C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* EA3730 80242E30 AFB00028 */  sw        $s0, 0x28($sp)
/* EA3734 80242E34 0080802D */  daddu     $s0, $a0, $zero
/* EA3738 80242E38 AFBF002C */  sw        $ra, 0x2c($sp)
/* EA373C 80242E3C C6000084 */  lwc1      $f0, 0x84($s0)
/* EA3740 80242E40 46800020 */  cvt.s.w   $f0, $f0
/* EA3744 80242E44 E7A00018 */  swc1      $f0, 0x18($sp)
/* EA3748 80242E48 C600008C */  lwc1      $f0, 0x8c($s0)
/* EA374C 80242E4C 46800020 */  cvt.s.w   $f0, $f0
/* EA3750 80242E50 27A20024 */  addiu     $v0, $sp, 0x24
/* EA3754 80242E54 3C040001 */  lui       $a0, 1
/* EA3758 80242E58 27A50018 */  addiu     $a1, $sp, 0x18
/* EA375C 80242E5C 27A6001C */  addiu     $a2, $sp, 0x1c
/* EA3760 80242E60 3C0144FA */  lui       $at, 0x44fa
/* EA3764 80242E64 44811000 */  mtc1      $at, $f2
/* EA3768 80242E68 27A70020 */  addiu     $a3, $sp, 0x20
/* EA376C 80242E6C E7A0001C */  swc1      $f0, 0x1c($sp)
/* EA3770 80242E70 AFA00020 */  sw        $zero, 0x20($sp)
/* EA3774 80242E74 E7A20024 */  swc1      $f2, 0x24($sp)
/* EA3778 80242E78 0C03908F */  jal       dead_npc_raycast_down_sides
/* EA377C 80242E7C AFA20010 */   sw       $v0, 0x10($sp)
/* EA3780 80242E80 1040000B */  beqz      $v0, .L80242EB0
/* EA3784 80242E84 00000000 */   nop
/* EA3788 80242E88 C7A2001C */  lwc1      $f2, 0x1c($sp)
/* EA378C 80242E8C 3C01425C */  lui       $at, 0x425c
/* EA3790 80242E90 44810000 */  mtc1      $at, $f0
/* EA3794 80242E94 00000000 */  nop
/* EA3798 80242E98 46001080 */  add.s     $f2, $f2, $f0
/* EA379C 80242E9C C7A00018 */  lwc1      $f0, 0x18($sp)
/* EA37A0 80242EA0 4600010D */  trunc.w.s $f4, $f0
/* EA37A4 80242EA4 E6040084 */  swc1      $f4, 0x84($s0)
/* EA37A8 80242EA8 4600110D */  trunc.w.s $f4, $f2
/* EA37AC 80242EAC E604008C */  swc1      $f4, 0x8c($s0)
.L80242EB0:
/* EA37B0 80242EB0 8FBF002C */  lw        $ra, 0x2c($sp)
/* EA37B4 80242EB4 8FB00028 */  lw        $s0, 0x28($sp)
/* EA37B8 80242EB8 24020002 */  addiu     $v0, $zero, 2
/* EA37BC 80242EBC 03E00008 */  jr        $ra
/* EA37C0 80242EC0 27BD0030 */   addiu    $sp, $sp, 0x30

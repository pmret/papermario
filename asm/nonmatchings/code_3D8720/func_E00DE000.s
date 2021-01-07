.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00DE000
/* 3D8720 E00DE000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3D8724 E00DE004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3D8728 E00DE008 4485A000 */  mtc1      $a1, $f20
/* 3D872C E00DE00C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3D8730 E00DE010 4486B000 */  mtc1      $a2, $f22
/* 3D8734 E00DE014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3D8738 E00DE018 0080902D */  daddu     $s2, $a0, $zero
/* 3D873C E00DE01C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3D8740 E00DE020 4487C000 */  mtc1      $a3, $f24
/* 3D8744 E00DE024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D8748 E00DE028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3D874C E00DE02C 8FB10064 */  lw        $s1, 0x64($sp)
/* 3D8750 E00DE030 3C02E00E */  lui       $v0, %hi(D_E00DE11C)
/* 3D8754 E00DE034 2442E11C */  addiu     $v0, $v0, %lo(D_E00DE11C)
/* 3D8758 E00DE038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3D875C E00DE03C 3C02E00E */  lui       $v0, %hi(D_E00DE124)
/* 3D8760 E00DE040 2442E124 */  addiu     $v0, $v0, %lo(D_E00DE124)
/* 3D8764 E00DE044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D8768 E00DE048 3C02E00E */  lui       $v0, %hi(D_E00DE260)
/* 3D876C E00DE04C 2442E260 */  addiu     $v0, $v0, %lo(D_E00DE260)
/* 3D8770 E00DE050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3D8774 E00DE054 2402006F */  addiu     $v0, $zero, 0x6f
/* 3D8778 E00DE058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3D877C E00DE05C AFB00028 */  sw        $s0, 0x28($sp)
/* 3D8780 E00DE060 AFA00010 */  sw        $zero, 0x10($sp)
/* 3D8784 E00DE064 AFA00024 */  sw        $zero, 0x24($sp)
/* 3D8788 E00DE068 0C080124 */  jal       func_E0200490
/* 3D878C E00DE06C AFA20014 */   sw       $v0, 0x14($sp)
/* 3D8790 E00DE070 24040044 */  addiu     $a0, $zero, 0x44
/* 3D8794 E00DE074 24030001 */  addiu     $v1, $zero, 1
/* 3D8798 E00DE078 0040802D */  daddu     $s0, $v0, $zero
/* 3D879C E00DE07C 0C08012C */  jal       func_E02004B0
/* 3D87A0 E00DE080 AE030008 */   sw       $v1, 8($s0)
/* 3D87A4 E00DE084 0040202D */  daddu     $a0, $v0, $zero
/* 3D87A8 E00DE088 14800003 */  bnez      $a0, .LE00DE098
/* 3D87AC E00DE08C AE02000C */   sw       $v0, 0xc($s0)
.LE00DE090:
/* 3D87B0 E00DE090 08037824 */  j         .LE00DE090
/* 3D87B4 E00DE094 00000000 */   nop      
.LE00DE098:
/* 3D87B8 E00DE098 AC920000 */  sw        $s2, ($a0)
/* 3D87BC E00DE09C 1E200004 */  bgtz      $s1, .LE00DE0B0
/* 3D87C0 E00DE0A0 AC800014 */   sw       $zero, 0x14($a0)
/* 3D87C4 E00DE0A4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3D87C8 E00DE0A8 0803782D */  j         .LE00DE0B4
/* 3D87CC E00DE0AC AC820010 */   sw       $v0, 0x10($a0)
.LE00DE0B0:
/* 3D87D0 E00DE0B0 AC910010 */  sw        $s1, 0x10($a0)
.LE00DE0B4:
/* 3D87D4 E00DE0B4 240300FF */  addiu     $v1, $zero, 0xff
/* 3D87D8 E00DE0B8 AC830024 */  sw        $v1, 0x24($a0)
/* 3D87DC E00DE0BC E4940004 */  swc1      $f20, 4($a0)
/* 3D87E0 E00DE0C0 E4960008 */  swc1      $f22, 8($a0)
/* 3D87E4 E00DE0C4 E498000C */  swc1      $f24, 0xc($a0)
/* 3D87E8 E00DE0C8 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 3D87EC E00DE0CC 0200102D */  daddu     $v0, $s0, $zero
/* 3D87F0 E00DE0D0 AC830018 */  sw        $v1, 0x18($a0)
/* 3D87F4 E00DE0D4 AC83001C */  sw        $v1, 0x1c($a0)
/* 3D87F8 E00DE0D8 AC830020 */  sw        $v1, 0x20($a0)
/* 3D87FC E00DE0DC AC830028 */  sw        $v1, 0x28($a0)
/* 3D8800 E00DE0E0 AC83002C */  sw        $v1, 0x2c($a0)
/* 3D8804 E00DE0E4 AC830030 */  sw        $v1, 0x30($a0)
/* 3D8808 E00DE0E8 AC830034 */  sw        $v1, 0x34($a0)
/* 3D880C E00DE0EC AC800038 */  sw        $zero, 0x38($a0)
/* 3D8810 E00DE0F0 AC80003C */  sw        $zero, 0x3c($a0)
/* 3D8814 E00DE0F4 E4800040 */  swc1      $f0, 0x40($a0)
/* 3D8818 E00DE0F8 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3D881C E00DE0FC 8FB20030 */  lw        $s2, 0x30($sp)
/* 3D8820 E00DE100 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3D8824 E00DE104 8FB00028 */  lw        $s0, 0x28($sp)
/* 3D8828 E00DE108 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3D882C E00DE10C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3D8830 E00DE110 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3D8834 E00DE114 03E00008 */  jr        $ra
/* 3D8838 E00DE118 27BD0050 */   addiu    $sp, $sp, 0x50

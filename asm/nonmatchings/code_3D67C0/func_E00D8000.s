.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00D8000
/* 3D67C0 E00D8000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3D67C4 E00D8004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3D67C8 E00D8008 4485A000 */  mtc1      $a1, $f20
/* 3D67CC E00D800C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3D67D0 E00D8010 4486B000 */  mtc1      $a2, $f22
/* 3D67D4 E00D8014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3D67D8 E00D8018 0080902D */  daddu     $s2, $a0, $zero
/* 3D67DC E00D801C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3D67E0 E00D8020 4487C000 */  mtc1      $a3, $f24
/* 3D67E4 E00D8024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D67E8 E00D8028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3D67EC E00D802C 8FB10064 */  lw        $s1, 0x64($sp)
/* 3D67F0 E00D8030 3C02E00E */  lui       $v0, %hi(func_E00D8120)
/* 3D67F4 E00D8034 24428120 */  addiu     $v0, $v0, %lo(func_E00D8120)
/* 3D67F8 E00D8038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3D67FC E00D803C 3C02E00E */  lui       $v0, %hi(func_E00D8128)
/* 3D6800 E00D8040 24428128 */  addiu     $v0, $v0, %lo(func_E00D8128)
/* 3D6804 E00D8044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D6808 E00D8048 3C02E00E */  lui       $v0, %hi(func_E00D825C)
/* 3D680C E00D804C 2442825C */  addiu     $v0, $v0, %lo(func_E00D825C)
/* 3D6810 E00D8050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3D6814 E00D8054 3C02E00E */  lui       $v0, %hi(func_E00D8264)
/* 3D6818 E00D8058 24428264 */  addiu     $v0, $v0, %lo(func_E00D8264)
/* 3D681C E00D805C AFA20024 */  sw        $v0, 0x24($sp)
/* 3D6820 E00D8060 2402006C */  addiu     $v0, $zero, 0x6c
/* 3D6824 E00D8064 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3D6828 E00D8068 AFB00028 */  sw        $s0, 0x28($sp)
/* 3D682C E00D806C AFA00010 */  sw        $zero, 0x10($sp)
/* 3D6830 E00D8070 0C080124 */  jal       func_E0200490
/* 3D6834 E00D8074 AFA20014 */   sw       $v0, 0x14($sp)
/* 3D6838 E00D8078 24040038 */  addiu     $a0, $zero, 0x38
/* 3D683C E00D807C 24030001 */  addiu     $v1, $zero, 1
/* 3D6840 E00D8080 0040802D */  daddu     $s0, $v0, $zero
/* 3D6844 E00D8084 0C08012C */  jal       func_E02004B0
/* 3D6848 E00D8088 AE030008 */   sw       $v1, 8($s0)
/* 3D684C E00D808C 0040202D */  daddu     $a0, $v0, $zero
/* 3D6850 E00D8090 14800003 */  bnez      $a0, .LE00D80A0
/* 3D6854 E00D8094 AE02000C */   sw       $v0, 0xc($s0)
.LE00D8098:
/* 3D6858 E00D8098 08036026 */  j         .LE00D8098
/* 3D685C E00D809C 00000000 */   nop
.LE00D80A0:
/* 3D6860 E00D80A0 AC920000 */  sw        $s2, ($a0)
/* 3D6864 E00D80A4 1E200004 */  bgtz      $s1, .LE00D80B8
/* 3D6868 E00D80A8 AC800014 */   sw       $zero, 0x14($a0)
/* 3D686C E00D80AC 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3D6870 E00D80B0 0803602F */  j         .LE00D80BC
/* 3D6874 E00D80B4 AC820010 */   sw       $v0, 0x10($a0)
.LE00D80B8:
/* 3D6878 E00D80B8 AC910010 */  sw        $s1, 0x10($a0)
.LE00D80BC:
/* 3D687C E00D80BC E4940004 */  swc1      $f20, 4($a0)
/* 3D6880 E00D80C0 E4960008 */  swc1      $f22, 8($a0)
/* 3D6884 E00D80C4 E498000C */  swc1      $f24, 0xc($a0)
/* 3D6888 E00D80C8 AC80001C */  sw        $zero, 0x1c($a0)
/* 3D688C E00D80CC C7A00060 */  lwc1      $f0, 0x60($sp)
/* 3D6890 E00D80D0 0200102D */  daddu     $v0, $s0, $zero
/* 3D6894 E00D80D4 AC800028 */  sw        $zero, 0x28($a0)
/* 3D6898 E00D80D8 E4800018 */  swc1      $f0, 0x18($a0)
/* 3D689C E00D80DC C4800028 */  lwc1      $f0, 0x28($a0)
/* 3D68A0 E00D80E0 240300FF */  addiu     $v1, $zero, 0xff
/* 3D68A4 E00D80E4 AC800020 */  sw        $zero, 0x20($a0)
/* 3D68A8 E00D80E8 AC800024 */  sw        $zero, 0x24($a0)
/* 3D68AC E00D80EC A0830034 */  sb        $v1, 0x34($a0)
/* 3D68B0 E00D80F0 A0830035 */  sb        $v1, 0x35($a0)
/* 3D68B4 E00D80F4 E4800030 */  swc1      $f0, 0x30($a0)
/* 3D68B8 E00D80F8 E480002C */  swc1      $f0, 0x2c($a0)
/* 3D68BC E00D80FC 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3D68C0 E00D8100 8FB20030 */  lw        $s2, 0x30($sp)
/* 3D68C4 E00D8104 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3D68C8 E00D8108 8FB00028 */  lw        $s0, 0x28($sp)
/* 3D68CC E00D810C D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3D68D0 E00D8110 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3D68D4 E00D8114 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3D68D8 E00D8118 03E00008 */  jr        $ra
/* 3D68DC E00D811C 27BD0050 */   addiu    $sp, $sp, 0x50

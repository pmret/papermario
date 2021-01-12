.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00DA000
/* 3D7240 E00DA000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3D7244 E00DA004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3D7248 E00DA008 4485A000 */  mtc1      $a1, $f20
/* 3D724C E00DA00C AFB1002C */  sw        $s1, 0x2c($sp)
/* 3D7250 E00DA010 0080882D */  daddu     $s1, $a0, $zero
/* 3D7254 E00DA014 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3D7258 E00DA018 4486B000 */  mtc1      $a2, $f22
/* 3D725C E00DA01C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3D7260 E00DA020 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3D7264 E00DA024 4487C000 */  mtc1      $a3, $f24
/* 3D7268 E00DA028 3C02E00E */  lui       $v0, %hi(func_E00DA0FC)
/* 3D726C E00DA02C 2442A0FC */  addiu     $v0, $v0, %lo(func_E00DA0FC)
/* 3D7270 E00DA030 AFA20018 */  sw        $v0, 0x18($sp)
/* 3D7274 E00DA034 3C02E00E */  lui       $v0, %hi(func_E00DA104)
/* 3D7278 E00DA038 2442A104 */  addiu     $v0, $v0, %lo(func_E00DA104)
/* 3D727C E00DA03C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3D7280 E00DA040 3C02E00E */  lui       $v0, %hi(func_E00DA1E0)
/* 3D7284 E00DA044 2442A1E0 */  addiu     $v0, $v0, %lo(func_E00DA1E0)
/* 3D7288 E00DA048 AFA20020 */  sw        $v0, 0x20($sp)
/* 3D728C E00DA04C 2402006D */  addiu     $v0, $zero, 0x6d
/* 3D7290 E00DA050 AFBF0030 */  sw        $ra, 0x30($sp)
/* 3D7294 E00DA054 AFB00028 */  sw        $s0, 0x28($sp)
/* 3D7298 E00DA058 AFA00010 */  sw        $zero, 0x10($sp)
/* 3D729C E00DA05C AFA00024 */  sw        $zero, 0x24($sp)
/* 3D72A0 E00DA060 0C080124 */  jal       func_E0200490
/* 3D72A4 E00DA064 AFA20014 */   sw       $v0, 0x14($sp)
/* 3D72A8 E00DA068 24040030 */  addiu     $a0, $zero, 0x30
/* 3D72AC E00DA06C 24030001 */  addiu     $v1, $zero, 1
/* 3D72B0 E00DA070 0040802D */  daddu     $s0, $v0, $zero
/* 3D72B4 E00DA074 0C08012C */  jal       func_E02004B0
/* 3D72B8 E00DA078 AE030008 */   sw       $v1, 8($s0)
/* 3D72BC E00DA07C 0040202D */  daddu     $a0, $v0, $zero
/* 3D72C0 E00DA080 14800003 */  bnez      $a0, .LE00DA090
/* 3D72C4 E00DA084 AE02000C */   sw       $v0, 0xc($s0)
.LE00DA088:
/* 3D72C8 E00DA088 08036822 */  j         .LE00DA088
/* 3D72CC E00DA08C 00000000 */   nop
.LE00DA090:
/* 3D72D0 E00DA090 0200102D */  daddu     $v0, $s0, $zero
/* 3D72D4 E00DA094 2403000A */  addiu     $v1, $zero, 0xa
/* 3D72D8 E00DA098 AC830010 */  sw        $v1, 0x10($a0)
/* 3D72DC E00DA09C 240300FF */  addiu     $v1, $zero, 0xff
/* 3D72E0 E00DA0A0 AC910000 */  sw        $s1, ($a0)
/* 3D72E4 E00DA0A4 AC800014 */  sw        $zero, 0x14($a0)
/* 3D72E8 E00DA0A8 AC830024 */  sw        $v1, 0x24($a0)
/* 3D72EC E00DA0AC E4940004 */  swc1      $f20, 4($a0)
/* 3D72F0 E00DA0B0 E4960008 */  swc1      $f22, 8($a0)
/* 3D72F4 E00DA0B4 E498000C */  swc1      $f24, 0xc($a0)
/* 3D72F8 E00DA0B8 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 3D72FC E00DA0BC 24030046 */  addiu     $v1, $zero, 0x46
/* 3D7300 E00DA0C0 AC830018 */  sw        $v1, 0x18($a0)
/* 3D7304 E00DA0C4 240300B4 */  addiu     $v1, $zero, 0xb4
/* 3D7308 E00DA0C8 AC83001C */  sw        $v1, 0x1c($a0)
/* 3D730C E00DA0CC 24030078 */  addiu     $v1, $zero, 0x78
/* 3D7310 E00DA0D0 AC830020 */  sw        $v1, 0x20($a0)
/* 3D7314 E00DA0D4 AC80002C */  sw        $zero, 0x2c($a0)
/* 3D7318 E00DA0D8 E4800028 */  swc1      $f0, 0x28($a0)
/* 3D731C E00DA0DC 8FBF0030 */  lw        $ra, 0x30($sp)
/* 3D7320 E00DA0E0 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3D7324 E00DA0E4 8FB00028 */  lw        $s0, 0x28($sp)
/* 3D7328 E00DA0E8 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3D732C E00DA0EC D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3D7330 E00DA0F0 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3D7334 E00DA0F4 03E00008 */  jr        $ra
/* 3D7338 E00DA0F8 27BD0050 */   addiu    $sp, $sp, 0x50

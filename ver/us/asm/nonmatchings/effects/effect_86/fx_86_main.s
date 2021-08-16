.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_86_main
/* 3AEE20 E00AC000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3AEE24 E00AC004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3AEE28 E00AC008 4485A000 */  mtc1      $a1, $f20
/* 3AEE2C E00AC00C AFB1002C */  sw        $s1, 0x2c($sp)
/* 3AEE30 E00AC010 0080882D */  daddu     $s1, $a0, $zero
/* 3AEE34 E00AC014 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3AEE38 E00AC018 4486B000 */  mtc1      $a2, $f22
/* 3AEE3C E00AC01C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3AEE40 E00AC020 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3AEE44 E00AC024 4487C000 */  mtc1      $a3, $f24
/* 3AEE48 E00AC028 3C02E00B */  lui       $v0, %hi(func_E00AC11C)
/* 3AEE4C E00AC02C 2442C11C */  addiu     $v0, $v0, %lo(func_E00AC11C)
/* 3AEE50 E00AC030 AFA20018 */  sw        $v0, 0x18($sp)
/* 3AEE54 E00AC034 3C02E00B */  lui       $v0, %hi(func_E00AC124)
/* 3AEE58 E00AC038 2442C124 */  addiu     $v0, $v0, %lo(func_E00AC124)
/* 3AEE5C E00AC03C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3AEE60 E00AC040 3C02E00B */  lui       $v0, %hi(func_E00AC280)
/* 3AEE64 E00AC044 2442C280 */  addiu     $v0, $v0, %lo(func_E00AC280)
/* 3AEE68 E00AC048 AFA20020 */  sw        $v0, 0x20($sp)
/* 3AEE6C E00AC04C 3C02E00B */  lui       $v0, %hi(func_E00AC288)
/* 3AEE70 E00AC050 2442C288 */  addiu     $v0, $v0, %lo(func_E00AC288)
/* 3AEE74 E00AC054 AFA20024 */  sw        $v0, 0x24($sp)
/* 3AEE78 E00AC058 24020056 */  addiu     $v0, $zero, 0x56
/* 3AEE7C E00AC05C AFBF0030 */  sw        $ra, 0x30($sp)
/* 3AEE80 E00AC060 AFB00028 */  sw        $s0, 0x28($sp)
/* 3AEE84 E00AC064 AFA00010 */  sw        $zero, 0x10($sp)
/* 3AEE88 E00AC068 0C080124 */  jal       func_E0200490
/* 3AEE8C E00AC06C AFA20014 */   sw       $v0, 0x14($sp)
/* 3AEE90 E00AC070 24040044 */  addiu     $a0, $zero, 0x44
/* 3AEE94 E00AC074 24030001 */  addiu     $v1, $zero, 1
/* 3AEE98 E00AC078 0040802D */  daddu     $s0, $v0, $zero
/* 3AEE9C E00AC07C 0C08012C */  jal       func_E02004B0
/* 3AEEA0 E00AC080 AE030008 */   sw       $v1, 8($s0)
/* 3AEEA4 E00AC084 0040202D */  daddu     $a0, $v0, $zero
/* 3AEEA8 E00AC088 14800003 */  bnez      $a0, .LE00AC098
/* 3AEEAC E00AC08C AE02000C */   sw       $v0, 0xc($s0)
.LE00AC090:
/* 3AEEB0 E00AC090 0802B024 */  j         .LE00AC090
/* 3AEEB4 E00AC094 00000000 */   nop
.LE00AC098:
/* 3AEEB8 E00AC098 AC910000 */  sw        $s1, ($a0)
/* 3AEEBC E00AC09C E4940004 */  swc1      $f20, 4($a0)
/* 3AEEC0 E00AC0A0 E4960008 */  swc1      $f22, 8($a0)
/* 3AEEC4 E00AC0A4 E498000C */  swc1      $f24, 0xc($a0)
/* 3AEEC8 E00AC0A8 8FA20064 */  lw        $v0, 0x64($sp)
/* 3AEECC E00AC0AC 3C03E00B */  lui       $v1, %hi(D_E00AC880)
/* 3AEED0 E00AC0B0 2463C880 */  addiu     $v1, $v1, %lo(D_E00AC880)
/* 3AEED4 E00AC0B4 AC800018 */  sw        $zero, 0x18($a0)
/* 3AEED8 E00AC0B8 AC820014 */  sw        $v0, 0x14($a0)
/* 3AEEDC E00AC0BC C7A00060 */  lwc1      $f0, 0x60($sp)
/* 3AEEE0 E00AC0C0 240200FF */  addiu     $v0, $zero, 0xff
/* 3AEEE4 E00AC0C4 AC820024 */  sw        $v0, 0x24($a0)
/* 3AEEE8 E00AC0C8 001110C0 */  sll       $v0, $s1, 3
/* 3AEEEC E00AC0CC 00431021 */  addu      $v0, $v0, $v1
/* 3AEEF0 E00AC0D0 AC800028 */  sw        $zero, 0x28($a0)
/* 3AEEF4 E00AC0D4 AC80002C */  sw        $zero, 0x2c($a0)
/* 3AEEF8 E00AC0D8 AC800030 */  sw        $zero, 0x30($a0)
/* 3AEEFC E00AC0DC AC800038 */  sw        $zero, 0x38($a0)
/* 3AEF00 E00AC0E0 AC800034 */  sw        $zero, 0x34($a0)
/* 3AEF04 E00AC0E4 E4800010 */  swc1      $f0, 0x10($a0)
/* 3AEF08 E00AC0E8 8C430000 */  lw        $v1, ($v0)
/* 3AEF0C E00AC0EC AC83001C */  sw        $v1, 0x1c($a0)
/* 3AEF10 E00AC0F0 8C430004 */  lw        $v1, 4($v0)
/* 3AEF14 E00AC0F4 0200102D */  daddu     $v0, $s0, $zero
/* 3AEF18 E00AC0F8 AC830020 */  sw        $v1, 0x20($a0)
/* 3AEF1C E00AC0FC 8FBF0030 */  lw        $ra, 0x30($sp)
/* 3AEF20 E00AC100 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3AEF24 E00AC104 8FB00028 */  lw        $s0, 0x28($sp)
/* 3AEF28 E00AC108 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3AEF2C E00AC10C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3AEF30 E00AC110 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3AEF34 E00AC114 03E00008 */  jr        $ra
/* 3AEF38 E00AC118 27BD0050 */   addiu    $sp, $sp, 0x50

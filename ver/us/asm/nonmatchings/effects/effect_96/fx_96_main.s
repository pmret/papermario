.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_96_main
/* 3BCD60 E00C0000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3BCD64 E00C0004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3BCD68 E00C0008 4485A000 */  mtc1      $a1, $f20
/* 3BCD6C E00C000C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 3BCD70 E00C0010 4486B000 */  mtc1      $a2, $f22
/* 3BCD74 E00C0014 AFB20030 */  sw        $s2, 0x30($sp)
/* 3BCD78 E00C0018 0080902D */  daddu     $s2, $a0, $zero
/* 3BCD7C E00C001C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 3BCD80 E00C0020 4487C000 */  mtc1      $a3, $f24
/* 3BCD84 E00C0024 27A40010 */  addiu     $a0, $sp, 0x10
/* 3BCD88 E00C0028 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3BCD8C E00C002C 8FB10064 */  lw        $s1, 0x64($sp)
/* 3BCD90 E00C0030 3C02E00C */  lui       $v0, %hi(func_E00C0158)
/* 3BCD94 E00C0034 24420158 */  addiu     $v0, $v0, %lo(func_E00C0158)
/* 3BCD98 E00C0038 AFA20018 */  sw        $v0, 0x18($sp)
/* 3BCD9C E00C003C 3C02E00C */  lui       $v0, %hi(func_E00C0160)
/* 3BCDA0 E00C0040 24420160 */  addiu     $v0, $v0, %lo(func_E00C0160)
/* 3BCDA4 E00C0044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3BCDA8 E00C0048 3C02E00C */  lui       $v0, %hi(func_E00C0710)
/* 3BCDAC E00C004C 24420710 */  addiu     $v0, $v0, %lo(func_E00C0710)
/* 3BCDB0 E00C0050 AFA20020 */  sw        $v0, 0x20($sp)
/* 3BCDB4 E00C0054 24020060 */  addiu     $v0, $zero, 0x60
/* 3BCDB8 E00C0058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 3BCDBC E00C005C AFB00028 */  sw        $s0, 0x28($sp)
/* 3BCDC0 E00C0060 AFA00010 */  sw        $zero, 0x10($sp)
/* 3BCDC4 E00C0064 AFA00024 */  sw        $zero, 0x24($sp)
/* 3BCDC8 E00C0068 0C080124 */  jal       func_E0200490
/* 3BCDCC E00C006C AFA20014 */   sw       $v0, 0x14($sp)
/* 3BCDD0 E00C0070 24040060 */  addiu     $a0, $zero, 0x60
/* 3BCDD4 E00C0074 24030001 */  addiu     $v1, $zero, 1
/* 3BCDD8 E00C0078 0040802D */  daddu     $s0, $v0, $zero
/* 3BCDDC E00C007C 0C08012C */  jal       func_E02004B0
/* 3BCDE0 E00C0080 AE030008 */   sw       $v1, 8($s0)
/* 3BCDE4 E00C0084 0040202D */  daddu     $a0, $v0, $zero
/* 3BCDE8 E00C0088 14800003 */  bnez      $a0, .LE00C0098
/* 3BCDEC E00C008C AE02000C */   sw       $v0, 0xc($s0)
.LE00C0090:
/* 3BCDF0 E00C0090 08030024 */  j         .LE00C0090
/* 3BCDF4 E00C0094 00000000 */   nop
.LE00C0098:
/* 3BCDF8 E00C0098 AC920000 */  sw        $s2, ($a0)
/* 3BCDFC E00C009C 1E200004 */  bgtz      $s1, .LE00C00B0
/* 3BCE00 E00C00A0 AC800014 */   sw       $zero, 0x14($a0)
/* 3BCE04 E00C00A4 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3BCE08 E00C00A8 0803002D */  j         .LE00C00B4
/* 3BCE0C E00C00AC AC820010 */   sw       $v0, 0x10($a0)
.LE00C00B0:
/* 3BCE10 E00C00B0 AC910010 */  sw        $s1, 0x10($a0)
.LE00C00B4:
/* 3BCE14 E00C00B4 0200102D */  daddu     $v0, $s0, $zero
/* 3BCE18 E00C00B8 24030002 */  addiu     $v1, $zero, 2
/* 3BCE1C E00C00BC AC800024 */  sw        $zero, 0x24($a0)
/* 3BCE20 E00C00C0 E4940004 */  swc1      $f20, 4($a0)
/* 3BCE24 E00C00C4 E4960008 */  swc1      $f22, 8($a0)
/* 3BCE28 E00C00C8 E498000C */  swc1      $f24, 0xc($a0)
/* 3BCE2C E00C00CC AC800030 */  sw        $zero, 0x30($a0)
/* 3BCE30 E00C00D0 AC800038 */  sw        $zero, 0x38($a0)
/* 3BCE34 E00C00D4 AC80003C */  sw        $zero, 0x3c($a0)
/* 3BCE38 E00C00D8 AC800040 */  sw        $zero, 0x40($a0)
/* 3BCE3C E00C00DC AC800044 */  sw        $zero, 0x44($a0)
/* 3BCE40 E00C00E0 AC800054 */  sw        $zero, 0x54($a0)
/* 3BCE44 E00C00E4 AC830058 */  sw        $v1, 0x58($a0)
/* 3BCE48 E00C00E8 C7A00060 */  lwc1      $f0, 0x60($sp)
/* 3BCE4C E00C00EC 3C01C100 */  lui       $at, 0xc100
/* 3BCE50 E00C00F0 44811000 */  mtc1      $at, $f2
/* 3BCE54 E00C00F4 3C01BF80 */  lui       $at, 0xbf80
/* 3BCE58 E00C00F8 44812000 */  mtc1      $at, $f4
/* 3BCE5C E00C00FC 240300C8 */  addiu     $v1, $zero, 0xc8
/* 3BCE60 E00C0100 AC830018 */  sw        $v1, 0x18($a0)
/* 3BCE64 E00C0104 240300DC */  addiu     $v1, $zero, 0xdc
/* 3BCE68 E00C0108 AC83001C */  sw        $v1, 0x1c($a0)
/* 3BCE6C E00C010C E4800028 */  swc1      $f0, 0x28($a0)
/* 3BCE70 E00C0110 3C014348 */  lui       $at, 0x4348
/* 3BCE74 E00C0114 44810000 */  mtc1      $at, $f0
/* 3BCE78 E00C0118 240300F0 */  addiu     $v1, $zero, 0xf0
/* 3BCE7C E00C011C AC80005C */  sw        $zero, 0x5c($a0)
/* 3BCE80 E00C0120 AC830020 */  sw        $v1, 0x20($a0)
/* 3BCE84 E00C0124 AC80002C */  sw        $zero, 0x2c($a0)
/* 3BCE88 E00C0128 E4820040 */  swc1      $f2, 0x40($a0)
/* 3BCE8C E00C012C E4840050 */  swc1      $f4, 0x50($a0)
/* 3BCE90 E00C0130 E4800034 */  swc1      $f0, 0x34($a0)
/* 3BCE94 E00C0134 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3BCE98 E00C0138 8FB20030 */  lw        $s2, 0x30($sp)
/* 3BCE9C E00C013C 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3BCEA0 E00C0140 8FB00028 */  lw        $s0, 0x28($sp)
/* 3BCEA4 E00C0144 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3BCEA8 E00C0148 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3BCEAC E00C014C D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3BCEB0 E00C0150 03E00008 */  jr        $ra
/* 3BCEB4 E00C0154 27BD0050 */   addiu    $sp, $sp, 0x50

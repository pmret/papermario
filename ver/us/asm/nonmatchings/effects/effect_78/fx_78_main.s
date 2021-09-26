.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_78_main
/* 3981F0 E009C000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 3981F4 E009C004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 3981F8 E009C008 4485A000 */  mtc1      $a1, $f20
/* 3981FC E009C00C AFB1002C */  sw        $s1, 0x2c($sp)
/* 398200 E009C010 0080882D */  daddu     $s1, $a0, $zero
/* 398204 E009C014 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 398208 E009C018 4486B000 */  mtc1      $a2, $f22
/* 39820C E009C01C 27A40010 */  addiu     $a0, $sp, 0x10
/* 398210 E009C020 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 398214 E009C024 4487C000 */  mtc1      $a3, $f24
/* 398218 E009C028 3C02E00A */  lui       $v0, %hi(func_E009C100)
/* 39821C E009C02C 2442C100 */  addiu     $v0, $v0, %lo(func_E009C100)
/* 398220 E009C030 AFA20018 */  sw        $v0, 0x18($sp)
/* 398224 E009C034 3C02E00A */  lui       $v0, %hi(func_E009C108)
/* 398228 E009C038 2442C108 */  addiu     $v0, $v0, %lo(func_E009C108)
/* 39822C E009C03C AFA2001C */  sw        $v0, 0x1c($sp)
/* 398230 E009C040 3C02E00A */  lui       $v0, %hi(func_E009C1DC)
/* 398234 E009C044 2442C1DC */  addiu     $v0, $v0, %lo(func_E009C1DC)
/* 398238 E009C048 AFA20020 */  sw        $v0, 0x20($sp)
/* 39823C E009C04C 2402004E */  addiu     $v0, $zero, 0x4e
/* 398240 E009C050 AFBF0030 */  sw        $ra, 0x30($sp)
/* 398244 E009C054 AFB00028 */  sw        $s0, 0x28($sp)
/* 398248 E009C058 AFA00010 */  sw        $zero, 0x10($sp)
/* 39824C E009C05C AFA00024 */  sw        $zero, 0x24($sp)
/* 398250 E009C060 0C080124 */  jal       shim_create_effect_instance
/* 398254 E009C064 AFA20014 */   sw       $v0, 0x14($sp)
/* 398258 E009C068 24040044 */  addiu     $a0, $zero, 0x44
/* 39825C E009C06C 24030001 */  addiu     $v1, $zero, 1
/* 398260 E009C070 0040802D */  daddu     $s0, $v0, $zero
/* 398264 E009C074 0C08012C */  jal       shim_general_heap_malloc
/* 398268 E009C078 AE030008 */   sw       $v1, 8($s0)
/* 39826C E009C07C 0040202D */  daddu     $a0, $v0, $zero
/* 398270 E009C080 14800003 */  bnez      $a0, .LE009C090
/* 398274 E009C084 AE02000C */   sw       $v0, 0xc($s0)
.LE009C088:
/* 398278 E009C088 08027022 */  j         .LE009C088
/* 39827C E009C08C 00000000 */   nop
.LE009C090:
/* 398280 E009C090 0200102D */  daddu     $v0, $s0, $zero
/* 398284 E009C094 24030064 */  addiu     $v1, $zero, 0x64
/* 398288 E009C098 AC830004 */  sw        $v1, 4($a0)
/* 39828C E009C09C 240300FF */  addiu     $v1, $zero, 0xff
/* 398290 E009C0A0 AC830018 */  sw        $v1, 0x18($a0)
/* 398294 E009C0A4 AC83001C */  sw        $v1, 0x1c($a0)
/* 398298 E009C0A8 AC830020 */  sw        $v1, 0x20($a0)
/* 39829C E009C0AC AC830024 */  sw        $v1, 0x24($a0)
/* 3982A0 E009C0B0 AC830028 */  sw        $v1, 0x28($a0)
/* 3982A4 E009C0B4 24030040 */  addiu     $v1, $zero, 0x40
/* 3982A8 E009C0B8 AC830030 */  sw        $v1, 0x30($a0)
/* 3982AC E009C0BC 2403000F */  addiu     $v1, $zero, 0xf
/* 3982B0 E009C0C0 AC910000 */  sw        $s1, ($a0)
/* 3982B4 E009C0C4 E494000C */  swc1      $f20, 0xc($a0)
/* 3982B8 E009C0C8 E4960010 */  swc1      $f22, 0x10($a0)
/* 3982BC E009C0CC E4980014 */  swc1      $f24, 0x14($a0)
/* 3982C0 E009C0D0 AC80002C */  sw        $zero, 0x2c($a0)
/* 3982C4 E009C0D4 AC830034 */  sw        $v1, 0x34($a0)
/* 3982C8 E009C0D8 AC800038 */  sw        $zero, 0x38($a0)
/* 3982CC E009C0DC AC800008 */  sw        $zero, 8($a0)
/* 3982D0 E009C0E0 8FBF0030 */  lw        $ra, 0x30($sp)
/* 3982D4 E009C0E4 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3982D8 E009C0E8 8FB00028 */  lw        $s0, 0x28($sp)
/* 3982DC E009C0EC D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3982E0 E009C0F0 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3982E4 E009C0F4 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3982E8 E009C0F8 03E00008 */  jr        $ra
/* 3982EC E009C0FC 27BD0050 */   addiu    $sp, $sp, 0x50

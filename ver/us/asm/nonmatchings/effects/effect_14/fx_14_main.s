.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_14_main
/* 330910 E001C000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 330914 E001C004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 330918 E001C008 46006506 */  mov.s     $f20, $f12
/* 33091C E001C00C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 330920 E001C010 46007586 */  mov.s     $f22, $f14
/* 330924 E001C014 AFB1002C */  sw        $s1, 0x2c($sp)
/* 330928 E001C018 00E0882D */  daddu     $s1, $a3, $zero
/* 33092C E001C01C 27A40010 */  addiu     $a0, $sp, 0x10
/* 330930 E001C020 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 330934 E001C024 4486C000 */  mtc1      $a2, $f24
/* 330938 E001C028 3C02E002 */  lui       $v0, %hi(fx_14_init)
/* 33093C E001C02C 2442C120 */  addiu     $v0, $v0, %lo(fx_14_init)
/* 330940 E001C030 AFA20018 */  sw        $v0, 0x18($sp)
/* 330944 E001C034 3C02E002 */  lui       $v0, %hi(fx_14_update)
/* 330948 E001C038 2442C128 */  addiu     $v0, $v0, %lo(fx_14_update)
/* 33094C E001C03C AFA2001C */  sw        $v0, 0x1c($sp)
/* 330950 E001C040 3C02E002 */  lui       $v0, %hi(fx_14_render)
/* 330954 E001C044 2442C200 */  addiu     $v0, $v0, %lo(fx_14_render)
/* 330958 E001C048 AFA20020 */  sw        $v0, 0x20($sp)
/* 33095C E001C04C 2402000E */  addiu     $v0, $zero, 0xe
/* 330960 E001C050 AFBF0030 */  sw        $ra, 0x30($sp)
/* 330964 E001C054 AFB00028 */  sw        $s0, 0x28($sp)
/* 330968 E001C058 AFA00010 */  sw        $zero, 0x10($sp)
/* 33096C E001C05C AFA00024 */  sw        $zero, 0x24($sp)
/* 330970 E001C060 0C080124 */  jal       shim_create_effect_instance
/* 330974 E001C064 AFA20014 */   sw       $v0, 0x14($sp)
/* 330978 E001C068 2404002C */  addiu     $a0, $zero, 0x2c
/* 33097C E001C06C 24030001 */  addiu     $v1, $zero, 1
/* 330980 E001C070 0040802D */  daddu     $s0, $v0, $zero
/* 330984 E001C074 0C08012C */  jal       shim_general_heap_malloc
/* 330988 E001C078 AE030008 */   sw       $v1, 8($s0)
/* 33098C E001C07C 14400003 */  bnez      $v0, .LE001C08C
/* 330990 E001C080 AE02000C */   sw       $v0, 0xc($s0)
.LE001C084:
/* 330994 E001C084 08007021 */  j         .LE001C084
/* 330998 E001C088 00000000 */   nop
.LE001C08C:
/* 33099C E001C08C 3C04E002 */  lui       $a0, %hi(D_E001C5E0)
/* 3309A0 E001C090 2484C5E0 */  addiu     $a0, $a0, %lo(D_E001C5E0)
/* 3309A4 E001C094 3C014120 */  lui       $at, 0x4120
/* 3309A8 E001C098 44812000 */  mtc1      $at, $f4
/* 3309AC E001C09C 3C01C040 */  lui       $at, 0xc040
/* 3309B0 E001C0A0 44810000 */  mtc1      $at, $f0
/* 3309B4 E001C0A4 3C014040 */  lui       $at, 0x4040
/* 3309B8 E001C0A8 44811000 */  mtc1      $at, $f2
/* 3309BC E001C0AC 8C830000 */  lw        $v1, ($a0)
/* 3309C0 E001C0B0 E4540000 */  swc1      $f20, ($v0)
/* 3309C4 E001C0B4 E4560004 */  swc1      $f22, 4($v0)
/* 3309C8 E001C0B8 E4580008 */  swc1      $f24, 8($v0)
/* 3309CC E001C0BC AC40000C */  sw        $zero, 0xc($v0)
/* 3309D0 E001C0C0 AC400014 */  sw        $zero, 0x14($v0)
/* 3309D4 E001C0C4 AC400018 */  sw        $zero, 0x18($v0)
/* 3309D8 E001C0C8 AC40001C */  sw        $zero, 0x1c($v0)
/* 3309DC E001C0CC E4400010 */  swc1      $f0, 0x10($v0)
/* 3309E0 E001C0D0 10600004 */  beqz      $v1, .LE001C0E4
/* 3309E4 E001C0D4 E4420020 */   swc1     $f2, 0x20($v0)
/* 3309E8 E001C0D8 3C01C120 */  lui       $at, 0xc120
/* 3309EC E001C0DC 44812000 */  mtc1      $at, $f4
/* 3309F0 E001C0E0 00000000 */  nop
.LE001C0E4:
/* 3309F4 E001C0E4 E4440024 */  swc1      $f4, 0x24($v0)
/* 3309F8 E001C0E8 AC510028 */  sw        $s1, 0x28($v0)
/* 3309FC E001C0EC 24620001 */  addiu     $v0, $v1, 1
/* 330A00 E001C0F0 AC820000 */  sw        $v0, ($a0)
/* 330A04 E001C0F4 28420002 */  slti      $v0, $v0, 2
/* 330A08 E001C0F8 50400001 */  beql      $v0, $zero, .LE001C100
/* 330A0C E001C0FC AC800000 */   sw       $zero, ($a0)
.LE001C100:
/* 330A10 E001C100 8FBF0030 */  lw        $ra, 0x30($sp)
/* 330A14 E001C104 8FB1002C */  lw        $s1, 0x2c($sp)
/* 330A18 E001C108 8FB00028 */  lw        $s0, 0x28($sp)
/* 330A1C E001C10C D7B80048 */  ldc1      $f24, 0x48($sp)
/* 330A20 E001C110 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 330A24 E001C114 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 330A28 E001C118 03E00008 */  jr        $ra
/* 330A2C E001C11C 27BD0050 */   addiu    $sp, $sp, 0x50

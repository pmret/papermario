.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_124_main
/* 3FEAE0 E0114000 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 3FEAE4 E0114004 27A40010 */  addiu     $a0, $sp, 0x10
/* 3FEAE8 E0114008 3C02E011 */  lui       $v0, %hi(func_E01140D4)
/* 3FEAEC E011400C 244240D4 */  addiu     $v0, $v0, %lo(func_E01140D4)
/* 3FEAF0 E0114010 AFA20018 */  sw        $v0, 0x18($sp)
/* 3FEAF4 E0114014 3C02E011 */  lui       $v0, %hi(func_E01140DC)
/* 3FEAF8 E0114018 244240DC */  addiu     $v0, $v0, %lo(func_E01140DC)
/* 3FEAFC E011401C AFA2001C */  sw        $v0, 0x1c($sp)
/* 3FEB00 E0114020 3C02E011 */  lui       $v0, %hi(func_E0114340)
/* 3FEB04 E0114024 24424340 */  addiu     $v0, $v0, %lo(func_E0114340)
/* 3FEB08 E0114028 AFA20020 */  sw        $v0, 0x20($sp)
/* 3FEB0C E011402C 2402007C */  addiu     $v0, $zero, 0x7c
/* 3FEB10 E0114030 AFBF002C */  sw        $ra, 0x2c($sp)
/* 3FEB14 E0114034 AFB00028 */  sw        $s0, 0x28($sp)
/* 3FEB18 E0114038 AFA00010 */  sw        $zero, 0x10($sp)
/* 3FEB1C E011403C AFA00024 */  sw        $zero, 0x24($sp)
/* 3FEB20 E0114040 0C080124 */  jal       shim_create_effect_instance
/* 3FEB24 E0114044 AFA20014 */   sw       $v0, 0x14($sp)
/* 3FEB28 E0114048 24040148 */  addiu     $a0, $zero, 0x148
/* 3FEB2C E011404C 24030001 */  addiu     $v1, $zero, 1
/* 3FEB30 E0114050 0040802D */  daddu     $s0, $v0, $zero
/* 3FEB34 E0114054 0C08012C */  jal       shim_general_heap_malloc
/* 3FEB38 E0114058 AE030008 */   sw       $v1, 8($s0)
/* 3FEB3C E011405C 0040282D */  daddu     $a1, $v0, $zero
/* 3FEB40 E0114060 14A00003 */  bnez      $a1, .LE0114070
/* 3FEB44 E0114064 AE02000C */   sw       $v0, 0xc($s0)
.LE0114068:
/* 3FEB48 E0114068 0804501A */  j         .LE0114068
/* 3FEB4C E011406C 00000000 */   nop
.LE0114070:
/* 3FEB50 E0114070 0000202D */  daddu     $a0, $zero, $zero
/* 3FEB54 E0114074 24060001 */  addiu     $a2, $zero, 1
/* 3FEB58 E0114078 00A0182D */  daddu     $v1, $a1, $zero
/* 3FEB5C E011407C 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 3FEB60 E0114080 ACA00004 */  sw        $zero, 4($a1)
/* 3FEB64 E0114084 ACA20000 */  sw        $v0, ($a1)
.LE0114088:
/* 3FEB68 E0114088 00A41021 */  addu      $v0, $a1, $a0
/* 3FEB6C E011408C AC600034 */  sw        $zero, 0x34($v1)
/* 3FEB70 E0114090 AC600060 */  sw        $zero, 0x60($v1)
/* 3FEB74 E0114094 AC60008C */  sw        $zero, 0x8c($v1)
/* 3FEB78 E0114098 AC6000B8 */  sw        $zero, 0xb8($v1)
/* 3FEB7C E011409C AC600008 */  sw        $zero, 8($v1)
/* 3FEB80 E01140A0 A04600FA */  sb        $a2, 0xfa($v0)
/* 3FEB84 E01140A4 A0460105 */  sb        $a2, 0x105($v0)
/* 3FEB88 E01140A8 AC600110 */  sw        $zero, 0x110($v1)
/* 3FEB8C E01140AC 24840001 */  addiu     $a0, $a0, 1
/* 3FEB90 E01140B0 A040013C */  sb        $zero, 0x13c($v0)
/* 3FEB94 E01140B4 2882000B */  slti      $v0, $a0, 0xb
/* 3FEB98 E01140B8 1440FFF3 */  bnez      $v0, .LE0114088
/* 3FEB9C E01140BC 24630004 */   addiu    $v1, $v1, 4
/* 3FEBA0 E01140C0 0200102D */  daddu     $v0, $s0, $zero
/* 3FEBA4 E01140C4 8FBF002C */  lw        $ra, 0x2c($sp)
/* 3FEBA8 E01140C8 8FB00028 */  lw        $s0, 0x28($sp)
/* 3FEBAC E01140CC 03E00008 */  jr        $ra
/* 3FEBB0 E01140D0 27BD0030 */   addiu    $sp, $sp, 0x30

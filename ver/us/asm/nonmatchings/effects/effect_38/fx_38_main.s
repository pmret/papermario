.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_38_main
/* 359F20 E004C000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 359F24 E004C004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 359F28 E004C008 4485A000 */  mtc1      $a1, $f20
/* 359F2C E004C00C AFB1002C */  sw        $s1, 0x2c($sp)
/* 359F30 E004C010 0080882D */  daddu     $s1, $a0, $zero
/* 359F34 E004C014 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 359F38 E004C018 4486B000 */  mtc1      $a2, $f22
/* 359F3C E004C01C 27A40010 */  addiu     $a0, $sp, 0x10
/* 359F40 E004C020 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 359F44 E004C024 4487C000 */  mtc1      $a3, $f24
/* 359F48 E004C028 3C02E005 */  lui       $v0, %hi(fx_38_init)
/* 359F4C E004C02C 2442C204 */  addiu     $v0, $v0, %lo(fx_38_init)
/* 359F50 E004C030 AFA20018 */  sw        $v0, 0x18($sp)
/* 359F54 E004C034 3C02E005 */  lui       $v0, %hi(fx_38_update)
/* 359F58 E004C038 2442C20C */  addiu     $v0, $v0, %lo(fx_38_update)
/* 359F5C E004C03C AFA2001C */  sw        $v0, 0x1c($sp)
/* 359F60 E004C040 3C02E005 */  lui       $v0, %hi(fx_38_render)
/* 359F64 E004C044 2442C364 */  addiu     $v0, $v0, %lo(fx_38_render)
/* 359F68 E004C048 AFA20020 */  sw        $v0, 0x20($sp)
/* 359F6C E004C04C 24020026 */  addiu     $v0, $zero, 0x26
/* 359F70 E004C050 AFBF0030 */  sw        $ra, 0x30($sp)
/* 359F74 E004C054 AFB00028 */  sw        $s0, 0x28($sp)
/* 359F78 E004C058 AFA00010 */  sw        $zero, 0x10($sp)
/* 359F7C E004C05C AFA00024 */  sw        $zero, 0x24($sp)
/* 359F80 E004C060 0C080124 */  jal       shim_create_effect_instance
/* 359F84 E004C064 AFA20014 */   sw       $v0, 0x14($sp)
/* 359F88 E004C068 24040034 */  addiu     $a0, $zero, 0x34
/* 359F8C E004C06C 24030001 */  addiu     $v1, $zero, 1
/* 359F90 E004C070 0040802D */  daddu     $s0, $v0, $zero
/* 359F94 E004C074 0C08012C */  jal       shim_general_heap_malloc
/* 359F98 E004C078 AE030008 */   sw       $v1, 8($s0)
/* 359F9C E004C07C AE02000C */  sw        $v0, 0xc($s0)
/* 359FA0 E004C080 0040802D */  daddu     $s0, $v0, $zero
/* 359FA4 E004C084 16000003 */  bnez      $s0, .LE004C094
/* 359FA8 E004C088 24040006 */   addiu    $a0, $zero, 6
.LE004C08C:
/* 359FAC E004C08C 08013023 */  j         .LE004C08C
/* 359FB0 E004C090 00000000 */   nop
.LE004C094:
/* 359FB4 E004C094 24020040 */  addiu     $v0, $zero, 0x40
/* 359FB8 E004C098 AE110000 */  sw        $s1, ($s0)
/* 359FBC E004C09C E6140004 */  swc1      $f20, 4($s0)
/* 359FC0 E004C0A0 E6160008 */  swc1      $f22, 8($s0)
/* 359FC4 E004C0A4 E618000C */  swc1      $f24, 0xc($s0)
/* 359FC8 E004C0A8 AE000010 */  sw        $zero, 0x10($s0)
/* 359FCC E004C0AC AE020018 */  sw        $v0, 0x18($s0)
/* 359FD0 E004C0B0 AE000014 */  sw        $zero, 0x14($s0)
/* 359FD4 E004C0B4 0C080138 */  jal       shim_rand_int
/* 359FD8 E004C0B8 AE00001C */   sw       $zero, 0x1c($s0)
/* 359FDC E004C0BC 12200006 */  beqz      $s1, .LE004C0D8
/* 359FE0 E004C0C0 AE020020 */   sw       $v0, 0x20($s0)
/* 359FE4 E004C0C4 24020001 */  addiu     $v0, $zero, 1
/* 359FE8 E004C0C8 1222000A */  beq       $s1, $v0, .LE004C0F4
/* 359FEC E004C0CC 00000000 */   nop
/* 359FF0 E004C0D0 08013059 */  j         .LE004C164
/* 359FF4 E004C0D4 00000000 */   nop
.LE004C0D8:
/* 359FF8 E004C0D8 3C013F80 */  lui       $at, 0x3f80
/* 359FFC E004C0DC 44810000 */  mtc1      $at, $f0
/* 35A000 E004C0E0 AE000024 */  sw        $zero, 0x24($s0)
/* 35A004 E004C0E4 AE00002C */  sw        $zero, 0x2c($s0)
/* 35A008 E004C0E8 E6000028 */  swc1      $f0, 0x28($s0)
/* 35A00C E004C0EC 08013079 */  j         .LE004C1E4
/* 35A010 E004C0F0 E6000030 */   swc1     $f0, 0x30($s0)
.LE004C0F4:
/* 35A014 E004C0F4 0C080138 */  jal       shim_rand_int
/* 35A018 E004C0F8 2404000A */   addiu    $a0, $zero, 0xa
/* 35A01C E004C0FC 3C01E005 */  lui       $at, %hi(D_E004C6A0)
/* 35A020 E004C100 D434C6A0 */  ldc1      $f20, %lo(D_E004C6A0)($at)
/* 35A024 E004C104 44820000 */  mtc1      $v0, $f0
/* 35A028 E004C108 00000000 */  nop
/* 35A02C E004C10C 46800021 */  cvt.d.w   $f0, $f0
/* 35A030 E004C110 46340002 */  mul.d     $f0, $f0, $f20
/* 35A034 E004C114 00000000 */  nop
/* 35A038 E004C118 3C01C014 */  lui       $at, 0xc014
/* 35A03C E004C11C 44811800 */  mtc1      $at, $f3
/* 35A040 E004C120 44801000 */  mtc1      $zero, $f2
/* 35A044 E004C124 00000000 */  nop
/* 35A048 E004C128 46220000 */  add.d     $f0, $f0, $f2
/* 35A04C E004C12C 2404000A */  addiu     $a0, $zero, 0xa
/* 35A050 E004C130 46200020 */  cvt.s.d   $f0, $f0
/* 35A054 E004C134 0C080138 */  jal       shim_rand_int
/* 35A058 E004C138 E6000024 */   swc1     $f0, 0x24($s0)
/* 35A05C E004C13C 44820000 */  mtc1      $v0, $f0
/* 35A060 E004C140 00000000 */  nop
/* 35A064 E004C144 46800021 */  cvt.d.w   $f0, $f0
/* 35A068 E004C148 46340002 */  mul.d     $f0, $f0, $f20
/* 35A06C E004C14C 00000000 */  nop
/* 35A070 E004C150 3C013FE0 */  lui       $at, 0x3fe0
/* 35A074 E004C154 44811800 */  mtc1      $at, $f3
/* 35A078 E004C158 44801000 */  mtc1      $zero, $f2
/* 35A07C E004C15C 08013075 */  j         .LE004C1D4
/* 35A080 E004C160 46220000 */   add.d    $f0, $f0, $f2
.LE004C164:
/* 35A084 E004C164 0C080138 */  jal       shim_rand_int
/* 35A088 E004C168 2404000A */   addiu    $a0, $zero, 0xa
/* 35A08C E004C16C 3C01E005 */  lui       $at, %hi(D_E004C6A8)
/* 35A090 E004C170 D434C6A8 */  ldc1      $f20, %lo(D_E004C6A8)($at)
/* 35A094 E004C174 44821000 */  mtc1      $v0, $f2
/* 35A098 E004C178 00000000 */  nop
/* 35A09C E004C17C 468010A1 */  cvt.d.w   $f2, $f2
/* 35A0A0 E004C180 46341082 */  mul.d     $f2, $f2, $f20
/* 35A0A4 E004C184 00000000 */  nop
/* 35A0A8 E004C188 3C014014 */  lui       $at, 0x4014
/* 35A0AC E004C18C 44810800 */  mtc1      $at, $f1
/* 35A0B0 E004C190 44800000 */  mtc1      $zero, $f0
/* 35A0B4 E004C194 00000000 */  nop
/* 35A0B8 E004C198 46220001 */  sub.d     $f0, $f0, $f2
/* 35A0BC E004C19C 2404000A */  addiu     $a0, $zero, 0xa
/* 35A0C0 E004C1A0 46200020 */  cvt.s.d   $f0, $f0
/* 35A0C4 E004C1A4 0C080138 */  jal       shim_rand_int
/* 35A0C8 E004C1A8 E6000024 */   swc1     $f0, 0x24($s0)
/* 35A0CC E004C1AC 44820000 */  mtc1      $v0, $f0
/* 35A0D0 E004C1B0 00000000 */  nop
/* 35A0D4 E004C1B4 46800021 */  cvt.d.w   $f0, $f0
/* 35A0D8 E004C1B8 46340002 */  mul.d     $f0, $f0, $f20
/* 35A0DC E004C1BC 00000000 */  nop
/* 35A0E0 E004C1C0 3C013FF0 */  lui       $at, 0x3ff0
/* 35A0E4 E004C1C4 44811800 */  mtc1      $at, $f3
/* 35A0E8 E004C1C8 44801000 */  mtc1      $zero, $f2
/* 35A0EC E004C1CC 00000000 */  nop
/* 35A0F0 E004C1D0 46220000 */  add.d     $f0, $f0, $f2
.LE004C1D4:
/* 35A0F4 E004C1D4 AE00002C */  sw        $zero, 0x2c($s0)
/* 35A0F8 E004C1D8 AE000030 */  sw        $zero, 0x30($s0)
/* 35A0FC E004C1DC 46200020 */  cvt.s.d   $f0, $f0
/* 35A100 E004C1E0 E6000028 */  swc1      $f0, 0x28($s0)
.LE004C1E4:
/* 35A104 E004C1E4 8FBF0030 */  lw        $ra, 0x30($sp)
/* 35A108 E004C1E8 8FB1002C */  lw        $s1, 0x2c($sp)
/* 35A10C E004C1EC 8FB00028 */  lw        $s0, 0x28($sp)
/* 35A110 E004C1F0 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 35A114 E004C1F4 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 35A118 E004C1F8 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 35A11C E004C1FC 03E00008 */  jr        $ra
/* 35A120 E004C200 27BD0050 */   addiu    $sp, $sp, 0x50

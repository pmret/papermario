.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_22_main
/* 33FE80 E002C000 27BDFF98 */  addiu     $sp, $sp, -0x68
/* 33FE84 E002C004 F7B40050 */  sdc1      $f20, 0x50($sp)
/* 33FE88 E002C008 4485A000 */  mtc1      $a1, $f20
/* 33FE8C E002C00C F7B60058 */  sdc1      $f22, 0x58($sp)
/* 33FE90 E002C010 4486B000 */  mtc1      $a2, $f22
/* 33FE94 E002C014 27A40010 */  addiu     $a0, $sp, 0x10
/* 33FE98 E002C018 F7B80060 */  sdc1      $f24, 0x60($sp)
/* 33FE9C E002C01C 4487C000 */  mtc1      $a3, $f24
/* 33FEA0 E002C020 3C02E003 */  lui       $v0, %hi(func_E002C234)
/* 33FEA4 E002C024 2442C234 */  addiu     $v0, $v0, %lo(func_E002C234)
/* 33FEA8 E002C028 AFA20018 */  sw        $v0, 0x18($sp)
/* 33FEAC E002C02C 3C02E003 */  lui       $v0, %hi(func_E002C23C)
/* 33FEB0 E002C030 2442C23C */  addiu     $v0, $v0, %lo(func_E002C23C)
/* 33FEB4 E002C034 AFA2001C */  sw        $v0, 0x1c($sp)
/* 33FEB8 E002C038 3C02E003 */  lui       $v0, %hi(func_E002C3D0)
/* 33FEBC E002C03C 2442C3D0 */  addiu     $v0, $v0, %lo(func_E002C3D0)
/* 33FEC0 E002C040 AFA20020 */  sw        $v0, 0x20($sp)
/* 33FEC4 E002C044 24020016 */  addiu     $v0, $zero, 0x16
/* 33FEC8 E002C048 AFBF0048 */  sw        $ra, 0x48($sp)
/* 33FECC E002C04C AFB70044 */  sw        $s7, 0x44($sp)
/* 33FED0 E002C050 AFB60040 */  sw        $s6, 0x40($sp)
/* 33FED4 E002C054 AFB5003C */  sw        $s5, 0x3c($sp)
/* 33FED8 E002C058 AFB40038 */  sw        $s4, 0x38($sp)
/* 33FEDC E002C05C AFB30034 */  sw        $s3, 0x34($sp)
/* 33FEE0 E002C060 AFB20030 */  sw        $s2, 0x30($sp)
/* 33FEE4 E002C064 AFB1002C */  sw        $s1, 0x2c($sp)
/* 33FEE8 E002C068 AFB00028 */  sw        $s0, 0x28($sp)
/* 33FEEC E002C06C AFA00010 */  sw        $zero, 0x10($sp)
/* 33FEF0 E002C070 AFA00024 */  sw        $zero, 0x24($sp)
/* 33FEF4 E002C074 0C080124 */  jal       shim_create_effect_instance
/* 33FEF8 E002C078 AFA20014 */   sw       $v0, 0x14($sp)
/* 33FEFC E002C07C 24040240 */  addiu     $a0, $zero, 0x240
/* 33FF00 E002C080 24150009 */  addiu     $s5, $zero, 9
/* 33FF04 E002C084 0040802D */  daddu     $s0, $v0, $zero
/* 33FF08 E002C088 0C08012C */  jal       shim_general_heap_malloc
/* 33FF0C E002C08C AE150008 */   sw       $s5, 8($s0)
/* 33FF10 E002C090 0040882D */  daddu     $s1, $v0, $zero
/* 33FF14 E002C094 16200003 */  bnez      $s1, .LE002C0A4
/* 33FF18 E002C098 AE11000C */   sw       $s1, 0xc($s0)
.LE002C09C:
/* 33FF1C E002C09C 0800B027 */  j         .LE002C09C
/* 33FF20 E002C0A0 00000000 */   nop
.LE002C0A4:
/* 33FF24 E002C0A4 3C01C000 */  lui       $at, 0xc000
/* 33FF28 E002C0A8 44811000 */  mtc1      $at, $f2
/* 33FF2C E002C0AC AE200024 */  sw        $zero, 0x24($s1)
/* 33FF30 E002C0B0 E6340000 */  swc1      $f20, ($s1)
/* 33FF34 E002C0B4 E6360004 */  swc1      $f22, 4($s1)
/* 33FF38 E002C0B8 C7A00078 */  lwc1      $f0, 0x78($sp)
/* 33FF3C E002C0BC 2404003C */  addiu     $a0, $zero, 0x3c
/* 33FF40 E002C0C0 E6380008 */  swc1      $f24, 8($s1)
/* 33FF44 E002C0C4 AE20002C */  sw        $zero, 0x2c($s1)
/* 33FF48 E002C0C8 AE200030 */  sw        $zero, 0x30($s1)
/* 33FF4C E002C0CC E620000C */  swc1      $f0, 0xc($s1)
/* 33FF50 E002C0D0 0C080138 */  jal       shim_rand_int
/* 33FF54 E002C0D4 E6220014 */   swc1     $f2, 0x14($s1)
/* 33FF58 E002C0D8 2404003C */  addiu     $a0, $zero, 0x3c
/* 33FF5C E002C0DC 2442FFE2 */  addiu     $v0, $v0, -0x1e
/* 33FF60 E002C0E0 44820000 */  mtc1      $v0, $f0
/* 33FF64 E002C0E4 00000000 */  nop
/* 33FF68 E002C0E8 46800020 */  cvt.s.w   $f0, $f0
/* 33FF6C E002C0EC 240200FF */  addiu     $v0, $zero, 0xff
/* 33FF70 E002C0F0 E6200034 */  swc1      $f0, 0x34($s1)
/* 33FF74 E002C0F4 0C080138 */  jal       shim_rand_int
/* 33FF78 E002C0F8 AE220028 */   sw       $v0, 0x28($s1)
/* 33FF7C E002C0FC 2442FFE2 */  addiu     $v0, $v0, -0x1e
/* 33FF80 E002C100 44822000 */  mtc1      $v0, $f4
/* 33FF84 E002C104 00000000 */  nop
/* 33FF88 E002C108 46802120 */  cvt.s.w   $f4, $f4
/* 33FF8C E002C10C 3C013FD0 */  lui       $at, 0x3fd0
/* 33FF90 E002C110 44811800 */  mtc1      $at, $f3
/* 33FF94 E002C114 44801000 */  mtc1      $zero, $f2
/* 33FF98 E002C118 46002021 */  cvt.d.s   $f0, $f4
/* 33FF9C E002C11C 46220002 */  mul.d     $f0, $f0, $f2
/* 33FFA0 E002C120 00000000 */  nop
/* 33FFA4 E002C124 24120001 */  addiu     $s2, $zero, 1
/* 33FFA8 E002C128 24020014 */  addiu     $v0, $zero, 0x14
/* 33FFAC E002C12C AE220020 */  sw        $v0, 0x20($s1)
/* 33FFB0 E002C130 0255102A */  slt       $v0, $s2, $s5
/* 33FFB4 E002C134 E6240038 */  swc1      $f4, 0x38($s1)
/* 33FFB8 E002C138 46200020 */  cvt.s.d   $f0, $f0
/* 33FFBC E002C13C E620003C */  swc1      $f0, 0x3c($s1)
/* 33FFC0 E002C140 1040002E */  beqz      $v0, .LE002C1FC
/* 33FFC4 E002C144 26310040 */   addiu    $s1, $s1, 0x40
/* 33FFC8 E002C148 3C17E003 */  lui       $s7, %hi(D_E002C984)
/* 33FFCC E002C14C 26F7C984 */  addiu     $s7, $s7, %lo(D_E002C984)
/* 33FFD0 E002C150 3C16E003 */  lui       $s6, %hi(D_E002C964)
/* 33FFD4 E002C154 26D6C964 */  addiu     $s6, $s6, %lo(D_E002C964)
/* 33FFD8 E002C158 26300034 */  addiu     $s0, $s1, 0x34
/* 33FFDC E002C15C 0000A02D */  daddu     $s4, $zero, $zero
/* 33FFE0 E002C160 0280982D */  daddu     $s3, $s4, $zero
/* 33FFE4 E002C164 3C01E003 */  lui       $at, %hi(D_E002C9D0)
/* 33FFE8 E002C168 D436C9D0 */  ldc1      $f22, %lo(D_E002C9D0)($at)
/* 33FFEC E002C16C 3C013FF0 */  lui       $at, 0x3ff0
/* 33FFF0 E002C170 4481A800 */  mtc1      $at, $f21
/* 33FFF4 E002C174 4480A000 */  mtc1      $zero, $f20
.LE002C178:
/* 33FFF8 E002C178 02771021 */  addu      $v0, $s3, $s7
/* 33FFFC E002C17C C4400000 */  lwc1      $f0, ($v0)
/* 340000 E002C180 E600FFE4 */  swc1      $f0, -0x1c($s0)
/* 340004 E002C184 C4400004 */  lwc1      $f0, 4($v0)
/* 340008 E002C188 02961021 */  addu      $v0, $s4, $s6
/* 34000C E002C18C E600FFE8 */  swc1      $f0, -0x18($s0)
/* 340010 E002C190 AE200000 */  sw        $zero, ($s1)
/* 340014 E002C194 AE00FFD0 */  sw        $zero, -0x30($s0)
/* 340018 E002C198 AE00FFD4 */  sw        $zero, -0x2c($s0)
/* 34001C E002C19C C4400000 */  lwc1      $f0, ($v0)
/* 340020 E002C1A0 46000000 */  add.s     $f0, $f0, $f0
/* 340024 E002C1A4 2404000A */  addiu     $a0, $zero, 0xa
/* 340028 E002C1A8 0C080138 */  jal       shim_rand_int
/* 34002C E002C1AC E600FFDC */   swc1     $f0, -0x24($s0)
/* 340030 E002C1B0 44820000 */  mtc1      $v0, $f0
/* 340034 E002C1B4 00000000 */  nop
/* 340038 E002C1B8 46800020 */  cvt.s.w   $f0, $f0
/* 34003C E002C1BC 46000021 */  cvt.d.s   $f0, $f0
/* 340040 E002C1C0 46360002 */  mul.d     $f0, $f0, $f22
/* 340044 E002C1C4 00000000 */  nop
/* 340048 E002C1C8 26940004 */  addiu     $s4, $s4, 4
/* 34004C E002C1CC 26730008 */  addiu     $s3, $s3, 8
/* 340050 E002C1D0 26520001 */  addiu     $s2, $s2, 1
/* 340054 E002C1D4 46200000 */  add.d     $f0, $f0, $f0
/* 340058 E002C1D8 26310040 */  addiu     $s1, $s1, 0x40
/* 34005C E002C1DC 0255102A */  slt       $v0, $s2, $s5
/* 340060 E002C1E0 46340000 */  add.d     $f0, $f0, $f20
/* 340064 E002C1E4 AE00FFF8 */  sw        $zero, -8($s0)
/* 340068 E002C1E8 AE000000 */  sw        $zero, ($s0)
/* 34006C E002C1EC 46200020 */  cvt.s.d   $f0, $f0
/* 340070 E002C1F0 E600FFE0 */  swc1      $f0, -0x20($s0)
/* 340074 E002C1F4 1440FFE0 */  bnez      $v0, .LE002C178
/* 340078 E002C1F8 26100040 */   addiu    $s0, $s0, 0x40
.LE002C1FC:
/* 34007C E002C1FC 8FBF0048 */  lw        $ra, 0x48($sp)
/* 340080 E002C200 8FB70044 */  lw        $s7, 0x44($sp)
/* 340084 E002C204 8FB60040 */  lw        $s6, 0x40($sp)
/* 340088 E002C208 8FB5003C */  lw        $s5, 0x3c($sp)
/* 34008C E002C20C 8FB40038 */  lw        $s4, 0x38($sp)
/* 340090 E002C210 8FB30034 */  lw        $s3, 0x34($sp)
/* 340094 E002C214 8FB20030 */  lw        $s2, 0x30($sp)
/* 340098 E002C218 8FB1002C */  lw        $s1, 0x2c($sp)
/* 34009C E002C21C 8FB00028 */  lw        $s0, 0x28($sp)
/* 3400A0 E002C220 D7B80060 */  ldc1      $f24, 0x60($sp)
/* 3400A4 E002C224 D7B60058 */  ldc1      $f22, 0x58($sp)
/* 3400A8 E002C228 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 3400AC E002C22C 03E00008 */  jr        $ra
/* 3400B0 E002C230 27BD0068 */   addiu    $sp, $sp, 0x68

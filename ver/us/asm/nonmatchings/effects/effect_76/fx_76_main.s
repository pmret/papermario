.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_76_main
/* 395BB0 E0098000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 395BB4 E0098004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 395BB8 E0098008 4485A000 */  mtc1      $a1, $f20
/* 395BBC E009800C F7B60040 */  sdc1      $f22, 0x40($sp)
/* 395BC0 E0098010 4486B000 */  mtc1      $a2, $f22
/* 395BC4 E0098014 AFB20030 */  sw        $s2, 0x30($sp)
/* 395BC8 E0098018 0080902D */  daddu     $s2, $a0, $zero
/* 395BCC E009801C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 395BD0 E0098020 4487C000 */  mtc1      $a3, $f24
/* 395BD4 E0098024 27A40010 */  addiu     $a0, $sp, 0x10
/* 395BD8 E0098028 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* 395BDC E009802C C7BA0074 */  lwc1      $f26, 0x74($sp)
/* 395BE0 E0098030 3C02E00A */  lui       $v0, %hi(func_E0098168)
/* 395BE4 E0098034 24428168 */  addiu     $v0, $v0, %lo(func_E0098168)
/* 395BE8 E0098038 AFA20018 */  sw        $v0, 0x18($sp)
/* 395BEC E009803C 3C02E00A */  lui       $v0, %hi(func_E0098170)
/* 395BF0 E0098040 24428170 */  addiu     $v0, $v0, %lo(func_E0098170)
/* 395BF4 E0098044 AFA2001C */  sw        $v0, 0x1c($sp)
/* 395BF8 E0098048 3C02E00A */  lui       $v0, %hi(func_E009829C)
/* 395BFC E009804C 2442829C */  addiu     $v0, $v0, %lo(func_E009829C)
/* 395C00 E0098050 AFA20020 */  sw        $v0, 0x20($sp)
/* 395C04 E0098054 2402004C */  addiu     $v0, $zero, 0x4c
/* 395C08 E0098058 AFBF0034 */  sw        $ra, 0x34($sp)
/* 395C0C E009805C AFB1002C */  sw        $s1, 0x2c($sp)
/* 395C10 E0098060 AFB00028 */  sw        $s0, 0x28($sp)
/* 395C14 E0098064 AFA00010 */  sw        $zero, 0x10($sp)
/* 395C18 E0098068 AFA00024 */  sw        $zero, 0x24($sp)
/* 395C1C E009806C 0C080124 */  jal       func_E0200490
/* 395C20 E0098070 AFA20014 */   sw       $v0, 0x14($sp)
/* 395C24 E0098074 24040050 */  addiu     $a0, $zero, 0x50
/* 395C28 E0098078 24030001 */  addiu     $v1, $zero, 1
/* 395C2C E009807C 0040882D */  daddu     $s1, $v0, $zero
/* 395C30 E0098080 0C08012C */  jal       func_E02004B0
/* 395C34 E0098084 AE230008 */   sw       $v1, 8($s1)
/* 395C38 E0098088 0040802D */  daddu     $s0, $v0, $zero
/* 395C3C E009808C 16000003 */  bnez      $s0, .LE009809C
/* 395C40 E0098090 AE22000C */   sw       $v0, 0xc($s1)
.LE0098094:
/* 395C44 E0098094 08026025 */  j         .LE0098094
/* 395C48 E0098098 00000000 */   nop
.LE009809C:
/* 395C4C E009809C AE120000 */  sw        $s2, ($s0)
/* 395C50 E00980A0 E6140004 */  swc1      $f20, 4($s0)
/* 395C54 E00980A4 E6160008 */  swc1      $f22, 8($s0)
/* 395C58 E00980A8 E618000C */  swc1      $f24, 0xc($s0)
/* 395C5C E00980AC C7A00068 */  lwc1      $f0, 0x68($sp)
/* 395C60 E00980B0 E6000010 */  swc1      $f0, 0x10($s0)
/* 395C64 E00980B4 C7A0006C */  lwc1      $f0, 0x6c($sp)
/* 395C68 E00980B8 E6000018 */  swc1      $f0, 0x18($s0)
/* 395C6C E00980BC C7A00070 */  lwc1      $f0, 0x70($sp)
/* 395C70 E00980C0 E6000020 */  swc1      $f0, 0x20($s0)
/* 395C74 E00980C4 8FA20078 */  lw        $v0, 0x78($sp)
/* 395C78 E00980C8 24040168 */  addiu     $a0, $zero, 0x168
/* 395C7C E00980CC AE00004C */  sw        $zero, 0x4c($s0)
/* 395C80 E00980D0 AE000014 */  sw        $zero, 0x14($s0)
/* 395C84 E00980D4 AE00001C */  sw        $zero, 0x1c($s0)
/* 395C88 E00980D8 AE000024 */  sw        $zero, 0x24($s0)
/* 395C8C E00980DC 0C080138 */  jal       func_E02004E0
/* 395C90 E00980E0 AE020048 */   sw       $v0, 0x48($s0)
/* 395C94 E00980E4 24040168 */  addiu     $a0, $zero, 0x168
/* 395C98 E00980E8 44820000 */  mtc1      $v0, $f0
/* 395C9C E00980EC 00000000 */  nop
/* 395CA0 E00980F0 46800020 */  cvt.s.w   $f0, $f0
/* 395CA4 E00980F4 0C080138 */  jal       func_E02004E0
/* 395CA8 E00980F8 E6000028 */   swc1     $f0, 0x28($s0)
/* 395CAC E00980FC 44820000 */  mtc1      $v0, $f0
/* 395CB0 E0098100 00000000 */  nop
/* 395CB4 E0098104 46800020 */  cvt.s.w   $f0, $f0
/* 395CB8 E0098108 0220102D */  daddu     $v0, $s1, $zero
/* 395CBC E009810C 240300FF */  addiu     $v1, $zero, 0xff
/* 395CC0 E0098110 E600002C */  swc1      $f0, 0x2c($s0)
/* 395CC4 E0098114 3C0141A0 */  lui       $at, 0x41a0
/* 395CC8 E0098118 44810000 */  mtc1      $at, $f0
/* 395CCC E009811C 3C01C1A0 */  lui       $at, 0xc1a0
/* 395CD0 E0098120 44811000 */  mtc1      $at, $f2
/* 395CD4 E0098124 461AD100 */  add.s     $f4, $f26, $f26
/* 395CD8 E0098128 AE000030 */  sw        $zero, 0x30($s0)
/* 395CDC E009812C AE030044 */  sw        $v1, 0x44($s0)
/* 395CE0 E0098130 AE000040 */  sw        $zero, 0x40($s0)
/* 395CE4 E0098134 E6000038 */  swc1      $f0, 0x38($s0)
/* 395CE8 E0098138 E6020034 */  swc1      $f2, 0x34($s0)
/* 395CEC E009813C E604003C */  swc1      $f4, 0x3c($s0)
/* 395CF0 E0098140 8FBF0034 */  lw        $ra, 0x34($sp)
/* 395CF4 E0098144 8FB20030 */  lw        $s2, 0x30($sp)
/* 395CF8 E0098148 8FB1002C */  lw        $s1, 0x2c($sp)
/* 395CFC E009814C 8FB00028 */  lw        $s0, 0x28($sp)
/* 395D00 E0098150 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* 395D04 E0098154 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 395D08 E0098158 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 395D0C E009815C D7B40038 */  ldc1      $f20, 0x38($sp)
/* 395D10 E0098160 03E00008 */  jr        $ra
/* 395D14 E0098164 27BD0058 */   addiu    $sp, $sp, 0x58

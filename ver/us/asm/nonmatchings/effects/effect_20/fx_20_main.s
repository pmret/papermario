.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_20_main
/* 33CDF0 E0028000 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 33CDF4 E0028004 F7B40040 */  sdc1      $f20, 0x40($sp)
/* 33CDF8 E0028008 4485A000 */  mtc1      $a1, $f20
/* 33CDFC E002800C AFB30034 */  sw        $s3, 0x34($sp)
/* 33CE00 E0028010 0080982D */  daddu     $s3, $a0, $zero
/* 33CE04 E0028014 F7B60048 */  sdc1      $f22, 0x48($sp)
/* 33CE08 E0028018 4486B000 */  mtc1      $a2, $f22
/* 33CE0C E002801C 27A40010 */  addiu     $a0, $sp, 0x10
/* 33CE10 E0028020 F7B80050 */  sdc1      $f24, 0x50($sp)
/* 33CE14 E0028024 4487C000 */  mtc1      $a3, $f24
/* 33CE18 E0028028 3C02E003 */  lui       $v0, %hi(fx_20_init)
/* 33CE1C E002802C 24428240 */  addiu     $v0, $v0, %lo(fx_20_init)
/* 33CE20 E0028030 AFA20018 */  sw        $v0, 0x18($sp)
/* 33CE24 E0028034 3C02E003 */  lui       $v0, %hi(fx_20_update)
/* 33CE28 E0028038 24428248 */  addiu     $v0, $v0, %lo(fx_20_update)
/* 33CE2C E002803C AFA2001C */  sw        $v0, 0x1c($sp)
/* 33CE30 E0028040 3C02E003 */  lui       $v0, %hi(fx_20_render)
/* 33CE34 E0028044 244284E8 */  addiu     $v0, $v0, %lo(fx_20_render)
/* 33CE38 E0028048 AFA20020 */  sw        $v0, 0x20($sp)
/* 33CE3C E002804C 24020014 */  addiu     $v0, $zero, 0x14
/* 33CE40 E0028050 AFBF0038 */  sw        $ra, 0x38($sp)
/* 33CE44 E0028054 AFB20030 */  sw        $s2, 0x30($sp)
/* 33CE48 E0028058 AFB1002C */  sw        $s1, 0x2c($sp)
/* 33CE4C E002805C AFB00028 */  sw        $s0, 0x28($sp)
/* 33CE50 E0028060 AFA00010 */  sw        $zero, 0x10($sp)
/* 33CE54 E0028064 AFA00024 */  sw        $zero, 0x24($sp)
/* 33CE58 E0028068 0C080124 */  jal       shim_create_effect_instance
/* 33CE5C E002806C AFA20014 */   sw       $v0, 0x14($sp)
/* 33CE60 E0028070 240400F0 */  addiu     $a0, $zero, 0xf0
/* 33CE64 E0028074 24120005 */  addiu     $s2, $zero, 5
/* 33CE68 E0028078 0040802D */  daddu     $s0, $v0, $zero
/* 33CE6C E002807C 0C08012C */  jal       shim_general_heap_malloc
/* 33CE70 E0028080 AE120008 */   sw       $s2, 8($s0)
/* 33CE74 E0028084 0040182D */  daddu     $v1, $v0, $zero
/* 33CE78 E0028088 14600003 */  bnez      $v1, .LE0028098
/* 33CE7C E002808C AE03000C */   sw       $v1, 0xc($s0)
.LE0028090:
/* 33CE80 E0028090 0800A024 */  j         .LE0028090
/* 33CE84 E0028094 00000000 */   nop
.LE0028098:
/* 33CE88 E0028098 AC730000 */  sw        $s3, ($v1)
/* 33CE8C E002809C E4740004 */  swc1      $f20, 4($v1)
/* 33CE90 E00280A0 E4760008 */  swc1      $f22, 8($v1)
/* 33CE94 E00280A4 E478000C */  swc1      $f24, 0xc($v1)
/* 33CE98 E00280A8 8FA20068 */  lw        $v0, 0x68($sp)
/* 33CE9C E00280AC 24110001 */  addiu     $s1, $zero, 1
/* 33CEA0 E00280B0 AC60002C */  sw        $zero, 0x2c($v1)
/* 33CEA4 E00280B4 AC600024 */  sw        $zero, 0x24($v1)
/* 33CEA8 E00280B8 AC620028 */  sw        $v0, 0x28($v1)
/* 33CEAC E00280BC 0232102A */  slt       $v0, $s1, $s2
/* 33CEB0 E00280C0 10400055 */  beqz      $v0, .LE0028218
/* 33CEB4 E00280C4 24630030 */   addiu    $v1, $v1, 0x30
/* 33CEB8 E00280C8 3C014120 */  lui       $at, 0x4120
/* 33CEBC E00280CC 4481A000 */  mtc1      $at, $f20
/* 33CEC0 E00280D0 24700014 */  addiu     $s0, $v1, 0x14
.LE00280D4:
/* 33CEC4 E00280D4 16600026 */  bnez      $s3, .LE0028170
/* 33CEC8 E00280D8 00000000 */   nop
/* 33CECC E00280DC 0C080000 */  jal       func_E0200000
/* 33CED0 E00280E0 24040032 */   addiu    $a0, $zero, 0x32
/* 33CED4 E00280E4 24040032 */  addiu     $a0, $zero, 0x32
/* 33CED8 E00280E8 2442FFE7 */  addiu     $v0, $v0, -0x19
/* 33CEDC E00280EC 44820000 */  mtc1      $v0, $f0
/* 33CEE0 E00280F0 00000000 */  nop
/* 33CEE4 E00280F4 46800020 */  cvt.s.w   $f0, $f0
/* 33CEE8 E00280F8 0C080000 */  jal       func_E0200000
/* 33CEEC E00280FC E600FFF0 */   swc1     $f0, -0x10($s0)
/* 33CEF0 E0028100 24040168 */  addiu     $a0, $zero, 0x168
/* 33CEF4 E0028104 2442FFE7 */  addiu     $v0, $v0, -0x19
/* 33CEF8 E0028108 44820000 */  mtc1      $v0, $f0
/* 33CEFC E002810C 00000000 */  nop
/* 33CF00 E0028110 46800020 */  cvt.s.w   $f0, $f0
/* 33CF04 E0028114 E600FFF4 */  swc1      $f0, -0xc($s0)
/* 33CF08 E0028118 0C080000 */  jal       func_E0200000
/* 33CF0C E002811C AE00FFF8 */   sw       $zero, -8($s0)
/* 33CF10 E0028120 24040168 */  addiu     $a0, $zero, 0x168
/* 33CF14 E0028124 44820000 */  mtc1      $v0, $f0
/* 33CF18 E0028128 00000000 */  nop
/* 33CF1C E002812C 46800020 */  cvt.s.w   $f0, $f0
/* 33CF20 E0028130 0C080000 */  jal       func_E0200000
/* 33CF24 E0028134 E6000004 */   swc1     $f0, 4($s0)
/* 33CF28 E0028138 24040064 */  addiu     $a0, $zero, 0x64
/* 33CF2C E002813C 44820000 */  mtc1      $v0, $f0
/* 33CF30 E0028140 00000000 */  nop
/* 33CF34 E0028144 46800020 */  cvt.s.w   $f0, $f0
/* 33CF38 E0028148 0C080000 */  jal       func_E0200000
/* 33CF3C E002814C E600000C */   swc1     $f0, 0xc($s0)
/* 33CF40 E0028150 44820000 */  mtc1      $v0, $f0
/* 33CF44 E0028154 00000000 */  nop
/* 33CF48 E0028158 46800020 */  cvt.s.w   $f0, $f0
/* 33CF4C E002815C 46140003 */  div.s     $f0, $f0, $f20
/* 33CF50 E0028160 E6000008 */  swc1      $f0, 8($s0)
/* 33CF54 E0028164 AE00FFFC */  sw        $zero, -4($s0)
/* 33CF58 E0028168 0800A082 */  j         .LE0028208
/* 33CF5C E002816C AE000000 */   sw       $zero, ($s0)
.LE0028170:
/* 33CF60 E0028170 0C080000 */  jal       func_E0200000
/* 33CF64 E0028174 2404000A */   addiu    $a0, $zero, 0xa
/* 33CF68 E0028178 2404000A */  addiu     $a0, $zero, 0xa
/* 33CF6C E002817C 2442FFFB */  addiu     $v0, $v0, -5
/* 33CF70 E0028180 44820000 */  mtc1      $v0, $f0
/* 33CF74 E0028184 00000000 */  nop
/* 33CF78 E0028188 46800020 */  cvt.s.w   $f0, $f0
/* 33CF7C E002818C 0C080000 */  jal       func_E0200000
/* 33CF80 E0028190 E600FFF0 */   swc1     $f0, -0x10($s0)
/* 33CF84 E0028194 24040168 */  addiu     $a0, $zero, 0x168
/* 33CF88 E0028198 24420005 */  addiu     $v0, $v0, 5
/* 33CF8C E002819C 44820000 */  mtc1      $v0, $f0
/* 33CF90 E00281A0 00000000 */  nop
/* 33CF94 E00281A4 46800020 */  cvt.s.w   $f0, $f0
/* 33CF98 E00281A8 E600FFF4 */  swc1      $f0, -0xc($s0)
/* 33CF9C E00281AC 0C080000 */  jal       func_E0200000
/* 33CFA0 E00281B0 E614FFF8 */   swc1     $f20, -8($s0)
/* 33CFA4 E00281B4 24040168 */  addiu     $a0, $zero, 0x168
/* 33CFA8 E00281B8 44820000 */  mtc1      $v0, $f0
/* 33CFAC E00281BC 00000000 */  nop
/* 33CFB0 E00281C0 46800020 */  cvt.s.w   $f0, $f0
/* 33CFB4 E00281C4 0C080000 */  jal       func_E0200000
/* 33CFB8 E00281C8 E6000004 */   swc1     $f0, 4($s0)
/* 33CFBC E00281CC 24040064 */  addiu     $a0, $zero, 0x64
/* 33CFC0 E00281D0 44820000 */  mtc1      $v0, $f0
/* 33CFC4 E00281D4 00000000 */  nop
/* 33CFC8 E00281D8 46800020 */  cvt.s.w   $f0, $f0
/* 33CFCC E00281DC 0C080000 */  jal       func_E0200000
/* 33CFD0 E00281E0 E600000C */   swc1     $f0, 0xc($s0)
/* 33CFD4 E00281E4 44820000 */  mtc1      $v0, $f0
/* 33CFD8 E00281E8 00000000 */  nop
/* 33CFDC E00281EC 46800020 */  cvt.s.w   $f0, $f0
/* 33CFE0 E00281F0 3C014000 */  lui       $at, 0x4000
/* 33CFE4 E00281F4 44811000 */  mtc1      $at, $f2
/* 33CFE8 E00281F8 46140003 */  div.s     $f0, $f0, $f20
/* 33CFEC E00281FC E6000008 */  swc1      $f0, 8($s0)
/* 33CFF0 E0028200 AE00FFFC */  sw        $zero, -4($s0)
/* 33CFF4 E0028204 E6020000 */  swc1      $f2, ($s0)
.LE0028208:
/* 33CFF8 E0028208 26310001 */  addiu     $s1, $s1, 1
/* 33CFFC E002820C 0232102A */  slt       $v0, $s1, $s2
/* 33D000 E0028210 1440FFB0 */  bnez      $v0, .LE00280D4
/* 33D004 E0028214 26100030 */   addiu    $s0, $s0, 0x30
.LE0028218:
/* 33D008 E0028218 8FBF0038 */  lw        $ra, 0x38($sp)
/* 33D00C E002821C 8FB30034 */  lw        $s3, 0x34($sp)
/* 33D010 E0028220 8FB20030 */  lw        $s2, 0x30($sp)
/* 33D014 E0028224 8FB1002C */  lw        $s1, 0x2c($sp)
/* 33D018 E0028228 8FB00028 */  lw        $s0, 0x28($sp)
/* 33D01C E002822C D7B80050 */  ldc1      $f24, 0x50($sp)
/* 33D020 E0028230 D7B60048 */  ldc1      $f22, 0x48($sp)
/* 33D024 E0028234 D7B40040 */  ldc1      $f20, 0x40($sp)
/* 33D028 E0028238 03E00008 */  jr        $ra
/* 33D02C E002823C 27BD0058 */   addiu    $sp, $sp, 0x58

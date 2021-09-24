.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_8_main
/* 32C988 E00101E8 27BDFF80 */  addiu     $sp, $sp, -0x80
/* 32C98C E00101EC F7BA0068 */  sdc1      $f26, 0x68($sp)
/* 32C990 E00101F0 46006686 */  mov.s     $f26, $f12
/* 32C994 E00101F4 F7BC0070 */  sdc1      $f28, 0x70($sp)
/* 32C998 E00101F8 46007706 */  mov.s     $f28, $f14
/* 32C99C E00101FC 27A40010 */  addiu     $a0, $sp, 0x10
/* 32C9A0 E0010200 F7BE0078 */  sdc1      $f30, 0x78($sp)
/* 32C9A4 E0010204 4486F000 */  mtc1      $a2, $f30
/* 32C9A8 E0010208 3C02E001 */  lui       $v0, %hi(func_E00103EC)
/* 32C9AC E001020C 244203EC */  addiu     $v0, $v0, %lo(func_E00103EC)
/* 32C9B0 E0010210 AFA20018 */  sw        $v0, 0x18($sp)
/* 32C9B4 E0010214 3C02E001 */  lui       $v0, %hi(func_E00103F4)
/* 32C9B8 E0010218 244203F4 */  addiu     $v0, $v0, %lo(func_E00103F4)
/* 32C9BC E001021C AFA2001C */  sw        $v0, 0x1c($sp)
/* 32C9C0 E0010220 3C02E001 */  lui       $v0, %hi(func_E00104B0)
/* 32C9C4 E0010224 244204B0 */  addiu     $v0, $v0, %lo(func_E00104B0)
/* 32C9C8 E0010228 AFA20020 */  sw        $v0, 0x20($sp)
/* 32C9CC E001022C 24020008 */  addiu     $v0, $zero, 8
/* 32C9D0 E0010230 AFBF0048 */  sw        $ra, 0x48($sp)
/* 32C9D4 E0010234 AFB70044 */  sw        $s7, 0x44($sp)
/* 32C9D8 E0010238 AFB60040 */  sw        $s6, 0x40($sp)
/* 32C9DC E001023C AFB5003C */  sw        $s5, 0x3c($sp)
/* 32C9E0 E0010240 AFB40038 */  sw        $s4, 0x38($sp)
/* 32C9E4 E0010244 AFB30034 */  sw        $s3, 0x34($sp)
/* 32C9E8 E0010248 AFB20030 */  sw        $s2, 0x30($sp)
/* 32C9EC E001024C AFB1002C */  sw        $s1, 0x2c($sp)
/* 32C9F0 E0010250 AFB00028 */  sw        $s0, 0x28($sp)
/* 32C9F4 E0010254 F7B80060 */  sdc1      $f24, 0x60($sp)
/* 32C9F8 E0010258 F7B60058 */  sdc1      $f22, 0x58($sp)
/* 32C9FC E001025C F7B40050 */  sdc1      $f20, 0x50($sp)
/* 32CA00 E0010260 AFA7008C */  sw        $a3, 0x8c($sp)
/* 32CA04 E0010264 AFA00010 */  sw        $zero, 0x10($sp)
/* 32CA08 E0010268 AFA00024 */  sw        $zero, 0x24($sp)
/* 32CA0C E001026C 0C080124 */  jal       shim_create_effect_instance
/* 32CA10 E0010270 AFA20014 */   sw       $v0, 0x14($sp)
/* 32CA14 E0010274 240402F8 */  addiu     $a0, $zero, 0x2f8
/* 32CA18 E0010278 24140005 */  addiu     $s4, $zero, 5
/* 32CA1C E001027C 0040802D */  daddu     $s0, $v0, $zero
/* 32CA20 E0010280 0C08012C */  jal       shim_general_heap_malloc
/* 32CA24 E0010284 AE140008 */   sw       $s4, 8($s0)
/* 32CA28 E0010288 0040882D */  daddu     $s1, $v0, $zero
/* 32CA2C E001028C 16200003 */  bnez      $s1, .LE001029C
/* 32CA30 E0010290 AE11000C */   sw       $s1, 0xc($s0)
.LE0010294:
/* 32CA34 E0010294 080040A5 */  j         .LE0010294
/* 32CA38 E0010298 00000000 */   nop
.LE001029C:
/* 32CA3C E001029C 0220202D */  daddu     $a0, $s1, $zero
/* 32CA40 E00102A0 00142880 */  sll       $a1, $s4, 2
/* 32CA44 E00102A4 00B42821 */  addu      $a1, $a1, $s4
/* 32CA48 E00102A8 00052880 */  sll       $a1, $a1, 2
/* 32CA4C E00102AC 00B42823 */  subu      $a1, $a1, $s4
/* 32CA50 E00102B0 0C080130 */  jal       shim_mem_clear
/* 32CA54 E00102B4 000528C0 */   sll      $a1, $a1, 3
/* 32CA58 E00102B8 1280003B */  beqz      $s4, .LE00103A8
/* 32CA5C E00102BC 0000902D */   daddu    $s2, $zero, $zero
/* 32CA60 E00102C0 24170001 */  addiu     $s7, $zero, 1
/* 32CA64 E00102C4 241600FF */  addiu     $s6, $zero, 0xff
/* 32CA68 E00102C8 2415003C */  addiu     $s5, $zero, 0x3c
/* 32CA6C E00102CC 26300094 */  addiu     $s0, $s1, 0x94
/* 32CA70 E00102D0 0240982D */  daddu     $s3, $s2, $zero
/* 32CA74 E00102D4 3C013E99 */  lui       $at, 0x3e99
/* 32CA78 E00102D8 34219999 */  ori       $at, $at, 0x9999
/* 32CA7C E00102DC 4481C000 */  mtc1      $at, $f24
/* 32CA80 E00102E0 3C013F80 */  lui       $at, 0x3f80
/* 32CA84 E00102E4 4481B000 */  mtc1      $at, $f22
.LE00102E8:
/* 32CA88 E00102E8 44930000 */  mtc1      $s3, $f0
/* 32CA8C E00102EC 00000000 */  nop
/* 32CA90 E00102F0 46800020 */  cvt.s.w   $f0, $f0
/* 32CA94 E00102F4 26730048 */  addiu     $s3, $s3, 0x48
/* 32CA98 E00102F8 C7A6008C */  lwc1      $f6, 0x8c($sp)
/* 32CA9C E00102FC 3C01BDA3 */  lui       $at, 0xbda3
/* 32CAA0 E0010300 3421D70A */  ori       $at, $at, 0xd70a
/* 32CAA4 E0010304 44811000 */  mtc1      $at, $f2
/* 32CAA8 E0010308 3C01C079 */  lui       $at, 0xc079
/* 32CAAC E001030C 3421999A */  ori       $at, $at, 0x999a
/* 32CAB0 E0010310 44812000 */  mtc1      $at, $f4
/* 32CAB4 E0010314 46003000 */  add.s     $f0, $f6, $f0
/* 32CAB8 E0010318 26520001 */  addiu     $s2, $s2, 1
/* 32CABC E001031C AE370000 */  sw        $s7, ($s1)
/* 32CAC0 E0010320 E600FF94 */  swc1      $f0, -0x6c($s0)
/* 32CAC4 E0010324 46000306 */  mov.s     $f12, $f0
/* 32CAC8 E0010328 3C013FE0 */  lui       $at, 0x3fe0
/* 32CACC E001032C 44810000 */  mtc1      $at, $f0
/* 32CAD0 E0010330 26310098 */  addiu     $s1, $s1, 0x98
/* 32CAD4 E0010334 E618FFE0 */  swc1      $f24, -0x20($s0)
/* 32CAD8 E0010338 AE00FFE4 */  sw        $zero, -0x1c($s0)
/* 32CADC E001033C AE00FFE8 */  sw        $zero, -0x18($s0)
/* 32CAE0 E0010340 E61AFF78 */  swc1      $f26, -0x88($s0)
/* 32CAE4 E0010344 E61CFF7C */  swc1      $f28, -0x84($s0)
/* 32CAE8 E0010348 E61EFF80 */  swc1      $f30, -0x80($s0)
/* 32CAEC E001034C E616FF84 */  swc1      $f22, -0x7c($s0)
/* 32CAF0 E0010350 E616FF88 */  swc1      $f22, -0x78($s0)
/* 32CAF4 E0010354 E616FF8C */  swc1      $f22, -0x74($s0)
/* 32CAF8 E0010358 A216FF74 */  sb        $s6, -0x8c($s0)
/* 32CAFC E001035C A615FF72 */  sh        $s5, -0x8e($s0)
/* 32CB00 E0010360 AE00FF90 */  sw        $zero, -0x70($s0)
/* 32CB04 E0010364 AE00FF98 */  sw        $zero, -0x68($s0)
/* 32CB08 E0010368 AE00FFF4 */  sw        $zero, -0xc($s0)
/* 32CB0C E001036C AE00FFF8 */  sw        $zero, -8($s0)
/* 32CB10 E0010370 E602FFF0 */  swc1      $f2, -0x10($s0)
/* 32CB14 E0010374 E604FFDC */  swc1      $f4, -0x24($s0)
/* 32CB18 E0010378 0C08013C */  jal       shim_clamp_angle
/* 32CB1C E001037C E600FFEC */   swc1     $f0, -0x14($s0)
/* 32CB20 E0010380 46000506 */  mov.s     $f20, $f0
/* 32CB24 E0010384 0C080140 */  jal       shim_sin_deg
/* 32CB28 E0010388 4600A306 */   mov.s    $f12, $f20
/* 32CB2C E001038C 4600A306 */  mov.s     $f12, $f20
/* 32CB30 E0010390 0C080144 */  jal       shim_cos_deg
/* 32CB34 E0010394 E600FFFC */   swc1     $f0, -4($s0)
/* 32CB38 E0010398 E6000000 */  swc1      $f0, ($s0)
/* 32CB3C E001039C 0254102A */  slt       $v0, $s2, $s4
/* 32CB40 E00103A0 1440FFD1 */  bnez      $v0, .LE00102E8
/* 32CB44 E00103A4 26100098 */   addiu    $s0, $s0, 0x98
.LE00103A8:
/* 32CB48 E00103A8 8FBF0048 */  lw        $ra, 0x48($sp)
/* 32CB4C E00103AC 8FB70044 */  lw        $s7, 0x44($sp)
/* 32CB50 E00103B0 8FB60040 */  lw        $s6, 0x40($sp)
/* 32CB54 E00103B4 8FB5003C */  lw        $s5, 0x3c($sp)
/* 32CB58 E00103B8 8FB40038 */  lw        $s4, 0x38($sp)
/* 32CB5C E00103BC 8FB30034 */  lw        $s3, 0x34($sp)
/* 32CB60 E00103C0 8FB20030 */  lw        $s2, 0x30($sp)
/* 32CB64 E00103C4 8FB1002C */  lw        $s1, 0x2c($sp)
/* 32CB68 E00103C8 8FB00028 */  lw        $s0, 0x28($sp)
/* 32CB6C E00103CC D7BE0078 */  ldc1      $f30, 0x78($sp)
/* 32CB70 E00103D0 D7BC0070 */  ldc1      $f28, 0x70($sp)
/* 32CB74 E00103D4 D7BA0068 */  ldc1      $f26, 0x68($sp)
/* 32CB78 E00103D8 D7B80060 */  ldc1      $f24, 0x60($sp)
/* 32CB7C E00103DC D7B60058 */  ldc1      $f22, 0x58($sp)
/* 32CB80 E00103E0 D7B40050 */  ldc1      $f20, 0x50($sp)
/* 32CB84 E00103E4 03E00008 */  jr        $ra
/* 32CB88 E00103E8 27BD0080 */   addiu    $sp, $sp, 0x80

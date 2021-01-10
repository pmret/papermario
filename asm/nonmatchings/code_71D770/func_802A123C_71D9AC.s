.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A123C_71D9AC
/* 71D9AC 802A123C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 71D9B0 802A1240 AFB00020 */  sw        $s0, 0x20($sp)
/* 71D9B4 802A1244 0080802D */  daddu     $s0, $a0, $zero
/* 71D9B8 802A1248 AFBF002C */  sw        $ra, 0x2c($sp)
/* 71D9BC 802A124C AFB20028 */  sw        $s2, 0x28($sp)
/* 71D9C0 802A1250 AFB10024 */  sw        $s1, 0x24($sp)
/* 71D9C4 802A1254 F7B60038 */  sdc1      $f22, 0x38($sp)
/* 71D9C8 802A1258 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 71D9CC 802A125C 0C00A67F */  jal       rand_int
/* 71D9D0 802A1260 240400C8 */   addiu    $a0, $zero, 0xc8
/* 71D9D4 802A1264 24040028 */  addiu     $a0, $zero, 0x28
/* 71D9D8 802A1268 0C00A67F */  jal       rand_int
/* 71D9DC 802A126C 24510064 */   addiu    $s1, $v0, 0x64
/* 71D9E0 802A1270 241200C8 */  addiu     $s2, $zero, 0xc8
/* 71D9E4 802A1274 8E030084 */  lw        $v1, 0x84($s0)
/* 71D9E8 802A1278 30630003 */  andi      $v1, $v1, 3
/* 71D9EC 802A127C 10600013 */  beqz      $v1, .L802A12CC
/* 71D9F0 802A1280 0040802D */   daddu    $s0, $v0, $zero
/* 71D9F4 802A1284 0C00A67F */  jal       rand_int
/* 71D9F8 802A1288 24040064 */   addiu    $a0, $zero, 0x64
/* 71D9FC 802A128C 00521021 */  addu      $v0, $v0, $s2
/* 71DA00 802A1290 02221023 */  subu      $v0, $s1, $v0
/* 71DA04 802A1294 4482B000 */  mtc1      $v0, $f22
/* 71DA08 802A1298 00000000 */  nop       
/* 71DA0C 802A129C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 71DA10 802A12A0 0C00A67F */  jal       rand_int
/* 71DA14 802A12A4 24040064 */   addiu    $a0, $zero, 0x64
/* 71DA18 802A12A8 2442FFCE */  addiu     $v0, $v0, -0x32
/* 71DA1C 802A12AC 02021023 */  subu      $v0, $s0, $v0
/* 71DA20 802A12B0 4482A000 */  mtc1      $v0, $f20
/* 71DA24 802A12B4 00000000 */  nop       
/* 71DA28 802A12B8 4680A520 */  cvt.s.w   $f20, $f20
/* 71DA2C 802A12BC 0C00A67F */  jal       rand_int
/* 71DA30 802A12C0 2404000A */   addiu    $a0, $zero, 0xa
/* 71DA34 802A12C4 080A84C4 */  j         .L802A1310
/* 71DA38 802A12C8 24040002 */   addiu    $a0, $zero, 2
.L802A12CC:
/* 71DA3C 802A12CC 0C00A67F */  jal       rand_int
/* 71DA40 802A12D0 24040064 */   addiu    $a0, $zero, 0x64
/* 71DA44 802A12D4 244200C8 */  addiu     $v0, $v0, 0xc8
/* 71DA48 802A12D8 02221023 */  subu      $v0, $s1, $v0
/* 71DA4C 802A12DC 4482B000 */  mtc1      $v0, $f22
/* 71DA50 802A12E0 00000000 */  nop       
/* 71DA54 802A12E4 4680B5A0 */  cvt.s.w   $f22, $f22
/* 71DA58 802A12E8 0C00A67F */  jal       rand_int
/* 71DA5C 802A12EC 24040064 */   addiu    $a0, $zero, 0x64
/* 71DA60 802A12F0 2442FFCE */  addiu     $v0, $v0, -0x32
/* 71DA64 802A12F4 02021023 */  subu      $v0, $s0, $v0
/* 71DA68 802A12F8 4482A000 */  mtc1      $v0, $f20
/* 71DA6C 802A12FC 00000000 */  nop       
/* 71DA70 802A1300 4680A520 */  cvt.s.w   $f20, $f20
/* 71DA74 802A1304 0C00A67F */  jal       rand_int
/* 71DA78 802A1308 2404000A */   addiu    $a0, $zero, 0xa
/* 71DA7C 802A130C 24040003 */  addiu     $a0, $zero, 3
.L802A1310:
/* 71DA80 802A1310 44911000 */  mtc1      $s1, $f2
/* 71DA84 802A1314 00000000 */  nop       
/* 71DA88 802A1318 468010A0 */  cvt.s.w   $f2, $f2
/* 71DA8C 802A131C 44051000 */  mfc1      $a1, $f2
/* 71DA90 802A1320 44921000 */  mtc1      $s2, $f2
/* 71DA94 802A1324 00000000 */  nop       
/* 71DA98 802A1328 468010A0 */  cvt.s.w   $f2, $f2
/* 71DA9C 802A132C 44061000 */  mfc1      $a2, $f2
/* 71DAA0 802A1330 44901000 */  mtc1      $s0, $f2
/* 71DAA4 802A1334 00000000 */  nop       
/* 71DAA8 802A1338 468010A0 */  cvt.s.w   $f2, $f2
/* 71DAAC 802A133C 24420007 */  addiu     $v0, $v0, 7
/* 71DAB0 802A1340 44071000 */  mfc1      $a3, $f2
/* 71DAB4 802A1344 44820000 */  mtc1      $v0, $f0
/* 71DAB8 802A1348 00000000 */  nop       
/* 71DABC 802A134C 46800020 */  cvt.s.w   $f0, $f0
/* 71DAC0 802A1350 E7B60010 */  swc1      $f22, 0x10($sp)
/* 71DAC4 802A1354 AFA00014 */  sw        $zero, 0x14($sp)
/* 71DAC8 802A1358 E7B40018 */  swc1      $f20, 0x18($sp)
/* 71DACC 802A135C 0C01BF8C */  jal       func_8006FE30
/* 71DAD0 802A1360 E7A0001C */   swc1     $f0, 0x1c($sp)
/* 71DAD4 802A1364 8FBF002C */  lw        $ra, 0x2c($sp)
/* 71DAD8 802A1368 8FB20028 */  lw        $s2, 0x28($sp)
/* 71DADC 802A136C 8FB10024 */  lw        $s1, 0x24($sp)
/* 71DAE0 802A1370 8FB00020 */  lw        $s0, 0x20($sp)
/* 71DAE4 802A1374 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 71DAE8 802A1378 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 71DAEC 802A137C 24020002 */  addiu     $v0, $zero, 2
/* 71DAF0 802A1380 03E00008 */  jr        $ra
/* 71DAF4 802A1384 27BD0040 */   addiu    $sp, $sp, 0x40

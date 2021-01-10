.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1228_75CBA8
/* 75CBA8 802A1228 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 75CBAC 802A122C AFB20020 */  sw        $s2, 0x20($sp)
/* 75CBB0 802A1230 0080902D */  daddu     $s2, $a0, $zero
/* 75CBB4 802A1234 AFBF0028 */  sw        $ra, 0x28($sp)
/* 75CBB8 802A1238 AFB30024 */  sw        $s3, 0x24($sp)
/* 75CBBC 802A123C AFB1001C */  sw        $s1, 0x1c($sp)
/* 75CBC0 802A1240 AFB00018 */  sw        $s0, 0x18($sp)
/* 75CBC4 802A1244 F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 75CBC8 802A1248 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 75CBCC 802A124C F7B60038 */  sdc1      $f22, 0x38($sp)
/* 75CBD0 802A1250 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 75CBD4 802A1254 8E50000C */  lw        $s0, 0xc($s2)
/* 75CBD8 802A1258 8E050000 */  lw        $a1, ($s0)
/* 75CBDC 802A125C 0C0B1EAF */  jal       get_variable
/* 75CBE0 802A1260 26100004 */   addiu    $s0, $s0, 4
/* 75CBE4 802A1264 8E050000 */  lw        $a1, ($s0)
/* 75CBE8 802A1268 26100004 */  addiu     $s0, $s0, 4
/* 75CBEC 802A126C 0240202D */  daddu     $a0, $s2, $zero
/* 75CBF0 802A1270 0C0B1EAF */  jal       get_variable
/* 75CBF4 802A1274 0040982D */   daddu    $s3, $v0, $zero
/* 75CBF8 802A1278 8E050000 */  lw        $a1, ($s0)
/* 75CBFC 802A127C 26100004 */  addiu     $s0, $s0, 4
/* 75CC00 802A1280 0240202D */  daddu     $a0, $s2, $zero
/* 75CC04 802A1284 0C0B1EAF */  jal       get_variable
/* 75CC08 802A1288 0040882D */   daddu    $s1, $v0, $zero
/* 75CC0C 802A128C 0240202D */  daddu     $a0, $s2, $zero
/* 75CC10 802A1290 8E050000 */  lw        $a1, ($s0)
/* 75CC14 802A1294 0C0B210B */  jal       get_float_variable
/* 75CC18 802A1298 0040802D */   daddu    $s0, $v0, $zero
/* 75CC1C 802A129C 24040006 */  addiu     $a0, $zero, 6
/* 75CC20 802A12A0 2673000A */  addiu     $s3, $s3, 0xa
/* 75CC24 802A12A4 4493D000 */  mtc1      $s3, $f26
/* 75CC28 802A12A8 00000000 */  nop       
/* 75CC2C 802A12AC 4680D6A0 */  cvt.s.w   $f26, $f26
/* 75CC30 802A12B0 26310012 */  addiu     $s1, $s1, 0x12
/* 75CC34 802A12B4 4491C000 */  mtc1      $s1, $f24
/* 75CC38 802A12B8 00000000 */  nop       
/* 75CC3C 802A12BC 4680C620 */  cvt.s.w   $f24, $f24
/* 75CC40 802A12C0 4490A000 */  mtc1      $s0, $f20
/* 75CC44 802A12C4 00000000 */  nop       
/* 75CC48 802A12C8 4680A520 */  cvt.s.w   $f20, $f20
/* 75CC4C 802A12CC 46000586 */  mov.s     $f22, $f0
/* 75CC50 802A12D0 4405D000 */  mfc1      $a1, $f26
/* 75CC54 802A12D4 4406C000 */  mfc1      $a2, $f24
/* 75CC58 802A12D8 4407A000 */  mfc1      $a3, $f20
/* 75CC5C 802A12DC 2402002D */  addiu     $v0, $zero, 0x2d
/* 75CC60 802A12E0 E7B60010 */  swc1      $f22, 0x10($sp)
/* 75CC64 802A12E4 0C01C82C */  jal       func_800720B0
/* 75CC68 802A12E8 AFA20014 */   sw       $v0, 0x14($sp)
/* 75CC6C 802A12EC 2404000C */  addiu     $a0, $zero, 0xc
/* 75CC70 802A12F0 4405D000 */  mfc1      $a1, $f26
/* 75CC74 802A12F4 4406C000 */  mfc1      $a2, $f24
/* 75CC78 802A12F8 4407A000 */  mfc1      $a3, $f20
/* 75CC7C 802A12FC 2402001E */  addiu     $v0, $zero, 0x1e
/* 75CC80 802A1300 E7B60010 */  swc1      $f22, 0x10($sp)
/* 75CC84 802A1304 0C01C2EC */  jal       func_80070BB0
/* 75CC88 802A1308 AFA20014 */   sw       $v0, 0x14($sp)
/* 75CC8C 802A130C 8FBF0028 */  lw        $ra, 0x28($sp)
/* 75CC90 802A1310 8FB30024 */  lw        $s3, 0x24($sp)
/* 75CC94 802A1314 8FB20020 */  lw        $s2, 0x20($sp)
/* 75CC98 802A1318 8FB1001C */  lw        $s1, 0x1c($sp)
/* 75CC9C 802A131C 8FB00018 */  lw        $s0, 0x18($sp)
/* 75CCA0 802A1320 D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 75CCA4 802A1324 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 75CCA8 802A1328 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 75CCAC 802A132C D7B40030 */  ldc1      $f20, 0x30($sp)
/* 75CCB0 802A1330 24020002 */  addiu     $v0, $zero, 2
/* 75CCB4 802A1334 03E00008 */  jr        $ra
/* 75CCB8 802A1338 27BD0050 */   addiu    $sp, $sp, 0x50

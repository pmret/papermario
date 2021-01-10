.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A12E0_72AA30
/* 72AA30 802A12E0 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 72AA34 802A12E4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 72AA38 802A12E8 0080882D */  daddu     $s1, $a0, $zero
/* 72AA3C 802A12EC AFBF0020 */  sw        $ra, 0x20($sp)
/* 72AA40 802A12F0 AFB00018 */  sw        $s0, 0x18($sp)
/* 72AA44 802A12F4 F7B80038 */  sdc1      $f24, 0x38($sp)
/* 72AA48 802A12F8 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 72AA4C 802A12FC F7B40028 */  sdc1      $f20, 0x28($sp)
/* 72AA50 802A1300 8E30000C */  lw        $s0, 0xc($s1)
/* 72AA54 802A1304 8E050000 */  lw        $a1, ($s0)
/* 72AA58 802A1308 0C0B1EAF */  jal       get_variable
/* 72AA5C 802A130C 26100004 */   addiu    $s0, $s0, 4
/* 72AA60 802A1310 4482A000 */  mtc1      $v0, $f20
/* 72AA64 802A1314 00000000 */  nop       
/* 72AA68 802A1318 4680A520 */  cvt.s.w   $f20, $f20
/* 72AA6C 802A131C 8E050000 */  lw        $a1, ($s0)
/* 72AA70 802A1320 26100004 */  addiu     $s0, $s0, 4
/* 72AA74 802A1324 0C0B1EAF */  jal       get_variable
/* 72AA78 802A1328 0220202D */   daddu    $a0, $s1, $zero
/* 72AA7C 802A132C 4482B000 */  mtc1      $v0, $f22
/* 72AA80 802A1330 00000000 */  nop       
/* 72AA84 802A1334 4680B5A0 */  cvt.s.w   $f22, $f22
/* 72AA88 802A1338 8E050000 */  lw        $a1, ($s0)
/* 72AA8C 802A133C 0C0B1EAF */  jal       get_variable
/* 72AA90 802A1340 0220202D */   daddu    $a0, $s1, $zero
/* 72AA94 802A1344 4482C000 */  mtc1      $v0, $f24
/* 72AA98 802A1348 00000000 */  nop       
/* 72AA9C 802A134C 4680C620 */  cvt.s.w   $f24, $f24
/* 72AAA0 802A1350 0C00A67F */  jal       rand_int
/* 72AAA4 802A1354 24040014 */   addiu    $a0, $zero, 0x14
/* 72AAA8 802A1358 2404000A */  addiu     $a0, $zero, 0xa
/* 72AAAC 802A135C 2442FFF6 */  addiu     $v0, $v0, -0xa
/* 72AAB0 802A1360 44820000 */  mtc1      $v0, $f0
/* 72AAB4 802A1364 00000000 */  nop       
/* 72AAB8 802A1368 46800020 */  cvt.s.w   $f0, $f0
/* 72AABC 802A136C 0C00A67F */  jal       rand_int
/* 72AAC0 802A1370 4600A500 */   add.s    $f20, $f20, $f0
/* 72AAC4 802A1374 0000202D */  daddu     $a0, $zero, $zero
/* 72AAC8 802A1378 2442FFFB */  addiu     $v0, $v0, -5
/* 72AACC 802A137C 44820000 */  mtc1      $v0, $f0
/* 72AAD0 802A1380 00000000 */  nop       
/* 72AAD4 802A1384 46800020 */  cvt.s.w   $f0, $f0
/* 72AAD8 802A1388 4600B580 */  add.s     $f22, $f22, $f0
/* 72AADC 802A138C 3C013F80 */  lui       $at, 0x3f80
/* 72AAE0 802A1390 44811000 */  mtc1      $at, $f2
/* 72AAE4 802A1394 4407C000 */  mfc1      $a3, $f24
/* 72AAE8 802A1398 4405A000 */  mfc1      $a1, $f20
/* 72AAEC 802A139C 4406B000 */  mfc1      $a2, $f22
/* 72AAF0 802A13A0 2402001E */  addiu     $v0, $zero, 0x1e
/* 72AAF4 802A13A4 AFA20014 */  sw        $v0, 0x14($sp)
/* 72AAF8 802A13A8 0C01C88C */  jal       func_80072230
/* 72AAFC 802A13AC E7A20010 */   swc1     $f2, 0x10($sp)
/* 72AB00 802A13B0 0040202D */  daddu     $a0, $v0, $zero
/* 72AB04 802A13B4 8C82000C */  lw        $v0, 0xc($a0)
/* 72AB08 802A13B8 240300F4 */  addiu     $v1, $zero, 0xf4
/* 72AB0C 802A13BC AC430018 */  sw        $v1, 0x18($v0)
/* 72AB10 802A13C0 8C82000C */  lw        $v0, 0xc($a0)
/* 72AB14 802A13C4 AC43001C */  sw        $v1, 0x1c($v0)
/* 72AB18 802A13C8 8C83000C */  lw        $v1, 0xc($a0)
/* 72AB1C 802A13CC 240200DC */  addiu     $v0, $zero, 0xdc
/* 72AB20 802A13D0 AC620020 */  sw        $v0, 0x20($v1)
/* 72AB24 802A13D4 8C82000C */  lw        $v0, 0xc($a0)
/* 72AB28 802A13D8 240500D2 */  addiu     $a1, $zero, 0xd2
/* 72AB2C 802A13DC AC450028 */  sw        $a1, 0x28($v0)
/* 72AB30 802A13E0 8C83000C */  lw        $v1, 0xc($a0)
/* 72AB34 802A13E4 AC65002C */  sw        $a1, 0x2c($v1)
/* 72AB38 802A13E8 8C84000C */  lw        $a0, 0xc($a0)
/* 72AB3C 802A13EC 240300BE */  addiu     $v1, $zero, 0xbe
/* 72AB40 802A13F0 AC830030 */  sw        $v1, 0x30($a0)
/* 72AB44 802A13F4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 72AB48 802A13F8 8FB1001C */  lw        $s1, 0x1c($sp)
/* 72AB4C 802A13FC 8FB00018 */  lw        $s0, 0x18($sp)
/* 72AB50 802A1400 D7B80038 */  ldc1      $f24, 0x38($sp)
/* 72AB54 802A1404 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 72AB58 802A1408 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 72AB5C 802A140C 24020002 */  addiu     $v0, $zero, 2
/* 72AB60 802A1410 03E00008 */  jr        $ra
/* 72AB64 802A1414 27BD0040 */   addiu    $sp, $sp, 0x40
/* 72AB68 802A1418 00000000 */  nop       
/* 72AB6C 802A141C 00000000 */  nop       

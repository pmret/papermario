.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1388_71DAF8
/* 71DAF8 802A1388 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 71DAFC 802A138C AFB10024 */  sw        $s1, 0x24($sp)
/* 71DB00 802A1390 0080882D */  daddu     $s1, $a0, $zero
/* 71DB04 802A1394 AFBF002C */  sw        $ra, 0x2c($sp)
/* 71DB08 802A1398 AFB20028 */  sw        $s2, 0x28($sp)
/* 71DB0C 802A139C AFB00020 */  sw        $s0, 0x20($sp)
/* 71DB10 802A13A0 8E30000C */  lw        $s0, 0xc($s1)
/* 71DB14 802A13A4 8E050000 */  lw        $a1, ($s0)
/* 71DB18 802A13A8 0C0B1EAF */  jal       get_variable
/* 71DB1C 802A13AC 26100004 */   addiu    $s0, $s0, 4
/* 71DB20 802A13B0 8E050000 */  lw        $a1, ($s0)
/* 71DB24 802A13B4 26100004 */  addiu     $s0, $s0, 4
/* 71DB28 802A13B8 0220202D */  daddu     $a0, $s1, $zero
/* 71DB2C 802A13BC 0C0B1EAF */  jal       get_variable
/* 71DB30 802A13C0 0040902D */   daddu    $s2, $v0, $zero
/* 71DB34 802A13C4 0220202D */  daddu     $a0, $s1, $zero
/* 71DB38 802A13C8 8E050000 */  lw        $a1, ($s0)
/* 71DB3C 802A13CC 0C0B1EAF */  jal       get_variable
/* 71DB40 802A13D0 0040802D */   daddu    $s0, $v0, $zero
/* 71DB44 802A13D4 24040002 */  addiu     $a0, $zero, 2
/* 71DB48 802A13D8 44921000 */  mtc1      $s2, $f2
/* 71DB4C 802A13DC 00000000 */  nop
/* 71DB50 802A13E0 468010A0 */  cvt.s.w   $f2, $f2
/* 71DB54 802A13E4 44051000 */  mfc1      $a1, $f2
/* 71DB58 802A13E8 44901000 */  mtc1      $s0, $f2
/* 71DB5C 802A13EC 00000000 */  nop
/* 71DB60 802A13F0 468010A0 */  cvt.s.w   $f2, $f2
/* 71DB64 802A13F4 44061000 */  mfc1      $a2, $f2
/* 71DB68 802A13F8 44821000 */  mtc1      $v0, $f2
/* 71DB6C 802A13FC 00000000 */  nop
/* 71DB70 802A1400 468010A0 */  cvt.s.w   $f2, $f2
/* 71DB74 802A1404 3C01BF80 */  lui       $at, 0xbf80
/* 71DB78 802A1408 44810000 */  mtc1      $at, $f0
/* 71DB7C 802A140C 44071000 */  mfc1      $a3, $f2
/* 71DB80 802A1410 24030005 */  addiu     $v1, $zero, 5
/* 71DB84 802A1414 AFA00010 */  sw        $zero, 0x10($sp)
/* 71DB88 802A1418 AFA00018 */  sw        $zero, 0x18($sp)
/* 71DB8C 802A141C AFA3001C */  sw        $v1, 0x1c($sp)
/* 71DB90 802A1420 0C01C064 */  jal       func_80070190
/* 71DB94 802A1424 E7A00014 */   swc1     $f0, 0x14($sp)
/* 71DB98 802A1428 8FBF002C */  lw        $ra, 0x2c($sp)
/* 71DB9C 802A142C 8FB20028 */  lw        $s2, 0x28($sp)
/* 71DBA0 802A1430 8FB10024 */  lw        $s1, 0x24($sp)
/* 71DBA4 802A1434 8FB00020 */  lw        $s0, 0x20($sp)
/* 71DBA8 802A1438 24020002 */  addiu     $v0, $zero, 2
/* 71DBAC 802A143C 03E00008 */  jr        $ra
/* 71DBB0 802A1440 27BD0030 */   addiu    $sp, $sp, 0x30

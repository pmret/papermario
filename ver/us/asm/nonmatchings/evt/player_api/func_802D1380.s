.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D1380
/* F5D30 802D1380 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* F5D34 802D1384 AFB10014 */  sw        $s1, 0x14($sp)
/* F5D38 802D1388 0080882D */  daddu     $s1, $a0, $zero
/* F5D3C 802D138C AFB20018 */  sw        $s2, 0x18($sp)
/* F5D40 802D1390 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* F5D44 802D1394 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* F5D48 802D1398 AFBF001C */  sw        $ra, 0x1c($sp)
/* F5D4C 802D139C AFB00010 */  sw        $s0, 0x10($sp)
/* F5D50 802D13A0 F7B60028 */  sdc1      $f22, 0x28($sp)
/* F5D54 802D13A4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* F5D58 802D13A8 10A00044 */  beqz      $a1, .L802D14BC
/* F5D5C 802D13AC 8E30000C */   lw       $s0, 0xc($s1)
/* F5D60 802D13B0 8E050000 */  lw        $a1, ($s0)
/* F5D64 802D13B4 0C0B1EAF */  jal       get_variable
/* F5D68 802D13B8 26100004 */   addiu    $s0, $s0, 4
/* F5D6C 802D13BC 8E050000 */  lw        $a1, ($s0)
/* F5D70 802D13C0 26100004 */  addiu     $s0, $s0, 4
/* F5D74 802D13C4 4482B000 */  mtc1      $v0, $f22
/* F5D78 802D13C8 00000000 */  nop
/* F5D7C 802D13CC 4680B5A0 */  cvt.s.w   $f22, $f22
/* F5D80 802D13D0 0C0B1EAF */  jal       get_variable
/* F5D84 802D13D4 0220202D */   daddu    $a0, $s1, $zero
/* F5D88 802D13D8 8E050000 */  lw        $a1, ($s0)
/* F5D8C 802D13DC 4482A000 */  mtc1      $v0, $f20
/* F5D90 802D13E0 00000000 */  nop
/* F5D94 802D13E4 4680A520 */  cvt.s.w   $f20, $f20
/* F5D98 802D13E8 0C0B1EAF */  jal       get_variable
/* F5D9C 802D13EC 0220202D */   daddu    $a0, $s1, $zero
/* F5DA0 802D13F0 3C10802E */  lui       $s0, %hi(playerNpc)
/* F5DA4 802D13F4 26109D20 */  addiu     $s0, $s0, %lo(playerNpc)
/* F5DA8 802D13F8 8E030000 */  lw        $v1, ($s0)
/* F5DAC 802D13FC 4406B000 */  mfc1      $a2, $f22
/* F5DB0 802D1400 4407A000 */  mfc1      $a3, $f20
/* F5DB4 802D1404 A462008E */  sh        $v0, 0x8e($v1)
/* F5DB8 802D1408 C64C0028 */  lwc1      $f12, 0x28($s2)
/* F5DBC 802D140C 0C00A720 */  jal       atan2
/* F5DC0 802D1410 C64E0030 */   lwc1     $f14, 0x30($s2)
/* F5DC4 802D1414 8E020000 */  lw        $v0, ($s0)
/* F5DC8 802D1418 E6400080 */  swc1      $f0, 0x80($s2)
/* F5DCC 802D141C 8442008E */  lh        $v0, 0x8e($v0)
/* F5DD0 802D1420 1040000F */  beqz      $v0, .L802D1460
/* F5DD4 802D1424 00000000 */   nop
/* F5DD8 802D1428 C64C0028 */  lwc1      $f12, 0x28($s2)
/* F5DDC 802D142C C64E0030 */  lwc1      $f14, 0x30($s2)
/* F5DE0 802D1430 4406B000 */  mfc1      $a2, $f22
/* F5DE4 802D1434 4407A000 */  mfc1      $a3, $f20
/* F5DE8 802D1438 0C00A7B5 */  jal       dist2D
/* F5DEC 802D143C 00000000 */   nop
/* F5DF0 802D1440 8E030000 */  lw        $v1, ($s0)
/* F5DF4 802D1444 8462008E */  lh        $v0, 0x8e($v1)
/* F5DF8 802D1448 44821000 */  mtc1      $v0, $f2
/* F5DFC 802D144C 00000000 */  nop
/* F5E00 802D1450 468010A0 */  cvt.s.w   $f2, $f2
/* F5E04 802D1454 46020003 */  div.s     $f0, $f0, $f2
/* F5E08 802D1458 080B4529 */  j         .L802D14A4
/* F5E0C 802D145C E4600018 */   swc1     $f0, 0x18($v1)
.L802D1460:
/* F5E10 802D1460 C64C0028 */  lwc1      $f12, 0x28($s2)
/* F5E14 802D1464 C64E0030 */  lwc1      $f14, 0x30($s2)
/* F5E18 802D1468 4406B000 */  mfc1      $a2, $f22
/* F5E1C 802D146C 4407A000 */  mfc1      $a3, $f20
/* F5E20 802D1470 0C00A7B5 */  jal       dist2D
/* F5E24 802D1474 00000000 */   nop
/* F5E28 802D1478 8E030000 */  lw        $v1, ($s0)
/* F5E2C 802D147C C4620018 */  lwc1      $f2, 0x18($v1)
/* F5E30 802D1480 46020003 */  div.s     $f0, $f0, $f2
/* F5E34 802D1484 4600010D */  trunc.w.s $f4, $f0
/* F5E38 802D1488 44022000 */  mfc1      $v0, $f4
/* F5E3C 802D148C 00000000 */  nop
/* F5E40 802D1490 A462008E */  sh        $v0, 0x8e($v1)
/* F5E44 802D1494 00021400 */  sll       $v0, $v0, 0x10
/* F5E48 802D1498 14400002 */  bnez      $v0, .L802D14A4
/* F5E4C 802D149C 24020001 */   addiu    $v0, $zero, 1
/* F5E50 802D14A0 A462008E */  sh        $v0, 0x8e($v1)
.L802D14A4:
/* F5E54 802D14A4 3C02802E */  lui       $v0, %hi(playerNpc)
/* F5E58 802D14A8 8C429D20 */  lw        $v0, %lo(playerNpc)($v0)
/* F5E5C 802D14AC 8E450080 */  lw        $a1, 0x80($s2)
/* F5E60 802D14B0 8444008E */  lh        $a0, 0x8e($v0)
/* F5E64 802D14B4 0C0389DE */  jal       move_player
/* F5E68 802D14B8 8C460018 */   lw       $a2, 0x18($v0)
.L802D14BC:
/* F5E6C 802D14BC 8FBF001C */  lw        $ra, 0x1c($sp)
/* F5E70 802D14C0 8FB20018 */  lw        $s2, 0x18($sp)
/* F5E74 802D14C4 8FB10014 */  lw        $s1, 0x14($sp)
/* F5E78 802D14C8 8FB00010 */  lw        $s0, 0x10($sp)
/* F5E7C 802D14CC D7B60028 */  ldc1      $f22, 0x28($sp)
/* F5E80 802D14D0 D7B40020 */  ldc1      $f20, 0x20($sp)
/* F5E84 802D14D4 24020001 */  addiu     $v0, $zero, 1
/* F5E88 802D14D8 03E00008 */  jr        $ra
/* F5E8C 802D14DC 27BD0030 */   addiu    $sp, $sp, 0x30

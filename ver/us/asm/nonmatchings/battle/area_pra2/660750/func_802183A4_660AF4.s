.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802183A4_660AF4
/* 660AF4 802183A4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 660AF8 802183A8 AFB10014 */  sw        $s1, 0x14($sp)
/* 660AFC 802183AC 0080882D */  daddu     $s1, $a0, $zero
/* 660B00 802183B0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 660B04 802183B4 AFB20018 */  sw        $s2, 0x18($sp)
/* 660B08 802183B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 660B0C 802183BC F7B80030 */  sdc1      $f24, 0x30($sp)
/* 660B10 802183C0 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 660B14 802183C4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 660B18 802183C8 8E30000C */  lw        $s0, 0xc($s1)
/* 660B1C 802183CC 8E120000 */  lw        $s2, ($s0)
/* 660B20 802183D0 26100004 */  addiu     $s0, $s0, 4
/* 660B24 802183D4 8E050000 */  lw        $a1, ($s0)
/* 660B28 802183D8 0C0B1EAF */  jal       evt_get_variable
/* 660B2C 802183DC 26100004 */   addiu    $s0, $s0, 4
/* 660B30 802183E0 8E050000 */  lw        $a1, ($s0)
/* 660B34 802183E4 26100004 */  addiu     $s0, $s0, 4
/* 660B38 802183E8 4482C000 */  mtc1      $v0, $f24
/* 660B3C 802183EC 00000000 */  nop
/* 660B40 802183F0 4680C620 */  cvt.s.w   $f24, $f24
/* 660B44 802183F4 0C0B1EAF */  jal       evt_get_variable
/* 660B48 802183F8 0220202D */   daddu    $a0, $s1, $zero
/* 660B4C 802183FC 8E050000 */  lw        $a1, ($s0)
/* 660B50 80218400 26100004 */  addiu     $s0, $s0, 4
/* 660B54 80218404 4482B000 */  mtc1      $v0, $f22
/* 660B58 80218408 00000000 */  nop
/* 660B5C 8021840C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 660B60 80218410 0C0B1EAF */  jal       evt_get_variable
/* 660B64 80218414 0220202D */   daddu    $a0, $s1, $zero
/* 660B68 80218418 8E050000 */  lw        $a1, ($s0)
/* 660B6C 8021841C 4482A000 */  mtc1      $v0, $f20
/* 660B70 80218420 00000000 */  nop
/* 660B74 80218424 4680A520 */  cvt.s.w   $f20, $f20
/* 660B78 80218428 0C0B1EAF */  jal       evt_get_variable
/* 660B7C 8021842C 0220202D */   daddu    $a0, $s1, $zero
/* 660B80 80218430 4600C306 */  mov.s     $f12, $f24
/* 660B84 80218434 44821000 */  mtc1      $v0, $f2
/* 660B88 80218438 00000000 */  nop
/* 660B8C 8021843C 468010A0 */  cvt.s.w   $f2, $f2
/* 660B90 80218440 4406A000 */  mfc1      $a2, $f20
/* 660B94 80218444 44071000 */  mfc1      $a3, $f2
/* 660B98 80218448 0C00A720 */  jal       atan2
/* 660B9C 8021844C 4600B386 */   mov.s    $f14, $f22
/* 660BA0 80218450 0220202D */  daddu     $a0, $s1, $zero
/* 660BA4 80218454 4600008D */  trunc.w.s $f2, $f0
/* 660BA8 80218458 44061000 */  mfc1      $a2, $f2
/* 660BAC 8021845C 0C0B2026 */  jal       evt_set_variable
/* 660BB0 80218460 0240282D */   daddu    $a1, $s2, $zero
/* 660BB4 80218464 8FBF001C */  lw        $ra, 0x1c($sp)
/* 660BB8 80218468 8FB20018 */  lw        $s2, 0x18($sp)
/* 660BBC 8021846C 8FB10014 */  lw        $s1, 0x14($sp)
/* 660BC0 80218470 8FB00010 */  lw        $s0, 0x10($sp)
/* 660BC4 80218474 D7B80030 */  ldc1      $f24, 0x30($sp)
/* 660BC8 80218478 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 660BCC 8021847C D7B40020 */  ldc1      $f20, 0x20($sp)
/* 660BD0 80218480 24020002 */  addiu     $v0, $zero, 2
/* 660BD4 80218484 03E00008 */  jr        $ra
/* 660BD8 80218488 27BD0038 */   addiu    $sp, $sp, 0x38

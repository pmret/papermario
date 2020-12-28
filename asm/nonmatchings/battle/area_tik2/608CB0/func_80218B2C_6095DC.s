.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B2C_6095DC
/* 6095DC 80218B2C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6095E0 80218B30 AFB10014 */  sw        $s1, 0x14($sp)
/* 6095E4 80218B34 0080882D */  daddu     $s1, $a0, $zero
/* 6095E8 80218B38 AFBF0020 */  sw        $ra, 0x20($sp)
/* 6095EC 80218B3C AFB3001C */  sw        $s3, 0x1c($sp)
/* 6095F0 80218B40 AFB20018 */  sw        $s2, 0x18($sp)
/* 6095F4 80218B44 AFB00010 */  sw        $s0, 0x10($sp)
/* 6095F8 80218B48 8E30000C */  lw        $s0, 0xc($s1)
/* 6095FC 80218B4C 8E050000 */  lw        $a1, ($s0)
/* 609600 80218B50 0C0B1EAF */  jal       get_variable
/* 609604 80218B54 26100004 */   addiu    $s0, $s0, 4
/* 609608 80218B58 8E050000 */  lw        $a1, ($s0)
/* 60960C 80218B5C 26100004 */  addiu     $s0, $s0, 4
/* 609610 80218B60 0220202D */  daddu     $a0, $s1, $zero
/* 609614 80218B64 0C0B1EAF */  jal       get_variable
/* 609618 80218B68 0040982D */   daddu    $s3, $v0, $zero
/* 60961C 80218B6C 8E050000 */  lw        $a1, ($s0)
/* 609620 80218B70 26100004 */  addiu     $s0, $s0, 4
/* 609624 80218B74 0220202D */  daddu     $a0, $s1, $zero
/* 609628 80218B78 0C0B1EAF */  jal       get_variable
/* 60962C 80218B7C 0040902D */   daddu    $s2, $v0, $zero
/* 609630 80218B80 0220202D */  daddu     $a0, $s1, $zero
/* 609634 80218B84 8E050000 */  lw        $a1, ($s0)
/* 609638 80218B88 0C0B1EAF */  jal       get_variable
/* 60963C 80218B8C 0040802D */   daddu    $s0, $v0, $zero
/* 609640 80218B90 44936000 */  mtc1      $s3, $f12
/* 609644 80218B94 00000000 */  nop       
/* 609648 80218B98 46806320 */  cvt.s.w   $f12, $f12
/* 60964C 80218B9C 44927000 */  mtc1      $s2, $f14
/* 609650 80218BA0 00000000 */  nop       
/* 609654 80218BA4 468073A0 */  cvt.s.w   $f14, $f14
/* 609658 80218BA8 44900000 */  mtc1      $s0, $f0
/* 60965C 80218BAC 00000000 */  nop       
/* 609660 80218BB0 46800020 */  cvt.s.w   $f0, $f0
/* 609664 80218BB4 44060000 */  mfc1      $a2, $f0
/* 609668 80218BB8 0C0B5D30 */  jal       func_802D74C0
/* 60966C 80218BBC 0040382D */   daddu    $a3, $v0, $zero
/* 609670 80218BC0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 609674 80218BC4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 609678 80218BC8 8FB20018 */  lw        $s2, 0x18($sp)
/* 60967C 80218BCC 8FB10014 */  lw        $s1, 0x14($sp)
/* 609680 80218BD0 8FB00010 */  lw        $s0, 0x10($sp)
/* 609684 80218BD4 24020002 */  addiu     $v0, $zero, 2
/* 609688 80218BD8 03E00008 */  jr        $ra
/* 60968C 80218BDC 27BD0028 */   addiu    $sp, $sp, 0x28

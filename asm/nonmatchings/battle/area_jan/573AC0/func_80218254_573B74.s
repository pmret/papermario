.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218254_573B74
/* 573B74 80218254 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 573B78 80218258 AFB10014 */  sw        $s1, 0x14($sp)
/* 573B7C 8021825C 0080882D */  daddu     $s1, $a0, $zero
/* 573B80 80218260 AFBF0020 */  sw        $ra, 0x20($sp)
/* 573B84 80218264 AFB3001C */  sw        $s3, 0x1c($sp)
/* 573B88 80218268 AFB20018 */  sw        $s2, 0x18($sp)
/* 573B8C 8021826C AFB00010 */  sw        $s0, 0x10($sp)
/* 573B90 80218270 8E30000C */  lw        $s0, 0xc($s1)
/* 573B94 80218274 8E050000 */  lw        $a1, ($s0)
/* 573B98 80218278 0C0B1EAF */  jal       get_variable
/* 573B9C 8021827C 26100004 */   addiu    $s0, $s0, 4
/* 573BA0 80218280 8E050000 */  lw        $a1, ($s0)
/* 573BA4 80218284 26100004 */  addiu     $s0, $s0, 4
/* 573BA8 80218288 0220202D */  daddu     $a0, $s1, $zero
/* 573BAC 8021828C 0C0B1EAF */  jal       get_variable
/* 573BB0 80218290 0040982D */   daddu    $s3, $v0, $zero
/* 573BB4 80218294 8E050000 */  lw        $a1, ($s0)
/* 573BB8 80218298 26100004 */  addiu     $s0, $s0, 4
/* 573BBC 8021829C 0220202D */  daddu     $a0, $s1, $zero
/* 573BC0 802182A0 0C0B1EAF */  jal       get_variable
/* 573BC4 802182A4 0040902D */   daddu    $s2, $v0, $zero
/* 573BC8 802182A8 0220202D */  daddu     $a0, $s1, $zero
/* 573BCC 802182AC 8E050000 */  lw        $a1, ($s0)
/* 573BD0 802182B0 0C0B1EAF */  jal       get_variable
/* 573BD4 802182B4 0040802D */   daddu    $s0, $v0, $zero
/* 573BD8 802182B8 44936000 */  mtc1      $s3, $f12
/* 573BDC 802182BC 00000000 */  nop       
/* 573BE0 802182C0 46806320 */  cvt.s.w   $f12, $f12
/* 573BE4 802182C4 44927000 */  mtc1      $s2, $f14
/* 573BE8 802182C8 00000000 */  nop       
/* 573BEC 802182CC 468073A0 */  cvt.s.w   $f14, $f14
/* 573BF0 802182D0 44900000 */  mtc1      $s0, $f0
/* 573BF4 802182D4 00000000 */  nop       
/* 573BF8 802182D8 46800020 */  cvt.s.w   $f0, $f0
/* 573BFC 802182DC 44060000 */  mfc1      $a2, $f0
/* 573C00 802182E0 0C0B5D30 */  jal       func_802D74C0
/* 573C04 802182E4 0040382D */   daddu    $a3, $v0, $zero
/* 573C08 802182E8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 573C0C 802182EC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 573C10 802182F0 8FB20018 */  lw        $s2, 0x18($sp)
/* 573C14 802182F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 573C18 802182F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 573C1C 802182FC 24020002 */  addiu     $v0, $zero, 2
/* 573C20 80218300 03E00008 */  jr        $ra
/* 573C24 80218304 27BD0028 */   addiu    $sp, $sp, 0x28
/* 573C28 80218308 00000000 */  nop       
/* 573C2C 8021830C 00000000 */  nop       

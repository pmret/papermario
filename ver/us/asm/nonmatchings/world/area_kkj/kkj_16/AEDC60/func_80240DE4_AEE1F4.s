.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DE4_AEE1F4
/* AEE1F4 80240DE4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* AEE1F8 80240DE8 AFB10014 */  sw        $s1, 0x14($sp)
/* AEE1FC 80240DEC 0080882D */  daddu     $s1, $a0, $zero
/* AEE200 80240DF0 AFBF0024 */  sw        $ra, 0x24($sp)
/* AEE204 80240DF4 AFB40020 */  sw        $s4, 0x20($sp)
/* AEE208 80240DF8 AFB3001C */  sw        $s3, 0x1c($sp)
/* AEE20C 80240DFC AFB20018 */  sw        $s2, 0x18($sp)
/* AEE210 80240E00 AFB00010 */  sw        $s0, 0x10($sp)
/* AEE214 80240E04 8E30000C */  lw        $s0, 0xc($s1)
/* AEE218 80240E08 8E140000 */  lw        $s4, ($s0)
/* AEE21C 80240E0C 26100004 */  addiu     $s0, $s0, 4
/* AEE220 80240E10 8E050000 */  lw        $a1, ($s0)
/* AEE224 80240E14 0C0B1EAF */  jal       evt_get_variable
/* AEE228 80240E18 26100004 */   addiu    $s0, $s0, 4
/* AEE22C 80240E1C 8E050000 */  lw        $a1, ($s0)
/* AEE230 80240E20 26100004 */  addiu     $s0, $s0, 4
/* AEE234 80240E24 0220202D */  daddu     $a0, $s1, $zero
/* AEE238 80240E28 0C0B1EAF */  jal       evt_get_variable
/* AEE23C 80240E2C 0040982D */   daddu    $s3, $v0, $zero
/* AEE240 80240E30 8E050000 */  lw        $a1, ($s0)
/* AEE244 80240E34 26100004 */  addiu     $s0, $s0, 4
/* AEE248 80240E38 0220202D */  daddu     $a0, $s1, $zero
/* AEE24C 80240E3C 0C0B1EAF */  jal       evt_get_variable
/* AEE250 80240E40 0040902D */   daddu    $s2, $v0, $zero
/* AEE254 80240E44 0220202D */  daddu     $a0, $s1, $zero
/* AEE258 80240E48 8E050000 */  lw        $a1, ($s0)
/* AEE25C 80240E4C 0C0B1EAF */  jal       evt_get_variable
/* AEE260 80240E50 0040802D */   daddu    $s0, $v0, $zero
/* AEE264 80240E54 44901000 */  mtc1      $s0, $f2
/* AEE268 80240E58 00000000 */  nop
/* AEE26C 80240E5C 468010A0 */  cvt.s.w   $f2, $f2
/* AEE270 80240E60 44936000 */  mtc1      $s3, $f12
/* AEE274 80240E64 00000000 */  nop
/* AEE278 80240E68 46806320 */  cvt.s.w   $f12, $f12
/* AEE27C 80240E6C 44061000 */  mfc1      $a2, $f2
/* AEE280 80240E70 44821000 */  mtc1      $v0, $f2
/* AEE284 80240E74 00000000 */  nop
/* AEE288 80240E78 468010A0 */  cvt.s.w   $f2, $f2
/* AEE28C 80240E7C 44071000 */  mfc1      $a3, $f2
/* AEE290 80240E80 44927000 */  mtc1      $s2, $f14
/* AEE294 80240E84 00000000 */  nop
/* AEE298 80240E88 0C00A720 */  jal       atan2
/* AEE29C 80240E8C 468073A0 */   cvt.s.w  $f14, $f14
/* AEE2A0 80240E90 0220202D */  daddu     $a0, $s1, $zero
/* AEE2A4 80240E94 4600008D */  trunc.w.s $f2, $f0
/* AEE2A8 80240E98 44061000 */  mfc1      $a2, $f2
/* AEE2AC 80240E9C 0C0B2026 */  jal       evt_set_variable
/* AEE2B0 80240EA0 0280282D */   daddu    $a1, $s4, $zero
/* AEE2B4 80240EA4 8FBF0024 */  lw        $ra, 0x24($sp)
/* AEE2B8 80240EA8 8FB40020 */  lw        $s4, 0x20($sp)
/* AEE2BC 80240EAC 8FB3001C */  lw        $s3, 0x1c($sp)
/* AEE2C0 80240EB0 8FB20018 */  lw        $s2, 0x18($sp)
/* AEE2C4 80240EB4 8FB10014 */  lw        $s1, 0x14($sp)
/* AEE2C8 80240EB8 8FB00010 */  lw        $s0, 0x10($sp)
/* AEE2CC 80240EBC 24020002 */  addiu     $v0, $zero, 2
/* AEE2D0 80240EC0 03E00008 */  jr        $ra
/* AEE2D4 80240EC4 27BD0028 */   addiu    $sp, $sp, 0x28

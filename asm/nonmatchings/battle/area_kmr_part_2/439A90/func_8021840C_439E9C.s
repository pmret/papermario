.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021840C_439E9C
/* 439E9C 8021840C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 439EA0 80218410 AFB40020 */  sw        $s4, 0x20($sp)
/* 439EA4 80218414 0080A02D */  daddu     $s4, $a0, $zero
/* 439EA8 80218418 AFBF0024 */  sw        $ra, 0x24($sp)
/* 439EAC 8021841C AFB3001C */  sw        $s3, 0x1c($sp)
/* 439EB0 80218420 AFB20018 */  sw        $s2, 0x18($sp)
/* 439EB4 80218424 AFB10014 */  sw        $s1, 0x14($sp)
/* 439EB8 80218428 AFB00010 */  sw        $s0, 0x10($sp)
/* 439EBC 8021842C 8E92000C */  lw        $s2, 0xc($s4)
/* 439EC0 80218430 8E450000 */  lw        $a1, ($s2)
/* 439EC4 80218434 0C0B1EAF */  jal       get_variable
/* 439EC8 80218438 26520004 */   addiu    $s2, $s2, 4
/* 439ECC 8021843C 8E450000 */  lw        $a1, ($s2)
/* 439ED0 80218440 26520004 */  addiu     $s2, $s2, 4
/* 439ED4 80218444 0280202D */  daddu     $a0, $s4, $zero
/* 439ED8 80218448 0C0B1EAF */  jal       get_variable
/* 439EDC 8021844C 0040802D */   daddu    $s0, $v0, $zero
/* 439EE0 80218450 8E450000 */  lw        $a1, ($s2)
/* 439EE4 80218454 26520004 */  addiu     $s2, $s2, 4
/* 439EE8 80218458 0280202D */  daddu     $a0, $s4, $zero
/* 439EEC 8021845C 0C0B1EAF */  jal       get_variable
/* 439EF0 80218460 0040882D */   daddu    $s1, $v0, $zero
/* 439EF4 80218464 0040982D */  daddu     $s3, $v0, $zero
/* 439EF8 80218468 8E450000 */  lw        $a1, ($s2)
/* 439EFC 8021846C 26520004 */  addiu     $s2, $s2, 4
/* 439F00 80218470 0280202D */  daddu     $a0, $s4, $zero
/* 439F04 80218474 0C0B1EAF */  jal       get_variable
/* 439F08 80218478 02709823 */   subu     $s3, $s3, $s0
/* 439F0C 8021847C 0040802D */  daddu     $s0, $v0, $zero
/* 439F10 80218480 0280202D */  daddu     $a0, $s4, $zero
/* 439F14 80218484 8E450000 */  lw        $a1, ($s2)
/* 439F18 80218488 0C0B1EAF */  jal       get_variable
/* 439F1C 8021848C 02118023 */   subu     $s0, $s0, $s1
/* 439F20 80218490 16600006 */  bnez      $s3, .L802184AC
/* 439F24 80218494 00000000 */   nop
/* 439F28 80218498 16000004 */  bnez      $s0, .L802184AC
/* 439F2C 8021849C 0280202D */   daddu    $a0, $s4, $zero
/* 439F30 802184A0 8E450000 */  lw        $a1, ($s2)
/* 439F34 802184A4 08086135 */  j         .L802184D4
/* 439F38 802184A8 0040302D */   daddu    $a2, $v0, $zero
.L802184AC:
/* 439F3C 802184AC 44936000 */  mtc1      $s3, $f12
/* 439F40 802184B0 00000000 */  nop
/* 439F44 802184B4 46806320 */  cvt.s.w   $f12, $f12
/* 439F48 802184B8 44907000 */  mtc1      $s0, $f14
/* 439F4C 802184BC 00000000 */  nop
/* 439F50 802184C0 0C0860A0 */  jal       func_80218280_439D10
/* 439F54 802184C4 468073A0 */   cvt.s.w  $f14, $f14
/* 439F58 802184C8 0280202D */  daddu     $a0, $s4, $zero
/* 439F5C 802184CC 8E450000 */  lw        $a1, ($s2)
/* 439F60 802184D0 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L802184D4:
/* 439F64 802184D4 0C0B2026 */  jal       set_variable
/* 439F68 802184D8 00000000 */   nop
/* 439F6C 802184DC 24020002 */  addiu     $v0, $zero, 2
/* 439F70 802184E0 8FBF0024 */  lw        $ra, 0x24($sp)
/* 439F74 802184E4 8FB40020 */  lw        $s4, 0x20($sp)
/* 439F78 802184E8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 439F7C 802184EC 8FB20018 */  lw        $s2, 0x18($sp)
/* 439F80 802184F0 8FB10014 */  lw        $s1, 0x14($sp)
/* 439F84 802184F4 8FB00010 */  lw        $s0, 0x10($sp)
/* 439F88 802184F8 03E00008 */  jr        $ra
/* 439F8C 802184FC 27BD0028 */   addiu    $sp, $sp, 0x28

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218970_557D50
/* 557D50 80218970 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 557D54 80218974 AFB10014 */  sw        $s1, 0x14($sp)
/* 557D58 80218978 0080882D */  daddu     $s1, $a0, $zero
/* 557D5C 8021897C AFBF0020 */  sw        $ra, 0x20($sp)
/* 557D60 80218980 AFB3001C */  sw        $s3, 0x1c($sp)
/* 557D64 80218984 AFB20018 */  sw        $s2, 0x18($sp)
/* 557D68 80218988 AFB00010 */  sw        $s0, 0x10($sp)
/* 557D6C 8021898C 8E30000C */  lw        $s0, 0xc($s1)
/* 557D70 80218990 8E050000 */  lw        $a1, ($s0)
/* 557D74 80218994 0C0B1EAF */  jal       get_variable
/* 557D78 80218998 26100004 */   addiu    $s0, $s0, 4
/* 557D7C 8021899C 8E050000 */  lw        $a1, ($s0)
/* 557D80 802189A0 26100004 */  addiu     $s0, $s0, 4
/* 557D84 802189A4 0220202D */  daddu     $a0, $s1, $zero
/* 557D88 802189A8 0C0B1EAF */  jal       get_variable
/* 557D8C 802189AC 0040982D */   daddu    $s3, $v0, $zero
/* 557D90 802189B0 8E050000 */  lw        $a1, ($s0)
/* 557D94 802189B4 26100004 */  addiu     $s0, $s0, 4
/* 557D98 802189B8 0220202D */  daddu     $a0, $s1, $zero
/* 557D9C 802189BC 0C0B1EAF */  jal       get_variable
/* 557DA0 802189C0 0040902D */   daddu    $s2, $v0, $zero
/* 557DA4 802189C4 0220202D */  daddu     $a0, $s1, $zero
/* 557DA8 802189C8 8E050000 */  lw        $a1, ($s0)
/* 557DAC 802189CC 0C0B1EAF */  jal       get_variable
/* 557DB0 802189D0 0040802D */   daddu    $s0, $v0, $zero
/* 557DB4 802189D4 44936000 */  mtc1      $s3, $f12
/* 557DB8 802189D8 00000000 */  nop       
/* 557DBC 802189DC 46806320 */  cvt.s.w   $f12, $f12
/* 557DC0 802189E0 44927000 */  mtc1      $s2, $f14
/* 557DC4 802189E4 00000000 */  nop       
/* 557DC8 802189E8 468073A0 */  cvt.s.w   $f14, $f14
/* 557DCC 802189EC 44900000 */  mtc1      $s0, $f0
/* 557DD0 802189F0 00000000 */  nop       
/* 557DD4 802189F4 46800020 */  cvt.s.w   $f0, $f0
/* 557DD8 802189F8 44060000 */  mfc1      $a2, $f0
/* 557DDC 802189FC 0C0B5D18 */  jal       func_802D7460
/* 557DE0 80218A00 0040382D */   daddu    $a3, $v0, $zero
/* 557DE4 80218A04 8FBF0020 */  lw        $ra, 0x20($sp)
/* 557DE8 80218A08 8FB3001C */  lw        $s3, 0x1c($sp)
/* 557DEC 80218A0C 8FB20018 */  lw        $s2, 0x18($sp)
/* 557DF0 80218A10 8FB10014 */  lw        $s1, 0x14($sp)
/* 557DF4 80218A14 8FB00010 */  lw        $s0, 0x10($sp)
/* 557DF8 80218A18 24020002 */  addiu     $v0, $zero, 2
/* 557DFC 80218A1C 03E00008 */  jr        $ra
/* 557E00 80218A20 27BD0028 */   addiu    $sp, $sp, 0x28

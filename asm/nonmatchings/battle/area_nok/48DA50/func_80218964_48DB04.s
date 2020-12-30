.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218964_48DB04
/* 48DB04 80218964 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 48DB08 80218968 AFB10014 */  sw        $s1, 0x14($sp)
/* 48DB0C 8021896C 0080882D */  daddu     $s1, $a0, $zero
/* 48DB10 80218970 AFBF0020 */  sw        $ra, 0x20($sp)
/* 48DB14 80218974 AFB3001C */  sw        $s3, 0x1c($sp)
/* 48DB18 80218978 AFB20018 */  sw        $s2, 0x18($sp)
/* 48DB1C 8021897C AFB00010 */  sw        $s0, 0x10($sp)
/* 48DB20 80218980 8E30000C */  lw        $s0, 0xc($s1)
/* 48DB24 80218984 8E050000 */  lw        $a1, ($s0)
/* 48DB28 80218988 0C0B1EAF */  jal       get_variable
/* 48DB2C 8021898C 26100004 */   addiu    $s0, $s0, 4
/* 48DB30 80218990 8E050000 */  lw        $a1, ($s0)
/* 48DB34 80218994 26100004 */  addiu     $s0, $s0, 4
/* 48DB38 80218998 0220202D */  daddu     $a0, $s1, $zero
/* 48DB3C 8021899C 0C0B1EAF */  jal       get_variable
/* 48DB40 802189A0 0040982D */   daddu    $s3, $v0, $zero
/* 48DB44 802189A4 8E050000 */  lw        $a1, ($s0)
/* 48DB48 802189A8 26100004 */  addiu     $s0, $s0, 4
/* 48DB4C 802189AC 0220202D */  daddu     $a0, $s1, $zero
/* 48DB50 802189B0 0C0B1EAF */  jal       get_variable
/* 48DB54 802189B4 0040902D */   daddu    $s2, $v0, $zero
/* 48DB58 802189B8 0220202D */  daddu     $a0, $s1, $zero
/* 48DB5C 802189BC 8E050000 */  lw        $a1, ($s0)
/* 48DB60 802189C0 0C0B1EAF */  jal       get_variable
/* 48DB64 802189C4 0040802D */   daddu    $s0, $v0, $zero
/* 48DB68 802189C8 44936000 */  mtc1      $s3, $f12
/* 48DB6C 802189CC 00000000 */  nop       
/* 48DB70 802189D0 46806320 */  cvt.s.w   $f12, $f12
/* 48DB74 802189D4 44927000 */  mtc1      $s2, $f14
/* 48DB78 802189D8 00000000 */  nop       
/* 48DB7C 802189DC 468073A0 */  cvt.s.w   $f14, $f14
/* 48DB80 802189E0 44900000 */  mtc1      $s0, $f0
/* 48DB84 802189E4 00000000 */  nop       
/* 48DB88 802189E8 46800020 */  cvt.s.w   $f0, $f0
/* 48DB8C 802189EC 44060000 */  mfc1      $a2, $f0
/* 48DB90 802189F0 0C0B5D30 */  jal       func_802D74C0
/* 48DB94 802189F4 0040382D */   daddu    $a3, $v0, $zero
/* 48DB98 802189F8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 48DB9C 802189FC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 48DBA0 80218A00 8FB20018 */  lw        $s2, 0x18($sp)
/* 48DBA4 80218A04 8FB10014 */  lw        $s1, 0x14($sp)
/* 48DBA8 80218A08 8FB00010 */  lw        $s0, 0x10($sp)
/* 48DBAC 80218A0C 24020002 */  addiu     $v0, $zero, 2
/* 48DBB0 80218A10 03E00008 */  jr        $ra
/* 48DBB4 80218A14 27BD0028 */   addiu    $sp, $sp, 0x28
/* 48DBB8 80218A18 00000000 */  nop       
/* 48DBBC 80218A1C 00000000 */  nop       

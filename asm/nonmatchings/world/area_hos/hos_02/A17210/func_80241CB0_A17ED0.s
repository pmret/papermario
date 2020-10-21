.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CB0_A17ED0
/* A17ED0 80241CB0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A17ED4 80241CB4 AFB3001C */  sw        $s3, 0x1c($sp)
/* A17ED8 80241CB8 0080982D */  daddu     $s3, $a0, $zero
/* A17EDC 80241CBC AFBF0020 */  sw        $ra, 0x20($sp)
/* A17EE0 80241CC0 AFB20018 */  sw        $s2, 0x18($sp)
/* A17EE4 80241CC4 AFB10014 */  sw        $s1, 0x14($sp)
/* A17EE8 80241CC8 AFB00010 */  sw        $s0, 0x10($sp)
/* A17EEC 80241CCC 8E720148 */  lw        $s2, 0x148($s3)
/* A17EF0 80241CD0 86440008 */  lh        $a0, 8($s2)
/* A17EF4 80241CD4 0C00EABB */  jal       get_npc_unsafe
/* A17EF8 80241CD8 00A0802D */   daddu    $s0, $a1, $zero
/* A17EFC 80241CDC 0040882D */  daddu     $s1, $v0, $zero
/* A17F00 80241CE0 C6420080 */  lwc1      $f2, 0x80($s2)
/* A17F04 80241CE4 468010A0 */  cvt.s.w   $f2, $f2
/* A17F08 80241CE8 460010A1 */  cvt.d.s   $f2, $f2
/* A17F0C 80241CEC C6400084 */  lwc1      $f0, 0x84($s2)
/* A17F10 80241CF0 46800020 */  cvt.s.w   $f0, $f0
/* A17F14 80241CF4 46000021 */  cvt.d.s   $f0, $f0
/* A17F18 80241CF8 3C014059 */  lui       $at, 0x4059
/* A17F1C 80241CFC 44812800 */  mtc1      $at, $f5
/* A17F20 80241D00 44802000 */  mtc1      $zero, $f4
/* A17F24 80241D04 8E4200CC */  lw        $v0, 0xcc($s2)
/* A17F28 80241D08 C62C0038 */  lwc1      $f12, 0x38($s1)
/* A17F2C 80241D0C C62E0040 */  lwc1      $f14, 0x40($s1)
/* A17F30 80241D10 46241083 */  div.d     $f2, $f2, $f4
/* A17F34 80241D14 462010A0 */  cvt.s.d   $f2, $f2
/* A17F38 80241D18 46240003 */  div.d     $f0, $f0, $f4
/* A17F3C 80241D1C 8C420020 */  lw        $v0, 0x20($v0)
/* A17F40 80241D20 46200020 */  cvt.s.d   $f0, $f0
/* A17F44 80241D24 E622001C */  swc1      $f2, 0x1c($s1)
/* A17F48 80241D28 E6200014 */  swc1      $f0, 0x14($s1)
/* A17F4C 80241D2C AE220028 */  sw        $v0, 0x28($s1)
/* A17F50 80241D30 C6000018 */  lwc1      $f0, 0x18($s0)
/* A17F54 80241D34 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* A17F58 80241D38 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* A17F5C 80241D3C E6200018 */  swc1      $f0, 0x18($s1)
/* A17F60 80241D40 8C460028 */  lw        $a2, 0x28($v0)
/* A17F64 80241D44 0C00A720 */  jal       atan2
/* A17F68 80241D48 8C470030 */   lw       $a3, 0x30($v0)
/* A17F6C 80241D4C E620000C */  swc1      $f0, 0xc($s1)
/* A17F70 80241D50 8E420018 */  lw        $v0, 0x18($s2)
/* A17F74 80241D54 AE400074 */  sw        $zero, 0x74($s2)
/* A17F78 80241D58 9442002A */  lhu       $v0, 0x2a($v0)
/* A17F7C 80241D5C 30420002 */  andi      $v0, $v0, 2
/* A17F80 80241D60 10400005 */  beqz      $v0, .L80241D78
/* A17F84 80241D64 24020003 */   addiu    $v0, $zero, 3
/* A17F88 80241D68 A622008E */  sh        $v0, 0x8e($s1)
/* A17F8C 80241D6C 2402000D */  addiu     $v0, $zero, 0xd
/* A17F90 80241D70 08090772 */  j         .L80241DC8
/* A17F94 80241D74 AE620070 */   sw       $v0, 0x70($s3)
.L80241D78:
/* A17F98 80241D78 24030001 */  addiu     $v1, $zero, 1
/* A17F9C 80241D7C 2402000E */  addiu     $v0, $zero, 0xe
/* A17FA0 80241D80 A623008E */  sh        $v1, 0x8e($s1)
/* A17FA4 80241D84 AE620070 */  sw        $v0, 0x70($s3)
/* A17FA8 80241D88 C6200038 */  lwc1      $f0, 0x38($s1)
/* A17FAC 80241D8C 4600018D */  trunc.w.s $f6, $f0
/* A17FB0 80241D90 44023000 */  mfc1      $v0, $f6
/* A17FB4 80241D94 00000000 */  nop       
/* A17FB8 80241D98 A6420010 */  sh        $v0, 0x10($s2)
/* A17FBC 80241D9C C620003C */  lwc1      $f0, 0x3c($s1)
/* A17FC0 80241DA0 4600018D */  trunc.w.s $f6, $f0
/* A17FC4 80241DA4 44023000 */  mfc1      $v0, $f6
/* A17FC8 80241DA8 00000000 */  nop       
/* A17FCC 80241DAC A6420012 */  sh        $v0, 0x12($s2)
/* A17FD0 80241DB0 C6200040 */  lwc1      $f0, 0x40($s1)
/* A17FD4 80241DB4 A2430007 */  sb        $v1, 7($s2)
/* A17FD8 80241DB8 4600018D */  trunc.w.s $f6, $f0
/* A17FDC 80241DBC 44023000 */  mfc1      $v0, $f6
/* A17FE0 80241DC0 00000000 */  nop       
/* A17FE4 80241DC4 A6420014 */  sh        $v0, 0x14($s2)
.L80241DC8:
/* A17FE8 80241DC8 8FBF0020 */  lw        $ra, 0x20($sp)
/* A17FEC 80241DCC 8FB3001C */  lw        $s3, 0x1c($sp)
/* A17FF0 80241DD0 8FB20018 */  lw        $s2, 0x18($sp)
/* A17FF4 80241DD4 8FB10014 */  lw        $s1, 0x14($sp)
/* A17FF8 80241DD8 8FB00010 */  lw        $s0, 0x10($sp)
/* A17FFC 80241DDC 03E00008 */  jr        $ra
/* A18000 80241DE0 27BD0028 */   addiu    $sp, $sp, 0x28

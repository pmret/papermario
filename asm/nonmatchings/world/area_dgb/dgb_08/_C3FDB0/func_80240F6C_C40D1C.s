.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F6C_C40D1C
/* C40D1C 80240F6C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* C40D20 80240F70 AFB10034 */  sw        $s1, 0x34($sp)
/* C40D24 80240F74 0080882D */  daddu     $s1, $a0, $zero
/* C40D28 80240F78 AFBF0038 */  sw        $ra, 0x38($sp)
/* C40D2C 80240F7C AFB00030 */  sw        $s0, 0x30($sp)
/* C40D30 80240F80 8E300148 */  lw        $s0, 0x148($s1)
/* C40D34 80240F84 0C00EABB */  jal       get_npc_unsafe
/* C40D38 80240F88 86040008 */   lh       $a0, 8($s0)
/* C40D3C 80240F8C 0040282D */  daddu     $a1, $v0, $zero
/* C40D40 80240F90 94A2008E */  lhu       $v0, 0x8e($a1)
/* C40D44 80240F94 2442FFFF */  addiu     $v0, $v0, -1
/* C40D48 80240F98 A4A2008E */  sh        $v0, 0x8e($a1)
/* C40D4C 80240F9C 00021400 */  sll       $v0, $v0, 0x10
/* C40D50 80240FA0 1C400023 */  bgtz      $v0, .L80241030
/* C40D54 80240FA4 24020004 */   addiu    $v0, $zero, 4
/* C40D58 80240FA8 8E0300CC */  lw        $v1, 0xcc($s0)
/* C40D5C 80240FAC AE02006C */  sw        $v0, 0x6c($s0)
/* C40D60 80240FB0 8C620000 */  lw        $v0, ($v1)
/* C40D64 80240FB4 ACA20028 */  sw        $v0, 0x28($a1)
/* C40D68 80240FB8 9602007A */  lhu       $v0, 0x7a($s0)
/* C40D6C 80240FBC A4A2008E */  sh        $v0, 0x8e($a1)
/* C40D70 80240FC0 8E020078 */  lw        $v0, 0x78($s0)
/* C40D74 80240FC4 28420008 */  slti      $v0, $v0, 8
/* C40D78 80240FC8 14400018 */  bnez      $v0, .L8024102C
/* C40D7C 80240FCC 24020021 */   addiu    $v0, $zero, 0x21
/* C40D80 80240FD0 24040003 */  addiu     $a0, $zero, 3
/* C40D84 80240FD4 27A30028 */  addiu     $v1, $sp, 0x28
/* C40D88 80240FD8 84A700A8 */  lh        $a3, 0xa8($a1)
/* C40D8C 80240FDC 3C013F80 */  lui       $at, 0x3f80
/* C40D90 80240FE0 44810000 */  mtc1      $at, $f0
/* C40D94 80240FE4 3C014000 */  lui       $at, 0x4000
/* C40D98 80240FE8 44811000 */  mtc1      $at, $f2
/* C40D9C 80240FEC 3C01C1A0 */  lui       $at, 0xc1a0
/* C40DA0 80240FF0 44812000 */  mtc1      $at, $f4
/* C40DA4 80240FF4 44873000 */  mtc1      $a3, $f6
/* C40DA8 80240FF8 00000000 */  nop       
/* C40DAC 80240FFC 468031A0 */  cvt.s.w   $f6, $f6
/* C40DB0 80241000 E7A00010 */  swc1      $f0, 0x10($sp)
/* C40DB4 80241004 E7A20014 */  swc1      $f2, 0x14($sp)
/* C40DB8 80241008 E7A40018 */  swc1      $f4, 0x18($sp)
/* C40DBC 8024100C 8E020078 */  lw        $v0, 0x78($s0)
/* C40DC0 80241010 44073000 */  mfc1      $a3, $f6
/* C40DC4 80241014 0000302D */  daddu     $a2, $zero, $zero
/* C40DC8 80241018 AFA30020 */  sw        $v1, 0x20($sp)
/* C40DCC 8024101C 2442FFFF */  addiu     $v0, $v0, -1
/* C40DD0 80241020 0C01BFA4 */  jal       fx_emote
/* C40DD4 80241024 AFA2001C */   sw       $v0, 0x1c($sp)
/* C40DD8 80241028 24020021 */  addiu     $v0, $zero, 0x21
.L8024102C:
/* C40DDC 8024102C AE220070 */  sw        $v0, 0x70($s1)
.L80241030:
/* C40DE0 80241030 8FBF0038 */  lw        $ra, 0x38($sp)
/* C40DE4 80241034 8FB10034 */  lw        $s1, 0x34($sp)
/* C40DE8 80241038 8FB00030 */  lw        $s0, 0x30($sp)
/* C40DEC 8024103C 03E00008 */  jr        $ra
/* C40DF0 80241040 27BD0040 */   addiu    $sp, $sp, 0x40

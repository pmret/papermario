.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F8C_D2CCBC
/* D2CCBC 80240F8C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* D2CCC0 80240F90 AFB3003C */  sw        $s3, 0x3c($sp)
/* D2CCC4 80240F94 0080982D */  daddu     $s3, $a0, $zero
/* D2CCC8 80240F98 AFBF0040 */  sw        $ra, 0x40($sp)
/* D2CCCC 80240F9C AFB20038 */  sw        $s2, 0x38($sp)
/* D2CCD0 80240FA0 AFB10034 */  sw        $s1, 0x34($sp)
/* D2CCD4 80240FA4 AFB00030 */  sw        $s0, 0x30($sp)
/* D2CCD8 80240FA8 8E720148 */  lw        $s2, 0x148($s3)
/* D2CCDC 80240FAC 00A0882D */  daddu     $s1, $a1, $zero
/* D2CCE0 80240FB0 86440008 */  lh        $a0, 8($s2)
/* D2CCE4 80240FB4 0C00EABB */  jal       get_npc_unsafe
/* D2CCE8 80240FB8 00C0802D */   daddu    $s0, $a2, $zero
/* D2CCEC 80240FBC 0200202D */  daddu     $a0, $s0, $zero
/* D2CCF0 80240FC0 0240282D */  daddu     $a1, $s2, $zero
/* D2CCF4 80240FC4 AFA00010 */  sw        $zero, 0x10($sp)
/* D2CCF8 80240FC8 8E26000C */  lw        $a2, 0xc($s1)
/* D2CCFC 80240FCC 8E270010 */  lw        $a3, 0x10($s1)
/* D2CD00 80240FD0 0C01242D */  jal       func_800490B4
/* D2CD04 80240FD4 0040882D */   daddu    $s1, $v0, $zero
/* D2CD08 80240FD8 10400024 */  beqz      $v0, .L8024106C
/* D2CD0C 80240FDC 0220202D */   daddu    $a0, $s1, $zero
/* D2CD10 80240FE0 24050322 */  addiu     $a1, $zero, 0x322
/* D2CD14 80240FE4 0C012530 */  jal       func_800494C0
/* D2CD18 80240FE8 0000302D */   daddu    $a2, $zero, $zero
/* D2CD1C 80240FEC 0000202D */  daddu     $a0, $zero, $zero
/* D2CD20 80240FF0 0220282D */  daddu     $a1, $s1, $zero
/* D2CD24 80240FF4 0000302D */  daddu     $a2, $zero, $zero
/* D2CD28 80240FF8 2410000A */  addiu     $s0, $zero, 0xa
/* D2CD2C 80240FFC 862300A8 */  lh        $v1, 0xa8($s1)
/* D2CD30 80241000 3C013F80 */  lui       $at, 0x3f80
/* D2CD34 80241004 44810000 */  mtc1      $at, $f0
/* D2CD38 80241008 3C014000 */  lui       $at, 0x4000
/* D2CD3C 8024100C 44811000 */  mtc1      $at, $f2
/* D2CD40 80241010 3C01C1A0 */  lui       $at, 0xc1a0
/* D2CD44 80241014 44812000 */  mtc1      $at, $f4
/* D2CD48 80241018 44833000 */  mtc1      $v1, $f6
/* D2CD4C 8024101C 00000000 */  nop       
/* D2CD50 80241020 468031A0 */  cvt.s.w   $f6, $f6
/* D2CD54 80241024 44073000 */  mfc1      $a3, $f6
/* D2CD58 80241028 27A20028 */  addiu     $v0, $sp, 0x28
/* D2CD5C 8024102C AFB0001C */  sw        $s0, 0x1c($sp)
/* D2CD60 80241030 AFA20020 */  sw        $v0, 0x20($sp)
/* D2CD64 80241034 E7A00010 */  swc1      $f0, 0x10($sp)
/* D2CD68 80241038 E7A20014 */  swc1      $f2, 0x14($sp)
/* D2CD6C 8024103C 0C01BFA4 */  jal       fx_emote
/* D2CD70 80241040 E7A40018 */   swc1     $f4, 0x18($sp)
/* D2CD74 80241044 0220202D */  daddu     $a0, $s1, $zero
/* D2CD78 80241048 240502F4 */  addiu     $a1, $zero, 0x2f4
/* D2CD7C 8024104C 0C012530 */  jal       func_800494C0
/* D2CD80 80241050 3C060020 */   lui      $a2, 0x20
/* D2CD84 80241054 8E4200CC */  lw        $v0, 0xcc($s2)
/* D2CD88 80241058 8C420020 */  lw        $v0, 0x20($v0)
/* D2CD8C 8024105C AE220028 */  sw        $v0, 0x28($s1)
/* D2CD90 80241060 9642008E */  lhu       $v0, 0x8e($s2)
/* D2CD94 80241064 A622008E */  sh        $v0, 0x8e($s1)
/* D2CD98 80241068 AE700070 */  sw        $s0, 0x70($s3)
.L8024106C:
/* D2CD9C 8024106C 8FBF0040 */  lw        $ra, 0x40($sp)
/* D2CDA0 80241070 8FB3003C */  lw        $s3, 0x3c($sp)
/* D2CDA4 80241074 8FB20038 */  lw        $s2, 0x38($sp)
/* D2CDA8 80241078 8FB10034 */  lw        $s1, 0x34($sp)
/* D2CDAC 8024107C 8FB00030 */  lw        $s0, 0x30($sp)
/* D2CDB0 80241080 03E00008 */  jr        $ra
/* D2CDB4 80241084 27BD0048 */   addiu    $sp, $sp, 0x48

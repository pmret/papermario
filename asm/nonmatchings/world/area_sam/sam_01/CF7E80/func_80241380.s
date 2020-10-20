.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241380
/* CF8EF0 80241380 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* CF8EF4 80241384 AFB20018 */  sw        $s2, 0x18($sp)
/* CF8EF8 80241388 0080902D */  daddu     $s2, $a0, $zero
/* CF8EFC 8024138C AFBF0030 */  sw        $ra, 0x30($sp)
/* CF8F00 80241390 AFB7002C */  sw        $s7, 0x2c($sp)
/* CF8F04 80241394 AFB60028 */  sw        $s6, 0x28($sp)
/* CF8F08 80241398 AFB50024 */  sw        $s5, 0x24($sp)
/* CF8F0C 8024139C AFB40020 */  sw        $s4, 0x20($sp)
/* CF8F10 802413A0 AFB3001C */  sw        $s3, 0x1c($sp)
/* CF8F14 802413A4 AFB10014 */  sw        $s1, 0x14($sp)
/* CF8F18 802413A8 AFB00010 */  sw        $s0, 0x10($sp)
/* CF8F1C 802413AC F7B60040 */  sdc1      $f22, 0x40($sp)
/* CF8F20 802413B0 F7B40038 */  sdc1      $f20, 0x38($sp)
/* CF8F24 802413B4 8E50000C */  lw        $s0, 0xc($s2)
/* CF8F28 802413B8 8E050000 */  lw        $a1, ($s0)
/* CF8F2C 802413BC 0C0B1EAF */  jal       get_variable
/* CF8F30 802413C0 26100004 */   addiu    $s0, $s0, 4
/* CF8F34 802413C4 8E050000 */  lw        $a1, ($s0)
/* CF8F38 802413C8 26100004 */  addiu     $s0, $s0, 4
/* CF8F3C 802413CC 0240202D */  daddu     $a0, $s2, $zero
/* CF8F40 802413D0 0C0B1EAF */  jal       get_variable
/* CF8F44 802413D4 0040B82D */   daddu    $s7, $v0, $zero
/* CF8F48 802413D8 8E050000 */  lw        $a1, ($s0)
/* CF8F4C 802413DC 26100004 */  addiu     $s0, $s0, 4
/* CF8F50 802413E0 0240202D */  daddu     $a0, $s2, $zero
/* CF8F54 802413E4 0C0B1EAF */  jal       get_variable
/* CF8F58 802413E8 0040B02D */   daddu    $s6, $v0, $zero
/* CF8F5C 802413EC 0240202D */  daddu     $a0, $s2, $zero
/* CF8F60 802413F0 3C05F4AC */  lui       $a1, 0xf4ac
/* CF8F64 802413F4 34A5D481 */  ori       $a1, $a1, 0xd481
/* CF8F68 802413F8 3C068007 */  lui       $a2, %hi(gCurrentCameraID)
/* CF8F6C 802413FC 8CC67410 */  lw        $a2, %lo(gCurrentCameraID)($a2)
/* CF8F70 80241400 8E140000 */  lw        $s4, ($s0)
/* CF8F74 80241404 00061880 */  sll       $v1, $a2, 2
/* CF8F78 80241408 00661821 */  addu      $v1, $v1, $a2
/* CF8F7C 8024140C 00031880 */  sll       $v1, $v1, 2
/* CF8F80 80241410 00661823 */  subu      $v1, $v1, $a2
/* CF8F84 80241414 000330C0 */  sll       $a2, $v1, 3
/* CF8F88 80241418 00661821 */  addu      $v1, $v1, $a2
/* CF8F8C 8024141C 000318C0 */  sll       $v1, $v1, 3
/* CF8F90 80241420 3C01800B */  lui       $at, 0x800b
/* CF8F94 80241424 00230821 */  addu      $at, $at, $v1
/* CF8F98 80241428 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* CF8F9C 8024142C 8E150004 */  lw        $s5, 4($s0)
/* CF8FA0 80241430 4600010D */  trunc.w.s $f4, $f0
/* CF8FA4 80241434 44112000 */  mfc1      $s1, $f4
/* CF8FA8 80241438 0C0B1EAF */  jal       get_variable
/* CF8FAC 8024143C 0040982D */   daddu    $s3, $v0, $zero
/* CF8FB0 80241440 4491B000 */  mtc1      $s1, $f22
/* CF8FB4 80241444 00000000 */  nop       
/* CF8FB8 80241448 4680B5A0 */  cvt.s.w   $f22, $f22
/* CF8FBC 8024144C 4600B306 */  mov.s     $f12, $f22
/* CF8FC0 80241450 0C00A8D4 */  jal       cos_deg
/* CF8FC4 80241454 0040802D */   daddu    $s0, $v0, $zero
/* CF8FC8 80241458 4493A000 */  mtc1      $s3, $f20
/* CF8FCC 8024145C 00000000 */  nop       
/* CF8FD0 80241460 4680A520 */  cvt.s.w   $f20, $f20
/* CF8FD4 80241464 4600A002 */  mul.s     $f0, $f20, $f0
/* CF8FD8 80241468 00000000 */  nop       
/* CF8FDC 8024146C 0240202D */  daddu     $a0, $s2, $zero
/* CF8FE0 80241470 44901000 */  mtc1      $s0, $f2
/* CF8FE4 80241474 00000000 */  nop       
/* CF8FE8 80241478 468010A0 */  cvt.s.w   $f2, $f2
/* CF8FEC 8024147C 46001081 */  sub.s     $f2, $f2, $f0
/* CF8FF0 80241480 3C05F4AC */  lui       $a1, 0xf4ac
/* CF8FF4 80241484 4600110D */  trunc.w.s $f4, $f2
/* CF8FF8 80241488 44102000 */  mfc1      $s0, $f4
/* CF8FFC 8024148C 0C0B1EAF */  jal       get_variable
/* CF9000 80241490 34A5D483 */   ori      $a1, $a1, 0xd483
/* CF9004 80241494 4600B306 */  mov.s     $f12, $f22
/* CF9008 80241498 0C00A8BB */  jal       sin_deg
/* CF900C 8024149C 0040882D */   daddu    $s1, $v0, $zero
/* CF9010 802414A0 4600A502 */  mul.s     $f20, $f20, $f0
/* CF9014 802414A4 00000000 */  nop       
/* CF9018 802414A8 0240202D */  daddu     $a0, $s2, $zero
/* CF901C 802414AC 44910000 */  mtc1      $s1, $f0
/* CF9020 802414B0 00000000 */  nop       
/* CF9024 802414B4 46800020 */  cvt.s.w   $f0, $f0
/* CF9028 802414B8 46140001 */  sub.s     $f0, $f0, $f20
/* CF902C 802414BC 0280282D */  daddu     $a1, $s4, $zero
/* CF9030 802414C0 02173023 */  subu      $a2, $s0, $s7
/* CF9034 802414C4 4600010D */  trunc.w.s $f4, $f0
/* CF9038 802414C8 44102000 */  mfc1      $s0, $f4
/* CF903C 802414CC 0C0B2026 */  jal       set_variable
/* CF9040 802414D0 02168023 */   subu     $s0, $s0, $s6
/* CF9044 802414D4 0240202D */  daddu     $a0, $s2, $zero
/* CF9048 802414D8 02A0282D */  daddu     $a1, $s5, $zero
/* CF904C 802414DC 0C0B2026 */  jal       set_variable
/* CF9050 802414E0 0200302D */   daddu    $a2, $s0, $zero
/* CF9054 802414E4 8FBF0030 */  lw        $ra, 0x30($sp)
/* CF9058 802414E8 8FB7002C */  lw        $s7, 0x2c($sp)
/* CF905C 802414EC 8FB60028 */  lw        $s6, 0x28($sp)
/* CF9060 802414F0 8FB50024 */  lw        $s5, 0x24($sp)
/* CF9064 802414F4 8FB40020 */  lw        $s4, 0x20($sp)
/* CF9068 802414F8 8FB3001C */  lw        $s3, 0x1c($sp)
/* CF906C 802414FC 8FB20018 */  lw        $s2, 0x18($sp)
/* CF9070 80241500 8FB10014 */  lw        $s1, 0x14($sp)
/* CF9074 80241504 8FB00010 */  lw        $s0, 0x10($sp)
/* CF9078 80241508 D7B60040 */  ldc1      $f22, 0x40($sp)
/* CF907C 8024150C D7B40038 */  ldc1      $f20, 0x38($sp)
/* CF9080 80241510 24020002 */  addiu     $v0, $zero, 2
/* CF9084 80241514 03E00008 */  jr        $ra
/* CF9088 80241518 27BD0048 */   addiu    $sp, $sp, 0x48

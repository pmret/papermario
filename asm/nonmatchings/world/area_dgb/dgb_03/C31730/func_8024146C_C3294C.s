.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024146C_C3294C
/* C3294C 8024146C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C32950 80241470 AFB3003C */  sw        $s3, 0x3c($sp)
/* C32954 80241474 0080982D */  daddu     $s3, $a0, $zero
/* C32958 80241478 AFBF0040 */  sw        $ra, 0x40($sp)
/* C3295C 8024147C AFB20038 */  sw        $s2, 0x38($sp)
/* C32960 80241480 AFB10034 */  sw        $s1, 0x34($sp)
/* C32964 80241484 AFB00030 */  sw        $s0, 0x30($sp)
/* C32968 80241488 8E720148 */  lw        $s2, 0x148($s3)
/* C3296C 8024148C 00A0882D */  daddu     $s1, $a1, $zero
/* C32970 80241490 86440008 */  lh        $a0, 8($s2)
/* C32974 80241494 0C00EABB */  jal       get_npc_unsafe
/* C32978 80241498 00C0802D */   daddu    $s0, $a2, $zero
/* C3297C 8024149C 0200202D */  daddu     $a0, $s0, $zero
/* C32980 802414A0 0240282D */  daddu     $a1, $s2, $zero
/* C32984 802414A4 24030001 */  addiu     $v1, $zero, 1
/* C32988 802414A8 AFA30010 */  sw        $v1, 0x10($sp)
/* C3298C 802414AC 8E260024 */  lw        $a2, 0x24($s1)
/* C32990 802414B0 8E270028 */  lw        $a3, 0x28($s1)
/* C32994 802414B4 0C01242D */  jal       func_800490B4
/* C32998 802414B8 0040802D */   daddu    $s0, $v0, $zero
/* C3299C 802414BC 1440001E */  bnez      $v0, .L80241538
/* C329A0 802414C0 0200202D */   daddu    $a0, $s0, $zero
/* C329A4 802414C4 24040002 */  addiu     $a0, $zero, 2
/* C329A8 802414C8 0200282D */  daddu     $a1, $s0, $zero
/* C329AC 802414CC 0000302D */  daddu     $a2, $zero, $zero
/* C329B0 802414D0 860300A8 */  lh        $v1, 0xa8($s0)
/* C329B4 802414D4 3C013F80 */  lui       $at, 0x3f80
/* C329B8 802414D8 44810000 */  mtc1      $at, $f0
/* C329BC 802414DC 3C014000 */  lui       $at, 0x4000
/* C329C0 802414E0 44811000 */  mtc1      $at, $f2
/* C329C4 802414E4 3C01C1A0 */  lui       $at, 0xc1a0
/* C329C8 802414E8 44812000 */  mtc1      $at, $f4
/* C329CC 802414EC 2402000F */  addiu     $v0, $zero, 0xf
/* C329D0 802414F0 AFA2001C */  sw        $v0, 0x1c($sp)
/* C329D4 802414F4 44833000 */  mtc1      $v1, $f6
/* C329D8 802414F8 00000000 */  nop
/* C329DC 802414FC 468031A0 */  cvt.s.w   $f6, $f6
/* C329E0 80241500 44073000 */  mfc1      $a3, $f6
/* C329E4 80241504 27A20028 */  addiu     $v0, $sp, 0x28
/* C329E8 80241508 AFA20020 */  sw        $v0, 0x20($sp)
/* C329EC 8024150C E7A00010 */  swc1      $f0, 0x10($sp)
/* C329F0 80241510 E7A20014 */  swc1      $f2, 0x14($sp)
/* C329F4 80241514 0C01BFA4 */  jal       fx_emote
/* C329F8 80241518 E7A40018 */   swc1     $f4, 0x18($sp)
/* C329FC 8024151C 8E4200CC */  lw        $v0, 0xcc($s2)
/* C32A00 80241520 8C430000 */  lw        $v1, ($v0)
/* C32A04 80241524 24020019 */  addiu     $v0, $zero, 0x19
/* C32A08 80241528 A602008E */  sh        $v0, 0x8e($s0)
/* C32A0C 8024152C 2402000E */  addiu     $v0, $zero, 0xe
/* C32A10 80241530 0809055B */  j         .L8024156C
/* C32A14 80241534 AE030028 */   sw       $v1, 0x28($s0)
.L80241538:
/* C32A18 80241538 0C00F598 */  jal       func_8003D660
/* C32A1C 8024153C 24050001 */   addiu    $a1, $zero, 1
/* C32A20 80241540 8E050018 */  lw        $a1, 0x18($s0)
/* C32A24 80241544 8E06000C */  lw        $a2, 0xc($s0)
/* C32A28 80241548 0C00EA95 */  jal       npc_move_heading
/* C32A2C 8024154C 0200202D */   daddu    $a0, $s0, $zero
/* C32A30 80241550 8602008E */  lh        $v0, 0x8e($s0)
/* C32A34 80241554 9603008E */  lhu       $v1, 0x8e($s0)
/* C32A38 80241558 18400003 */  blez      $v0, .L80241568
/* C32A3C 8024155C 2462FFFF */   addiu    $v0, $v1, -1
/* C32A40 80241560 0809055C */  j         .L80241570
/* C32A44 80241564 A602008E */   sh       $v0, 0x8e($s0)
.L80241568:
/* C32A48 80241568 2402000C */  addiu     $v0, $zero, 0xc
.L8024156C:
/* C32A4C 8024156C AE620070 */  sw        $v0, 0x70($s3)
.L80241570:
/* C32A50 80241570 8FBF0040 */  lw        $ra, 0x40($sp)
/* C32A54 80241574 8FB3003C */  lw        $s3, 0x3c($sp)
/* C32A58 80241578 8FB20038 */  lw        $s2, 0x38($sp)
/* C32A5C 8024157C 8FB10034 */  lw        $s1, 0x34($sp)
/* C32A60 80241580 8FB00030 */  lw        $s0, 0x30($sp)
/* C32A64 80241584 03E00008 */  jr        $ra
/* C32A68 80241588 27BD0048 */   addiu    $sp, $sp, 0x48

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241480
/* 801D00 80241480 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 801D04 80241484 AFB3001C */  sw        $s3, 0x1c($sp)
/* 801D08 80241488 0080982D */  daddu     $s3, $a0, $zero
/* 801D0C 8024148C AFBF0020 */  sw        $ra, 0x20($sp)
/* 801D10 80241490 AFB20018 */  sw        $s2, 0x18($sp)
/* 801D14 80241494 AFB10014 */  sw        $s1, 0x14($sp)
/* 801D18 80241498 AFB00010 */  sw        $s0, 0x10($sp)
/* 801D1C 8024149C 8E720148 */  lw        $s2, 0x148($s3)
/* 801D20 802414A0 86440008 */  lh        $a0, 8($s2)
/* 801D24 802414A4 0C00EABB */  jal       get_npc_unsafe
/* 801D28 802414A8 00A0882D */   daddu    $s1, $a1, $zero
/* 801D2C 802414AC 8E240008 */  lw        $a0, 8($s1)
/* 801D30 802414B0 0040802D */  daddu     $s0, $v0, $zero
/* 801D34 802414B4 00041FC2 */  srl       $v1, $a0, 0x1f
/* 801D38 802414B8 00832021 */  addu      $a0, $a0, $v1
/* 801D3C 802414BC 00042043 */  sra       $a0, $a0, 1
/* 801D40 802414C0 0C00A67F */  jal       rand_int
/* 801D44 802414C4 24840001 */   addiu    $a0, $a0, 1
/* 801D48 802414C8 8E230008 */  lw        $v1, 8($s1)
/* 801D4C 802414CC 240400B4 */  addiu     $a0, $zero, 0xb4
/* 801D50 802414D0 00032FC2 */  srl       $a1, $v1, 0x1f
/* 801D54 802414D4 00651821 */  addu      $v1, $v1, $a1
/* 801D58 802414D8 00031843 */  sra       $v1, $v1, 1
/* 801D5C 802414DC 00621821 */  addu      $v1, $v1, $v0
/* 801D60 802414E0 0C00A67F */  jal       rand_int
/* 801D64 802414E4 A603008E */   sh       $v1, 0x8e($s0)
/* 801D68 802414E8 C60C000C */  lwc1      $f12, 0xc($s0)
/* 801D6C 802414EC 44820000 */  mtc1      $v0, $f0
/* 801D70 802414F0 00000000 */  nop       
/* 801D74 802414F4 46800020 */  cvt.s.w   $f0, $f0
/* 801D78 802414F8 46006300 */  add.s     $f12, $f12, $f0
/* 801D7C 802414FC 3C0142B4 */  lui       $at, 0x42b4
/* 801D80 80241500 44810000 */  mtc1      $at, $f0
/* 801D84 80241504 0C00A6C9 */  jal       clamp_angle
/* 801D88 80241508 46006301 */   sub.s    $f12, $f12, $f0
/* 801D8C 8024150C E600000C */  swc1      $f0, 0xc($s0)
/* 801D90 80241510 8E4200CC */  lw        $v0, 0xcc($s2)
/* 801D94 80241514 8C420000 */  lw        $v0, ($v0)
/* 801D98 80241518 AE020028 */  sw        $v0, 0x28($s0)
/* 801D9C 8024151C 24020003 */  addiu     $v0, $zero, 3
/* 801DA0 80241520 AE620070 */  sw        $v0, 0x70($s3)
/* 801DA4 80241524 8FBF0020 */  lw        $ra, 0x20($sp)
/* 801DA8 80241528 8FB3001C */  lw        $s3, 0x1c($sp)
/* 801DAC 8024152C 8FB20018 */  lw        $s2, 0x18($sp)
/* 801DB0 80241530 8FB10014 */  lw        $s1, 0x14($sp)
/* 801DB4 80241534 8FB00010 */  lw        $s0, 0x10($sp)
/* 801DB8 80241538 03E00008 */  jr        $ra
/* 801DBC 8024153C 27BD0028 */   addiu    $sp, $sp, 0x28

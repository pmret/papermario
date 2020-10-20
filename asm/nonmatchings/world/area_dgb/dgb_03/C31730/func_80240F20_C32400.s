.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F20_C32400
/* C32400 80240F20 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C32404 80240F24 AFB3001C */  sw        $s3, 0x1c($sp)
/* C32408 80240F28 0080982D */  daddu     $s3, $a0, $zero
/* C3240C 80240F2C AFBF0020 */  sw        $ra, 0x20($sp)
/* C32410 80240F30 AFB20018 */  sw        $s2, 0x18($sp)
/* C32414 80240F34 AFB10014 */  sw        $s1, 0x14($sp)
/* C32418 80240F38 AFB00010 */  sw        $s0, 0x10($sp)
/* C3241C 80240F3C 8E720148 */  lw        $s2, 0x148($s3)
/* C32420 80240F40 86440008 */  lh        $a0, 8($s2)
/* C32424 80240F44 0C00EABB */  jal       get_npc_unsafe
/* C32428 80240F48 00A0882D */   daddu    $s1, $a1, $zero
/* C3242C 80240F4C 8E240008 */  lw        $a0, 8($s1)
/* C32430 80240F50 0040802D */  daddu     $s0, $v0, $zero
/* C32434 80240F54 00041FC2 */  srl       $v1, $a0, 0x1f
/* C32438 80240F58 00832021 */  addu      $a0, $a0, $v1
/* C3243C 80240F5C 00042043 */  sra       $a0, $a0, 1
/* C32440 80240F60 0C00A67F */  jal       rand_int
/* C32444 80240F64 24840001 */   addiu    $a0, $a0, 1
/* C32448 80240F68 8E230008 */  lw        $v1, 8($s1)
/* C3244C 80240F6C 240400B4 */  addiu     $a0, $zero, 0xb4
/* C32450 80240F70 00032FC2 */  srl       $a1, $v1, 0x1f
/* C32454 80240F74 00651821 */  addu      $v1, $v1, $a1
/* C32458 80240F78 00031843 */  sra       $v1, $v1, 1
/* C3245C 80240F7C 00621821 */  addu      $v1, $v1, $v0
/* C32460 80240F80 0C00A67F */  jal       rand_int
/* C32464 80240F84 A603008E */   sh       $v1, 0x8e($s0)
/* C32468 80240F88 C60C000C */  lwc1      $f12, 0xc($s0)
/* C3246C 80240F8C 44820000 */  mtc1      $v0, $f0
/* C32470 80240F90 00000000 */  nop       
/* C32474 80240F94 46800020 */  cvt.s.w   $f0, $f0
/* C32478 80240F98 46006300 */  add.s     $f12, $f12, $f0
/* C3247C 80240F9C 3C0142B4 */  lui       $at, 0x42b4
/* C32480 80240FA0 44810000 */  mtc1      $at, $f0
/* C32484 80240FA4 0C00A6C9 */  jal       clamp_angle
/* C32488 80240FA8 46006301 */   sub.s    $f12, $f12, $f0
/* C3248C 80240FAC E600000C */  swc1      $f0, 0xc($s0)
/* C32490 80240FB0 8E4200CC */  lw        $v0, 0xcc($s2)
/* C32494 80240FB4 8C420000 */  lw        $v0, ($v0)
/* C32498 80240FB8 AE020028 */  sw        $v0, 0x28($s0)
/* C3249C 80240FBC 24020003 */  addiu     $v0, $zero, 3
/* C324A0 80240FC0 AE620070 */  sw        $v0, 0x70($s3)
/* C324A4 80240FC4 8FBF0020 */  lw        $ra, 0x20($sp)
/* C324A8 80240FC8 8FB3001C */  lw        $s3, 0x1c($sp)
/* C324AC 80240FCC 8FB20018 */  lw        $s2, 0x18($sp)
/* C324B0 80240FD0 8FB10014 */  lw        $s1, 0x14($sp)
/* C324B4 80240FD4 8FB00010 */  lw        $s0, 0x10($sp)
/* C324B8 80240FD8 03E00008 */  jr        $ra
/* C324BC 80240FDC 27BD0028 */   addiu    $sp, $sp, 0x28

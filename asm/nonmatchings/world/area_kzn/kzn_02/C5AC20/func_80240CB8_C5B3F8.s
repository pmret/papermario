.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CB8_C5B3F8
/* C5B3F8 80240CB8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C5B3FC 80240CBC AFB3001C */  sw        $s3, 0x1c($sp)
/* C5B400 80240CC0 0080982D */  daddu     $s3, $a0, $zero
/* C5B404 80240CC4 AFBF0020 */  sw        $ra, 0x20($sp)
/* C5B408 80240CC8 AFB20018 */  sw        $s2, 0x18($sp)
/* C5B40C 80240CCC AFB10014 */  sw        $s1, 0x14($sp)
/* C5B410 80240CD0 AFB00010 */  sw        $s0, 0x10($sp)
/* C5B414 80240CD4 8E720148 */  lw        $s2, 0x148($s3)
/* C5B418 80240CD8 86440008 */  lh        $a0, 8($s2)
/* C5B41C 80240CDC 0C00EABB */  jal       get_npc_unsafe
/* C5B420 80240CE0 00A0882D */   daddu    $s1, $a1, $zero
/* C5B424 80240CE4 8E240008 */  lw        $a0, 8($s1)
/* C5B428 80240CE8 0040802D */  daddu     $s0, $v0, $zero
/* C5B42C 80240CEC 00041FC2 */  srl       $v1, $a0, 0x1f
/* C5B430 80240CF0 00832021 */  addu      $a0, $a0, $v1
/* C5B434 80240CF4 00042043 */  sra       $a0, $a0, 1
/* C5B438 80240CF8 0C00A67F */  jal       rand_int
/* C5B43C 80240CFC 24840001 */   addiu    $a0, $a0, 1
/* C5B440 80240D00 8E230008 */  lw        $v1, 8($s1)
/* C5B444 80240D04 240400B4 */  addiu     $a0, $zero, 0xb4
/* C5B448 80240D08 00032FC2 */  srl       $a1, $v1, 0x1f
/* C5B44C 80240D0C 00651821 */  addu      $v1, $v1, $a1
/* C5B450 80240D10 00031843 */  sra       $v1, $v1, 1
/* C5B454 80240D14 00621821 */  addu      $v1, $v1, $v0
/* C5B458 80240D18 0C00A67F */  jal       rand_int
/* C5B45C 80240D1C A603008E */   sh       $v1, 0x8e($s0)
/* C5B460 80240D20 C60C000C */  lwc1      $f12, 0xc($s0)
/* C5B464 80240D24 44820000 */  mtc1      $v0, $f0
/* C5B468 80240D28 00000000 */  nop       
/* C5B46C 80240D2C 46800020 */  cvt.s.w   $f0, $f0
/* C5B470 80240D30 46006300 */  add.s     $f12, $f12, $f0
/* C5B474 80240D34 3C0142B4 */  lui       $at, 0x42b4
/* C5B478 80240D38 44810000 */  mtc1      $at, $f0
/* C5B47C 80240D3C 0C00A6C9 */  jal       clamp_angle
/* C5B480 80240D40 46006301 */   sub.s    $f12, $f12, $f0
/* C5B484 80240D44 E600000C */  swc1      $f0, 0xc($s0)
/* C5B488 80240D48 8E4200CC */  lw        $v0, 0xcc($s2)
/* C5B48C 80240D4C 8C420000 */  lw        $v0, ($v0)
/* C5B490 80240D50 AE020028 */  sw        $v0, 0x28($s0)
/* C5B494 80240D54 24020003 */  addiu     $v0, $zero, 3
/* C5B498 80240D58 AE620070 */  sw        $v0, 0x70($s3)
/* C5B49C 80240D5C 8FBF0020 */  lw        $ra, 0x20($sp)
/* C5B4A0 80240D60 8FB3001C */  lw        $s3, 0x1c($sp)
/* C5B4A4 80240D64 8FB20018 */  lw        $s2, 0x18($sp)
/* C5B4A8 80240D68 8FB10014 */  lw        $s1, 0x14($sp)
/* C5B4AC 80240D6C 8FB00010 */  lw        $s0, 0x10($sp)
/* C5B4B0 80240D70 03E00008 */  jr        $ra
/* C5B4B4 80240D74 27BD0028 */   addiu    $sp, $sp, 0x28

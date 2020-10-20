.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F38_C41CE8
/* C41CE8 80241F38 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* C41CEC 80241F3C AFB3001C */  sw        $s3, 0x1c($sp)
/* C41CF0 80241F40 0080982D */  daddu     $s3, $a0, $zero
/* C41CF4 80241F44 AFBF0020 */  sw        $ra, 0x20($sp)
/* C41CF8 80241F48 AFB20018 */  sw        $s2, 0x18($sp)
/* C41CFC 80241F4C AFB10014 */  sw        $s1, 0x14($sp)
/* C41D00 80241F50 AFB00010 */  sw        $s0, 0x10($sp)
/* C41D04 80241F54 8E720148 */  lw        $s2, 0x148($s3)
/* C41D08 80241F58 86440008 */  lh        $a0, 8($s2)
/* C41D0C 80241F5C 0C00EABB */  jal       get_npc_unsafe
/* C41D10 80241F60 00A0882D */   daddu    $s1, $a1, $zero
/* C41D14 80241F64 8E240008 */  lw        $a0, 8($s1)
/* C41D18 80241F68 0040802D */  daddu     $s0, $v0, $zero
/* C41D1C 80241F6C 00041FC2 */  srl       $v1, $a0, 0x1f
/* C41D20 80241F70 00832021 */  addu      $a0, $a0, $v1
/* C41D24 80241F74 00042043 */  sra       $a0, $a0, 1
/* C41D28 80241F78 0C00A67F */  jal       rand_int
/* C41D2C 80241F7C 24840001 */   addiu    $a0, $a0, 1
/* C41D30 80241F80 8E230008 */  lw        $v1, 8($s1)
/* C41D34 80241F84 240400B4 */  addiu     $a0, $zero, 0xb4
/* C41D38 80241F88 00032FC2 */  srl       $a1, $v1, 0x1f
/* C41D3C 80241F8C 00651821 */  addu      $v1, $v1, $a1
/* C41D40 80241F90 00031843 */  sra       $v1, $v1, 1
/* C41D44 80241F94 00621821 */  addu      $v1, $v1, $v0
/* C41D48 80241F98 0C00A67F */  jal       rand_int
/* C41D4C 80241F9C A603008E */   sh       $v1, 0x8e($s0)
/* C41D50 80241FA0 C60C000C */  lwc1      $f12, 0xc($s0)
/* C41D54 80241FA4 44820000 */  mtc1      $v0, $f0
/* C41D58 80241FA8 00000000 */  nop       
/* C41D5C 80241FAC 46800020 */  cvt.s.w   $f0, $f0
/* C41D60 80241FB0 46006300 */  add.s     $f12, $f12, $f0
/* C41D64 80241FB4 3C0142B4 */  lui       $at, 0x42b4
/* C41D68 80241FB8 44810000 */  mtc1      $at, $f0
/* C41D6C 80241FBC 0C00A6C9 */  jal       clamp_angle
/* C41D70 80241FC0 46006301 */   sub.s    $f12, $f12, $f0
/* C41D74 80241FC4 E600000C */  swc1      $f0, 0xc($s0)
/* C41D78 80241FC8 8E4200CC */  lw        $v0, 0xcc($s2)
/* C41D7C 80241FCC 8C420000 */  lw        $v0, ($v0)
/* C41D80 80241FD0 AE020028 */  sw        $v0, 0x28($s0)
/* C41D84 80241FD4 24020003 */  addiu     $v0, $zero, 3
/* C41D88 80241FD8 AE620070 */  sw        $v0, 0x70($s3)
/* C41D8C 80241FDC 8FBF0020 */  lw        $ra, 0x20($sp)
/* C41D90 80241FE0 8FB3001C */  lw        $s3, 0x1c($sp)
/* C41D94 80241FE4 8FB20018 */  lw        $s2, 0x18($sp)
/* C41D98 80241FE8 8FB10014 */  lw        $s1, 0x14($sp)
/* C41D9C 80241FEC 8FB00010 */  lw        $s0, 0x10($sp)
/* C41DA0 80241FF0 03E00008 */  jr        $ra
/* C41DA4 80241FF4 27BD0028 */   addiu    $sp, $sp, 0x28

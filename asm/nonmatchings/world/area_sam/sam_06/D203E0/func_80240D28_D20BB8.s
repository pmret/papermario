.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D28_D20BB8
/* D20BB8 80240D28 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D20BBC 80240D2C AFB3001C */  sw        $s3, 0x1c($sp)
/* D20BC0 80240D30 0080982D */  daddu     $s3, $a0, $zero
/* D20BC4 80240D34 AFBF0020 */  sw        $ra, 0x20($sp)
/* D20BC8 80240D38 AFB20018 */  sw        $s2, 0x18($sp)
/* D20BCC 80240D3C AFB10014 */  sw        $s1, 0x14($sp)
/* D20BD0 80240D40 AFB00010 */  sw        $s0, 0x10($sp)
/* D20BD4 80240D44 8E720148 */  lw        $s2, 0x148($s3)
/* D20BD8 80240D48 86440008 */  lh        $a0, 8($s2)
/* D20BDC 80240D4C 0C00EABB */  jal       get_npc_unsafe
/* D20BE0 80240D50 00A0882D */   daddu    $s1, $a1, $zero
/* D20BE4 80240D54 8E240008 */  lw        $a0, 8($s1)
/* D20BE8 80240D58 0040802D */  daddu     $s0, $v0, $zero
/* D20BEC 80240D5C 00041FC2 */  srl       $v1, $a0, 0x1f
/* D20BF0 80240D60 00832021 */  addu      $a0, $a0, $v1
/* D20BF4 80240D64 00042043 */  sra       $a0, $a0, 1
/* D20BF8 80240D68 0C00A67F */  jal       rand_int
/* D20BFC 80240D6C 24840001 */   addiu    $a0, $a0, 1
/* D20C00 80240D70 8E230008 */  lw        $v1, 8($s1)
/* D20C04 80240D74 240400B4 */  addiu     $a0, $zero, 0xb4
/* D20C08 80240D78 00032FC2 */  srl       $a1, $v1, 0x1f
/* D20C0C 80240D7C 00651821 */  addu      $v1, $v1, $a1
/* D20C10 80240D80 00031843 */  sra       $v1, $v1, 1
/* D20C14 80240D84 00621821 */  addu      $v1, $v1, $v0
/* D20C18 80240D88 0C00A67F */  jal       rand_int
/* D20C1C 80240D8C A603008E */   sh       $v1, 0x8e($s0)
/* D20C20 80240D90 C60C000C */  lwc1      $f12, 0xc($s0)
/* D20C24 80240D94 44820000 */  mtc1      $v0, $f0
/* D20C28 80240D98 00000000 */  nop       
/* D20C2C 80240D9C 46800020 */  cvt.s.w   $f0, $f0
/* D20C30 80240DA0 46006300 */  add.s     $f12, $f12, $f0
/* D20C34 80240DA4 3C0142B4 */  lui       $at, 0x42b4
/* D20C38 80240DA8 44810000 */  mtc1      $at, $f0
/* D20C3C 80240DAC 0C00A6C9 */  jal       clamp_angle
/* D20C40 80240DB0 46006301 */   sub.s    $f12, $f12, $f0
/* D20C44 80240DB4 E600000C */  swc1      $f0, 0xc($s0)
/* D20C48 80240DB8 8E4200CC */  lw        $v0, 0xcc($s2)
/* D20C4C 80240DBC 8C420000 */  lw        $v0, ($v0)
/* D20C50 80240DC0 AE020028 */  sw        $v0, 0x28($s0)
/* D20C54 80240DC4 24020003 */  addiu     $v0, $zero, 3
/* D20C58 80240DC8 AE620070 */  sw        $v0, 0x70($s3)
/* D20C5C 80240DCC 8FBF0020 */  lw        $ra, 0x20($sp)
/* D20C60 80240DD0 8FB3001C */  lw        $s3, 0x1c($sp)
/* D20C64 80240DD4 8FB20018 */  lw        $s2, 0x18($sp)
/* D20C68 80240DD8 8FB10014 */  lw        $s1, 0x14($sp)
/* D20C6C 80240DDC 8FB00010 */  lw        $s0, 0x10($sp)
/* D20C70 80240DE0 03E00008 */  jr        $ra
/* D20C74 80240DE4 27BD0028 */   addiu    $sp, $sp, 0x28

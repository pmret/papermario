.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_80049B44
/* 024F44 80049B44 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 024F48 80049B48 AFB3001C */  sw    $s3, 0x1c($sp)
/* 024F4C 80049B4C 0080982D */  daddu $s3, $a0, $zero
/* 024F50 80049B50 AFBF0020 */  sw    $ra, 0x20($sp)
/* 024F54 80049B54 AFB20018 */  sw    $s2, 0x18($sp)
/* 024F58 80049B58 AFB10014 */  sw    $s1, 0x14($sp)
/* 024F5C 80049B5C AFB00010 */  sw    $s0, 0x10($sp)
/* 024F60 80049B60 8E720148 */  lw    $s2, 0x148($s3)
/* 024F64 80049B64 86440008 */  lh    $a0, 8($s2)
/* 024F68 80049B68 0C00EABB */  jal   get_npc_unsafe
/* 024F6C 80049B6C 00A0882D */   daddu $s1, $a1, $zero
/* 024F70 80049B70 8E240008 */  lw    $a0, 8($s1)
/* 024F74 80049B74 0040802D */  daddu $s0, $v0, $zero
/* 024F78 80049B78 00041FC2 */  srl   $v1, $a0, 0x1f
/* 024F7C 80049B7C 00832021 */  addu  $a0, $a0, $v1
/* 024F80 80049B80 00042043 */  sra   $a0, $a0, 1
/* 024F84 80049B84 0C00A67F */  jal   rand_int
/* 024F88 80049B88 24840001 */   addiu $a0, $a0, 1
/* 024F8C 80049B8C 8E230008 */  lw    $v1, 8($s1)
/* 024F90 80049B90 240400B4 */  addiu $a0, $zero, 0xb4
/* 024F94 80049B94 00032FC2 */  srl   $a1, $v1, 0x1f
/* 024F98 80049B98 00651821 */  addu  $v1, $v1, $a1
/* 024F9C 80049B9C 00031843 */  sra   $v1, $v1, 1
/* 024FA0 80049BA0 00621821 */  addu  $v1, $v1, $v0
/* 024FA4 80049BA4 0C00A67F */  jal   rand_int
/* 024FA8 80049BA8 A603008E */   sh    $v1, 0x8e($s0)
/* 024FAC 80049BAC C60C000C */  lwc1  $f12, 0xc($s0)
/* 024FB0 80049BB0 44820000 */  mtc1  $v0, $f0
/* 024FB4 80049BB4 00000000 */  nop   
/* 024FB8 80049BB8 46800020 */  cvt.s.w $f0, $f0
/* 024FBC 80049BBC 46006300 */  add.s $f12, $f12, $f0
/* 024FC0 80049BC0 3C0142B4 */  lui   $at, 0x42b4
/* 024FC4 80049BC4 44810000 */  mtc1  $at, $f0
/* 024FC8 80049BC8 0C00A6C9 */  jal   clamp_angle
/* 024FCC 80049BCC 46006301 */   sub.s $f12, $f12, $f0
/* 024FD0 80049BD0 E600000C */  swc1  $f0, 0xc($s0)
/* 024FD4 80049BD4 8E4200CC */  lw    $v0, 0xcc($s2)
/* 024FD8 80049BD8 8C420000 */  lw    $v0, ($v0)
/* 024FDC 80049BDC AE020028 */  sw    $v0, 0x28($s0)
/* 024FE0 80049BE0 24020003 */  addiu $v0, $zero, 3
/* 024FE4 80049BE4 AE620070 */  sw    $v0, 0x70($s3)
/* 024FE8 80049BE8 8FBF0020 */  lw    $ra, 0x20($sp)
/* 024FEC 80049BEC 8FB3001C */  lw    $s3, 0x1c($sp)
/* 024FF0 80049BF0 8FB20018 */  lw    $s2, 0x18($sp)
/* 024FF4 80049BF4 8FB10014 */  lw    $s1, 0x14($sp)
/* 024FF8 80049BF8 8FB00010 */  lw    $s0, 0x10($sp)
/* 024FFC 80049BFC 03E00008 */  jr    $ra
/* 025000 80049C00 27BD0028 */   addiu $sp, $sp, 0x28


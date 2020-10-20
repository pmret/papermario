.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FAC_9F59EC
/* 9F59EC 80240FAC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9F59F0 80240FB0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9F59F4 80240FB4 0080982D */  daddu     $s3, $a0, $zero
/* 9F59F8 80240FB8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9F59FC 80240FBC AFB20018 */  sw        $s2, 0x18($sp)
/* 9F5A00 80240FC0 AFB10014 */  sw        $s1, 0x14($sp)
/* 9F5A04 80240FC4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9F5A08 80240FC8 8E720148 */  lw        $s2, 0x148($s3)
/* 9F5A0C 80240FCC 86440008 */  lh        $a0, 8($s2)
/* 9F5A10 80240FD0 0C00EABB */  jal       get_npc_unsafe
/* 9F5A14 80240FD4 00A0882D */   daddu    $s1, $a1, $zero
/* 9F5A18 80240FD8 8E240008 */  lw        $a0, 8($s1)
/* 9F5A1C 80240FDC 0040802D */  daddu     $s0, $v0, $zero
/* 9F5A20 80240FE0 00041FC2 */  srl       $v1, $a0, 0x1f
/* 9F5A24 80240FE4 00832021 */  addu      $a0, $a0, $v1
/* 9F5A28 80240FE8 00042043 */  sra       $a0, $a0, 1
/* 9F5A2C 80240FEC 0C00A67F */  jal       rand_int
/* 9F5A30 80240FF0 24840001 */   addiu    $a0, $a0, 1
/* 9F5A34 80240FF4 8E230008 */  lw        $v1, 8($s1)
/* 9F5A38 80240FF8 240400B4 */  addiu     $a0, $zero, 0xb4
/* 9F5A3C 80240FFC 00032FC2 */  srl       $a1, $v1, 0x1f
/* 9F5A40 80241000 00651821 */  addu      $v1, $v1, $a1
/* 9F5A44 80241004 00031843 */  sra       $v1, $v1, 1
/* 9F5A48 80241008 00621821 */  addu      $v1, $v1, $v0
/* 9F5A4C 8024100C 0C00A67F */  jal       rand_int
/* 9F5A50 80241010 A603008E */   sh       $v1, 0x8e($s0)
/* 9F5A54 80241014 C60C000C */  lwc1      $f12, 0xc($s0)
/* 9F5A58 80241018 44820000 */  mtc1      $v0, $f0
/* 9F5A5C 8024101C 00000000 */  nop       
/* 9F5A60 80241020 46800020 */  cvt.s.w   $f0, $f0
/* 9F5A64 80241024 46006300 */  add.s     $f12, $f12, $f0
/* 9F5A68 80241028 3C0142B4 */  lui       $at, 0x42b4
/* 9F5A6C 8024102C 44810000 */  mtc1      $at, $f0
/* 9F5A70 80241030 0C00A6C9 */  jal       clamp_angle
/* 9F5A74 80241034 46006301 */   sub.s    $f12, $f12, $f0
/* 9F5A78 80241038 E600000C */  swc1      $f0, 0xc($s0)
/* 9F5A7C 8024103C 8E4200CC */  lw        $v0, 0xcc($s2)
/* 9F5A80 80241040 8C420000 */  lw        $v0, ($v0)
/* 9F5A84 80241044 AE020028 */  sw        $v0, 0x28($s0)
/* 9F5A88 80241048 24020003 */  addiu     $v0, $zero, 3
/* 9F5A8C 8024104C AE620070 */  sw        $v0, 0x70($s3)
/* 9F5A90 80241050 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9F5A94 80241054 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9F5A98 80241058 8FB20018 */  lw        $s2, 0x18($sp)
/* 9F5A9C 8024105C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9F5AA0 80241060 8FB00010 */  lw        $s0, 0x10($sp)
/* 9F5AA4 80241064 03E00008 */  jr        $ra
/* 9F5AA8 80241068 27BD0028 */   addiu    $sp, $sp, 0x28

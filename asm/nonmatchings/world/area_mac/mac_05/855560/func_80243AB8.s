.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243AB8
/* 855C28 80243AB8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 855C2C 80243ABC AFB10014 */  sw        $s1, 0x14($sp)
/* 855C30 80243AC0 0080882D */  daddu     $s1, $a0, $zero
/* 855C34 80243AC4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 855C38 80243AC8 AFB00010 */  sw        $s0, 0x10($sp)
/* 855C3C 80243ACC F7B80030 */  sdc1      $f24, 0x30($sp)
/* 855C40 80243AD0 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 855C44 80243AD4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 855C48 80243AD8 0C00EAD2 */  jal       get_npc_safe
/* 855C4C 80243ADC 0000202D */   daddu    $a0, $zero, $zero
/* 855C50 80243AE0 0040802D */  daddu     $s0, $v0, $zero
/* 855C54 80243AE4 C614000C */  lwc1      $f20, 0xc($s0)
/* 855C58 80243AE8 3C01428C */  lui       $at, 0x428c
/* 855C5C 80243AEC 4481C000 */  mtc1      $at, $f24
/* 855C60 80243AF0 4600A507 */  neg.s     $f20, $f20
/* 855C64 80243AF4 0C00A8BB */  jal       sin_deg
/* 855C68 80243AF8 4600A306 */   mov.s    $f12, $f20
/* 855C6C 80243AFC 46180002 */  mul.s     $f0, $f0, $f24
/* 855C70 80243B00 00000000 */  nop       
/* 855C74 80243B04 C6160038 */  lwc1      $f22, 0x38($s0)
/* 855C78 80243B08 3C0141F0 */  lui       $at, 0x41f0
/* 855C7C 80243B0C 44811000 */  mtc1      $at, $f2
/* 855C80 80243B10 00000000 */  nop       
/* 855C84 80243B14 4602B580 */  add.s     $f22, $f22, $f2
/* 855C88 80243B18 4600A306 */  mov.s     $f12, $f20
/* 855C8C 80243B1C 0C00A8D4 */  jal       cos_deg
/* 855C90 80243B20 4600B580 */   add.s    $f22, $f22, $f0
/* 855C94 80243B24 0220202D */  daddu     $a0, $s1, $zero
/* 855C98 80243B28 46180002 */  mul.s     $f0, $f0, $f24
/* 855C9C 80243B2C 00000000 */  nop       
/* 855CA0 80243B30 3C05FE36 */  lui       $a1, 0xfe36
/* 855CA4 80243B34 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 855CA8 80243B38 C6180040 */  lwc1      $f24, 0x40($s0)
/* 855CAC 80243B3C C614003C */  lwc1      $f20, 0x3c($s0)
/* 855CB0 80243B40 4600C600 */  add.s     $f24, $f24, $f0
/* 855CB4 80243B44 3C014248 */  lui       $at, 0x4248
/* 855CB8 80243B48 44810000 */  mtc1      $at, $f0
/* 855CBC 80243B4C 4406B000 */  mfc1      $a2, $f22
/* 855CC0 80243B50 0C0B2190 */  jal       set_float_variable
/* 855CC4 80243B54 4600A500 */   add.s    $f20, $f20, $f0
/* 855CC8 80243B58 0220202D */  daddu     $a0, $s1, $zero
/* 855CCC 80243B5C 3C05FE36 */  lui       $a1, 0xfe36
/* 855CD0 80243B60 4406A000 */  mfc1      $a2, $f20
/* 855CD4 80243B64 0C0B2190 */  jal       set_float_variable
/* 855CD8 80243B68 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 855CDC 80243B6C 0220202D */  daddu     $a0, $s1, $zero
/* 855CE0 80243B70 3C05FE36 */  lui       $a1, 0xfe36
/* 855CE4 80243B74 4406C000 */  mfc1      $a2, $f24
/* 855CE8 80243B78 0C0B2190 */  jal       set_float_variable
/* 855CEC 80243B7C 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 855CF0 80243B80 8FBF0018 */  lw        $ra, 0x18($sp)
/* 855CF4 80243B84 8FB10014 */  lw        $s1, 0x14($sp)
/* 855CF8 80243B88 8FB00010 */  lw        $s0, 0x10($sp)
/* 855CFC 80243B8C D7B80030 */  ldc1      $f24, 0x30($sp)
/* 855D00 80243B90 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 855D04 80243B94 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 855D08 80243B98 24020002 */  addiu     $v0, $zero, 2
/* 855D0C 80243B9C 03E00008 */  jr        $ra
/* 855D10 80243BA0 27BD0038 */   addiu    $sp, $sp, 0x38

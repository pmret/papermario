.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FF0_7ECD00
/* 7ECD00 80241FF0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7ECD04 80241FF4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 7ECD08 80241FF8 0080982D */  daddu     $s3, $a0, $zero
/* 7ECD0C 80241FFC AFB20018 */  sw        $s2, 0x18($sp)
/* 7ECD10 80242000 0000902D */  daddu     $s2, $zero, $zero
/* 7ECD14 80242004 AFB10014 */  sw        $s1, 0x14($sp)
/* 7ECD18 80242008 0240882D */  daddu     $s1, $s2, $zero
/* 7ECD1C 8024200C AFB00010 */  sw        $s0, 0x10($sp)
/* 7ECD20 80242010 3C108025 */  lui       $s0, %hi(D_80248F28)
/* 7ECD24 80242014 26108F28 */  addiu     $s0, $s0, %lo(D_80248F28)
/* 7ECD28 80242018 AFBF0020 */  sw        $ra, 0x20($sp)
.L8024201C:
/* 7ECD2C 8024201C 8E05FFF8 */  lw        $a1, -8($s0)
/* 7ECD30 80242020 0C0B1EAF */  jal       get_variable
/* 7ECD34 80242024 0260202D */   daddu    $a0, $s3, $zero
/* 7ECD38 80242028 50400007 */  beql      $v0, $zero, .L80242048
/* 7ECD3C 8024202C 26310001 */   addiu    $s1, $s1, 1
/* 7ECD40 80242030 8E050000 */  lw        $a1, ($s0)
/* 7ECD44 80242034 0C0B1EAF */  jal       get_variable
/* 7ECD48 80242038 0260202D */   daddu    $a0, $s3, $zero
/* 7ECD4C 8024203C 50400001 */  beql      $v0, $zero, .L80242044
/* 7ECD50 80242040 26520001 */   addiu    $s2, $s2, 1
.L80242044:
/* 7ECD54 80242044 26310001 */  addiu     $s1, $s1, 1
.L80242048:
/* 7ECD58 80242048 2E220024 */  sltiu     $v0, $s1, 0x24
/* 7ECD5C 8024204C 1440FFF3 */  bnez      $v0, .L8024201C
/* 7ECD60 80242050 26100014 */   addiu    $s0, $s0, 0x14
/* 7ECD64 80242054 AE720084 */  sw        $s2, 0x84($s3)
/* 7ECD68 80242058 8FBF0020 */  lw        $ra, 0x20($sp)
/* 7ECD6C 8024205C 8FB3001C */  lw        $s3, 0x1c($sp)
/* 7ECD70 80242060 8FB20018 */  lw        $s2, 0x18($sp)
/* 7ECD74 80242064 8FB10014 */  lw        $s1, 0x14($sp)
/* 7ECD78 80242068 8FB00010 */  lw        $s0, 0x10($sp)
/* 7ECD7C 8024206C 24020002 */  addiu     $v0, $zero, 2
/* 7ECD80 80242070 03E00008 */  jr        $ra
/* 7ECD84 80242074 27BD0028 */   addiu    $sp, $sp, 0x28

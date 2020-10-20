.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242030
/* 8EDE50 80242030 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8EDE54 80242034 2404010D */  addiu     $a0, $zero, 0x10d
/* 8EDE58 80242038 2405FFFF */  addiu     $a1, $zero, -1
/* 8EDE5C 8024203C 0000302D */  daddu     $a2, $zero, $zero
/* 8EDE60 80242040 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8EDE64 80242044 0C046E54 */  jal       func_8011B950
/* 8EDE68 80242048 24070001 */   addiu    $a3, $zero, 1
/* 8EDE6C 8024204C 0000202D */  daddu     $a0, $zero, $zero
/* 8EDE70 80242050 0080282D */  daddu     $a1, $a0, $zero
/* 8EDE74 80242054 0080302D */  daddu     $a2, $a0, $zero
/* 8EDE78 80242058 0C046F97 */  jal       set_background_color_blend
/* 8EDE7C 8024205C 0080382D */   daddu    $a3, $a0, $zero
/* 8EDE80 80242060 3C02800B */  lui       $v0, %hi(gCameras)
/* 8EDE84 80242064 24421D80 */  addiu     $v0, $v0, %lo(gCameras)
/* 8EDE88 80242068 A440002C */  sh        $zero, 0x2c($v0)
/* 8EDE8C 8024206C A440002E */  sh        $zero, 0x2e($v0)
/* 8EDE90 80242070 A4400030 */  sh        $zero, 0x30($v0)
/* 8EDE94 80242074 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8EDE98 80242078 24020002 */  addiu     $v0, $zero, 2
/* 8EDE9C 8024207C 03E00008 */  jr        $ra
/* 8EDEA0 80242080 27BD0018 */   addiu    $sp, $sp, 0x18

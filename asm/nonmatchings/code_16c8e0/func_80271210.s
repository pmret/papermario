.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80271210
/* 19FAF0 80271210 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19FAF4 80271214 0080102D */  daddu     $v0, $a0, $zero
/* 19FAF8 80271218 AFBF0010 */  sw        $ra, 0x10($sp)
/* 19FAFC 8027121C C4400084 */  lwc1      $f0, 0x84($v0)
/* 19FB00 80271220 46800020 */  cvt.s.w   $f0, $f0
/* 19FB04 80271224 44050000 */  mfc1      $a1, $f0
/* 19FB08 80271228 C4400088 */  lwc1      $f0, 0x88($v0)
/* 19FB0C 8027122C 46800020 */  cvt.s.w   $f0, $f0
/* 19FB10 80271230 44060000 */  mfc1      $a2, $f0
/* 19FB14 80271234 C440008C */  lwc1      $f0, 0x8c($v0)
/* 19FB18 80271238 46800020 */  cvt.s.w   $f0, $f0
/* 19FB1C 8027123C 44070000 */  mfc1      $a3, $f0
/* 19FB20 80271240 0C01C2BC */  jal       func_80070AF0
/* 19FB24 80271244 0000202D */   daddu    $a0, $zero, $zero
/* 19FB28 80271248 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19FB2C 8027124C 24020002 */  addiu     $v0, $zero, 2
/* 19FB30 80271250 03E00008 */  jr        $ra
/* 19FB34 80271254 27BD0018 */   addiu    $sp, $sp, 0x18

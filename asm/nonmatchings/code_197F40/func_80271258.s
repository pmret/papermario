.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80271258
/* 19FB38 80271258 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19FB3C 8027125C 0080102D */  daddu     $v0, $a0, $zero
/* 19FB40 80271260 AFBF0010 */  sw        $ra, 0x10($sp)
/* 19FB44 80271264 C4400084 */  lwc1      $f0, 0x84($v0)
/* 19FB48 80271268 46800020 */  cvt.s.w   $f0, $f0
/* 19FB4C 8027126C 44050000 */  mfc1      $a1, $f0
/* 19FB50 80271270 C4400088 */  lwc1      $f0, 0x88($v0)
/* 19FB54 80271274 46800020 */  cvt.s.w   $f0, $f0
/* 19FB58 80271278 44060000 */  mfc1      $a2, $f0
/* 19FB5C 8027127C C440008C */  lwc1      $f0, 0x8c($v0)
/* 19FB60 80271280 46800020 */  cvt.s.w   $f0, $f0
/* 19FB64 80271284 44070000 */  mfc1      $a3, $f0
/* 19FB68 80271288 0C01C2BC */  jal       func_80070AF0
/* 19FB6C 8027128C 24040001 */   addiu    $a0, $zero, 1
/* 19FB70 80271290 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19FB74 80271294 24020002 */  addiu     $v0, $zero, 2
/* 19FB78 80271298 03E00008 */  jr        $ra
/* 19FB7C 8027129C 27BD0018 */   addiu    $sp, $sp, 0x18

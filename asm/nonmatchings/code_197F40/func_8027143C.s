.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8027143C
/* 19FD1C 8027143C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19FD20 80271440 0080102D */  daddu     $v0, $a0, $zero
/* 19FD24 80271444 AFBF0010 */  sw        $ra, 0x10($sp)
/* 19FD28 80271448 C4400084 */  lwc1      $f0, 0x84($v0)
/* 19FD2C 8027144C 46800020 */  cvt.s.w   $f0, $f0
/* 19FD30 80271450 44050000 */  mfc1      $a1, $f0
/* 19FD34 80271454 C4400088 */  lwc1      $f0, 0x88($v0)
/* 19FD38 80271458 46800020 */  cvt.s.w   $f0, $f0
/* 19FD3C 8027145C 44060000 */  mfc1      $a2, $f0
/* 19FD40 80271460 C440008C */  lwc1      $f0, 0x8c($v0)
/* 19FD44 80271464 46800020 */  cvt.s.w   $f0, $f0
/* 19FD48 80271468 44070000 */  mfc1      $a3, $f0
/* 19FD4C 8027146C 0C01C2A4 */  jal       func_80070A90
/* 19FD50 80271470 0000202D */   daddu    $a0, $zero, $zero
/* 19FD54 80271474 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19FD58 80271478 24020002 */  addiu     $v0, $zero, 2
/* 19FD5C 8027147C 03E00008 */  jr        $ra
/* 19FD60 80271480 27BD0018 */   addiu    $sp, $sp, 0x18

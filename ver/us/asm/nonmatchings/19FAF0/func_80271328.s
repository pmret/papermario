.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80271328
/* 19FC08 80271328 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19FC0C 8027132C 0080102D */  daddu     $v0, $a0, $zero
/* 19FC10 80271330 AFBF0010 */  sw        $ra, 0x10($sp)
/* 19FC14 80271334 C4400084 */  lwc1      $f0, 0x84($v0)
/* 19FC18 80271338 46800020 */  cvt.s.w   $f0, $f0
/* 19FC1C 8027133C 44050000 */  mfc1      $a1, $f0
/* 19FC20 80271340 C4400088 */  lwc1      $f0, 0x88($v0)
/* 19FC24 80271344 46800020 */  cvt.s.w   $f0, $f0
/* 19FC28 80271348 44060000 */  mfc1      $a2, $f0
/* 19FC2C 8027134C C440008C */  lwc1      $f0, 0x8c($v0)
/* 19FC30 80271350 46800020 */  cvt.s.w   $f0, $f0
/* 19FC34 80271354 44070000 */  mfc1      $a3, $f0
/* 19FC38 80271358 0C01C2BC */  jal       playFX_31
/* 19FC3C 8027135C 24040002 */   addiu    $a0, $zero, 2
/* 19FC40 80271360 8C44000C */  lw        $a0, 0xc($v0)
/* 19FC44 80271364 2403003C */  addiu     $v1, $zero, 0x3c
/* 19FC48 80271368 A0830038 */  sb        $v1, 0x38($a0)
/* 19FC4C 8027136C 8C44000C */  lw        $a0, 0xc($v0)
/* 19FC50 80271370 240300A0 */  addiu     $v1, $zero, 0xa0
/* 19FC54 80271374 A0830039 */  sb        $v1, 0x39($a0)
/* 19FC58 80271378 8C43000C */  lw        $v1, 0xc($v0)
/* 19FC5C 8027137C A060003A */  sb        $zero, 0x3a($v1)
/* 19FC60 80271380 8C44000C */  lw        $a0, 0xc($v0)
/* 19FC64 80271384 2403005A */  addiu     $v1, $zero, 0x5a
/* 19FC68 80271388 A083003B */  sb        $v1, 0x3b($a0)
/* 19FC6C 8027138C 8C44000C */  lw        $a0, 0xc($v0)
/* 19FC70 80271390 240300F0 */  addiu     $v1, $zero, 0xf0
/* 19FC74 80271394 A083003C */  sb        $v1, 0x3c($a0)
/* 19FC78 80271398 8C43000C */  lw        $v1, 0xc($v0)
/* 19FC7C 8027139C A060003D */  sb        $zero, 0x3d($v1)
/* 19FC80 802713A0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19FC84 802713A4 24020002 */  addiu     $v0, $zero, 2
/* 19FC88 802713A8 03E00008 */  jr        $ra
/* 19FC8C 802713AC 27BD0018 */   addiu    $sp, $sp, 0x18

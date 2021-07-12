.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802712A0
/* 19FB80 802712A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19FB84 802712A4 0080102D */  daddu     $v0, $a0, $zero
/* 19FB88 802712A8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 19FB8C 802712AC C4400084 */  lwc1      $f0, 0x84($v0)
/* 19FB90 802712B0 46800020 */  cvt.s.w   $f0, $f0
/* 19FB94 802712B4 44050000 */  mfc1      $a1, $f0
/* 19FB98 802712B8 C4400088 */  lwc1      $f0, 0x88($v0)
/* 19FB9C 802712BC 46800020 */  cvt.s.w   $f0, $f0
/* 19FBA0 802712C0 44060000 */  mfc1      $a2, $f0
/* 19FBA4 802712C4 C440008C */  lwc1      $f0, 0x8c($v0)
/* 19FBA8 802712C8 46800020 */  cvt.s.w   $f0, $f0
/* 19FBAC 802712CC 44070000 */  mfc1      $a3, $f0
/* 19FBB0 802712D0 0C01C2BC */  jal       playFX_31
/* 19FBB4 802712D4 24040002 */   addiu    $a0, $zero, 2
/* 19FBB8 802712D8 8C44000C */  lw        $a0, 0xc($v0)
/* 19FBBC 802712DC 240300C8 */  addiu     $v1, $zero, 0xc8
/* 19FBC0 802712E0 A0830038 */  sb        $v1, 0x38($a0)
/* 19FBC4 802712E4 8C44000C */  lw        $a0, 0xc($v0)
/* 19FBC8 802712E8 24030078 */  addiu     $v1, $zero, 0x78
/* 19FBCC 802712EC A0830039 */  sb        $v1, 0x39($a0)
/* 19FBD0 802712F0 8C43000C */  lw        $v1, 0xc($v0)
/* 19FBD4 802712F4 A060003A */  sb        $zero, 0x3a($v1)
/* 19FBD8 802712F8 8C44000C */  lw        $a0, 0xc($v0)
/* 19FBDC 802712FC 240300EA */  addiu     $v1, $zero, 0xea
/* 19FBE0 80271300 A083003B */  sb        $v1, 0x3b($a0)
/* 19FBE4 80271304 8C44000C */  lw        $a0, 0xc($v0)
/* 19FBE8 80271308 240300C1 */  addiu     $v1, $zero, 0xc1
/* 19FBEC 8027130C A083003C */  sb        $v1, 0x3c($a0)
/* 19FBF0 80271310 8C43000C */  lw        $v1, 0xc($v0)
/* 19FBF4 80271314 A060003D */  sb        $zero, 0x3d($v1)
/* 19FBF8 80271318 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19FBFC 8027131C 24020002 */  addiu     $v0, $zero, 2
/* 19FC00 80271320 03E00008 */  jr        $ra
/* 19FC04 80271324 27BD0018 */   addiu    $sp, $sp, 0x18

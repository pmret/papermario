.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802713B0
/* 19FC90 802713B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19FC94 802713B4 0080102D */  daddu     $v0, $a0, $zero
/* 19FC98 802713B8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 19FC9C 802713BC C4400084 */  lwc1      $f0, 0x84($v0)
/* 19FCA0 802713C0 46800020 */  cvt.s.w   $f0, $f0
/* 19FCA4 802713C4 44050000 */  mfc1      $a1, $f0
/* 19FCA8 802713C8 C4400088 */  lwc1      $f0, 0x88($v0)
/* 19FCAC 802713CC 46800020 */  cvt.s.w   $f0, $f0
/* 19FCB0 802713D0 44060000 */  mfc1      $a2, $f0
/* 19FCB4 802713D4 C440008C */  lwc1      $f0, 0x8c($v0)
/* 19FCB8 802713D8 46800020 */  cvt.s.w   $f0, $f0
/* 19FCBC 802713DC 44070000 */  mfc1      $a3, $f0
/* 19FCC0 802713E0 0C01C2BC */  jal       func_80070AF0
/* 19FCC4 802713E4 24040002 */   addiu    $a0, $zero, 2
/* 19FCC8 802713E8 0040282D */  daddu     $a1, $v0, $zero
/* 19FCCC 802713EC 8CA2000C */  lw        $v0, 0xc($a1)
/* 19FCD0 802713F0 240400CD */  addiu     $a0, $zero, 0xcd
/* 19FCD4 802713F4 A0440038 */  sb        $a0, 0x38($v0)
/* 19FCD8 802713F8 8CA2000C */  lw        $v0, 0xc($a1)
/* 19FCDC 802713FC A0400039 */  sb        $zero, 0x39($v0)
/* 19FCE0 80271400 8CA3000C */  lw        $v1, 0xc($a1)
/* 19FCE4 80271404 24020028 */  addiu     $v0, $zero, 0x28
/* 19FCE8 80271408 A062003A */  sb        $v0, 0x3a($v1)
/* 19FCEC 8027140C 8CA3000C */  lw        $v1, 0xc($a1)
/* 19FCF0 80271410 A064003B */  sb        $a0, 0x3b($v1)
/* 19FCF4 80271414 8CA4000C */  lw        $a0, 0xc($a1)
/* 19FCF8 80271418 24030020 */  addiu     $v1, $zero, 0x20
/* 19FCFC 8027141C A083003C */  sb        $v1, 0x3c($a0)
/* 19FD00 80271420 8CA4000C */  lw        $a0, 0xc($a1)
/* 19FD04 80271424 240300F2 */  addiu     $v1, $zero, 0xf2
/* 19FD08 80271428 A083003D */  sb        $v1, 0x3d($a0)
/* 19FD0C 8027142C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 19FD10 80271430 24020002 */  addiu     $v0, $zero, 2
/* 19FD14 80271434 03E00008 */  jr        $ra
/* 19FD18 80271438 27BD0018 */   addiu    $sp, $sp, 0x18

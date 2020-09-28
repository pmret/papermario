.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetBattleCamTarget
/* 17D1EC 8024E90C 3C028028 */  lui       $v0, 0x8028
/* 17D1F0 8024E910 80420CE0 */  lb        $v0, 0xce0($v0)
/* 17D1F4 8024E914 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 17D1F8 8024E918 AFB10014 */  sw        $s1, 0x14($sp)
/* 17D1FC 8024E91C 0080882D */  daddu     $s1, $a0, $zero
/* 17D200 8024E920 AFBF0018 */  sw        $ra, 0x18($sp)
/* 17D204 8024E924 AFB00010 */  sw        $s0, 0x10($sp)
/* 17D208 8024E928 8E30000C */  lw        $s0, 0xc($s1)
/* 17D20C 8024E92C 5440001B */  bnel      $v0, $zero, .L8024E99C
/* 17D210 8024E930 24020002 */   addiu    $v0, $zero, 2
/* 17D214 8024E934 8E050000 */  lw        $a1, ($s0)
/* 17D218 8024E938 0C0B1EAF */  jal       get_variable
/* 17D21C 8024E93C 26100004 */   addiu    $s0, $s0, 4
/* 17D220 8024E940 44820000 */  mtc1      $v0, $f0
/* 17D224 8024E944 00000000 */  nop       
/* 17D228 8024E948 46800020 */  cvt.s.w   $f0, $f0
/* 17D22C 8024E94C 3C01802A */  lui       $at, 0x802a
/* 17D230 8024E950 E420F270 */  swc1      $f0, -0xd90($at)
/* 17D234 8024E954 8E050000 */  lw        $a1, ($s0)
/* 17D238 8024E958 26100004 */  addiu     $s0, $s0, 4
/* 17D23C 8024E95C 0C0B1EAF */  jal       get_variable
/* 17D240 8024E960 0220202D */   daddu    $a0, $s1, $zero
/* 17D244 8024E964 44820000 */  mtc1      $v0, $f0
/* 17D248 8024E968 00000000 */  nop       
/* 17D24C 8024E96C 46800020 */  cvt.s.w   $f0, $f0
/* 17D250 8024E970 3C01802A */  lui       $at, 0x802a
/* 17D254 8024E974 E420F274 */  swc1      $f0, -0xd8c($at)
/* 17D258 8024E978 8E050000 */  lw        $a1, ($s0)
/* 17D25C 8024E97C 0C0B1EAF */  jal       get_variable
/* 17D260 8024E980 0220202D */   daddu    $a0, $s1, $zero
/* 17D264 8024E984 44820000 */  mtc1      $v0, $f0
/* 17D268 8024E988 00000000 */  nop       
/* 17D26C 8024E98C 46800020 */  cvt.s.w   $f0, $f0
/* 17D270 8024E990 3C01802A */  lui       $at, 0x802a
/* 17D274 8024E994 E420F278 */  swc1      $f0, -0xd88($at)
/* 17D278 8024E998 24020002 */  addiu     $v0, $zero, 2
.L8024E99C:
/* 17D27C 8024E99C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 17D280 8024E9A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 17D284 8024E9A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 17D288 8024E9A8 03E00008 */  jr        $ra
/* 17D28C 8024E9AC 27BD0020 */   addiu    $sp, $sp, 0x20

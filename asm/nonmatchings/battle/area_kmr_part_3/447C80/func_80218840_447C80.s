.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218840_447C80
/* 447C80 80218840 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 447C84 80218844 AFB10014 */  sw        $s1, 0x14($sp)
/* 447C88 80218848 0080882D */  daddu     $s1, $a0, $zero
/* 447C8C 8021884C AFBF0020 */  sw        $ra, 0x20($sp)
/* 447C90 80218850 AFB3001C */  sw        $s3, 0x1c($sp)
/* 447C94 80218854 AFB20018 */  sw        $s2, 0x18($sp)
/* 447C98 80218858 AFB00010 */  sw        $s0, 0x10($sp)
/* 447C9C 8021885C 8E30000C */  lw        $s0, 0xc($s1)
/* 447CA0 80218860 8E050000 */  lw        $a1, ($s0)
/* 447CA4 80218864 0C0B1EAF */  jal       get_variable
/* 447CA8 80218868 26100004 */   addiu    $s0, $s0, 4
/* 447CAC 8021886C 8E050000 */  lw        $a1, ($s0)
/* 447CB0 80218870 26100004 */  addiu     $s0, $s0, 4
/* 447CB4 80218874 0220202D */  daddu     $a0, $s1, $zero
/* 447CB8 80218878 0C0B1EAF */  jal       get_variable
/* 447CBC 8021887C 0040982D */   daddu    $s3, $v0, $zero
/* 447CC0 80218880 8E050000 */  lw        $a1, ($s0)
/* 447CC4 80218884 26100004 */  addiu     $s0, $s0, 4
/* 447CC8 80218888 0220202D */  daddu     $a0, $s1, $zero
/* 447CCC 8021888C 0C0B1EAF */  jal       get_variable
/* 447CD0 80218890 0040902D */   daddu    $s2, $v0, $zero
/* 447CD4 80218894 0220202D */  daddu     $a0, $s1, $zero
/* 447CD8 80218898 8E050000 */  lw        $a1, ($s0)
/* 447CDC 8021889C 0C0B1EAF */  jal       get_variable
/* 447CE0 802188A0 0040802D */   daddu    $s0, $v0, $zero
/* 447CE4 802188A4 8E240148 */  lw        $a0, 0x148($s1)
/* 447CE8 802188A8 0C09A75B */  jal       get_actor
/* 447CEC 802188AC 0040882D */   daddu    $s1, $v0, $zero
/* 447CF0 802188B0 0040182D */  daddu     $v1, $v0, $zero
/* 447CF4 802188B4 8C620008 */  lw        $v0, 8($v1)
/* 447CF8 802188B8 90420024 */  lbu       $v0, 0x24($v0)
/* 447CFC 802188BC 8C640008 */  lw        $a0, 8($v1)
/* 447D00 802188C0 02629823 */  subu      $s3, $s3, $v0
/* 447D04 802188C4 A0730194 */  sb        $s3, 0x194($v1)
/* 447D08 802188C8 90820025 */  lbu       $v0, 0x25($a0)
/* 447D0C 802188CC 02429023 */  subu      $s2, $s2, $v0
/* 447D10 802188D0 A0720195 */  sb        $s2, 0x195($v1)
/* 447D14 802188D4 90820026 */  lbu       $v0, 0x26($a0)
/* 447D18 802188D8 02028023 */  subu      $s0, $s0, $v0
/* 447D1C 802188DC A0700196 */  sb        $s0, 0x196($v1)
/* 447D20 802188E0 90840027 */  lbu       $a0, 0x27($a0)
/* 447D24 802188E4 02248823 */  subu      $s1, $s1, $a0
/* 447D28 802188E8 A0710197 */  sb        $s1, 0x197($v1)
/* 447D2C 802188EC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 447D30 802188F0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 447D34 802188F4 8FB20018 */  lw        $s2, 0x18($sp)
/* 447D38 802188F8 8FB10014 */  lw        $s1, 0x14($sp)
/* 447D3C 802188FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 447D40 80218900 24020002 */  addiu     $v0, $zero, 2
/* 447D44 80218904 03E00008 */  jr        $ra
/* 447D48 80218908 27BD0028 */   addiu    $sp, $sp, 0x28
/* 447D4C 8021890C 00000000 */  nop       

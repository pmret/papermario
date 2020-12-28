.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218380_5B1830
/* 5B1830 80218380 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5B1834 80218384 AFB10014 */  sw        $s1, 0x14($sp)
/* 5B1838 80218388 0080882D */  daddu     $s1, $a0, $zero
/* 5B183C 8021838C AFBF0020 */  sw        $ra, 0x20($sp)
/* 5B1840 80218390 AFB3001C */  sw        $s3, 0x1c($sp)
/* 5B1844 80218394 AFB20018 */  sw        $s2, 0x18($sp)
/* 5B1848 80218398 AFB00010 */  sw        $s0, 0x10($sp)
/* 5B184C 8021839C 8E30000C */  lw        $s0, 0xc($s1)
/* 5B1850 802183A0 8E050000 */  lw        $a1, ($s0)
/* 5B1854 802183A4 0C0B1EAF */  jal       get_variable
/* 5B1858 802183A8 26100004 */   addiu    $s0, $s0, 4
/* 5B185C 802183AC 8E050000 */  lw        $a1, ($s0)
/* 5B1860 802183B0 26100004 */  addiu     $s0, $s0, 4
/* 5B1864 802183B4 0220202D */  daddu     $a0, $s1, $zero
/* 5B1868 802183B8 0C0B1EAF */  jal       get_variable
/* 5B186C 802183BC 0040982D */   daddu    $s3, $v0, $zero
/* 5B1870 802183C0 8E050000 */  lw        $a1, ($s0)
/* 5B1874 802183C4 26100004 */  addiu     $s0, $s0, 4
/* 5B1878 802183C8 0220202D */  daddu     $a0, $s1, $zero
/* 5B187C 802183CC 0C0B1EAF */  jal       get_variable
/* 5B1880 802183D0 0040902D */   daddu    $s2, $v0, $zero
/* 5B1884 802183D4 0220202D */  daddu     $a0, $s1, $zero
/* 5B1888 802183D8 8E050000 */  lw        $a1, ($s0)
/* 5B188C 802183DC 0C0B1EAF */  jal       get_variable
/* 5B1890 802183E0 0040802D */   daddu    $s0, $v0, $zero
/* 5B1894 802183E4 8E240148 */  lw        $a0, 0x148($s1)
/* 5B1898 802183E8 0C09A75B */  jal       get_actor
/* 5B189C 802183EC 0040882D */   daddu    $s1, $v0, $zero
/* 5B18A0 802183F0 0040182D */  daddu     $v1, $v0, $zero
/* 5B18A4 802183F4 8C620008 */  lw        $v0, 8($v1)
/* 5B18A8 802183F8 90420024 */  lbu       $v0, 0x24($v0)
/* 5B18AC 802183FC 8C640008 */  lw        $a0, 8($v1)
/* 5B18B0 80218400 02629823 */  subu      $s3, $s3, $v0
/* 5B18B4 80218404 A0730194 */  sb        $s3, 0x194($v1)
/* 5B18B8 80218408 90820025 */  lbu       $v0, 0x25($a0)
/* 5B18BC 8021840C 02429023 */  subu      $s2, $s2, $v0
/* 5B18C0 80218410 A0720195 */  sb        $s2, 0x195($v1)
/* 5B18C4 80218414 90820026 */  lbu       $v0, 0x26($a0)
/* 5B18C8 80218418 02028023 */  subu      $s0, $s0, $v0
/* 5B18CC 8021841C A0700196 */  sb        $s0, 0x196($v1)
/* 5B18D0 80218420 90840027 */  lbu       $a0, 0x27($a0)
/* 5B18D4 80218424 02248823 */  subu      $s1, $s1, $a0
/* 5B18D8 80218428 A0710197 */  sb        $s1, 0x197($v1)
/* 5B18DC 8021842C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 5B18E0 80218430 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5B18E4 80218434 8FB20018 */  lw        $s2, 0x18($sp)
/* 5B18E8 80218438 8FB10014 */  lw        $s1, 0x14($sp)
/* 5B18EC 8021843C 8FB00010 */  lw        $s0, 0x10($sp)
/* 5B18F0 80218440 24020002 */  addiu     $v0, $zero, 2
/* 5B18F4 80218444 03E00008 */  jr        $ra
/* 5B18F8 80218448 27BD0028 */   addiu    $sp, $sp, 0x28

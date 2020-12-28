.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219244_64A054
/* 64A054 80219244 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 64A058 80219248 AFB10014 */  sw        $s1, 0x14($sp)
/* 64A05C 8021924C 0080882D */  daddu     $s1, $a0, $zero
/* 64A060 80219250 AFBF0020 */  sw        $ra, 0x20($sp)
/* 64A064 80219254 AFB3001C */  sw        $s3, 0x1c($sp)
/* 64A068 80219258 AFB20018 */  sw        $s2, 0x18($sp)
/* 64A06C 8021925C AFB00010 */  sw        $s0, 0x10($sp)
/* 64A070 80219260 8E30000C */  lw        $s0, 0xc($s1)
/* 64A074 80219264 8E050000 */  lw        $a1, ($s0)
/* 64A078 80219268 0C0B1EAF */  jal       get_variable
/* 64A07C 8021926C 26100004 */   addiu    $s0, $s0, 4
/* 64A080 80219270 8E050000 */  lw        $a1, ($s0)
/* 64A084 80219274 26100004 */  addiu     $s0, $s0, 4
/* 64A088 80219278 0220202D */  daddu     $a0, $s1, $zero
/* 64A08C 8021927C 0C0B1EAF */  jal       get_variable
/* 64A090 80219280 0040982D */   daddu    $s3, $v0, $zero
/* 64A094 80219284 8E050000 */  lw        $a1, ($s0)
/* 64A098 80219288 26100004 */  addiu     $s0, $s0, 4
/* 64A09C 8021928C 0220202D */  daddu     $a0, $s1, $zero
/* 64A0A0 80219290 0C0B1EAF */  jal       get_variable
/* 64A0A4 80219294 0040902D */   daddu    $s2, $v0, $zero
/* 64A0A8 80219298 0220202D */  daddu     $a0, $s1, $zero
/* 64A0AC 8021929C 8E050000 */  lw        $a1, ($s0)
/* 64A0B0 802192A0 0C0B1EAF */  jal       get_variable
/* 64A0B4 802192A4 0040802D */   daddu    $s0, $v0, $zero
/* 64A0B8 802192A8 8E240148 */  lw        $a0, 0x148($s1)
/* 64A0BC 802192AC 0C09A75B */  jal       get_actor
/* 64A0C0 802192B0 0040882D */   daddu    $s1, $v0, $zero
/* 64A0C4 802192B4 0040182D */  daddu     $v1, $v0, $zero
/* 64A0C8 802192B8 8C620008 */  lw        $v0, 8($v1)
/* 64A0CC 802192BC 90420024 */  lbu       $v0, 0x24($v0)
/* 64A0D0 802192C0 8C640008 */  lw        $a0, 8($v1)
/* 64A0D4 802192C4 02629823 */  subu      $s3, $s3, $v0
/* 64A0D8 802192C8 A0730194 */  sb        $s3, 0x194($v1)
/* 64A0DC 802192CC 90820025 */  lbu       $v0, 0x25($a0)
/* 64A0E0 802192D0 02429023 */  subu      $s2, $s2, $v0
/* 64A0E4 802192D4 A0720195 */  sb        $s2, 0x195($v1)
/* 64A0E8 802192D8 90820026 */  lbu       $v0, 0x26($a0)
/* 64A0EC 802192DC 02028023 */  subu      $s0, $s0, $v0
/* 64A0F0 802192E0 A0700196 */  sb        $s0, 0x196($v1)
/* 64A0F4 802192E4 90840027 */  lbu       $a0, 0x27($a0)
/* 64A0F8 802192E8 02248823 */  subu      $s1, $s1, $a0
/* 64A0FC 802192EC A0710197 */  sb        $s1, 0x197($v1)
/* 64A100 802192F0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 64A104 802192F4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 64A108 802192F8 8FB20018 */  lw        $s2, 0x18($sp)
/* 64A10C 802192FC 8FB10014 */  lw        $s1, 0x14($sp)
/* 64A110 80219300 8FB00010 */  lw        $s0, 0x10($sp)
/* 64A114 80219304 24020002 */  addiu     $v0, $zero, 2
/* 64A118 80219308 03E00008 */  jr        $ra
/* 64A11C 8021930C 27BD0028 */   addiu    $sp, $sp, 0x28

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218310_6DE0D0
/* 6DE0D0 80218310 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6DE0D4 80218314 AFB10014 */  sw        $s1, 0x14($sp)
/* 6DE0D8 80218318 0080882D */  daddu     $s1, $a0, $zero
/* 6DE0DC 8021831C AFBF0020 */  sw        $ra, 0x20($sp)
/* 6DE0E0 80218320 AFB3001C */  sw        $s3, 0x1c($sp)
/* 6DE0E4 80218324 AFB20018 */  sw        $s2, 0x18($sp)
/* 6DE0E8 80218328 AFB00010 */  sw        $s0, 0x10($sp)
/* 6DE0EC 8021832C 8E30000C */  lw        $s0, 0xc($s1)
/* 6DE0F0 80218330 8E050000 */  lw        $a1, ($s0)
/* 6DE0F4 80218334 0C0B1EAF */  jal       get_variable
/* 6DE0F8 80218338 26100004 */   addiu    $s0, $s0, 4
/* 6DE0FC 8021833C 8E050000 */  lw        $a1, ($s0)
/* 6DE100 80218340 26100004 */  addiu     $s0, $s0, 4
/* 6DE104 80218344 0220202D */  daddu     $a0, $s1, $zero
/* 6DE108 80218348 0C0B1EAF */  jal       get_variable
/* 6DE10C 8021834C 0040982D */   daddu    $s3, $v0, $zero
/* 6DE110 80218350 8E050000 */  lw        $a1, ($s0)
/* 6DE114 80218354 26100004 */  addiu     $s0, $s0, 4
/* 6DE118 80218358 0220202D */  daddu     $a0, $s1, $zero
/* 6DE11C 8021835C 0C0B1EAF */  jal       get_variable
/* 6DE120 80218360 0040902D */   daddu    $s2, $v0, $zero
/* 6DE124 80218364 0220202D */  daddu     $a0, $s1, $zero
/* 6DE128 80218368 8E050000 */  lw        $a1, ($s0)
/* 6DE12C 8021836C 0C0B1EAF */  jal       get_variable
/* 6DE130 80218370 0040802D */   daddu    $s0, $v0, $zero
/* 6DE134 80218374 8E240148 */  lw        $a0, 0x148($s1)
/* 6DE138 80218378 0C09A75B */  jal       get_actor
/* 6DE13C 8021837C 0040882D */   daddu    $s1, $v0, $zero
/* 6DE140 80218380 0040182D */  daddu     $v1, $v0, $zero
/* 6DE144 80218384 8C620008 */  lw        $v0, 8($v1)
/* 6DE148 80218388 90420024 */  lbu       $v0, 0x24($v0)
/* 6DE14C 8021838C 8C640008 */  lw        $a0, 8($v1)
/* 6DE150 80218390 02629823 */  subu      $s3, $s3, $v0
/* 6DE154 80218394 A0730194 */  sb        $s3, 0x194($v1)
/* 6DE158 80218398 90820025 */  lbu       $v0, 0x25($a0)
/* 6DE15C 8021839C 02429023 */  subu      $s2, $s2, $v0
/* 6DE160 802183A0 A0720195 */  sb        $s2, 0x195($v1)
/* 6DE164 802183A4 90820026 */  lbu       $v0, 0x26($a0)
/* 6DE168 802183A8 02028023 */  subu      $s0, $s0, $v0
/* 6DE16C 802183AC A0700196 */  sb        $s0, 0x196($v1)
/* 6DE170 802183B0 90840027 */  lbu       $a0, 0x27($a0)
/* 6DE174 802183B4 02248823 */  subu      $s1, $s1, $a0
/* 6DE178 802183B8 A0710197 */  sb        $s1, 0x197($v1)
/* 6DE17C 802183BC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6DE180 802183C0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6DE184 802183C4 8FB20018 */  lw        $s2, 0x18($sp)
/* 6DE188 802183C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 6DE18C 802183CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 6DE190 802183D0 24020002 */  addiu     $v0, $zero, 2
/* 6DE194 802183D4 03E00008 */  jr        $ra
/* 6DE198 802183D8 27BD0028 */   addiu    $sp, $sp, 0x28
/* 6DE19C 802183DC 00000000 */  nop       

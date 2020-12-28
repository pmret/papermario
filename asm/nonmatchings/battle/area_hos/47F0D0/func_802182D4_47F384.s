.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802182D4_47F384
/* 47F384 802182D4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 47F388 802182D8 AFB10014 */  sw        $s1, 0x14($sp)
/* 47F38C 802182DC 0080882D */  daddu     $s1, $a0, $zero
/* 47F390 802182E0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 47F394 802182E4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 47F398 802182E8 AFB20018 */  sw        $s2, 0x18($sp)
/* 47F39C 802182EC AFB00010 */  sw        $s0, 0x10($sp)
/* 47F3A0 802182F0 8E30000C */  lw        $s0, 0xc($s1)
/* 47F3A4 802182F4 8E050000 */  lw        $a1, ($s0)
/* 47F3A8 802182F8 0C0B1EAF */  jal       get_variable
/* 47F3AC 802182FC 26100004 */   addiu    $s0, $s0, 4
/* 47F3B0 80218300 8E050000 */  lw        $a1, ($s0)
/* 47F3B4 80218304 26100004 */  addiu     $s0, $s0, 4
/* 47F3B8 80218308 0220202D */  daddu     $a0, $s1, $zero
/* 47F3BC 8021830C 0C0B1EAF */  jal       get_variable
/* 47F3C0 80218310 0040982D */   daddu    $s3, $v0, $zero
/* 47F3C4 80218314 8E050000 */  lw        $a1, ($s0)
/* 47F3C8 80218318 26100004 */  addiu     $s0, $s0, 4
/* 47F3CC 8021831C 0220202D */  daddu     $a0, $s1, $zero
/* 47F3D0 80218320 0C0B1EAF */  jal       get_variable
/* 47F3D4 80218324 0040902D */   daddu    $s2, $v0, $zero
/* 47F3D8 80218328 0220202D */  daddu     $a0, $s1, $zero
/* 47F3DC 8021832C 8E050000 */  lw        $a1, ($s0)
/* 47F3E0 80218330 0C0B1EAF */  jal       get_variable
/* 47F3E4 80218334 0040802D */   daddu    $s0, $v0, $zero
/* 47F3E8 80218338 8E240148 */  lw        $a0, 0x148($s1)
/* 47F3EC 8021833C 0C09A75B */  jal       get_actor
/* 47F3F0 80218340 0040882D */   daddu    $s1, $v0, $zero
/* 47F3F4 80218344 0040182D */  daddu     $v1, $v0, $zero
/* 47F3F8 80218348 8C620008 */  lw        $v0, 8($v1)
/* 47F3FC 8021834C 90420024 */  lbu       $v0, 0x24($v0)
/* 47F400 80218350 8C640008 */  lw        $a0, 8($v1)
/* 47F404 80218354 02629823 */  subu      $s3, $s3, $v0
/* 47F408 80218358 A0730194 */  sb        $s3, 0x194($v1)
/* 47F40C 8021835C 90820025 */  lbu       $v0, 0x25($a0)
/* 47F410 80218360 02429023 */  subu      $s2, $s2, $v0
/* 47F414 80218364 A0720195 */  sb        $s2, 0x195($v1)
/* 47F418 80218368 90820026 */  lbu       $v0, 0x26($a0)
/* 47F41C 8021836C 02028023 */  subu      $s0, $s0, $v0
/* 47F420 80218370 A0700196 */  sb        $s0, 0x196($v1)
/* 47F424 80218374 90840027 */  lbu       $a0, 0x27($a0)
/* 47F428 80218378 02248823 */  subu      $s1, $s1, $a0
/* 47F42C 8021837C A0710197 */  sb        $s1, 0x197($v1)
/* 47F430 80218380 8FBF0020 */  lw        $ra, 0x20($sp)
/* 47F434 80218384 8FB3001C */  lw        $s3, 0x1c($sp)
/* 47F438 80218388 8FB20018 */  lw        $s2, 0x18($sp)
/* 47F43C 8021838C 8FB10014 */  lw        $s1, 0x14($sp)
/* 47F440 80218390 8FB00010 */  lw        $s0, 0x10($sp)
/* 47F444 80218394 24020002 */  addiu     $v0, $zero, 2
/* 47F448 80218398 03E00008 */  jr        $ra
/* 47F44C 8021839C 27BD0028 */   addiu    $sp, $sp, 0x28

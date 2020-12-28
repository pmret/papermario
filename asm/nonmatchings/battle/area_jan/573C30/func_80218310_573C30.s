.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218310_573C30
/* 573C30 80218310 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 573C34 80218314 AFB10014 */  sw        $s1, 0x14($sp)
/* 573C38 80218318 0080882D */  daddu     $s1, $a0, $zero
/* 573C3C 8021831C AFBF0020 */  sw        $ra, 0x20($sp)
/* 573C40 80218320 AFB3001C */  sw        $s3, 0x1c($sp)
/* 573C44 80218324 AFB20018 */  sw        $s2, 0x18($sp)
/* 573C48 80218328 AFB00010 */  sw        $s0, 0x10($sp)
/* 573C4C 8021832C 8E30000C */  lw        $s0, 0xc($s1)
/* 573C50 80218330 8E050000 */  lw        $a1, ($s0)
/* 573C54 80218334 0C0B1EAF */  jal       get_variable
/* 573C58 80218338 26100004 */   addiu    $s0, $s0, 4
/* 573C5C 8021833C 8E050000 */  lw        $a1, ($s0)
/* 573C60 80218340 26100004 */  addiu     $s0, $s0, 4
/* 573C64 80218344 0220202D */  daddu     $a0, $s1, $zero
/* 573C68 80218348 0C0B1EAF */  jal       get_variable
/* 573C6C 8021834C 0040982D */   daddu    $s3, $v0, $zero
/* 573C70 80218350 8E050000 */  lw        $a1, ($s0)
/* 573C74 80218354 26100004 */  addiu     $s0, $s0, 4
/* 573C78 80218358 0220202D */  daddu     $a0, $s1, $zero
/* 573C7C 8021835C 0C0B1EAF */  jal       get_variable
/* 573C80 80218360 0040902D */   daddu    $s2, $v0, $zero
/* 573C84 80218364 0220202D */  daddu     $a0, $s1, $zero
/* 573C88 80218368 8E050000 */  lw        $a1, ($s0)
/* 573C8C 8021836C 0C0B1EAF */  jal       get_variable
/* 573C90 80218370 0040802D */   daddu    $s0, $v0, $zero
/* 573C94 80218374 8E240148 */  lw        $a0, 0x148($s1)
/* 573C98 80218378 0C09A75B */  jal       get_actor
/* 573C9C 8021837C 0040882D */   daddu    $s1, $v0, $zero
/* 573CA0 80218380 0040182D */  daddu     $v1, $v0, $zero
/* 573CA4 80218384 8C620008 */  lw        $v0, 8($v1)
/* 573CA8 80218388 90420024 */  lbu       $v0, 0x24($v0)
/* 573CAC 8021838C 8C640008 */  lw        $a0, 8($v1)
/* 573CB0 80218390 02629823 */  subu      $s3, $s3, $v0
/* 573CB4 80218394 A0730194 */  sb        $s3, 0x194($v1)
/* 573CB8 80218398 90820025 */  lbu       $v0, 0x25($a0)
/* 573CBC 8021839C 02429023 */  subu      $s2, $s2, $v0
/* 573CC0 802183A0 A0720195 */  sb        $s2, 0x195($v1)
/* 573CC4 802183A4 90820026 */  lbu       $v0, 0x26($a0)
/* 573CC8 802183A8 02028023 */  subu      $s0, $s0, $v0
/* 573CCC 802183AC A0700196 */  sb        $s0, 0x196($v1)
/* 573CD0 802183B0 90840027 */  lbu       $a0, 0x27($a0)
/* 573CD4 802183B4 02248823 */  subu      $s1, $s1, $a0
/* 573CD8 802183B8 A0710197 */  sb        $s1, 0x197($v1)
/* 573CDC 802183BC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 573CE0 802183C0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 573CE4 802183C4 8FB20018 */  lw        $s2, 0x18($sp)
/* 573CE8 802183C8 8FB10014 */  lw        $s1, 0x14($sp)
/* 573CEC 802183CC 8FB00010 */  lw        $s0, 0x10($sp)
/* 573CF0 802183D0 24020002 */  addiu     $v0, $zero, 2
/* 573CF4 802183D4 03E00008 */  jr        $ra
/* 573CF8 802183D8 27BD0028 */   addiu    $sp, $sp, 0x28

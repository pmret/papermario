.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403F8
/* 9D7418 802403F8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9D741C 802403FC AFB10014 */  sw        $s1, 0x14($sp)
/* 9D7420 80240400 0080882D */  daddu     $s1, $a0, $zero
/* 9D7424 80240404 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9D7428 80240408 AFB00010 */  sw        $s0, 0x10($sp)
/* 9D742C 8024040C 8E30000C */  lw        $s0, 0xc($s1)
/* 9D7430 80240410 8E050000 */  lw        $a1, ($s0)
/* 9D7434 80240414 0C0B1EAF */  jal       get_variable
/* 9D7438 80240418 26100004 */   addiu    $s0, $s0, 4
/* 9D743C 8024041C 0C00EAD2 */  jal       get_npc_safe
/* 9D7440 80240420 0040202D */   daddu    $a0, $v0, $zero
/* 9D7444 80240424 10400005 */  beqz      $v0, .L8024043C
/* 9D7448 80240428 00000000 */   nop      
/* 9D744C 8024042C 8E050000 */  lw        $a1, ($s0)
/* 9D7450 80240430 844600A8 */  lh        $a2, 0xa8($v0)
/* 9D7454 80240434 0C0B2026 */  jal       set_variable
/* 9D7458 80240438 0220202D */   daddu    $a0, $s1, $zero
.L8024043C:
/* 9D745C 8024043C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9D7460 80240440 8FB10014 */  lw        $s1, 0x14($sp)
/* 9D7464 80240444 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D7468 80240448 24020002 */  addiu     $v0, $zero, 2
/* 9D746C 8024044C 03E00008 */  jr        $ra
/* 9D7470 80240450 27BD0020 */   addiu    $sp, $sp, 0x20

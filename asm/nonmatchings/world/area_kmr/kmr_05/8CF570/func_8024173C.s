.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024173C
/* 8CF7AC 8024173C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8CF7B0 80241740 AFB00010 */  sw        $s0, 0x10($sp)
/* 8CF7B4 80241744 0080802D */  daddu     $s0, $a0, $zero
/* 8CF7B8 80241748 AFBF0014 */  sw        $ra, 0x14($sp)
/* 8CF7BC 8024174C 0C00FB5A */  jal       get_enemy_safe
/* 8CF7C0 80241750 24040006 */   addiu    $a0, $zero, 6
/* 8CF7C4 80241754 14400003 */  bnez      $v0, .L80241764
/* 8CF7C8 80241758 24020001 */   addiu    $v0, $zero, 1
/* 8CF7CC 8024175C 080905DA */  j         .L80241768
/* 8CF7D0 80241760 AE000084 */   sw       $zero, 0x84($s0)
.L80241764:
/* 8CF7D4 80241764 AE020084 */  sw        $v0, 0x84($s0)
.L80241768:
/* 8CF7D8 80241768 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8CF7DC 8024176C 8FB00010 */  lw        $s0, 0x10($sp)
/* 8CF7E0 80241770 24020002 */  addiu     $v0, $zero, 2
/* 8CF7E4 80241774 03E00008 */  jr        $ra
/* 8CF7E8 80241778 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8CF7EC 8024177C 00000000 */  nop       

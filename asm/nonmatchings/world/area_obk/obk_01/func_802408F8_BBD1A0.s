.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408F8_BBDA98
/* BBDA98 802408F8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BBDA9C 802408FC AFB10014 */  sw        $s1, 0x14($sp)
/* BBDAA0 80240900 0080882D */  daddu     $s1, $a0, $zero
/* BBDAA4 80240904 AFBF0018 */  sw        $ra, 0x18($sp)
/* BBDAA8 80240908 AFB00010 */  sw        $s0, 0x10($sp)
/* BBDAAC 8024090C 8E30000C */  lw        $s0, 0xc($s1)
/* BBDAB0 80240910 8E050000 */  lw        $a1, ($s0)
/* BBDAB4 80240914 0C0B1EAF */  jal       get_variable
/* BBDAB8 80240918 26100004 */   addiu    $s0, $s0, 4
/* BBDABC 8024091C 0C00EAD2 */  jal       get_npc_safe
/* BBDAC0 80240920 0040202D */   daddu    $a0, $v0, $zero
/* BBDAC4 80240924 10400005 */  beqz      $v0, .L8024093C
/* BBDAC8 80240928 00000000 */   nop      
/* BBDACC 8024092C 8E050000 */  lw        $a1, ($s0)
/* BBDAD0 80240930 844600A8 */  lh        $a2, 0xa8($v0)
/* BBDAD4 80240934 0C0B2026 */  jal       set_variable
/* BBDAD8 80240938 0220202D */   daddu    $a0, $s1, $zero
.L8024093C:
/* BBDADC 8024093C 8FBF0018 */  lw        $ra, 0x18($sp)
/* BBDAE0 80240940 8FB10014 */  lw        $s1, 0x14($sp)
/* BBDAE4 80240944 8FB00010 */  lw        $s0, 0x10($sp)
/* BBDAE8 80240948 24020002 */  addiu     $v0, $zero, 2
/* BBDAEC 8024094C 03E00008 */  jr        $ra
/* BBDAF0 80240950 27BD0020 */   addiu    $sp, $sp, 0x20

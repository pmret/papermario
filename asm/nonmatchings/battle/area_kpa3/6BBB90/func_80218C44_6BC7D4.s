.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218C44_6BC7D4
/* 6BC7D4 80218C44 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6BC7D8 80218C48 AFB10014 */  sw        $s1, 0x14($sp)
/* 6BC7DC 80218C4C 0080882D */  daddu     $s1, $a0, $zero
/* 6BC7E0 80218C50 AFBF0020 */  sw        $ra, 0x20($sp)
/* 6BC7E4 80218C54 AFB3001C */  sw        $s3, 0x1c($sp)
/* 6BC7E8 80218C58 AFB20018 */  sw        $s2, 0x18($sp)
/* 6BC7EC 80218C5C AFB00010 */  sw        $s0, 0x10($sp)
/* 6BC7F0 80218C60 8E30000C */  lw        $s0, 0xc($s1)
/* 6BC7F4 80218C64 8E050000 */  lw        $a1, ($s0)
/* 6BC7F8 80218C68 0C0B1EAF */  jal       get_variable
/* 6BC7FC 80218C6C 26100004 */   addiu    $s0, $s0, 4
/* 6BC800 80218C70 8E050000 */  lw        $a1, ($s0)
/* 6BC804 80218C74 26100004 */  addiu     $s0, $s0, 4
/* 6BC808 80218C78 0220202D */  daddu     $a0, $s1, $zero
/* 6BC80C 80218C7C 0C0B1EAF */  jal       get_variable
/* 6BC810 80218C80 0040982D */   daddu    $s3, $v0, $zero
/* 6BC814 80218C84 8E050000 */  lw        $a1, ($s0)
/* 6BC818 80218C88 26100004 */  addiu     $s0, $s0, 4
/* 6BC81C 80218C8C 0220202D */  daddu     $a0, $s1, $zero
/* 6BC820 80218C90 0C0B1EAF */  jal       get_variable
/* 6BC824 80218C94 0040902D */   daddu    $s2, $v0, $zero
/* 6BC828 80218C98 0220202D */  daddu     $a0, $s1, $zero
/* 6BC82C 80218C9C 8E050000 */  lw        $a1, ($s0)
/* 6BC830 80218CA0 0C0B1EAF */  jal       get_variable
/* 6BC834 80218CA4 0040802D */   daddu    $s0, $v0, $zero
/* 6BC838 80218CA8 8E240148 */  lw        $a0, 0x148($s1)
/* 6BC83C 80218CAC 0C09A75B */  jal       get_actor
/* 6BC840 80218CB0 0040882D */   daddu    $s1, $v0, $zero
/* 6BC844 80218CB4 0040182D */  daddu     $v1, $v0, $zero
/* 6BC848 80218CB8 8C620008 */  lw        $v0, 8($v1)
/* 6BC84C 80218CBC 90420024 */  lbu       $v0, 0x24($v0)
/* 6BC850 80218CC0 8C640008 */  lw        $a0, 8($v1)
/* 6BC854 80218CC4 02629823 */  subu      $s3, $s3, $v0
/* 6BC858 80218CC8 A0730194 */  sb        $s3, 0x194($v1)
/* 6BC85C 80218CCC 90820025 */  lbu       $v0, 0x25($a0)
/* 6BC860 80218CD0 02429023 */  subu      $s2, $s2, $v0
/* 6BC864 80218CD4 A0720195 */  sb        $s2, 0x195($v1)
/* 6BC868 80218CD8 90820026 */  lbu       $v0, 0x26($a0)
/* 6BC86C 80218CDC 02028023 */  subu      $s0, $s0, $v0
/* 6BC870 80218CE0 A0700196 */  sb        $s0, 0x196($v1)
/* 6BC874 80218CE4 90840027 */  lbu       $a0, 0x27($a0)
/* 6BC878 80218CE8 02248823 */  subu      $s1, $s1, $a0
/* 6BC87C 80218CEC A0710197 */  sb        $s1, 0x197($v1)
/* 6BC880 80218CF0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6BC884 80218CF4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 6BC888 80218CF8 8FB20018 */  lw        $s2, 0x18($sp)
/* 6BC88C 80218CFC 8FB10014 */  lw        $s1, 0x14($sp)
/* 6BC890 80218D00 8FB00010 */  lw        $s0, 0x10($sp)
/* 6BC894 80218D04 24020002 */  addiu     $v0, $zero, 2
/* 6BC898 80218D08 03E00008 */  jr        $ra
/* 6BC89C 80218D0C 27BD0028 */   addiu    $sp, $sp, 0x28

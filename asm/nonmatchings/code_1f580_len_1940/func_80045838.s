.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045838
/* 20C38 80045838 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 20C3C 8004583C AFB10014 */  sw        $s1, 0x14($sp)
/* 20C40 80045840 0080882D */  daddu     $s1, $a0, $zero
/* 20C44 80045844 AFBF0020 */  sw        $ra, 0x20($sp)
/* 20C48 80045848 AFB3001C */  sw        $s3, 0x1c($sp)
/* 20C4C 8004584C AFB20018 */  sw        $s2, 0x18($sp)
/* 20C50 80045850 AFB00010 */  sw        $s0, 0x10($sp)
/* 20C54 80045854 8E30000C */  lw        $s0, 0xc($s1)
/* 20C58 80045858 8E050000 */  lw        $a1, ($s0)
/* 20C5C 8004585C 0C0B1EAF */  jal       get_variable
/* 20C60 80045860 26100004 */   addiu    $s0, $s0, 4
/* 20C64 80045864 8E050000 */  lw        $a1, ($s0)
/* 20C68 80045868 26100004 */  addiu     $s0, $s0, 4
/* 20C6C 8004586C 0220202D */  daddu     $a0, $s1, $zero
/* 20C70 80045870 0C0B1EAF */  jal       get_variable
/* 20C74 80045874 0040902D */   daddu    $s2, $v0, $zero
/* 20C78 80045878 0220202D */  daddu     $a0, $s1, $zero
/* 20C7C 8004587C 8E050000 */  lw        $a1, ($s0)
/* 20C80 80045880 0C0B1EAF */  jal       get_variable
/* 20C84 80045884 0040982D */   daddu    $s3, $v0, $zero
/* 20C88 80045888 0220202D */  daddu     $a0, $s1, $zero
/* 20C8C 8004588C 0240282D */  daddu     $a1, $s2, $zero
/* 20C90 80045890 0C0B36B0 */  jal       resolve_npc
/* 20C94 80045894 0040802D */   daddu    $s0, $v0, $zero
/* 20C98 80045898 10400004 */  beqz      $v0, .L800458AC
/* 20C9C 8004589C 0040202D */   daddu    $a0, $v0, $zero
/* 20CA0 800458A0 0260282D */  daddu     $a1, $s3, $zero
/* 20CA4 800458A4 0C012530 */  jal       func_800494C0
/* 20CA8 800458A8 0200302D */   daddu    $a2, $s0, $zero
.L800458AC:
/* 20CAC 800458AC 24020002 */  addiu     $v0, $zero, 2
/* 20CB0 800458B0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 20CB4 800458B4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 20CB8 800458B8 8FB20018 */  lw        $s2, 0x18($sp)
/* 20CBC 800458BC 8FB10014 */  lw        $s1, 0x14($sp)
/* 20CC0 800458C0 8FB00010 */  lw        $s0, 0x10($sp)
/* 20CC4 800458C4 03E00008 */  jr        $ra
/* 20CC8 800458C8 27BD0028 */   addiu    $sp, $sp, 0x28

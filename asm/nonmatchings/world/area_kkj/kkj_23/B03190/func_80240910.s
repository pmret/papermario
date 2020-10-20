.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240910
/* B03190 80240910 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B03194 80240914 AFB10014 */  sw        $s1, 0x14($sp)
/* B03198 80240918 0080882D */  daddu     $s1, $a0, $zero
/* B0319C 8024091C AFBF0020 */  sw        $ra, 0x20($sp)
/* B031A0 80240920 AFB3001C */  sw        $s3, 0x1c($sp)
/* B031A4 80240924 AFB20018 */  sw        $s2, 0x18($sp)
/* B031A8 80240928 AFB00010 */  sw        $s0, 0x10($sp)
/* B031AC 8024092C 8E30000C */  lw        $s0, 0xc($s1)
/* B031B0 80240930 8E050000 */  lw        $a1, ($s0)
/* B031B4 80240934 0C0B1EAF */  jal       get_variable
/* B031B8 80240938 26100004 */   addiu    $s0, $s0, 4
/* B031BC 8024093C 8E050000 */  lw        $a1, ($s0)
/* B031C0 80240940 26100004 */  addiu     $s0, $s0, 4
/* B031C4 80240944 0220202D */  daddu     $a0, $s1, $zero
/* B031C8 80240948 0C0B1EAF */  jal       get_variable
/* B031CC 8024094C 0040902D */   daddu    $s2, $v0, $zero
/* B031D0 80240950 8E050000 */  lw        $a1, ($s0)
/* B031D4 80240954 26100004 */  addiu     $s0, $s0, 4
/* B031D8 80240958 0220202D */  daddu     $a0, $s1, $zero
/* B031DC 8024095C 0C0B1EAF */  jal       get_variable
/* B031E0 80240960 0040982D */   daddu    $s3, $v0, $zero
/* B031E4 80240964 0220202D */  daddu     $a0, $s1, $zero
/* B031E8 80240968 8E050000 */  lw        $a1, ($s0)
/* B031EC 8024096C 0C0B1EAF */  jal       get_variable
/* B031F0 80240970 0040802D */   daddu    $s0, $v0, $zero
/* B031F4 80240974 8E43000C */  lw        $v1, 0xc($s2)
/* B031F8 80240978 AC730030 */  sw        $s3, 0x30($v1)
/* B031FC 8024097C 8E43000C */  lw        $v1, 0xc($s2)
/* B03200 80240980 AC700034 */  sw        $s0, 0x34($v1)
/* B03204 80240984 8E43000C */  lw        $v1, 0xc($s2)
/* B03208 80240988 AC620038 */  sw        $v0, 0x38($v1)
/* B0320C 8024098C 8FBF0020 */  lw        $ra, 0x20($sp)
/* B03210 80240990 8FB3001C */  lw        $s3, 0x1c($sp)
/* B03214 80240994 8FB20018 */  lw        $s2, 0x18($sp)
/* B03218 80240998 8FB10014 */  lw        $s1, 0x14($sp)
/* B0321C 8024099C 8FB00010 */  lw        $s0, 0x10($sp)
/* B03220 802409A0 24020002 */  addiu     $v0, $zero, 2
/* B03224 802409A4 03E00008 */  jr        $ra
/* B03228 802409A8 27BD0028 */   addiu    $sp, $sp, 0x28

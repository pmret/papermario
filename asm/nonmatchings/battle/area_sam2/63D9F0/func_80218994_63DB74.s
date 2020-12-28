.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218994_63DB74
/* 63DB74 80218994 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 63DB78 80218998 AFB10014 */  sw        $s1, 0x14($sp)
/* 63DB7C 8021899C 0080882D */  daddu     $s1, $a0, $zero
/* 63DB80 802189A0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 63DB84 802189A4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 63DB88 802189A8 AFB20018 */  sw        $s2, 0x18($sp)
/* 63DB8C 802189AC AFB00010 */  sw        $s0, 0x10($sp)
/* 63DB90 802189B0 8E30000C */  lw        $s0, 0xc($s1)
/* 63DB94 802189B4 8E050000 */  lw        $a1, ($s0)
/* 63DB98 802189B8 0C0B1EAF */  jal       get_variable
/* 63DB9C 802189BC 26100004 */   addiu    $s0, $s0, 4
/* 63DBA0 802189C0 8E050000 */  lw        $a1, ($s0)
/* 63DBA4 802189C4 26100004 */  addiu     $s0, $s0, 4
/* 63DBA8 802189C8 0220202D */  daddu     $a0, $s1, $zero
/* 63DBAC 802189CC 0C0B1EAF */  jal       get_variable
/* 63DBB0 802189D0 0040982D */   daddu    $s3, $v0, $zero
/* 63DBB4 802189D4 8E050000 */  lw        $a1, ($s0)
/* 63DBB8 802189D8 26100004 */  addiu     $s0, $s0, 4
/* 63DBBC 802189DC 0220202D */  daddu     $a0, $s1, $zero
/* 63DBC0 802189E0 0C0B1EAF */  jal       get_variable
/* 63DBC4 802189E4 0040902D */   daddu    $s2, $v0, $zero
/* 63DBC8 802189E8 0220202D */  daddu     $a0, $s1, $zero
/* 63DBCC 802189EC 8E050000 */  lw        $a1, ($s0)
/* 63DBD0 802189F0 0C0B1EAF */  jal       get_variable
/* 63DBD4 802189F4 0040802D */   daddu    $s0, $v0, $zero
/* 63DBD8 802189F8 8E240148 */  lw        $a0, 0x148($s1)
/* 63DBDC 802189FC 0C09A75B */  jal       get_actor
/* 63DBE0 80218A00 0040882D */   daddu    $s1, $v0, $zero
/* 63DBE4 80218A04 0040182D */  daddu     $v1, $v0, $zero
/* 63DBE8 80218A08 8C620008 */  lw        $v0, 8($v1)
/* 63DBEC 80218A0C 90420024 */  lbu       $v0, 0x24($v0)
/* 63DBF0 80218A10 8C640008 */  lw        $a0, 8($v1)
/* 63DBF4 80218A14 02629823 */  subu      $s3, $s3, $v0
/* 63DBF8 80218A18 A0730194 */  sb        $s3, 0x194($v1)
/* 63DBFC 80218A1C 90820025 */  lbu       $v0, 0x25($a0)
/* 63DC00 80218A20 02429023 */  subu      $s2, $s2, $v0
/* 63DC04 80218A24 A0720195 */  sb        $s2, 0x195($v1)
/* 63DC08 80218A28 90820026 */  lbu       $v0, 0x26($a0)
/* 63DC0C 80218A2C 02028023 */  subu      $s0, $s0, $v0
/* 63DC10 80218A30 A0700196 */  sb        $s0, 0x196($v1)
/* 63DC14 80218A34 90840027 */  lbu       $a0, 0x27($a0)
/* 63DC18 80218A38 02248823 */  subu      $s1, $s1, $a0
/* 63DC1C 80218A3C A0710197 */  sb        $s1, 0x197($v1)
/* 63DC20 80218A40 8FBF0020 */  lw        $ra, 0x20($sp)
/* 63DC24 80218A44 8FB3001C */  lw        $s3, 0x1c($sp)
/* 63DC28 80218A48 8FB20018 */  lw        $s2, 0x18($sp)
/* 63DC2C 80218A4C 8FB10014 */  lw        $s1, 0x14($sp)
/* 63DC30 80218A50 8FB00010 */  lw        $s0, 0x10($sp)
/* 63DC34 80218A54 24020002 */  addiu     $v0, $zero, 2
/* 63DC38 80218A58 03E00008 */  jr        $ra
/* 63DC3C 80218A5C 27BD0028 */   addiu    $sp, $sp, 0x28

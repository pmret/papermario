.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_56E2A0
/* 56E2A0 80218000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 56E2A4 80218004 AFB10014 */  sw        $s1, 0x14($sp)
/* 56E2A8 80218008 0080882D */  daddu     $s1, $a0, $zero
/* 56E2AC 8021800C AFBF0020 */  sw        $ra, 0x20($sp)
/* 56E2B0 80218010 AFB3001C */  sw        $s3, 0x1c($sp)
/* 56E2B4 80218014 AFB20018 */  sw        $s2, 0x18($sp)
/* 56E2B8 80218018 AFB00010 */  sw        $s0, 0x10($sp)
/* 56E2BC 8021801C 8E30000C */  lw        $s0, 0xc($s1)
/* 56E2C0 80218020 8E050000 */  lw        $a1, ($s0)
/* 56E2C4 80218024 0C0B1EAF */  jal       get_variable
/* 56E2C8 80218028 26100004 */   addiu    $s0, $s0, 4
/* 56E2CC 8021802C 8E050000 */  lw        $a1, ($s0)
/* 56E2D0 80218030 26100004 */  addiu     $s0, $s0, 4
/* 56E2D4 80218034 0220202D */  daddu     $a0, $s1, $zero
/* 56E2D8 80218038 0C0B1EAF */  jal       get_variable
/* 56E2DC 8021803C 0040982D */   daddu    $s3, $v0, $zero
/* 56E2E0 80218040 8E050000 */  lw        $a1, ($s0)
/* 56E2E4 80218044 26100004 */  addiu     $s0, $s0, 4
/* 56E2E8 80218048 0220202D */  daddu     $a0, $s1, $zero
/* 56E2EC 8021804C 0C0B1EAF */  jal       get_variable
/* 56E2F0 80218050 0040902D */   daddu    $s2, $v0, $zero
/* 56E2F4 80218054 0220202D */  daddu     $a0, $s1, $zero
/* 56E2F8 80218058 8E050000 */  lw        $a1, ($s0)
/* 56E2FC 8021805C 0C0B1EAF */  jal       get_variable
/* 56E300 80218060 0040802D */   daddu    $s0, $v0, $zero
/* 56E304 80218064 8E240148 */  lw        $a0, 0x148($s1)
/* 56E308 80218068 0C09A75B */  jal       get_actor
/* 56E30C 8021806C 0040882D */   daddu    $s1, $v0, $zero
/* 56E310 80218070 0040182D */  daddu     $v1, $v0, $zero
/* 56E314 80218074 8C620008 */  lw        $v0, 8($v1)
/* 56E318 80218078 90420024 */  lbu       $v0, 0x24($v0)
/* 56E31C 8021807C 8C640008 */  lw        $a0, 8($v1)
/* 56E320 80218080 02629823 */  subu      $s3, $s3, $v0
/* 56E324 80218084 A0730194 */  sb        $s3, 0x194($v1)
/* 56E328 80218088 90820025 */  lbu       $v0, 0x25($a0)
/* 56E32C 8021808C 02429023 */  subu      $s2, $s2, $v0
/* 56E330 80218090 A0720195 */  sb        $s2, 0x195($v1)
/* 56E334 80218094 90820026 */  lbu       $v0, 0x26($a0)
/* 56E338 80218098 02028023 */  subu      $s0, $s0, $v0
/* 56E33C 8021809C A0700196 */  sb        $s0, 0x196($v1)
/* 56E340 802180A0 90840027 */  lbu       $a0, 0x27($a0)
/* 56E344 802180A4 02248823 */  subu      $s1, $s1, $a0
/* 56E348 802180A8 A0710197 */  sb        $s1, 0x197($v1)
/* 56E34C 802180AC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 56E350 802180B0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 56E354 802180B4 8FB20018 */  lw        $s2, 0x18($sp)
/* 56E358 802180B8 8FB10014 */  lw        $s1, 0x14($sp)
/* 56E35C 802180BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 56E360 802180C0 24020002 */  addiu     $v0, $zero, 2
/* 56E364 802180C4 03E00008 */  jr        $ra
/* 56E368 802180C8 27BD0028 */   addiu    $sp, $sp, 0x28

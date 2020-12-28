.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218000_5EC490
/* 5EC490 80218000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5EC494 80218004 AFB10014 */  sw        $s1, 0x14($sp)
/* 5EC498 80218008 0080882D */  daddu     $s1, $a0, $zero
/* 5EC49C 8021800C AFBF0020 */  sw        $ra, 0x20($sp)
/* 5EC4A0 80218010 AFB3001C */  sw        $s3, 0x1c($sp)
/* 5EC4A4 80218014 AFB20018 */  sw        $s2, 0x18($sp)
/* 5EC4A8 80218018 AFB00010 */  sw        $s0, 0x10($sp)
/* 5EC4AC 8021801C 8E30000C */  lw        $s0, 0xc($s1)
/* 5EC4B0 80218020 8E050000 */  lw        $a1, ($s0)
/* 5EC4B4 80218024 0C0B1EAF */  jal       get_variable
/* 5EC4B8 80218028 26100004 */   addiu    $s0, $s0, 4
/* 5EC4BC 8021802C 8E050000 */  lw        $a1, ($s0)
/* 5EC4C0 80218030 26100004 */  addiu     $s0, $s0, 4
/* 5EC4C4 80218034 0220202D */  daddu     $a0, $s1, $zero
/* 5EC4C8 80218038 0C0B1EAF */  jal       get_variable
/* 5EC4CC 8021803C 0040982D */   daddu    $s3, $v0, $zero
/* 5EC4D0 80218040 8E050000 */  lw        $a1, ($s0)
/* 5EC4D4 80218044 26100004 */  addiu     $s0, $s0, 4
/* 5EC4D8 80218048 0220202D */  daddu     $a0, $s1, $zero
/* 5EC4DC 8021804C 0C0B1EAF */  jal       get_variable
/* 5EC4E0 80218050 0040902D */   daddu    $s2, $v0, $zero
/* 5EC4E4 80218054 0220202D */  daddu     $a0, $s1, $zero
/* 5EC4E8 80218058 8E050000 */  lw        $a1, ($s0)
/* 5EC4EC 8021805C 0C0B1EAF */  jal       get_variable
/* 5EC4F0 80218060 0040802D */   daddu    $s0, $v0, $zero
/* 5EC4F4 80218064 8E240148 */  lw        $a0, 0x148($s1)
/* 5EC4F8 80218068 0C09A75B */  jal       get_actor
/* 5EC4FC 8021806C 0040882D */   daddu    $s1, $v0, $zero
/* 5EC500 80218070 0040182D */  daddu     $v1, $v0, $zero
/* 5EC504 80218074 8C620008 */  lw        $v0, 8($v1)
/* 5EC508 80218078 90420024 */  lbu       $v0, 0x24($v0)
/* 5EC50C 8021807C 8C640008 */  lw        $a0, 8($v1)
/* 5EC510 80218080 02629823 */  subu      $s3, $s3, $v0
/* 5EC514 80218084 A0730194 */  sb        $s3, 0x194($v1)
/* 5EC518 80218088 90820025 */  lbu       $v0, 0x25($a0)
/* 5EC51C 8021808C 02429023 */  subu      $s2, $s2, $v0
/* 5EC520 80218090 A0720195 */  sb        $s2, 0x195($v1)
/* 5EC524 80218094 90820026 */  lbu       $v0, 0x26($a0)
/* 5EC528 80218098 02028023 */  subu      $s0, $s0, $v0
/* 5EC52C 8021809C A0700196 */  sb        $s0, 0x196($v1)
/* 5EC530 802180A0 90840027 */  lbu       $a0, 0x27($a0)
/* 5EC534 802180A4 02248823 */  subu      $s1, $s1, $a0
/* 5EC538 802180A8 A0710197 */  sb        $s1, 0x197($v1)
/* 5EC53C 802180AC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 5EC540 802180B0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5EC544 802180B4 8FB20018 */  lw        $s2, 0x18($sp)
/* 5EC548 802180B8 8FB10014 */  lw        $s1, 0x14($sp)
/* 5EC54C 802180BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 5EC550 802180C0 24020002 */  addiu     $v0, $zero, 2
/* 5EC554 802180C4 03E00008 */  jr        $ra
/* 5EC558 802180C8 27BD0028 */   addiu    $sp, $sp, 0x28
/* 5EC55C 802180CC 00000000 */  nop       

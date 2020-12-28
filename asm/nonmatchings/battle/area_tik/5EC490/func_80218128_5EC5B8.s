.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218128_5EC5B8
/* 5EC5B8 80218128 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5EC5BC 8021812C AFB10014 */  sw        $s1, 0x14($sp)
/* 5EC5C0 80218130 0080882D */  daddu     $s1, $a0, $zero
/* 5EC5C4 80218134 AFBF0020 */  sw        $ra, 0x20($sp)
/* 5EC5C8 80218138 AFB3001C */  sw        $s3, 0x1c($sp)
/* 5EC5CC 8021813C AFB20018 */  sw        $s2, 0x18($sp)
/* 5EC5D0 80218140 AFB00010 */  sw        $s0, 0x10($sp)
/* 5EC5D4 80218144 8E30000C */  lw        $s0, 0xc($s1)
/* 5EC5D8 80218148 8E050000 */  lw        $a1, ($s0)
/* 5EC5DC 8021814C 0C0B1EAF */  jal       get_variable
/* 5EC5E0 80218150 26100004 */   addiu    $s0, $s0, 4
/* 5EC5E4 80218154 8E050000 */  lw        $a1, ($s0)
/* 5EC5E8 80218158 26100004 */  addiu     $s0, $s0, 4
/* 5EC5EC 8021815C 0220202D */  daddu     $a0, $s1, $zero
/* 5EC5F0 80218160 0C0B1EAF */  jal       get_variable
/* 5EC5F4 80218164 0040982D */   daddu    $s3, $v0, $zero
/* 5EC5F8 80218168 8E050000 */  lw        $a1, ($s0)
/* 5EC5FC 8021816C 26100004 */  addiu     $s0, $s0, 4
/* 5EC600 80218170 0220202D */  daddu     $a0, $s1, $zero
/* 5EC604 80218174 0C0B1EAF */  jal       get_variable
/* 5EC608 80218178 0040902D */   daddu    $s2, $v0, $zero
/* 5EC60C 8021817C 0220202D */  daddu     $a0, $s1, $zero
/* 5EC610 80218180 8E050000 */  lw        $a1, ($s0)
/* 5EC614 80218184 0C0B1EAF */  jal       get_variable
/* 5EC618 80218188 0040802D */   daddu    $s0, $v0, $zero
/* 5EC61C 8021818C 8E240148 */  lw        $a0, 0x148($s1)
/* 5EC620 80218190 0C09A75B */  jal       get_actor
/* 5EC624 80218194 0040882D */   daddu    $s1, $v0, $zero
/* 5EC628 80218198 0040182D */  daddu     $v1, $v0, $zero
/* 5EC62C 8021819C 8C620008 */  lw        $v0, 8($v1)
/* 5EC630 802181A0 90420024 */  lbu       $v0, 0x24($v0)
/* 5EC634 802181A4 8C640008 */  lw        $a0, 8($v1)
/* 5EC638 802181A8 02629823 */  subu      $s3, $s3, $v0
/* 5EC63C 802181AC A0730194 */  sb        $s3, 0x194($v1)
/* 5EC640 802181B0 90820025 */  lbu       $v0, 0x25($a0)
/* 5EC644 802181B4 02429023 */  subu      $s2, $s2, $v0
/* 5EC648 802181B8 A0720195 */  sb        $s2, 0x195($v1)
/* 5EC64C 802181BC 90820026 */  lbu       $v0, 0x26($a0)
/* 5EC650 802181C0 02028023 */  subu      $s0, $s0, $v0
/* 5EC654 802181C4 A0700196 */  sb        $s0, 0x196($v1)
/* 5EC658 802181C8 90840027 */  lbu       $a0, 0x27($a0)
/* 5EC65C 802181CC 02248823 */  subu      $s1, $s1, $a0
/* 5EC660 802181D0 A0710197 */  sb        $s1, 0x197($v1)
/* 5EC664 802181D4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 5EC668 802181D8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5EC66C 802181DC 8FB20018 */  lw        $s2, 0x18($sp)
/* 5EC670 802181E0 8FB10014 */  lw        $s1, 0x14($sp)
/* 5EC674 802181E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 5EC678 802181E8 24020002 */  addiu     $v0, $zero, 2
/* 5EC67C 802181EC 03E00008 */  jr        $ra
/* 5EC680 802181F0 27BD0028 */   addiu    $sp, $sp, 0x28
/* 5EC684 802181F4 00000000 */  nop       
/* 5EC688 802181F8 00000000 */  nop       
/* 5EC68C 802181FC 00000000 */  nop       

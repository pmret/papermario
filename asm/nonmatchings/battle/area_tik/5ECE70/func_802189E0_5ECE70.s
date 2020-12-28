.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802189E0_5ECE70
/* 5ECE70 802189E0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 5ECE74 802189E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 5ECE78 802189E8 0080882D */  daddu     $s1, $a0, $zero
/* 5ECE7C 802189EC AFBF0020 */  sw        $ra, 0x20($sp)
/* 5ECE80 802189F0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 5ECE84 802189F4 AFB20018 */  sw        $s2, 0x18($sp)
/* 5ECE88 802189F8 AFB00010 */  sw        $s0, 0x10($sp)
/* 5ECE8C 802189FC 8E30000C */  lw        $s0, 0xc($s1)
/* 5ECE90 80218A00 8E050000 */  lw        $a1, ($s0)
/* 5ECE94 80218A04 0C0B1EAF */  jal       get_variable
/* 5ECE98 80218A08 26100004 */   addiu    $s0, $s0, 4
/* 5ECE9C 80218A0C 8E050000 */  lw        $a1, ($s0)
/* 5ECEA0 80218A10 26100004 */  addiu     $s0, $s0, 4
/* 5ECEA4 80218A14 0220202D */  daddu     $a0, $s1, $zero
/* 5ECEA8 80218A18 0C0B1EAF */  jal       get_variable
/* 5ECEAC 80218A1C 0040982D */   daddu    $s3, $v0, $zero
/* 5ECEB0 80218A20 8E050000 */  lw        $a1, ($s0)
/* 5ECEB4 80218A24 26100004 */  addiu     $s0, $s0, 4
/* 5ECEB8 80218A28 0220202D */  daddu     $a0, $s1, $zero
/* 5ECEBC 80218A2C 0C0B1EAF */  jal       get_variable
/* 5ECEC0 80218A30 0040902D */   daddu    $s2, $v0, $zero
/* 5ECEC4 80218A34 0220202D */  daddu     $a0, $s1, $zero
/* 5ECEC8 80218A38 8E050000 */  lw        $a1, ($s0)
/* 5ECECC 80218A3C 0C0B1EAF */  jal       get_variable
/* 5ECED0 80218A40 0040802D */   daddu    $s0, $v0, $zero
/* 5ECED4 80218A44 8E240148 */  lw        $a0, 0x148($s1)
/* 5ECED8 80218A48 0C09A75B */  jal       get_actor
/* 5ECEDC 80218A4C 0040882D */   daddu    $s1, $v0, $zero
/* 5ECEE0 80218A50 0040182D */  daddu     $v1, $v0, $zero
/* 5ECEE4 80218A54 8C620008 */  lw        $v0, 8($v1)
/* 5ECEE8 80218A58 90420024 */  lbu       $v0, 0x24($v0)
/* 5ECEEC 80218A5C 8C640008 */  lw        $a0, 8($v1)
/* 5ECEF0 80218A60 02629823 */  subu      $s3, $s3, $v0
/* 5ECEF4 80218A64 A0730194 */  sb        $s3, 0x194($v1)
/* 5ECEF8 80218A68 90820025 */  lbu       $v0, 0x25($a0)
/* 5ECEFC 80218A6C 02429023 */  subu      $s2, $s2, $v0
/* 5ECF00 80218A70 A0720195 */  sb        $s2, 0x195($v1)
/* 5ECF04 80218A74 90820026 */  lbu       $v0, 0x26($a0)
/* 5ECF08 80218A78 02028023 */  subu      $s0, $s0, $v0
/* 5ECF0C 80218A7C A0700196 */  sb        $s0, 0x196($v1)
/* 5ECF10 80218A80 90840027 */  lbu       $a0, 0x27($a0)
/* 5ECF14 80218A84 02248823 */  subu      $s1, $s1, $a0
/* 5ECF18 80218A88 A0710197 */  sb        $s1, 0x197($v1)
/* 5ECF1C 80218A8C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 5ECF20 80218A90 8FB3001C */  lw        $s3, 0x1c($sp)
/* 5ECF24 80218A94 8FB20018 */  lw        $s2, 0x18($sp)
/* 5ECF28 80218A98 8FB10014 */  lw        $s1, 0x14($sp)
/* 5ECF2C 80218A9C 8FB00010 */  lw        $s0, 0x10($sp)
/* 5ECF30 80218AA0 24020002 */  addiu     $v0, $zero, 2
/* 5ECF34 80218AA4 03E00008 */  jr        $ra
/* 5ECF38 80218AA8 27BD0028 */   addiu    $sp, $sp, 0x28
/* 5ECF3C 80218AAC 00000000 */  nop       

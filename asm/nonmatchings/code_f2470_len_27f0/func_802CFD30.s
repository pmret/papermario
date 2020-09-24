.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CFD30
/* F46E0 802CFD30 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* F46E4 802CFD34 AFB10024 */  sw        $s1, 0x24($sp)
/* F46E8 802CFD38 0080882D */  daddu     $s1, $a0, $zero
/* F46EC 802CFD3C AFBF003C */  sw        $ra, 0x3c($sp)
/* F46F0 802CFD40 AFB60038 */  sw        $s6, 0x38($sp)
/* F46F4 802CFD44 AFB50034 */  sw        $s5, 0x34($sp)
/* F46F8 802CFD48 AFB40030 */  sw        $s4, 0x30($sp)
/* F46FC 802CFD4C AFB3002C */  sw        $s3, 0x2c($sp)
/* F4700 802CFD50 AFB20028 */  sw        $s2, 0x28($sp)
/* F4704 802CFD54 AFB00020 */  sw        $s0, 0x20($sp)
/* F4708 802CFD58 8E30000C */  lw        $s0, 0xc($s1)
/* F470C 802CFD5C 8E050000 */  lw        $a1, ($s0)
/* F4710 802CFD60 0C0B1EAF */  jal       get_variable
/* F4714 802CFD64 26100004 */   addiu    $s0, $s0, 4
/* F4718 802CFD68 8E050000 */  lw        $a1, ($s0)
/* F471C 802CFD6C 26100004 */  addiu     $s0, $s0, 4
/* F4720 802CFD70 0220202D */  daddu     $a0, $s1, $zero
/* F4724 802CFD74 0C0B1EAF */  jal       get_variable
/* F4728 802CFD78 0040902D */   daddu    $s2, $v0, $zero
/* F472C 802CFD7C 8E050000 */  lw        $a1, ($s0)
/* F4730 802CFD80 26100004 */  addiu     $s0, $s0, 4
/* F4734 802CFD84 0220202D */  daddu     $a0, $s1, $zero
/* F4738 802CFD88 0C0B1EAF */  jal       get_variable
/* F473C 802CFD8C 0040B02D */   daddu    $s6, $v0, $zero
/* F4740 802CFD90 8E050000 */  lw        $a1, ($s0)
/* F4744 802CFD94 26100004 */  addiu     $s0, $s0, 4
/* F4748 802CFD98 0220202D */  daddu     $a0, $s1, $zero
/* F474C 802CFD9C 0C0B1EAF */  jal       get_variable
/* F4750 802CFDA0 0040A82D */   daddu    $s5, $v0, $zero
/* F4754 802CFDA4 8E050000 */  lw        $a1, ($s0)
/* F4758 802CFDA8 26100004 */  addiu     $s0, $s0, 4
/* F475C 802CFDAC 0220202D */  daddu     $a0, $s1, $zero
/* F4760 802CFDB0 0C0B1EAF */  jal       get_variable
/* F4764 802CFDB4 0040A02D */   daddu    $s4, $v0, $zero
/* F4768 802CFDB8 0220202D */  daddu     $a0, $s1, $zero
/* F476C 802CFDBC 8E050000 */  lw        $a1, ($s0)
/* F4770 802CFDC0 0C0B1EAF */  jal       get_variable
/* F4774 802CFDC4 0040982D */   daddu    $s3, $v0, $zero
/* F4778 802CFDC8 0220202D */  daddu     $a0, $s1, $zero
/* F477C 802CFDCC 0240282D */  daddu     $a1, $s2, $zero
/* F4780 802CFDD0 0C0B36B0 */  jal       resolve_npc
/* F4784 802CFDD4 0040802D */   daddu    $s0, $v0, $zero
/* F4788 802CFDD8 10400009 */  beqz      $v0, .L802CFE00
/* F478C 802CFDDC 0040202D */   daddu    $a0, $v0, $zero
/* F4790 802CFDE0 02C0282D */  daddu     $a1, $s6, $zero
/* F4794 802CFDE4 02A0302D */  daddu     $a2, $s5, $zero
/* F4798 802CFDE8 AFB30010 */  sw        $s3, 0x10($sp)
/* F479C 802CFDEC AFB00014 */  sw        $s0, 0x14($sp)
/* F47A0 802CFDF0 948200A2 */  lhu       $v0, 0xa2($a0)
/* F47A4 802CFDF4 0280382D */  daddu     $a3, $s4, $zero
/* F47A8 802CFDF8 0C00F589 */  jal       func_8003D624
/* F47AC 802CFDFC AFA20018 */   sw       $v0, 0x18($sp)
.L802CFE00:
/* F47B0 802CFE00 24020002 */  addiu     $v0, $zero, 2
/* F47B4 802CFE04 8FBF003C */  lw        $ra, 0x3c($sp)
/* F47B8 802CFE08 8FB60038 */  lw        $s6, 0x38($sp)
/* F47BC 802CFE0C 8FB50034 */  lw        $s5, 0x34($sp)
/* F47C0 802CFE10 8FB40030 */  lw        $s4, 0x30($sp)
/* F47C4 802CFE14 8FB3002C */  lw        $s3, 0x2c($sp)
/* F47C8 802CFE18 8FB20028 */  lw        $s2, 0x28($sp)
/* F47CC 802CFE1C 8FB10024 */  lw        $s1, 0x24($sp)
/* F47D0 802CFE20 8FB00020 */  lw        $s0, 0x20($sp)
/* F47D4 802CFE24 03E00008 */  jr        $ra
/* F47D8 802CFE28 27BD0040 */   addiu    $sp, $sp, 0x40

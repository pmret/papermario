.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CFEEC
/* F489C 802CFEEC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* F48A0 802CFEF0 AFB1001C */  sw        $s1, 0x1c($sp)
/* F48A4 802CFEF4 0080882D */  daddu     $s1, $a0, $zero
/* F48A8 802CFEF8 AFBF0030 */  sw        $ra, 0x30($sp)
/* F48AC 802CFEFC AFB5002C */  sw        $s5, 0x2c($sp)
/* F48B0 802CFF00 AFB40028 */  sw        $s4, 0x28($sp)
/* F48B4 802CFF04 AFB30024 */  sw        $s3, 0x24($sp)
/* F48B8 802CFF08 AFB20020 */  sw        $s2, 0x20($sp)
/* F48BC 802CFF0C AFB00018 */  sw        $s0, 0x18($sp)
/* F48C0 802CFF10 8E30000C */  lw        $s0, 0xc($s1)
/* F48C4 802CFF14 8E050000 */  lw        $a1, ($s0)
/* F48C8 802CFF18 0C0B1EAF */  jal       get_variable
/* F48CC 802CFF1C 26100004 */   addiu    $s0, $s0, 4
/* F48D0 802CFF20 8E050000 */  lw        $a1, ($s0)
/* F48D4 802CFF24 26100004 */  addiu     $s0, $s0, 4
/* F48D8 802CFF28 0220202D */  daddu     $a0, $s1, $zero
/* F48DC 802CFF2C 0C0B1EAF */  jal       get_variable
/* F48E0 802CFF30 0040902D */   daddu    $s2, $v0, $zero
/* F48E4 802CFF34 8E050000 */  lw        $a1, ($s0)
/* F48E8 802CFF38 26100004 */  addiu     $s0, $s0, 4
/* F48EC 802CFF3C 0220202D */  daddu     $a0, $s1, $zero
/* F48F0 802CFF40 0C0B1EAF */  jal       get_variable
/* F48F4 802CFF44 0040A82D */   daddu    $s5, $v0, $zero
/* F48F8 802CFF48 8E050000 */  lw        $a1, ($s0)
/* F48FC 802CFF4C 26100004 */  addiu     $s0, $s0, 4
/* F4900 802CFF50 0220202D */  daddu     $a0, $s1, $zero
/* F4904 802CFF54 0C0B1EAF */  jal       get_variable
/* F4908 802CFF58 0040A02D */   daddu    $s4, $v0, $zero
/* F490C 802CFF5C 0220202D */  daddu     $a0, $s1, $zero
/* F4910 802CFF60 8E050000 */  lw        $a1, ($s0)
/* F4914 802CFF64 0C0B1EAF */  jal       get_variable
/* F4918 802CFF68 0040982D */   daddu    $s3, $v0, $zero
/* F491C 802CFF6C 0220202D */  daddu     $a0, $s1, $zero
/* F4920 802CFF70 0240282D */  daddu     $a1, $s2, $zero
/* F4924 802CFF74 0C0B36B0 */  jal       resolve_npc
/* F4928 802CFF78 0040802D */   daddu    $s0, $v0, $zero
/* F492C 802CFF7C 10400006 */  beqz      $v0, .L802CFF98
/* F4930 802CFF80 0040202D */   daddu    $a0, $v0, $zero
/* F4934 802CFF84 AFB00010 */  sw        $s0, 0x10($sp)
/* F4938 802CFF88 02A0282D */  daddu     $a1, $s5, $zero
/* F493C 802CFF8C 0280302D */  daddu     $a2, $s4, $zero
/* F4940 802CFF90 0C00ED13 */  jal       func_8003B44C
/* F4944 802CFF94 0260382D */   daddu    $a3, $s3, $zero
.L802CFF98:
/* F4948 802CFF98 24020002 */  addiu     $v0, $zero, 2
/* F494C 802CFF9C 8FBF0030 */  lw        $ra, 0x30($sp)
/* F4950 802CFFA0 8FB5002C */  lw        $s5, 0x2c($sp)
/* F4954 802CFFA4 8FB40028 */  lw        $s4, 0x28($sp)
/* F4958 802CFFA8 8FB30024 */  lw        $s3, 0x24($sp)
/* F495C 802CFFAC 8FB20020 */  lw        $s2, 0x20($sp)
/* F4960 802CFFB0 8FB1001C */  lw        $s1, 0x1c($sp)
/* F4964 802CFFB4 8FB00018 */  lw        $s0, 0x18($sp)
/* F4968 802CFFB8 03E00008 */  jr        $ra
/* F496C 802CFFBC 27BD0038 */   addiu    $sp, $sp, 0x38

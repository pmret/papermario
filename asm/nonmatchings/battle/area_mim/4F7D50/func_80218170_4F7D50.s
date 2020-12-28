.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218170_4F7D50
/* 4F7D50 80218170 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4F7D54 80218174 AFB10014 */  sw        $s1, 0x14($sp)
/* 4F7D58 80218178 0080882D */  daddu     $s1, $a0, $zero
/* 4F7D5C 8021817C AFBF0020 */  sw        $ra, 0x20($sp)
/* 4F7D60 80218180 AFB3001C */  sw        $s3, 0x1c($sp)
/* 4F7D64 80218184 AFB20018 */  sw        $s2, 0x18($sp)
/* 4F7D68 80218188 AFB00010 */  sw        $s0, 0x10($sp)
/* 4F7D6C 8021818C 8E30000C */  lw        $s0, 0xc($s1)
/* 4F7D70 80218190 8E050000 */  lw        $a1, ($s0)
/* 4F7D74 80218194 0C0B1EAF */  jal       get_variable
/* 4F7D78 80218198 26100004 */   addiu    $s0, $s0, 4
/* 4F7D7C 8021819C 8E050000 */  lw        $a1, ($s0)
/* 4F7D80 802181A0 26100004 */  addiu     $s0, $s0, 4
/* 4F7D84 802181A4 0220202D */  daddu     $a0, $s1, $zero
/* 4F7D88 802181A8 0C0B1EAF */  jal       get_variable
/* 4F7D8C 802181AC 0040982D */   daddu    $s3, $v0, $zero
/* 4F7D90 802181B0 8E050000 */  lw        $a1, ($s0)
/* 4F7D94 802181B4 26100004 */  addiu     $s0, $s0, 4
/* 4F7D98 802181B8 0220202D */  daddu     $a0, $s1, $zero
/* 4F7D9C 802181BC 0C0B1EAF */  jal       get_variable
/* 4F7DA0 802181C0 0040902D */   daddu    $s2, $v0, $zero
/* 4F7DA4 802181C4 0220202D */  daddu     $a0, $s1, $zero
/* 4F7DA8 802181C8 8E050000 */  lw        $a1, ($s0)
/* 4F7DAC 802181CC 0C0B1EAF */  jal       get_variable
/* 4F7DB0 802181D0 0040802D */   daddu    $s0, $v0, $zero
/* 4F7DB4 802181D4 8E240148 */  lw        $a0, 0x148($s1)
/* 4F7DB8 802181D8 0C09A75B */  jal       get_actor
/* 4F7DBC 802181DC 0040882D */   daddu    $s1, $v0, $zero
/* 4F7DC0 802181E0 0040182D */  daddu     $v1, $v0, $zero
/* 4F7DC4 802181E4 8C620008 */  lw        $v0, 8($v1)
/* 4F7DC8 802181E8 90420024 */  lbu       $v0, 0x24($v0)
/* 4F7DCC 802181EC 8C640008 */  lw        $a0, 8($v1)
/* 4F7DD0 802181F0 02629823 */  subu      $s3, $s3, $v0
/* 4F7DD4 802181F4 A0730194 */  sb        $s3, 0x194($v1)
/* 4F7DD8 802181F8 90820025 */  lbu       $v0, 0x25($a0)
/* 4F7DDC 802181FC 02429023 */  subu      $s2, $s2, $v0
/* 4F7DE0 80218200 A0720195 */  sb        $s2, 0x195($v1)
/* 4F7DE4 80218204 90820026 */  lbu       $v0, 0x26($a0)
/* 4F7DE8 80218208 02028023 */  subu      $s0, $s0, $v0
/* 4F7DEC 8021820C A0700196 */  sb        $s0, 0x196($v1)
/* 4F7DF0 80218210 90840027 */  lbu       $a0, 0x27($a0)
/* 4F7DF4 80218214 02248823 */  subu      $s1, $s1, $a0
/* 4F7DF8 80218218 A0710197 */  sb        $s1, 0x197($v1)
/* 4F7DFC 8021821C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 4F7E00 80218220 8FB3001C */  lw        $s3, 0x1c($sp)
/* 4F7E04 80218224 8FB20018 */  lw        $s2, 0x18($sp)
/* 4F7E08 80218228 8FB10014 */  lw        $s1, 0x14($sp)
/* 4F7E0C 8021822C 8FB00010 */  lw        $s0, 0x10($sp)
/* 4F7E10 80218230 24020002 */  addiu     $v0, $zero, 2
/* 4F7E14 80218234 03E00008 */  jr        $ra
/* 4F7E18 80218238 27BD0028 */   addiu    $sp, $sp, 0x28

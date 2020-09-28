.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CFFC0
/* F4970 802CFFC0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* F4974 802CFFC4 AFB10024 */  sw        $s1, 0x24($sp)
/* F4978 802CFFC8 0080882D */  daddu     $s1, $a0, $zero
/* F497C 802CFFCC AFBF0044 */  sw        $ra, 0x44($sp)
/* F4980 802CFFD0 AFBE0040 */  sw        $fp, 0x40($sp)
/* F4984 802CFFD4 AFB7003C */  sw        $s7, 0x3c($sp)
/* F4988 802CFFD8 AFB60038 */  sw        $s6, 0x38($sp)
/* F498C 802CFFDC AFB50034 */  sw        $s5, 0x34($sp)
/* F4990 802CFFE0 AFB40030 */  sw        $s4, 0x30($sp)
/* F4994 802CFFE4 AFB3002C */  sw        $s3, 0x2c($sp)
/* F4998 802CFFE8 AFB20028 */  sw        $s2, 0x28($sp)
/* F499C 802CFFEC AFB00020 */  sw        $s0, 0x20($sp)
/* F49A0 802CFFF0 8E30000C */  lw        $s0, 0xc($s1)
/* F49A4 802CFFF4 8E050000 */  lw        $a1, ($s0)
/* F49A8 802CFFF8 0C0B1EAF */  jal       get_variable
/* F49AC 802CFFFC 26100004 */   addiu    $s0, $s0, 4
/* F49B0 802D0000 8E050000 */  lw        $a1, ($s0)
/* F49B4 802D0004 26100004 */  addiu     $s0, $s0, 4
/* F49B8 802D0008 0220202D */  daddu     $a0, $s1, $zero
/* F49BC 802D000C 0C0B1EAF */  jal       get_variable
/* F49C0 802D0010 0040902D */   daddu    $s2, $v0, $zero
/* F49C4 802D0014 8E050000 */  lw        $a1, ($s0)
/* F49C8 802D0018 26100004 */  addiu     $s0, $s0, 4
/* F49CC 802D001C 0220202D */  daddu     $a0, $s1, $zero
/* F49D0 802D0020 0C0B1EAF */  jal       get_variable
/* F49D4 802D0024 AFA20018 */   sw       $v0, 0x18($sp)
/* F49D8 802D0028 8E050000 */  lw        $a1, ($s0)
/* F49DC 802D002C 26100004 */  addiu     $s0, $s0, 4
/* F49E0 802D0030 0220202D */  daddu     $a0, $s1, $zero
/* F49E4 802D0034 0C0B1EAF */  jal       get_variable
/* F49E8 802D0038 0040F02D */   daddu    $fp, $v0, $zero
/* F49EC 802D003C 8E050000 */  lw        $a1, ($s0)
/* F49F0 802D0040 26100004 */  addiu     $s0, $s0, 4
/* F49F4 802D0044 0220202D */  daddu     $a0, $s1, $zero
/* F49F8 802D0048 0C0B1EAF */  jal       get_variable
/* F49FC 802D004C 0040B82D */   daddu    $s7, $v0, $zero
/* F4A00 802D0050 8E050000 */  lw        $a1, ($s0)
/* F4A04 802D0054 26100004 */  addiu     $s0, $s0, 4
/* F4A08 802D0058 0220202D */  daddu     $a0, $s1, $zero
/* F4A0C 802D005C 0C0B1EAF */  jal       get_variable
/* F4A10 802D0060 0040B02D */   daddu    $s6, $v0, $zero
/* F4A14 802D0064 8E050000 */  lw        $a1, ($s0)
/* F4A18 802D0068 26100004 */  addiu     $s0, $s0, 4
/* F4A1C 802D006C 0220202D */  daddu     $a0, $s1, $zero
/* F4A20 802D0070 0C0B1EAF */  jal       get_variable
/* F4A24 802D0074 0040A82D */   daddu    $s5, $v0, $zero
/* F4A28 802D0078 8E050000 */  lw        $a1, ($s0)
/* F4A2C 802D007C 26100004 */  addiu     $s0, $s0, 4
/* F4A30 802D0080 0220202D */  daddu     $a0, $s1, $zero
/* F4A34 802D0084 0C0B1EAF */  jal       get_variable
/* F4A38 802D0088 0040A02D */   daddu    $s4, $v0, $zero
/* F4A3C 802D008C 0220202D */  daddu     $a0, $s1, $zero
/* F4A40 802D0090 8E050000 */  lw        $a1, ($s0)
/* F4A44 802D0094 0C0B1EAF */  jal       get_variable
/* F4A48 802D0098 0040982D */   daddu    $s3, $v0, $zero
/* F4A4C 802D009C 0220202D */  daddu     $a0, $s1, $zero
/* F4A50 802D00A0 0240282D */  daddu     $a1, $s2, $zero
/* F4A54 802D00A4 0C0B36B0 */  jal       resolve_npc
/* F4A58 802D00A8 0040882D */   daddu    $s1, $v0, $zero
/* F4A5C 802D00AC 0040802D */  daddu     $s0, $v0, $zero
/* F4A60 802D00B0 1200000C */  beqz      $s0, .L802D00E4
/* F4A64 802D00B4 0200202D */   daddu    $a0, $s0, $zero
/* F4A68 802D00B8 03C0302D */  daddu     $a2, $fp, $zero
/* F4A6C 802D00BC 8FA50018 */  lw        $a1, 0x18($sp)
/* F4A70 802D00C0 02E0382D */  daddu     $a3, $s7, $zero
/* F4A74 802D00C4 0C00ED13 */  jal       func_8003B44C
/* F4A78 802D00C8 AFB60010 */   sw       $s6, 0x10($sp)
/* F4A7C 802D00CC 0200202D */  daddu     $a0, $s0, $zero
/* F4A80 802D00D0 02A0282D */  daddu     $a1, $s5, $zero
/* F4A84 802D00D4 0280302D */  daddu     $a2, $s4, $zero
/* F4A88 802D00D8 0260382D */  daddu     $a3, $s3, $zero
/* F4A8C 802D00DC 0C00ED19 */  jal       func_8003B464
/* F4A90 802D00E0 AFB10010 */   sw       $s1, 0x10($sp)
.L802D00E4:
/* F4A94 802D00E4 24020002 */  addiu     $v0, $zero, 2
/* F4A98 802D00E8 8FBF0044 */  lw        $ra, 0x44($sp)
/* F4A9C 802D00EC 8FBE0040 */  lw        $fp, 0x40($sp)
/* F4AA0 802D00F0 8FB7003C */  lw        $s7, 0x3c($sp)
/* F4AA4 802D00F4 8FB60038 */  lw        $s6, 0x38($sp)
/* F4AA8 802D00F8 8FB50034 */  lw        $s5, 0x34($sp)
/* F4AAC 802D00FC 8FB40030 */  lw        $s4, 0x30($sp)
/* F4AB0 802D0100 8FB3002C */  lw        $s3, 0x2c($sp)
/* F4AB4 802D0104 8FB20028 */  lw        $s2, 0x28($sp)
/* F4AB8 802D0108 8FB10024 */  lw        $s1, 0x24($sp)
/* F4ABC 802D010C 8FB00020 */  lw        $s0, 0x20($sp)
/* F4AC0 802D0110 03E00008 */  jr        $ra
/* F4AC4 802D0114 27BD0048 */   addiu    $sp, $sp, 0x48

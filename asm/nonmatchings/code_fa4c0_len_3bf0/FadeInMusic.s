.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel FadeInMusic
/* FA7A4 802D5DF4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* FA7A8 802D5DF8 AFB1001C */  sw        $s1, 0x1c($sp)
/* FA7AC 802D5DFC 0080882D */  daddu     $s1, $a0, $zero
/* FA7B0 802D5E00 AFBF0030 */  sw        $ra, 0x30($sp)
/* FA7B4 802D5E04 AFB5002C */  sw        $s5, 0x2c($sp)
/* FA7B8 802D5E08 AFB40028 */  sw        $s4, 0x28($sp)
/* FA7BC 802D5E0C AFB30024 */  sw        $s3, 0x24($sp)
/* FA7C0 802D5E10 AFB20020 */  sw        $s2, 0x20($sp)
/* FA7C4 802D5E14 AFB00018 */  sw        $s0, 0x18($sp)
/* FA7C8 802D5E18 8E30000C */  lw        $s0, 0xc($s1)
/* FA7CC 802D5E1C 8E050000 */  lw        $a1, ($s0)
/* FA7D0 802D5E20 0C0B1EAF */  jal       get_variable
/* FA7D4 802D5E24 26100004 */   addiu    $s0, $s0, 4
/* FA7D8 802D5E28 8E050000 */  lw        $a1, ($s0)
/* FA7DC 802D5E2C 26100004 */  addiu     $s0, $s0, 4
/* FA7E0 802D5E30 0220202D */  daddu     $a0, $s1, $zero
/* FA7E4 802D5E34 0C0B1EAF */  jal       get_variable
/* FA7E8 802D5E38 0040A82D */   daddu    $s5, $v0, $zero
/* FA7EC 802D5E3C 8E050000 */  lw        $a1, ($s0)
/* FA7F0 802D5E40 26100004 */  addiu     $s0, $s0, 4
/* FA7F4 802D5E44 0220202D */  daddu     $a0, $s1, $zero
/* FA7F8 802D5E48 0C0B1EAF */  jal       get_variable
/* FA7FC 802D5E4C 0040982D */   daddu    $s3, $v0, $zero
/* FA800 802D5E50 8E050000 */  lw        $a1, ($s0)
/* FA804 802D5E54 26100004 */  addiu     $s0, $s0, 4
/* FA808 802D5E58 0220202D */  daddu     $a0, $s1, $zero
/* FA80C 802D5E5C 0C0B1EAF */  jal       get_variable
/* FA810 802D5E60 0040A02D */   daddu    $s4, $v0, $zero
/* FA814 802D5E64 8E050000 */  lw        $a1, ($s0)
/* FA818 802D5E68 26100004 */  addiu     $s0, $s0, 4
/* FA81C 802D5E6C 0220202D */  daddu     $a0, $s1, $zero
/* FA820 802D5E70 0C0B1EAF */  jal       get_variable
/* FA824 802D5E74 0040902D */   daddu    $s2, $v0, $zero
/* FA828 802D5E78 0220202D */  daddu     $a0, $s1, $zero
/* FA82C 802D5E7C 8E050000 */  lw        $a1, ($s0)
/* FA830 802D5E80 0C0B1EAF */  jal       get_variable
/* FA834 802D5E84 0040802D */   daddu    $s0, $v0, $zero
/* FA838 802D5E88 02A0202D */  daddu     $a0, $s5, $zero
/* FA83C 802D5E8C 0260282D */  daddu     $a1, $s3, $zero
/* FA840 802D5E90 00108400 */  sll       $s0, $s0, 0x10
/* FA844 802D5E94 00108403 */  sra       $s0, $s0, 0x10
/* FA848 802D5E98 00021400 */  sll       $v0, $v0, 0x10
/* FA84C 802D5E9C 00021403 */  sra       $v0, $v0, 0x10
/* FA850 802D5EA0 0280302D */  daddu     $a2, $s4, $zero
/* FA854 802D5EA4 0240382D */  daddu     $a3, $s2, $zero
/* FA858 802D5EA8 AFB00010 */  sw        $s0, 0x10($sp)
/* FA85C 802D5EAC 0C052A59 */  jal       func_8014A964
/* FA860 802D5EB0 AFA20014 */   sw       $v0, 0x14($sp)
/* FA864 802D5EB4 0002102B */  sltu      $v0, $zero, $v0
/* FA868 802D5EB8 8FBF0030 */  lw        $ra, 0x30($sp)
/* FA86C 802D5EBC 8FB5002C */  lw        $s5, 0x2c($sp)
/* FA870 802D5EC0 8FB40028 */  lw        $s4, 0x28($sp)
/* FA874 802D5EC4 8FB30024 */  lw        $s3, 0x24($sp)
/* FA878 802D5EC8 8FB20020 */  lw        $s2, 0x20($sp)
/* FA87C 802D5ECC 8FB1001C */  lw        $s1, 0x1c($sp)
/* FA880 802D5ED0 8FB00018 */  lw        $s0, 0x18($sp)
/* FA884 802D5ED4 00021040 */  sll       $v0, $v0, 1
/* FA888 802D5ED8 03E00008 */  jr        $ra
/* FA88C 802D5EDC 27BD0038 */   addiu    $sp, $sp, 0x38

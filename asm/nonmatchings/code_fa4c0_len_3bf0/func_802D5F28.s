.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D5F28
/* FA8D8 802D5F28 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* FA8DC 802D5F2C AFB10014 */  sw        $s1, 0x14($sp)
/* FA8E0 802D5F30 0080882D */  daddu     $s1, $a0, $zero
/* FA8E4 802D5F34 AFBF001C */  sw        $ra, 0x1c($sp)
/* FA8E8 802D5F38 AFB20018 */  sw        $s2, 0x18($sp)
/* FA8EC 802D5F3C AFB00010 */  sw        $s0, 0x10($sp)
/* FA8F0 802D5F40 8E30000C */  lw        $s0, 0xc($s1)
/* FA8F4 802D5F44 8E050000 */  lw        $a1, ($s0)
/* FA8F8 802D5F48 0C0B1EAF */  jal       get_variable
/* FA8FC 802D5F4C 26100004 */   addiu    $s0, $s0, 4
/* FA900 802D5F50 8E050000 */  lw        $a1, ($s0)
/* FA904 802D5F54 26100004 */  addiu     $s0, $s0, 4
/* FA908 802D5F58 0220202D */  daddu     $a0, $s1, $zero
/* FA90C 802D5F5C 0C0B1EAF */  jal       get_variable
/* FA910 802D5F60 0040902D */   daddu    $s2, $v0, $zero
/* FA914 802D5F64 0220202D */  daddu     $a0, $s1, $zero
/* FA918 802D5F68 8E050000 */  lw        $a1, ($s0)
/* FA91C 802D5F6C 0C0B1EAF */  jal       get_variable
/* FA920 802D5F70 0040802D */   daddu    $s0, $v0, $zero
/* FA924 802D5F74 0240202D */  daddu     $a0, $s2, $zero
/* FA928 802D5F78 0200282D */  daddu     $a1, $s0, $zero
/* FA92C 802D5F7C 00021400 */  sll       $v0, $v0, 0x10
/* FA930 802D5F80 0C052A95 */  jal       func_8014AA54
/* FA934 802D5F84 00023403 */   sra      $a2, $v0, 0x10
/* FA938 802D5F88 8FBF001C */  lw        $ra, 0x1c($sp)
/* FA93C 802D5F8C 8FB20018 */  lw        $s2, 0x18($sp)
/* FA940 802D5F90 8FB10014 */  lw        $s1, 0x14($sp)
/* FA944 802D5F94 8FB00010 */  lw        $s0, 0x10($sp)
/* FA948 802D5F98 24020002 */  addiu     $v0, $zero, 2
/* FA94C 802D5F9C 03E00008 */  jr        $ra
/* FA950 802D5FA0 27BD0020 */   addiu    $sp, $sp, 0x20

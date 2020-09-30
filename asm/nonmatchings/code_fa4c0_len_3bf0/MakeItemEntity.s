.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel MakeItemEntity
/* FB670 802D6CC0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* FB674 802D6CC4 AFB1001C */  sw        $s1, 0x1c($sp)
/* FB678 802D6CC8 0080882D */  daddu     $s1, $a0, $zero
/* FB67C 802D6CCC AFBF0030 */  sw        $ra, 0x30($sp)
/* FB680 802D6CD0 AFB5002C */  sw        $s5, 0x2c($sp)
/* FB684 802D6CD4 AFB40028 */  sw        $s4, 0x28($sp)
/* FB688 802D6CD8 AFB30024 */  sw        $s3, 0x24($sp)
/* FB68C 802D6CDC AFB20020 */  sw        $s2, 0x20($sp)
/* FB690 802D6CE0 AFB00018 */  sw        $s0, 0x18($sp)
/* FB694 802D6CE4 8E30000C */  lw        $s0, 0xc($s1)
/* FB698 802D6CE8 8E050000 */  lw        $a1, ($s0)
/* FB69C 802D6CEC 0C0B1EAF */  jal       get_variable
/* FB6A0 802D6CF0 26100004 */   addiu    $s0, $s0, 4
/* FB6A4 802D6CF4 8E050000 */  lw        $a1, ($s0)
/* FB6A8 802D6CF8 26100004 */  addiu     $s0, $s0, 4
/* FB6AC 802D6CFC 0220202D */  daddu     $a0, $s1, $zero
/* FB6B0 802D6D00 0C0B1EAF */  jal       get_variable
/* FB6B4 802D6D04 0040A82D */   daddu    $s5, $v0, $zero
/* FB6B8 802D6D08 8E050000 */  lw        $a1, ($s0)
/* FB6BC 802D6D0C 26100004 */  addiu     $s0, $s0, 4
/* FB6C0 802D6D10 0220202D */  daddu     $a0, $s1, $zero
/* FB6C4 802D6D14 0C0B1EAF */  jal       get_variable
/* FB6C8 802D6D18 0040A02D */   daddu    $s4, $v0, $zero
/* FB6CC 802D6D1C 8E050000 */  lw        $a1, ($s0)
/* FB6D0 802D6D20 26100004 */  addiu     $s0, $s0, 4
/* FB6D4 802D6D24 0220202D */  daddu     $a0, $s1, $zero
/* FB6D8 802D6D28 0C0B1EAF */  jal       get_variable
/* FB6DC 802D6D2C 0040982D */   daddu    $s3, $v0, $zero
/* FB6E0 802D6D30 8E050000 */  lw        $a1, ($s0)
/* FB6E4 802D6D34 26100004 */  addiu     $s0, $s0, 4
/* FB6E8 802D6D38 0220202D */  daddu     $a0, $s1, $zero
/* FB6EC 802D6D3C 0C0B1EAF */  jal       get_variable
/* FB6F0 802D6D40 0040902D */   daddu    $s2, $v0, $zero
/* FB6F4 802D6D44 0220202D */  daddu     $a0, $s1, $zero
/* FB6F8 802D6D48 8E050000 */  lw        $a1, ($s0)
/* FB6FC 802D6D4C 0C0B1F6A */  jal       get_variable_index
/* FB700 802D6D50 0040802D */   daddu    $s0, $v0, $zero
/* FB704 802D6D54 44940000 */  mtc1      $s4, $f0
/* FB708 802D6D58 00000000 */  nop       
/* FB70C 802D6D5C 46800020 */  cvt.s.w   $f0, $f0
/* FB710 802D6D60 44050000 */  mfc1      $a1, $f0
/* FB714 802D6D64 44930000 */  mtc1      $s3, $f0
/* FB718 802D6D68 00000000 */  nop       
/* FB71C 802D6D6C 46800020 */  cvt.s.w   $f0, $f0
/* FB720 802D6D70 44060000 */  mfc1      $a2, $f0
/* FB724 802D6D74 44920000 */  mtc1      $s2, $f0
/* FB728 802D6D78 00000000 */  nop       
/* FB72C 802D6D7C 46800020 */  cvt.s.w   $f0, $f0
/* FB730 802D6D80 44070000 */  mfc1      $a3, $f0
/* FB734 802D6D84 02A0202D */  daddu     $a0, $s5, $zero
/* FB738 802D6D88 AFB00010 */  sw        $s0, 0x10($sp)
/* FB73C 802D6D8C 0C04C6A5 */  jal       make_item_entity_nodelay
/* FB740 802D6D90 AFA20014 */   sw       $v0, 0x14($sp)
/* FB744 802D6D94 AE220084 */  sw        $v0, 0x84($s1)
/* FB748 802D6D98 8FBF0030 */  lw        $ra, 0x30($sp)
/* FB74C 802D6D9C 8FB5002C */  lw        $s5, 0x2c($sp)
/* FB750 802D6DA0 8FB40028 */  lw        $s4, 0x28($sp)
/* FB754 802D6DA4 8FB30024 */  lw        $s3, 0x24($sp)
/* FB758 802D6DA8 8FB20020 */  lw        $s2, 0x20($sp)
/* FB75C 802D6DAC 8FB1001C */  lw        $s1, 0x1c($sp)
/* FB760 802D6DB0 8FB00018 */  lw        $s0, 0x18($sp)
/* FB764 802D6DB4 24020002 */  addiu     $v0, $zero, 2
/* FB768 802D6DB8 03E00008 */  jr        $ra
/* FB76C 802D6DBC 27BD0038 */   addiu    $sp, $sp, 0x38

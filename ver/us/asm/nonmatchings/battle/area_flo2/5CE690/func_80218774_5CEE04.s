.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218774_5CEE04
/* 5CEE04 80218774 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* 5CEE08 80218778 AFB10024 */  sw        $s1, 0x24($sp)
/* 5CEE0C 8021877C 0080882D */  daddu     $s1, $a0, $zero
/* 5CEE10 80218780 AFBF002C */  sw        $ra, 0x2c($sp)
/* 5CEE14 80218784 AFB20028 */  sw        $s2, 0x28($sp)
/* 5CEE18 80218788 AFB00020 */  sw        $s0, 0x20($sp)
/* 5CEE1C 8021878C F7BE0058 */  sdc1      $f30, 0x58($sp)
/* 5CEE20 80218790 F7BC0050 */  sdc1      $f28, 0x50($sp)
/* 5CEE24 80218794 F7BA0048 */  sdc1      $f26, 0x48($sp)
/* 5CEE28 80218798 F7B80040 */  sdc1      $f24, 0x40($sp)
/* 5CEE2C 8021879C F7B60038 */  sdc1      $f22, 0x38($sp)
/* 5CEE30 802187A0 F7B40030 */  sdc1      $f20, 0x30($sp)
/* 5CEE34 802187A4 8E30000C */  lw        $s0, 0xc($s1)
/* 5CEE38 802187A8 8E050000 */  lw        $a1, ($s0)
/* 5CEE3C 802187AC 0C0B1EAF */  jal       get_variable
/* 5CEE40 802187B0 26100004 */   addiu    $s0, $s0, 4
/* 5CEE44 802187B4 8E050000 */  lw        $a1, ($s0)
/* 5CEE48 802187B8 26100004 */  addiu     $s0, $s0, 4
/* 5CEE4C 802187BC 0220202D */  daddu     $a0, $s1, $zero
/* 5CEE50 802187C0 0C0B210B */  jal       get_float_variable
/* 5CEE54 802187C4 0040902D */   daddu    $s2, $v0, $zero
/* 5CEE58 802187C8 8E050000 */  lw        $a1, ($s0)
/* 5CEE5C 802187CC 26100004 */  addiu     $s0, $s0, 4
/* 5CEE60 802187D0 0220202D */  daddu     $a0, $s1, $zero
/* 5CEE64 802187D4 0C0B210B */  jal       get_float_variable
/* 5CEE68 802187D8 46000786 */   mov.s    $f30, $f0
/* 5CEE6C 802187DC 8E050000 */  lw        $a1, ($s0)
/* 5CEE70 802187E0 26100004 */  addiu     $s0, $s0, 4
/* 5CEE74 802187E4 0220202D */  daddu     $a0, $s1, $zero
/* 5CEE78 802187E8 0C0B210B */  jal       get_float_variable
/* 5CEE7C 802187EC 46000706 */   mov.s    $f28, $f0
/* 5CEE80 802187F0 8E050000 */  lw        $a1, ($s0)
/* 5CEE84 802187F4 26100004 */  addiu     $s0, $s0, 4
/* 5CEE88 802187F8 0220202D */  daddu     $a0, $s1, $zero
/* 5CEE8C 802187FC 0C0B210B */  jal       get_float_variable
/* 5CEE90 80218800 46000686 */   mov.s    $f26, $f0
/* 5CEE94 80218804 8E050000 */  lw        $a1, ($s0)
/* 5CEE98 80218808 26100004 */  addiu     $s0, $s0, 4
/* 5CEE9C 8021880C 0220202D */  daddu     $a0, $s1, $zero
/* 5CEEA0 80218810 0C0B210B */  jal       get_float_variable
/* 5CEEA4 80218814 46000606 */   mov.s    $f24, $f0
/* 5CEEA8 80218818 8E050000 */  lw        $a1, ($s0)
/* 5CEEAC 8021881C 26100004 */  addiu     $s0, $s0, 4
/* 5CEEB0 80218820 0220202D */  daddu     $a0, $s1, $zero
/* 5CEEB4 80218824 0C0B210B */  jal       get_float_variable
/* 5CEEB8 80218828 46000586 */   mov.s    $f22, $f0
/* 5CEEBC 8021882C 8E050000 */  lw        $a1, ($s0)
/* 5CEEC0 80218830 26100004 */  addiu     $s0, $s0, 4
/* 5CEEC4 80218834 0220202D */  daddu     $a0, $s1, $zero
/* 5CEEC8 80218838 0C0B1EAF */  jal       get_variable
/* 5CEECC 8021883C 46000506 */   mov.s    $f20, $f0
/* 5CEED0 80218840 4405F000 */  mfc1      $a1, $f30
/* 5CEED4 80218844 4406E000 */  mfc1      $a2, $f28
/* 5CEED8 80218848 4407D000 */  mfc1      $a3, $f26
/* 5CEEDC 8021884C 0240202D */  daddu     $a0, $s2, $zero
/* 5CEEE0 80218850 E7B80010 */  swc1      $f24, 0x10($sp)
/* 5CEEE4 80218854 E7B60014 */  swc1      $f22, 0x14($sp)
/* 5CEEE8 80218858 E7B40018 */  swc1      $f20, 0x18($sp)
/* 5CEEEC 8021885C 0C01C874 */  jal       playFX_6E
/* 5CEEF0 80218860 AFA2001C */   sw       $v0, 0x1c($sp)
/* 5CEEF4 80218864 0220202D */  daddu     $a0, $s1, $zero
/* 5CEEF8 80218868 8E050000 */  lw        $a1, ($s0)
/* 5CEEFC 8021886C 0C0B2026 */  jal       set_variable
/* 5CEF00 80218870 0040302D */   daddu    $a2, $v0, $zero
/* 5CEF04 80218874 8FBF002C */  lw        $ra, 0x2c($sp)
/* 5CEF08 80218878 8FB20028 */  lw        $s2, 0x28($sp)
/* 5CEF0C 8021887C 8FB10024 */  lw        $s1, 0x24($sp)
/* 5CEF10 80218880 8FB00020 */  lw        $s0, 0x20($sp)
/* 5CEF14 80218884 D7BE0058 */  ldc1      $f30, 0x58($sp)
/* 5CEF18 80218888 D7BC0050 */  ldc1      $f28, 0x50($sp)
/* 5CEF1C 8021888C D7BA0048 */  ldc1      $f26, 0x48($sp)
/* 5CEF20 80218890 D7B80040 */  ldc1      $f24, 0x40($sp)
/* 5CEF24 80218894 D7B60038 */  ldc1      $f22, 0x38($sp)
/* 5CEF28 80218898 D7B40030 */  ldc1      $f20, 0x30($sp)
/* 5CEF2C 8021889C 24020002 */  addiu     $v0, $zero, 2
/* 5CEF30 802188A0 03E00008 */  jr        $ra
/* 5CEF34 802188A4 27BD0060 */   addiu    $sp, $sp, 0x60

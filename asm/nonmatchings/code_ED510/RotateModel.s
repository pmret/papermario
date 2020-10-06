.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel RotateModel
/* ED614 802C8C64 27BDFF78 */  addiu     $sp, $sp, -0x88
/* ED618 802C8C68 AFB1005C */  sw        $s1, 0x5c($sp)
/* ED61C 802C8C6C 0080882D */  daddu     $s1, $a0, $zero
/* ED620 802C8C70 AFBF0064 */  sw        $ra, 0x64($sp)
/* ED624 802C8C74 AFB20060 */  sw        $s2, 0x60($sp)
/* ED628 802C8C78 AFB00058 */  sw        $s0, 0x58($sp)
/* ED62C 802C8C7C F7BA0080 */  sdc1      $f26, 0x80($sp)
/* ED630 802C8C80 F7B80078 */  sdc1      $f24, 0x78($sp)
/* ED634 802C8C84 F7B60070 */  sdc1      $f22, 0x70($sp)
/* ED638 802C8C88 F7B40068 */  sdc1      $f20, 0x68($sp)
/* ED63C 802C8C8C 8E30000C */  lw        $s0, 0xc($s1)
/* ED640 802C8C90 8E050000 */  lw        $a1, ($s0)
/* ED644 802C8C94 0C0B1EAF */  jal       get_variable
/* ED648 802C8C98 26100004 */   addiu    $s0, $s0, 4
/* ED64C 802C8C9C 0C046C04 */  jal       get_model_list_index_from_tree_index
/* ED650 802C8CA0 0040202D */   daddu    $a0, $v0, $zero
/* ED654 802C8CA4 8E050000 */  lw        $a1, ($s0)
/* ED658 802C8CA8 26100004 */  addiu     $s0, $s0, 4
/* ED65C 802C8CAC 0220202D */  daddu     $a0, $s1, $zero
/* ED660 802C8CB0 0C0B210B */  jal       get_float_variable
/* ED664 802C8CB4 0040902D */   daddu    $s2, $v0, $zero
/* ED668 802C8CB8 8E050000 */  lw        $a1, ($s0)
/* ED66C 802C8CBC 26100004 */  addiu     $s0, $s0, 4
/* ED670 802C8CC0 0220202D */  daddu     $a0, $s1, $zero
/* ED674 802C8CC4 0C0B210B */  jal       get_float_variable
/* ED678 802C8CC8 46000686 */   mov.s    $f26, $f0
/* ED67C 802C8CCC 8E050000 */  lw        $a1, ($s0)
/* ED680 802C8CD0 26100004 */  addiu     $s0, $s0, 4
/* ED684 802C8CD4 0220202D */  daddu     $a0, $s1, $zero
/* ED688 802C8CD8 0C0B210B */  jal       get_float_variable
/* ED68C 802C8CDC 46000606 */   mov.s    $f24, $f0
/* ED690 802C8CE0 0220202D */  daddu     $a0, $s1, $zero
/* ED694 802C8CE4 8E050000 */  lw        $a1, ($s0)
/* ED698 802C8CE8 0C0B210B */  jal       get_float_variable
/* ED69C 802C8CEC 46000506 */   mov.s    $f20, $f0
/* ED6A0 802C8CF0 0240202D */  daddu     $a0, $s2, $zero
/* ED6A4 802C8CF4 0C046B4C */  jal       get_model_from_list_index
/* ED6A8 802C8CF8 46000586 */   mov.s    $f22, $f0
/* ED6AC 802C8CFC 0040802D */  daddu     $s0, $v0, $zero
/* ED6B0 802C8D00 96020000 */  lhu       $v0, ($s0)
/* ED6B4 802C8D04 30420400 */  andi      $v0, $v0, 0x400
/* ED6B8 802C8D08 1440000B */  bnez      $v0, .L802C8D38
/* ED6BC 802C8D0C 27A40018 */   addiu    $a0, $sp, 0x18
/* ED6C0 802C8D10 4405D000 */  mfc1      $a1, $f26
/* ED6C4 802C8D14 4406C000 */  mfc1      $a2, $f24
/* ED6C8 802C8D18 4407A000 */  mfc1      $a3, $f20
/* ED6CC 802C8D1C 26040058 */  addiu     $a0, $s0, 0x58
/* ED6D0 802C8D20 0C019EC8 */  jal       guRotateF
/* ED6D4 802C8D24 E7B60010 */   swc1     $f22, 0x10($sp)
/* ED6D8 802C8D28 96020000 */  lhu       $v0, ($s0)
/* ED6DC 802C8D2C 34421400 */  ori       $v0, $v0, 0x1400
/* ED6E0 802C8D30 080B2357 */  j         .L802C8D5C
/* ED6E4 802C8D34 A6020000 */   sh       $v0, ($s0)
.L802C8D38:
/* ED6E8 802C8D38 4405D000 */  mfc1      $a1, $f26
/* ED6EC 802C8D3C 4406C000 */  mfc1      $a2, $f24
/* ED6F0 802C8D40 4407A000 */  mfc1      $a3, $f20
/* ED6F4 802C8D44 0C019EC8 */  jal       guRotateF
/* ED6F8 802C8D48 E7B60010 */   swc1     $f22, 0x10($sp)
/* ED6FC 802C8D4C 27A40018 */  addiu     $a0, $sp, 0x18
/* ED700 802C8D50 26050058 */  addiu     $a1, $s0, 0x58
/* ED704 802C8D54 0C019D80 */  jal       guMtxCatF
/* ED708 802C8D58 00A0302D */   daddu    $a2, $a1, $zero
.L802C8D5C:
/* ED70C 802C8D5C 8FBF0064 */  lw        $ra, 0x64($sp)
/* ED710 802C8D60 8FB20060 */  lw        $s2, 0x60($sp)
/* ED714 802C8D64 8FB1005C */  lw        $s1, 0x5c($sp)
/* ED718 802C8D68 8FB00058 */  lw        $s0, 0x58($sp)
/* ED71C 802C8D6C D7BA0080 */  ldc1      $f26, 0x80($sp)
/* ED720 802C8D70 D7B80078 */  ldc1      $f24, 0x78($sp)
/* ED724 802C8D74 D7B60070 */  ldc1      $f22, 0x70($sp)
/* ED728 802C8D78 D7B40068 */  ldc1      $f20, 0x68($sp)
/* ED72C 802C8D7C 24020002 */  addiu     $v0, $zero, 2
/* ED730 802C8D80 03E00008 */  jr        $ra
/* ED734 802C8D84 27BD0088 */   addiu    $sp, $sp, 0x88

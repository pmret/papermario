.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetNpcRotation
/* F2760 802CDDB0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* F2764 802CDDB4 AFB10014 */  sw        $s1, 0x14($sp)
/* F2768 802CDDB8 0080882D */  daddu     $s1, $a0, $zero
/* F276C 802CDDBC AFBF001C */  sw        $ra, 0x1c($sp)
/* F2770 802CDDC0 AFB20018 */  sw        $s2, 0x18($sp)
/* F2774 802CDDC4 AFB00010 */  sw        $s0, 0x10($sp)
/* F2778 802CDDC8 F7B80030 */  sdc1      $f24, 0x30($sp)
/* F277C 802CDDCC F7B60028 */  sdc1      $f22, 0x28($sp)
/* F2780 802CDDD0 F7B40020 */  sdc1      $f20, 0x20($sp)
/* F2784 802CDDD4 8E30000C */  lw        $s0, 0xc($s1)
/* F2788 802CDDD8 8E050000 */  lw        $a1, ($s0)
/* F278C 802CDDDC 0C0B1EAF */  jal       get_variable
/* F2790 802CDDE0 26100004 */   addiu    $s0, $s0, 4
/* F2794 802CDDE4 8E050000 */  lw        $a1, ($s0)
/* F2798 802CDDE8 26100004 */  addiu     $s0, $s0, 4
/* F279C 802CDDEC 0220202D */  daddu     $a0, $s1, $zero
/* F27A0 802CDDF0 0C0B210B */  jal       get_float_variable
/* F27A4 802CDDF4 0040902D */   daddu    $s2, $v0, $zero
/* F27A8 802CDDF8 8E050000 */  lw        $a1, ($s0)
/* F27AC 802CDDFC 26100004 */  addiu     $s0, $s0, 4
/* F27B0 802CDE00 0220202D */  daddu     $a0, $s1, $zero
/* F27B4 802CDE04 0C0B210B */  jal       get_float_variable
/* F27B8 802CDE08 46000606 */   mov.s    $f24, $f0
/* F27BC 802CDE0C 0220202D */  daddu     $a0, $s1, $zero
/* F27C0 802CDE10 8E050000 */  lw        $a1, ($s0)
/* F27C4 802CDE14 0C0B210B */  jal       get_float_variable
/* F27C8 802CDE18 46000586 */   mov.s    $f22, $f0
/* F27CC 802CDE1C 0220202D */  daddu     $a0, $s1, $zero
/* F27D0 802CDE20 0240282D */  daddu     $a1, $s2, $zero
/* F27D4 802CDE24 0C0B36B0 */  jal       resolve_npc
/* F27D8 802CDE28 46000506 */   mov.s    $f20, $f0
/* F27DC 802CDE2C 0040182D */  daddu     $v1, $v0, $zero
/* F27E0 802CDE30 10600004 */  beqz      $v1, .L802CDE44
/* F27E4 802CDE34 24020002 */   addiu    $v0, $zero, 2
/* F27E8 802CDE38 E4780044 */  swc1      $f24, 0x44($v1)
/* F27EC 802CDE3C E4760048 */  swc1      $f22, 0x48($v1)
/* F27F0 802CDE40 E474004C */  swc1      $f20, 0x4c($v1)
.L802CDE44:
/* F27F4 802CDE44 8FBF001C */  lw        $ra, 0x1c($sp)
/* F27F8 802CDE48 8FB20018 */  lw        $s2, 0x18($sp)
/* F27FC 802CDE4C 8FB10014 */  lw        $s1, 0x14($sp)
/* F2800 802CDE50 8FB00010 */  lw        $s0, 0x10($sp)
/* F2804 802CDE54 D7B80030 */  ldc1      $f24, 0x30($sp)
/* F2808 802CDE58 D7B60028 */  ldc1      $f22, 0x28($sp)
/* F280C 802CDE5C D7B40020 */  ldc1      $f20, 0x20($sp)
/* F2810 802CDE60 03E00008 */  jr        $ra
/* F2814 802CDE64 27BD0038 */   addiu    $sp, $sp, 0x38

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024077C
/* A39C5C 8024077C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A39C60 80240780 AFB10014 */  sw        $s1, 0x14($sp)
/* A39C64 80240784 0080882D */  daddu     $s1, $a0, $zero
/* A39C68 80240788 AFBF0018 */  sw        $ra, 0x18($sp)
/* A39C6C 8024078C AFB00010 */  sw        $s0, 0x10($sp)
/* A39C70 80240790 8E30000C */  lw        $s0, 0xc($s1)
/* A39C74 80240794 8E050000 */  lw        $a1, ($s0)
/* A39C78 80240798 0C0B1EAF */  jal       get_variable
/* A39C7C 8024079C 26100004 */   addiu    $s0, $s0, 4
/* A39C80 802407A0 AE22008C */  sw        $v0, 0x8c($s1)
/* A39C84 802407A4 8E050000 */  lw        $a1, ($s0)
/* A39C88 802407A8 26100004 */  addiu     $s0, $s0, 4
/* A39C8C 802407AC 0C0B1EAF */  jal       get_variable
/* A39C90 802407B0 0220202D */   daddu    $a0, $s1, $zero
/* A39C94 802407B4 AE220090 */  sw        $v0, 0x90($s1)
/* A39C98 802407B8 8E050000 */  lw        $a1, ($s0)
/* A39C9C 802407BC 26100004 */  addiu     $s0, $s0, 4
/* A39CA0 802407C0 0C0B1EAF */  jal       get_variable
/* A39CA4 802407C4 0220202D */   daddu    $a0, $s1, $zero
/* A39CA8 802407C8 AE220094 */  sw        $v0, 0x94($s1)
/* A39CAC 802407CC 8E050000 */  lw        $a1, ($s0)
/* A39CB0 802407D0 26100004 */  addiu     $s0, $s0, 4
/* A39CB4 802407D4 0C0B1EAF */  jal       get_variable
/* A39CB8 802407D8 0220202D */   daddu    $a0, $s1, $zero
/* A39CBC 802407DC AE220098 */  sw        $v0, 0x98($s1)
/* A39CC0 802407E0 8E050000 */  lw        $a1, ($s0)
/* A39CC4 802407E4 26100004 */  addiu     $s0, $s0, 4
/* A39CC8 802407E8 0C0B1EAF */  jal       get_variable
/* A39CCC 802407EC 0220202D */   daddu    $a0, $s1, $zero
/* A39CD0 802407F0 AE22009C */  sw        $v0, 0x9c($s1)
/* A39CD4 802407F4 8E050000 */  lw        $a1, ($s0)
/* A39CD8 802407F8 26100004 */  addiu     $s0, $s0, 4
/* A39CDC 802407FC 0C0B1EAF */  jal       get_variable
/* A39CE0 80240800 0220202D */   daddu    $a0, $s1, $zero
/* A39CE4 80240804 AE2200A0 */  sw        $v0, 0xa0($s1)
/* A39CE8 80240808 8E050000 */  lw        $a1, ($s0)
/* A39CEC 8024080C 26100004 */  addiu     $s0, $s0, 4
/* A39CF0 80240810 0C0B1EAF */  jal       get_variable
/* A39CF4 80240814 0220202D */   daddu    $a0, $s1, $zero
/* A39CF8 80240818 AE2200A4 */  sw        $v0, 0xa4($s1)
/* A39CFC 8024081C 8E050000 */  lw        $a1, ($s0)
/* A39D00 80240820 26100004 */  addiu     $s0, $s0, 4
/* A39D04 80240824 0C0B1EAF */  jal       get_variable
/* A39D08 80240828 0220202D */   daddu    $a0, $s1, $zero
/* A39D0C 8024082C AE2200A8 */  sw        $v0, 0xa8($s1)
/* A39D10 80240830 8E050000 */  lw        $a1, ($s0)
/* A39D14 80240834 26100004 */  addiu     $s0, $s0, 4
/* A39D18 80240838 0C0B1EAF */  jal       get_variable
/* A39D1C 8024083C 0220202D */   daddu    $a0, $s1, $zero
/* A39D20 80240840 AE2200AC */  sw        $v0, 0xac($s1)
/* A39D24 80240844 8E050000 */  lw        $a1, ($s0)
/* A39D28 80240848 0C0B1EAF */  jal       get_variable
/* A39D2C 8024084C 0220202D */   daddu    $a0, $s1, $zero
/* A39D30 80240850 AE2200B0 */  sw        $v0, 0xb0($s1)
/* A39D34 80240854 8FBF0018 */  lw        $ra, 0x18($sp)
/* A39D38 80240858 8FB10014 */  lw        $s1, 0x14($sp)
/* A39D3C 8024085C 8FB00010 */  lw        $s0, 0x10($sp)
/* A39D40 80240860 24020002 */  addiu     $v0, $zero, 2
/* A39D44 80240864 03E00008 */  jr        $ra
/* A39D48 80240868 27BD0020 */   addiu    $sp, $sp, 0x20

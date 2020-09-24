.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetSelfAnimationFromTable
/* 20B34 80045734 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 20B38 80045738 AFB10014 */  sw        $s1, 0x14($sp)
/* 20B3C 8004573C 0080882D */  daddu     $s1, $a0, $zero
/* 20B40 80045740 AFBF001C */  sw        $ra, 0x1c($sp)
/* 20B44 80045744 AFB20018 */  sw        $s2, 0x18($sp)
/* 20B48 80045748 AFB00010 */  sw        $s0, 0x10($sp)
/* 20B4C 8004574C 8E30000C */  lw        $s0, 0xc($s1)
/* 20B50 80045750 8E320148 */  lw        $s2, 0x148($s1)
/* 20B54 80045754 8E050000 */  lw        $a1, ($s0)
/* 20B58 80045758 0C0B1EAF */  jal       get_variable
/* 20B5C 8004575C 26100004 */   addiu    $s0, $s0, 4
/* 20B60 80045760 00021080 */  sll       $v0, $v0, 2
/* 20B64 80045764 8E4300CC */  lw        $v1, 0xcc($s2)
/* 20B68 80045768 8E050000 */  lw        $a1, ($s0)
/* 20B6C 8004576C 00431021 */  addu      $v0, $v0, $v1
/* 20B70 80045770 8C460000 */  lw        $a2, ($v0)
/* 20B74 80045774 0C0B2026 */  jal       set_variable
/* 20B78 80045778 0220202D */   daddu    $a0, $s1, $zero
/* 20B7C 8004577C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 20B80 80045780 8FB20018 */  lw        $s2, 0x18($sp)
/* 20B84 80045784 8FB10014 */  lw        $s1, 0x14($sp)
/* 20B88 80045788 8FB00010 */  lw        $s0, 0x10($sp)
/* 20B8C 8004578C 24020002 */  addiu     $v0, $zero, 2
/* 20B90 80045790 03E00008 */  jr        $ra
/* 20B94 80045794 27BD0020 */   addiu    $sp, $sp, 0x20

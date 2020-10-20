.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240734
/* 8754F4 80240734 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8754F8 80240738 AFB00010 */  sw        $s0, 0x10($sp)
/* 8754FC 8024073C 0080802D */  daddu     $s0, $a0, $zero
/* 875500 80240740 AFBF0018 */  sw        $ra, 0x18($sp)
/* 875504 80240744 AFB10014 */  sw        $s1, 0x14($sp)
/* 875508 80240748 8E02000C */  lw        $v0, 0xc($s0)
/* 87550C 8024074C 8C510000 */  lw        $s1, ($v0)
/* 875510 80240750 0C0B1EAF */  jal       get_variable
/* 875514 80240754 0220282D */   daddu    $a1, $s1, $zero
/* 875518 80240758 3C03FFF0 */  lui       $v1, 0xfff0
/* 87551C 8024075C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 875520 80240760 0200202D */  daddu     $a0, $s0, $zero
/* 875524 80240764 00431024 */  and       $v0, $v0, $v1
/* 875528 80240768 00021140 */  sll       $v0, $v0, 5
/* 87552C 8024076C 3C068008 */  lui       $a2, %hi(gItemTable)
/* 875530 80240770 00C23021 */  addu      $a2, $a2, $v0
/* 875534 80240774 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 875538 80240778 0C0B2026 */  jal       set_variable
/* 87553C 8024077C 0220282D */   daddu    $a1, $s1, $zero
/* 875540 80240780 8FBF0018 */  lw        $ra, 0x18($sp)
/* 875544 80240784 8FB10014 */  lw        $s1, 0x14($sp)
/* 875548 80240788 8FB00010 */  lw        $s0, 0x10($sp)
/* 87554C 8024078C 24020002 */  addiu     $v0, $zero, 2
/* 875550 80240790 03E00008 */  jr        $ra
/* 875554 80240794 27BD0020 */   addiu    $sp, $sp, 0x20

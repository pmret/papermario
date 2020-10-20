.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243514_95E714
/* 95E714 80243514 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 95E718 80243518 AFB00010 */  sw        $s0, 0x10($sp)
/* 95E71C 8024351C 0080802D */  daddu     $s0, $a0, $zero
/* 95E720 80243520 AFBF0018 */  sw        $ra, 0x18($sp)
/* 95E724 80243524 AFB10014 */  sw        $s1, 0x14($sp)
/* 95E728 80243528 8E02000C */  lw        $v0, 0xc($s0)
/* 95E72C 8024352C 8C510000 */  lw        $s1, ($v0)
/* 95E730 80243530 0C0B1EAF */  jal       get_variable
/* 95E734 80243534 0220282D */   daddu    $a1, $s1, $zero
/* 95E738 80243538 3C03FFF0 */  lui       $v1, 0xfff0
/* 95E73C 8024353C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 95E740 80243540 0200202D */  daddu     $a0, $s0, $zero
/* 95E744 80243544 00431024 */  and       $v0, $v0, $v1
/* 95E748 80243548 00021140 */  sll       $v0, $v0, 5
/* 95E74C 8024354C 3C068008 */  lui       $a2, %hi(gItemTable)
/* 95E750 80243550 00C23021 */  addu      $a2, $a2, $v0
/* 95E754 80243554 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 95E758 80243558 0C0B2026 */  jal       set_variable
/* 95E75C 8024355C 0220282D */   daddu    $a1, $s1, $zero
/* 95E760 80243560 8FBF0018 */  lw        $ra, 0x18($sp)
/* 95E764 80243564 8FB10014 */  lw        $s1, 0x14($sp)
/* 95E768 80243568 8FB00010 */  lw        $s0, 0x10($sp)
/* 95E76C 8024356C 24020002 */  addiu     $v0, $zero, 2
/* 95E770 80243570 03E00008 */  jr        $ra
/* 95E774 80243574 27BD0020 */   addiu    $sp, $sp, 0x20

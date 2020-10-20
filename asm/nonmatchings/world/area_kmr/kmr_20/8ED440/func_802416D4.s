.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416D4
/* 8ED4F4 802416D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8ED4F8 802416D8 AFB00010 */  sw        $s0, 0x10($sp)
/* 8ED4FC 802416DC 0080802D */  daddu     $s0, $a0, $zero
/* 8ED500 802416E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8ED504 802416E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 8ED508 802416E8 8E02000C */  lw        $v0, 0xc($s0)
/* 8ED50C 802416EC 8C510000 */  lw        $s1, ($v0)
/* 8ED510 802416F0 0C0B1EAF */  jal       get_variable
/* 8ED514 802416F4 0220282D */   daddu    $a1, $s1, $zero
/* 8ED518 802416F8 3C03FFF0 */  lui       $v1, 0xfff0
/* 8ED51C 802416FC 3463FFFF */  ori       $v1, $v1, 0xffff
/* 8ED520 80241700 0200202D */  daddu     $a0, $s0, $zero
/* 8ED524 80241704 00431024 */  and       $v0, $v0, $v1
/* 8ED528 80241708 00021140 */  sll       $v0, $v0, 5
/* 8ED52C 8024170C 3C068008 */  lui       $a2, %hi(gItemTable)
/* 8ED530 80241710 00C23021 */  addu      $a2, $a2, $v0
/* 8ED534 80241714 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 8ED538 80241718 0C0B2026 */  jal       set_variable
/* 8ED53C 8024171C 0220282D */   daddu    $a1, $s1, $zero
/* 8ED540 80241720 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8ED544 80241724 8FB10014 */  lw        $s1, 0x14($sp)
/* 8ED548 80241728 8FB00010 */  lw        $s0, 0x10($sp)
/* 8ED54C 8024172C 24020002 */  addiu     $v0, $zero, 2
/* 8ED550 80241730 03E00008 */  jr        $ra
/* 8ED554 80241734 27BD0020 */   addiu    $sp, $sp, 0x20

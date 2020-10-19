.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241524
/* 95C724 80241524 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 95C728 80241528 AFB00010 */  sw        $s0, 0x10($sp)
/* 95C72C 8024152C 0080802D */  daddu     $s0, $a0, $zero
/* 95C730 80241530 AFBF0018 */  sw        $ra, 0x18($sp)
/* 95C734 80241534 AFB10014 */  sw        $s1, 0x14($sp)
/* 95C738 80241538 8E02000C */  lw        $v0, 0xc($s0)
/* 95C73C 8024153C 8C510000 */  lw        $s1, ($v0)
/* 95C740 80241540 0C0B1EAF */  jal       get_variable
/* 95C744 80241544 0220282D */   daddu    $a1, $s1, $zero
/* 95C748 80241548 3C03FFF0 */  lui       $v1, 0xfff0
/* 95C74C 8024154C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 95C750 80241550 0200202D */  daddu     $a0, $s0, $zero
/* 95C754 80241554 00431024 */  and       $v0, $v0, $v1
/* 95C758 80241558 00021140 */  sll       $v0, $v0, 5
/* 95C75C 8024155C 3C068008 */  lui       $a2, %hi(gItemTable)
/* 95C760 80241560 00C23021 */  addu      $a2, $a2, $v0
/* 95C764 80241564 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 95C768 80241568 0C0B2026 */  jal       set_variable
/* 95C76C 8024156C 0220282D */   daddu    $a1, $s1, $zero
/* 95C770 80241570 8FBF0018 */  lw        $ra, 0x18($sp)
/* 95C774 80241574 8FB10014 */  lw        $s1, 0x14($sp)
/* 95C778 80241578 8FB00010 */  lw        $s0, 0x10($sp)
/* 95C77C 8024157C 24020002 */  addiu     $v0, $zero, 2
/* 95C780 80241580 03E00008 */  jr        $ra
/* 95C784 80241584 27BD0020 */   addiu    $sp, $sp, 0x20

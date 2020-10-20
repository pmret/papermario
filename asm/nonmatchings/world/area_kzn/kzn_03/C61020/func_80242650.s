.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242650
/* C63360 80242650 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C63364 80242654 AFB00010 */  sw        $s0, 0x10($sp)
/* C63368 80242658 0080802D */  daddu     $s0, $a0, $zero
/* C6336C 8024265C AFBF0018 */  sw        $ra, 0x18($sp)
/* C63370 80242660 AFB10014 */  sw        $s1, 0x14($sp)
/* C63374 80242664 8E02000C */  lw        $v0, 0xc($s0)
/* C63378 80242668 8C510000 */  lw        $s1, ($v0)
/* C6337C 8024266C 0C0B1EAF */  jal       get_variable
/* C63380 80242670 0220282D */   daddu    $a1, $s1, $zero
/* C63384 80242674 3C03FFF0 */  lui       $v1, 0xfff0
/* C63388 80242678 3463FFFF */  ori       $v1, $v1, 0xffff
/* C6338C 8024267C 0200202D */  daddu     $a0, $s0, $zero
/* C63390 80242680 00431024 */  and       $v0, $v0, $v1
/* C63394 80242684 00021140 */  sll       $v0, $v0, 5
/* C63398 80242688 3C068008 */  lui       $a2, %hi(gItemTable)
/* C6339C 8024268C 00C23021 */  addu      $a2, $a2, $v0
/* C633A0 80242690 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* C633A4 80242694 0C0B2026 */  jal       set_variable
/* C633A8 80242698 0220282D */   daddu    $a1, $s1, $zero
/* C633AC 8024269C 8FBF0018 */  lw        $ra, 0x18($sp)
/* C633B0 802426A0 8FB10014 */  lw        $s1, 0x14($sp)
/* C633B4 802426A4 8FB00010 */  lw        $s0, 0x10($sp)
/* C633B8 802426A8 24020002 */  addiu     $v0, $zero, 2
/* C633BC 802426AC 03E00008 */  jr        $ra
/* C633C0 802426B0 27BD0020 */   addiu    $sp, $sp, 0x20

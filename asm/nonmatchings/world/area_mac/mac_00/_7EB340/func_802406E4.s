.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406E4
/* 7EB3F4 802406E4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7EB3F8 802406E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 7EB3FC 802406EC 0080802D */  daddu     $s0, $a0, $zero
/* 7EB400 802406F0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7EB404 802406F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EB408 802406F8 8E02000C */  lw        $v0, 0xc($s0)
/* 7EB40C 802406FC 8C510000 */  lw        $s1, ($v0)
/* 7EB410 80240700 0C0B1EAF */  jal       get_variable
/* 7EB414 80240704 0220282D */   daddu    $a1, $s1, $zero
/* 7EB418 80240708 3C03FFF0 */  lui       $v1, 0xfff0
/* 7EB41C 8024070C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 7EB420 80240710 0200202D */  daddu     $a0, $s0, $zero
/* 7EB424 80240714 00431024 */  and       $v0, $v0, $v1
/* 7EB428 80240718 00021140 */  sll       $v0, $v0, 5
/* 7EB42C 8024071C 3C068008 */  lui       $a2, %hi(gItemTable)
/* 7EB430 80240720 00C23021 */  addu      $a2, $a2, $v0
/* 7EB434 80240724 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 7EB438 80240728 0C0B2026 */  jal       set_variable
/* 7EB43C 8024072C 0220282D */   daddu    $a1, $s1, $zero
/* 7EB440 80240730 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7EB444 80240734 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EB448 80240738 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EB44C 8024073C 24020002 */  addiu     $v0, $zero, 2
/* 7EB450 80240740 03E00008 */  jr        $ra
/* 7EB454 80240744 27BD0020 */   addiu    $sp, $sp, 0x20

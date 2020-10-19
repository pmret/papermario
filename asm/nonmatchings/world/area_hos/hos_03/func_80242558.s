.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242558
/* A1D658 80242558 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A1D65C 8024255C AFB00010 */  sw        $s0, 0x10($sp)
/* A1D660 80242560 0080802D */  daddu     $s0, $a0, $zero
/* A1D664 80242564 AFBF0018 */  sw        $ra, 0x18($sp)
/* A1D668 80242568 AFB10014 */  sw        $s1, 0x14($sp)
/* A1D66C 8024256C 8E02000C */  lw        $v0, 0xc($s0)
/* A1D670 80242570 8C510000 */  lw        $s1, ($v0)
/* A1D674 80242574 0C0B1EAF */  jal       get_variable
/* A1D678 80242578 0220282D */   daddu    $a1, $s1, $zero
/* A1D67C 8024257C 3C03FFF0 */  lui       $v1, 0xfff0
/* A1D680 80242580 3463FFFF */  ori       $v1, $v1, 0xffff
/* A1D684 80242584 0200202D */  daddu     $a0, $s0, $zero
/* A1D688 80242588 00431024 */  and       $v0, $v0, $v1
/* A1D68C 8024258C 00021140 */  sll       $v0, $v0, 5
/* A1D690 80242590 3C068008 */  lui       $a2, %hi(gItemTable)
/* A1D694 80242594 00C23021 */  addu      $a2, $a2, $v0
/* A1D698 80242598 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* A1D69C 8024259C 0C0B2026 */  jal       set_variable
/* A1D6A0 802425A0 0220282D */   daddu    $a1, $s1, $zero
/* A1D6A4 802425A4 8FBF0018 */  lw        $ra, 0x18($sp)
/* A1D6A8 802425A8 8FB10014 */  lw        $s1, 0x14($sp)
/* A1D6AC 802425AC 8FB00010 */  lw        $s0, 0x10($sp)
/* A1D6B0 802425B0 24020002 */  addiu     $v0, $zero, 2
/* A1D6B4 802425B4 03E00008 */  jr        $ra
/* A1D6B8 802425B8 27BD0020 */   addiu    $sp, $sp, 0x20

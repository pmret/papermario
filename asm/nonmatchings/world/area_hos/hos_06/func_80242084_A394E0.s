.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242084_A3B564
/* A3B564 80242084 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A3B568 80242088 AFB00010 */  sw        $s0, 0x10($sp)
/* A3B56C 8024208C 0080802D */  daddu     $s0, $a0, $zero
/* A3B570 80242090 AFBF0018 */  sw        $ra, 0x18($sp)
/* A3B574 80242094 AFB10014 */  sw        $s1, 0x14($sp)
/* A3B578 80242098 8E02000C */  lw        $v0, 0xc($s0)
/* A3B57C 8024209C 8C510000 */  lw        $s1, ($v0)
/* A3B580 802420A0 0C0B1EAF */  jal       get_variable
/* A3B584 802420A4 0220282D */   daddu    $a1, $s1, $zero
/* A3B588 802420A8 3C03FFF0 */  lui       $v1, 0xfff0
/* A3B58C 802420AC 3463FFFF */  ori       $v1, $v1, 0xffff
/* A3B590 802420B0 0200202D */  daddu     $a0, $s0, $zero
/* A3B594 802420B4 00431024 */  and       $v0, $v0, $v1
/* A3B598 802420B8 00021140 */  sll       $v0, $v0, 5
/* A3B59C 802420BC 3C068008 */  lui       $a2, %hi(gItemTable)
/* A3B5A0 802420C0 00C23021 */  addu      $a2, $a2, $v0
/* A3B5A4 802420C4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* A3B5A8 802420C8 0C0B2026 */  jal       set_variable
/* A3B5AC 802420CC 0220282D */   daddu    $a1, $s1, $zero
/* A3B5B0 802420D0 8FBF0018 */  lw        $ra, 0x18($sp)
/* A3B5B4 802420D4 8FB10014 */  lw        $s1, 0x14($sp)
/* A3B5B8 802420D8 8FB00010 */  lw        $s0, 0x10($sp)
/* A3B5BC 802420DC 24020002 */  addiu     $v0, $zero, 2
/* A3B5C0 802420E0 03E00008 */  jr        $ra
/* A3B5C4 802420E4 27BD0020 */   addiu    $sp, $sp, 0x20

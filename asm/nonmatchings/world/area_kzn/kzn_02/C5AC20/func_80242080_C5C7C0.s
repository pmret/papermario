.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242080_C5C7C0
/* C5C7C0 80242080 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C5C7C4 80242084 AFB00010 */  sw        $s0, 0x10($sp)
/* C5C7C8 80242088 0080802D */  daddu     $s0, $a0, $zero
/* C5C7CC 8024208C AFBF0018 */  sw        $ra, 0x18($sp)
/* C5C7D0 80242090 AFB10014 */  sw        $s1, 0x14($sp)
/* C5C7D4 80242094 8E02000C */  lw        $v0, 0xc($s0)
/* C5C7D8 80242098 8C510000 */  lw        $s1, ($v0)
/* C5C7DC 8024209C 0C0B1EAF */  jal       get_variable
/* C5C7E0 802420A0 0220282D */   daddu    $a1, $s1, $zero
/* C5C7E4 802420A4 3C03FFF0 */  lui       $v1, 0xfff0
/* C5C7E8 802420A8 3463FFFF */  ori       $v1, $v1, 0xffff
/* C5C7EC 802420AC 0200202D */  daddu     $a0, $s0, $zero
/* C5C7F0 802420B0 00431024 */  and       $v0, $v0, $v1
/* C5C7F4 802420B4 00021140 */  sll       $v0, $v0, 5
/* C5C7F8 802420B8 3C068008 */  lui       $a2, %hi(gItemTable)
/* C5C7FC 802420BC 00C23021 */  addu      $a2, $a2, $v0
/* C5C800 802420C0 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* C5C804 802420C4 0C0B2026 */  jal       set_variable
/* C5C808 802420C8 0220282D */   daddu    $a1, $s1, $zero
/* C5C80C 802420CC 8FBF0018 */  lw        $ra, 0x18($sp)
/* C5C810 802420D0 8FB10014 */  lw        $s1, 0x14($sp)
/* C5C814 802420D4 8FB00010 */  lw        $s0, 0x10($sp)
/* C5C818 802420D8 24020002 */  addiu     $v0, $zero, 2
/* C5C81C 802420DC 03E00008 */  jr        $ra
/* C5C820 802420E0 27BD0020 */   addiu    $sp, $sp, 0x20

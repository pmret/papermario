.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802407D4_DCD4A4
/* DCD4A4 802407D4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DCD4A8 802407D8 AFB00010 */  sw        $s0, 0x10($sp)
/* DCD4AC 802407DC 0080802D */  daddu     $s0, $a0, $zero
/* DCD4B0 802407E0 AFBF0018 */  sw        $ra, 0x18($sp)
/* DCD4B4 802407E4 AFB10014 */  sw        $s1, 0x14($sp)
/* DCD4B8 802407E8 8E02000C */  lw        $v0, 0xc($s0)
/* DCD4BC 802407EC 8C510000 */  lw        $s1, ($v0)
/* DCD4C0 802407F0 0C0B1EAF */  jal       get_variable
/* DCD4C4 802407F4 0220282D */   daddu    $a1, $s1, $zero
/* DCD4C8 802407F8 3C03FFF0 */  lui       $v1, 0xfff0
/* DCD4CC 802407FC 3463FFFF */  ori       $v1, $v1, 0xffff
/* DCD4D0 80240800 0200202D */  daddu     $a0, $s0, $zero
/* DCD4D4 80240804 00431024 */  and       $v0, $v0, $v1
/* DCD4D8 80240808 00021140 */  sll       $v0, $v0, 5
/* DCD4DC 8024080C 3C068008 */  lui       $a2, %hi(gItemTable)
/* DCD4E0 80240810 00C23021 */  addu      $a2, $a2, $v0
/* DCD4E4 80240814 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* DCD4E8 80240818 0C0B2026 */  jal       set_variable
/* DCD4EC 8024081C 0220282D */   daddu    $a1, $s1, $zero
/* DCD4F0 80240820 8FBF0018 */  lw        $ra, 0x18($sp)
/* DCD4F4 80240824 8FB10014 */  lw        $s1, 0x14($sp)
/* DCD4F8 80240828 8FB00010 */  lw        $s0, 0x10($sp)
/* DCD4FC 8024082C 24020002 */  addiu     $v0, $zero, 2
/* DCD500 80240830 03E00008 */  jr        $ra
/* DCD504 80240834 27BD0020 */   addiu    $sp, $sp, 0x20

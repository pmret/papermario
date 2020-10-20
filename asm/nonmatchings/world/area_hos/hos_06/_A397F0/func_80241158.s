.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241158
/* A3A638 80241158 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A3A63C 8024115C AFB00010 */  sw        $s0, 0x10($sp)
/* A3A640 80241160 0080802D */  daddu     $s0, $a0, $zero
/* A3A644 80241164 AFBF0018 */  sw        $ra, 0x18($sp)
/* A3A648 80241168 AFB10014 */  sw        $s1, 0x14($sp)
/* A3A64C 8024116C 8E02000C */  lw        $v0, 0xc($s0)
/* A3A650 80241170 8C510000 */  lw        $s1, ($v0)
/* A3A654 80241174 0C0B1EAF */  jal       get_variable
/* A3A658 80241178 0220282D */   daddu    $a1, $s1, $zero
/* A3A65C 8024117C 3C03FFF0 */  lui       $v1, 0xfff0
/* A3A660 80241180 3463FFFF */  ori       $v1, $v1, 0xffff
/* A3A664 80241184 0200202D */  daddu     $a0, $s0, $zero
/* A3A668 80241188 00431024 */  and       $v0, $v0, $v1
/* A3A66C 8024118C 00021140 */  sll       $v0, $v0, 5
/* A3A670 80241190 3C068008 */  lui       $a2, %hi(gItemTable)
/* A3A674 80241194 00C23021 */  addu      $a2, $a2, $v0
/* A3A678 80241198 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* A3A67C 8024119C 0C0B2026 */  jal       set_variable
/* A3A680 802411A0 0220282D */   daddu    $a1, $s1, $zero
/* A3A684 802411A4 8FBF0018 */  lw        $ra, 0x18($sp)
/* A3A688 802411A8 8FB10014 */  lw        $s1, 0x14($sp)
/* A3A68C 802411AC 8FB00010 */  lw        $s0, 0x10($sp)
/* A3A690 802411B0 24020002 */  addiu     $v0, $zero, 2
/* A3A694 802411B4 03E00008 */  jr        $ra
/* A3A698 802411B8 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_CC3810
/* CC3810 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CC3814 80240004 0000202D */  daddu     $a0, $zero, $zero
/* CC3818 80240008 0080282D */  daddu     $a1, $a0, $zero
/* CC381C 8024000C 0080302D */  daddu     $a2, $a0, $zero
/* CC3820 80240010 0080382D */  daddu     $a3, $a0, $zero
/* CC3824 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* CC3828 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* CC382C 8024001C 0C01CA54 */  jal       func_80072950
/* CC3830 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* CC3834 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* CC3838 80240028 24020002 */  addiu     $v0, $zero, 2
/* CC383C 8024002C 03E00008 */  jr        $ra
/* CC3840 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* CC3844 80240034 00000000 */  nop       
/* CC3848 80240038 00000000 */  nop       
/* CC384C 8024003C 00000000 */  nop       

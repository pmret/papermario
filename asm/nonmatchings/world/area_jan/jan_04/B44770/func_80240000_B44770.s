.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B44770
/* B44770 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B44774 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* B44778 80240008 3C05F5DE */  lui       $a1, 0xf5de
/* B4477C 8024000C 34A50180 */  ori       $a1, $a1, 0x180
/* B44780 80240010 0C0B1EAF */  jal       get_variable
/* B44784 80240014 0000202D */   daddu    $a0, $zero, $zero
/* B44788 80240018 2843000F */  slti      $v1, $v0, 0xf
/* B4478C 8024001C 3C020019 */  lui       $v0, 0x19
/* B44790 80240020 14600003 */  bnez      $v1, .L80240030
/* B44794 80240024 344200F0 */   ori      $v0, $v0, 0xf0
/* B44798 80240028 3C020019 */  lui       $v0, 0x19
/* B4479C 8024002C 344200F1 */  ori       $v0, $v0, 0xf1
.L80240030:
/* B447A0 80240030 8FBF0010 */  lw        $ra, 0x10($sp)
/* B447A4 80240034 03E00008 */  jr        $ra
/* B447A8 80240038 27BD0018 */   addiu    $sp, $sp, 0x18
/* B447AC 8024003C 00000000 */  nop

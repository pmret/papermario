.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_B4AA70
/* B4AA70 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B4AA74 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* B4AA78 80240008 3C05F5DE */  lui       $a1, 0xf5de
/* B4AA7C 8024000C 34A50180 */  ori       $a1, $a1, 0x180
/* B4AA80 80240010 0C0B1EAF */  jal       get_variable
/* B4AA84 80240014 0000202D */   daddu    $a0, $zero, $zero
/* B4AA88 80240018 2843000F */  slti      $v1, $v0, 0xf
/* B4AA8C 8024001C 3C020019 */  lui       $v0, 0x19
/* B4AA90 80240020 14600003 */  bnez      $v1, .L80240030
/* B4AA94 80240024 344200F2 */   ori      $v0, $v0, 0xf2
/* B4AA98 80240028 3C020019 */  lui       $v0, 0x19
/* B4AA9C 8024002C 344200F3 */  ori       $v0, $v0, 0xf3
.L80240030:
/* B4AAA0 80240030 8FBF0010 */  lw        $ra, 0x10($sp)
/* B4AAA4 80240034 03E00008 */  jr        $ra
/* B4AAA8 80240038 27BD0018 */   addiu    $sp, $sp, 0x18
/* B4AAAC 8024003C 00000000 */  nop       

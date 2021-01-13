.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_CB9200
/* CB9200 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CB9204 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* CB9208 80240008 3C05F5DE */  lui       $a1, 0xf5de
/* CB920C 8024000C 34A50180 */  ori       $a1, $a1, 0x180
/* CB9210 80240010 0C0B1EAF */  jal       get_variable
/* CB9214 80240014 0000202D */   daddu    $a0, $zero, $zero
/* CB9218 80240018 28430031 */  slti      $v1, $v0, 0x31
/* CB921C 8024001C 3C020019 */  lui       $v0, 0x19
/* CB9220 80240020 14600003 */  bnez      $v1, .L80240030
/* CB9224 80240024 34420119 */   ori      $v0, $v0, 0x119
/* CB9228 80240028 3C020019 */  lui       $v0, 0x19
/* CB922C 8024002C 3442011A */  ori       $v0, $v0, 0x11a
.L80240030:
/* CB9230 80240030 8FBF0010 */  lw        $ra, 0x10($sp)
/* CB9234 80240034 03E00008 */  jr        $ra
/* CB9238 80240038 27BD0018 */   addiu    $sp, $sp, 0x18
/* CB923C 8024003C 00000000 */  nop

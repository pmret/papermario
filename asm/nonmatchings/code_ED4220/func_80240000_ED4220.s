.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_ED4220
/* ED4220 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ED4224 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* ED4228 80240008 3C05F5DE */  lui       $a1, 0xf5de
/* ED422C 8024000C 34A50180 */  ori       $a1, $a1, 0x180
/* ED4230 80240010 0C0B53A3 */  jal       func_802D4E8C
/* ED4234 80240014 0000202D */   daddu    $a0, $zero, $zero
/* ED4238 80240018 28430031 */  slti      $v1, $v0, 0x31
/* ED423C 8024001C 3C020019 */  lui       $v0, 0x19
/* ED4240 80240020 14600003 */  bnez      $v1, .L80240030
/* ED4244 80240024 34420119 */   ori      $v0, $v0, 0x119
/* ED4248 80240028 3C020019 */  lui       $v0, 0x19
/* ED424C 8024002C 3442011A */  ori       $v0, $v0, 0x11a
.L80240030:
/* ED4250 80240030 8FBF0010 */  lw        $ra, 0x10($sp)
/* ED4254 80240034 03E00008 */  jr        $ra
/* ED4258 80240038 27BD0018 */   addiu    $sp, $sp, 0x18
/* ED425C 8024003C 00000000 */  nop

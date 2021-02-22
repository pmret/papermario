.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_C8C0A0
/* C8C0A0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C8C0A4 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* C8C0A8 80240008 3C05F5DE */  lui       $a1, 0xf5de
/* C8C0AC 8024000C 34A50180 */  ori       $a1, $a1, 0x180
/* C8C0B0 80240010 0C0B1EAF */  jal       get_variable
/* C8C0B4 80240014 0000202D */   daddu    $a0, $zero, $zero
/* C8C0B8 80240018 28430027 */  slti      $v1, $v0, 0x27
/* C8C0BC 8024001C 3C020019 */  lui       $v0, 0x19
/* C8C0C0 80240020 14600003 */  bnez      $v1, .L80240030
/* C8C0C4 80240024 3442010F */   ori      $v0, $v0, 0x10f
/* C8C0C8 80240028 3C020019 */  lui       $v0, 0x19
/* C8C0CC 8024002C 34420110 */  ori       $v0, $v0, 0x110
.L80240030:
/* C8C0D0 80240030 8FBF0010 */  lw        $ra, 0x10($sp)
/* C8C0D4 80240034 03E00008 */  jr        $ra
/* C8C0D8 80240038 27BD0018 */   addiu    $sp, $sp, 0x18
/* C8C0DC 8024003C 00000000 */  nop

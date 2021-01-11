.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_EA6FD0
/* EA6FD0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA6FD4 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* EA6FD8 80240008 3C05F5DE */  lui       $a1, 0xf5de
/* EA6FDC 8024000C 34A50180 */  ori       $a1, $a1, 0x180
/* EA6FE0 80240010 0C0B53A3 */  jal       func_802D4E8C
/* EA6FE4 80240014 0000202D */   daddu    $a0, $zero, $zero
/* EA6FE8 80240018 28430027 */  slti      $v1, $v0, 0x27
/* EA6FEC 8024001C 3C020019 */  lui       $v0, 0x19
/* EA6FF0 80240020 14600003 */  bnez      $v1, .L80240030
/* EA6FF4 80240024 3442010F */   ori      $v0, $v0, 0x10f
/* EA6FF8 80240028 3C020019 */  lui       $v0, 0x19
/* EA6FFC 8024002C 34420110 */  ori       $v0, $v0, 0x110
.L80240030:
/* EA7000 80240030 8FBF0010 */  lw        $ra, 0x10($sp)
/* EA7004 80240034 03E00008 */  jr        $ra
/* EA7008 80240038 27BD0018 */   addiu    $sp, $sp, 0x18
/* EA700C 8024003C 00000000 */  nop       

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_D3A5D0
/* D3A5D0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D3A5D4 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* D3A5D8 80240008 3C05F5DE */  lui       $a1, 0xf5de
/* D3A5DC 8024000C 34A50180 */  ori       $a1, $a1, 0x180
/* D3A5E0 80240010 0C0B1EAF */  jal       get_variable
/* D3A5E4 80240014 0000202D */   daddu    $a0, $zero, $zero
/* D3A5E8 80240018 28430040 */  slti      $v1, $v0, 0x40
/* D3A5EC 8024001C 3C020019 */  lui       $v0, 0x19
/* D3A5F0 80240020 14600003 */  bnez      $v1, .L80240030
/* D3A5F4 80240024 3442012B */   ori      $v0, $v0, 0x12b
/* D3A5F8 80240028 3C020019 */  lui       $v0, 0x19
/* D3A5FC 8024002C 3442012C */  ori       $v0, $v0, 0x12c
.L80240030:
/* D3A600 80240030 8FBF0010 */  lw        $ra, 0x10($sp)
/* D3A604 80240034 03E00008 */  jr        $ra
/* D3A608 80240038 27BD0018 */   addiu    $sp, $sp, 0x18
/* D3A60C 8024003C 00000000 */  nop       

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_92A2B0
/* 92A2B0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 92A2B4 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* 92A2B8 80240008 3C05F5DE */  lui       $a1, 0xf5de
/* 92A2BC 8024000C 34A50180 */  ori       $a1, $a1, 0x180
/* 92A2C0 80240010 0C0B1EAF */  jal       get_variable
/* 92A2C4 80240014 0000202D */   daddu    $a0, $zero, $zero
/* 92A2C8 80240018 3C030019 */  lui       $v1, 0x19
/* 92A2CC 8024001C 2842FFC2 */  slti      $v0, $v0, -0x3e
/* 92A2D0 80240020 14400003 */  bnez      $v0, .L80240030
/* 92A2D4 80240024 34630062 */   ori      $v1, $v1, 0x62
/* 92A2D8 80240028 3C030019 */  lui       $v1, 0x19
/* 92A2DC 8024002C 34630063 */  ori       $v1, $v1, 0x63
.L80240030:
/* 92A2E0 80240030 8FBF0010 */  lw        $ra, 0x10($sp)
/* 92A2E4 80240034 0060102D */  daddu     $v0, $v1, $zero
/* 92A2E8 80240038 03E00008 */  jr        $ra
/* 92A2EC 8024003C 27BD0018 */   addiu    $sp, $sp, 0x18

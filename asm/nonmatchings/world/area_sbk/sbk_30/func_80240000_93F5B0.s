.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_93F5B0
/* 93F5B0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 93F5B4 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* 93F5B8 80240008 3C05F5DE */  lui       $a1, 0xf5de
/* 93F5BC 8024000C 34A50180 */  ori       $a1, $a1, 0x180
/* 93F5C0 80240010 0C0B1EAF */  jal       get_variable
/* 93F5C4 80240014 0000202D */   daddu    $a0, $zero, $zero
/* 93F5C8 80240018 3C030019 */  lui       $v1, 0x19
/* 93F5CC 8024001C 2842FFCC */  slti      $v0, $v0, -0x34
/* 93F5D0 80240020 14400003 */  bnez      $v0, .L80240030
/* 93F5D4 80240024 34630076 */   ori      $v1, $v1, 0x76
/* 93F5D8 80240028 3C030019 */  lui       $v1, 0x19
/* 93F5DC 8024002C 34630077 */  ori       $v1, $v1, 0x77
.L80240030:
/* 93F5E0 80240030 8FBF0010 */  lw        $ra, 0x10($sp)
/* 93F5E4 80240034 0060102D */  daddu     $v0, $v1, $zero
/* 93F5E8 80240038 03E00008 */  jr        $ra
/* 93F5EC 8024003C 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A55F20
/* A55F20 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A55F24 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* A55F28 80240008 3C05F840 */  lui       $a1, 0xf840
/* A55F2C 8024000C 34A56194 */  ori       $a1, $a1, 0x6194
/* A55F30 80240010 0C0B1EAF */  jal       get_variable
/* A55F34 80240014 0000202D */   daddu    $a0, $zero, $zero
/* A55F38 80240018 0040182D */  daddu     $v1, $v0, $zero
/* A55F3C 8024001C 3C020019 */  lui       $v0, 0x19
/* A55F40 80240020 10600003 */  beqz      $v1, .L80240030
/* A55F44 80240024 34420162 */   ori      $v0, $v0, 0x162
/* A55F48 80240028 3C020019 */  lui       $v0, 0x19
/* A55F4C 8024002C 34420163 */  ori       $v0, $v0, 0x163
.L80240030:
/* A55F50 80240030 8FBF0010 */  lw        $ra, 0x10($sp)
/* A55F54 80240034 03E00008 */  jr        $ra
/* A55F58 80240038 27BD0018 */   addiu    $sp, $sp, 0x18
/* A55F5C 8024003C 00000000 */  nop       

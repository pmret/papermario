.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A54950
/* A54950 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A54954 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* A54958 80240008 3C05F840 */  lui       $a1, 0xf840
/* A5495C 8024000C 34A56194 */  ori       $a1, $a1, 0x6194
/* A54960 80240010 0C0B1EAF */  jal       get_variable
/* A54964 80240014 0000202D */   daddu    $a0, $zero, $zero
/* A54968 80240018 0040182D */  daddu     $v1, $v0, $zero
/* A5496C 8024001C 3C020019 */  lui       $v0, 0x19
/* A54970 80240020 10600003 */  beqz      $v1, .L80240030
/* A54974 80240024 34420160 */   ori      $v0, $v0, 0x160
/* A54978 80240028 3C020019 */  lui       $v0, 0x19
/* A5497C 8024002C 34420161 */  ori       $v0, $v0, 0x161
.L80240030:
/* A54980 80240030 8FBF0010 */  lw        $ra, 0x10($sp)
/* A54984 80240034 03E00008 */  jr        $ra
/* A54988 80240038 27BD0018 */   addiu    $sp, $sp, 0x18
/* A5498C 8024003C 00000000 */  nop

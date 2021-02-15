.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_C9DF20
/* C9DF20 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C9DF24 80240004 0000202D */  daddu     $a0, $zero, $zero
/* C9DF28 80240008 0080282D */  daddu     $a1, $a0, $zero
/* C9DF2C 8024000C 0080302D */  daddu     $a2, $a0, $zero
/* C9DF30 80240010 0080382D */  daddu     $a3, $a0, $zero
/* C9DF34 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* C9DF38 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* C9DF3C 8024001C 0C01CA54 */  jal       func_80072950
/* C9DF40 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* C9DF44 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* C9DF48 80240028 24020002 */  addiu     $v0, $zero, 2
/* C9DF4C 8024002C 03E00008 */  jr        $ra
/* C9DF50 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* C9DF54 80240034 00000000 */  nop
/* C9DF58 80240038 00000000 */  nop
/* C9DF5C 8024003C 00000000 */  nop

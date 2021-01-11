.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_EB8E50
/* EB8E50 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EB8E54 80240004 0000202D */  daddu     $a0, $zero, $zero
/* EB8E58 80240008 0080282D */  daddu     $a1, $a0, $zero
/* EB8E5C 8024000C 0080302D */  daddu     $a2, $a0, $zero
/* EB8E60 80240010 0080382D */  daddu     $a3, $a0, $zero
/* EB8E64 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* EB8E68 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* EB8E6C 8024001C 0C01DEF4 */  jal       func_80077BD0
/* EB8E70 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* EB8E74 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* EB8E78 80240028 24020002 */  addiu     $v0, $zero, 2
/* EB8E7C 8024002C 03E00008 */  jr        $ra
/* EB8E80 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* EB8E84 80240034 00000000 */  nop       
/* EB8E88 80240038 00000000 */  nop       
/* EB8E8C 8024003C 00000000 */  nop       

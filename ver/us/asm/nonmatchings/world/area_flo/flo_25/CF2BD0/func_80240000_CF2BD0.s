.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_CF2BD0
/* CF2BD0 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF2BD4 80240004 0000202D */  daddu     $a0, $zero, $zero
/* CF2BD8 80240008 0080282D */  daddu     $a1, $a0, $zero
/* CF2BDC 8024000C 0080302D */  daddu     $a2, $a0, $zero
/* CF2BE0 80240010 0080382D */  daddu     $a3, $a0, $zero
/* CF2BE4 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* CF2BE8 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* CF2BEC 8024001C 0C01CA54 */  jal       func_80072950
/* CF2BF0 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* CF2BF4 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* CF2BF8 80240028 24020002 */  addiu     $v0, $zero, 2
/* CF2BFC 8024002C 03E00008 */  jr        $ra
/* CF2C00 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* CF2C04 80240034 00000000 */  nop
/* CF2C08 80240038 00000000 */  nop
/* CF2C0C 8024003C 00000000 */  nop

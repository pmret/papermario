.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_CB5000
/* CB5000 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CB5004 80240004 24040001 */  addiu     $a0, $zero, 1
/* CB5008 80240008 0000282D */  daddu     $a1, $zero, $zero
/* CB500C 8024000C 00A0302D */  daddu     $a2, $a1, $zero
/* CB5010 80240010 00A0382D */  daddu     $a3, $a1, $zero
/* CB5014 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* CB5018 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* CB501C 8024001C 0C01CA54 */  jal       func_80072950
/* CB5020 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* CB5024 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* CB5028 80240028 24020002 */  addiu     $v0, $zero, 2
/* CB502C 8024002C 03E00008 */  jr        $ra
/* CB5030 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* CB5034 80240034 00000000 */  nop
/* CB5038 80240038 00000000 */  nop
/* CB503C 8024003C 00000000 */  nop

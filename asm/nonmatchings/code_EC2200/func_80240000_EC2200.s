.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_EC2200
/* EC2200 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EC2204 80240004 24040001 */  addiu     $a0, $zero, 1
/* EC2208 80240008 0000282D */  daddu     $a1, $zero, $zero
/* EC220C 8024000C 00A0302D */  daddu     $a2, $a1, $zero
/* EC2210 80240010 00A0382D */  daddu     $a3, $a1, $zero
/* EC2214 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* EC2218 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* EC221C 8024001C 0C01DEF4 */  jal       func_80077BD0
/* EC2220 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* EC2224 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* EC2228 80240028 24020002 */  addiu     $v0, $zero, 2
/* EC222C 8024002C 03E00008 */  jr        $ra
/* EC2230 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* EC2234 80240034 00000000 */  nop
/* EC2238 80240038 00000000 */  nop
/* EC223C 8024003C 00000000 */  nop

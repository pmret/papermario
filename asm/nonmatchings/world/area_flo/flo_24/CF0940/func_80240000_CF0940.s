.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_CF0940
/* CF0940 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CF0944 80240004 24040001 */  addiu     $a0, $zero, 1
/* CF0948 80240008 0000282D */  daddu     $a1, $zero, $zero
/* CF094C 8024000C 00A0302D */  daddu     $a2, $a1, $zero
/* CF0950 80240010 00A0382D */  daddu     $a3, $a1, $zero
/* CF0954 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* CF0958 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* CF095C 8024001C 0C01CA54 */  jal       func_80072950
/* CF0960 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* CF0964 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* CF0968 80240028 24020002 */  addiu     $v0, $zero, 2
/* CF096C 8024002C 03E00008 */  jr        $ra
/* CF0970 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* CF0974 80240034 00000000 */  nop
/* CF0978 80240038 00000000 */  nop
/* CF097C 8024003C 00000000 */  nop

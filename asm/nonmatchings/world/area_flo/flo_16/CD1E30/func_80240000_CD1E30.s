.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_CD1E30
/* CD1E30 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CD1E34 80240004 24040001 */  addiu     $a0, $zero, 1
/* CD1E38 80240008 0000282D */  daddu     $a1, $zero, $zero
/* CD1E3C 8024000C 00A0302D */  daddu     $a2, $a1, $zero
/* CD1E40 80240010 00A0382D */  daddu     $a3, $a1, $zero
/* CD1E44 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* CD1E48 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* CD1E4C 8024001C 0C01CA54 */  jal       func_80072950
/* CD1E50 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* CD1E54 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* CD1E58 80240028 24020002 */  addiu     $v0, $zero, 2
/* CD1E5C 8024002C 03E00008 */  jr        $ra
/* CD1E60 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* CD1E64 80240034 00000000 */  nop
/* CD1E68 80240038 00000000 */  nop
/* CD1E6C 8024003C 00000000 */  nop

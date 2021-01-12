.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_ECFFF0
/* ECFFF0 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* ECFFF4 80240004 24040001 */  addiu     $a0, $zero, 1
/* ECFFF8 80240008 0000282D */  daddu     $a1, $zero, $zero
/* ECFFFC 8024000C 00A0302D */  daddu     $a2, $a1, $zero
/* ED0000 80240010 00A0382D */  daddu     $a3, $a1, $zero
/* ED0004 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* ED0008 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* ED000C 8024001C 0C01DEF4 */  jal       func_80077BD0
/* ED0010 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* ED0014 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* ED0018 80240028 24020002 */  addiu     $v0, $zero, 2
/* ED001C 8024002C 03E00008 */  jr        $ra
/* ED0020 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* ED0024 80240034 00000000 */  nop
/* ED0028 80240038 00000000 */  nop
/* ED002C 8024003C 00000000 */  nop

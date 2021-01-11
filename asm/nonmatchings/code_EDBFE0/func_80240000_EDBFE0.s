.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_EDBFE0
/* EDBFE0 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EDBFE4 80240004 0000202D */  daddu     $a0, $zero, $zero
/* EDBFE8 80240008 0080282D */  daddu     $a1, $a0, $zero
/* EDBFEC 8024000C 0080302D */  daddu     $a2, $a0, $zero
/* EDBFF0 80240010 0080382D */  daddu     $a3, $a0, $zero
/* EDBFF4 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* EDBFF8 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* EDBFFC 8024001C 0C01DEF4 */  jal       func_80077BD0
/* EDC000 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* EDC004 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* EDC008 80240028 24020002 */  addiu     $v0, $zero, 2
/* EDC00C 8024002C 03E00008 */  jr        $ra
/* EDC010 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* EDC014 80240034 00000000 */  nop
/* EDC018 80240038 00000000 */  nop
/* EDC01C 8024003C 00000000 */  nop

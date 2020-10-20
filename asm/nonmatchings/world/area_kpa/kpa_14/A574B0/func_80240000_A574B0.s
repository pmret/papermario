.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A574B0
/* A574B0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A574B4 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* A574B8 80240008 3C05F840 */  lui       $a1, 0xf840
/* A574BC 8024000C 34A56194 */  ori       $a1, $a1, 0x6194
/* A574C0 80240010 0C0B1EAF */  jal       get_variable
/* A574C4 80240014 0000202D */   daddu    $a0, $zero, $zero
/* A574C8 80240018 0040182D */  daddu     $v1, $v0, $zero
/* A574CC 8024001C 3C020019 */  lui       $v0, 0x19
/* A574D0 80240020 10600003 */  beqz      $v1, .L80240030
/* A574D4 80240024 34420164 */   ori      $v0, $v0, 0x164
/* A574D8 80240028 3C020019 */  lui       $v0, 0x19
/* A574DC 8024002C 34420165 */  ori       $v0, $v0, 0x165
.L80240030:
/* A574E0 80240030 8FBF0010 */  lw        $ra, 0x10($sp)
/* A574E4 80240034 03E00008 */  jr        $ra
/* A574E8 80240038 27BD0018 */   addiu    $sp, $sp, 0x18
/* A574EC 8024003C 00000000 */  nop       

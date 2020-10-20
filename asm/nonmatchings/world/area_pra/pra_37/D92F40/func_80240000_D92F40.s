.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_D92F40
/* D92F40 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D92F44 80240004 3C04800E */  lui       $a0, 0x800e
/* D92F48 80240008 24849230 */  addiu     $a0, $a0, -0x6dd0
/* D92F4C 8024000C 3C058024 */  lui       $a1, 0x8024
/* D92F50 80240010 24A524E0 */  addiu     $a1, $a1, 0x24e0
/* D92F54 80240014 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* D92F58 80240018 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* D92F5C 8024001C 24020001 */  addiu     $v0, $zero, 1
/* D92F60 80240020 AFBF0010 */  sw        $ra, 0x10($sp)
/* D92F64 80240024 0C01953C */  jal       sprintf
/* D92F68 80240028 A0620084 */   sb       $v0, 0x84($v1)
/* D92F6C 8024002C 3C04800E */  lui       $a0, 0x800e
/* D92F70 80240030 248491E0 */  addiu     $a0, $a0, -0x6e20
/* D92F74 80240034 3C058024 */  lui       $a1, 0x8024
/* D92F78 80240038 0C01953C */  jal       sprintf
/* D92F7C 8024003C 24A524F0 */   addiu    $a1, $a1, 0x24f0
/* D92F80 80240040 8FBF0010 */  lw        $ra, 0x10($sp)
/* D92F84 80240044 0000102D */  daddu     $v0, $zero, $zero
/* D92F88 80240048 03E00008 */  jr        $ra
/* D92F8C 8024004C 27BD0018 */   addiu    $sp, $sp, 0x18

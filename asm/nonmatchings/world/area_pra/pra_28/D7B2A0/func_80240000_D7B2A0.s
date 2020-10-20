.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_D7B2A0
/* D7B2A0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D7B2A4 80240004 3C04800E */  lui       $a0, 0x800e
/* D7B2A8 80240008 24849230 */  addiu     $a0, $a0, -0x6dd0
/* D7B2AC 8024000C 3C058024 */  lui       $a1, 0x8024
/* D7B2B0 80240010 24A51880 */  addiu     $a1, $a1, 0x1880
/* D7B2B4 80240014 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* D7B2B8 80240018 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* D7B2BC 8024001C 24020001 */  addiu     $v0, $zero, 1
/* D7B2C0 80240020 AFBF0010 */  sw        $ra, 0x10($sp)
/* D7B2C4 80240024 0C01953C */  jal       sprintf
/* D7B2C8 80240028 A0620084 */   sb       $v0, 0x84($v1)
/* D7B2CC 8024002C 3C04800E */  lui       $a0, 0x800e
/* D7B2D0 80240030 248491E0 */  addiu     $a0, $a0, -0x6e20
/* D7B2D4 80240034 3C058024 */  lui       $a1, 0x8024
/* D7B2D8 80240038 0C01953C */  jal       sprintf
/* D7B2DC 8024003C 24A51890 */   addiu    $a1, $a1, 0x1890
/* D7B2E0 80240040 8FBF0010 */  lw        $ra, 0x10($sp)
/* D7B2E4 80240044 0000102D */  daddu     $v0, $zero, $zero
/* D7B2E8 80240048 03E00008 */  jr        $ra
/* D7B2EC 8024004C 27BD0018 */   addiu    $sp, $sp, 0x18

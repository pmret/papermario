.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80240390_A9ED10
.ascii "kpa_112_shape\0\0\0"

glabel D_802403A0_A9ED20
.ascii "kpa_112_hit\0kpa_113\0kpa_115\0\0\0\0\0"

.section .text

glabel func_80240000_A9E980
/* A9E980 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A9E984 80240004 3C04800E */  lui       $a0, %hi(mapShapeName)
/* A9E988 80240008 24849230 */  addiu     $a0, $a0, %lo(mapShapeName)
/* A9E98C 8024000C 3C058024 */  lui       $a1, %hi(D_80240390_A9ED10)
/* A9E990 80240010 24A50390 */  addiu     $a1, $a1, %lo(D_80240390_A9ED10)
/* A9E994 80240014 AFBF0010 */  sw        $ra, 0x10($sp)
/* A9E998 80240018 0C01953C */  jal       sprintf
/* A9E99C 8024001C 00000000 */   nop
/* A9E9A0 80240020 3C04800E */  lui       $a0, %hi(mapHitName)
/* A9E9A4 80240024 248491E0 */  addiu     $a0, $a0, %lo(mapHitName)
/* A9E9A8 80240028 3C058024 */  lui       $a1, %hi(D_802403A0_A9ED20)
/* A9E9AC 8024002C 0C01953C */  jal       sprintf
/* A9E9B0 80240030 24A503A0 */   addiu    $a1, $a1, %lo(D_802403A0_A9ED20)
/* A9E9B4 80240034 8FBF0010 */  lw        $ra, 0x10($sp)
/* A9E9B8 80240038 0000102D */  daddu     $v0, $zero, $zero
/* A9E9BC 8024003C 03E00008 */  jr        $ra
/* A9E9C0 80240040 27BD0018 */   addiu    $sp, $sp, 0x18
/* A9E9C4 80240044 00000000 */  nop
/* A9E9C8 80240048 00000000 */  nop
/* A9E9CC 8024004C 00000000 */  nop

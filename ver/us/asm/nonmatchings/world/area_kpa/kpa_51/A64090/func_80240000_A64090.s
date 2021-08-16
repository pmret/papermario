.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80242F20_A66FB0
.ascii "kpa_50_shape\0\0\0\0"

glabel D_80242F30_A66FC0
.ascii "kpa_50_hit\0\0kpa_32\0\0kpa_133\0\0\0\0\0"

.section .text

glabel func_80240000_A64090
/* A64090 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A64094 80240004 3C04800E */  lui       $a0, %hi(gMapShapeName)
/* A64098 80240008 24849230 */  addiu     $a0, $a0, %lo(gMapShapeName)
/* A6409C 8024000C 3C058024 */  lui       $a1, %hi(D_80242F20_A66FB0)
/* A640A0 80240010 24A52F20 */  addiu     $a1, $a1, %lo(D_80242F20_A66FB0)
/* A640A4 80240014 AFBF0010 */  sw        $ra, 0x10($sp)
/* A640A8 80240018 0C01953C */  jal       sprintf
/* A640AC 8024001C 00000000 */   nop
/* A640B0 80240020 3C04800E */  lui       $a0, %hi(mapHitName)
/* A640B4 80240024 248491E0 */  addiu     $a0, $a0, %lo(mapHitName)
/* A640B8 80240028 3C058024 */  lui       $a1, %hi(D_80242F30_A66FC0)
/* A640BC 8024002C 0C01953C */  jal       sprintf
/* A640C0 80240030 24A52F30 */   addiu    $a1, $a1, %lo(D_80242F30_A66FC0)
/* A640C4 80240034 8FBF0010 */  lw        $ra, 0x10($sp)
/* A640C8 80240038 0000102D */  daddu     $v0, $zero, $zero
/* A640CC 8024003C 03E00008 */  jr        $ra
/* A640D0 80240040 27BD0018 */   addiu    $sp, $sp, 0x18
/* A640D4 80240044 00000000 */  nop
/* A640D8 80240048 00000000 */  nop
/* A640DC 8024004C 00000000 */  nop

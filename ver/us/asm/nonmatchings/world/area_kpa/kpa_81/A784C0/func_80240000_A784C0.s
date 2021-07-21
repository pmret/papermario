.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80242000_A7A4C0
.ascii "kpa_80_shape\0\0\0\0"

glabel D_80242010_A7A4D0
.ascii "kpa_80_hit\0\0kpa_50\0\0kpa_32\0\0kpa_04\0\0kpa_17\0\0\0\0\0\0"

.section .text

glabel func_80240000_A784C0
/* A784C0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A784C4 80240004 3C04800E */  lui       $a0, %hi(mapShapeName)
/* A784C8 80240008 24849230 */  addiu     $a0, $a0, %lo(mapShapeName)
/* A784CC 8024000C 3C058024 */  lui       $a1, %hi(D_80242000_A7A4C0)
/* A784D0 80240010 24A52000 */  addiu     $a1, $a1, %lo(D_80242000_A7A4C0)
/* A784D4 80240014 AFBF0010 */  sw        $ra, 0x10($sp)
/* A784D8 80240018 0C01953C */  jal       sprintf
/* A784DC 8024001C 00000000 */   nop
/* A784E0 80240020 3C04800E */  lui       $a0, %hi(mapHitName)
/* A784E4 80240024 248491E0 */  addiu     $a0, $a0, %lo(mapHitName)
/* A784E8 80240028 3C058024 */  lui       $a1, %hi(D_80242010_A7A4D0)
/* A784EC 8024002C 0C01953C */  jal       sprintf
/* A784F0 80240030 24A52010 */   addiu    $a1, $a1, %lo(D_80242010_A7A4D0)
/* A784F4 80240034 8FBF0010 */  lw        $ra, 0x10($sp)
/* A784F8 80240038 0000102D */  daddu     $v0, $zero, $zero
/* A784FC 8024003C 03E00008 */  jr        $ra
/* A78500 80240040 27BD0018 */   addiu    $sp, $sp, 0x18
/* A78504 80240044 00000000 */  nop
/* A78508 80240048 00000000 */  nop
/* A7850C 8024004C 00000000 */  nop

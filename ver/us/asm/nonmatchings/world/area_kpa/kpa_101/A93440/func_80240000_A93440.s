.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_802402D0_A93710
.ascii "kpa_119_shape\0\0\0"

dlabel D_802402E0_A93720
.ascii "kpa_119_hit\0kpa_09\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

.section .text

glabel func_80240000_A93440
/* A93440 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A93444 80240004 3C04800E */  lui       $a0, %hi(wMapShapeName)
/* A93448 80240008 24849230 */  addiu     $a0, $a0, %lo(wMapShapeName)
/* A9344C 8024000C 3C058024 */  lui       $a1, %hi(D_802402D0_A93710)
/* A93450 80240010 24A502D0 */  addiu     $a1, $a1, %lo(D_802402D0_A93710)
/* A93454 80240014 AFBF0010 */  sw        $ra, 0x10($sp)
/* A93458 80240018 0C01953C */  jal       sprintf
/* A9345C 8024001C 00000000 */   nop
/* A93460 80240020 3C04800E */  lui       $a0, %hi(wMapHitName)
/* A93464 80240024 248491E0 */  addiu     $a0, $a0, %lo(wMapHitName)
/* A93468 80240028 3C058024 */  lui       $a1, %hi(D_802402E0_A93720)
/* A9346C 8024002C 0C01953C */  jal       sprintf
/* A93470 80240030 24A502E0 */   addiu    $a1, $a1, %lo(D_802402E0_A93720)
/* A93474 80240034 8FBF0010 */  lw        $ra, 0x10($sp)
/* A93478 80240038 0000102D */  daddu     $v0, $zero, $zero
/* A9347C 8024003C 03E00008 */  jr        $ra
/* A93480 80240040 27BD0018 */   addiu    $sp, $sp, 0x18
/* A93484 80240044 00000000 */  nop
/* A93488 80240048 00000000 */  nop
/* A9348C 8024004C 00000000 */  nop

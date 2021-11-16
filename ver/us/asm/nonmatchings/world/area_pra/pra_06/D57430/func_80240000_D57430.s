.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_80241430_D58860
.ascii "pra_05_shape\0\0\0\0"

dlabel D_80241440_D58870
.ascii "pra_05_hit\0\0pra_39\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

.section .text

glabel func_80240000_D57430
/* D57430 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D57434 80240004 3C04800E */  lui       $a0, %hi(wMapShapeName)
/* D57438 80240008 24849230 */  addiu     $a0, $a0, %lo(wMapShapeName)
/* D5743C 8024000C 3C058024 */  lui       $a1, %hi(D_80241430_D58860)
/* D57440 80240010 24A51430 */  addiu     $a1, $a1, %lo(D_80241430_D58860)
/* D57444 80240014 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* D57448 80240018 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* D5744C 8024001C 24020001 */  addiu     $v0, $zero, 1
/* D57450 80240020 AFBF0010 */  sw        $ra, 0x10($sp)
/* D57454 80240024 0C01953C */  jal       sprintf
/* D57458 80240028 A0620084 */   sb       $v0, 0x84($v1)
/* D5745C 8024002C 3C04800E */  lui       $a0, %hi(wMapHitName)
/* D57460 80240030 248491E0 */  addiu     $a0, $a0, %lo(wMapHitName)
/* D57464 80240034 3C058024 */  lui       $a1, %hi(D_80241440_D58870)
/* D57468 80240038 0C01953C */  jal       sprintf
/* D5746C 8024003C 24A51440 */   addiu    $a1, $a1, %lo(D_80241440_D58870)
/* D57470 80240040 8FBF0010 */  lw        $ra, 0x10($sp)
/* D57474 80240044 0000102D */  daddu     $v0, $zero, $zero
/* D57478 80240048 03E00008 */  jr        $ra
/* D5747C 8024004C 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802420A0_D99930
.ascii "pra_10_shape\0\0\0\0"

glabel D_802420B0_D99940
.ascii "pra_10_hit\0\0pra_04\0\0pra_06\0\0\0\0\0\0"

.section .text

glabel func_80240000_D97890
/* D97890 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D97894 80240004 3C04800E */  lui       $a0, %hi(mapShapeName)
/* D97898 80240008 24849230 */  addiu     $a0, $a0, %lo(mapShapeName)
/* D9789C 8024000C 3C058024 */  lui       $a1, %hi(D_802420A0_D99930)
/* D978A0 80240010 24A520A0 */  addiu     $a1, $a1, %lo(D_802420A0_D99930)
/* D978A4 80240014 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* D978A8 80240018 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* D978AC 8024001C 24020001 */  addiu     $v0, $zero, 1
/* D978B0 80240020 AFBF0010 */  sw        $ra, 0x10($sp)
/* D978B4 80240024 0C01953C */  jal       sprintf
/* D978B8 80240028 A0620084 */   sb       $v0, 0x84($v1)
/* D978BC 8024002C 3C04800E */  lui       $a0, %hi(mapHitName)
/* D978C0 80240030 248491E0 */  addiu     $a0, $a0, %lo(mapHitName)
/* D978C4 80240034 3C058024 */  lui       $a1, %hi(D_802420B0_D99940)
/* D978C8 80240038 0C01953C */  jal       sprintf
/* D978CC 8024003C 24A520B0 */   addiu    $a1, $a1, %lo(D_802420B0_D99940)
/* D978D0 80240040 8FBF0010 */  lw        $ra, 0x10($sp)
/* D978D4 80240044 0000102D */  daddu     $v0, $zero, $zero
/* D978D8 80240048 03E00008 */  jr        $ra
/* D978DC 8024004C 27BD0018 */   addiu    $sp, $sp, 0x18

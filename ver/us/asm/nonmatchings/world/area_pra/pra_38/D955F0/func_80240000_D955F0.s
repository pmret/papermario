.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80242220_D97810
.ascii "pra_10_shape\0\0\0\0"

glabel D_80242230_D97820
.ascii "pra_10_hit\0\0pra_03\0\0pra_05\0\0\0\0\0\0"

.section .text

glabel func_80240000_D955F0
/* D955F0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D955F4 80240004 3C04800E */  lui       $a0, %hi(wMapShapeName)
/* D955F8 80240008 24849230 */  addiu     $a0, $a0, %lo(wMapShapeName)
/* D955FC 8024000C 3C058024 */  lui       $a1, %hi(D_80242220_D97810)
/* D95600 80240010 24A52220 */  addiu     $a1, $a1, %lo(D_80242220_D97810)
/* D95604 80240014 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* D95608 80240018 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* D9560C 8024001C 24020001 */  addiu     $v0, $zero, 1
/* D95610 80240020 AFBF0010 */  sw        $ra, 0x10($sp)
/* D95614 80240024 0C01953C */  jal       sprintf
/* D95618 80240028 A0620084 */   sb       $v0, 0x84($v1)
/* D9561C 8024002C 3C04800E */  lui       $a0, %hi(wMapHitName)
/* D95620 80240030 248491E0 */  addiu     $a0, $a0, %lo(wMapHitName)
/* D95624 80240034 3C058024 */  lui       $a1, %hi(D_80242230_D97820)
/* D95628 80240038 0C01953C */  jal       sprintf
/* D9562C 8024003C 24A52230 */   addiu    $a1, $a1, %lo(D_80242230_D97820)
/* D95630 80240040 8FBF0010 */  lw        $ra, 0x10($sp)
/* D95634 80240044 0000102D */  daddu     $v0, $zero, $zero
/* D95638 80240048 03E00008 */  jr        $ra
/* D9563C 8024004C 27BD0018 */   addiu    $sp, $sp, 0x18

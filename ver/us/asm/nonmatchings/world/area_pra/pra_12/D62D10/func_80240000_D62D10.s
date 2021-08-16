.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_802418A0_D645B0
.ascii "pra_05_shape\0\0\0\0"

glabel D_802418B0_D645C0
.ascii "pra_05_hit\0\0pra_10\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

.section .text

glabel func_80240000_D62D10
/* D62D10 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D62D14 80240004 3C04800E */  lui       $a0, %hi(gMapShapeName)
/* D62D18 80240008 24849230 */  addiu     $a0, $a0, %lo(gMapShapeName)
/* D62D1C 8024000C 3C058024 */  lui       $a1, %hi(D_802418A0_D645B0)
/* D62D20 80240010 24A518A0 */  addiu     $a1, $a1, %lo(D_802418A0_D645B0)
/* D62D24 80240014 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* D62D28 80240018 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* D62D2C 8024001C 24020001 */  addiu     $v0, $zero, 1
/* D62D30 80240020 AFBF0010 */  sw        $ra, 0x10($sp)
/* D62D34 80240024 0C01953C */  jal       sprintf
/* D62D38 80240028 A0620084 */   sb       $v0, 0x84($v1)
/* D62D3C 8024002C 3C04800E */  lui       $a0, %hi(mapHitName)
/* D62D40 80240030 248491E0 */  addiu     $a0, $a0, %lo(mapHitName)
/* D62D44 80240034 3C058024 */  lui       $a1, %hi(D_802418B0_D645C0)
/* D62D48 80240038 0C01953C */  jal       sprintf
/* D62D4C 8024003C 24A518B0 */   addiu    $a1, $a1, %lo(D_802418B0_D645C0)
/* D62D50 80240040 8FBF0010 */  lw        $ra, 0x10($sp)
/* D62D54 80240044 0000102D */  daddu     $v0, $zero, $zero
/* D62D58 80240048 03E00008 */  jr        $ra
/* D62D5C 8024004C 27BD0018 */   addiu    $sp, $sp, 0x18

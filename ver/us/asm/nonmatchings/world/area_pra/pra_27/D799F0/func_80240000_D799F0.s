.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80241880_D7B270
.ascii "pra_05_shape\0\0\0\0"

glabel D_80241890_D7B280
.ascii "pra_05_hit\0\0pra_36\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

.section .text

glabel func_80240000_D799F0
/* D799F0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D799F4 80240004 3C04800E */  lui       $a0, %hi(D_800D9230)
/* D799F8 80240008 24849230 */  addiu     $a0, $a0, %lo(D_800D9230)
/* D799FC 8024000C 3C058024 */  lui       $a1, %hi(D_80241880_D7B270)
/* D79A00 80240010 24A51880 */  addiu     $a1, $a1, %lo(D_80241880_D7B270)
/* D79A04 80240014 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* D79A08 80240018 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* D79A0C 8024001C 24020001 */  addiu     $v0, $zero, 1
/* D79A10 80240020 AFBF0010 */  sw        $ra, 0x10($sp)
/* D79A14 80240024 0C01953C */  jal       sprintf
/* D79A18 80240028 A0620084 */   sb       $v0, 0x84($v1)
/* D79A1C 8024002C 3C04800E */  lui       $a0, %hi(D_800D91E0)
/* D79A20 80240030 248491E0 */  addiu     $a0, $a0, %lo(D_800D91E0)
/* D79A24 80240034 3C058024 */  lui       $a1, %hi(D_80241890_D7B280)
/* D79A28 80240038 0C01953C */  jal       sprintf
/* D79A2C 8024003C 24A51890 */   addiu    $a1, $a1, %lo(D_80241890_D7B280)
/* D79A30 80240040 8FBF0010 */  lw        $ra, 0x10($sp)
/* D79A34 80240044 0000102D */  daddu     $v0, $zero, $zero
/* D79A38 80240048 03E00008 */  jr        $ra
/* D79A3C 8024004C 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80248F60_A83460
.ascii "kpa_80_shape\0\0\0\0"

glabel D_80248F70_A83470
.ascii "kpa_80_hit\0\0kpa_113\0kpa_61\0\0\0\0\0\0"

.section .text

glabel func_80240000_A7A500
/* A7A500 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A7A504 80240004 3C04800E */  lui       $a0, %hi(D_800D9230)
/* A7A508 80240008 24849230 */  addiu     $a0, $a0, %lo(D_800D9230)
/* A7A50C 8024000C 3C058025 */  lui       $a1, %hi(D_80248F60_A83460)
/* A7A510 80240010 24A58F60 */  addiu     $a1, $a1, %lo(D_80248F60_A83460)
/* A7A514 80240014 AFBF0010 */  sw        $ra, 0x10($sp)
/* A7A518 80240018 0C01953C */  jal       sprintf
/* A7A51C 8024001C 00000000 */   nop
/* A7A520 80240020 3C04800E */  lui       $a0, %hi(D_800D91E0)
/* A7A524 80240024 248491E0 */  addiu     $a0, $a0, %lo(D_800D91E0)
/* A7A528 80240028 3C058025 */  lui       $a1, %hi(D_80248F70_A83470)
/* A7A52C 8024002C 0C01953C */  jal       sprintf
/* A7A530 80240030 24A58F70 */   addiu    $a1, $a1, %lo(D_80248F70_A83470)
/* A7A534 80240034 8FBF0010 */  lw        $ra, 0x10($sp)
/* A7A538 80240038 0000102D */  daddu     $v0, $zero, $zero
/* A7A53C 8024003C 03E00008 */  jr        $ra
/* A7A540 80240040 27BD0018 */   addiu    $sp, $sp, 0x18
/* A7A544 80240044 00000000 */  nop
/* A7A548 80240048 00000000 */  nop
/* A7A54C 8024004C 00000000 */  nop

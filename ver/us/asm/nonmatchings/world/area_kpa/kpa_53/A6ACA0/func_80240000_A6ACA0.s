.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80241E20_A6CAC0
.ascii "kpa_50_shape\0\0\0\0"

glabel D_80241E30_A6CAD0
.ascii "kpa_50_hit\0\0kpa_102\0kpa_83\0\0\0\0\0\0"

.section .text

glabel func_80240000_A6ACA0
/* A6ACA0 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A6ACA4 80240004 3C04800E */  lui       $a0, %hi(D_800D9230)
/* A6ACA8 80240008 24849230 */  addiu     $a0, $a0, %lo(D_800D9230)
/* A6ACAC 8024000C 3C058024 */  lui       $a1, %hi(D_80241E20_A6CAC0)
/* A6ACB0 80240010 24A51E20 */  addiu     $a1, $a1, %lo(D_80241E20_A6CAC0)
/* A6ACB4 80240014 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* A6ACB8 80240018 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* A6ACBC 8024001C 24020002 */  addiu     $v0, $zero, 2
/* A6ACC0 80240020 AFBF0010 */  sw        $ra, 0x10($sp)
/* A6ACC4 80240024 0C01953C */  jal       sprintf
/* A6ACC8 80240028 A0620084 */   sb       $v0, 0x84($v1)
/* A6ACCC 8024002C 3C04800E */  lui       $a0, %hi(D_800D91E0)
/* A6ACD0 80240030 248491E0 */  addiu     $a0, $a0, %lo(D_800D91E0)
/* A6ACD4 80240034 3C058024 */  lui       $a1, %hi(D_80241E30_A6CAD0)
/* A6ACD8 80240038 0C01953C */  jal       sprintf
/* A6ACDC 8024003C 24A51E30 */   addiu    $a1, $a1, %lo(D_80241E30_A6CAD0)
/* A6ACE0 80240040 8FBF0010 */  lw        $ra, 0x10($sp)
/* A6ACE4 80240044 0000102D */  daddu     $v0, $zero, $zero
/* A6ACE8 80240048 03E00008 */  jr        $ra
/* A6ACEC 8024004C 27BD0018 */   addiu    $sp, $sp, 0x18

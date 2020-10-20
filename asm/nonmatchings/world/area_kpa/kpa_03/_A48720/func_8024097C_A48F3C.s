.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024097C_A48F3C
/* A48F3C 8024097C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A48F40 80240980 AFBF0010 */  sw        $ra, 0x10($sp)
/* A48F44 80240984 0C00EAD2 */  jal       get_npc_safe
/* A48F48 80240988 8C84014C */   lw       $a0, 0x14c($a0)
/* A48F4C 8024098C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* A48F50 80240990 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* A48F54 80240994 C44C0038 */  lwc1      $f12, 0x38($v0)
/* A48F58 80240998 C44E0040 */  lwc1      $f14, 0x40($v0)
/* A48F5C 8024099C 8C660028 */  lw        $a2, 0x28($v1)
/* A48F60 802409A0 0C00A7B5 */  jal       dist2D
/* A48F64 802409A4 8C670030 */   lw       $a3, 0x30($v1)
/* A48F68 802409A8 3C014248 */  lui       $at, 0x4248
/* A48F6C 802409AC 44811000 */  mtc1      $at, $f2
/* A48F70 802409B0 00000000 */  nop       
/* A48F74 802409B4 4602003C */  c.lt.s    $f0, $f2
/* A48F78 802409B8 00000000 */  nop       
/* A48F7C 802409BC 45010002 */  bc1t      .L802409C8
/* A48F80 802409C0 24020002 */   addiu    $v0, $zero, 2
/* A48F84 802409C4 0000102D */  daddu     $v0, $zero, $zero
.L802409C8:
/* A48F88 802409C8 8FBF0010 */  lw        $ra, 0x10($sp)
/* A48F8C 802409CC 03E00008 */  jr        $ra
/* A48F90 802409D0 27BD0018 */   addiu    $sp, $sp, 0x18

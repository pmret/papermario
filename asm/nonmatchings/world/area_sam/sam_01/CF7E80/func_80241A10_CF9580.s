.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A10_CF9580
/* CF9580 80241A10 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CF9584 80241A14 AFB00010 */  sw        $s0, 0x10($sp)
/* CF9588 80241A18 0080802D */  daddu     $s0, $a0, $zero
/* CF958C 80241A1C AFBF0014 */  sw        $ra, 0x14($sp)
/* CF9590 80241A20 0C00EABB */  jal       get_npc_unsafe
/* CF9594 80241A24 8E04008C */   lw       $a0, 0x8c($s0)
/* CF9598 80241A28 0040282D */  daddu     $a1, $v0, $zero
/* CF959C 80241A2C 8E040094 */  lw        $a0, 0x94($s0)
/* CF95A0 80241A30 8CA30028 */  lw        $v1, 0x28($a1)
/* CF95A4 80241A34 ACA40028 */  sw        $a0, 0x28($a1)
/* CF95A8 80241A38 8FBF0014 */  lw        $ra, 0x14($sp)
/* CF95AC 80241A3C 8FB00010 */  lw        $s0, 0x10($sp)
/* CF95B0 80241A40 24020002 */  addiu     $v0, $zero, 2
/* CF95B4 80241A44 3C018025 */  lui       $at, %hi(D_8024DF24)
/* CF95B8 80241A48 AC23DF24 */  sw        $v1, %lo(D_8024DF24)($at)
/* CF95BC 80241A4C 03E00008 */  jr        $ra
/* CF95C0 80241A50 27BD0018 */   addiu    $sp, $sp, 0x18

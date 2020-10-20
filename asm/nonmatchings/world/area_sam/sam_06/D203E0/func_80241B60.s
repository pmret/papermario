.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B60
/* D219F0 80241B60 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D219F4 80241B64 AFB10014 */  sw        $s1, 0x14($sp)
/* D219F8 80241B68 0080882D */  daddu     $s1, $a0, $zero
/* D219FC 80241B6C AFBF0018 */  sw        $ra, 0x18($sp)
/* D21A00 80241B70 AFB00010 */  sw        $s0, 0x10($sp)
/* D21A04 80241B74 8E30000C */  lw        $s0, 0xc($s1)
/* D21A08 80241B78 8E050000 */  lw        $a1, ($s0)
/* D21A0C 80241B7C 0C0B1EAF */  jal       get_variable
/* D21A10 80241B80 26100004 */   addiu    $s0, $s0, 4
/* D21A14 80241B84 0C00EAD2 */  jal       get_npc_safe
/* D21A18 80241B88 0040202D */   daddu    $a0, $v0, $zero
/* D21A1C 80241B8C 10400005 */  beqz      $v0, .L80241BA4
/* D21A20 80241B90 00000000 */   nop      
/* D21A24 80241B94 8E050000 */  lw        $a1, ($s0)
/* D21A28 80241B98 844600A8 */  lh        $a2, 0xa8($v0)
/* D21A2C 80241B9C 0C0B2026 */  jal       set_variable
/* D21A30 80241BA0 0220202D */   daddu    $a0, $s1, $zero
.L80241BA4:
/* D21A34 80241BA4 8FBF0018 */  lw        $ra, 0x18($sp)
/* D21A38 80241BA8 8FB10014 */  lw        $s1, 0x14($sp)
/* D21A3C 80241BAC 8FB00010 */  lw        $s0, 0x10($sp)
/* D21A40 80241BB0 24020002 */  addiu     $v0, $zero, 2
/* D21A44 80241BB4 03E00008 */  jr        $ra
/* D21A48 80241BB8 27BD0020 */   addiu    $sp, $sp, 0x20

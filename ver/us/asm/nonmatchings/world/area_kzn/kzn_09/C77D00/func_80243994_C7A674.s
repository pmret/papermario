.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243994_C7A674
/* C7A674 80243994 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C7A678 80243998 AFB00010 */  sw        $s0, 0x10($sp)
/* C7A67C 8024399C 0080802D */  daddu     $s0, $a0, $zero
/* C7A680 802439A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* C7A684 802439A4 0C00EABB */  jal       get_npc_unsafe
/* C7A688 802439A8 8E04008C */   lw       $a0, 0x8c($s0)
/* C7A68C 802439AC 0040282D */  daddu     $a1, $v0, $zero
/* C7A690 802439B0 8E040094 */  lw        $a0, 0x94($s0)
/* C7A694 802439B4 8CA30028 */  lw        $v1, 0x28($a1)
/* C7A698 802439B8 ACA40028 */  sw        $a0, 0x28($a1)
/* C7A69C 802439BC 8FBF0014 */  lw        $ra, 0x14($sp)
/* C7A6A0 802439C0 8FB00010 */  lw        $s0, 0x10($sp)
/* C7A6A4 802439C4 24020002 */  addiu     $v0, $zero, 2
/* C7A6A8 802439C8 3C018024 */  lui       $at, %hi(D_80247664)
/* C7A6AC 802439CC AC237664 */  sw        $v1, %lo(D_80247664)($at)
/* C7A6B0 802439D0 03E00008 */  jr        $ra
/* C7A6B4 802439D4 27BD0018 */   addiu    $sp, $sp, 0x18

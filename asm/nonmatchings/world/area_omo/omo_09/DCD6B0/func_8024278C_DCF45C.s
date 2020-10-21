.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024278C_DCF45C
/* DCF45C 8024278C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DCF460 80242790 AFB10014 */  sw        $s1, 0x14($sp)
/* DCF464 80242794 0080882D */  daddu     $s1, $a0, $zero
/* DCF468 80242798 AFBF0018 */  sw        $ra, 0x18($sp)
/* DCF46C 8024279C AFB00010 */  sw        $s0, 0x10($sp)
/* DCF470 802427A0 8E300148 */  lw        $s0, 0x148($s1)
/* DCF474 802427A4 0C00EABB */  jal       get_npc_unsafe
/* DCF478 802427A8 86040008 */   lh       $a0, 8($s0)
/* DCF47C 802427AC 96030076 */  lhu       $v1, 0x76($s0)
/* DCF480 802427B0 A443008E */  sh        $v1, 0x8e($v0)
/* DCF484 802427B4 24020021 */  addiu     $v0, $zero, 0x21
/* DCF488 802427B8 AE220070 */  sw        $v0, 0x70($s1)
/* DCF48C 802427BC 8FBF0018 */  lw        $ra, 0x18($sp)
/* DCF490 802427C0 8FB10014 */  lw        $s1, 0x14($sp)
/* DCF494 802427C4 8FB00010 */  lw        $s0, 0x10($sp)
/* DCF498 802427C8 03E00008 */  jr        $ra
/* DCF49C 802427CC 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_801497FC
/* DFEFC 801497FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DFF00 80149800 AFB00010 */  sw        $s0, 0x10($sp)
/* DFF04 80149804 AFBF0014 */  sw        $ra, 0x14($sp)
/* DFF08 80149808 0C015879 */  jal       func_800561E4
/* DFF0C 8014980C 0080802D */   daddu    $s0, $a0, $zero
/* DFF10 80149810 8FBF0014 */  lw        $ra, 0x14($sp)
/* DFF14 80149814 3C018016 */  lui       $at, %hi(D_80159AD4)
/* DFF18 80149818 AC309AD4 */  sw        $s0, %lo(D_80159AD4)($at)
/* DFF1C 8014981C 8FB00010 */  lw        $s0, 0x10($sp)
/* DFF20 80149820 03E00008 */  jr        $ra
/* DFF24 80149824 27BD0018 */   addiu    $sp, $sp, 0x18

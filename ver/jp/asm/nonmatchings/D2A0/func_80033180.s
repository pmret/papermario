.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80033180
/* E580 80033180 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E584 80033184 3C01800A */  lui       $at, %hi(D_8009E700)
/* E588 80033188 A424E700 */  sh        $a0, %lo(D_8009E700)($at)
/* E58C 8003318C 00042400 */  sll       $a0, $a0, 0x10
/* E590 80033190 00042383 */  sra       $a0, $a0, 0xe
/* E594 80033194 AFBF0010 */  sw        $ra, 0x10($sp)
/* E598 80033198 3C058007 */  lui       $a1, %hi(D_80077820)
/* E59C 8003319C 00A42821 */  addu      $a1, $a1, $a0
/* E5A0 800331A0 8CA57820 */  lw        $a1, %lo(D_80077820)($a1)
/* E5A4 800331A4 0C045FAE */  jal       func_80117EB8
/* E5A8 800331A8 0000202D */   daddu    $a0, $zero, $zero
/* E5AC 800331AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* E5B0 800331B0 03E00008 */  jr        $ra
/* E5B4 800331B4 27BD0018 */   addiu    $sp, $sp, 0x18

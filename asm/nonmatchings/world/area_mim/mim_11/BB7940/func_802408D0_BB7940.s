.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802408D0_BB7940
/* BB7940 802408D0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BB7944 802408D4 AFBF0010 */  sw        $ra, 0x10($sp)
/* BB7948 802408D8 0C03A86D */  jal       increment_max_SP
/* BB794C 802408DC 00000000 */   nop      
/* BB7950 802408E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* BB7954 802408E4 24020002 */  addiu     $v0, $zero, 2
/* BB7958 802408E8 03E00008 */  jr        $ra
/* BB795C 802408EC 27BD0018 */   addiu    $sp, $sp, 0x18

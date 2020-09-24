.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802827A8
/* 7E3628 802827A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E362C 802827AC AFBF0010 */  sw        $ra, 0x10($sp)
/* 7E3630 802827B0 8C820074 */  lw        $v0, 0x74($a0)
/* 7E3634 802827B4 0C04D08C */  jal       func_80134230
/* 7E3638 802827B8 8444000A */   lh       $a0, 0xa($v0)
/* 7E363C 802827BC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 7E3640 802827C0 24020002 */  addiu     $v0, $zero, 2
/* 7E3644 802827C4 03E00008 */  jr        $ra
/* 7E3648 802827C8 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240408_AA93A8
/* AA93A8 80240408 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AA93AC 8024040C 3C05442A */  lui       $a1, 0x442a
/* AA93B0 80240410 3C064370 */  lui       $a2, 0x4370
/* AA93B4 80240414 3C07C20C */  lui       $a3, 0xc20c
/* AA93B8 80240418 AFBF0010 */  sw        $ra, 0x10($sp)
/* AA93BC 8024041C 0C044898 */  jal       create_shadow_type
/* AA93C0 80240420 0000202D */   daddu    $a0, $zero, $zero
/* AA93C4 80240424 8FBF0010 */  lw        $ra, 0x10($sp)
/* AA93C8 80240428 24020002 */  addiu     $v0, $zero, 2
/* AA93CC 8024042C 03E00008 */  jr        $ra
/* AA93D0 80240430 27BD0018 */   addiu    $sp, $sp, 0x18

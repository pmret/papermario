.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240408_C805A8
/* C805A8 80240408 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C805AC 8024040C AFBF0010 */  sw        $ra, 0x10($sp)
/* C805B0 80240410 8C82000C */  lw        $v0, 0xc($a0)
/* C805B4 80240414 3C068016 */  lui       $a2, %hi(gCollisionStatus+0x2)
/* C805B8 80240418 84C6A552 */  lh        $a2, %lo(gCollisionStatus+0x2)($a2)
/* C805BC 8024041C 0C0B2026 */  jal       set_variable
/* C805C0 80240420 8C450000 */   lw       $a1, ($v0)
/* C805C4 80240424 8FBF0010 */  lw        $ra, 0x10($sp)
/* C805C8 80240428 24020002 */  addiu     $v0, $zero, 2
/* C805CC 8024042C 03E00008 */  jr        $ra
/* C805D0 80240430 27BD0018 */   addiu    $sp, $sp, 0x18

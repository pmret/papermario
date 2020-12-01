.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242360_CCD670
/* CCD670 80242360 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CCD674 80242364 AFBF0010 */  sw        $ra, 0x10($sp)
/* CCD678 80242368 8C82000C */  lw        $v0, 0xc($a0)
/* CCD67C 8024236C 3C068016 */  lui       $a2, %hi(gCollisionStatus+0x6)
/* CCD680 80242370 84C6A556 */  lh        $a2, %lo(gCollisionStatus+0x6)($a2)
/* CCD684 80242374 0C0B2026 */  jal       set_variable
/* CCD688 80242378 8C450000 */   lw       $a1, ($v0)
/* CCD68C 8024237C 8FBF0010 */  lw        $ra, 0x10($sp)
/* CCD690 80242380 24020002 */  addiu     $v0, $zero, 2
/* CCD694 80242384 03E00008 */  jr        $ra
/* CCD698 80242388 27BD0018 */   addiu    $sp, $sp, 0x18
/* CCD69C 8024238C 00000000 */  nop       

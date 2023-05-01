.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

glabel nuGfxSetUcodeFifo
/* 3BE20 80060A20 3C018007 */  lui       $at, %hi(D_PAL_80073718)
/* 3BE24 80060A24 AC243718 */  sw        $a0, %lo(D_PAL_80073718)($at)
/* 3BE28 80060A28 3C018007 */  lui       $at, %hi(D_PAL_80073714)
/* 3BE2C 80060A2C AC253714 */  sw        $a1, %lo(D_PAL_80073714)($at)
/* 3BE30 80060A30 03E00008 */  jr        $ra
/* 3BE34 80060A34 00000000 */   nop
/* 3BE38 80060A38 00000000 */  nop
/* 3BE3C 80060A3C 00000000 */  nop

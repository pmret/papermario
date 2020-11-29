.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel partner_can_use_ability
/* 848DC 800EB42C 3C028011 */  lui       $v0, %hi(D_8010CFEC)
/* 848E0 800EB430 8C42CFEC */  lw        $v0, %lo(D_8010CFEC)($v0)
/* 848E4 800EB434 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 848E8 800EB438 AFBF0010 */  sw        $ra, 0x10($sp)
/* 848EC 800EB43C 8C42002C */  lw        $v0, 0x2c($v0)
/* 848F0 800EB440 50400009 */  beql      $v0, $zero, .L800EB468
/* 848F4 800EB444 0000102D */   daddu    $v0, $zero, $zero
/* 848F8 800EB448 3C048011 */  lui       $a0, %hi(D_8010C930)
/* 848FC 800EB44C 8C84C930 */  lw        $a0, %lo(D_8010C930)($a0)
/* 84900 800EB450 0040F809 */  jalr      $v0
/* 84904 800EB454 00000000 */   nop      
/* 84908 800EB458 0040182D */  daddu     $v1, $v0, $zero
/* 8490C 800EB45C 10600002 */  beqz      $v1, .L800EB468
/* 84910 800EB460 24020001 */   addiu    $v0, $zero, 1
/* 84914 800EB464 0000102D */  daddu     $v0, $zero, $zero
.L800EB468:
/* 84918 800EB468 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8491C 800EB46C 03E00008 */  jr        $ra
/* 84920 800EB470 27BD0018 */   addiu    $sp, $sp, 0x18

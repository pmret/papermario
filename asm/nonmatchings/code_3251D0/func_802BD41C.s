.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD41C
/* 3254EC 802BD41C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3254F0 802BD420 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3254F4 802BD424 0C009C22 */  jal       func_80027088
/* 3254F8 802BD428 0000202D */   daddu    $a0, $zero, $zero
/* 3254FC 802BD42C 3C04FFDF */  lui       $a0, 0xffdf
/* 325500 802BD430 3C03800A */  lui       $v1, %hi(D_8009A650)
/* 325504 802BD434 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* 325508 802BD438 8C620000 */  lw        $v0, ($v1)
/* 32550C 802BD43C 3484FFFF */  ori       $a0, $a0, 0xffff
/* 325510 802BD440 00441024 */  and       $v0, $v0, $a0
/* 325514 802BD444 AC620000 */  sw        $v0, ($v1)
/* 325518 802BD448 8FBF0010 */  lw        $ra, 0x10($sp)
/* 32551C 802BD44C 24020002 */  addiu     $v0, $zero, 2
/* 325520 802BD450 03E00008 */  jr        $ra
/* 325524 802BD454 27BD0018 */   addiu    $sp, $sp, 0x18

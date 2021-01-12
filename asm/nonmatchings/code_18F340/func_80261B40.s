.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80261B40
/* 190420 80261B40 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 190424 80261B44 AFB00010 */  sw        $s0, 0x10($sp)
/* 190428 80261B48 0080802D */  daddu     $s0, $a0, $zero
/* 19042C 80261B4C AFBF0014 */  sw        $ra, 0x14($sp)
/* 190430 80261B50 8E0200AC */  lw        $v0, 0xac($s0)
/* 190434 80261B54 18400005 */  blez      $v0, .L80261B6C
/* 190438 80261B58 00000000 */   nop
/* 19043C 80261B5C 3C04802A */  lui       $a0, %hi(D_8029FBAC)
/* 190440 80261B60 8C84FBAC */  lw        $a0, %lo(D_8029FBAC)($a0)
/* 190444 80261B64 0C05123D */  jal       free_icon
/* 190448 80261B68 00000000 */   nop
.L80261B6C:
/* 19044C 80261B6C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 190450 80261B70 1C400004 */  bgtz      $v0, .L80261B84
/* 190454 80261B74 00000000 */   nop
/* 190458 80261B78 8E0200B4 */  lw        $v0, 0xb4($s0)
/* 19045C 80261B7C 18400005 */  blez      $v0, .L80261B94
/* 190460 80261B80 00000000 */   nop
.L80261B84:
/* 190464 80261B84 3C04802A */  lui       $a0, %hi(D_8029FBA8)
/* 190468 80261B88 8C84FBA8 */  lw        $a0, %lo(D_8029FBA8)($a0)
/* 19046C 80261B8C 0C05123D */  jal       free_icon
/* 190470 80261B90 00000000 */   nop
.L80261B94:
/* 190474 80261B94 8FBF0014 */  lw        $ra, 0x14($sp)
/* 190478 80261B98 8FB00010 */  lw        $s0, 0x10($sp)
/* 19047C 80261B9C 24020002 */  addiu     $v0, $zero, 2
/* 190480 80261BA0 03E00008 */  jr        $ra
/* 190484 80261BA4 27BD0018 */   addiu    $sp, $sp, 0x18

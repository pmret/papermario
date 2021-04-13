.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80033488
/* E888 80033488 3C058007 */  lui       $a1, %hi(D_8007417C)
/* E88C 8003348C 8CA5417C */  lw        $a1, %lo(D_8007417C)($a1)
/* E890 80033490 84A200B6 */  lh        $v0, 0xb6($a1)
/* E894 80033494 94A300B6 */  lhu       $v1, 0xb6($a1)
/* E898 80033498 14400003 */  bnez      $v0, .L800334A8
/* E89C 8003349C 00641023 */   subu     $v0, $v1, $a0
/* E8A0 800334A0 03E00008 */  jr        $ra
/* E8A4 800334A4 24020001 */   addiu    $v0, $zero, 1
.L800334A8:
/* E8A8 800334A8 A4A200B6 */  sh        $v0, 0xb6($a1)
/* E8AC 800334AC 00021400 */  sll       $v0, $v0, 0x10
/* E8B0 800334B0 04420001 */  bltzl     $v0, .L800334B8
/* E8B4 800334B4 A4A000B6 */   sh       $zero, 0xb6($a1)
.L800334B8:
/* E8B8 800334B8 03E00008 */  jr        $ra
/* E8BC 800334BC 0000102D */   daddu    $v0, $zero, $zero

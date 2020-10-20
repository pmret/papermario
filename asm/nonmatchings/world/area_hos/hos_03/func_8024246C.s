.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024246C
/* A1D56C 8024246C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1D570 80242470 AFBF0010 */  sw        $ra, 0x10($sp)
/* A1D574 80242474 8C82000C */  lw        $v0, 0xc($a0)
/* A1D578 80242478 0C0B1EAF */  jal       get_variable
/* A1D57C 8024247C 8C450000 */   lw       $a1, ($v0)
/* A1D580 80242480 00021600 */  sll       $v0, $v0, 0x18
/* A1D584 80242484 0C03AC5A */  jal       func_800EB168
/* A1D588 80242488 00022603 */   sra      $a0, $v0, 0x18
/* A1D58C 8024248C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1D590 80242490 24020002 */  addiu     $v0, $zero, 2
/* A1D594 80242494 03E00008 */  jr        $ra
/* A1D598 80242498 27BD0018 */   addiu    $sp, $sp, 0x18

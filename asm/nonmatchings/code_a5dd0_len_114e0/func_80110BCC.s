.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80110BCC
/* A72CC 80110BCC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A72D0 80110BD0 AFBF0010 */  sw        $ra, 0x10($sp)
/* A72D4 80110BD4 8C820000 */  lw        $v0, ($a0)
/* A72D8 80110BD8 30420008 */  andi      $v0, $v0, 8
/* A72DC 80110BDC 14400003 */  bnez      $v0, .L80110BEC
/* A72E0 80110BE0 00000000 */   nop
/* A72E4 80110BE4 0C048B5F */  jal       func_80122D7C
/* A72E8 80110BE8 84840014 */   lh       $a0, 0x14($a0)
.L80110BEC:
/* A72EC 80110BEC 8FBF0010 */  lw        $ra, 0x10($sp)
/* A72F0 80110BF0 03E00008 */  jr        $ra
/* A72F4 80110BF4 27BD0018 */   addiu    $sp, $sp, 0x18

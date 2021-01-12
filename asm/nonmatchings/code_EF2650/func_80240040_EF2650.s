.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_EF2650
/* EF2650 80240040 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EF2654 80240044 AFBF0010 */  sw        $ra, 0x10($sp)
/* EF2658 80240048 8C82000C */  lw        $v0, 0xc($a0)
/* EF265C 8024004C 3C068017 */  lui       $a2, %hi(D_80169B16)
/* EF2660 80240050 84C69B16 */  lh        $a2, %lo(D_80169B16)($a2)
/* EF2664 80240054 0C0B551A */  jal       func_802D5468
/* EF2668 80240058 8C450000 */   lw       $a1, ($v0)
/* EF266C 8024005C 8FBF0010 */  lw        $ra, 0x10($sp)
/* EF2670 80240060 24020002 */  addiu     $v0, $zero, 2
/* EF2674 80240064 03E00008 */  jr        $ra
/* EF2678 80240068 27BD0018 */   addiu    $sp, $sp, 0x18
/* EF267C 8024006C 00000000 */  nop

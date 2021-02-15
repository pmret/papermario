.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242390_EE8940
/* EE8940 80242390 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EE8944 80242394 AFBF0010 */  sw        $ra, 0x10($sp)
/* EE8948 80242398 8C82000C */  lw        $v0, 0xc($a0)
/* EE894C 8024239C 3C068017 */  lui       $a2, %hi(D_80169B16)
/* EE8950 802423A0 84C69B16 */  lh        $a2, %lo(D_80169B16)($a2)
/* EE8954 802423A4 0C0B551A */  jal       func_802D5468
/* EE8958 802423A8 8C450000 */   lw       $a1, ($v0)
/* EE895C 802423AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* EE8960 802423B0 24020002 */  addiu     $v0, $zero, 2
/* EE8964 802423B4 03E00008 */  jr        $ra
/* EE8968 802423B8 27BD0018 */   addiu    $sp, $sp, 0x18
/* EE896C 802423BC 00000000 */  nop

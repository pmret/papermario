.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024041C_ECA11C
/* ECA11C 8024041C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ECA120 80240420 AFBF0010 */  sw        $ra, 0x10($sp)
/* ECA124 80240424 8C82000C */  lw        $v0, 0xc($a0)
/* ECA128 80240428 0C0B53A3 */  jal       dead_evt_get_variable
/* ECA12C 8024042C 8C450000 */   lw       $a1, ($v0)
/* ECA130 80240430 0C03CB57 */  jal       func_800F2D5C
/* ECA134 80240434 0040202D */   daddu    $a0, $v0, $zero
/* ECA138 80240438 8FBF0010 */  lw        $ra, 0x10($sp)
/* ECA13C 8024043C 24020002 */  addiu     $v0, $zero, 2
/* ECA140 80240440 03E00008 */  jr        $ra
/* ECA144 80240444 27BD0018 */   addiu    $sp, $sp, 0x18

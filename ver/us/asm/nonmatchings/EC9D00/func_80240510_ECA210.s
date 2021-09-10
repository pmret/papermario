.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240510_ECA210
/* ECA210 80240510 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ECA214 80240514 AFBF0010 */  sw        $ra, 0x10($sp)
/* ECA218 80240518 8C82000C */  lw        $v0, 0xc($a0)
/* ECA21C 8024051C 0C0B53A3 */  jal       dead_evt_get_variable
/* ECA220 80240520 8C450000 */   lw       $a1, ($v0)
/* ECA224 80240524 0040202D */  daddu     $a0, $v0, $zero
/* ECA228 80240528 8C830000 */  lw        $v1, ($a0)
/* ECA22C 8024052C 34630010 */  ori       $v1, $v1, 0x10
/* ECA230 80240530 AC830000 */  sw        $v1, ($a0)
/* ECA234 80240534 8FBF0010 */  lw        $ra, 0x10($sp)
/* ECA238 80240538 24020002 */  addiu     $v0, $zero, 2
/* ECA23C 8024053C 03E00008 */  jr        $ra
/* ECA240 80240540 27BD0018 */   addiu    $sp, $sp, 0x18

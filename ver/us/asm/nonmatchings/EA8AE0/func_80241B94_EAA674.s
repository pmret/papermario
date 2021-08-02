.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B94_EAA674
/* EAA674 80241B94 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EAA678 80241B98 AFBF0010 */  sw        $ra, 0x10($sp)
/* EAA67C 80241B9C 0C00F92F */  jal       dead_get_npc_unsafe
/* EAA680 80241BA0 8C84008C */   lw       $a0, 0x8c($a0)
/* EAA684 80241BA4 3C038025 */  lui       $v1, %hi(D_8024854C)
/* EAA688 80241BA8 8C63854C */  lw        $v1, %lo(D_8024854C)($v1)
/* EAA68C 80241BAC AC430028 */  sw        $v1, 0x28($v0)
/* EAA690 80241BB0 8FBF0010 */  lw        $ra, 0x10($sp)
/* EAA694 80241BB4 24020002 */  addiu     $v0, $zero, 2
/* EAA698 80241BB8 03E00008 */  jr        $ra
/* EAA69C 80241BBC 27BD0018 */   addiu    $sp, $sp, 0x18

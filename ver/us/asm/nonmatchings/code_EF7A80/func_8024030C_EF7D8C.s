.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_EF7D8C
/* EF7D8C 8024030C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EF7D90 80240310 24040001 */  addiu     $a0, $zero, 1
/* EF7D94 80240314 0000282D */  daddu     $a1, $zero, $zero
/* EF7D98 80240318 00A0302D */  daddu     $a2, $a1, $zero
/* EF7D9C 8024031C 00A0382D */  daddu     $a3, $a1, $zero
/* EF7DA0 80240320 AFBF0018 */  sw        $ra, 0x18($sp)
/* EF7DA4 80240324 AFA00010 */  sw        $zero, 0x10($sp)
/* EF7DA8 80240328 0C01DEF4 */  jal       func_80077BD0
/* EF7DAC 8024032C AFA00014 */   sw       $zero, 0x14($sp)
/* EF7DB0 80240330 8FBF0018 */  lw        $ra, 0x18($sp)
/* EF7DB4 80240334 24020002 */  addiu     $v0, $zero, 2
/* EF7DB8 80240338 03E00008 */  jr        $ra
/* EF7DBC 8024033C 27BD0020 */   addiu    $sp, $sp, 0x20

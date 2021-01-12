.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_EE68BC
/* EE68BC 8024030C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EE68C0 80240310 0000202D */  daddu     $a0, $zero, $zero
/* EE68C4 80240314 0080282D */  daddu     $a1, $a0, $zero
/* EE68C8 80240318 0080302D */  daddu     $a2, $a0, $zero
/* EE68CC 8024031C 0080382D */  daddu     $a3, $a0, $zero
/* EE68D0 80240320 AFBF0018 */  sw        $ra, 0x18($sp)
/* EE68D4 80240324 AFA00010 */  sw        $zero, 0x10($sp)
/* EE68D8 80240328 0C01DEF4 */  jal       func_80077BD0
/* EE68DC 8024032C AFA00014 */   sw       $zero, 0x14($sp)
/* EE68E0 80240330 8FBF0018 */  lw        $ra, 0x18($sp)
/* EE68E4 80240334 24020002 */  addiu     $v0, $zero, 2
/* EE68E8 80240338 03E00008 */  jr        $ra
/* EE68EC 8024033C 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A50
/* A1BB50 80240A50 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* A1BB54 80240A54 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* A1BB58 80240A58 8442008E */  lh        $v0, 0x8e($v0)
/* A1BB5C 80240A5C AC820084 */  sw        $v0, 0x84($a0)
/* A1BB60 80240A60 03E00008 */  jr        $ra
/* A1BB64 80240A64 24020002 */   addiu    $v0, $zero, 2
/* A1BB68 80240A68 00000000 */  nop       
/* A1BB6C 80240A6C 00000000 */  nop       

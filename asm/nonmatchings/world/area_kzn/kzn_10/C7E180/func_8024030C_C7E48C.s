.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_C7E48C
/* C7E48C 8024030C 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* C7E490 80240310 8C42EFC8 */  lw        $v0, %lo(gPlayerStatus)($v0)
/* C7E494 80240314 3C030400 */  lui       $v1, 0x400
/* C7E498 80240318 00431024 */  and       $v0, $v0, $v1
/* C7E49C 8024031C 2C420001 */  sltiu     $v0, $v0, 1
/* C7E4A0 80240320 03E00008 */  jr        $ra
/* C7E4A4 80240324 00021040 */   sll      $v0, $v0, 1
/* C7E4A8 80240328 00000000 */  nop
/* C7E4AC 8024032C 00000000 */  nop

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D20_D1A500
/* D1A500 80241D20 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* D1A504 80241D24 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* D1A508 80241D28 90420012 */  lbu       $v0, 0x12($v0)
/* D1A50C 80241D2C 000211C2 */  srl       $v0, $v0, 7
/* D1A510 80241D30 03E00008 */  jr        $ra
/* D1A514 80241D34 00021040 */   sll      $v0, $v0, 1
/* D1A518 80241D38 00000000 */  nop       
/* D1A51C 80241D3C 00000000 */  nop       

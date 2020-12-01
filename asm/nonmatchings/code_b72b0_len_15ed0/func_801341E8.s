.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_801341E8
/* CA8E8 801341E8 3C028015 */  lui       $v0, %hi(D_801565A8)
/* CA8EC 801341EC 844265A8 */  lh        $v0, %lo(D_801565A8)($v0)
/* CA8F0 801341F0 3C038015 */  lui       $v1, %hi(D_801565A4)
/* CA8F4 801341F4 846365A4 */  lh        $v1, %lo(D_801565A4)($v1)
/* CA8F8 801341F8 10600002 */  beqz      $v1, .L80134204
/* CA8FC 801341FC 0002102B */   sltu     $v0, $zero, $v0
/* CA900 80134200 24020001 */  addiu     $v0, $zero, 1
.L80134204:
/* CA904 80134204 03E00008 */  jr        $ra
/* CA908 80134208 00000000 */   nop      

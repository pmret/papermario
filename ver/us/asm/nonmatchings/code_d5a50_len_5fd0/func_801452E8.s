.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_801452E8
/* DB9E8 801452E8 3C018015 */  lui       $at, %hi(D_8014EFC0)
/* DB9EC 801452EC AC24EFC0 */  sw        $a0, %lo(D_8014EFC0)($at)
/* DB9F0 801452F0 14800005 */  bnez      $a0, .L80145308
/* DB9F4 801452F4 3C020001 */   lui      $v0, 1
/* DB9F8 801452F8 34421000 */  ori       $v0, $v0, 0x1000
/* DB9FC 801452FC 3C018015 */  lui       $at, %hi(D_8014EFC4)
/* DBA00 80145300 03E00008 */  jr        $ra
/* DBA04 80145304 AC22EFC4 */   sw       $v0, %lo(D_8014EFC4)($at)
.L80145308:
/* DBA08 80145308 3C018015 */  lui       $at, %hi(D_8014EFC4)
/* DBA0C 8014530C 03E00008 */  jr        $ra
/* DBA10 80145310 AC25EFC4 */   sw       $a1, %lo(D_8014EFC4)($at)
/* DBA14 80145314 00000000 */  nop
/* DBA18 80145318 00000000 */  nop
/* DBA1C 8014531C 00000000 */  nop

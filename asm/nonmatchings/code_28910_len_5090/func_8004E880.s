.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8004E880
/* 029C80 8004E880 3C02009F */  lui   $v0, 0x9f
/* 029C84 8004E884 344238DE */  ori   $v0, $v0, 0x38de
/* 029C88 8004E888 14C00002 */  bnez  $a2, .L8004E894
/* 029C8C 8004E88C 0046001B */   divu  $zero, $v0, $a2
/* 029C90 8004E890 0007000D */  break 7
.L8004E894:
/* 029C94 8004E894 00001812 */  mflo  $v1
/* 029C98 8004E898 3C020007 */  lui   $v0, 7
/* 029C9C 8004E89C 3442A120 */  ori   $v0, $v0, 0xa120
/* 029CA0 8004E8A0 0043102B */  sltu  $v0, $v0, $v1
/* 029CA4 8004E8A4 10400004 */  beqz  $v0, .L8004E8B8
/* 029CA8 8004E8A8 3C020001 */   lui   $v0, 1
/* 029CAC 8004E8AC 3C030007 */  lui   $v1, 7
/* 029CB0 8004E8B0 08013A34 */  j     .L8004E8D0
/* 029CB4 8004E8B4 3463A120 */   ori   $v1, $v1, 0xa120

.L8004E8B8:
/* 029CB8 8004E8B8 3442387F */  ori   $v0, $v0, 0x387f
/* 029CBC 8004E8BC 0043102B */  sltu  $v0, $v0, $v1
/* 029CC0 8004E8C0 14400004 */  bnez  $v0, .L8004E8D4
/* 029CC4 8004E8C4 0065102B */   sltu  $v0, $v1, $a1
/* 029CC8 8004E8C8 3C030001 */  lui   $v1, 1
/* 029CCC 8004E8CC 34633880 */  ori   $v1, $v1, 0x3880
.L8004E8D0:
/* 029CD0 8004E8D0 0065102B */  sltu  $v0, $v1, $a1
.L8004E8D4:
/* 029CD4 8004E8D4 54400001 */  bnel  $v0, $zero, .L8004E8DC
/* 029CD8 8004E8D8 0060282D */   daddu $a1, $v1, $zero
.L8004E8DC:
/* 029CDC 8004E8DC 3C021062 */  lui   $v0, 0x1062
/* 029CE0 8004E8E0 34424DD3 */  ori   $v0, $v0, 0x4dd3
/* 029CE4 8004E8E4 00620019 */  multu $v1, $v0
/* 029CE8 8004E8E8 AC850008 */  sw    $a1, 8($a0)
/* 029CEC 8004E8EC AC83000C */  sw    $v1, 0xc($a0)
/* 029CF0 8004E8F0 AC830010 */  sw    $v1, 0x10($a0)
/* 029CF4 8004E8F4 00003810 */  mfhi  $a3
/* 029CF8 8004E8F8 00071182 */  srl   $v0, $a3, 6
/* 029CFC 8004E8FC 03E00008 */  jr    $ra
/* 029D00 8004E900 A482020A */   sh    $v0, 0x20a($a0)


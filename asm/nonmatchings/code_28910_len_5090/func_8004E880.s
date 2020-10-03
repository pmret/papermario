.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004E880
/* 29C80 8004E880 3C02009F */  lui       $v0, 0x9f
/* 29C84 8004E884 344238DE */  ori       $v0, $v0, 0x38de
/* 29C88 8004E888 14C00002 */  bnez      $a2, .L8004E894
/* 29C8C 8004E88C 0046001B */   divu     $zero, $v0, $a2
/* 29C90 8004E890 0007000D */  break     7
.L8004E894:
/* 29C94 8004E894 00001812 */   mflo     $v1
/* 29C98 8004E898 3C020007 */  lui       $v0, 7
/* 29C9C 8004E89C 3442A120 */  ori       $v0, $v0, 0xa120
/* 29CA0 8004E8A0 0043102B */  sltu      $v0, $v0, $v1
/* 29CA4 8004E8A4 10400004 */  beqz      $v0, .L8004E8B8
/* 29CA8 8004E8A8 3C020001 */   lui      $v0, 1
/* 29CAC 8004E8AC 3C030007 */  lui       $v1, 7
/* 29CB0 8004E8B0 08013A34 */  j         .L8004E8D0
/* 29CB4 8004E8B4 3463A120 */   ori      $v1, $v1, 0xa120
.L8004E8B8:
/* 29CB8 8004E8B8 3442387F */  ori       $v0, $v0, 0x387f
/* 29CBC 8004E8BC 0043102B */  sltu      $v0, $v0, $v1
/* 29CC0 8004E8C0 14400004 */  bnez      $v0, .L8004E8D4
/* 29CC4 8004E8C4 0065102B */   sltu     $v0, $v1, $a1
/* 29CC8 8004E8C8 3C030001 */  lui       $v1, 1
/* 29CCC 8004E8CC 34633880 */  ori       $v1, $v1, 0x3880
.L8004E8D0:
/* 29CD0 8004E8D0 0065102B */  sltu      $v0, $v1, $a1
.L8004E8D4:
/* 29CD4 8004E8D4 54400001 */  bnel      $v0, $zero, .L8004E8DC
/* 29CD8 8004E8D8 0060282D */   daddu    $a1, $v1, $zero
.L8004E8DC:
/* 29CDC 8004E8DC 3C021062 */  lui       $v0, 0x1062
/* 29CE0 8004E8E0 34424DD3 */  ori       $v0, $v0, 0x4dd3
/* 29CE4 8004E8E4 00620019 */  multu     $v1, $v0
/* 29CE8 8004E8E8 AC850008 */  sw        $a1, 8($a0)
/* 29CEC 8004E8EC AC83000C */  sw        $v1, 0xc($a0)
/* 29CF0 8004E8F0 AC830010 */  sw        $v1, 0x10($a0)
/* 29CF4 8004E8F4 00003810 */  mfhi      $a3
/* 29CF8 8004E8F8 00071182 */  srl       $v0, $a3, 6
/* 29CFC 8004E8FC 03E00008 */  jr        $ra
/* 29D00 8004E900 A482020A */   sh       $v0, 0x20a($a0)

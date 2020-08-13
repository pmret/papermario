.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80050970
/* 02BD70 80050970 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 02BD74 80050974 AFBF003C */  sw    $ra, 0x3c($sp)
/* 02BD78 80050978 AFBE0038 */  sw    $fp, 0x38($sp)
/* 02BD7C 8005097C AFB70034 */  sw    $s7, 0x34($sp)
/* 02BD80 80050980 AFB60030 */  sw    $s6, 0x30($sp)
/* 02BD84 80050984 AFB5002C */  sw    $s5, 0x2c($sp)
/* 02BD88 80050988 AFB40028 */  sw    $s4, 0x28($sp)
/* 02BD8C 8005098C AFB30024 */  sw    $s3, 0x24($sp)
/* 02BD90 80050990 AFB20020 */  sw    $s2, 0x20($sp)
/* 02BD94 80050994 AFB1001C */  sw    $s1, 0x1c($sp)
/* 02BD98 80050998 AFB00018 */  sw    $s0, 0x18($sp)
/* 02BD9C 8005099C 8C820000 */  lw    $v0, ($a0)
/* 02BDA0 800509A0 8C840010 */  lw    $a0, 0x10($a0)
/* 02BDA4 800509A4 0000B82D */  daddu $s7, $zero, $zero
/* 02BDA8 800509A8 1040006A */  beqz  $v0, .L80050B54
/* 02BDAC 800509AC AFA40010 */   sw    $a0, 0x10($sp)
/* 02BDB0 800509B0 0C0135E5 */  jal   func_8004D794
/* 02BDB4 800509B4 0040202D */   daddu $a0, $v0, $zero
/* 02BDB8 800509B8 0040882D */  daddu $s1, $v0, $zero
/* 02BDBC 800509BC 12200063 */  beqz  $s1, .L80050B4C
/* 02BDC0 800509C0 02E0A82D */   daddu $s5, $s7, $zero
/* 02BDC4 800509C4 241E0001 */  addiu $fp, $zero, 1
/* 02BDC8 800509C8 3C168008 */  lui   $s6, 0x8008
/* 02BDCC 800509CC 26D68554 */  addiu $s6, $s6, -0x7aac
/* 02BDD0 800509D0 2414025C */  addiu $s4, $zero, 0x25c
.L800509D4:
/* 02BDD4 800509D4 02349021 */  addu  $s2, $s1, $s4
/* 02BDD8 800509D8 8E420000 */  lw    $v0, ($s2)
/* 02BDDC 800509DC 50400056 */  beql  $v0, $zero, .L80050B38
/* 02BDE0 800509E0 26B50001 */   addiu $s5, $s5, 1
/* 02BDE4 800509E4 92420059 */  lbu   $v0, 0x59($s2)
/* 02BDE8 800509E8 10400052 */  beqz  $v0, .L80050B34
/* 02BDEC 800509EC 0040182D */   daddu $v1, $v0, $zero
/* 02BDF0 800509F0 00031040 */  sll   $v0, $v1, 1
/* 02BDF4 800509F4 00431021 */  addu  $v0, $v0, $v1
/* 02BDF8 800509F8 00021140 */  sll   $v0, $v0, 5
/* 02BDFC 800509FC 244201FC */  addiu $v0, $v0, 0x1fc
/* 02BE00 80050A00 8FA70010 */  lw    $a3, 0x10($sp)
/* 02BE04 80050A04 10E00024 */  beqz  $a3, .L80050A98
/* 02BE08 80050A08 02229821 */   addu  $s3, $s1, $v0
/* 02BE0C 80050A0C 9242005A */  lbu   $v0, 0x5a($s2)
/* 02BE10 80050A10 50400049 */  beql  $v0, $zero, .L80050B38
/* 02BE14 80050A14 26B50001 */   addiu $s5, $s5, 1
/* 02BE18 80050A18 A240005A */  sb    $zero, 0x5a($s2)
/* 02BE1C 80050A1C 92650052 */  lbu   $a1, 0x52($s3)
/* 02BE20 80050A20 92620053 */  lbu   $v0, 0x53($s3)
/* 02BE24 80050A24 00A2102A */  slt   $v0, $a1, $v0
/* 02BE28 80050A28 10400014 */  beqz  $v0, .L80050A7C
/* 02BE2C 80050A2C A27E005A */   sb    $fp, 0x5a($s3)
/* 02BE30 80050A30 000510C0 */  sll   $v0, $a1, 3
/* 02BE34 80050A34 00451021 */  addu  $v0, $v0, $a1
/* 02BE38 80050A38 000210C0 */  sll   $v0, $v0, 3
/* 02BE3C 80050A3C 24461320 */  addiu $a2, $v0, 0x1320
.L80050A40:
/* 02BE40 80050A40 8E220000 */  lw    $v0, ($s1)
/* 02BE44 80050A44 00462021 */  addu  $a0, $v0, $a2
/* 02BE48 80050A48 90830045 */  lbu   $v1, 0x45($a0)
/* 02BE4C 80050A4C 92220234 */  lbu   $v0, 0x234($s1)
/* 02BE50 80050A50 14620005 */  bne   $v1, $v0, .L80050A68
/* 02BE54 80050A54 00000000 */   nop   
/* 02BE58 80050A58 9082003D */  lbu   $v0, 0x3d($a0)
/* 02BE5C 80050A5C AC960018 */  sw    $s6, 0x18($a0)
/* 02BE60 80050A60 34420010 */  ori   $v0, $v0, 0x10
/* 02BE64 80050A64 A082003D */  sb    $v0, 0x3d($a0)
.L80050A68:
/* 02BE68 80050A68 92620053 */  lbu   $v0, 0x53($s3)
/* 02BE6C 80050A6C 24A50001 */  addiu $a1, $a1, 1
/* 02BE70 80050A70 00A2102A */  slt   $v0, $a1, $v0
/* 02BE74 80050A74 1440FFF2 */  bnez  $v0, .L80050A40
/* 02BE78 80050A78 24C60048 */   addiu $a2, $a2, 0x48
.L80050A7C:
/* 02BE7C 80050A7C 0220202D */  daddu $a0, $s1, $zero
/* 02BE80 80050A80 82500018 */  lb    $s0, 0x18($s2)
/* 02BE84 80050A84 0C013FAC */  jal   func_8004FEB0
/* 02BE88 80050A88 0240282D */   daddu $a1, $s2, $zero
/* 02BE8C 80050A8C 0220202D */  daddu $a0, $s1, $zero
/* 02BE90 80050A90 080142C8 */  j     .L80050B20
/* 02BE94 80050A94 0240282D */   daddu $a1, $s2, $zero

.L80050A98:
/* 02BE98 80050A98 9242005A */  lbu   $v0, 0x5a($s2)
/* 02BE9C 80050A9C 54400026 */  bnel  $v0, $zero, .L80050B38
/* 02BEA0 80050AA0 26B50001 */   addiu $s5, $s5, 1
/* 02BEA4 80050AA4 A25E005A */  sb    $fp, 0x5a($s2)
/* 02BEA8 80050AA8 A260005A */  sb    $zero, 0x5a($s3)
/* 02BEAC 80050AAC 92450052 */  lbu   $a1, 0x52($s2)
/* 02BEB0 80050AB0 92420053 */  lbu   $v0, 0x53($s2)
/* 02BEB4 80050AB4 00A2102A */  slt   $v0, $a1, $v0
/* 02BEB8 80050AB8 10400013 */  beqz  $v0, .L80050B08
/* 02BEBC 80050ABC 000510C0 */   sll   $v0, $a1, 3
/* 02BEC0 80050AC0 00451021 */  addu  $v0, $v0, $a1
/* 02BEC4 80050AC4 000210C0 */  sll   $v0, $v0, 3
/* 02BEC8 80050AC8 24461320 */  addiu $a2, $v0, 0x1320
.L80050ACC:
/* 02BECC 80050ACC 8E220000 */  lw    $v0, ($s1)
/* 02BED0 80050AD0 00462021 */  addu  $a0, $v0, $a2
/* 02BED4 80050AD4 90830045 */  lbu   $v1, 0x45($a0)
/* 02BED8 80050AD8 92220234 */  lbu   $v0, 0x234($s1)
/* 02BEDC 80050ADC 14620005 */  bne   $v1, $v0, .L80050AF4
/* 02BEE0 80050AE0 00000000 */   nop   
/* 02BEE4 80050AE4 9082003D */  lbu   $v0, 0x3d($a0)
/* 02BEE8 80050AE8 AC960018 */  sw    $s6, 0x18($a0)
/* 02BEEC 80050AEC 34420010 */  ori   $v0, $v0, 0x10
/* 02BEF0 80050AF0 A082003D */  sb    $v0, 0x3d($a0)
.L80050AF4:
/* 02BEF4 80050AF4 92420053 */  lbu   $v0, 0x53($s2)
/* 02BEF8 80050AF8 24A50001 */  addiu $a1, $a1, 1
/* 02BEFC 80050AFC 00A2102A */  slt   $v0, $a1, $v0
/* 02BF00 80050B00 1440FFF2 */  bnez  $v0, .L80050ACC
/* 02BF04 80050B04 24C60048 */   addiu $a2, $a2, 0x48
.L80050B08:
/* 02BF08 80050B08 0220202D */  daddu $a0, $s1, $zero
/* 02BF0C 80050B0C 82700018 */  lb    $s0, 0x18($s3)
/* 02BF10 80050B10 0C013FAC */  jal   func_8004FEB0
/* 02BF14 80050B14 0260282D */   daddu $a1, $s3, $zero
/* 02BF18 80050B18 0220202D */  daddu $a0, $s1, $zero
/* 02BF1C 80050B1C 0260282D */  daddu $a1, $s3, $zero
.L80050B20:
/* 02BF20 80050B20 24020060 */  addiu $v0, $zero, 0x60
/* 02BF24 80050B24 A22000D4 */  sb    $zero, 0xd4($s1)
/* 02BF28 80050B28 A62200D4 */  sh    $v0, 0xd4($s1)
/* 02BF2C 80050B2C 0C013FB4 */  jal   func_8004FED0
/* 02BF30 80050B30 A23000D6 */   sb    $s0, 0xd6($s1)
.L80050B34:
/* 02BF34 80050B34 26B50001 */  addiu $s5, $s5, 1
.L80050B38:
/* 02BF38 80050B38 2AA20010 */  slti  $v0, $s5, 0x10
/* 02BF3C 80050B3C 1440FFA5 */  bnez  $v0, .L800509D4
/* 02BF40 80050B40 26940060 */   addiu $s4, $s4, 0x60
/* 02BF44 80050B44 080142D7 */  j     .L80050B5C
/* 02BF48 80050B48 02E0102D */   daddu $v0, $s7, $zero

.L80050B4C:
/* 02BF4C 80050B4C 080142D6 */  j     .L80050B58
/* 02BF50 80050B50 24170002 */   addiu $s7, $zero, 2

.L80050B54:
/* 02BF54 80050B54 24170003 */  addiu $s7, $zero, 3
.L80050B58:
/* 02BF58 80050B58 02E0102D */  daddu $v0, $s7, $zero
.L80050B5C:
/* 02BF5C 80050B5C 8FBF003C */  lw    $ra, 0x3c($sp)
/* 02BF60 80050B60 8FBE0038 */  lw    $fp, 0x38($sp)
/* 02BF64 80050B64 8FB70034 */  lw    $s7, 0x34($sp)
/* 02BF68 80050B68 8FB60030 */  lw    $s6, 0x30($sp)
/* 02BF6C 80050B6C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 02BF70 80050B70 8FB40028 */  lw    $s4, 0x28($sp)
/* 02BF74 80050B74 8FB30024 */  lw    $s3, 0x24($sp)
/* 02BF78 80050B78 8FB20020 */  lw    $s2, 0x20($sp)
/* 02BF7C 80050B7C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 02BF80 80050B80 8FB00018 */  lw    $s0, 0x18($sp)
/* 02BF84 80050B84 03E00008 */  jr    $ra
/* 02BF88 80050B88 27BD0040 */   addiu $sp, $sp, 0x40

/* 02BF8C 80050B8C 00000000 */  nop   

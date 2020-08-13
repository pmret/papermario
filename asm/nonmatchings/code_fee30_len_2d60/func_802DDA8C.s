.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802DDA8C
/* 100B7C 802DDA8C 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 100B80 802DDA90 AFB70034 */  sw    $s7, 0x34($sp)
/* 100B84 802DDA94 0080B82D */  daddu $s7, $a0, $zero
/* 100B88 802DDA98 AFB5002C */  sw    $s5, 0x2c($sp)
/* 100B8C 802DDA9C 00A0A82D */  daddu $s5, $a1, $zero
/* 100B90 802DDAA0 00151403 */  sra   $v0, $s5, 0x10
/* 100B94 802DDAA4 304200FF */  andi  $v0, $v0, 0xff
/* 100B98 802DDAA8 AFB40028 */  sw    $s4, 0x28($sp)
/* 100B9C 802DDAAC 2454FFFF */  addiu $s4, $v0, -1
/* 100BA0 802DDAB0 AFB20020 */  sw    $s2, 0x20($sp)
/* 100BA4 802DDAB4 32F200FF */  andi  $s2, $s7, 0xff
/* 100BA8 802DDAB8 3C03802E */  lui   $v1, 0x802e
/* 100BAC 802DDABC 2463F588 */  addiu $v1, $v1, -0xa78
/* 100BB0 802DDAC0 00121040 */  sll   $v0, $s2, 1
/* 100BB4 802DDAC4 00521021 */  addu  $v0, $v0, $s2
/* 100BB8 802DDAC8 F7B40040 */  sdc1  $f20, 0x40($sp)
/* 100BBC 802DDACC 4486A000 */  mtc1  $a2, $f20
/* 100BC0 802DDAD0 00021080 */  sll   $v0, $v0, 2
/* 100BC4 802DDAD4 AFB00018 */  sw    $s0, 0x18($sp)
/* 100BC8 802DDAD8 00438021 */  addu  $s0, $v0, $v1
/* 100BCC 802DDADC AFBF0038 */  sw    $ra, 0x38($sp)
/* 100BD0 802DDAE0 AFB60030 */  sw    $s6, 0x30($sp)
/* 100BD4 802DDAE4 AFB30024 */  sw    $s3, 0x24($sp)
/* 100BD8 802DDAE8 AFB1001C */  sw    $s1, 0x1c($sp)
/* 100BDC 802DDAEC 8E020000 */  lw    $v0, ($s0)
/* 100BE0 802DDAF0 3C01802E */  lui   $at, 0x802e
/* 100BE4 802DDAF4 AC34F57C */  sw    $s4, -0xa84($at)
/* 100BE8 802DDAF8 14400013 */  bnez  $v0, .L802DDB48
/* 100BEC 802DDAFC 32B600FF */   andi  $s6, $s5, 0xff
/* 100BF0 802DDB00 3C04802E */  lui   $a0, 0x802e
/* 100BF4 802DDB04 8C84F580 */  lw    $a0, -0xa80($a0)
/* 100BF8 802DDB08 0C0B7CB6 */  jal   func_802DF2D8
/* 100BFC 802DDB0C 00000000 */   nop   
/* 100C00 802DDB10 0040882D */  daddu $s1, $v0, $zero
/* 100C04 802DDB14 AE110000 */  sw    $s1, ($s0)
/* 100C08 802DDB18 8E230000 */  lw    $v1, ($s1)
/* 100C0C 802DDB1C 2402FFFF */  addiu $v0, $zero, -1
/* 100C10 802DDB20 10620009 */  beq   $v1, $v0, .L802DDB48
/* 100C14 802DDB24 0040982D */   daddu $s3, $v0, $zero
.L802DDB28:
/* 100C18 802DDB28 8E300000 */  lw    $s0, ($s1)
/* 100C1C 802DDB2C 0C04E9C1 */  jal   func_8013A704
/* 100C20 802DDB30 24040001 */   addiu $a0, $zero, 1
/* 100C24 802DDB34 26310004 */  addiu $s1, $s1, 4
/* 100C28 802DDB38 AE02004C */  sw    $v0, 0x4c($s0)
/* 100C2C 802DDB3C 8E220000 */  lw    $v0, ($s1)
/* 100C30 802DDB40 1453FFF9 */  bne   $v0, $s3, .L802DDB28
/* 100C34 802DDB44 00000000 */   nop   
.L802DDB48:
/* 100C38 802DDB48 00141080 */  sll   $v0, $s4, 2
/* 100C3C 802DDB4C 3C03802E */  lui   $v1, 0x802e
/* 100C40 802DDB50 2463F588 */  addiu $v1, $v1, -0xa78
/* 100C44 802DDB54 3C05802E */  lui   $a1, 0x802e
/* 100C48 802DDB58 00A22821 */  addu  $a1, $a1, $v0
/* 100C4C 802DDB5C 8CA5F548 */  lw    $a1, -0xab8($a1)
/* 100C50 802DDB60 00121040 */  sll   $v0, $s2, 1
/* 100C54 802DDB64 00521021 */  addu  $v0, $v0, $s2
/* 100C58 802DDB68 00021080 */  sll   $v0, $v0, 2
/* 100C5C 802DDB6C 00438021 */  addu  $s0, $v0, $v1
/* 100C60 802DDB70 8E110000 */  lw    $s1, ($s0)
/* 100C64 802DDB74 10A00026 */  beqz  $a1, .L802DDC10
/* 100C68 802DDB78 0000102D */   daddu $v0, $zero, $zero
/* 100C6C 802DDB7C 00161080 */  sll   $v0, $s6, 2
/* 100C70 802DDB80 24420010 */  addiu $v0, $v0, 0x10
/* 100C74 802DDB84 8CB40000 */  lw    $s4, ($a1)
/* 100C78 802DDB88 00A22821 */  addu  $a1, $a1, $v0
/* 100C7C 802DDB8C 8CB30000 */  lw    $s3, ($a1)
/* 100C80 802DDB90 0C0B7623 */  jal   func_802DD88C
/* 100C84 802DDB94 4600A306 */   mov.s $f12, $f20
/* 100C88 802DDB98 06E00007 */  bltz  $s7, .L802DDBB8
/* 100C8C 802DDB9C 3C02FEFF */   lui   $v0, 0xfeff
/* 100C90 802DDBA0 3442FFFF */  ori   $v0, $v0, 0xffff
/* 100C94 802DDBA4 8E030004 */  lw    $v1, 4($s0)
/* 100C98 802DDBA8 02A22024 */  and   $a0, $s5, $v0
/* 100C9C 802DDBAC 00621824 */  and   $v1, $v1, $v0
/* 100CA0 802DDBB0 10830005 */  beq   $a0, $v1, .L802DDBC8
/* 100CA4 802DDBB4 00000000 */   nop   
.L802DDBB8:
/* 100CA8 802DDBB8 0220202D */  daddu $a0, $s1, $zero
/* 100CAC 802DDBBC 0C0B7608 */  jal   func_802DD820
/* 100CB0 802DDBC0 0260282D */   daddu $a1, $s3, $zero
/* 100CB4 802DDBC4 AE000008 */  sw    $zero, 8($s0)
.L802DDBC8:
/* 100CB8 802DDBC8 3C02802E */  lui   $v0, 0x802e
/* 100CBC 802DDBCC 2442F588 */  addiu $v0, $v0, -0xa78
/* 100CC0 802DDBD0 00121840 */  sll   $v1, $s2, 1
/* 100CC4 802DDBD4 00721821 */  addu  $v1, $v1, $s2
/* 100CC8 802DDBD8 00031880 */  sll   $v1, $v1, 2
/* 100CCC 802DDBDC 00628021 */  addu  $s0, $v1, $v0
/* 100CD0 802DDBE0 3C024000 */  lui   $v0, 0x4000
/* 100CD4 802DDBE4 02E21024 */  and   $v0, $s7, $v0
/* 100CD8 802DDBE8 14400008 */  bnez  $v0, .L802DDC0C
/* 100CDC 802DDBEC AE150004 */   sw    $s5, 4($s0)
/* 100CE0 802DDBF0 0220282D */  daddu $a1, $s1, $zero
/* 100CE4 802DDBF4 0260302D */  daddu $a2, $s3, $zero
/* 100CE8 802DDBF8 AFA00010 */  sw    $zero, 0x10($sp)
/* 100CEC 802DDBFC 8E040008 */  lw    $a0, 8($s0)
/* 100CF0 802DDC00 0C0B75B7 */  jal   func_802DD6DC
/* 100CF4 802DDC04 0280382D */   daddu $a3, $s4, $zero
/* 100CF8 802DDC08 AE020008 */  sw    $v0, 8($s0)
.L802DDC0C:
/* 100CFC 802DDC0C 8E020008 */  lw    $v0, 8($s0)
.L802DDC10:
/* 100D00 802DDC10 8FBF0038 */  lw    $ra, 0x38($sp)
/* 100D04 802DDC14 8FB70034 */  lw    $s7, 0x34($sp)
/* 100D08 802DDC18 8FB60030 */  lw    $s6, 0x30($sp)
/* 100D0C 802DDC1C 8FB5002C */  lw    $s5, 0x2c($sp)
/* 100D10 802DDC20 8FB40028 */  lw    $s4, 0x28($sp)
/* 100D14 802DDC24 8FB30024 */  lw    $s3, 0x24($sp)
/* 100D18 802DDC28 8FB20020 */  lw    $s2, 0x20($sp)
/* 100D1C 802DDC2C 8FB1001C */  lw    $s1, 0x1c($sp)
/* 100D20 802DDC30 8FB00018 */  lw    $s0, 0x18($sp)
/* 100D24 802DDC34 D7B40040 */  ldc1  $f20, 0x40($sp)
/* 100D28 802DDC38 03E00008 */  jr    $ra
/* 100D2C 802DDC3C 27BD0048 */   addiu $sp, $sp, 0x48


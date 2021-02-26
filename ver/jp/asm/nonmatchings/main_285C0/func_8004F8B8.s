.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004F8B8
/* 2ACB8 8004F8B8 44852000 */  mtc1      $a1, $f4
/* 2ACBC 8004F8BC 00000000 */  nop
/* 2ACC0 8004F8C0 46802121 */  cvt.d.w   $f4, $f4
/* 2ACC4 8004F8C4 04A10006 */  bgez      $a1, .L8004F8E0
/* 2ACC8 8004F8C8 9483020A */   lhu      $v1, 0x20a($a0)
/* 2ACCC 8004F8CC 3C0141F0 */  lui       $at, 0x41f0
/* 2ACD0 8004F8D0 44810800 */  mtc1      $at, $f1
/* 2ACD4 8004F8D4 44800000 */  mtc1      $zero, $f0
/* 2ACD8 8004F8D8 00000000 */  nop
/* 2ACDC 8004F8DC 46202100 */  add.d     $f4, $f4, $f0
.L8004F8E0:
/* 2ACE0 8004F8E0 C48200D0 */  lwc1      $f2, 0xd0($a0)
/* 2ACE4 8004F8E4 46202020 */  cvt.s.d   $f0, $f4
/* 2ACE8 8004F8E8 46020002 */  mul.s     $f0, $f0, $f2
/* 2ACEC 8004F8EC 00000000 */  nop
/* 2ACF0 8004F8F0 3C014F00 */  lui       $at, 0x4f00
/* 2ACF4 8004F8F4 44811000 */  mtc1      $at, $f2
/* 2ACF8 8004F8F8 00000000 */  nop
/* 2ACFC 8004F8FC 4600103E */  c.le.s    $f2, $f0
/* 2AD00 8004F900 00000000 */  nop
/* 2AD04 8004F904 45030005 */  bc1tl     .L8004F91C
/* 2AD08 8004F908 46020001 */   sub.s    $f0, $f0, $f2
/* 2AD0C 8004F90C 4600018D */  trunc.w.s $f6, $f0
/* 2AD10 8004F910 44053000 */  mfc1      $a1, $f6
/* 2AD14 8004F914 08013E4D */  j         .L8004F934
/* 2AD18 8004F918 0065102B */   sltu     $v0, $v1, $a1
.L8004F91C:
/* 2AD1C 8004F91C 3C028000 */  lui       $v0, 0x8000
/* 2AD20 8004F920 4600018D */  trunc.w.s $f6, $f0
/* 2AD24 8004F924 44053000 */  mfc1      $a1, $f6
/* 2AD28 8004F928 00000000 */  nop
/* 2AD2C 8004F92C 00A22825 */  or        $a1, $a1, $v0
/* 2AD30 8004F930 0065102B */  sltu      $v0, $v1, $a1
.L8004F934:
/* 2AD34 8004F934 10400003 */  beqz      $v0, .L8004F944
/* 2AD38 8004F938 00000000 */   nop
/* 2AD3C 8004F93C 08013E53 */  j         .L8004F94C
/* 2AD40 8004F940 0060282D */   daddu    $a1, $v1, $zero
.L8004F944:
/* 2AD44 8004F944 50A00001 */  beql      $a1, $zero, .L8004F94C
/* 2AD48 8004F948 24050001 */   addiu    $a1, $zero, 1
.L8004F94C:
/* 2AD4C 8004F94C 00051040 */  sll       $v0, $a1, 1
/* 2AD50 8004F950 00451021 */  addu      $v0, $v0, $a1
/* 2AD54 8004F954 000210C0 */  sll       $v0, $v0, 3
/* 2AD58 8004F958 00451021 */  addu      $v0, $v0, $a1
/* 2AD5C 8004F95C 03E00008 */  jr        $ra
/* 2AD60 8004F960 00021080 */   sll      $v0, $v0, 2

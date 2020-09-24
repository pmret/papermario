.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FC08
/* 2B008 8004FC08 44852000 */  mtc1      $a1, $f4
/* 2B00C 8004FC0C 00000000 */  nop       
/* 2B010 8004FC10 46802121 */  cvt.d.w   $f4, $f4
/* 2B014 8004FC14 04A10006 */  bgez      $a1, .L8004FC30
/* 2B018 8004FC18 9483020A */   lhu      $v1, 0x20a($a0)
/* 2B01C 8004FC1C 3C0141F0 */  lui       $at, 0x41f0
/* 2B020 8004FC20 44810800 */  mtc1      $at, $f1
/* 2B024 8004FC24 44800000 */  mtc1      $zero, $f0
/* 2B028 8004FC28 00000000 */  nop       
/* 2B02C 8004FC2C 46202100 */  add.d     $f4, $f4, $f0
.L8004FC30:
/* 2B030 8004FC30 C48200D0 */  lwc1      $f2, 0xd0($a0)
/* 2B034 8004FC34 46202020 */  cvt.s.d   $f0, $f4
/* 2B038 8004FC38 46020002 */  mul.s     $f0, $f0, $f2
/* 2B03C 8004FC3C 00000000 */  nop       
/* 2B040 8004FC40 3C014F00 */  lui       $at, 0x4f00
/* 2B044 8004FC44 44811000 */  mtc1      $at, $f2
/* 2B048 8004FC48 00000000 */  nop       
/* 2B04C 8004FC4C 4600103E */  c.le.s    $f2, $f0
/* 2B050 8004FC50 00000000 */  nop       
/* 2B054 8004FC54 45030005 */  bc1tl     .L8004FC6C
/* 2B058 8004FC58 46020001 */   sub.s    $f0, $f0, $f2
/* 2B05C 8004FC5C 4600018D */  trunc.w.s $f6, $f0
/* 2B060 8004FC60 44053000 */  mfc1      $a1, $f6
/* 2B064 8004FC64 08013F21 */  j         .L8004FC84
/* 2B068 8004FC68 0065102B */   sltu     $v0, $v1, $a1
.L8004FC6C:
/* 2B06C 8004FC6C 3C028000 */  lui       $v0, 0x8000
/* 2B070 8004FC70 4600018D */  trunc.w.s $f6, $f0
/* 2B074 8004FC74 44053000 */  mfc1      $a1, $f6
/* 2B078 8004FC78 00000000 */  nop       
/* 2B07C 8004FC7C 00A22825 */  or        $a1, $a1, $v0
/* 2B080 8004FC80 0065102B */  sltu      $v0, $v1, $a1
.L8004FC84:
/* 2B084 8004FC84 10400003 */  beqz      $v0, .L8004FC94
/* 2B088 8004FC88 00000000 */   nop      
/* 2B08C 8004FC8C 08013F27 */  j         .L8004FC9C
/* 2B090 8004FC90 0060282D */   daddu    $a1, $v1, $zero
.L8004FC94:
/* 2B094 8004FC94 50A00001 */  beql      $a1, $zero, .L8004FC9C
/* 2B098 8004FC98 24050001 */   addiu    $a1, $zero, 1
.L8004FC9C:
/* 2B09C 8004FC9C 00051040 */  sll       $v0, $a1, 1
/* 2B0A0 8004FCA0 00451021 */  addu      $v0, $v0, $a1
/* 2B0A4 8004FCA4 000210C0 */  sll       $v0, $v0, 3
/* 2B0A8 8004FCA8 00451021 */  addu      $v0, $v0, $a1
/* 2B0AC 8004FCAC 03E00008 */  jr        $ra
/* 2B0B0 8004FCB0 00021080 */   sll      $v0, $v0, 2

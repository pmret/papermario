.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004D794
/* 28B94 8004D794 3C05800A */  lui       $a1, 0x800a
/* 28B98 8004D798 8CA5A664 */  lw        $a1, -0x599c($a1)
/* 28B9C 8004D79C 8CA30000 */  lw        $v1, ($a1)
/* 28BA0 8004D7A0 8C62005C */  lw        $v0, 0x5c($v1)
/* 28BA4 8004D7A4 8C420008 */  lw        $v0, 8($v0)
/* 28BA8 8004D7A8 10820009 */  beq       $a0, $v0, .L8004D7D0
/* 28BAC 8004D7AC 00000000 */   nop      
/* 28BB0 8004D7B0 8C620060 */  lw        $v0, 0x60($v1)
/* 28BB4 8004D7B4 8C420008 */  lw        $v0, 8($v0)
/* 28BB8 8004D7B8 14820007 */  bne       $a0, $v0, .L8004D7D8
/* 28BBC 8004D7BC 00000000 */   nop      
/* 28BC0 8004D7C0 3C02800A */  lui       $v0, 0x800a
/* 28BC4 8004D7C4 8C42A5FC */  lw        $v0, -0x5a04($v0)
/* 28BC8 8004D7C8 03E00008 */  jr        $ra
/* 28BCC 8004D7CC 00000000 */   nop      
.L8004D7D0:
/* 28BD0 8004D7D0 03E00008 */  jr        $ra
/* 28BD4 8004D7D4 00A0102D */   daddu    $v0, $a1, $zero
.L8004D7D8:
/* 28BD8 8004D7D8 03E00008 */  jr        $ra
/* 28BDC 8004D7DC 0000102D */   daddu    $v0, $zero, $zero

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054DA8
/* 301A8 80054DA8 30840001 */  andi      $a0, $a0, 1
/* 301AC 80054DAC 24050001 */  addiu     $a1, $zero, 1
/* 301B0 80054DB0 14850008 */  bne       $a0, $a1, .L80054DD4
/* 301B4 80054DB4 00000000 */   nop      
/* 301B8 80054DB8 3C03800A */  lui       $v1, %hi(D_8009A5C0)
/* 301BC 80054DBC 8C63A5C0 */  lw        $v1, %lo(D_8009A5C0)($v1)
/* 301C0 80054DC0 9062130C */  lbu       $v0, 0x130c($v1)
/* 301C4 80054DC4 1440000C */  bnez      $v0, .L80054DF8
/* 301C8 80054DC8 24020002 */   addiu    $v0, $zero, 2
/* 301CC 80054DCC 03E00008 */  jr        $ra
/* 301D0 80054DD0 A062130C */   sb       $v0, 0x130c($v1)
.L80054DD4:
/* 301D4 80054DD4 3C04800A */  lui       $a0, %hi(D_8009A5C0)
/* 301D8 80054DD8 2484A5C0 */  addiu     $a0, $a0, %lo(D_8009A5C0)
/* 301DC 80054DDC 8C830000 */  lw        $v1, ($a0)
/* 301E0 80054DE0 9062130C */  lbu       $v0, 0x130c($v1)
/* 301E4 80054DE4 10400004 */  beqz      $v0, .L80054DF8
/* 301E8 80054DE8 00000000 */   nop      
/* 301EC 80054DEC A0650050 */  sb        $a1, 0x50($v1)
/* 301F0 80054DF0 8C820000 */  lw        $v0, ($a0)
/* 301F4 80054DF4 A040130C */  sb        $zero, 0x130c($v0)
.L80054DF8:
/* 301F8 80054DF8 03E00008 */  jr        $ra
/* 301FC 80054DFC 00000000 */   nop      

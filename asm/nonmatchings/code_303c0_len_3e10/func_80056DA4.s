.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056DA4
/* 321A4 80056DA4 308400FF */  andi      $a0, $a0, 0xff
/* 321A8 80056DA8 00041840 */  sll       $v1, $a0, 1
/* 321AC 80056DAC 3C028008 */  lui       $v0, 0x8008
/* 321B0 80056DB0 8C428E54 */  lw        $v0, -0x71ac($v0)
/* 321B4 80056DB4 00641821 */  addu      $v1, $v1, $a0
/* 321B8 80056DB8 8C420020 */  lw        $v0, 0x20($v0)
/* 321BC 80056DBC 000318C0 */  sll       $v1, $v1, 3
/* 321C0 80056DC0 00431021 */  addu      $v0, $v0, $v1
/* 321C4 80056DC4 03E00008 */  jr        $ra
/* 321C8 80056DC8 94420000 */   lhu      $v0, ($v0)

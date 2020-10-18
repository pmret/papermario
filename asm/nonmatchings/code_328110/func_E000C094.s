.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E000C094
/* 3281A4 E000C094 C4860024 */  lwc1      $f6, 0x24($a0)
/* 3281A8 E000C098 C4800028 */  lwc1      $f0, 0x28($a0)
/* 3281AC E000C09C 46003182 */  mul.s     $f6, $f6, $f0
/* 3281B0 E000C0A0 00000000 */  nop       
/* 3281B4 E000C0A4 C4840008 */  lwc1      $f4, 8($a0)
/* 3281B8 E000C0A8 C4800020 */  lwc1      $f0, 0x20($a0)
/* 3281BC E000C0AC 46002100 */  add.s     $f4, $f4, $f0
/* 3281C0 E000C0B0 C4820024 */  lwc1      $f2, 0x24($a0)
/* 3281C4 E000C0B4 46020000 */  add.s     $f0, $f0, $f2
/* 3281C8 E000C0B8 E4840008 */  swc1      $f4, 8($a0)
/* 3281CC E000C0BC E4800020 */  swc1      $f0, 0x20($a0)
/* 3281D0 E000C0C0 03E00008 */  jr        $ra
/* 3281D4 E000C0C4 E4860024 */   swc1     $f6, 0x24($a0)

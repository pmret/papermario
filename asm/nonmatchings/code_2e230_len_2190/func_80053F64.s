.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80053F64
/* 2F364 80053F64 14800004 */  bnez      $a0, .L80053F78
/* 2F368 80053F68 0000102D */   daddu    $v0, $zero, $zero
/* 2F36C 80053F6C 3C02800A */  lui       $v0, 0x800a
/* 2F370 80053F70 8C42A5C0 */  lw        $v0, -0x5a40($v0)
/* 2F374 80053F74 8C42006C */  lw        $v0, 0x6c($v0)
.L80053F78:
/* 2F378 80053F78 03E00008 */  jr        $ra
/* 2F37C 80053F7C 00000000 */   nop      

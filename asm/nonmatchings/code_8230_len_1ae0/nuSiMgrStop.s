.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuSiMgrStop
/* 838C 8002CF8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8390 8002CF90 24047F00 */  addiu     $a0, $zero, 0x7f00
/* 8394 8002CF94 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8398 8002CF98 0C00B3CA */  jal       nuSiSendMesg
/* 839C 8002CF9C 0000282D */   daddu    $a1, $zero, $zero
/* 83A0 8002CFA0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 83A4 8002CFA4 03E00008 */  jr        $ra
/* 83A8 8002CFA8 27BD0018 */   addiu    $sp, $sp, 0x18

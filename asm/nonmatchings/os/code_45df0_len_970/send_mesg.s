.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel send_mesg
/* 4637C 8006AF7C 03E09021 */  addu      $s2, $ra, $zero
/* 46380 8006AF80 3C0A800E */  lui       $t2, 0x800e
/* 46384 8006AF84 254A9F80 */  addiu     $t2, $t2, -0x6080
/* 46388 8006AF88 01445021 */  addu      $t2, $t2, $a0
/* 4638C 8006AF8C 8D490000 */  lw        $t1, ($t2)
/* 46390 8006AF90 11200027 */  beqz      $t1, .L8006B030
/* 46394 8006AF94 00000000 */   nop      
/* 46398 8006AF98 8D2B0008 */  lw        $t3, 8($t1)
/* 4639C 8006AF9C 8D2C0010 */  lw        $t4, 0x10($t1)
/* 463A0 8006AFA0 016C082A */  slt       $at, $t3, $t4
/* 463A4 8006AFA4 10200022 */  beqz      $at, .L8006B030
/* 463A8 8006AFA8 00000000 */   nop      
/* 463AC 8006AFAC 8D2D000C */  lw        $t5, 0xc($t1)
/* 463B0 8006AFB0 01AB6821 */  addu      $t5, $t5, $t3
/* 463B4 8006AFB4 01AC001A */  div       $zero, $t5, $t4
/* 463B8 8006AFB8 15800002 */  bnez      $t4, send_done
/* 463BC 8006AFBC 00000000 */   nop      
/* 463C0 8006AFC0 0007000D */  break     7

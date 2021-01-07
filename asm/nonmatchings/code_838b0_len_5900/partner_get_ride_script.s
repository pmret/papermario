.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel partner_get_ride_script
/* 84AE8 800EB638 3C028011 */  lui       $v0, %hi(D_8010CFEC)
/* 84AEC 800EB63C 8C42CFEC */  lw        $v0, %lo(D_8010CFEC)($v0)
/* 84AF0 800EB640 10400003 */  beqz      $v0, .L800EB650
/* 84AF4 800EB644 00000000 */   nop      
/* 84AF8 800EB648 03E00008 */  jr        $ra
/* 84AFC 800EB64C 8C42003C */   lw       $v0, 0x3c($v0)
.L800EB650:
/* 84B00 800EB650 03E00008 */  jr        $ra
/* 84B04 800EB654 0000102D */   daddu    $v0, $zero, $zero

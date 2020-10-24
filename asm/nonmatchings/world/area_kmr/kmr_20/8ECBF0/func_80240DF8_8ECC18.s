.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DF8_8ECC18
/* 8ECC18 80240DF8 3C03800B */  lui       $v1, %hi(gCameras)
/* 8ECC1C 80240DFC 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 8ECC20 80240E00 94620002 */  lhu       $v0, 2($v1)
/* 8ECC24 80240E04 3042FFFE */  andi      $v0, $v0, 0xfffe
/* 8ECC28 80240E08 A4620002 */  sh        $v0, 2($v1)
/* 8ECC2C 80240E0C 03E00008 */  jr        $ra
/* 8ECC30 80240E10 24020002 */   addiu    $v0, $zero, 2
/* 8ECC34 80240E14 00000000 */  nop       
/* 8ECC38 80240E18 00000000 */  nop       
/* 8ECC3C 80240E1C 00000000 */  nop       

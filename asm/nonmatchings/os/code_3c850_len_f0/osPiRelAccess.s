.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osPiRelAccess
/* 3C910 80061510 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3C914 80061514 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3C918 80061518 3C04800B */  lui       $a0, 0x800b
/* 3C91C 8006151C 24844380 */  addiu     $a0, $a0, 0x4380
/* 3C920 80061520 00002821 */  addu      $a1, $zero, $zero
/* 3C924 80061524 0C019608 */  jal       osSendMesg
/* 3C928 80061528 00003021 */   addu     $a2, $zero, $zero
/* 3C92C 8006152C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3C930 80061530 03E00008 */  jr        $ra
/* 3C934 80061534 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3C938 80061538 00000000 */  nop       
/* 3C93C 8006153C 00000000 */  nop       

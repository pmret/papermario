.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050184
/* 2B584 80050184 908600D6 */  lbu       $a2, 0xd6($a0)
/* 2B588 80050188 948200D4 */  lhu       $v0, 0xd4($a0)
/* 2B58C 8005018C 8C840064 */  lw        $a0, 0x64($a0)
/* 2B590 80050190 8CA30000 */  lw        $v1, ($a1)
/* 2B594 80050194 00441021 */  addu      $v0, $v0, $a0
/* 2B598 80050198 A4A6003E */  sh        $a2, 0x3e($a1)
/* 2B59C 8005019C ACA30004 */  sw        $v1, 4($a1)
/* 2B5A0 800501A0 03E00008 */  jr        $ra
/* 2B5A4 800501A4 ACA20000 */   sw       $v0, ($a1)

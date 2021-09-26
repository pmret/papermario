.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel hide_status_icon_debuff
/* 22CF8 800478F8 00041040 */  sll       $v0, $a0, 1
/* 22CFC 800478FC 00441021 */  addu      $v0, $v0, $a0
/* 22D00 80047900 00021080 */  sll       $v0, $v0, 2
/* 22D04 80047904 00441023 */  subu      $v0, $v0, $a0
/* 22D08 80047908 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 22D0C 8004790C 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 22D10 80047910 00021100 */  sll       $v0, $v0, 4
/* 22D14 80047914 00621821 */  addu      $v1, $v1, $v0
/* 22D18 80047918 8C620000 */  lw        $v0, ($v1)
/* 22D1C 8004791C 34420004 */  ori       $v0, $v0, 4
/* 22D20 80047920 03E00008 */  jr        $ra
/* 22D24 80047924 AC620000 */   sw       $v0, ($v1)

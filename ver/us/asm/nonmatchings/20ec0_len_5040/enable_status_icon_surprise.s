.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel enable_status_icon_surprise
/* 23434 80048034 00041040 */  sll       $v0, $a0, 1
/* 23438 80048038 00441021 */  addu      $v0, $v0, $a0
/* 2343C 8004803C 00021080 */  sll       $v0, $v0, 2
/* 23440 80048040 00441023 */  subu      $v0, $v0, $a0
/* 23444 80048044 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 23448 80048048 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 2344C 8004804C 00021100 */  sll       $v0, $v0, 4
/* 23450 80048050 00621821 */  addu      $v1, $v1, $v0
/* 23454 80048054 8C620000 */  lw        $v0, ($v1)
/* 23458 80048058 34420200 */  ori       $v0, $v0, 0x200
/* 2345C 8004805C 03E00008 */  jr        $ra
/* 23460 80048060 AC620000 */   sw       $v0, ($v1)

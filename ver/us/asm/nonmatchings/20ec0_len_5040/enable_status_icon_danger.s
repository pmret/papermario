.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel enable_status_icon_danger
/* 2364C 8004824C 00041040 */  sll       $v0, $a0, 1
/* 23650 80048250 00441021 */  addu      $v0, $v0, $a0
/* 23654 80048254 00021080 */  sll       $v0, $v0, 2
/* 23658 80048258 00441023 */  subu      $v0, $v0, $a0
/* 2365C 8004825C 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 23660 80048260 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 23664 80048264 00021100 */  sll       $v0, $v0, 4
/* 23668 80048268 00621821 */  addu      $v1, $v1, $v0
/* 2366C 8004826C 8C620000 */  lw        $v0, ($v1)
/* 23670 80048270 34420800 */  ori       $v0, $v0, 0x800
/* 23674 80048274 03E00008 */  jr        $ra
/* 23678 80048278 AC620000 */   sw       $v0, ($v1)
/* 2367C 8004827C 00000000 */  nop

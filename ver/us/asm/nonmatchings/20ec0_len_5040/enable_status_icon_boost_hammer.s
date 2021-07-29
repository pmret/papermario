.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel enable_status_icon_boost_hammer
/* 2321C 80047E1C 00041040 */  sll       $v0, $a0, 1
/* 23220 80047E20 00441021 */  addu      $v0, $v0, $a0
/* 23224 80047E24 00021080 */  sll       $v0, $v0, 2
/* 23228 80047E28 00441023 */  subu      $v0, $v0, $a0
/* 2322C 80047E2C 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 23230 80047E30 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 23234 80047E34 00021100 */  sll       $v0, $v0, 4
/* 23238 80047E38 00621821 */  addu      $v1, $v1, $v0
/* 2323C 80047E3C 8C620000 */  lw        $v0, ($v1)
/* 23240 80047E40 34420080 */  ori       $v0, $v0, 0x80
/* 23244 80047E44 03E00008 */  jr        $ra
/* 23248 80047E48 AC620000 */   sw       $v0, ($v1)

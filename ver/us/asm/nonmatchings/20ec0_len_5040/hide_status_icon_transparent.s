.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel hide_status_icon_transparent
/* 22F08 80047B08 00041040 */  sll       $v0, $a0, 1
/* 22F0C 80047B0C 00441021 */  addu      $v0, $v0, $a0
/* 22F10 80047B10 00021080 */  sll       $v0, $v0, 2
/* 22F14 80047B14 00441023 */  subu      $v0, $v0, $a0
/* 22F18 80047B18 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 22F1C 80047B1C 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 22F20 80047B20 00021100 */  sll       $v0, $v0, 4
/* 22F24 80047B24 00621821 */  addu      $v1, $v1, $v0
/* 22F28 80047B28 8C620000 */  lw        $v0, ($v1)
/* 22F2C 80047B2C 34420010 */  ori       $v0, $v0, 0x10
/* 22F30 80047B30 03E00008 */  jr        $ra
/* 22F34 80047B34 AC620000 */   sw       $v0, ($v1)

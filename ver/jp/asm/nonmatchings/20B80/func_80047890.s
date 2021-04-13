.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047890
/* 22C90 80047890 00041040 */  sll       $v0, $a0, 1
/* 22C94 80047894 00441021 */  addu      $v0, $v0, $a0
/* 22C98 80047898 00021080 */  sll       $v0, $v0, 2
/* 22C9C 8004789C 00441023 */  subu      $v0, $v0, $a0
/* 22CA0 800478A0 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 22CA4 800478A4 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 22CA8 800478A8 00021100 */  sll       $v0, $v0, 4
/* 22CAC 800478AC 00621821 */  addu      $v1, $v1, $v0
/* 22CB0 800478B0 8C620000 */  lw        $v0, ($v1)
/* 22CB4 800478B4 34420020 */  ori       $v0, $v0, 0x20
/* 22CB8 800478B8 03E00008 */  jr        $ra
/* 22CBC 800478BC AC620000 */   sw       $v0, ($v1)

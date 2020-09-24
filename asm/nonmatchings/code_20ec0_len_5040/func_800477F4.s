.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800477F4
/* 22BF4 800477F4 00041040 */  sll       $v0, $a0, 1
/* 22BF8 800477F8 00441021 */  addu      $v0, $v0, $a0
/* 22BFC 800477FC 00021080 */  sll       $v0, $v0, 2
/* 22C00 80047800 00441023 */  subu      $v0, $v0, $a0
/* 22C04 80047804 3C03800A */  lui       $v1, 0x800a
/* 22C08 80047808 8C630F44 */  lw        $v1, 0xf44($v1)
/* 22C0C 8004780C 00021100 */  sll       $v0, $v0, 4
/* 22C10 80047810 00621821 */  addu      $v1, $v1, $v0
/* 22C14 80047814 AC650030 */  sw        $a1, 0x30($v1)
/* 22C18 80047818 03E00008 */  jr        $ra
/* 22C1C 8004781C AC660034 */   sw       $a2, 0x34($v1)

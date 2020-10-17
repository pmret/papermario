.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuAuDmaNew
/* 26624 8004B224 3C03800A */  lui       $v1, 0x800a
/* 26628 8004B228 24633BD0 */  addiu     $v1, $v1, 0x3bd0
/* 2662C 8004B22C 90620000 */  lbu       $v0, ($v1)
/* 26630 8004B230 14400007 */  bnez      $v0, .L8004B250
/* 26634 8004B234 00000000 */   nop      
/* 26638 8004B238 3C02800A */  lui       $v0, 0x800a
/* 2663C 8004B23C 24423BE0 */  addiu     $v0, $v0, 0x3be0
/* 26640 8004B240 AC620008 */  sw        $v0, 8($v1)
/* 26644 8004B244 24020001 */  addiu     $v0, $zero, 1
/* 26648 8004B248 AC600004 */  sw        $zero, 4($v1)
/* 2664C 8004B24C A0620000 */  sb        $v0, ($v1)
.L8004B250:
/* 26650 8004B250 3C028005 */  lui       $v0, %hi(nuAuDmaCallBack)
/* 26654 8004B254 2442B074 */  addiu     $v0, $v0, %lo(nuAuDmaCallBack)
/* 26658 8004B258 3C018008 */  lui       $at, 0x8008
/* 2665C 8004B25C AC208178 */  sw        $zero, -0x7e88($at)
/* 26660 8004B260 03E00008 */  jr        $ra
/* 26664 8004B264 AC830000 */   sw       $v1, ($a0)

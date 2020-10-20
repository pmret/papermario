.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240518_DC48E8
/* DC48E8 80240518 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* DC48EC 8024051C 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* DC48F0 80240520 8C620000 */  lw        $v0, ($v1)
/* DC48F4 80240524 AC800084 */  sw        $zero, 0x84($a0)
/* DC48F8 80240528 8C420010 */  lw        $v0, 0x10($v0)
/* DC48FC 8024052C 30428000 */  andi      $v0, $v0, 0x8000
/* DC4900 80240530 10400002 */  beqz      $v0, .L8024053C
/* DC4904 80240534 24020001 */   addiu    $v0, $zero, 1
/* DC4908 80240538 AC820084 */  sw        $v0, 0x84($a0)
.L8024053C:
/* DC490C 8024053C 8C620000 */  lw        $v0, ($v1)
/* DC4910 80240540 8C420010 */  lw        $v0, 0x10($v0)
/* DC4914 80240544 30424000 */  andi      $v0, $v0, 0x4000
/* DC4918 80240548 10400002 */  beqz      $v0, .L80240554
/* DC491C 8024054C 24020001 */   addiu    $v0, $zero, 1
/* DC4920 80240550 AC820084 */  sw        $v0, 0x84($a0)
.L80240554:
/* DC4924 80240554 03E00008 */  jr        $ra
/* DC4928 80240558 24020002 */   addiu    $v0, $zero, 2

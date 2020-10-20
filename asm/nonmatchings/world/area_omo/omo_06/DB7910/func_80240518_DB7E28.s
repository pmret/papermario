.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240518_DB7E28
/* DB7E28 80240518 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* DB7E2C 8024051C 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* DB7E30 80240520 8C620000 */  lw        $v0, ($v1)
/* DB7E34 80240524 AC800084 */  sw        $zero, 0x84($a0)
/* DB7E38 80240528 8C420010 */  lw        $v0, 0x10($v0)
/* DB7E3C 8024052C 30428000 */  andi      $v0, $v0, 0x8000
/* DB7E40 80240530 10400002 */  beqz      $v0, .L8024053C
/* DB7E44 80240534 24020001 */   addiu    $v0, $zero, 1
/* DB7E48 80240538 AC820084 */  sw        $v0, 0x84($a0)
.L8024053C:
/* DB7E4C 8024053C 8C620000 */  lw        $v0, ($v1)
/* DB7E50 80240540 8C420010 */  lw        $v0, 0x10($v0)
/* DB7E54 80240544 30424000 */  andi      $v0, $v0, 0x4000
/* DB7E58 80240548 10400002 */  beqz      $v0, .L80240554
/* DB7E5C 8024054C 24020001 */   addiu    $v0, $zero, 1
/* DB7E60 80240550 AC820084 */  sw        $v0, 0x84($a0)
.L80240554:
/* DB7E64 80240554 03E00008 */  jr        $ra
/* DB7E68 80240558 24020002 */   addiu    $v0, $zero, 2

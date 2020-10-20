.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240518_DD7EC8
/* DD7EC8 80240518 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* DD7ECC 8024051C 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* DD7ED0 80240520 8C620000 */  lw        $v0, ($v1)
/* DD7ED4 80240524 AC800084 */  sw        $zero, 0x84($a0)
/* DD7ED8 80240528 8C420010 */  lw        $v0, 0x10($v0)
/* DD7EDC 8024052C 30428000 */  andi      $v0, $v0, 0x8000
/* DD7EE0 80240530 10400002 */  beqz      $v0, .L8024053C
/* DD7EE4 80240534 24020001 */   addiu    $v0, $zero, 1
/* DD7EE8 80240538 AC820084 */  sw        $v0, 0x84($a0)
.L8024053C:
/* DD7EEC 8024053C 8C620000 */  lw        $v0, ($v1)
/* DD7EF0 80240540 8C420010 */  lw        $v0, 0x10($v0)
/* DD7EF4 80240544 30424000 */  andi      $v0, $v0, 0x4000
/* DD7EF8 80240548 10400002 */  beqz      $v0, .L80240554
/* DD7EFC 8024054C 24020001 */   addiu    $v0, $zero, 1
/* DD7F00 80240550 AC820084 */  sw        $v0, 0x84($a0)
.L80240554:
/* DD7F04 80240554 03E00008 */  jr        $ra
/* DD7F08 80240558 24020002 */   addiu    $v0, $zero, 2

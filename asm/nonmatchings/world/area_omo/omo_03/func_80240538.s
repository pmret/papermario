.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240538
/* DA5778 80240538 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* DA577C 8024053C 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* DA5780 80240540 8C620000 */  lw        $v0, ($v1)
/* DA5784 80240544 AC800084 */  sw        $zero, 0x84($a0)
/* DA5788 80240548 8C420010 */  lw        $v0, 0x10($v0)
/* DA578C 8024054C 30428000 */  andi      $v0, $v0, 0x8000
/* DA5790 80240550 10400002 */  beqz      $v0, .L8024055C
/* DA5794 80240554 24020001 */   addiu    $v0, $zero, 1
/* DA5798 80240558 AC820084 */  sw        $v0, 0x84($a0)
.L8024055C:
/* DA579C 8024055C 8C620000 */  lw        $v0, ($v1)
/* DA57A0 80240560 8C420010 */  lw        $v0, 0x10($v0)
/* DA57A4 80240564 30424000 */  andi      $v0, $v0, 0x4000
/* DA57A8 80240568 10400002 */  beqz      $v0, .L80240574
/* DA57AC 8024056C 24020001 */   addiu    $v0, $zero, 1
/* DA57B0 80240570 AC820084 */  sw        $v0, 0x84($a0)
.L80240574:
/* DA57B4 80240574 03E00008 */  jr        $ra
/* DA57B8 80240578 24020002 */   addiu    $v0, $zero, 2

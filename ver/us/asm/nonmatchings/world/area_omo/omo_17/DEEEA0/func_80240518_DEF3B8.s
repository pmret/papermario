.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240518_DEF3B8
/* DEF3B8 80240518 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* DEF3BC 8024051C 2463419C */  addiu     $v1, $v1, %lo(gGameStatusPtr)
/* DEF3C0 80240520 8C620000 */  lw        $v0, ($v1)
/* DEF3C4 80240524 AC800084 */  sw        $zero, 0x84($a0)
/* DEF3C8 80240528 8C420010 */  lw        $v0, 0x10($v0)
/* DEF3CC 8024052C 30428000 */  andi      $v0, $v0, 0x8000
/* DEF3D0 80240530 10400002 */  beqz      $v0, .L8024053C
/* DEF3D4 80240534 24020001 */   addiu    $v0, $zero, 1
/* DEF3D8 80240538 AC820084 */  sw        $v0, 0x84($a0)
.L8024053C:
/* DEF3DC 8024053C 8C620000 */  lw        $v0, ($v1)
/* DEF3E0 80240540 8C420010 */  lw        $v0, 0x10($v0)
/* DEF3E4 80240544 30424000 */  andi      $v0, $v0, 0x4000
/* DEF3E8 80240548 10400002 */  beqz      $v0, .L80240554
/* DEF3EC 8024054C 24020001 */   addiu    $v0, $zero, 1
/* DEF3F0 80240550 AC820084 */  sw        $v0, 0x84($a0)
.L80240554:
/* DEF3F4 80240554 03E00008 */  jr        $ra
/* DEF3F8 80240558 24020002 */   addiu    $v0, $zero, 2
/* DEF3FC 8024055C 00000000 */  nop

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406E0_EB1540
/* EB1540 802406E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EB1544 802406E4 AFBF0010 */  sw        $ra, 0x10($sp)
/* EB1548 802406E8 8C82000C */  lw        $v0, 0xc($a0)
/* EB154C 802406EC 0C0B53A3 */  jal       dead_get_variable
/* EB1550 802406F0 8C450000 */   lw       $a1, ($v0)
/* EB1554 802406F4 0040182D */  daddu     $v1, $v0, $zero
/* EB1558 802406F8 10600012 */  beqz      $v1, .L80240744
/* EB155C 802406FC 0000202D */   daddu    $a0, $zero, $zero
/* EB1560 80240700 8C620000 */  lw        $v0, ($v1)
/* EB1564 80240704 5040000A */  beql      $v0, $zero, .L80240730
/* EB1568 80240708 00041080 */   sll      $v0, $a0, 2
/* EB156C 8024070C 3C058024 */  lui       $a1, %hi(D_802442D0)
/* EB1570 80240710 24A542D0 */  addiu     $a1, $a1, %lo(D_802442D0)
.L80240714:
/* EB1574 80240714 24630004 */  addiu     $v1, $v1, 4
/* EB1578 80240718 24840001 */  addiu     $a0, $a0, 1
/* EB157C 8024071C ACA20000 */  sw        $v0, ($a1)
/* EB1580 80240720 8C620000 */  lw        $v0, ($v1)
/* EB1584 80240724 1440FFFB */  bnez      $v0, .L80240714
/* EB1588 80240728 24A50004 */   addiu    $a1, $a1, 4
/* EB158C 8024072C 00041080 */  sll       $v0, $a0, 2
.L80240730:
/* EB1590 80240730 3C018024 */  lui       $at, %hi(D_802442D0)
/* EB1594 80240734 00220821 */  addu      $at, $at, $v0
/* EB1598 80240738 AC2042D0 */  sw        $zero, %lo(D_802442D0)($at)
/* EB159C 8024073C 080901DB */  j         .L8024076C
/* EB15A0 80240740 00000000 */   nop
.L80240744:
/* EB15A4 80240744 3C038024 */  lui       $v1, %hi(D_802442D0)
/* EB15A8 80240748 246342D0 */  addiu     $v1, $v1, %lo(D_802442D0)
/* EB15AC 8024074C 0060282D */  daddu     $a1, $v1, $zero
.L80240750:
/* EB15B0 80240750 24820010 */  addiu     $v0, $a0, 0x10
/* EB15B4 80240754 AC620000 */  sw        $v0, ($v1)
/* EB15B8 80240758 24630004 */  addiu     $v1, $v1, 4
/* EB15BC 8024075C 24840001 */  addiu     $a0, $a0, 1
/* EB15C0 80240760 28820070 */  slti      $v0, $a0, 0x70
/* EB15C4 80240764 1440FFFA */  bnez      $v0, .L80240750
/* EB15C8 80240768 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L8024076C:
/* EB15CC 8024076C 8FBF0010 */  lw        $ra, 0x10($sp)
/* EB15D0 80240770 24020002 */  addiu     $v0, $zero, 2
/* EB15D4 80240774 03E00008 */  jr        $ra
/* EB15D8 80240778 27BD0018 */   addiu    $sp, $sp, 0x18

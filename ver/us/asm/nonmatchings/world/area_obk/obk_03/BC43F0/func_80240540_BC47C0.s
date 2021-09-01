.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240540_BC47C0
/* BC47C0 80240540 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BC47C4 80240544 AFBF0010 */  sw        $ra, 0x10($sp)
/* BC47C8 80240548 8C82000C */  lw        $v0, 0xc($a0)
/* BC47CC 8024054C 0C0B1EAF */  jal       evt_get_variable
/* BC47D0 80240550 8C450000 */   lw       $a1, ($v0)
/* BC47D4 80240554 0040182D */  daddu     $v1, $v0, $zero
/* BC47D8 80240558 10600012 */  beqz      $v1, .L802405A4
/* BC47DC 8024055C 0000202D */   daddu    $a0, $zero, $zero
/* BC47E0 80240560 8C620000 */  lw        $v0, ($v1)
/* BC47E4 80240564 5040000A */  beql      $v0, $zero, .L80240590
/* BC47E8 80240568 00041080 */   sll      $v0, $a0, 2
/* BC47EC 8024056C 3C058024 */  lui       $a1, %hi(D_80243BE0)
/* BC47F0 80240570 24A53BE0 */  addiu     $a1, $a1, %lo(D_80243BE0)
.L80240574:
/* BC47F4 80240574 24630004 */  addiu     $v1, $v1, 4
/* BC47F8 80240578 24840001 */  addiu     $a0, $a0, 1
/* BC47FC 8024057C ACA20000 */  sw        $v0, ($a1)
/* BC4800 80240580 8C620000 */  lw        $v0, ($v1)
/* BC4804 80240584 1440FFFB */  bnez      $v0, .L80240574
/* BC4808 80240588 24A50004 */   addiu    $a1, $a1, 4
/* BC480C 8024058C 00041080 */  sll       $v0, $a0, 2
.L80240590:
/* BC4810 80240590 3C018024 */  lui       $at, %hi(D_80243BE0)
/* BC4814 80240594 00220821 */  addu      $at, $at, $v0
/* BC4818 80240598 AC203BE0 */  sw        $zero, %lo(D_80243BE0)($at)
/* BC481C 8024059C 08090173 */  j         .L802405CC
/* BC4820 802405A0 00000000 */   nop
.L802405A4:
/* BC4824 802405A4 3C038024 */  lui       $v1, %hi(D_80243BE0)
/* BC4828 802405A8 24633BE0 */  addiu     $v1, $v1, %lo(D_80243BE0)
/* BC482C 802405AC 0060282D */  daddu     $a1, $v1, $zero
.L802405B0:
/* BC4830 802405B0 24820010 */  addiu     $v0, $a0, 0x10
/* BC4834 802405B4 AC620000 */  sw        $v0, ($v1)
/* BC4838 802405B8 24630004 */  addiu     $v1, $v1, 4
/* BC483C 802405BC 24840001 */  addiu     $a0, $a0, 1
/* BC4840 802405C0 28820070 */  slti      $v0, $a0, 0x70
/* BC4844 802405C4 1440FFFA */  bnez      $v0, .L802405B0
/* BC4848 802405C8 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L802405CC:
/* BC484C 802405CC 8FBF0010 */  lw        $ra, 0x10($sp)
/* BC4850 802405D0 24020002 */  addiu     $v0, $zero, 2
/* BC4854 802405D4 03E00008 */  jr        $ra
/* BC4858 802405D8 27BD0018 */   addiu    $sp, $sp, 0x18

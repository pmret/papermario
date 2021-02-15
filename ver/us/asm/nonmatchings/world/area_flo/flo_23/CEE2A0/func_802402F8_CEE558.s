.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402F8_CEE558
/* CEE558 802402F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CEE55C 802402FC AFBF0010 */  sw        $ra, 0x10($sp)
/* CEE560 80240300 8C82000C */  lw        $v0, 0xc($a0)
/* CEE564 80240304 0C0B1EAF */  jal       get_variable
/* CEE568 80240308 8C450000 */   lw       $a1, ($v0)
/* CEE56C 8024030C 0040182D */  daddu     $v1, $v0, $zero
/* CEE570 80240310 10600012 */  beqz      $v1, .L8024035C
/* CEE574 80240314 0000202D */   daddu    $a0, $zero, $zero
/* CEE578 80240318 8C620000 */  lw        $v0, ($v1)
/* CEE57C 8024031C 5040000A */  beql      $v0, $zero, .L80240348
/* CEE580 80240320 00041080 */   sll      $v0, $a0, 2
/* CEE584 80240324 3C058024 */  lui       $a1, %hi(func_802426E0_BA6E60)
/* CEE588 80240328 24A526E0 */  addiu     $a1, $a1, %lo(func_802426E0_BA6E60)
.L8024032C:
/* CEE58C 8024032C 24630004 */  addiu     $v1, $v1, 4
/* CEE590 80240330 24840001 */  addiu     $a0, $a0, 1
/* CEE594 80240334 ACA20000 */  sw        $v0, ($a1)
/* CEE598 80240338 8C620000 */  lw        $v0, ($v1)
/* CEE59C 8024033C 1440FFFB */  bnez      $v0, .L8024032C
/* CEE5A0 80240340 24A50004 */   addiu    $a1, $a1, 4
/* CEE5A4 80240344 00041080 */  sll       $v0, $a0, 2
.L80240348:
/* CEE5A8 80240348 3C018024 */  lui       $at, %hi(func_802426E0_BA6E60)
/* CEE5AC 8024034C 00220821 */  addu      $at, $at, $v0
/* CEE5B0 80240350 AC2026E0 */  sw        $zero, %lo(func_802426E0_BA6E60)($at)
/* CEE5B4 80240354 080900E1 */  j         .L80240384
/* CEE5B8 80240358 00000000 */   nop
.L8024035C:
/* CEE5BC 8024035C 3C038024 */  lui       $v1, %hi(func_802426E0_BA6E60)
/* CEE5C0 80240360 246326E0 */  addiu     $v1, $v1, %lo(func_802426E0_BA6E60)
/* CEE5C4 80240364 0060282D */  daddu     $a1, $v1, $zero
.L80240368:
/* CEE5C8 80240368 24820080 */  addiu     $v0, $a0, 0x80
/* CEE5CC 8024036C AC620000 */  sw        $v0, ($v1)
/* CEE5D0 80240370 24630004 */  addiu     $v1, $v1, 4
/* CEE5D4 80240374 24840001 */  addiu     $a0, $a0, 1
/* CEE5D8 80240378 2882005B */  slti      $v0, $a0, 0x5b
/* CEE5DC 8024037C 1440FFFA */  bnez      $v0, .L80240368
/* CEE5E0 80240380 ACA0016C */   sw       $zero, 0x16c($a1)
.L80240384:
/* CEE5E4 80240384 8FBF0010 */  lw        $ra, 0x10($sp)
/* CEE5E8 80240388 24020002 */  addiu     $v0, $zero, 2
/* CEE5EC 8024038C 03E00008 */  jr        $ra
/* CEE5F0 80240390 27BD0018 */   addiu    $sp, $sp, 0x18

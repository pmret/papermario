.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_window_hierarchy
/* DE470 80147D70 30A200FF */  andi      $v0, $a1, 0xff
/* DE474 80147D74 2C420041 */  sltiu     $v0, $v0, 0x41
/* DE478 80147D78 14400002 */  bnez      $v0, .L80147D84
/* DE47C 80147D7C 27BDFEF8 */   addiu    $sp, $sp, -0x108
/* DE480 80147D80 24050040 */  addiu     $a1, $zero, 0x40
.L80147D84:
/* DE484 80147D84 03A0382D */  daddu     $a3, $sp, $zero
/* DE488 80147D88 2402FFFF */  addiu     $v0, $zero, -1
/* DE48C 80147D8C 24060040 */  addiu     $a2, $zero, 0x40
.L80147D90:
/* DE490 80147D90 ACE20000 */  sw        $v0, ($a3)
/* DE494 80147D94 24C6FFFF */  addiu     $a2, $a2, -1
/* DE498 80147D98 04C1FFFD */  bgez      $a2, .L80147D90
/* DE49C 80147D9C 24E70004 */   addiu    $a3, $a3, 4
/* DE4A0 80147DA0 30A200FF */  andi      $v0, $a1, 0xff
/* DE4A4 80147DA4 00021880 */  sll       $v1, $v0, 2
/* DE4A8 80147DA8 03A31821 */  addu      $v1, $sp, $v1
/* DE4AC 80147DAC AC640000 */  sw        $a0, ($v1)
/* DE4B0 80147DB0 0000302D */  daddu     $a2, $zero, $zero
/* DE4B4 80147DB4 3C058016 */  lui       $a1, %hi(gUIPanels)
/* DE4B8 80147DB8 24A59D50 */  addiu     $a1, $a1, %lo(gUIPanels)
/* DE4BC 80147DBC 0040382D */  daddu     $a3, $v0, $zero
.L80147DC0:
/* DE4C0 80147DC0 90A20000 */  lbu       $v0, ($a1)
/* DE4C4 80147DC4 5040000B */  beql      $v0, $zero, .L80147DF4
/* DE4C8 80147DC8 24C60001 */   addiu    $a2, $a2, 1
/* DE4CC 80147DCC 50C40009 */  beql      $a2, $a0, .L80147DF4
/* DE4D0 80147DD0 24C60001 */   addiu    $a2, $a2, 1
/* DE4D4 80147DD4 90A30001 */  lbu       $v1, 1($a1)
/* DE4D8 80147DD8 0067102A */  slt       $v0, $v1, $a3
/* DE4DC 80147DDC 50400001 */  beql      $v0, $zero, .L80147DE4
/* DE4E0 80147DE0 24630001 */   addiu    $v1, $v1, 1
.L80147DE4:
/* DE4E4 80147DE4 00031080 */  sll       $v0, $v1, 2
/* DE4E8 80147DE8 03A21021 */  addu      $v0, $sp, $v0
/* DE4EC 80147DEC AC460000 */  sw        $a2, ($v0)
/* DE4F0 80147DF0 24C60001 */  addiu     $a2, $a2, 1
.L80147DF4:
/* DE4F4 80147DF4 28C20040 */  slti      $v0, $a2, 0x40
/* DE4F8 80147DF8 1440FFF1 */  bnez      $v0, .L80147DC0
/* DE4FC 80147DFC 24A50020 */   addiu    $a1, $a1, 0x20
/* DE500 80147E00 0000182D */  daddu     $v1, $zero, $zero
/* DE504 80147E04 0060302D */  daddu     $a2, $v1, $zero
/* DE508 80147E08 03A0382D */  daddu     $a3, $sp, $zero
/* DE50C 80147E0C 2405FFFF */  addiu     $a1, $zero, -1
/* DE510 80147E10 3C048016 */  lui       $a0, %hi(gUIPanels)
/* DE514 80147E14 24849D50 */  addiu     $a0, $a0, %lo(gUIPanels)
.L80147E18:
/* DE518 80147E18 8CE20000 */  lw        $v0, ($a3)
/* DE51C 80147E1C 10450005 */  beq       $v0, $a1, .L80147E34
/* DE520 80147E20 24C60001 */   addiu    $a2, $a2, 1
/* DE524 80147E24 00021140 */  sll       $v0, $v0, 5
/* DE528 80147E28 00441021 */  addu      $v0, $v0, $a0
/* DE52C 80147E2C A0430001 */  sb        $v1, 1($v0)
/* DE530 80147E30 24630001 */  addiu     $v1, $v1, 1
.L80147E34:
/* DE534 80147E34 28C20041 */  slti      $v0, $a2, 0x41
/* DE538 80147E38 1440FFF7 */  bnez      $v0, .L80147E18
/* DE53C 80147E3C 24E70004 */   addiu    $a3, $a3, 4
/* DE540 80147E40 03E00008 */  jr        $ra
/* DE544 80147E44 27BD0108 */   addiu    $sp, $sp, 0x108

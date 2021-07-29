.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SummonEnemy
/* 19C444 8026DB64 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 19C448 8026DB68 AFB20018 */  sw        $s2, 0x18($sp)
/* 19C44C 8026DB6C 0080902D */  daddu     $s2, $a0, $zero
/* 19C450 8026DB70 AFB10014 */  sw        $s1, 0x14($sp)
/* 19C454 8026DB74 3C11800E */  lui       $s1, %hi(gBattleStatus)
/* 19C458 8026DB78 2631C070 */  addiu     $s1, $s1, %lo(gBattleStatus)
/* 19C45C 8026DB7C AFBF001C */  sw        $ra, 0x1c($sp)
/* 19C460 8026DB80 AFB00010 */  sw        $s0, 0x10($sp)
/* 19C464 8026DB84 8E50000C */  lw        $s0, 0xc($s2)
/* 19C468 8026DB88 54A00001 */  bnel      $a1, $zero, .L8026DB90
/* 19C46C 8026DB8C AE400070 */   sw       $zero, 0x70($s2)
.L8026DB90:
/* 19C470 8026DB90 8E430070 */  lw        $v1, 0x70($s2)
/* 19C474 8026DB94 10600005 */  beqz      $v1, .L8026DBAC
/* 19C478 8026DB98 24020001 */   addiu    $v0, $zero, 1
/* 19C47C 8026DB9C 10620011 */  beq       $v1, $v0, .L8026DBE4
/* 19C480 8026DBA0 0000102D */   daddu    $v0, $zero, $zero
/* 19C484 8026DBA4 0809B77A */  j         .L8026DDE8
/* 19C488 8026DBA8 00000000 */   nop
.L8026DBAC:
/* 19C48C 8026DBAC 8E050000 */  lw        $a1, ($s0)
/* 19C490 8026DBB0 26100004 */  addiu     $s0, $s0, 4
/* 19C494 8026DBB4 0C0B1EAF */  jal       get_variable
/* 19C498 8026DBB8 0240202D */   daddu    $a0, $s2, $zero
/* 19C49C 8026DBBC 0C0994E9 */  jal       create_actor
/* 19C4A0 8026DBC0 0040202D */   daddu    $a0, $v0, $zero
/* 19C4A4 8026DBC4 AE420074 */  sw        $v0, 0x74($s2)
/* 19C4A8 8026DBC8 8E050000 */  lw        $a1, ($s0)
/* 19C4AC 8026DBCC 0C0B1EAF */  jal       get_variable
/* 19C4B0 8026DBD0 0240202D */   daddu    $a0, $s2, $zero
/* 19C4B4 8026DBD4 AE420078 */  sw        $v0, 0x78($s2)
/* 19C4B8 8026DBD8 24020001 */  addiu     $v0, $zero, 1
/* 19C4BC 8026DBDC 0809B779 */  j         .L8026DDE4
/* 19C4C0 8026DBE0 AE420070 */   sw       $v0, 0x70($s2)
.L8026DBE4:
/* 19C4C4 8026DBE4 8E500074 */  lw        $s0, 0x74($s2)
/* 19C4C8 8026DBE8 0C0B1059 */  jal       does_script_exist
/* 19C4CC 8026DBEC 8E0401E4 */   lw       $a0, 0x1e4($s0)
/* 19C4D0 8026DBF0 1440007D */  bnez      $v0, .L8026DDE8
/* 19C4D4 8026DBF4 0000102D */   daddu    $v0, $zero, $zero
/* 19C4D8 8026DBF8 82220170 */  lb        $v0, 0x170($s1)
/* 19C4DC 8026DBFC 14400040 */  bnez      $v0, .L8026DD00
/* 19C4E0 8026DC00 262E0140 */   addiu    $t6, $s1, 0x140
/* 19C4E4 8026DC04 0000582D */  daddu     $t3, $zero, $zero
/* 19C4E8 8026DC08 0160202D */  daddu     $a0, $t3, $zero
/* 19C4EC 8026DC0C 0220282D */  daddu     $a1, $s1, $zero
/* 19C4F0 8026DC10 0220182D */  daddu     $v1, $s1, $zero
.L8026DC14:
/* 19C4F4 8026DC14 8CA200E0 */  lw        $v0, 0xe0($a1)
/* 19C4F8 8026DC18 50400006 */  beql      $v0, $zero, .L8026DC34
/* 19C4FC 8026DC1C 24840001 */   addiu    $a0, $a0, 1
/* 19C500 8026DC20 34820200 */  ori       $v0, $a0, 0x200
/* 19C504 8026DC24 A4620140 */  sh        $v0, 0x140($v1)
/* 19C508 8026DC28 24630002 */  addiu     $v1, $v1, 2
/* 19C50C 8026DC2C 256B0001 */  addiu     $t3, $t3, 1
/* 19C510 8026DC30 24840001 */  addiu     $a0, $a0, 1
.L8026DC34:
/* 19C514 8026DC34 28820018 */  slti      $v0, $a0, 0x18
/* 19C518 8026DC38 1440FFF6 */  bnez      $v0, .L8026DC14
/* 19C51C 8026DC3C 24A50004 */   addiu    $a1, $a1, 4
/* 19C520 8026DC40 A22B0171 */  sb        $t3, 0x171($s1)
/* 19C524 8026DC44 8E420078 */  lw        $v0, 0x78($s2)
/* 19C528 8026DC48 10400002 */  beqz      $v0, .L8026DC54
/* 19C52C 8026DC4C 240C03E8 */   addiu    $t4, $zero, 0x3e8
/* 19C530 8026DC50 240CFC18 */  addiu     $t4, $zero, -0x3e8
.L8026DC54:
/* 19C534 8026DC54 262E0140 */  addiu     $t6, $s1, 0x140
/* 19C538 8026DC58 2562FFFF */  addiu     $v0, $t3, -1
/* 19C53C 8026DC5C 1840005D */  blez      $v0, .L8026DDD4
/* 19C540 8026DC60 0000202D */   daddu    $a0, $zero, $zero
/* 19C544 8026DC64 0040782D */  daddu     $t7, $v0, $zero
/* 19C548 8026DC68 01C0682D */  daddu     $t5, $t6, $zero
.L8026DC6C:
/* 19C54C 8026DC6C 24880001 */  addiu     $t0, $a0, 1
/* 19C550 8026DC70 010B102A */  slt       $v0, $t0, $t3
/* 19C554 8026DC74 5040001D */  beql      $v0, $zero, .L8026DCEC
/* 19C558 8026DC78 24840001 */   addiu    $a0, $a0, 1
/* 19C55C 8026DC7C 01A0502D */  daddu     $t2, $t5, $zero
/* 19C560 8026DC80 00081040 */  sll       $v0, $t0, 1
/* 19C564 8026DC84 004E3821 */  addu      $a3, $v0, $t6
.L8026DC88:
/* 19C568 8026DC88 95490000 */  lhu       $t1, ($t2)
/* 19C56C 8026DC8C 312200FF */  andi      $v0, $t1, 0xff
/* 19C570 8026DC90 00021080 */  sll       $v0, $v0, 2
/* 19C574 8026DC94 02221021 */  addu      $v0, $s1, $v0
/* 19C578 8026DC98 8C4200E0 */  lw        $v0, 0xe0($v0)
/* 19C57C 8026DC9C 804501F1 */  lb        $a1, 0x1f1($v0)
/* 19C580 8026DCA0 50500001 */  beql      $v0, $s0, .L8026DCA8
/* 19C584 8026DCA4 00AC2821 */   addu     $a1, $a1, $t4
.L8026DCA8:
/* 19C588 8026DCA8 94E60000 */  lhu       $a2, ($a3)
/* 19C58C 8026DCAC 30C200FF */  andi      $v0, $a2, 0xff
/* 19C590 8026DCB0 00021080 */  sll       $v0, $v0, 2
/* 19C594 8026DCB4 02221021 */  addu      $v0, $s1, $v0
/* 19C598 8026DCB8 8C4200E0 */  lw        $v0, 0xe0($v0)
/* 19C59C 8026DCBC 804301F1 */  lb        $v1, 0x1f1($v0)
/* 19C5A0 8026DCC0 50500001 */  beql      $v0, $s0, .L8026DCC8
/* 19C5A4 8026DCC4 006C1821 */   addu     $v1, $v1, $t4
.L8026DCC8:
/* 19C5A8 8026DCC8 00A3102A */  slt       $v0, $a1, $v1
/* 19C5AC 8026DCCC 10400003 */  beqz      $v0, .L8026DCDC
/* 19C5B0 8026DCD0 25080001 */   addiu    $t0, $t0, 1
/* 19C5B4 8026DCD4 A5460000 */  sh        $a2, ($t2)
/* 19C5B8 8026DCD8 A4E90000 */  sh        $t1, ($a3)
.L8026DCDC:
/* 19C5BC 8026DCDC 010B102A */  slt       $v0, $t0, $t3
/* 19C5C0 8026DCE0 1440FFE9 */  bnez      $v0, .L8026DC88
/* 19C5C4 8026DCE4 24E70002 */   addiu    $a3, $a3, 2
/* 19C5C8 8026DCE8 24840001 */  addiu     $a0, $a0, 1
.L8026DCEC:
/* 19C5CC 8026DCEC 008F102A */  slt       $v0, $a0, $t7
/* 19C5D0 8026DCF0 1440FFDE */  bnez      $v0, .L8026DC6C
/* 19C5D4 8026DCF4 25AD0002 */   addiu    $t5, $t5, 2
/* 19C5D8 8026DCF8 0809B775 */  j         .L8026DDD4
/* 19C5DC 8026DCFC 00000000 */   nop
.L8026DD00:
/* 19C5E0 8026DD00 822B0171 */  lb        $t3, 0x171($s1)
/* 19C5E4 8026DD04 1960000D */  blez      $t3, .L8026DD3C
/* 19C5E8 8026DD08 0000202D */   daddu    $a0, $zero, $zero
/* 19C5EC 8026DD0C 2405FFFF */  addiu     $a1, $zero, -1
/* 19C5F0 8026DD10 01C0182D */  daddu     $v1, $t6, $zero
.L8026DD14:
/* 19C5F4 8026DD14 90620001 */  lbu       $v0, 1($v1)
/* 19C5F8 8026DD18 00021080 */  sll       $v0, $v0, 2
/* 19C5FC 8026DD1C 02221021 */  addu      $v0, $s1, $v0
/* 19C600 8026DD20 8C4200E0 */  lw        $v0, 0xe0($v0)
/* 19C604 8026DD24 50500001 */  beql      $v0, $s0, .L8026DD2C
/* 19C608 8026DD28 A4650000 */   sh       $a1, ($v1)
.L8026DD2C:
/* 19C60C 8026DD2C 24840001 */  addiu     $a0, $a0, 1
/* 19C610 8026DD30 008B102A */  slt       $v0, $a0, $t3
/* 19C614 8026DD34 1440FFF7 */  bnez      $v0, .L8026DD14
/* 19C618 8026DD38 24630002 */   addiu    $v1, $v1, 2
.L8026DD3C:
/* 19C61C 8026DD3C 8E420078 */  lw        $v0, 0x78($s2)
/* 19C620 8026DD40 1440001C */  bnez      $v0, .L8026DDB4
/* 19C624 8026DD44 0160202D */   daddu    $a0, $t3, $zero
/* 19C628 8026DD48 82220170 */  lb        $v0, 0x170($s1)
/* 19C62C 8026DD4C 0082102A */  slt       $v0, $a0, $v0
/* 19C630 8026DD50 1440000B */  bnez      $v0, .L8026DD80
/* 19C634 8026DD54 00041840 */   sll      $v1, $a0, 1
.L8026DD58:
/* 19C638 8026DD58 2484FFFF */  addiu     $a0, $a0, -1
/* 19C63C 8026DD5C 00041040 */  sll       $v0, $a0, 1
/* 19C640 8026DD60 02221021 */  addu      $v0, $s1, $v0
/* 19C644 8026DD64 94420140 */  lhu       $v0, 0x140($v0)
/* 19C648 8026DD68 02231821 */  addu      $v1, $s1, $v1
/* 19C64C 8026DD6C A4620140 */  sh        $v0, 0x140($v1)
/* 19C650 8026DD70 82220170 */  lb        $v0, 0x170($s1)
/* 19C654 8026DD74 0082102A */  slt       $v0, $a0, $v0
/* 19C658 8026DD78 1040FFF7 */  beqz      $v0, .L8026DD58
/* 19C65C 8026DD7C 00041840 */   sll      $v1, $a0, 1
.L8026DD80:
/* 19C660 8026DD80 82220170 */  lb        $v0, 0x170($s1)
/* 19C664 8026DD84 96030192 */  lhu       $v1, 0x192($s0)
/* 19C668 8026DD88 2442FFFF */  addiu     $v0, $v0, -1
/* 19C66C 8026DD8C 00021040 */  sll       $v0, $v0, 1
/* 19C670 8026DD90 02221021 */  addu      $v0, $s1, $v0
/* 19C674 8026DD94 A4430140 */  sh        $v1, 0x140($v0)
/* 19C678 8026DD98 92220171 */  lbu       $v0, 0x171($s1)
/* 19C67C 8026DD9C 92230170 */  lbu       $v1, 0x170($s1)
/* 19C680 8026DDA0 24420001 */  addiu     $v0, $v0, 1
/* 19C684 8026DDA4 24630001 */  addiu     $v1, $v1, 1
/* 19C688 8026DDA8 A2220171 */  sb        $v0, 0x171($s1)
/* 19C68C 8026DDAC 0809B775 */  j         .L8026DDD4
/* 19C690 8026DDB0 A2230170 */   sb       $v1, 0x170($s1)
.L8026DDB4:
/* 19C694 8026DDB4 82220171 */  lb        $v0, 0x171($s1)
/* 19C698 8026DDB8 96030192 */  lhu       $v1, 0x192($s0)
/* 19C69C 8026DDBC 00021040 */  sll       $v0, $v0, 1
/* 19C6A0 8026DDC0 02221021 */  addu      $v0, $s1, $v0
/* 19C6A4 8026DDC4 A4430140 */  sh        $v1, 0x140($v0)
/* 19C6A8 8026DDC8 92220171 */  lbu       $v0, 0x171($s1)
/* 19C6AC 8026DDCC 24420001 */  addiu     $v0, $v0, 1
/* 19C6B0 8026DDD0 A2220171 */  sb        $v0, 0x171($s1)
.L8026DDD4:
/* 19C6B4 8026DDD4 86030192 */  lh        $v1, 0x192($s0)
/* 19C6B8 8026DDD8 24020002 */  addiu     $v0, $zero, 2
/* 19C6BC 8026DDDC 0809B77A */  j         .L8026DDE8
/* 19C6C0 8026DDE0 AE430084 */   sw       $v1, 0x84($s2)
.L8026DDE4:
/* 19C6C4 8026DDE4 0000102D */  daddu     $v0, $zero, $zero
.L8026DDE8:
/* 19C6C8 8026DDE8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 19C6CC 8026DDEC 8FB20018 */  lw        $s2, 0x18($sp)
/* 19C6D0 8026DDF0 8FB10014 */  lw        $s1, 0x14($sp)
/* 19C6D4 8026DDF4 8FB00010 */  lw        $s0, 0x10($sp)
/* 19C6D8 8026DDF8 03E00008 */  jr        $ra
/* 19C6DC 8026DDFC 27BD0020 */   addiu    $sp, $sp, 0x20

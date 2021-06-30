.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_player_blink
/* 7947C 800DFFCC 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* 79480 800DFFD0 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* 79484 800DFFD4 3C048011 */  lui       $a0, %hi(D_8010EBB0)
/* 79488 800DFFD8 2484EBB0 */  addiu     $a0, $a0, %lo(D_8010EBB0)
/* 7948C 800DFFDC 80830003 */  lb        $v1, 3($a0)
/* 79490 800DFFE0 24020009 */  addiu     $v0, $zero, 9
/* 79494 800DFFE4 14620003 */  bne       $v1, $v0, .L800DFFF4
/* 79498 800DFFE8 0000302D */   daddu    $a2, $zero, $zero
/* 7949C 800DFFEC 80820000 */  lb        $v0, ($a0)
/* 794A0 800DFFF0 00C2302B */  sltu      $a2, $a2, $v0
.L800DFFF4:
/* 794A4 800DFFF4 84A20010 */  lh        $v0, 0x10($a1)
/* 794A8 800DFFF8 94A40010 */  lhu       $a0, 0x10($a1)
/* 794AC 800DFFFC 18400020 */  blez      $v0, .L800E0080
/* 794B0 800E0000 2482FFFF */   addiu    $v0, $a0, -1
/* 794B4 800E0004 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 794B8 800E0008 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 794BC 800E000C A4A20010 */  sh        $v0, 0x10($a1)
/* 794C0 800E0010 94620134 */  lhu       $v0, 0x134($v1)
/* 794C4 800E0014 30420001 */  andi      $v0, $v0, 1
/* 794C8 800E0018 14400005 */  bnez      $v0, .L800E0030
/* 794CC 800E001C 24A4000E */   addiu    $a0, $a1, 0xe
/* 794D0 800E0020 10C00004 */  beqz      $a2, .L800E0034
/* 794D4 800E0024 240300FF */   addiu    $v1, $zero, 0xff
/* 794D8 800E0028 0803800D */  j         .L800E0034
/* 794DC 800E002C 240300C0 */   addiu    $v1, $zero, 0xc0
.L800E0030:
/* 794E0 800E0030 24030060 */  addiu     $v1, $zero, 0x60
.L800E0034:
/* 794E4 800E0034 84A20010 */  lh        $v0, 0x10($a1)
/* 794E8 800E0038 1440000E */  bnez      $v0, .L800E0074
/* 794EC 800E003C A0830000 */   sb       $v1, ($a0)
/* 794F0 800E0040 10C00004 */  beqz      $a2, .L800E0054
/* 794F4 800E0044 24030080 */   addiu    $v1, $zero, 0x80
/* 794F8 800E0048 8CA20000 */  lw        $v0, ($a1)
/* 794FC 800E004C 0803801E */  j         .L800E0078
/* 79500 800E0050 A0A3000E */   sb       $v1, 0xe($a1)
.L800E0054:
/* 79504 800E0054 3C02FFFF */  lui       $v0, 0xffff
/* 79508 800E0058 34427FFF */  ori       $v0, $v0, 0x7fff
/* 7950C 800E005C 8CA30000 */  lw        $v1, ($a1)
/* 79510 800E0060 240400FF */  addiu     $a0, $zero, 0xff
/* 79514 800E0064 A0A4000E */  sb        $a0, 0xe($a1)
/* 79518 800E0068 00621824 */  and       $v1, $v1, $v0
/* 7951C 800E006C 03E00008 */  jr        $ra
/* 79520 800E0070 ACA30000 */   sw       $v1, ($a1)
.L800E0074:
/* 79524 800E0074 8CA20000 */  lw        $v0, ($a1)
.L800E0078:
/* 79528 800E0078 34428000 */  ori       $v0, $v0, 0x8000
/* 7952C 800E007C ACA20000 */  sw        $v0, ($a1)
.L800E0080:
/* 79530 800E0080 03E00008 */  jr        $ra
/* 79534 800E0084 00000000 */   nop

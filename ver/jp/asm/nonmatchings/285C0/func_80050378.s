.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050378
/* 2B778 80050378 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 2B77C 8005037C AFB00010 */  sw        $s0, 0x10($sp)
/* 2B780 80050380 00A0802D */  daddu     $s0, $a1, $zero
/* 2B784 80050384 AFB10014 */  sw        $s1, 0x14($sp)
/* 2B788 80050388 0000882D */  daddu     $s1, $zero, $zero
/* 2B78C 8005038C AFB20018 */  sw        $s2, 0x18($sp)
/* 2B790 80050390 0200902D */  daddu     $s2, $s0, $zero
/* 2B794 80050394 1080001C */  beqz      $a0, .L80050408
/* 2B798 80050398 AFBF001C */   sw       $ra, 0x1c($sp)
/* 2B79C 8005039C 0C013511 */  jal       func_8004D444
/* 2B7A0 800503A0 00000000 */   nop
/* 2B7A4 800503A4 0040282D */  daddu     $a1, $v0, $zero
/* 2B7A8 800503A8 10A00017 */  beqz      $a1, .L80050408
/* 2B7AC 800503AC 00000000 */   nop
/* 2B7B0 800503B0 8CA2016C */  lw        $v0, 0x16c($a1)
/* 2B7B4 800503B4 10500014 */  beq       $v0, $s0, .L80050408
/* 2B7B8 800503B8 324200FF */   andi     $v0, $s2, 0xff
/* 2B7BC 800503BC 90A30170 */  lbu       $v1, 0x170($a1)
/* 2B7C0 800503C0 10620003 */  beq       $v1, $v0, .L800503D0
/* 2B7C4 800503C4 ACB0016C */   sw       $s0, 0x16c($a1)
/* 2B7C8 800503C8 A0B00170 */  sb        $s0, 0x170($a1)
/* 2B7CC 800503CC 24110001 */  addiu     $s1, $zero, 1
.L800503D0:
/* 2B7D0 800503D0 00101602 */  srl       $v0, $s0, 0x18
/* 2B7D4 800503D4 3042007F */  andi      $v0, $v0, 0x7f
/* 2B7D8 800503D8 A0A20171 */  sb        $v0, 0x171($a1)
/* 2B7DC 800503DC 0000202D */  daddu     $a0, $zero, $zero
/* 2B7E0 800503E0 24060001 */  addiu     $a2, $zero, 1
/* 2B7E4 800503E4 2403025C */  addiu     $v1, $zero, 0x25c
.L800503E8:
/* 2B7E8 800503E8 12200002 */  beqz      $s1, .L800503F4
/* 2B7EC 800503EC 00A31021 */   addu     $v0, $a1, $v1
/* 2B7F0 800503F0 A046004D */  sb        $a2, 0x4d($v0)
.L800503F4:
/* 2B7F4 800503F4 A046004E */  sb        $a2, 0x4e($v0)
/* 2B7F8 800503F8 24840001 */  addiu     $a0, $a0, 1
/* 2B7FC 800503FC 28820010 */  slti      $v0, $a0, 0x10
/* 2B800 80050400 1440FFF9 */  bnez      $v0, .L800503E8
/* 2B804 80050404 24630060 */   addiu    $v1, $v1, 0x60
.L80050408:
/* 2B808 80050408 8FBF001C */  lw        $ra, 0x1c($sp)
/* 2B80C 8005040C 8FB20018 */  lw        $s2, 0x18($sp)
/* 2B810 80050410 8FB10014 */  lw        $s1, 0x14($sp)
/* 2B814 80050414 8FB00010 */  lw        $s0, 0x10($sp)
/* 2B818 80050418 03E00008 */  jr        $ra
/* 2B81C 8005041C 27BD0020 */   addiu    $sp, $sp, 0x20

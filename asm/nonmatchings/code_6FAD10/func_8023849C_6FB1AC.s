.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8023849C_6FB1AC
/* 6FB1AC 8023849C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 6FB1B0 802384A0 AFB10014 */  sw        $s1, 0x14($sp)
/* 6FB1B4 802384A4 0080882D */  daddu     $s1, $a0, $zero
/* 6FB1B8 802384A8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 6FB1BC 802384AC AFB00010 */  sw        $s0, 0x10($sp)
/* 6FB1C0 802384B0 8E22000C */  lw        $v0, 0xc($s1)
/* 6FB1C4 802384B4 8C450000 */  lw        $a1, ($v0)
/* 6FB1C8 802384B8 3C10800E */  lui       $s0, %hi(gBattleStatus+0xDC)
/* 6FB1CC 802384BC 8E10C14C */  lw        $s0, %lo(gBattleStatus+0xDC)($s0)
/* 6FB1D0 802384C0 0C0B1EAF */  jal       get_variable
/* 6FB1D4 802384C4 00000000 */   nop      
/* 6FB1D8 802384C8 8E030008 */  lw        $v1, 8($s0)
/* 6FB1DC 802384CC 0040282D */  daddu     $a1, $v0, $zero
/* 6FB1E0 802384D0 90630006 */  lbu       $v1, 6($v1)
/* 6FB1E4 802384D4 24020001 */  addiu     $v0, $zero, 1
/* 6FB1E8 802384D8 10620006 */  beq       $v1, $v0, .L802384F4
/* 6FB1EC 802384DC 0000202D */   daddu    $a0, $zero, $zero
/* 6FB1F0 802384E0 24020002 */  addiu     $v0, $zero, 2
/* 6FB1F4 802384E4 10620011 */  beq       $v1, $v0, .L8023852C
/* 6FB1F8 802384E8 28A20064 */   slti     $v0, $a1, 0x64
/* 6FB1FC 802384EC 0808E159 */  j         .L80238564
/* 6FB200 802384F0 00000000 */   nop      
.L802384F4:
/* 6FB204 802384F4 28A20024 */  slti      $v0, $a1, 0x24
/* 6FB208 802384F8 14400019 */  bnez      $v0, .L80238560
/* 6FB20C 802384FC 24040001 */   addiu    $a0, $zero, 1
/* 6FB210 80238500 28A2003D */  slti      $v0, $a1, 0x3d
/* 6FB214 80238504 14400016 */  bnez      $v0, .L80238560
/* 6FB218 80238508 24040003 */   addiu    $a0, $zero, 3
/* 6FB21C 8023850C 28A20051 */  slti      $v0, $a1, 0x51
/* 6FB220 80238510 14400013 */  bnez      $v0, .L80238560
/* 6FB224 80238514 24040004 */   addiu    $a0, $zero, 4
/* 6FB228 80238518 28A20064 */  slti      $v0, $a1, 0x64
/* 6FB22C 8023851C 10400011 */  beqz      $v0, .L80238564
/* 6FB230 80238520 24040006 */   addiu    $a0, $zero, 6
/* 6FB234 80238524 0808E159 */  j         .L80238564
/* 6FB238 80238528 24040005 */   addiu    $a0, $zero, 5
.L8023852C:
/* 6FB23C 8023852C 28A20024 */  slti      $v0, $a1, 0x24
/* 6FB240 80238530 1440000B */  bnez      $v0, .L80238560
/* 6FB244 80238534 24040001 */   addiu    $a0, $zero, 1
/* 6FB248 80238538 28A2003D */  slti      $v0, $a1, 0x3d
/* 6FB24C 8023853C 14400008 */  bnez      $v0, .L80238560
/* 6FB250 80238540 24040003 */   addiu    $a0, $zero, 3
/* 6FB254 80238544 28A20051 */  slti      $v0, $a1, 0x51
/* 6FB258 80238548 14400005 */  bnez      $v0, .L80238560
/* 6FB25C 8023854C 24040005 */   addiu    $a0, $zero, 5
/* 6FB260 80238550 28A20064 */  slti      $v0, $a1, 0x64
/* 6FB264 80238554 10400003 */  beqz      $v0, .L80238564
/* 6FB268 80238558 24040007 */   addiu    $a0, $zero, 7
/* 6FB26C 8023855C 24040006 */  addiu     $a0, $zero, 6
.L80238560:
/* 6FB270 80238560 28A20064 */  slti      $v0, $a1, 0x64
.L80238564:
/* 6FB274 80238564 54400003 */  bnel      $v0, $zero, .L80238574
/* 6FB278 80238568 AE200084 */   sw       $zero, 0x84($s1)
/* 6FB27C 8023856C 24020001 */  addiu     $v0, $zero, 1
/* 6FB280 80238570 AE220084 */  sw        $v0, 0x84($s1)
.L80238574:
/* 6FB284 80238574 AE2400C0 */  sw        $a0, 0xc0($s1)
/* 6FB288 80238578 8FBF0018 */  lw        $ra, 0x18($sp)
/* 6FB28C 8023857C 8FB10014 */  lw        $s1, 0x14($sp)
/* 6FB290 80238580 8FB00010 */  lw        $s0, 0x10($sp)
/* 6FB294 80238584 24020002 */  addiu     $v0, $zero, 2
/* 6FB298 80238588 03E00008 */  jr        $ra
/* 6FB29C 8023858C 27BD0020 */   addiu    $sp, $sp, 0x20

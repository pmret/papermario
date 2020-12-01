.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802424CC_A3B9AC
/* A3B9AC 802424CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A3B9B0 802424D0 0000282D */  daddu     $a1, $zero, $zero
/* A3B9B4 802424D4 00A0302D */  daddu     $a2, $a1, $zero
/* A3B9B8 802424D8 3C038024 */  lui       $v1, %hi(D_80245EEC)
/* A3B9BC 802424DC 24635EEC */  addiu     $v1, $v1, %lo(D_80245EEC)
/* A3B9C0 802424E0 AFBF0010 */  sw        $ra, 0x10($sp)
/* A3B9C4 802424E4 8C840084 */  lw        $a0, 0x84($a0)
.L802424E8:
/* A3B9C8 802424E8 8C620000 */  lw        $v0, ($v1)
/* A3B9CC 802424EC 54820003 */  bnel      $a0, $v0, .L802424FC
/* A3B9D0 802424F0 24C60001 */   addiu    $a2, $a2, 1
/* A3B9D4 802424F4 08090942 */  j         .L80242508
/* A3B9D8 802424F8 24050001 */   addiu    $a1, $zero, 1
.L802424FC:
/* A3B9DC 802424FC 28C20005 */  slti      $v0, $a2, 5
/* A3B9E0 80242500 1440FFF9 */  bnez      $v0, .L802424E8
/* A3B9E4 80242504 24630004 */   addiu    $v1, $v1, 4
.L80242508:
/* A3B9E8 80242508 10A00006 */  beqz      $a1, .L80242524
/* A3B9EC 8024250C 3C05F840 */   lui      $a1, 0xf840
/* A3B9F0 80242510 34A55D6E */  ori       $a1, $a1, 0x5d6e
/* A3B9F4 80242514 0000202D */  daddu     $a0, $zero, $zero
/* A3B9F8 80242518 00C52821 */  addu      $a1, $a2, $a1
/* A3B9FC 8024251C 0C0B2026 */  jal       set_variable
/* A3BA00 80242520 24060001 */   addiu    $a2, $zero, 1
.L80242524:
/* A3BA04 80242524 8FBF0010 */  lw        $ra, 0x10($sp)
/* A3BA08 80242528 24020002 */  addiu     $v0, $zero, 2
/* A3BA0C 8024252C 03E00008 */  jr        $ra
/* A3BA10 80242530 27BD0018 */   addiu    $sp, $sp, 0x18

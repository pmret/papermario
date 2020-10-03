.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8014AC94
/* E1394 8014AC94 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E1398 8014AC98 3C048015 */  lui       $a0, 0x8015
/* E139C 8014AC9C 2484F738 */  addiu     $a0, $a0, -0x8c8
/* E13A0 8014ACA0 AFBF0010 */  sw        $ra, 0x10($sp)
/* E13A4 8014ACA4 84820000 */  lh        $v0, ($a0)
/* E13A8 8014ACA8 94830000 */  lhu       $v1, ($a0)
/* E13AC 8014ACAC 10400003 */  beqz      $v0, .L8014ACBC
/* E13B0 8014ACB0 2462FFFF */   addiu    $v0, $v1, -1
/* E13B4 8014ACB4 08052B4D */  j         .L8014AD34
/* E13B8 8014ACB8 A4820000 */   sh       $v0, ($a0)
.L8014ACBC:
/* E13BC 8014ACBC 3C038016 */  lui       $v1, %hi(D_80159AE2)
/* E13C0 8014ACC0 84639AE2 */  lh        $v1, %lo(D_80159AE2)($v1)
/* E13C4 8014ACC4 3C028016 */  lui       $v0, %hi(D_80159AE4)
/* E13C8 8014ACC8 84429AE4 */  lh        $v0, %lo(D_80159AE4)($v0)
/* E13CC 8014ACCC 3C048016 */  lui       $a0, %hi(D_80159AE2)
/* E13D0 8014ACD0 94849AE2 */  lhu       $a0, %lo(D_80159AE2)($a0)
/* E13D4 8014ACD4 0043102A */  slt       $v0, $v0, $v1
/* E13D8 8014ACD8 3C038016 */  lui       $v1, %hi(D_80159AE4)
/* E13DC 8014ACDC 94639AE4 */  lhu       $v1, %lo(D_80159AE4)($v1)
/* E13E0 8014ACE0 54400001 */  bnel      $v0, $zero, .L8014ACE8
/* E13E4 8014ACE4 0060202D */   daddu    $a0, $v1, $zero
.L8014ACE8:
/* E13E8 8014ACE8 3C058016 */  lui       $a1, 0x8016
/* E13EC 8014ACEC 24A59AE6 */  addiu     $a1, $a1, -0x651a
/* E13F0 8014ACF0 00041400 */  sll       $v0, $a0, 0x10
/* E13F4 8014ACF4 00022403 */  sra       $a0, $v0, 0x10
/* E13F8 8014ACF8 84A20000 */  lh        $v0, ($a1)
/* E13FC 8014ACFC 94A30000 */  lhu       $v1, ($a1)
/* E1400 8014AD00 1044000C */  beq       $v0, $a0, .L8014AD34
/* E1404 8014AD04 0044102A */   slt      $v0, $v0, $a0
/* E1408 8014AD08 14400002 */  bnez      $v0, .L8014AD14
/* E140C 8014AD0C 24620001 */   addiu    $v0, $v1, 1
/* E1410 8014AD10 2462FFFF */  addiu     $v0, $v1, -1
.L8014AD14:
/* E1414 8014AD14 A4A20000 */  sh        $v0, ($a1)
/* E1418 8014AD18 3C048016 */  lui       $a0, 0x8016
/* E141C 8014AD1C 84849AE6 */  lh        $a0, -0x651a($a0)
/* E1420 8014AD20 0C015869 */  jal       func_800561A4
/* E1424 8014AD24 00000000 */   nop      
/* E1428 8014AD28 24020003 */  addiu     $v0, $zero, 3
/* E142C 8014AD2C 3C018015 */  lui       $at, 0x8015
/* E1430 8014AD30 A422F738 */  sh        $v0, -0x8c8($at)
.L8014AD34:
/* E1434 8014AD34 8FBF0010 */  lw        $ra, 0x10($sp)
/* E1438 8014AD38 03E00008 */  jr        $ra
/* E143C 8014AD3C 27BD0018 */   addiu    $sp, $sp, 0x18

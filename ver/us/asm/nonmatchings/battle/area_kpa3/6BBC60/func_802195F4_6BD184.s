.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802195F4_6BD184
/* 6BD184 802195F4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6BD188 802195F8 AFB00010 */  sw        $s0, 0x10($sp)
/* 6BD18C 802195FC 0080802D */  daddu     $s0, $a0, $zero
/* 6BD190 80219600 AFBF0014 */  sw        $ra, 0x14($sp)
/* 6BD194 80219604 8E02000C */  lw        $v0, 0xc($s0)
/* 6BD198 80219608 0C0B1EAF */  jal       evt_get_variable
/* 6BD19C 8021960C 8C450000 */   lw       $a1, ($v0)
/* 6BD1A0 80219610 8E040148 */  lw        $a0, 0x148($s0)
/* 6BD1A4 80219614 0C09A75B */  jal       get_actor
/* 6BD1A8 80219618 0040802D */   daddu    $s0, $v0, $zero
/* 6BD1AC 8021961C 0040182D */  daddu     $v1, $v0, $zero
/* 6BD1B0 80219620 2610FFFF */  addiu     $s0, $s0, -1
/* 6BD1B4 80219624 2E020009 */  sltiu     $v0, $s0, 9
/* 6BD1B8 80219628 1040001E */  beqz      $v0, L802196A4_6BD234
/* 6BD1BC 8021962C 0000202D */   daddu    $a0, $zero, $zero
/* 6BD1C0 80219630 00101080 */  sll       $v0, $s0, 2
/* 6BD1C4 80219634 3C018023 */  lui       $at, %hi(jtbl_80228450_6CBFE0)
/* 6BD1C8 80219638 00220821 */  addu      $at, $at, $v0
/* 6BD1CC 8021963C 8C228450 */  lw        $v0, %lo(jtbl_80228450_6CBFE0)($at)
/* 6BD1D0 80219640 00400008 */  jr        $v0
/* 6BD1D4 80219644 00000000 */   nop
glabel L80219648_6BD1D8
/* 6BD1D8 80219648 3C048022 */  lui       $a0, %hi(D_8021E990_6C2520)
/* 6BD1DC 8021964C 080865A9 */  j         L802196A4_6BD234
/* 6BD1E0 80219650 2484E990 */   addiu    $a0, $a0, %lo(D_8021E990_6C2520)
glabel L80219654_6BD1E4
/* 6BD1E4 80219654 3C048022 */  lui       $a0, %hi(D_80220644_6C41D4)
/* 6BD1E8 80219658 080865A9 */  j         L802196A4_6BD234
/* 6BD1EC 8021965C 24840644 */   addiu    $a0, $a0, %lo(D_80220644_6C41D4)
glabel L80219660_6BD1F0
/* 6BD1F0 80219660 3C048022 */  lui       $a0, %hi(D_802218A4_6C5434)
/* 6BD1F4 80219664 080865A9 */  j         L802196A4_6BD234
/* 6BD1F8 80219668 248418A4 */   addiu    $a0, $a0, %lo(D_802218A4_6C5434)
glabel L8021966C_6BD1FC
/* 6BD1FC 8021966C 3C048022 */  lui       $a0, %hi(D_80222830_6C63C0)
/* 6BD200 80219670 080865A9 */  j         L802196A4_6BD234
/* 6BD204 80219674 24842830 */   addiu    $a0, $a0, %lo(D_80222830_6C63C0)
glabel L80219678_6BD208
/* 6BD208 80219678 3C048022 */  lui       $a0, %hi(D_80223C00_6C7790)
/* 6BD20C 8021967C 080865A9 */  j         L802196A4_6BD234
/* 6BD210 80219680 24843C00 */   addiu    $a0, $a0, %lo(D_80223C00_6C7790)
glabel L80219684_6BD214
/* 6BD214 80219684 3C048022 */  lui       $a0, %hi(D_80224AFC_6C868C)
/* 6BD218 80219688 080865A9 */  j         L802196A4_6BD234
/* 6BD21C 8021968C 24844AFC */   addiu    $a0, $a0, %lo(D_80224AFC_6C868C)
glabel L80219690_6BD220
/* 6BD220 80219690 3C048022 */  lui       $a0, %hi(D_80226494_6CA024)
/* 6BD224 80219694 080865A9 */  j         L802196A4_6BD234
/* 6BD228 80219698 24846494 */   addiu    $a0, $a0, %lo(D_80226494_6CA024)
glabel L8021969C_6BD22C
/* 6BD22C 8021969C 3C048022 */  lui       $a0, %hi(D_80227734_6CB2C4)
/* 6BD230 802196A0 24847734 */  addiu     $a0, $a0, %lo(D_80227734_6CB2C4)
glabel L802196A4_6BD234
/* 6BD234 802196A4 806301F1 */  lb        $v1, 0x1f1($v1)
/* 6BD238 802196A8 AC830008 */  sw        $v1, 8($a0)
/* 6BD23C 802196AC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 6BD240 802196B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 6BD244 802196B4 24020002 */  addiu     $v0, $zero, 2
/* 6BD248 802196B8 03E00008 */  jr        $ra
/* 6BD24C 802196BC 27BD0018 */   addiu    $sp, $sp, 0x18

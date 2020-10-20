.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240360_B2C7D0
/* B2C7D0 80240360 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B2C7D4 80240364 AFB00010 */  sw        $s0, 0x10($sp)
/* B2C7D8 80240368 3C108024 */  lui       $s0, 0x8024
/* B2C7DC 8024036C 26102BD8 */  addiu     $s0, $s0, 0x2bd8
/* B2C7E0 80240370 AFBF0014 */  sw        $ra, 0x14($sp)
/* B2C7E4 80240374 8E020000 */  lw        $v0, ($s0)
/* B2C7E8 80240378 3C038016 */  lui       $v1, 0x8016
/* B2C7EC 8024037C 9463A552 */  lhu       $v1, -0x5aae($v1)
/* B2C7F0 80240380 1040000C */  beqz      $v0, .L802403B4
/* B2C7F4 80240384 2402000A */   addiu    $v0, $zero, 0xa
/* B2C7F8 80240388 3063FFFF */  andi      $v1, $v1, 0xffff
/* B2C7FC 8024038C 10620003 */  beq       $v1, $v0, .L8024039C
/* B2C800 80240390 2402000D */   addiu    $v0, $zero, 0xd
/* B2C804 80240394 14620013 */  bne       $v1, $v0, .L802403E4
/* B2C808 80240398 00000000 */   nop      
.L8024039C:
/* B2C80C 8024039C 24040009 */  addiu     $a0, $zero, 9
/* B2C810 802403A0 24050002 */  addiu     $a1, $zero, 2
/* B2C814 802403A4 0C046DF0 */  jal       func_8011B7C0
/* B2C818 802403A8 0000302D */   daddu    $a2, $zero, $zero
/* B2C81C 802403AC 080900F9 */  j         .L802403E4
/* B2C820 802403B0 AE000000 */   sw       $zero, ($s0)
.L802403B4:
/* B2C824 802403B4 3063FFFF */  andi      $v1, $v1, 0xffff
/* B2C828 802403B8 2402002E */  addiu     $v0, $zero, 0x2e
/* B2C82C 802403BC 10620003 */  beq       $v1, $v0, .L802403CC
/* B2C830 802403C0 2402002B */   addiu    $v0, $zero, 0x2b
/* B2C834 802403C4 14620007 */  bne       $v1, $v0, .L802403E4
/* B2C838 802403C8 00000000 */   nop      
.L802403CC:
/* B2C83C 802403CC 24040009 */  addiu     $a0, $zero, 9
/* B2C840 802403D0 24050002 */  addiu     $a1, $zero, 2
/* B2C844 802403D4 0C046DF0 */  jal       func_8011B7C0
/* B2C848 802403D8 24060001 */   addiu    $a2, $zero, 1
/* B2C84C 802403DC 24020001 */  addiu     $v0, $zero, 1
/* B2C850 802403E0 AE020000 */  sw        $v0, ($s0)
.L802403E4:
/* B2C854 802403E4 8FBF0014 */  lw        $ra, 0x14($sp)
/* B2C858 802403E8 8FB00010 */  lw        $s0, 0x10($sp)
/* B2C85C 802403EC 0000102D */  daddu     $v0, $zero, $zero
/* B2C860 802403F0 03E00008 */  jr        $ra
/* B2C864 802403F4 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242380_9D93A0
/* 9D93A0 80242380 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9D93A4 80242384 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9D93A8 80242388 8C82000C */  lw        $v0, 0xc($a0)
/* 9D93AC 8024238C 0C0B1EAF */  jal       get_variable
/* 9D93B0 80242390 8C450000 */   lw       $a1, ($v0)
/* 9D93B4 80242394 0040202D */  daddu     $a0, $v0, $zero
/* 9D93B8 80242398 3C028025 */  lui       $v0, %hi(func_802549C0)
/* 9D93BC 8024239C 8C4249C0 */  lw        $v0, %lo(func_802549C0)($v0)
/* 9D93C0 802423A0 24030001 */  addiu     $v1, $zero, 1
/* 9D93C4 802423A4 8C45000C */  lw        $a1, 0xc($v0)
/* 9D93C8 802423A8 1083000D */  beq       $a0, $v1, .L802423E0
/* 9D93CC 802423AC 28820002 */   slti     $v0, $a0, 2
/* 9D93D0 802423B0 10400005 */  beqz      $v0, .L802423C8
/* 9D93D4 802423B4 24020002 */   addiu    $v0, $zero, 2
/* 9D93D8 802423B8 10800007 */  beqz      $a0, .L802423D8
/* 9D93DC 802423BC 240200C0 */   addiu    $v0, $zero, 0xc0
/* 9D93E0 802423C0 080908FC */  j         .L802423F0
/* 9D93E4 802423C4 ACA00038 */   sw       $zero, 0x38($a1)
.L802423C8:
/* 9D93E8 802423C8 10820008 */  beq       $a0, $v0, .L802423EC
/* 9D93EC 802423CC 24020040 */   addiu    $v0, $zero, 0x40
/* 9D93F0 802423D0 080908FC */  j         .L802423F0
/* 9D93F4 802423D4 ACA00038 */   sw       $zero, 0x38($a1)
.L802423D8:
/* 9D93F8 802423D8 080908FC */  j         .L802423F0
/* 9D93FC 802423DC ACA20038 */   sw       $v0, 0x38($a1)
.L802423E0:
/* 9D9400 802423E0 24020080 */  addiu     $v0, $zero, 0x80
/* 9D9404 802423E4 080908FC */  j         .L802423F0
/* 9D9408 802423E8 ACA20038 */   sw       $v0, 0x38($a1)
.L802423EC:
/* 9D940C 802423EC ACA20038 */  sw        $v0, 0x38($a1)
.L802423F0:
/* 9D9410 802423F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9D9414 802423F4 24020002 */  addiu     $v0, $zero, 2
/* 9D9418 802423F8 03E00008 */  jr        $ra
/* 9D941C 802423FC 27BD0018 */   addiu    $sp, $sp, 0x18

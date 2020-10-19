.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C20_872650
/* 872650 80240C20 3C038016 */  lui       $v1, 0x8016
/* 872654 80240C24 8463A552 */  lh        $v1, -0x5aae($v1)
/* 872658 80240C28 24020009 */  addiu     $v0, $zero, 9
/* 87265C 80240C2C 10620003 */  beq       $v1, $v0, .L80240C3C
/* 872660 80240C30 2402000B */   addiu    $v0, $zero, 0xb
/* 872664 80240C34 1462000B */  bne       $v1, $v0, .L80240C64
/* 872668 80240C38 00000000 */   nop      
.L80240C3C:
/* 87266C 80240C3C 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 872670 80240C40 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 872674 80240C44 804300B4 */  lb        $v1, 0xb4($v0)
/* 872678 80240C48 2402000E */  addiu     $v0, $zero, 0xe
/* 87267C 80240C4C 10620003 */  beq       $v1, $v0, .L80240C5C
/* 872680 80240C50 24020010 */   addiu    $v0, $zero, 0x10
/* 872684 80240C54 14620003 */  bne       $v1, $v0, .L80240C64
/* 872688 80240C58 00000000 */   nop      
.L80240C5C:
/* 87268C 80240C5C 03E00008 */  jr        $ra
/* 872690 80240C60 0000102D */   daddu    $v0, $zero, $zero
.L80240C64:
/* 872694 80240C64 03E00008 */  jr        $ra
/* 872698 80240C68 24020002 */   addiu    $v0, $zero, 2
/* 87269C 80240C6C 00000000 */  nop       

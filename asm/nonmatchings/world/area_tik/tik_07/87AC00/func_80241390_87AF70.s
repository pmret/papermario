.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241390_87AF70
/* 87AF70 80241390 3C088011 */  lui       $t0, %hi(gPlayerStatus)
/* 87AF74 80241394 2508EFC8 */  addiu     $t0, $t0, %lo(gPlayerStatus)
/* 87AF78 80241398 0000202D */  daddu     $a0, $zero, $zero
/* 87AF7C 8024139C 3C058016 */  lui       $a1, %hi(gCollisionStatus+0x2)
/* 87AF80 802413A0 84A5A552 */  lh        $a1, %lo(gCollisionStatus+0x2)($a1)
/* 87AF84 802413A4 2407000E */  addiu     $a3, $zero, 0xe
/* 87AF88 802413A8 24060010 */  addiu     $a2, $zero, 0x10
/* 87AF8C 802413AC 3C038024 */  lui       $v1, %hi(D_802449B0_87E590)
/* 87AF90 802413B0 246349B0 */  addiu     $v1, $v1, %lo(D_802449B0_87E590)
.L802413B4:
/* 87AF94 802413B4 8C620000 */  lw        $v0, ($v1)
/* 87AF98 802413B8 54A20008 */  bnel      $a1, $v0, .L802413DC
/* 87AF9C 802413BC 24840001 */   addiu    $a0, $a0, 1
/* 87AFA0 802413C0 810200B4 */  lb        $v0, 0xb4($t0)
/* 87AFA4 802413C4 10470003 */  beq       $v0, $a3, .L802413D4
/* 87AFA8 802413C8 00000000 */   nop
/* 87AFAC 802413CC 14460003 */  bne       $v0, $a2, .L802413DC
/* 87AFB0 802413D0 24840001 */   addiu    $a0, $a0, 1
.L802413D4:
/* 87AFB4 802413D4 03E00008 */  jr        $ra
/* 87AFB8 802413D8 0000102D */   daddu    $v0, $zero, $zero
.L802413DC:
/* 87AFBC 802413DC 2C820004 */  sltiu     $v0, $a0, 4
/* 87AFC0 802413E0 1440FFF4 */  bnez      $v0, .L802413B4
/* 87AFC4 802413E4 24630004 */   addiu    $v1, $v1, 4
/* 87AFC8 802413E8 03E00008 */  jr        $ra
/* 87AFCC 802413EC 24020002 */   addiu    $v0, $zero, 2

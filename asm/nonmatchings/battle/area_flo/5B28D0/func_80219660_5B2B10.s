.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219660_5B2B10
/* 5B2B10 80219660 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 5B2B14 80219664 AFB20020 */  sw        $s2, 0x20($sp)
/* 5B2B18 80219668 0000902D */  daddu     $s2, $zero, $zero
/* 5B2B1C 8021966C AFB1001C */  sw        $s1, 0x1c($sp)
/* 5B2B20 80219670 0240882D */  daddu     $s1, $s2, $zero
/* 5B2B24 80219674 AFB30024 */  sw        $s3, 0x24($sp)
/* 5B2B28 80219678 3C138009 */  lui       $s3, %hi(gAreas)
/* 5B2B2C 8021967C 267334F0 */  addiu     $s3, $s3, %lo(gAreas)
/* 5B2B30 80219680 AFB00018 */  sw        $s0, 0x18($sp)
/* 5B2B34 80219684 3C108023 */  lui       $s0, %hi(D_80231FA8)
/* 5B2B38 80219688 26101FA8 */  addiu     $s0, $s0, %lo(D_80231FA8)
/* 5B2B3C 8021968C AFBF0028 */  sw        $ra, 0x28($sp)
.L80219690:
/* 5B2B40 80219690 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 5B2B44 80219694 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 5B2B48 80219698 8E050000 */  lw        $a1, ($s0)
/* 5B2B4C 8021969C 84430086 */  lh        $v1, 0x86($v0)
/* 5B2B50 802196A0 8442008C */  lh        $v0, 0x8c($v0)
/* 5B2B54 802196A4 00031900 */  sll       $v1, $v1, 4
/* 5B2B58 802196A8 00731821 */  addu      $v1, $v1, $s3
/* 5B2B5C 802196AC 8C630004 */  lw        $v1, 4($v1)
/* 5B2B60 802196B0 00021140 */  sll       $v0, $v0, 5
/* 5B2B64 802196B4 00431021 */  addu      $v0, $v0, $v1
/* 5B2B68 802196B8 0C01BB5C */  jal       strcmp
/* 5B2B6C 802196BC 8C440000 */   lw       $a0, ($v0)
/* 5B2B70 802196C0 14400003 */  bnez      $v0, .L802196D0
/* 5B2B74 802196C4 26310001 */   addiu    $s1, $s1, 1
/* 5B2B78 802196C8 080865B7 */  j         .L802196DC
/* 5B2B7C 802196CC 24120001 */   addiu    $s2, $zero, 1
.L802196D0:
/* 5B2B80 802196D0 2E22000B */  sltiu     $v0, $s1, 0xb
/* 5B2B84 802196D4 1440FFEE */  bnez      $v0, .L80219690
/* 5B2B88 802196D8 26100004 */   addiu    $s0, $s0, 4
.L802196DC:
/* 5B2B8C 802196DC 44800000 */  mtc1      $zero, $f0
/* 5B2B90 802196E0 00000000 */  nop
/* 5B2B94 802196E4 44050000 */  mfc1      $a1, $f0
/* 5B2B98 802196E8 0240202D */  daddu     $a0, $s2, $zero
/* 5B2B9C 802196EC AFA00014 */  sw        $zero, 0x14($sp)
/* 5B2BA0 802196F0 00A0302D */  daddu     $a2, $a1, $zero
/* 5B2BA4 802196F4 00A0382D */  daddu     $a3, $a1, $zero
/* 5B2BA8 802196F8 0C01CA54 */  jal       func_80072950
/* 5B2BAC 802196FC AFA50010 */   sw       $a1, 0x10($sp)
/* 5B2BB0 80219700 8FBF0028 */  lw        $ra, 0x28($sp)
/* 5B2BB4 80219704 8FB30024 */  lw        $s3, 0x24($sp)
/* 5B2BB8 80219708 8FB20020 */  lw        $s2, 0x20($sp)
/* 5B2BBC 8021970C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 5B2BC0 80219710 8FB00018 */  lw        $s0, 0x18($sp)
/* 5B2BC4 80219714 24020002 */  addiu     $v0, $zero, 2
/* 5B2BC8 80219718 03E00008 */  jr        $ra
/* 5B2BCC 8021971C 27BD0030 */   addiu    $sp, $sp, 0x30

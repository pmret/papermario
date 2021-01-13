.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024064C_CC147C
/* CC147C 8024064C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CC1480 80240650 AFBF0010 */  sw        $ra, 0x10($sp)
/* CC1484 80240654 8C82000C */  lw        $v0, 0xc($a0)
/* CC1488 80240658 0C0B1EAF */  jal       get_variable
/* CC148C 8024065C 8C450000 */   lw       $a1, ($v0)
/* CC1490 80240660 0040182D */  daddu     $v1, $v0, $zero
/* CC1494 80240664 10600012 */  beqz      $v1, .L802406B0
/* CC1498 80240668 0000202D */   daddu    $a0, $zero, $zero
/* CC149C 8024066C 8C620000 */  lw        $v0, ($v1)
/* CC14A0 80240670 5040000A */  beql      $v0, $zero, .L8024069C
/* CC14A4 80240674 00041080 */   sll      $v0, $a0, 2
/* CC14A8 80240678 3C058024 */  lui       $a1, %hi(D_802429E0)
/* CC14AC 8024067C 24A529E0 */  addiu     $a1, $a1, %lo(D_802429E0)
.L80240680:
/* CC14B0 80240680 24630004 */  addiu     $v1, $v1, 4
/* CC14B4 80240684 24840001 */  addiu     $a0, $a0, 1
/* CC14B8 80240688 ACA20000 */  sw        $v0, ($a1)
/* CC14BC 8024068C 8C620000 */  lw        $v0, ($v1)
/* CC14C0 80240690 1440FFFB */  bnez      $v0, .L80240680
/* CC14C4 80240694 24A50004 */   addiu    $a1, $a1, 4
/* CC14C8 80240698 00041080 */  sll       $v0, $a0, 2
.L8024069C:
/* CC14CC 8024069C 3C018024 */  lui       $at, %hi(D_802429E0)
/* CC14D0 802406A0 00220821 */  addu      $at, $at, $v0
/* CC14D4 802406A4 AC2029E0 */  sw        $zero, %lo(D_802429E0)($at)
/* CC14D8 802406A8 080901B6 */  j         .L802406D8
/* CC14DC 802406AC 00000000 */   nop
.L802406B0:
/* CC14E0 802406B0 3C038024 */  lui       $v1, %hi(D_802429E0)
/* CC14E4 802406B4 246329E0 */  addiu     $v1, $v1, %lo(D_802429E0)
/* CC14E8 802406B8 0060282D */  daddu     $a1, $v1, $zero
.L802406BC:
/* CC14EC 802406BC 24820010 */  addiu     $v0, $a0, 0x10
/* CC14F0 802406C0 AC620000 */  sw        $v0, ($v1)
/* CC14F4 802406C4 24630004 */  addiu     $v1, $v1, 4
/* CC14F8 802406C8 24840001 */  addiu     $a0, $a0, 1
/* CC14FC 802406CC 28820070 */  slti      $v0, $a0, 0x70
/* CC1500 802406D0 1440FFFA */  bnez      $v0, .L802406BC
/* CC1504 802406D4 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L802406D8:
/* CC1508 802406D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* CC150C 802406DC 24020002 */  addiu     $v0, $zero, 2
/* CC1510 802406E0 03E00008 */  jr        $ra
/* CC1514 802406E4 27BD0018 */   addiu    $sp, $sp, 0x18
/* CC1518 802406E8 00000000 */  nop
/* CC151C 802406EC 00000000 */  nop

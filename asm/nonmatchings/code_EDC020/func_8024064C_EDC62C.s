.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024064C_EDC62C
/* EDC62C 8024064C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EDC630 80240650 AFBF0010 */  sw        $ra, 0x10($sp)
/* EDC634 80240654 8C82000C */  lw        $v0, 0xc($a0)
/* EDC638 80240658 0C0B53A3 */  jal       func_802D4E8C
/* EDC63C 8024065C 8C450000 */   lw       $a1, ($v0)
/* EDC640 80240660 0040182D */  daddu     $v1, $v0, $zero
/* EDC644 80240664 10600012 */  beqz      $v1, .L802406B0
/* EDC648 80240668 0000202D */   daddu    $a0, $zero, $zero
/* EDC64C 8024066C 8C620000 */  lw        $v0, ($v1)
/* EDC650 80240670 5040000A */  beql      $v0, $zero, .L8024069C
/* EDC654 80240674 00041080 */   sll      $v0, $a0, 2
/* EDC658 80240678 3C058024 */  lui       $a1, %hi(D_802429E0)
/* EDC65C 8024067C 24A529E0 */  addiu     $a1, $a1, %lo(D_802429E0)
.L80240680:
/* EDC660 80240680 24630004 */  addiu     $v1, $v1, 4
/* EDC664 80240684 24840001 */  addiu     $a0, $a0, 1
/* EDC668 80240688 ACA20000 */  sw        $v0, ($a1)
/* EDC66C 8024068C 8C620000 */  lw        $v0, ($v1)
/* EDC670 80240690 1440FFFB */  bnez      $v0, .L80240680
/* EDC674 80240694 24A50004 */   addiu    $a1, $a1, 4
/* EDC678 80240698 00041080 */  sll       $v0, $a0, 2
.L8024069C:
/* EDC67C 8024069C 3C018024 */  lui       $at, %hi(D_802429E0)
/* EDC680 802406A0 00220821 */  addu      $at, $at, $v0
/* EDC684 802406A4 AC2029E0 */  sw        $zero, %lo(D_802429E0)($at)
/* EDC688 802406A8 080901B6 */  j         .L802406D8
/* EDC68C 802406AC 00000000 */   nop      
.L802406B0:
/* EDC690 802406B0 3C038024 */  lui       $v1, %hi(D_802429E0)
/* EDC694 802406B4 246329E0 */  addiu     $v1, $v1, %lo(D_802429E0)
/* EDC698 802406B8 0060282D */  daddu     $a1, $v1, $zero
.L802406BC:
/* EDC69C 802406BC 24820010 */  addiu     $v0, $a0, 0x10
/* EDC6A0 802406C0 AC620000 */  sw        $v0, ($v1)
/* EDC6A4 802406C4 24630004 */  addiu     $v1, $v1, 4
/* EDC6A8 802406C8 24840001 */  addiu     $a0, $a0, 1
/* EDC6AC 802406CC 28820070 */  slti      $v0, $a0, 0x70
/* EDC6B0 802406D0 1440FFFA */  bnez      $v0, .L802406BC
/* EDC6B4 802406D4 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L802406D8:
/* EDC6B8 802406D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* EDC6BC 802406DC 24020002 */  addiu     $v0, $zero, 2
/* EDC6C0 802406E0 03E00008 */  jr        $ra
/* EDC6C4 802406E4 27BD0018 */   addiu    $sp, $sp, 0x18
/* EDC6C8 802406E8 00000000 */  nop       
/* EDC6CC 802406EC 00000000 */  nop       

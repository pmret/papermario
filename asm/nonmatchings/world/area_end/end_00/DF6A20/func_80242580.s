.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242580
/* DF8F80 80242580 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DF8F84 80242584 AFB10014 */  sw        $s1, 0x14($sp)
/* DF8F88 80242588 0080882D */  daddu     $s1, $a0, $zero
/* DF8F8C 8024258C AFBF001C */  sw        $ra, 0x1c($sp)
/* DF8F90 80242590 AFB20018 */  sw        $s2, 0x18($sp)
/* DF8F94 80242594 AFB00010 */  sw        $s0, 0x10($sp)
/* DF8F98 80242598 8E22000C */  lw        $v0, 0xc($s1)
/* DF8F9C 8024259C 00A0802D */  daddu     $s0, $a1, $zero
/* DF8FA0 802425A0 0C0B1EAF */  jal       get_variable
/* DF8FA4 802425A4 8C450000 */   lw       $a1, ($v0)
/* DF8FA8 802425A8 12000005 */  beqz      $s0, .L802425C0
/* DF8FAC 802425AC 0040902D */   daddu    $s2, $v0, $zero
/* DF8FB0 802425B0 2402FFFF */  addiu     $v0, $zero, -1
/* DF8FB4 802425B4 AE200084 */  sw        $zero, 0x84($s1)
/* DF8FB8 802425B8 AE220088 */  sw        $v0, 0x88($s1)
/* DF8FBC 802425BC AE20008C */  sw        $zero, 0x8c($s1)
.L802425C0:
/* DF8FC0 802425C0 8E230084 */  lw        $v1, 0x84($s1)
/* DF8FC4 802425C4 10600005 */  beqz      $v1, .L802425DC
/* DF8FC8 802425C8 24020001 */   addiu    $v0, $zero, 1
/* DF8FCC 802425CC 10620020 */  beq       $v1, $v0, .L80242650
/* DF8FD0 802425D0 0000102D */   daddu    $v0, $zero, $zero
/* DF8FD4 802425D4 0809099A */  j         .L80242668
/* DF8FD8 802425D8 00000000 */   nop      
.L802425DC:
/* DF8FDC 802425DC 2410FFFF */  addiu     $s0, $zero, -1
.L802425E0:
/* DF8FE0 802425E0 8E22008C */  lw        $v0, 0x8c($s1)
/* DF8FE4 802425E4 000218C0 */  sll       $v1, $v0, 3
/* DF8FE8 802425E8 00621823 */  subu      $v1, $v1, $v0
/* DF8FEC 802425EC 000318C0 */  sll       $v1, $v1, 3
/* DF8FF0 802425F0 00722021 */  addu      $a0, $v1, $s2
/* DF8FF4 802425F4 8C820000 */  lw        $v0, ($a0)
/* DF8FF8 802425F8 10400003 */  beqz      $v0, .L80242608
/* DF8FFC 802425FC 00000000 */   nop      
/* DF9000 80242600 0C0908D6 */  jal       func_80242358
/* DF9004 80242604 00000000 */   nop      
.L80242608:
/* DF9008 80242608 8E23008C */  lw        $v1, 0x8c($s1)
/* DF900C 8024260C 000310C0 */  sll       $v0, $v1, 3
/* DF9010 80242610 00431023 */  subu      $v0, $v0, $v1
/* DF9014 80242614 000210C0 */  sll       $v0, $v0, 3
/* DF9018 80242618 00521021 */  addu      $v0, $v0, $s2
/* DF901C 8024261C 8C420030 */  lw        $v0, 0x30($v0)
/* DF9020 80242620 AE220088 */  sw        $v0, 0x88($s1)
/* DF9024 80242624 0060102D */  daddu     $v0, $v1, $zero
/* DF9028 80242628 8E230088 */  lw        $v1, 0x88($s1)
/* DF902C 8024262C 24420001 */  addiu     $v0, $v0, 1
/* DF9030 80242630 1C600005 */  bgtz      $v1, .L80242648
/* DF9034 80242634 AE22008C */   sw       $v0, 0x8c($s1)
/* DF9038 80242638 1470FFE9 */  bne       $v1, $s0, .L802425E0
/* DF903C 8024263C 24020002 */   addiu    $v0, $zero, 2
/* DF9040 80242640 0809099A */  j         .L80242668
/* DF9044 80242644 00000000 */   nop      
.L80242648:
/* DF9048 80242648 24020001 */  addiu     $v0, $zero, 1
/* DF904C 8024264C AE220084 */  sw        $v0, 0x84($s1)
.L80242650:
/* DF9050 80242650 8E220088 */  lw        $v0, 0x88($s1)
/* DF9054 80242654 2442FFFF */  addiu     $v0, $v0, -1
/* DF9058 80242658 1C400002 */  bgtz      $v0, .L80242664
/* DF905C 8024265C AE220088 */   sw       $v0, 0x88($s1)
/* DF9060 80242660 AE200084 */  sw        $zero, 0x84($s1)
.L80242664:
/* DF9064 80242664 0000102D */  daddu     $v0, $zero, $zero
.L80242668:
/* DF9068 80242668 8FBF001C */  lw        $ra, 0x1c($sp)
/* DF906C 8024266C 8FB20018 */  lw        $s2, 0x18($sp)
/* DF9070 80242670 8FB10014 */  lw        $s1, 0x14($sp)
/* DF9074 80242674 8FB00010 */  lw        $s0, 0x10($sp)
/* DF9078 80242678 03E00008 */  jr        $ra
/* DF907C 8024267C 27BD0020 */   addiu    $sp, $sp, 0x20

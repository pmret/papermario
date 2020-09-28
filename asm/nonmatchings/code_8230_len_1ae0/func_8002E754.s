.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002E754
/* 9B54 8002E754 00A0402D */  daddu     $t0, $a1, $zero
/* 9B58 8002E758 3C05800B */  lui       $a1, %hi(gCameras)
/* 9B5C 8002E75C 24A51D80 */  addiu     $a1, $a1, %lo(gCameras)
/* 9B60 8002E760 00041080 */  sll       $v0, $a0, 2
/* 9B64 8002E764 00441021 */  addu      $v0, $v0, $a0
/* 9B68 8002E768 00021080 */  sll       $v0, $v0, 2
/* 9B6C 8002E76C 00441023 */  subu      $v0, $v0, $a0
/* 9B70 8002E770 000218C0 */  sll       $v1, $v0, 3
/* 9B74 8002E774 00431021 */  addu      $v0, $v0, $v1
/* 9B78 8002E778 000210C0 */  sll       $v0, $v0, 3
/* 9B7C 8002E77C 00451021 */  addu      $v0, $v0, $a1
/* 9B80 8002E780 8443000E */  lh        $v1, 0xe($v0)
/* 9B84 8002E784 84450010 */  lh        $a1, 0x10($v0)
/* 9B88 8002E788 8444000A */  lh        $a0, 0xa($v0)
/* 9B8C 8002E78C 8442000C */  lh        $v0, 0xc($v0)
/* 9B90 8002E790 00642021 */  addu      $a0, $v1, $a0
/* 9B94 8002E794 0103182A */  slt       $v1, $t0, $v1
/* 9B98 8002E798 14600004 */  bnez      $v1, .L8002E7AC
/* 9B9C 8002E79C 00A23821 */   addu     $a3, $a1, $v0
/* 9BA0 8002E7A0 0088102A */  slt       $v0, $a0, $t0
/* 9BA4 8002E7A4 10400003 */  beqz      $v0, .L8002E7B4
/* 9BA8 8002E7A8 00C5102A */   slt      $v0, $a2, $a1
.L8002E7AC:
/* 9BAC 8002E7AC 03E00008 */  jr        $ra
/* 9BB0 8002E7B0 24020001 */   addiu    $v0, $zero, 1
.L8002E7B4:
/* 9BB4 8002E7B4 10400003 */  beqz      $v0, .L8002E7C4
/* 9BB8 8002E7B8 00E6102A */   slt      $v0, $a3, $a2
/* 9BBC 8002E7BC 03E00008 */  jr        $ra
/* 9BC0 8002E7C0 24020001 */   addiu    $v0, $zero, 1
.L8002E7C4:
/* 9BC4 8002E7C4 03E00008 */  jr        $ra
/* 9BC8 8002E7C8 00000000 */   nop      

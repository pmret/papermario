.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80280B78
/* 7E19F8 80280B78 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7E19FC 80280B7C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7E1A00 80280B80 8C420144 */  lw        $v0, 0x144($v0)
/* 7E1A04 80280B84 84460004 */  lh        $a2, 4($v0)
/* 7E1A08 80280B88 8C43001C */  lw        $v1, 0x1c($v0)
/* 7E1A0C 80280B8C 18C0000A */  blez      $a2, .L80280BB8
/* 7E1A10 80280B90 0000282D */   daddu    $a1, $zero, $zero
.L80280B94:
/* 7E1A14 80280B94 8C620000 */  lw        $v0, ($v1)
/* 7E1A18 80280B98 14440004 */  bne       $v0, $a0, .L80280BAC
/* 7E1A1C 80280B9C 24A50001 */   addiu    $a1, $a1, 1
/* 7E1A20 80280BA0 8C620004 */  lw        $v0, 4($v1)
/* 7E1A24 80280BA4 03E00008 */  jr        $ra
/* 7E1A28 80280BA8 00000000 */   nop      
.L80280BAC:
/* 7E1A2C 80280BAC 00A6102A */  slt       $v0, $a1, $a2
/* 7E1A30 80280BB0 1440FFF8 */  bnez      $v0, .L80280B94
/* 7E1A34 80280BB4 2463000C */   addiu    $v1, $v1, 0xc
.L80280BB8:
/* 7E1A38 80280BB8 00041140 */  sll       $v0, $a0, 5
/* 7E1A3C 80280BBC 3C018008 */  lui       $at, %hi(gItemTable+0xC)
/* 7E1A40 80280BC0 00220821 */  addu      $at, $at, $v0
/* 7E1A44 80280BC4 842278EC */  lh        $v0, %lo(gItemTable+0xC)($at)
/* 7E1A48 80280BC8 03E00008 */  jr        $ra
/* 7E1A4C 80280BCC 00000000 */   nop      

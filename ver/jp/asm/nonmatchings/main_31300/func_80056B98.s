.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056B98
/* 31F98 80056B98 308400FF */  andi      $a0, $a0, 0xff
/* 31F9C 80056B9C 00041140 */  sll       $v0, $a0, 5
/* 31FA0 80056BA0 00441023 */  subu      $v0, $v0, $a0
/* 31FA4 80056BA4 3C038008 */  lui       $v1, %hi(D_80078E24)
/* 31FA8 80056BA8 8C638E24 */  lw        $v1, %lo(D_80078E24)($v1)
/* 31FAC 80056BAC 00021080 */  sll       $v0, $v0, 2
/* 31FB0 80056BB0 8C63001C */  lw        $v1, 0x1c($v1)
/* 31FB4 80056BB4 24050001 */  addiu     $a1, $zero, 1
/* 31FB8 80056BB8 00621821 */  addu      $v1, $v1, $v0
/* 31FBC 80056BBC 8C620018 */  lw        $v0, 0x18($v1)
/* 31FC0 80056BC0 24640004 */  addiu     $a0, $v1, 4
/* 31FC4 80056BC4 AC600070 */  sw        $zero, 0x70($v1)
/* 31FC8 80056BC8 AC65006C */  sw        $a1, 0x6c($v1)
/* 31FCC 80056BCC A465004E */  sh        $a1, 0x4e($v1)
/* 31FD0 80056BD0 AC600040 */  sw        $zero, 0x40($v1)
/* 31FD4 80056BD4 AC650044 */  sw        $a1, 0x44($v1)
/* 31FD8 80056BD8 AC60002C */  sw        $zero, 0x2c($v1)
/* 31FDC 80056BDC AC650030 */  sw        $a1, 0x30($v1)
/* 31FE0 80056BE0 1040000F */  beqz      $v0, .L80056C20
/* 31FE4 80056BE4 AC600028 */   sw       $zero, 0x28($v1)
/* 31FE8 80056BE8 8C820014 */  lw        $v0, 0x14($a0)
/* 31FEC 80056BEC 8C420000 */  lw        $v0, ($v0)
/* 31FF0 80056BF0 AC620034 */  sw        $v0, 0x34($v1)
/* 31FF4 80056BF4 8C840014 */  lw        $a0, 0x14($a0)
/* 31FF8 80056BF8 90820024 */  lbu       $v0, 0x24($a0)
/* 31FFC 80056BFC 10400003 */  beqz      $v0, .L80056C0C
/* 32000 80056C00 00000000 */   nop
/* 32004 80056C04 14450006 */  bne       $v0, $a1, .L80056C20
/* 32008 80056C08 00000000 */   nop
.L80056C0C:
/* 3200C 80056C0C 8C820010 */  lw        $v0, 0x10($a0)
/* 32010 80056C10 10400003 */  beqz      $v0, .L80056C20
/* 32014 80056C14 00000000 */   nop
/* 32018 80056C18 8C820014 */  lw        $v0, 0x14($a0)
/* 3201C 80056C1C AC620014 */  sw        $v0, 0x14($v1)
.L80056C20:
/* 32020 80056C20 03E00008 */  jr        $ra
/* 32024 80056C24 00000000 */   nop

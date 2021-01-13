.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B60_A27A30
/* A27A30 80240B60 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A27A34 80240B64 AFB00010 */  sw        $s0, 0x10($sp)
/* A27A38 80240B68 0080802D */  daddu     $s0, $a0, $zero
/* A27A3C 80240B6C 10A00002 */  beqz      $a1, .L80240B78
/* A27A40 80240B70 AFBF0014 */   sw       $ra, 0x14($sp)
/* A27A44 80240B74 AE000074 */  sw        $zero, 0x74($s0)
.L80240B78:
/* A27A48 80240B78 8E020074 */  lw        $v0, 0x74($s0)
/* A27A4C 80240B7C 24420010 */  addiu     $v0, $v0, 0x10
/* A27A50 80240B80 AE020074 */  sw        $v0, 0x74($s0)
/* A27A54 80240B84 28420100 */  slti      $v0, $v0, 0x100
/* A27A58 80240B88 14400002 */  bnez      $v0, .L80240B94
/* A27A5C 80240B8C 240200FF */   addiu    $v0, $zero, 0xff
/* A27A60 80240B90 AE020074 */  sw        $v0, 0x74($s0)
.L80240B94:
/* A27A64 80240B94 C6000074 */  lwc1      $f0, 0x74($s0)
/* A27A68 80240B98 46800020 */  cvt.s.w   $f0, $f0
/* A27A6C 80240B9C 44050000 */  mfc1      $a1, $f0
/* A27A70 80240BA0 0C04DF62 */  jal       func_80137D88
/* A27A74 80240BA4 0000202D */   daddu    $a0, $zero, $zero
/* A27A78 80240BA8 8E020074 */  lw        $v0, 0x74($s0)
/* A27A7C 80240BAC 8FBF0014 */  lw        $ra, 0x14($sp)
/* A27A80 80240BB0 8FB00010 */  lw        $s0, 0x10($sp)
/* A27A84 80240BB4 384200FF */  xori      $v0, $v0, 0xff
/* A27A88 80240BB8 2C420001 */  sltiu     $v0, $v0, 1
/* A27A8C 80240BBC 00021040 */  sll       $v0, $v0, 1
/* A27A90 80240BC0 03E00008 */  jr        $ra
/* A27A94 80240BC4 27BD0018 */   addiu    $sp, $sp, 0x18
/* A27A98 80240BC8 00000000 */  nop
/* A27A9C 80240BCC 00000000 */  nop

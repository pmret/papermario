.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osContDataCrc
/* 47CCC 8006C8CC 00001821 */  addu      $v1, $zero, $zero
/* 47CD0 8006C8D0 24060020 */  addiu     $a2, $zero, 0x20
.L8006C8D4:
/* 47CD4 8006C8D4 24050080 */  addiu     $a1, $zero, 0x80
/* 47CD8 8006C8D8 90870000 */  lbu       $a3, ($a0)
/* 47CDC 8006C8DC 00E51024 */  and       $v0, $a3, $a1
.L8006C8E0:
/* 47CE0 8006C8E0 10400006 */  beqz      $v0, .L8006C8FC
/* 47CE4 8006C8E4 00031840 */   sll      $v1, $v1, 1
/* 47CE8 8006C8E8 30620100 */  andi      $v0, $v1, 0x100
/* 47CEC 8006C8EC 50400006 */  beql      $v0, $zero, .L8006C908
/* 47CF0 8006C8F0 24630001 */   addiu    $v1, $v1, 1
/* 47CF4 8006C8F4 0801B242 */  j         .L8006C908
/* 47CF8 8006C8F8 38630084 */   xori     $v1, $v1, 0x84
.L8006C8FC:
/* 47CFC 8006C8FC 30620100 */  andi      $v0, $v1, 0x100
/* 47D00 8006C900 54400001 */  bnel      $v0, $zero, .L8006C908
/* 47D04 8006C904 38630085 */   xori     $v1, $v1, 0x85
.L8006C908:
/* 47D08 8006C908 00052842 */  srl       $a1, $a1, 1
/* 47D0C 8006C90C 14A0FFF4 */  bnez      $a1, .L8006C8E0
/* 47D10 8006C910 00E51024 */   and      $v0, $a3, $a1
/* 47D14 8006C914 24C6FFFF */  addiu     $a2, $a2, -1
/* 47D18 8006C918 14C0FFEE */  bnez      $a2, .L8006C8D4
/* 47D1C 8006C91C 24840001 */   addiu    $a0, $a0, 1
/* 47D20 8006C920 00031840 */  sll       $v1, $v1, 1
.L8006C924:
/* 47D24 8006C924 30620100 */  andi      $v0, $v1, 0x100
/* 47D28 8006C928 54400001 */  bnel      $v0, $zero, .L8006C930
/* 47D2C 8006C92C 38630085 */   xori     $v1, $v1, 0x85
.L8006C930:
/* 47D30 8006C930 24C60001 */  addiu     $a2, $a2, 1
/* 47D34 8006C934 2CC20008 */  sltiu     $v0, $a2, 8
/* 47D38 8006C938 5440FFFA */  bnel      $v0, $zero, .L8006C924
/* 47D3C 8006C93C 00031840 */   sll      $v1, $v1, 1
/* 47D40 8006C940 03E00008 */  jr        $ra
/* 47D44 8006C944 306200FF */   andi     $v0, $v1, 0xff
/* 47D48 8006C948 00000000 */  nop
/* 47D4C 8006C94C 00000000 */  nop

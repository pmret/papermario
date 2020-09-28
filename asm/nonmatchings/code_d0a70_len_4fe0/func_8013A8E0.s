.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013A8E0
/* D0FE0 8013A8E0 2C82005A */  sltiu     $v0, $a0, 0x5a
/* D0FE4 8013A8E4 14400003 */  bnez      $v0, .L8013A8F4
/* D0FE8 8013A8E8 2882005A */   slti     $v0, $a0, 0x5a
/* D0FEC 8013A8EC 03E00008 */  jr        $ra
/* D0FF0 8013A8F0 2402FFFF */   addiu    $v0, $zero, -1
.L8013A8F4:
/* D0FF4 8013A8F4 10400008 */  beqz      $v0, .L8013A918
/* D0FF8 8013A8F8 00041140 */   sll      $v0, $a0, 5
/* D0FFC 8013A8FC 00441023 */  subu      $v0, $v0, $a0
/* D1000 8013A900 3C038015 */  lui       $v1, 0x8015
/* D1004 8013A904 8C636954 */  lw        $v1, 0x6954($v1)
/* D1008 8013A908 00021080 */  sll       $v0, $v0, 2
/* D100C 8013A90C 00431021 */  addu      $v0, $v0, $v1
/* D1010 8013A910 03E00008 */  jr        $ra
/* D1014 8013A914 84420010 */   lh       $v0, 0x10($v0)
.L8013A918:
/* D1018 8013A918 03E00008 */  jr        $ra
/* D101C 8013A91C 240200FF */   addiu    $v0, $zero, 0xff

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004CEEC
/* 282EC 8004CEEC 00A0382D */  daddu     $a3, $a1, $zero
/* 282F0 8004CEF0 8CE20000 */  lw        $v0, ($a3)
/* 282F4 8004CEF4 8C860008 */  lw        $a2, 8($a0)
/* 282F8 8004CEF8 90430001 */  lbu       $v1, 1($v0)
/* 282FC 8004CEFC 90450002 */  lbu       $a1, 2($v0)
/* 28300 8004CF00 90440000 */  lbu       $a0, ($v0)
/* 28304 8004CF04 24420003 */  addiu     $v0, $v0, 3
/* 28308 8004CF08 ACE20000 */  sw        $v0, ($a3)
/* 2830C 8004CF0C 24020002 */  addiu     $v0, $zero, 2
/* 28310 8004CF10 00031A00 */  sll       $v1, $v1, 8
/* 28314 8004CF14 00651821 */  addu      $v1, $v1, $a1
/* 28318 8004CF18 A0E40084 */  sb        $a0, 0x84($a3)
/* 2831C 8004CF1C 308400FF */  andi      $a0, $a0, 0xff
/* 28320 8004CF20 1082000B */  beq       $a0, $v0, .L8004CF50
/* 28324 8004CF24 00661821 */   addu     $v1, $v1, $a2
/* 28328 8004CF28 28820003 */  slti      $v0, $a0, 3
/* 2832C 8004CF2C 10400005 */  beqz      $v0, .L8004CF44
/* 28330 8004CF30 24020001 */   addiu    $v0, $zero, 1
/* 28334 8004CF34 10820006 */  beq       $a0, $v0, .L8004CF50
/* 28338 8004CF38 00000000 */   nop
/* 2833C 8004CF3C 03E00008 */  jr        $ra
/* 28340 8004CF40 ACE00080 */   sw       $zero, 0x80($a3)
.L8004CF44:
/* 28344 8004CF44 24020003 */  addiu     $v0, $zero, 3
/* 28348 8004CF48 54820003 */  bnel      $a0, $v0, .L8004CF58
/* 2834C 8004CF4C ACE00080 */   sw       $zero, 0x80($a3)
.L8004CF50:
/* 28350 8004CF50 03E00008 */  jr        $ra
/* 28354 8004CF54 ACE30080 */   sw       $v1, 0x80($a3)
.L8004CF58:
/* 28358 8004CF58 03E00008 */  jr        $ra
/* 2835C 8004CF5C 00000000 */   nop

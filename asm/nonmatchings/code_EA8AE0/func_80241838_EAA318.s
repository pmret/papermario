.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241838_EAA318
/* EAA318 80241838 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EAA31C 8024183C AFBF0010 */  sw        $ra, 0x10($sp)
/* EAA320 80241840 8C82000C */  lw        $v0, 0xc($a0)
/* EAA324 80241844 0C0B53A3 */  jal       func_802D4E8C
/* EAA328 80241848 8C450000 */   lw       $a1, ($v0)
/* EAA32C 8024184C 0040182D */  daddu     $v1, $v0, $zero
/* EAA330 80241850 10600012 */  beqz      $v1, .L8024189C
/* EAA334 80241854 0000202D */   daddu    $a0, $zero, $zero
/* EAA338 80241858 8C620000 */  lw        $v0, ($v1)
/* EAA33C 8024185C 5040000A */  beql      $v0, $zero, .L80241888
/* EAA340 80241860 00041080 */   sll      $v0, $a0, 2
/* EAA344 80241864 3C058025 */  lui       $a1, %hi(D_80248388)
/* EAA348 80241868 24A58388 */  addiu     $a1, $a1, %lo(D_80248388)
.L8024186C:
/* EAA34C 8024186C 24630004 */  addiu     $v1, $v1, 4
/* EAA350 80241870 24840001 */  addiu     $a0, $a0, 1
/* EAA354 80241874 ACA20000 */  sw        $v0, ($a1)
/* EAA358 80241878 8C620000 */  lw        $v0, ($v1)
/* EAA35C 8024187C 1440FFFB */  bnez      $v0, .L8024186C
/* EAA360 80241880 24A50004 */   addiu    $a1, $a1, 4
/* EAA364 80241884 00041080 */  sll       $v0, $a0, 2
.L80241888:
/* EAA368 80241888 3C018025 */  lui       $at, %hi(D_80248388)
/* EAA36C 8024188C 00220821 */  addu      $at, $at, $v0
/* EAA370 80241890 AC208388 */  sw        $zero, %lo(D_80248388)($at)
/* EAA374 80241894 08090631 */  j         .L802418C4
/* EAA378 80241898 00000000 */   nop
.L8024189C:
/* EAA37C 8024189C 3C038025 */  lui       $v1, %hi(D_80248388)
/* EAA380 802418A0 24638388 */  addiu     $v1, $v1, %lo(D_80248388)
/* EAA384 802418A4 0060282D */  daddu     $a1, $v1, $zero
.L802418A8:
/* EAA388 802418A8 24820010 */  addiu     $v0, $a0, 0x10
/* EAA38C 802418AC AC620000 */  sw        $v0, ($v1)
/* EAA390 802418B0 24630004 */  addiu     $v1, $v1, 4
/* EAA394 802418B4 24840001 */  addiu     $a0, $a0, 1
/* EAA398 802418B8 28820070 */  slti      $v0, $a0, 0x70
/* EAA39C 802418BC 1440FFFA */  bnez      $v0, .L802418A8
/* EAA3A0 802418C0 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L802418C4:
/* EAA3A4 802418C4 8FBF0010 */  lw        $ra, 0x10($sp)
/* EAA3A8 802418C8 24020002 */  addiu     $v0, $zero, 2
/* EAA3AC 802418CC 03E00008 */  jr        $ra
/* EAA3B0 802418D0 27BD0018 */   addiu    $sp, $sp, 0x18

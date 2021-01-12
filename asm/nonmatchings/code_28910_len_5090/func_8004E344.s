.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004E344
/* 29744 8004E344 0000182D */  daddu     $v1, $zero, $zero
.L8004E348:
/* 29748 8004E348 90A60000 */  lbu       $a2, ($a1)
/* 2974C 8004E34C 00061600 */  sll       $v0, $a2, 0x18
/* 29750 8004E350 04400007 */  bltz      $v0, .L8004E370
/* 29754 8004E354 24A50001 */   addiu    $a1, $a1, 1
/* 29758 8004E358 00831021 */  addu      $v0, $a0, $v1
/* 2975C 8004E35C A046004C */  sb        $a2, 0x4c($v0)
/* 29760 8004E360 24630001 */  addiu     $v1, $v1, 1
/* 29764 8004E364 28620004 */  slti      $v0, $v1, 4
/* 29768 8004E368 1440FFF7 */  bnez      $v0, .L8004E348
/* 2976C 8004E36C 00000000 */   nop
.L8004E370:
/* 29770 8004E370 24020004 */  addiu     $v0, $zero, 4
/* 29774 8004E374 00432823 */  subu      $a1, $v0, $v1
/* 29778 8004E378 18A00008 */  blez      $a1, .L8004E39C
/* 2977C 8004E37C 24A5FFFF */   addiu    $a1, $a1, -1
/* 29780 8004E380 240600FF */  addiu     $a2, $zero, 0xff
.L8004E384:
/* 29784 8004E384 00831021 */  addu      $v0, $a0, $v1
/* 29788 8004E388 A046004C */  sb        $a2, 0x4c($v0)
/* 2978C 8004E38C 24630001 */  addiu     $v1, $v1, 1
/* 29790 8004E390 00A0102D */  daddu     $v0, $a1, $zero
/* 29794 8004E394 1440FFFB */  bnez      $v0, .L8004E384
/* 29798 8004E398 24A5FFFF */   addiu    $a1, $a1, -1
.L8004E39C:
/* 2979C 8004E39C 03E00008 */  jr        $ra
/* 297A0 8004E3A0 00000000 */   nop

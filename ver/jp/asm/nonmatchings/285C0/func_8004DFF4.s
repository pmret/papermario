.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004DFF4
/* 293F4 8004DFF4 0000182D */  daddu     $v1, $zero, $zero
.L8004DFF8:
/* 293F8 8004DFF8 90A60000 */  lbu       $a2, ($a1)
/* 293FC 8004DFFC 00061600 */  sll       $v0, $a2, 0x18
/* 29400 8004E000 04400007 */  bltz      $v0, .L8004E020
/* 29404 8004E004 24A50001 */   addiu    $a1, $a1, 1
/* 29408 8004E008 00831021 */  addu      $v0, $a0, $v1
/* 2940C 8004E00C A046004C */  sb        $a2, 0x4c($v0)
/* 29410 8004E010 24630001 */  addiu     $v1, $v1, 1
/* 29414 8004E014 28620004 */  slti      $v0, $v1, 4
/* 29418 8004E018 1440FFF7 */  bnez      $v0, .L8004DFF8
/* 2941C 8004E01C 00000000 */   nop
.L8004E020:
/* 29420 8004E020 24020004 */  addiu     $v0, $zero, 4
/* 29424 8004E024 00432823 */  subu      $a1, $v0, $v1
/* 29428 8004E028 18A00008 */  blez      $a1, .L8004E04C
/* 2942C 8004E02C 24A5FFFF */   addiu    $a1, $a1, -1
/* 29430 8004E030 240600FF */  addiu     $a2, $zero, 0xff
.L8004E034:
/* 29434 8004E034 00831021 */  addu      $v0, $a0, $v1
/* 29438 8004E038 A046004C */  sb        $a2, 0x4c($v0)
/* 2943C 8004E03C 24630001 */  addiu     $v1, $v1, 1
/* 29440 8004E040 00A0102D */  daddu     $v0, $a1, $zero
/* 29444 8004E044 1440FFFB */  bnez      $v0, .L8004E034
/* 29448 8004E048 24A5FFFF */   addiu    $a1, $a1, -1
.L8004E04C:
/* 2944C 8004E04C 03E00008 */  jr        $ra
/* 29450 8004E050 00000000 */   nop

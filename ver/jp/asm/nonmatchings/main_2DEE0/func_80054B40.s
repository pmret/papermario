.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054B40
/* 2FF40 80054B40 10A0000A */  beqz      $a1, .L80054B6C
/* 2FF44 80054B44 28A20400 */   slti     $v0, $a1, 0x400
/* 2FF48 80054B48 1040000A */  beqz      $v0, .L80054B74
/* 2FF4C 80054B4C 00A0102D */   daddu    $v0, $a1, $zero
/* 2FF50 80054B50 10400006 */  beqz      $v0, .L80054B6C
/* 2FF54 80054B54 24A5FFFF */   addiu    $a1, $a1, -1
.L80054B58:
/* 2FF58 80054B58 A0860000 */  sb        $a2, ($a0)
/* 2FF5C 80054B5C 24840001 */  addiu     $a0, $a0, 1
/* 2FF60 80054B60 00A0102D */  daddu     $v0, $a1, $zero
/* 2FF64 80054B64 1440FFFC */  bnez      $v0, .L80054B58
/* 2FF68 80054B68 24A5FFFF */   addiu    $a1, $a1, -1
.L80054B6C:
/* 2FF6C 80054B6C 03E00008 */  jr        $ra
/* 2FF70 80054B70 00000000 */   nop
.L80054B74:
/* 2FF74 80054B74 30870003 */  andi      $a3, $a0, 3
/* 2FF78 80054B78 10E00009 */  beqz      $a3, .L80054BA0
/* 2FF7C 80054B7C 24020004 */   addiu    $v0, $zero, 4
/* 2FF80 80054B80 00473823 */  subu      $a3, $v0, $a3
/* 2FF84 80054B84 080152E5 */  j         .L80054B94
/* 2FF88 80054B88 00A72823 */   subu     $a1, $a1, $a3
.L80054B8C:
/* 2FF8C 80054B8C A0860000 */  sb        $a2, ($a0)
/* 2FF90 80054B90 24840001 */  addiu     $a0, $a0, 1
.L80054B94:
/* 2FF94 80054B94 00E0102D */  daddu     $v0, $a3, $zero
/* 2FF98 80054B98 1440FFFC */  bnez      $v0, .L80054B8C
/* 2FF9C 80054B9C 24E7FFFF */   addiu    $a3, $a3, -1
.L80054BA0:
/* 2FFA0 80054BA0 00053883 */  sra       $a3, $a1, 2
/* 2FFA4 80054BA4 30C300FF */  andi      $v1, $a2, 0xff
/* 2FFA8 80054BA8 00031200 */  sll       $v0, $v1, 8
/* 2FFAC 80054BAC 00431821 */  addu      $v1, $v0, $v1
/* 2FFB0 80054BB0 00031400 */  sll       $v0, $v1, 0x10
/* 2FFB4 80054BB4 080152F1 */  j         .L80054BC4
/* 2FFB8 80054BB8 00621821 */   addu     $v1, $v1, $v0
.L80054BBC:
/* 2FFBC 80054BBC AC830000 */  sw        $v1, ($a0)
/* 2FFC0 80054BC0 24840004 */  addiu     $a0, $a0, 4
.L80054BC4:
/* 2FFC4 80054BC4 00E0102D */  daddu     $v0, $a3, $zero
/* 2FFC8 80054BC8 1440FFFC */  bnez      $v0, .L80054BBC
/* 2FFCC 80054BCC 24E7FFFF */   addiu    $a3, $a3, -1
/* 2FFD0 80054BD0 30A70003 */  andi      $a3, $a1, 3
/* 2FFD4 80054BD4 10E0FFE5 */  beqz      $a3, .L80054B6C
/* 2FFD8 80054BD8 24E7FFFF */   addiu    $a3, $a3, -1
.L80054BDC:
/* 2FFDC 80054BDC A0860000 */  sb        $a2, ($a0)
/* 2FFE0 80054BE0 24840001 */  addiu     $a0, $a0, 1
/* 2FFE4 80054BE4 00E0102D */  daddu     $v0, $a3, $zero
/* 2FFE8 80054BE8 1440FFFC */  bnez      $v0, .L80054BDC
/* 2FFEC 80054BEC 24E7FFFF */   addiu    $a3, $a3, -1
/* 2FFF0 80054BF0 03E00008 */  jr        $ra
/* 2FFF4 80054BF4 00000000 */   nop

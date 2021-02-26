.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054F80
/* 30380 80054F80 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30384 80054F84 0080482D */  daddu     $t1, $a0, $zero
/* 30388 80054F88 00C0402D */  daddu     $t0, $a2, $zero
/* 3038C 80054F8C 30A500FF */  andi      $a1, $a1, 0xff
/* 30390 80054F90 00051A00 */  sll       $v1, $a1, 8
/* 30394 80054F94 3C04800A */  lui       $a0, %hi(D_8009A620)
/* 30398 80054F98 8C84A620 */  lw        $a0, %lo(D_8009A620)($a0)
/* 3039C 80054F9C 0060382D */  daddu     $a3, $v1, $zero
/* 303A0 80054FA0 10A00002 */  beqz      $a1, .L80054FAC
/* 303A4 80054FA4 AFBF0018 */   sw       $ra, 0x18($sp)
/* 303A8 80054FA8 346700FF */  ori       $a3, $v1, 0xff
.L80054FAC:
/* 303AC 80054FAC 00061600 */  sll       $v0, $a2, 0x18
/* 303B0 80054FB0 04420001 */  bltzl     $v0, .L80054FB8
/* 303B4 80054FB4 2408007F */   addiu    $t0, $zero, 0x7f
.L80054FB8:
/* 303B8 80054FB8 310200FF */  andi      $v0, $t0, 0xff
/* 303BC 80054FBC 00073400 */  sll       $a2, $a3, 0x10
/* 303C0 80054FC0 35251000 */  ori       $a1, $t1, 0x1000
/* 303C4 80054FC4 00063403 */  sra       $a2, $a2, 0x10
/* 303C8 80054FC8 0000382D */  daddu     $a3, $zero, $zero
/* 303CC 80054FCC 0C012CE2 */  jal       func_8004B388
/* 303D0 80054FD0 AFA20010 */   sw       $v0, 0x10($sp)
/* 303D4 80054FD4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 303D8 80054FD8 03E00008 */  jr        $ra
/* 303DC 80054FDC 27BD0020 */   addiu    $sp, $sp, 0x20

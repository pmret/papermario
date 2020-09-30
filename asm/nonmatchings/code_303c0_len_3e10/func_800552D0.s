.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800552D0
/* 306D0 800552D0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 306D4 800552D4 0080482D */  daddu     $t1, $a0, $zero
/* 306D8 800552D8 00C0402D */  daddu     $t0, $a2, $zero
/* 306DC 800552DC 30A500FF */  andi      $a1, $a1, 0xff
/* 306E0 800552E0 00051A00 */  sll       $v1, $a1, 8
/* 306E4 800552E4 3C04800A */  lui       $a0, 0x800a
/* 306E8 800552E8 8C84A640 */  lw        $a0, -0x59c0($a0)
/* 306EC 800552EC 0060382D */  daddu     $a3, $v1, $zero
/* 306F0 800552F0 10A00002 */  beqz      $a1, .L800552FC
/* 306F4 800552F4 AFBF0018 */   sw       $ra, 0x18($sp)
/* 306F8 800552F8 346700FF */  ori       $a3, $v1, 0xff
.L800552FC:
/* 306FC 800552FC 00061600 */  sll       $v0, $a2, 0x18
/* 30700 80055300 04420001 */  bltzl     $v0, .L80055308
/* 30704 80055304 2408007F */   addiu    $t0, $zero, 0x7f
.L80055308:
/* 30708 80055308 310200FF */  andi      $v0, $t0, 0xff
/* 3070C 8005530C 00073400 */  sll       $a2, $a3, 0x10
/* 30710 80055310 35251000 */  ori       $a1, $t1, 0x1000
/* 30714 80055314 00063403 */  sra       $a2, $a2, 0x10
/* 30718 80055318 0000382D */  daddu     $a3, $zero, $zero
/* 3071C 8005531C 0C012DB6 */  jal       func_8004B6D8
/* 30720 80055320 AFA20010 */   sw       $v0, 0x10($sp)
/* 30724 80055324 8FBF0018 */  lw        $ra, 0x18($sp)
/* 30728 80055328 03E00008 */  jr        $ra
/* 3072C 8005532C 27BD0020 */   addiu    $sp, $sp, 0x20

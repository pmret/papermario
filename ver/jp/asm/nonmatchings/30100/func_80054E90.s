.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054E90
/* 30290 80054E90 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 30294 80054E94 0080482D */  daddu     $t1, $a0, $zero
/* 30298 80054E98 00C0402D */  daddu     $t0, $a2, $zero
/* 3029C 80054E9C 30A500FF */  andi      $a1, $a1, 0xff
/* 302A0 80054EA0 00051A00 */  sll       $v1, $a1, 8
/* 302A4 80054EA4 3C04800A */  lui       $a0, %hi(D_8009A620)
/* 302A8 80054EA8 8C84A620 */  lw        $a0, %lo(D_8009A620)($a0)
/* 302AC 80054EAC 0060382D */  daddu     $a3, $v1, $zero
/* 302B0 80054EB0 10A00002 */  beqz      $a1, .L80054EBC
/* 302B4 80054EB4 AFBF0018 */   sw       $ra, 0x18($sp)
/* 302B8 80054EB8 346700FF */  ori       $a3, $v1, 0xff
.L80054EBC:
/* 302BC 80054EBC 00061600 */  sll       $v0, $a2, 0x18
/* 302C0 80054EC0 04420001 */  bltzl     $v0, .L80054EC8
/* 302C4 80054EC4 2408007F */   addiu    $t0, $zero, 0x7f
.L80054EC8:
/* 302C8 80054EC8 310200FF */  andi      $v0, $t0, 0xff
/* 302CC 80054ECC 00073400 */  sll       $a2, $a3, 0x10
/* 302D0 80054ED0 0120282D */  daddu     $a1, $t1, $zero
/* 302D4 80054ED4 00063403 */  sra       $a2, $a2, 0x10
/* 302D8 80054ED8 0000382D */  daddu     $a3, $zero, $zero
/* 302DC 80054EDC 0C012CE2 */  jal       func_8004B388
/* 302E0 80054EE0 AFA20010 */   sw       $v0, 0x10($sp)
/* 302E4 80054EE4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 302E8 80054EE8 03E00008 */  jr        $ra
/* 302EC 80054EEC 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800551E0
/* 305E0 800551E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 305E4 800551E4 0080482D */  daddu     $t1, $a0, $zero
/* 305E8 800551E8 00C0402D */  daddu     $t0, $a2, $zero
/* 305EC 800551EC 30A500FF */  andi      $a1, $a1, 0xff
/* 305F0 800551F0 00051A00 */  sll       $v1, $a1, 8
/* 305F4 800551F4 3C04800A */  lui       $a0, %hi(D_8009A640)
/* 305F8 800551F8 8C84A640 */  lw        $a0, %lo(D_8009A640)($a0)
/* 305FC 800551FC 0060382D */  daddu     $a3, $v1, $zero
/* 30600 80055200 10A00002 */  beqz      $a1, .L8005520C
/* 30604 80055204 AFBF0018 */   sw       $ra, 0x18($sp)
/* 30608 80055208 346700FF */  ori       $a3, $v1, 0xff
.L8005520C:
/* 3060C 8005520C 00061600 */  sll       $v0, $a2, 0x18
/* 30610 80055210 04420001 */  bltzl     $v0, .L80055218
/* 30614 80055214 2408007F */   addiu    $t0, $zero, 0x7f
.L80055218:
/* 30618 80055218 310200FF */  andi      $v0, $t0, 0xff
/* 3061C 8005521C 00073400 */  sll       $a2, $a3, 0x10
/* 30620 80055220 0120282D */  daddu     $a1, $t1, $zero
/* 30624 80055224 00063403 */  sra       $a2, $a2, 0x10
/* 30628 80055228 0000382D */  daddu     $a3, $zero, $zero
/* 3062C 8005522C 0C012DB6 */  jal       func_8004B6D8
/* 30630 80055230 AFA20010 */   sw       $v0, 0x10($sp)
/* 30634 80055234 8FBF0018 */  lw        $ra, 0x18($sp)
/* 30638 80055238 03E00008 */  jr        $ra
/* 3063C 8005523C 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240034_ED8E54
/* ED8E54 80240034 3C038017 */  lui       $v1, %hi(D_80169B12)
/* ED8E58 80240038 84639B12 */  lh        $v1, %lo(D_80169B12)($v1)
/* ED8E5C 8024003C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ED8E60 80240040 AFB00010 */  sw        $s0, 0x10($sp)
/* ED8E64 80240044 0080802D */  daddu     $s0, $a0, $zero
/* ED8E68 80240048 AFBF0014 */  sw        $ra, 0x14($sp)
/* ED8E6C 8024004C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* ED8E70 80240050 10620003 */  beq       $v1, $v0, .L80240060
/* ED8E74 80240054 24020002 */   addiu    $v0, $zero, 2
/* ED8E78 80240058 08090038 */  j         .L802400E0
/* ED8E7C 8024005C AE000084 */   sw       $zero, 0x84($s0)
.L80240060:
/* ED8E80 80240060 3C038008 */  lui       $v1, %hi(D_80079430)
/* ED8E84 80240064 8C639430 */  lw        $v1, %lo(D_80079430)($v1)
/* ED8E88 80240068 80620040 */  lb        $v0, 0x40($v1)
/* ED8E8C 8024006C 80670044 */  lb        $a3, 0x44($v1)
/* ED8E90 80240070 04420001 */  bltzl     $v0, .L80240078
/* ED8E94 80240074 00021023 */   negu     $v0, $v0
.L80240078:
/* ED8E98 80240078 14400003 */  bnez      $v0, .L80240088
/* ED8E9C 8024007C 00000000 */   nop      
/* ED8EA0 80240080 50E00017 */  beql      $a3, $zero, .L802400E0
/* ED8EA4 80240084 0000102D */   daddu    $v0, $zero, $zero
.L80240088:
/* ED8EA8 80240088 44822000 */  mtc1      $v0, $f4
/* ED8EAC 8024008C 00000000 */  nop       
/* ED8EB0 80240090 46802120 */  cvt.s.w   $f4, $f4
/* ED8EB4 80240094 44062000 */  mfc1      $a2, $f4
/* ED8EB8 80240098 44872000 */  mtc1      $a3, $f4
/* ED8EBC 8024009C 00000000 */  nop       
/* ED8EC0 802400A0 46802120 */  cvt.s.w   $f4, $f4
/* ED8EC4 802400A4 44806000 */  mtc1      $zero, $f12
/* ED8EC8 802400A8 44072000 */  mfc1      $a3, $f4
/* ED8ECC 802400AC 0C00ABDC */  jal       fio_validate_header_checksums
/* ED8ED0 802400B0 46006386 */   mov.s    $f14, $f12
/* ED8ED4 802400B4 3C014270 */  lui       $at, 0x4270
/* ED8ED8 802400B8 44811000 */  mtc1      $at, $f2
/* ED8EDC 802400BC 00000000 */  nop       
/* ED8EE0 802400C0 4602003C */  c.lt.s    $f0, $f2
/* ED8EE4 802400C4 00000000 */  nop       
/* ED8EE8 802400C8 45000004 */  bc1f      .L802400DC
/* ED8EEC 802400CC 24020001 */   addiu    $v0, $zero, 1
/* ED8EF0 802400D0 AE020084 */  sw        $v0, 0x84($s0)
/* ED8EF4 802400D4 08090038 */  j         .L802400E0
/* ED8EF8 802400D8 24020002 */   addiu    $v0, $zero, 2
.L802400DC:
/* ED8EFC 802400DC 0000102D */  daddu     $v0, $zero, $zero
.L802400E0:
/* ED8F00 802400E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* ED8F04 802400E4 8FB00010 */  lw        $s0, 0x10($sp)
/* ED8F08 802400E8 03E00008 */  jr        $ra
/* ED8F0C 802400EC 27BD0018 */   addiu    $sp, $sp, 0x18

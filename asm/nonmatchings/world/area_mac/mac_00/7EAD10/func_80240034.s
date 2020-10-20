.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240034
/* 7EAD44 80240034 3C038016 */  lui       $v1, 0x8016
/* 7EAD48 80240038 8463A552 */  lh        $v1, -0x5aae($v1)
/* 7EAD4C 8024003C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7EAD50 80240040 AFB00010 */  sw        $s0, 0x10($sp)
/* 7EAD54 80240044 0080802D */  daddu     $s0, $a0, $zero
/* 7EAD58 80240048 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7EAD5C 8024004C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 7EAD60 80240050 10620003 */  beq       $v1, $v0, .L80240060
/* 7EAD64 80240054 24020002 */   addiu    $v0, $zero, 2
/* 7EAD68 80240058 08090038 */  j         .L802400E0
/* 7EAD6C 8024005C AE000084 */   sw       $zero, 0x84($s0)
.L80240060:
/* 7EAD70 80240060 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 7EAD74 80240064 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 7EAD78 80240068 80620040 */  lb        $v0, 0x40($v1)
/* 7EAD7C 8024006C 80670044 */  lb        $a3, 0x44($v1)
/* 7EAD80 80240070 04420001 */  bltzl     $v0, .L80240078
/* 7EAD84 80240074 00021023 */   negu     $v0, $v0
.L80240078:
/* 7EAD88 80240078 14400003 */  bnez      $v0, .L80240088
/* 7EAD8C 8024007C 00000000 */   nop      
/* 7EAD90 80240080 50E00017 */  beql      $a3, $zero, .L802400E0
/* 7EAD94 80240084 0000102D */   daddu    $v0, $zero, $zero
.L80240088:
/* 7EAD98 80240088 44822000 */  mtc1      $v0, $f4
/* 7EAD9C 8024008C 00000000 */  nop       
/* 7EADA0 80240090 46802120 */  cvt.s.w   $f4, $f4
/* 7EADA4 80240094 44062000 */  mfc1      $a2, $f4
/* 7EADA8 80240098 44872000 */  mtc1      $a3, $f4
/* 7EADAC 8024009C 00000000 */  nop       
/* 7EADB0 802400A0 46802120 */  cvt.s.w   $f4, $f4
/* 7EADB4 802400A4 44806000 */  mtc1      $zero, $f12
/* 7EADB8 802400A8 44072000 */  mfc1      $a3, $f4
/* 7EADBC 802400AC 0C00A720 */  jal       atan2
/* 7EADC0 802400B0 46006386 */   mov.s    $f14, $f12
/* 7EADC4 802400B4 3C014270 */  lui       $at, 0x4270
/* 7EADC8 802400B8 44811000 */  mtc1      $at, $f2
/* 7EADCC 802400BC 00000000 */  nop       
/* 7EADD0 802400C0 4602003C */  c.lt.s    $f0, $f2
/* 7EADD4 802400C4 00000000 */  nop       
/* 7EADD8 802400C8 45000004 */  bc1f      .L802400DC
/* 7EADDC 802400CC 24020001 */   addiu    $v0, $zero, 1
/* 7EADE0 802400D0 AE020084 */  sw        $v0, 0x84($s0)
/* 7EADE4 802400D4 08090038 */  j         .L802400E0
/* 7EADE8 802400D8 24020002 */   addiu    $v0, $zero, 2
.L802400DC:
/* 7EADEC 802400DC 0000102D */  daddu     $v0, $zero, $zero
.L802400E0:
/* 7EADF0 802400E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7EADF4 802400E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EADF8 802400E8 03E00008 */  jr        $ra
/* 7EADFC 802400EC 27BD0018 */   addiu    $sp, $sp, 0x18

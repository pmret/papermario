.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240034_88FBD4
/* 88FBD4 80240034 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x2)
/* 88FBD8 80240038 8463A552 */  lh        $v1, %lo(gCollisionStatus+0x2)($v1)
/* 88FBDC 8024003C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 88FBE0 80240040 AFB00010 */  sw        $s0, 0x10($sp)
/* 88FBE4 80240044 0080802D */  daddu     $s0, $a0, $zero
/* 88FBE8 80240048 AFBF0014 */  sw        $ra, 0x14($sp)
/* 88FBEC 8024004C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 88FBF0 80240050 10620003 */  beq       $v1, $v0, .L80240060
/* 88FBF4 80240054 24020002 */   addiu    $v0, $zero, 2
/* 88FBF8 80240058 08090038 */  j         .L802400E0
/* 88FBFC 8024005C AE000084 */   sw       $zero, 0x84($s0)
.L80240060:
/* 88FC00 80240060 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 88FC04 80240064 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 88FC08 80240068 80620040 */  lb        $v0, 0x40($v1)
/* 88FC0C 8024006C 80670044 */  lb        $a3, 0x44($v1)
/* 88FC10 80240070 04420001 */  bltzl     $v0, .L80240078
/* 88FC14 80240074 00021023 */   negu     $v0, $v0
.L80240078:
/* 88FC18 80240078 14400003 */  bnez      $v0, .L80240088
/* 88FC1C 8024007C 00000000 */   nop      
/* 88FC20 80240080 50E00017 */  beql      $a3, $zero, .L802400E0
/* 88FC24 80240084 0000102D */   daddu    $v0, $zero, $zero
.L80240088:
/* 88FC28 80240088 44822000 */  mtc1      $v0, $f4
/* 88FC2C 8024008C 00000000 */  nop       
/* 88FC30 80240090 46802120 */  cvt.s.w   $f4, $f4
/* 88FC34 80240094 44062000 */  mfc1      $a2, $f4
/* 88FC38 80240098 44872000 */  mtc1      $a3, $f4
/* 88FC3C 8024009C 00000000 */  nop       
/* 88FC40 802400A0 46802120 */  cvt.s.w   $f4, $f4
/* 88FC44 802400A4 44806000 */  mtc1      $zero, $f12
/* 88FC48 802400A8 44072000 */  mfc1      $a3, $f4
/* 88FC4C 802400AC 0C00A720 */  jal       atan2
/* 88FC50 802400B0 46006386 */   mov.s    $f14, $f12
/* 88FC54 802400B4 3C014270 */  lui       $at, 0x4270
/* 88FC58 802400B8 44811000 */  mtc1      $at, $f2
/* 88FC5C 802400BC 00000000 */  nop       
/* 88FC60 802400C0 4602003C */  c.lt.s    $f0, $f2
/* 88FC64 802400C4 00000000 */  nop       
/* 88FC68 802400C8 45000004 */  bc1f      .L802400DC
/* 88FC6C 802400CC 24020001 */   addiu    $v0, $zero, 1
/* 88FC70 802400D0 AE020084 */  sw        $v0, 0x84($s0)
/* 88FC74 802400D4 08090038 */  j         .L802400E0
/* 88FC78 802400D8 24020002 */   addiu    $v0, $zero, 2
.L802400DC:
/* 88FC7C 802400DC 0000102D */  daddu     $v0, $zero, $zero
.L802400E0:
/* 88FC80 802400E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* 88FC84 802400E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 88FC88 802400E8 03E00008 */  jr        $ra
/* 88FC8C 802400EC 27BD0018 */   addiu    $sp, $sp, 0x18

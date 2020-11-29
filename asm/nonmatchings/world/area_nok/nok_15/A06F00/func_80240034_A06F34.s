.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240034_A06F34
/* A06F34 80240034 3C038016 */  lui       $v1, %hi(gCollisionStatus+0x2)
/* A06F38 80240038 8463A552 */  lh        $v1, %lo(gCollisionStatus+0x2)($v1)
/* A06F3C 8024003C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A06F40 80240040 AFB00010 */  sw        $s0, 0x10($sp)
/* A06F44 80240044 0080802D */  daddu     $s0, $a0, $zero
/* A06F48 80240048 AFBF0014 */  sw        $ra, 0x14($sp)
/* A06F4C 8024004C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* A06F50 80240050 10620003 */  beq       $v1, $v0, .L80240060
/* A06F54 80240054 24020002 */   addiu    $v0, $zero, 2
/* A06F58 80240058 08090038 */  j         .L802400E0
/* A06F5C 8024005C AE000084 */   sw       $zero, 0x84($s0)
.L80240060:
/* A06F60 80240060 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* A06F64 80240064 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* A06F68 80240068 80620040 */  lb        $v0, 0x40($v1)
/* A06F6C 8024006C 80670044 */  lb        $a3, 0x44($v1)
/* A06F70 80240070 04420001 */  bltzl     $v0, .L80240078
/* A06F74 80240074 00021023 */   negu     $v0, $v0
.L80240078:
/* A06F78 80240078 14400003 */  bnez      $v0, .L80240088
/* A06F7C 8024007C 00000000 */   nop      
/* A06F80 80240080 50E00017 */  beql      $a3, $zero, .L802400E0
/* A06F84 80240084 0000102D */   daddu    $v0, $zero, $zero
.L80240088:
/* A06F88 80240088 44822000 */  mtc1      $v0, $f4
/* A06F8C 8024008C 00000000 */  nop       
/* A06F90 80240090 46802120 */  cvt.s.w   $f4, $f4
/* A06F94 80240094 44062000 */  mfc1      $a2, $f4
/* A06F98 80240098 44872000 */  mtc1      $a3, $f4
/* A06F9C 8024009C 00000000 */  nop       
/* A06FA0 802400A0 46802120 */  cvt.s.w   $f4, $f4
/* A06FA4 802400A4 44806000 */  mtc1      $zero, $f12
/* A06FA8 802400A8 44072000 */  mfc1      $a3, $f4
/* A06FAC 802400AC 0C00A720 */  jal       atan2
/* A06FB0 802400B0 46006386 */   mov.s    $f14, $f12
/* A06FB4 802400B4 3C014270 */  lui       $at, 0x4270
/* A06FB8 802400B8 44811000 */  mtc1      $at, $f2
/* A06FBC 802400BC 00000000 */  nop       
/* A06FC0 802400C0 4602003C */  c.lt.s    $f0, $f2
/* A06FC4 802400C4 00000000 */  nop       
/* A06FC8 802400C8 45000004 */  bc1f      .L802400DC
/* A06FCC 802400CC 24020001 */   addiu    $v0, $zero, 1
/* A06FD0 802400D0 AE020084 */  sw        $v0, 0x84($s0)
/* A06FD4 802400D4 08090038 */  j         .L802400E0
/* A06FD8 802400D8 24020002 */   addiu    $v0, $zero, 2
.L802400DC:
/* A06FDC 802400DC 0000102D */  daddu     $v0, $zero, $zero
.L802400E0:
/* A06FE0 802400E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* A06FE4 802400E4 8FB00010 */  lw        $s0, 0x10($sp)
/* A06FE8 802400E8 03E00008 */  jr        $ra
/* A06FEC 802400EC 27BD0018 */   addiu    $sp, $sp, 0x18

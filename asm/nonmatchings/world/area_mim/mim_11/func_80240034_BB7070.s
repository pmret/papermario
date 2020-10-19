.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240034_BB70A4
/* BB70A4 80240034 3C038016 */  lui       $v1, 0x8016
/* BB70A8 80240038 8463A552 */  lh        $v1, -0x5aae($v1)
/* BB70AC 8024003C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BB70B0 80240040 AFB00010 */  sw        $s0, 0x10($sp)
/* BB70B4 80240044 0080802D */  daddu     $s0, $a0, $zero
/* BB70B8 80240048 AFBF0014 */  sw        $ra, 0x14($sp)
/* BB70BC 8024004C 8E0200B0 */  lw        $v0, 0xb0($s0)
/* BB70C0 80240050 10620003 */  beq       $v1, $v0, .L80240060
/* BB70C4 80240054 24020002 */   addiu    $v0, $zero, 2
/* BB70C8 80240058 08090038 */  j         .L802400E0
/* BB70CC 8024005C AE000084 */   sw       $zero, 0x84($s0)
.L80240060:
/* BB70D0 80240060 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* BB70D4 80240064 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* BB70D8 80240068 80620040 */  lb        $v0, 0x40($v1)
/* BB70DC 8024006C 80670044 */  lb        $a3, 0x44($v1)
/* BB70E0 80240070 04420001 */  bltzl     $v0, .L80240078
/* BB70E4 80240074 00021023 */   negu     $v0, $v0
.L80240078:
/* BB70E8 80240078 14400003 */  bnez      $v0, .L80240088
/* BB70EC 8024007C 00000000 */   nop      
/* BB70F0 80240080 50E00017 */  beql      $a3, $zero, .L802400E0
/* BB70F4 80240084 0000102D */   daddu    $v0, $zero, $zero
.L80240088:
/* BB70F8 80240088 44822000 */  mtc1      $v0, $f4
/* BB70FC 8024008C 00000000 */  nop       
/* BB7100 80240090 46802120 */  cvt.s.w   $f4, $f4
/* BB7104 80240094 44062000 */  mfc1      $a2, $f4
/* BB7108 80240098 44872000 */  mtc1      $a3, $f4
/* BB710C 8024009C 00000000 */  nop       
/* BB7110 802400A0 46802120 */  cvt.s.w   $f4, $f4
/* BB7114 802400A4 44806000 */  mtc1      $zero, $f12
/* BB7118 802400A8 44072000 */  mfc1      $a3, $f4
/* BB711C 802400AC 0C00A720 */  jal       atan2
/* BB7120 802400B0 46006386 */   mov.s    $f14, $f12
/* BB7124 802400B4 3C014270 */  lui       $at, 0x4270
/* BB7128 802400B8 44811000 */  mtc1      $at, $f2
/* BB712C 802400BC 00000000 */  nop       
/* BB7130 802400C0 4602003C */  c.lt.s    $f0, $f2
/* BB7134 802400C4 00000000 */  nop       
/* BB7138 802400C8 45000004 */  bc1f      .L802400DC
/* BB713C 802400CC 24020001 */   addiu    $v0, $zero, 1
/* BB7140 802400D0 AE020084 */  sw        $v0, 0x84($s0)
/* BB7144 802400D4 08090038 */  j         .L802400E0
/* BB7148 802400D8 24020002 */   addiu    $v0, $zero, 2
.L802400DC:
/* BB714C 802400DC 0000102D */  daddu     $v0, $zero, $zero
.L802400E0:
/* BB7150 802400E0 8FBF0014 */  lw        $ra, 0x14($sp)
/* BB7154 802400E4 8FB00010 */  lw        $s0, 0x10($sp)
/* BB7158 802400E8 03E00008 */  jr        $ra
/* BB715C 802400EC 27BD0018 */   addiu    $sp, $sp, 0x18

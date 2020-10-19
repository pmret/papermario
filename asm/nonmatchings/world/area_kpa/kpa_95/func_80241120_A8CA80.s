.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241120_A8DBA0
/* A8DBA0 80241120 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* A8DBA4 80241124 AFB3003C */  sw        $s3, 0x3c($sp)
/* A8DBA8 80241128 0080982D */  daddu     $s3, $a0, $zero
/* A8DBAC 8024112C AFBF0040 */  sw        $ra, 0x40($sp)
/* A8DBB0 80241130 AFB20038 */  sw        $s2, 0x38($sp)
/* A8DBB4 80241134 AFB10034 */  sw        $s1, 0x34($sp)
/* A8DBB8 80241138 AFB00030 */  sw        $s0, 0x30($sp)
/* A8DBBC 8024113C 8E710148 */  lw        $s1, 0x148($s3)
/* A8DBC0 80241140 0C00EABB */  jal       get_npc_unsafe
/* A8DBC4 80241144 86240008 */   lh       $a0, 8($s1)
/* A8DBC8 80241148 0040802D */  daddu     $s0, $v0, $zero
/* A8DBCC 8024114C 8E22007C */  lw        $v0, 0x7c($s1)
/* A8DBD0 80241150 8603008E */  lh        $v1, 0x8e($s0)
/* A8DBD4 80241154 2442FFFF */  addiu     $v0, $v0, -1
/* A8DBD8 80241158 14620012 */  bne       $v1, $v0, .L802411A4
/* A8DBDC 8024115C 00000000 */   nop      
/* A8DBE0 80241160 C6000038 */  lwc1      $f0, 0x38($s0)
/* A8DBE4 80241164 4600020D */  trunc.w.s $f8, $f0
/* A8DBE8 80241168 44024000 */  mfc1      $v0, $f8
/* A8DBEC 8024116C 00000000 */  nop       
/* A8DBF0 80241170 A6220010 */  sh        $v0, 0x10($s1)
/* A8DBF4 80241174 C600003C */  lwc1      $f0, 0x3c($s0)
/* A8DBF8 80241178 4600020D */  trunc.w.s $f8, $f0
/* A8DBFC 8024117C 44024000 */  mfc1      $v0, $f8
/* A8DC00 80241180 00000000 */  nop       
/* A8DC04 80241184 A6220012 */  sh        $v0, 0x12($s1)
/* A8DC08 80241188 C6000040 */  lwc1      $f0, 0x40($s0)
/* A8DC0C 8024118C 24020001 */  addiu     $v0, $zero, 1
/* A8DC10 80241190 A2220007 */  sb        $v0, 7($s1)
/* A8DC14 80241194 4600020D */  trunc.w.s $f8, $f0
/* A8DC18 80241198 44024000 */  mfc1      $v0, $f8
/* A8DC1C 8024119C 00000000 */  nop       
/* A8DC20 802411A0 A6220014 */  sh        $v0, 0x14($s1)
.L802411A4:
/* A8DC24 802411A4 C6000038 */  lwc1      $f0, 0x38($s0)
/* A8DC28 802411A8 C602003C */  lwc1      $f2, 0x3c($s0)
/* A8DC2C 802411AC C6040040 */  lwc1      $f4, 0x40($s0)
/* A8DC30 802411B0 C6060018 */  lwc1      $f6, 0x18($s0)
/* A8DC34 802411B4 E7A00020 */  swc1      $f0, 0x20($sp)
/* A8DC38 802411B8 E7A20024 */  swc1      $f2, 0x24($sp)
/* A8DC3C 802411BC E7A40028 */  swc1      $f4, 0x28($sp)
/* A8DC40 802411C0 E7A60010 */  swc1      $f6, 0x10($sp)
/* A8DC44 802411C4 C600000C */  lwc1      $f0, 0xc($s0)
/* A8DC48 802411C8 E7A00014 */  swc1      $f0, 0x14($sp)
/* A8DC4C 802411CC 860200A8 */  lh        $v0, 0xa8($s0)
/* A8DC50 802411D0 27A50020 */  addiu     $a1, $sp, 0x20
/* A8DC54 802411D4 44820000 */  mtc1      $v0, $f0
/* A8DC58 802411D8 00000000 */  nop       
/* A8DC5C 802411DC 46800020 */  cvt.s.w   $f0, $f0
/* A8DC60 802411E0 E7A00018 */  swc1      $f0, 0x18($sp)
/* A8DC64 802411E4 860200A6 */  lh        $v0, 0xa6($s0)
/* A8DC68 802411E8 27A60024 */  addiu     $a2, $sp, 0x24
/* A8DC6C 802411EC 44820000 */  mtc1      $v0, $f0
/* A8DC70 802411F0 00000000 */  nop       
/* A8DC74 802411F4 46800020 */  cvt.s.w   $f0, $f0
/* A8DC78 802411F8 E7A0001C */  swc1      $f0, 0x1c($sp)
/* A8DC7C 802411FC 8E040080 */  lw        $a0, 0x80($s0)
/* A8DC80 80241200 0C037711 */  jal       func_800DDC44
/* A8DC84 80241204 27A70028 */   addiu    $a3, $sp, 0x28
/* A8DC88 80241208 0040902D */  daddu     $s2, $v0, $zero
/* A8DC8C 8024120C 16400005 */  bnez      $s2, .L80241224
/* A8DC90 80241210 00000000 */   nop      
/* A8DC94 80241214 8E050018 */  lw        $a1, 0x18($s0)
/* A8DC98 80241218 8E06000C */  lw        $a2, 0xc($s0)
/* A8DC9C 8024121C 0C00EA95 */  jal       npc_move_heading
/* A8DCA0 80241220 0200202D */   daddu    $a0, $s0, $zero
.L80241224:
/* A8DCA4 80241224 8602008E */  lh        $v0, 0x8e($s0)
/* A8DCA8 80241228 9603008E */  lhu       $v1, 0x8e($s0)
/* A8DCAC 8024122C 18400007 */  blez      $v0, .L8024124C
/* A8DCB0 80241230 2462FFFF */   addiu    $v0, $v1, -1
/* A8DCB4 80241234 A602008E */  sh        $v0, 0x8e($s0)
/* A8DCB8 80241238 00021400 */  sll       $v0, $v0, 0x10
/* A8DCBC 8024123C 18400003 */  blez      $v0, .L8024124C
/* A8DCC0 80241240 00000000 */   nop      
/* A8DCC4 80241244 12400008 */  beqz      $s2, .L80241268
/* A8DCC8 80241248 00000000 */   nop      
.L8024124C:
/* A8DCCC 8024124C 8E2200CC */  lw        $v0, 0xcc($s1)
/* A8DCD0 80241250 A2200007 */  sb        $zero, 7($s1)
/* A8DCD4 80241254 8C420028 */  lw        $v0, 0x28($v0)
/* A8DCD8 80241258 A600008E */  sh        $zero, 0x8e($s0)
/* A8DCDC 8024125C AE020028 */  sw        $v0, 0x28($s0)
/* A8DCE0 80241260 2402000F */  addiu     $v0, $zero, 0xf
/* A8DCE4 80241264 AE620070 */  sw        $v0, 0x70($s3)
.L80241268:
/* A8DCE8 80241268 8FBF0040 */  lw        $ra, 0x40($sp)
/* A8DCEC 8024126C 8FB3003C */  lw        $s3, 0x3c($sp)
/* A8DCF0 80241270 8FB20038 */  lw        $s2, 0x38($sp)
/* A8DCF4 80241274 8FB10034 */  lw        $s1, 0x34($sp)
/* A8DCF8 80241278 8FB00030 */  lw        $s0, 0x30($sp)
/* A8DCFC 8024127C 03E00008 */  jr        $ra
/* A8DD00 80241280 27BD0048 */   addiu    $sp, $sp, 0x48

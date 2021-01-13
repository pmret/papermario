.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B72C0_E22870
/* E22870 802B72C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E22874 802B72C4 AFB00010 */  sw        $s0, 0x10($sp)
/* E22878 802B72C8 3C10802B */  lui       $s0, %hi(D_802B7C78)
/* E2287C 802B72CC 26107C78 */  addiu     $s0, $s0, %lo(D_802B7C78)
/* E22880 802B72D0 AFBF0014 */  sw        $ra, 0x14($sp)
/* E22884 802B72D4 8E040000 */  lw        $a0, ($s0)
/* E22888 802B72D8 0C00A580 */  jal       mem_clear
/* E2288C 802B72DC 2405002C */   addiu    $a1, $zero, 0x2c
/* E22890 802B72E0 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* E22894 802B72E4 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* E22898 802B72E8 8E030000 */  lw        $v1, ($s0)
/* E2289C 802B72EC C4800028 */  lwc1      $f0, 0x28($a0)
/* E228A0 802B72F0 E4600000 */  swc1      $f0, ($v1)
/* E228A4 802B72F4 848200B0 */  lh        $v0, 0xb0($a0)
/* E228A8 802B72F8 C480002C */  lwc1      $f0, 0x2c($a0)
/* E228AC 802B72FC 44821000 */  mtc1      $v0, $f2
/* E228B0 802B7300 00000000 */  nop
/* E228B4 802B7304 468010A0 */  cvt.s.w   $f2, $f2
/* E228B8 802B7308 46020000 */  add.s     $f0, $f0, $f2
/* E228BC 802B730C 3C014100 */  lui       $at, 0x4100
/* E228C0 802B7310 44811000 */  mtc1      $at, $f2
/* E228C4 802B7314 00000000 */  nop
/* E228C8 802B7318 46020000 */  add.s     $f0, $f0, $f2
/* E228CC 802B731C E4600004 */  swc1      $f0, 4($v1)
/* E228D0 802B7320 C4800030 */  lwc1      $f0, 0x30($a0)
/* E228D4 802B7324 240200FF */  addiu     $v0, $zero, 0xff
/* E228D8 802B7328 AC620028 */  sw        $v0, 0x28($v1)
/* E228DC 802B732C E4600008 */  swc1      $f0, 8($v1)
/* E228E0 802B7330 8C820004 */  lw        $v0, 4($a0)
/* E228E4 802B7334 34420100 */  ori       $v0, $v0, 0x100
/* E228E8 802B7338 AC820004 */  sw        $v0, 4($a0)
/* E228EC 802B733C 8FBF0014 */  lw        $ra, 0x14($sp)
/* E228F0 802B7340 8FB00010 */  lw        $s0, 0x10($sp)
/* E228F4 802B7344 3C03802B */  lui       $v1, %hi(func_802B735C_E2290C)
/* E228F8 802B7348 2463735C */  addiu     $v1, $v1, %lo(func_802B735C_E2290C)
/* E228FC 802B734C 3C018011 */  lui       $at, %hi(D_8010C93C)
/* E22900 802B7350 AC23C93C */  sw        $v1, %lo(D_8010C93C)($at)
/* E22904 802B7354 03E00008 */  jr        $ra
/* E22908 802B7358 27BD0018 */   addiu    $sp, $sp, 0x18

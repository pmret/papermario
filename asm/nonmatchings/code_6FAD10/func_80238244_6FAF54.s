.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238244_6FAF54
/* 6FAF54 80238244 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 6FAF58 80238248 AFB00018 */  sw        $s0, 0x18($sp)
/* 6FAF5C 8023824C 3C10800E */  lui       $s0, %hi(gBattleStatus+0xDC)
/* 6FAF60 80238250 8E10C14C */  lw        $s0, %lo(gBattleStatus+0xDC)($s0)
/* 6FAF64 80238254 AFBF0020 */  sw        $ra, 0x20($sp)
/* 6FAF68 80238258 AFB1001C */  sw        $s1, 0x1c($sp)
/* 6FAF6C 8023825C 10A00007 */  beqz      $a1, .L8023827C
/* 6FAF70 80238260 2611000C */   addiu    $s1, $s0, 0xc
/* 6FAF74 80238264 C6000144 */  lwc1      $f0, 0x144($s0)
/* 6FAF78 80238268 C6020148 */  lwc1      $f2, 0x148($s0)
/* 6FAF7C 8023826C C604014C */  lwc1      $f4, 0x14c($s0)
/* 6FAF80 80238270 E600000C */  swc1      $f0, 0xc($s0)
/* 6FAF84 80238274 E6020010 */  swc1      $f2, 0x10($s0)
/* 6FAF88 80238278 E6040014 */  swc1      $f4, 0x14($s0)
.L8023827C:
/* 6FAF8C 8023827C 8E05004C */  lw        $a1, 0x4c($s0)
/* 6FAF90 80238280 8E060054 */  lw        $a2, 0x54($s0)
/* 6FAF94 80238284 0C09904A */  jal       add_xz_vec3f
/* 6FAF98 80238288 0220202D */   daddu    $a0, $s1, $zero
/* 6FAF9C 8023828C C602004C */  lwc1      $f2, 0x4c($s0)
/* 6FAFA0 80238290 3C014080 */  lui       $at, 0x4080
/* 6FAFA4 80238294 44810000 */  mtc1      $at, $f0
/* 6FAFA8 80238298 00000000 */  nop       
/* 6FAFAC 8023829C 4600103C */  c.lt.s    $f2, $f0
/* 6FAFB0 802382A0 00000000 */  nop       
/* 6FAFB4 802382A4 45000007 */  bc1f      .L802382C4
/* 6FAFB8 802382A8 0000202D */   daddu    $a0, $zero, $zero
/* 6FAFBC 802382AC C6000054 */  lwc1      $f0, 0x54($s0)
/* 6FAFC0 802382B0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 6FAFC4 802382B4 8E05000C */  lw        $a1, 0xc($s0)
/* 6FAFC8 802382B8 8E060010 */  lw        $a2, 0x10($s0)
/* 6FAFCC 802382BC 0808E0B7 */  j         .L802382DC
/* 6FAFD0 802382C0 8E070014 */   lw       $a3, 0x14($s0)
.L802382C4:
/* 6FAFD4 802382C4 C6000054 */  lwc1      $f0, 0x54($s0)
/* 6FAFD8 802382C8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 6FAFDC 802382CC 8E05000C */  lw        $a1, 0xc($s0)
/* 6FAFE0 802382D0 8E060010 */  lw        $a2, 0x10($s0)
/* 6FAFE4 802382D4 8E070014 */  lw        $a3, 0x14($s0)
/* 6FAFE8 802382D8 24040001 */  addiu     $a0, $zero, 1
.L802382DC:
/* 6FAFEC 802382DC 0C0990BC */  jal       play_movement_dust_effects
/* 6FAFF0 802382E0 00000000 */   nop      
/* 6FAFF4 802382E4 C6200040 */  lwc1      $f0, 0x40($s1)
/* 6FAFF8 802382E8 3C013FF8 */  lui       $at, 0x3ff8
/* 6FAFFC 802382EC 44811800 */  mtc1      $at, $f3
/* 6FB000 802382F0 44801000 */  mtc1      $zero, $f2
/* 6FB004 802382F4 46000021 */  cvt.d.s   $f0, $f0
/* 6FB008 802382F8 46220003 */  div.d     $f0, $f0, $f2
/* 6FB00C 802382FC C6220000 */  lwc1      $f2, ($s1)
/* 6FB010 80238300 46200020 */  cvt.s.d   $f0, $f0
/* 6FB014 80238304 E6200040 */  swc1      $f0, 0x40($s1)
/* 6FB018 80238308 E6020144 */  swc1      $f2, 0x144($s0)
/* 6FB01C 8023830C C6200004 */  lwc1      $f0, 4($s1)
/* 6FB020 80238310 E6000148 */  swc1      $f0, 0x148($s0)
/* 6FB024 80238314 C6200008 */  lwc1      $f0, 8($s1)
/* 6FB028 80238318 E600014C */  swc1      $f0, 0x14c($s0)
/* 6FB02C 8023831C C6200040 */  lwc1      $f0, 0x40($s1)
/* 6FB030 80238320 3C013FF0 */  lui       $at, 0x3ff0
/* 6FB034 80238324 44811800 */  mtc1      $at, $f3
/* 6FB038 80238328 44801000 */  mtc1      $zero, $f2
/* 6FB03C 8023832C 46000021 */  cvt.d.s   $f0, $f0
/* 6FB040 80238330 4622003C */  c.lt.d    $f0, $f2
/* 6FB044 80238334 00000000 */  nop       
/* 6FB048 80238338 45010002 */  bc1t      .L80238344
/* 6FB04C 8023833C 24020002 */   addiu    $v0, $zero, 2
/* 6FB050 80238340 0000102D */  daddu     $v0, $zero, $zero
.L80238344:
/* 6FB054 80238344 8FBF0020 */  lw        $ra, 0x20($sp)
/* 6FB058 80238348 8FB1001C */  lw        $s1, 0x1c($sp)
/* 6FB05C 8023834C 8FB00018 */  lw        $s0, 0x18($sp)
/* 6FB060 80238350 03E00008 */  jr        $ra
/* 6FB064 80238354 27BD0028 */   addiu    $sp, $sp, 0x28

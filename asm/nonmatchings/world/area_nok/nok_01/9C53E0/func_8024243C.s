.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024243C
/* 9C781C 8024243C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9C7820 80242440 AFB10014 */  sw        $s1, 0x14($sp)
/* 9C7824 80242444 0080882D */  daddu     $s1, $a0, $zero
/* 9C7828 80242448 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9C782C 8024244C AFB00010 */  sw        $s0, 0x10($sp)
/* 9C7830 80242450 8E30000C */  lw        $s0, 0xc($s1)
/* 9C7834 80242454 8E050000 */  lw        $a1, ($s0)
/* 9C7838 80242458 0C0B1EAF */  jal       get_variable
/* 9C783C 8024245C 26100004 */   addiu    $s0, $s0, 4
/* 9C7840 80242460 8E100000 */  lw        $s0, ($s0)
/* 9C7844 80242464 0C00EAD2 */  jal       get_npc_safe
/* 9C7848 80242468 0040202D */   daddu    $a0, $v0, $zero
/* 9C784C 8024246C 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* 9C7850 80242470 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* 9C7854 80242474 C440000C */  lwc1      $f0, 0xc($v0)
/* 9C7858 80242478 3C014334 */  lui       $at, 0x4334
/* 9C785C 8024247C 44811000 */  mtc1      $at, $f2
/* 9C7860 80242480 00041880 */  sll       $v1, $a0, 2
/* 9C7864 80242484 00641821 */  addu      $v1, $v1, $a0
/* 9C7868 80242488 00031880 */  sll       $v1, $v1, 2
/* 9C786C 8024248C 00641823 */  subu      $v1, $v1, $a0
/* 9C7870 80242490 000320C0 */  sll       $a0, $v1, 3
/* 9C7874 80242494 00641821 */  addu      $v1, $v1, $a0
/* 9C7878 80242498 000318C0 */  sll       $v1, $v1, 3
/* 9C787C 8024249C 46020000 */  add.s     $f0, $f0, $f2
/* 9C7880 802424A0 3C01800B */  lui       $at, 0x800b
/* 9C7884 802424A4 00230821 */  addu      $at, $at, $v1
/* 9C7888 802424A8 C42C1DEC */  lwc1      $f12, 0x1dec($at)
/* 9C788C 802424AC 0C00A6C9 */  jal       clamp_angle
/* 9C7890 802424B0 460C0301 */   sub.s    $f12, $f0, $f12
/* 9C7894 802424B4 3C014387 */  lui       $at, 0x4387
/* 9C7898 802424B8 44811000 */  mtc1      $at, $f2
/* 9C789C 802424BC 46000106 */  mov.s     $f4, $f0
/* 9C78A0 802424C0 4604103C */  c.lt.s    $f2, $f4
/* 9C78A4 802424C4 00000000 */  nop       
/* 9C78A8 802424C8 45010008 */  bc1t      .L802424EC
/* 9C78AC 802424CC 0000302D */   daddu    $a2, $zero, $zero
/* 9C78B0 802424D0 3C0142B4 */  lui       $at, 0x42b4
/* 9C78B4 802424D4 44810000 */  mtc1      $at, $f0
/* 9C78B8 802424D8 00000000 */  nop       
/* 9C78BC 802424DC 4600203C */  c.lt.s    $f4, $f0
/* 9C78C0 802424E0 00000000 */  nop       
/* 9C78C4 802424E4 45000003 */  bc1f      .L802424F4
/* 9C78C8 802424E8 0220202D */   daddu    $a0, $s1, $zero
.L802424EC:
/* 9C78CC 802424EC 24060001 */  addiu     $a2, $zero, 1
/* 9C78D0 802424F0 0220202D */  daddu     $a0, $s1, $zero
.L802424F4:
/* 9C78D4 802424F4 0C0B2026 */  jal       set_variable
/* 9C78D8 802424F8 0200282D */   daddu    $a1, $s0, $zero
/* 9C78DC 802424FC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9C78E0 80242500 8FB10014 */  lw        $s1, 0x14($sp)
/* 9C78E4 80242504 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C78E8 80242508 24020002 */  addiu     $v0, $zero, 2
/* 9C78EC 8024250C 03E00008 */  jr        $ra
/* 9C78F0 80242510 27BD0020 */   addiu    $sp, $sp, 0x20

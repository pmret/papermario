.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240854
/* 90FF04 80240854 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 90FF08 80240858 AFB20038 */  sw        $s2, 0x38($sp)
/* 90FF0C 8024085C 0080902D */  daddu     $s2, $a0, $zero
/* 90FF10 80240860 AFBF003C */  sw        $ra, 0x3c($sp)
/* 90FF14 80240864 AFB10034 */  sw        $s1, 0x34($sp)
/* 90FF18 80240868 AFB00030 */  sw        $s0, 0x30($sp)
/* 90FF1C 8024086C 8E510148 */  lw        $s1, 0x148($s2)
/* 90FF20 80240870 0C00EABB */  jal       get_npc_unsafe
/* 90FF24 80240874 86240008 */   lh       $a0, 8($s1)
/* 90FF28 80240878 0040802D */  daddu     $s0, $v0, $zero
/* 90FF2C 8024087C 9602008E */  lhu       $v0, 0x8e($s0)
/* 90FF30 80240880 2442FFFF */  addiu     $v0, $v0, -1
/* 90FF34 80240884 A602008E */  sh        $v0, 0x8e($s0)
/* 90FF38 80240888 00021400 */  sll       $v0, $v0, 0x10
/* 90FF3C 8024088C 1C40002B */  bgtz      $v0, .L8024093C
/* 90FF40 80240890 00000000 */   nop      
/* 90FF44 80240894 0C090148 */  jal       func_80240520
/* 90FF48 80240898 0240202D */   daddu    $a0, $s2, $zero
/* 90FF4C 8024089C 0040202D */  daddu     $a0, $v0, $zero
/* 90FF50 802408A0 0481001A */  bgez      $a0, .L8024090C
/* 90FF54 802408A4 2402000F */   addiu    $v0, $zero, 0xf
/* 90FF58 802408A8 24040002 */  addiu     $a0, $zero, 2
/* 90FF5C 802408AC 860300A8 */  lh        $v1, 0xa8($s0)
/* 90FF60 802408B0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 90FF64 802408B4 27A20028 */  addiu     $v0, $sp, 0x28
/* 90FF68 802408B8 0200282D */  daddu     $a1, $s0, $zero
/* 90FF6C 802408BC 3C013F80 */  lui       $at, 0x3f80
/* 90FF70 802408C0 44810000 */  mtc1      $at, $f0
/* 90FF74 802408C4 3C014000 */  lui       $at, 0x4000
/* 90FF78 802408C8 44811000 */  mtc1      $at, $f2
/* 90FF7C 802408CC 3C01C1A0 */  lui       $at, 0xc1a0
/* 90FF80 802408D0 44812000 */  mtc1      $at, $f4
/* 90FF84 802408D4 44833000 */  mtc1      $v1, $f6
/* 90FF88 802408D8 00000000 */  nop       
/* 90FF8C 802408DC 468031A0 */  cvt.s.w   $f6, $f6
/* 90FF90 802408E0 44073000 */  mfc1      $a3, $f6
/* 90FF94 802408E4 0000302D */  daddu     $a2, $zero, $zero
/* 90FF98 802408E8 AFA20020 */  sw        $v0, 0x20($sp)
/* 90FF9C 802408EC E7A00010 */  swc1      $f0, 0x10($sp)
/* 90FFA0 802408F0 E7A20014 */  swc1      $f2, 0x14($sp)
/* 90FFA4 802408F4 0C01BFA4 */  jal       fx_emote
/* 90FFA8 802408F8 E7A40018 */   swc1     $f4, 0x18($sp)
/* 90FFAC 802408FC 8E2200CC */  lw        $v0, 0xcc($s1)
/* 90FFB0 80240900 8C420000 */  lw        $v0, ($v0)
/* 90FFB4 80240904 0809024B */  j         .L8024092C
/* 90FFB8 80240908 AE020028 */   sw       $v0, 0x28($s0)
.L8024090C:
/* 90FFBC 8024090C 8E2200CC */  lw        $v0, 0xcc($s1)
/* 90FFC0 80240910 8C420024 */  lw        $v0, 0x24($v0)
/* 90FFC4 80240914 0C00FB3A */  jal       get_enemy
/* 90FFC8 80240918 AE020028 */   sw       $v0, 0x28($s0)
/* 90FFCC 8024091C 86240008 */  lh        $a0, 8($s1)
/* 90FFD0 80240920 24030001 */  addiu     $v1, $zero, 1
/* 90FFD4 80240924 AC43006C */  sw        $v1, 0x6c($v0)
/* 90FFD8 80240928 AC44007C */  sw        $a0, 0x7c($v0)
.L8024092C:
/* 90FFDC 8024092C 96220076 */  lhu       $v0, 0x76($s1)
/* 90FFE0 80240930 A602008E */  sh        $v0, 0x8e($s0)
/* 90FFE4 80240934 24020021 */  addiu     $v0, $zero, 0x21
/* 90FFE8 80240938 AE420070 */  sw        $v0, 0x70($s2)
.L8024093C:
/* 90FFEC 8024093C 8FBF003C */  lw        $ra, 0x3c($sp)
/* 90FFF0 80240940 8FB20038 */  lw        $s2, 0x38($sp)
/* 90FFF4 80240944 8FB10034 */  lw        $s1, 0x34($sp)
/* 90FFF8 80240948 8FB00030 */  lw        $s0, 0x30($sp)
/* 90FFFC 8024094C 03E00008 */  jr        $ra
/* 910000 80240950 27BD0040 */   addiu    $sp, $sp, 0x40

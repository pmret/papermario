.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E7034
/* 1088B4 802E7034 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1088B8 802E7038 AFB10014 */  sw        $s1, 0x14($sp)
/* 1088BC 802E703C 0080882D */  daddu     $s1, $a0, $zero
/* 1088C0 802E7040 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1088C4 802E7044 AFB00010 */  sw        $s0, 0x10($sp)
/* 1088C8 802E7048 8E300040 */  lw        $s0, 0x40($s1)
/* 1088CC 802E704C 96030000 */  lhu       $v1, ($s0)
/* 1088D0 802E7050 3402FFFF */  ori       $v0, $zero, 0xffff
/* 1088D4 802E7054 10620011 */  beq       $v1, $v0, .L802E709C
/* 1088D8 802E7058 00000000 */   nop      
/* 1088DC 802E705C 0C05152F */  jal       get_global_flag
/* 1088E0 802E7060 0060202D */   daddu    $a0, $v1, $zero
/* 1088E4 802E7064 1040000D */  beqz      $v0, .L802E709C
/* 1088E8 802E7068 0220202D */   daddu    $a0, $s1, $zero
/* 1088EC 802E706C 3C05802F */  lui       $a1, 0x802f
/* 1088F0 802E7070 24A5AD7C */  addiu     $a1, $a1, -0x5284
/* 1088F4 802E7074 8E220000 */  lw        $v0, ($s1)
/* 1088F8 802E7078 3C01C1E5 */  lui       $at, 0xc1e5
/* 1088FC 802E707C 3421999A */  ori       $at, $at, 0x999a
/* 108900 802E7080 44810000 */  mtc1      $at, $f0
/* 108904 802E7084 34424000 */  ori       $v0, $v0, 0x4000
/* 108908 802E7088 AC820000 */  sw        $v0, ($a0)
/* 10890C 802E708C 2402FFFF */  addiu     $v0, $zero, -1
/* 108910 802E7090 AE020010 */  sw        $v0, 0x10($s0)
/* 108914 802E7094 0C043EF0 */  jal       func_8010FBC0
/* 108918 802E7098 E6000008 */   swc1     $f0, 8($s0)
.L802E709C:
/* 10891C 802E709C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 108920 802E70A0 8FB10014 */  lw        $s1, 0x14($sp)
/* 108924 802E70A4 8FB00010 */  lw        $s0, 0x10($sp)
/* 108928 802E70A8 03E00008 */  jr        $ra
/* 10892C 802E70AC 27BD0020 */   addiu    $sp, $sp, 0x20
